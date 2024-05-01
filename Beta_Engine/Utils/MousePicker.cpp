#include "MousePicker.h"
#include "../Core/Window.h"
#include <chrono>
#include <thread>




void MousePicker::update(Camera* camera) {


	double mousePosX, mousePosY;
	glfwGetCursorPos(glfwGetCurrentContext(), &mousePosX, &mousePosY);
	//std::cout << "Camera Pos " << camera.Position.x << "/" << camera.Position.y << "/" << camera.Position.z << "/" << endl;
	int width, height;
	glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
	glm::vec3 unproject = glm::unProject(glm::vec3(mousePosX, height - mousePosY, 0.0f), camera->view, camera->projection, glm::vec4(0, 0, width, height));
	glm::vec3 unproj_dir_vec = unproject - camera->Position;
	currentRay = glm::normalize(unproj_dir_vec);

	/*std::cout << "CURRENT RAY : " << currentRay.x << "/" << currentRay.y << "/" << currentRay.z << endl;*/

   /* getPointOnRay(currentRay, 0,camera);
    getPointOnRay(currentRay, 10, camera);*/

    //if (intersectionInRange(0, 10, currentRay,camera)) {
    //    currentTerrainPoint = binarySearch(0, 0, RAY_RANGE, currentRay);
    //}
    //else {
    //    currentTerrainPoint = null;
    //}

}


glm::vec3 MousePicker::getPointOnRay(glm::vec3 ray, float distance,Camera* camera) {
    glm::vec3 camPos = camera->Position; 
    glm::vec3 start = { camPos.x, camPos.y, camPos.z };
    glm::vec3 scaledRay = { ray.x * distance, ray.y * distance, ray.z * distance };

  
        
        std::cout << "point on ray : x :" << start.x + scaledRay.x << "y : " << start.y + scaledRay.y << " z : " << start.z + scaledRay.z << endl;

  
       
    return { start.x + scaledRay.x, start.y + scaledRay.y, start.z + scaledRay.z };
}
//
//glm::vec3 binarySearch(int count, float start, float finish, glm::vec3 ray) {
//    const int RECURSION_COUNT = 5;
//    float half = start + ((finish - start) / 2.0f);
//   // if (count >= RECURSION_COUNT) {
//   //     glm::vec3 endPoint = getPointOnRay(ray, half);
//   // /*    Terrain terrain; */
//   ///*     if (terrain != nullptr) {
//   //         return endPoint;
//   //     }*/
//   //     //else {
//   //     //    return { 0.0f, 0.0f, 0.0f };
//   //     //}
//   // }
//   // if (intersectionInRange(start, half, ray)) {
//   //     return binarySearch(count + 1, start, half, ray);
//   // }
//   // else {
//   //     return binarySearch(count + 1, half, finish, ray);
//   // }
//}

//normalement nsemiha isTestPointInsideBlock
//bool isUnderGround(glm::vec3 testPoint) {
//    /* Terrain terrain; */
//    float height = 0;
//    //if (terrain != nullptr) {
//    //    height = terrain.getHeightOfTerrain(testPoint.x, testPoint.z);
//    //}
//    return testPoint.y < height;
//}
//bool intersectionInRange(float start, float finish, glm::vec3 ray, Camera* camera) {
//    glm::vec3 startPoint = getPointOnRay(ray, start,camera);
//    glm::vec3 endPoint = getPointOnRay(ray, finish,camera);
//    return !isUnderGround(startPoint) && isUnderGround(endPoint);
//}

