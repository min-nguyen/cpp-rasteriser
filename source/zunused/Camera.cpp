#include "Camera.h"

Camera::Camera (glm::vec3 pos,glm::vec3 dir) : pos(pos) , dir(normalize(dir))
{

}


glm::vec3 Camera::position()
{
	return pos;
}

glm::vec3 Camera::direction() {
	return dir;
}

void Camera::moveDir(glm::vec3 pos) {
	dir += pos;
	dir = normalize(dir);
}

void Camera::movePos(glm::vec3 m) {
	pos += m;
}


std::ostream& operator<<(std::ostream& os, const Camera& cam)
{
	os << "(" << cam.pos.x << "," << cam.pos.y << "," << cam.pos.z << ") || " << "(" << cam.dir.x << "," << cam.dir.y << "," << cam.dir.z << ")";
	return os;
}
