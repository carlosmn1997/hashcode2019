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
            if(i1.tags[i].compare(i2.tags[j])){
                comunes++;
            }
        }
    }

    int interes = min(min(comunes, i1.num_tags-comunes), i2.num_tags-comunes);
    return interes;
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
    Imagen i1=horizs[0];
//    horizs[0].usado= true;

//    for (int i = 0; i < horizs.size()-1; ++i){
//        int max_interes = -1;
//        int index_max_interes = -1;
//        if(!horizs[i].usado){
//            i1 = horizs[i];
//            horizs[i].usado= true;
//        } else continue;
//        for (int j = 0; j < horizs.size(); ++j) {
//            if(horizs[j].usado and j!=i){
//                continue;
//            }
//            int interes = getInteres(i1, horizs[j]);
//            if (interes > max_interes){
//                max_interes = interes;
//                index_max_interes = j;
//            }
//        }
//        slides.push_back(horizs[index_max_interes]);
//        horizs[index_max_interes].usado = true;
//    }

    return 0;
}
