#include <iostream>
#include <algorithm>
#include <cstring>
#include "Imagen.h"
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

using namespace std;

int getInteres(Imagen& i1, Imagen& i2){

    // Numero comunes
    int comunes = 0;
    for (int i = 0; i < i1.num_tags; i++){
        for (int j = 0; j < i2.num_tags; j++){
            if(i1.tags[i] == i2.tags[j]){
                comunes++;
            }
        }
    }

    int interes = min(min(comunes, i1.num_tags-comunes), i2.num_tags-comunes);
    return interes;
}

int getCompatibilidad(Imagen i1, Imagen i2){

    int numNoComunes = 0;
    for (int i = 0; i < i1.num_tags; i++){
        for (int j = 0; j < i2.num_tags; j++){
            if(i1.tags[i] == i2.tags[j]){
                numNoComunes++;
            }
        }
    }
    return numNoComunes;
}

vector<Imagen> mezclaVertical(vector<Imagen> vertics){
    vector<Imagen> res = vector<Imagen>();

    Imagen i1 = vertics[0];
    for (int i = 0; i < vertics.size()-1; ++i) {
        int max_diferentes = -1;
        int index_max_interes = -1;
        if (!vertics[i].usado) {
            i1 = vertics[i];
            vertics[i].usado = true;
        } else continue;
        for (int j = 0; j < vertics.size(); ++j) {
            if (vertics[j].usado and j != i) {
                continue;
            }
            int diferencia = getInteres(i1, vertics[j]);
            if (diferencia > max_diferentes) {
                max_diferentes = diferencia;
                index_max_interes = j;
            }
        }
    }

    return res;
}

#define MAX_IMGS 2500
int main(int argc, char** argv){

    ifstream inFile(argv[1], ifstream::in);
    vector<Imagen> verts = vector<Imagen>();
    vector<Imagen> horizs = vector<Imagen>();

//    Imagen imagenes[MAX_IMGS];
    int totalImgs;
    inFile >> totalImgs;
    cout << totalImgs << endl;
    char type;
    int totalTags;
    string tag;
    int totalHorizs = 0;
    int totalVerts = 0;
    Imagen img;
    for (int i=0; i<totalImgs; i++) {
        cout << i << endl;
        inFile >> type;
        inFile >> totalTags;
        array<string, MAX_TAGS> tags = array<string, MAX_TAGS>();
        for (int j=0; j<totalTags; j++) {
            inFile >> tag;
            tags[j] = tag;
        }
        img = Imagen(i, -1, totalTags, tags);
        if (type == 'H') {
            horizs.push_back(img);
            totalHorizs++;
        } else {
            verts.push_back(img);
            totalVerts++;
        }
        cout << type << endl;
        for (int k=0; k<totalTags; k++) {
            cout << tags[k] << endl;
        }
    }
    inFile.close();

    vector<Imagen> slides = vector<Imagen>();
    Imagen i1 = horizs[0];
    horizs[0].usado = true;
    slides.push_back(horizs[0]);


    for (int i = 1; i < horizs.size()-1; ++i){
        int max_interes = -1;
        int index_max_interes = -1;

        for (int j = 1; j < horizs.size(); ++j) {
            if(horizs[j].usado and j!=i){
                continue;
            }
            int interes = getInteres(i1, horizs[j]);
            if (interes > max_interes){
                max_interes = interes;
                index_max_interes = j;
            }
        }
        slides.push_back(horizs[index_max_interes]);
        horizs[index_max_interes].usado = true;
    }

    return 0;
}
