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
    bool usado= false;
    int id1, id2;
    int num_tags;
    array<string, MAX_TAGS> tags = array<string, MAX_TAGS>();

    Imagen(int _id1, int _id2, int _num_tags, array<string, MAX_TAGS>& _tags){
        id1 = _id1;
        id2 = _id2;
        num_tags = _num_tags;
        array<string, MAX_TAGS> tags = _tags;
    }

    Imagen(int _id1, int _num_tags, array<string, MAX_TAGS>& _tags){
        id1 = _id1;
        id2 = -1;
        num_tags = _num_tags;
        array<string, MAX_TAGS> tags = _tags;
    }

    Imagen() {}
};


#endif //HASHCODE2019_IMAGEN_H
