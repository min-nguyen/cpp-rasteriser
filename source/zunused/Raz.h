#ifndef RAZ_H
#define RAZ_H

// #include "SDLauxiliary.h"
#include "Model.h"
#include <glm/glm.hpp>
#include <vector>
#include "Ren.h"
// //todo remove using from header file

// mat4 Ren::projection;
// mat4 Ren::viewPort;
// mat4 Ren::modelView;
// float Ren::depth;



class Raz : public Ren {

public:
  Raz(Screen* cs, Model* model,Camera &camera, Lighting &lighting);
  void Draw(bool cut);

// protected:
//   glm::vec3 light_pos;
//   glm::vec3 camera_pos;
//   glm::vec3 light_colour;
//   Model* model;
//   Camera &camera;
//   Lighting &lighting;


// private:
//   float *depthBufferCamera;
//   float *depthBufferLight;
//   void DrawTriangle(RenderData *data, Shader &shader, float *z_buffer, Polygon *triangle, bool draw_screen);
//   void DrawPolygon(glm::vec4 *inVertices, glm::vec2 *inTextures, int polyEdgeCount, Shader &shader, float *z_buffer, Polygon *triangle,
//                        bool draw_screen);
//   void LookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
//   void ViewPort(int x, int y, int w, int h);
//   void Projection(float c);
//   glm::vec3 barycentric(glm::vec2 A, glm::vec2 B, glm::vec2 C, glm::vec2 P);
//   //void Clip(vec4 *inVerticies, int inCount);
  
//   struct DepthShader: Shader {
//       Raz *r;
//       glm::mat3 tri;
//       DepthShader(Raz *rr) : r(rr),tri(0) {}
//       bool colour(glm::vec3 bar, glm::vec3 &colour, Polygon *triangle, RenderData *data);
//   };

//   struct Shadow: Shader {
//       Raz *r;
//       glm::mat4 screen_shadow;
//       Shadow(Raz* rr, glm::mat4 sc) : r(rr), screen_shadow(sc) {};
//       bool colour(glm::vec3 bar, glm::vec3 &colour, Polygon *triangle, RenderData *data);
//   };


//   void ProcessPolygons(Model *model, Ren::Shader &shader, float *z_buffer, glm::vec4 *vertices, glm::vec2 *textures,
//                        glm::vec4 *outVertices, glm::vec2 *outTextures,bool clip, bool draw_screen);

};


#endif
