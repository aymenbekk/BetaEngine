#include "Renderer.h"


Renderer::Renderer(Camera& camera,vector<pair<const char*, const char*>>& shadersPaths) :
	camera(camera)
{

	for (const auto& pair : shadersPaths) {
		Shader* shaderProgram = new Shader(pair.first, pair.second);
		shaderProgram->Activate();
		shaders.push_back(shaderProgram);
	}
}

void Renderer::RenderScene(Entity* root) {
	
	/*root->updateSelfAndChild();*/

	Draw(root);

}

void Renderer::Draw(Entity* e) {
	cout << "cam x:" << camera.Position.x << "/" << camera.Position.y << "/" << camera.Position.z << endl;
	string tag0 = "cube01";//EARTH
	if (e->getTag() == tag0) {

		glm::vec3 positionA = glm::vec3(e->getTransform()->getWorldMatrix()[3]); //small sube
		glm::vec3 positionB = glm::vec3(e->getParent()->getTransform()->getWorldMatrix()[3]);
		float rotationAngle = glm::radians(0.1f);
		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotationAngle, vec3(0.0f, 1.0f, 0.0f));


		//Rotate around itself
		mat4 translateToOriginSelf = translate(mat4(1.0f), -positionA);
		mat4 translateBackSelf = translate(mat4(1.0f), positionA);

		glm::mat4 modelMatrix1 = translateToOriginSelf * rotationMatrix * translateBackSelf;

		//Rotate aroun sun

		glm::mat4 translationToOrigin = glm::translate(glm::mat4(1.0f), -positionB);

		glm::mat4 translationBack = glm::translate(glm::mat4(1.0f), positionB);

		

		glm::mat4 modelMatrix = translationBack * rotationMatrix * translationToOrigin * e->getTransform()->getWorldMatrix();


		e->getTransform()->setWorldMatrix(modelMatrix);

		/*e->updateSelfAndChild();*/
		e->updateChilds();
	/*	e->getTransform()->setWorldMatrix(modelMatrix*modelMatrix1);*/
	}

	//Moon
	string tag = "cube02";
	if (e->getTag() == tag ) {
		glm::vec3 positionA = glm::vec3(e->getTransform()->getWorldMatrix()[3]); //small sube
		glm::vec3 positionB = glm::vec3(e->getParent()->getTransform()->getWorldMatrix()[3]);
		float rotationAngle = glm::radians(1.0f);
		glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotationAngle, vec3(0.0f, 1.0f, 0.0f));



		/*e->updateSelfAndChild();*/
		
		glm::mat4 translationToOrigin = glm::translate(glm::mat4(1.0f), - positionB);

		glm::mat4 translationBack = glm::translate(glm::mat4(1.0f), positionB);

		
		glm::mat4 modelMatrix = translationBack*rotationMatrix * translationToOrigin * e->getTransform()->getWorldMatrix();


		e->getTransform()->setWorldMatrix(modelMatrix);
		
		/*e->updateSelfAndChild();*/
	}
	if (e->getMesh()) {
		
		Shader* target = findShaderByID(e->getShaderIndex());
	
		target->Activate();
		glUniformMatrix4fv(glGetUniformLocation(target->ID, "model"), 1, GL_FALSE, glm::value_ptr(e->getTransform()->getWorldMatrix()));
		e->getMesh()->Draw(target, camera);//draw the mesh
	}

	for(Entity* i : e->childs) {
		Draw(i);
	}

}


Shader* Renderer::findShaderByID(size_t Index) {

	return shaders.at(Index);
}


void printMat4(const glm::mat4& matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			std::cout << matrix[row][col] << "\t";
		}
		std::cout << std::endl;
	}
}
