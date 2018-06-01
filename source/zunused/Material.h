#ifndef MATERIAL_H
#define MATERIAL_H
#include <glm/glm.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
struct Entry {
    glm::vec3 Ka;
    glm::vec3 Kd;
    glm::vec3 Ks;
    glm::vec3 Ke;
    float Ns;
};

class Material {

    private:
        std::map<std::string, int> materialNameMap;


    public:
        std::vector<Entry> data;
        bool ReadMaterial(const char *filename);
        int MaterialLookup(std::string s);
};
 

#endif //COMPUTER_GRAPHICS_MATERIAL_H
