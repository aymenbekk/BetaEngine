#include "Renderer.h"
#include "../Components/MeshRenderer.h"
#include "../Scene/World.h"


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
	

	/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); */
	root->updateAll();
	root->updateSelfAndChild();

	if (root->getTag() == "world") {

		Shader* target = findShaderByID(root->getShaderIndex());
	/*	target->Activate();*/
		root->Draw(camera,target);//matensach el model matrix for each chunk howa wajed bel getWorld matrix tahtajo tpassih le shaer so je c jatek fi balek dir ghi el vertices ta3 ga3 el chunkMeshes fe VBO we troyah madalich tecriyi fe entities mais nrespecti ECS is better where each chunk is an entity
		return;
	}
	Draw(root);

}

void Renderer::Draw(Entity* e) {

	
		
	Shader* target = findShaderByID(e->getShaderIndex());
	
	target->Activate();
	glUniformMatrix4fv(glGetUniformLocation(target->ID, "model"), 1, GL_FALSE, glm::value_ptr(e->getTransform()->getWorldMatrix()));
	//e->getMesh()->Draw(target, camera);//draw the mesh

	//for (Component* c : e->getComponents()) {
	//	if (dynamic_cast<MeshRenderer*>(c) == nullptr) {
	//		c->Render();
	//	}
	//	else {
	//		dynamic_cast<MeshRenderer*>(c)->Render(target, camera);
	//	}
	//	
	//}
	

	for(Entity* i : e->childs) {
		Draw(i);
	}

}


Shader* Renderer::findShaderByID(size_t Index) {

	return shaders.at(Index);
}


void Renderer::DrawWorld(Entity* root) {

}


void printMat4(const glm::mat4& matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			std::cout << matrix[row][col] << "\t";
		}
		std::cout << std::endl;
	}
}

void generateDrawCommands() {

}

