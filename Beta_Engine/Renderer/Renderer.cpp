#include "Renderer.h"


Renderer::Renderer(Camera& camera) :
	camera(camera)
{

}

void Renderer::RenderScene(Entity* root, list<Shader*>& shaderss) {
	shaders=shaderss;
	root->updateSelfAndChild();
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	Draw(root);

}

void Renderer::Draw(Entity* e) {
	//LZM EL RECURSIVITE
	if (e->getMesh()) {
		Shader* target = findShaderByID(e->getShaderID());
		target->Activate();
		glUniformMatrix4fv(glGetUniformLocation(target->ID, "model"), 1, GL_FALSE, glm::value_ptr(e->getTransform()->getWorldMatrix()));
		e->getMesh()->Draw(*target,camera);//draw the mesh
	}

	for(Entity* i : e->childs) {
		Draw(i);
	}

}


Shader* Renderer::findShaderByID(GLuint ID) {
	for (Shader* s : shaders) {
		if (s->ID == ID) {
			return s;
		}
	}
}


