#include <iostream>
#include <algorithm>
#include <cstring>
#include "Imagen.h"

//#define CORBI
using namespace std;

int get_comunes(Imagen& i1, Imagen& i2){

    // Numero comunes
    int comunes = 0;
    for (int i = 0; i < i1.num_tags; i++){
        for (int j = 0; j < i2.num_tags; j++){
            if(i1.tags[i].compare(i2.tags[j])){
                comunes++;
            }
        }
    }

    int interes = min(min(comunes, i1.num_tags-comunes), i2.num_tags-comunes);
    return interes;
}

#ifndef CORBI

#define MAX_IMGS 100000
int main(){

    array<Imagen, MAX_IMGS> imagenes;
    array<Imagen, MAX_IMGS> slides;
    // funcion corbalan

//    slides[0] = imagenes[0];
//    imagenes[0].usado= true;
//    for (int i = 0; i < MAX_IMGS; ++i){
//        int max_interes = 0;
//        for (int j = 0; j < MAX_IMGS; ++j) {
//
//        }
//    }

    return 0;
}

#endif