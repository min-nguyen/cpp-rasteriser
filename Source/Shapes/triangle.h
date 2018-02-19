#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glm/glm.hpp>
#include "shape2D.h"
#include "../Light/intersection.h"
#include "../Light/ray.h"
using glm::vec3;
using glm::vec4;
using glm::mat3;

class Triangle : public Shape2D
{
public:
    glm::vec4 v0;
    glm::vec4 v1;
    glm::vec4 v2;
    glm::vec4 normal;

    Triangle(glm::vec4 v0, glm::vec4 v1, glm::vec4 v2, glm::vec3 color, glm::vec3 gloss)
        :  Shape2D(color, gloss), v0(scalevertex(v0)), v1(scalevertex(v1)), v2(scalevertex(v2)), normal(ComputeNormal())
    {
    }

    virtual bool intersect(Ray& ray, vec3 dir, vec4& intersectionpoint) override {

        vec3 e1 = vec3(v1.x - v0.x, v1.y - v0.y, v1.z - v0.z);
        vec3 e2 = vec3(v2.x - v0.x, v2.y - v0.y, v2.z - v0.z);
        vec3 b = vec3(ray.position.x - v0.x, ray.position.y - v0.y, ray.position.z - v0.z);
        mat3 A( -dir, e1, e2 );
        vec3 x = glm::inverse( A ) * b;

        float t = x.x;
        float u = x.y;
        float v = x.z; 

        if (0 <= t && 0 <= u && 0 <= v && u + v <= 1) { 
            intersectionpoint = tocamcoordinates(x.y, x.z);
            return true;
        }
        return false;
    }

    virtual vec4 tocamcoordinates(float u, float v){
        vec4 e1 = v1 - v0;
        vec4 e2 = v2 - v0;
        return v0 + u * e1 + v * e2;
    }

    virtual vec3 getnormal(vec4 start, vec4 dir){
        return  glm::normalize(glm::triangleNormal((vec3) v0, (vec3) v1, (vec3) v2));
    }


private:
    virtual bool isEqual(const Shape2D& other) const override {
        Triangle tri = static_cast<const Triangle&>(other);
        if( (v0 == tri.v0 && v1 == tri.v1 && v2 == tri.v2) ||
            (v0 == tri.v0 && v1 == tri.v2 && v2 == tri.v1) ||
            (v0 == tri.v1 && v1 == tri.v2 && v2 == tri.v0) ||
            (v0 == tri.v1 && v1 == tri.v0 && v2 == tri.v2) ||
            (v0 == tri.v2 && v1 == tri.v0 && v2 == tri.v1) ||
            (v0 == tri.v2 && v1 == tri.v1 && v2 == tri.v0)){
            return true;
        }
        return false;
    }

    vec4 ComputeNormal()
    {
        vec4 norm;
        glm::vec3 e1 = glm::vec3(v1.x-v0.x,v1.y-v0.y,v1.z-v0.z);
        glm::vec3 e2 = glm::vec3(v2.x-v0.x,v2.y-v0.y,v2.z-v0.z);
        glm::vec3 normal3 = glm::normalize( glm::cross( e2, e1 ) );
        norm.x = normal3.x;
        norm.y = normal3.y;
        norm.z = normal3.z;
        norm.w = 1.0;
        return norm;
    }

    vec4 scalevertex(vec4 v) {
        v *= 2/L;
        v -= vec4(1,1,1,1);
        v.x *= -1;
        v.y *= -1;
        v.w = 1.0;
        return v;
    }

};
#endif