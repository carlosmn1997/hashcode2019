#include <iostream>
#include <algorithm>
#include "Imagen.h"

#define CORBI
using namespace std;

int get_comunes(Imagen& i1, Imagen& i2){

    // Numero comunes
    int comunes = 0;
    for (int i = 0; i < i1.num_tags; i++){
        for (int j = 0; j < i2.num_tags; j++){
            if(i1.tags[i] == i2.tags[j]){
                comunes++;
            }
        }
    }
    return comunes;
}

int get_interes(Imagen& i1, Imagn& i2){
    int comunes = get_comunes(i1, i2);
    int interes = min(comunes, i1.num_tags-comunes, i2.num_tags-comunes);
    return interes;
}

#ifndef CORBI

int main(){
    // funcion corbalan


}

#endif