#include <iostream>
#include <algorithm>
#include <cstring>
#include "Imagen.h"
#include <iostream>
#include <fstream>
#include <array>
#include <vector>

#define MAX_TAGS 30

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

#define MAX_IMGS 2500
int main(int argc, char** argv){

    vector<Imagen> verts = vector<Imagen>();
    vector<Imagen> horizs = vector<Imagen>();
//    Imagen imagenes[MAX_IMGS];
    ifstream inFile(argv[1], ifstream::in);
    int totalImgs;
    inFile >> totalImgs;
    cout << totalImgs << endl;
    char type;
    int totalTags;
    string tag;
    int totalHorizs = 0;
    int totalVerts = 0;
    for (int i=0; i<totalImgs; i++) {
        cout << i << endl;
        inFile >> type;
        inFile >> totalTags;
        array<string, MAX_TAGS> tags = array<string, MAX_TAGS>();
        for (int j=0; j<totalTags; j++) {
            inFile >> tag;
            tags[j] = tag;
        }
        if (type == 'H') {
            //horizs[totalHorizs] = Imagen(i, totalTags, tags);
            totalHorizs++;
        } else {
            //verts[totalVerts] = Imagen(i, totalTags, tags);
            totalVerts++;
        }
        cout << type << endl;
        for (int k=0; k<totalTags; k++) {
            cout << tags[k] << endl;
        }
    }
    inFile.close();

    return 0;
}
