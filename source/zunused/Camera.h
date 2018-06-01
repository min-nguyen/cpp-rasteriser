#ifndef COMPUTER_GRAPHICS_CAMERA_H
#define COMPUTER_GRAPHICS_CAMERA_H


#include <iostream>
#include <glm/glm.hpp>


class Camera
{

private:
		glm::vec3 pos;
		glm::vec3 dir;
public:

    Camera (glm::vec3 pos,glm::vec3 dir);
		void setPos(glm::vec3 pos);
		void setDir(glm::vec3 pos);

		void moveDir(glm::vec3 pos);
		void movePos(glm::vec3 pos);

    glm::vec3 position();
		glm::vec3 direction();
    friend std::ostream& operator<<(std::ostream& os, const Camera& cam);
};



#endif
