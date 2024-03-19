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
	
	root->updateAll();
	root->updateSelfAndChild();

	Draw(root);

}

void Renderer::Draw(Entity* e) {

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
