//
// Created by cms on 28/02/19.
//

#ifndef HASHCODE2019_IMAGEN_H
#define HASHCODE2019_IMAGEN_H

#define MAX_TAGS 100

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Imagen {
public:
    int id;
    int num_tags;
    array<string, MAX_TAGS> tags = array<string, MAX_TAGS>();

    Imagen(int _id, int _num_tags, array<string, MAX_TAGS>& _tags){
        id = _id;
        num_tags = _num_tags;
        array<string, MAX_TAGS> tags = _tags;
    }

    Imagen() {}
};


#endif //HASHCODE2019_IMAGEN_H
