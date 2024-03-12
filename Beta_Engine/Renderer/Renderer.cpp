#include "Renderer.h"


Renderer::Renderer(Camera& camera,vector<pair<const char*, const char*>>& shadersPaths) :
	camera(camera)
{

	for (const auto& pair : shadersPaths) {

		cout << "first pair" << pair.first << "scond" << pair.second << endl;
		Shader* shaderProgram = new Shader(pair.first, pair.second);
		shaderProgram->Activate();
		shaders.push_back(shaderProgram);
	}
}

void Renderer::RenderScene(Entity* root) {
	//shaders=shaderss;
	root->updateSelfAndChild();

	/*Draw(root);*/

	//Shader* target = findShaderByID(e->getShaderIndex());

	//cout << target->ID << endl;
	//target->Activate();
	/*printMat4(e->getTransform()->getWorldMatrix());*/
	//glUniformMatrix4fv(glGetUniformLocation(target->ID, "model"), 1, GL_FALSE, glm::value_ptr(e->getTransform()->getWorldMatrix()));
	root->getMesh()->Draw(shaders[0], camera);//draw the mesh

}

void Renderer::Draw(Entity* e) {

	if (e->getMesh()) {
		
		Shader* target = findShaderByID(e->getShaderIndex());
	
		//cout << target->ID << endl;
		target->Activate();
		/*printMat4(e->getTransform()->getWorldMatrix());*/
		glUniformMatrix4fv(glGetUniformLocation(target->ID, "model"), 1, GL_FALSE, glm::value_ptr(e->getTransform()->getWorldMatrix()));
		e->getMesh()->Draw(shaders[0], camera);//draw the mesh
	}

	for(Entity* i : e->childs) {
		Draw(i);
	}

}


Shader* Renderer::findShaderByID(size_t Index) {
	cout << Index << endl;
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