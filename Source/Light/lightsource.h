#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "ray.h"
#include "intersection.h"
#include <glm/glm.hpp>
#include <vector>
#define PI           3.14159265358979323846

using glm::vec3; 

class LightSource{
public:

    glm::vec4 position;
    glm::vec3 color;
    float power;
    LightSource(glm::vec4 pos, glm::vec3 col, float pow) :
        position(pos),color(col), power(pow) {

    };
    LightSource(){
        position    = glm::vec4(0, -0.5, -1.4, 1.0);
        color       = glm::vec3(1,1,1);
        power       = 10.f;
    }
    

    vec3 light_at_position(Intersection& point, const std::vector<Shape2D*>& shapes){
        vec3 directlight    = GetDirectLight(point, shapes);
        vec3 indirectlight  = GetIndirectLight(); 
        return (directlight + indirectlight);
    }

    vec3 GetDirectLight(Intersection& point, const std::vector<Shape2D*>& shapes) {

        if (IsOccluded(point, shapes)) {
            return vec3(0.0001, 0.0001, 0.0001);
        }

        float dist = glm::distance(position, point.position);

        vec3 surfaceNormal =  point.shape2D->getnormal(point.position, point.direction);
        vec3 lightToPoint =   glm::normalize((vec3) point.position - (vec3) position);

        float dotProduct = glm::dot(surfaceNormal, lightToPoint);
        float powPerSurface = (power * std::max(dotProduct, 0.f))/(4 * PI * pow(dist, 2));
        return color * powPerSurface;
    }


    bool IsOccluded(Intersection& point, const std::vector<Shape2D*>& shapes){
        Intersection intersect; 
        vec4 shadow_dir = position - point.position;
        Ray shadow_ray(position, shadow_dir);
        if(shadow_ray.ClosestIntersection(shapes, intersect, intersect.shape2D)){
            if(intersect.shape2D != point.shape2D)
                return true;
        }
        return false;
    }

    vec3 GetIndirectLight(){
        return vec3(0.3,0.2,0.18);
    }
};

#endif