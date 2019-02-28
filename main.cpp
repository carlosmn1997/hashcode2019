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

    return min(min(comunes, i1.num_tags-comunes), i2.num_tags-comunes);
}

int getCoincidentes(Imagen& i1, Imagen& i2) {
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

#define MAX_IMGS 2500
int main(int argc, char** argv){

    // Lectura entrada
    ifstream inFile(argv[1], ifstream::in);
    vector<Imagen> verts = vector<Imagen>();
    vector<Imagen> horizs = vector<Imagen>();
    int totalImgs;
    inFile >> totalImgs;
    char type;
    int totalTags;
    string tag;
    int totalHorizs = 0;
    int totalVerts = 0;
    Imagen img;
    for (int i=0; i<totalImgs; i++) {
        inFile >> type;
        inFile >> totalTags;
        array<string, MAX_TAGS> tags = array<string, MAX_TAGS>();
        for (int j=0; j<totalTags; j++) {
            inFile >> tag;
            tags[j] = tag;
        }
        img = Imagen(i, totalTags, tags);
        if (type == 'H') {
            horizs.push_back(img);
            totalHorizs++;
        } else {
            verts.push_back(img);
            totalVerts++;
        }
    }
    inFile.close();
    // Depuración lectura entrada
    /*for (Imagen imag : verts) {
        cout << imag.id1 << endl;
        cout << imag.id2 << endl;
        cout << imag.num_tags << endl;
        for (int k = 0; k<imag.num_tags; k++) {
            cout << imag.tags[k] << endl;
        }
        cout << "----" << endl;
    }
    for (Imagen imag : horizs) {
        cout << imag.id1 << endl;
        cout << imag.id2 << endl;
        cout << imag.num_tags << endl;
        for (int k = 0; k<imag.num_tags; k++) {
            cout << imag.tags[k] << endl;
        }
        cout << "----" << endl;
    }*/

    /*vector<Imagen> slides = vector<Imagen>();
    Imagen i1=horizs[0];
    horizs[0].usado= true;

    for (int i = 0; i < horizs.size()-1; ++i){
        int max_interes = -1;
        int index_max_interes = -1;
        if(!horizs[i].usado){
            i1 = horizs[i];
            horizs[i].usado= true;
        } else continue;
        for (int j = 0; j < horizs.size(); ++j) {
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
    }*/
    //Imagen lastVert = verts[0];
    //verts.erase(verts.begin());
    while(verts.size() > 1) {
        Imagen lastVert = verts[0];
        verts.erase(verts.begin());
        int min_comunes = 100000;
        int min_idx = 0;
        for (int i=0; i<verts.size(); i++) {
            int comunes = getCoincidentes(lastVert, verts[i]);
            if (comunes < min_comunes) {
                min_comunes = comunes;
                min_idx = i;
            }
        }
        array<string, MAX_TAGS> mergedTags = array<string, MAX_TAGS>();
        merge(lastVert.tags.begin(), lastVert.tags.begin()+lastVert.num_tags-1, verts[min_idx].tags.begin(), verts[min_idx].tags.begin()+verts[min_idx].num_tags-1, mergedTags.begin());
        Imagen merged = Imagen(lastVert.id1, verts[min_idx].id1, lastVert.num_tags+verts[min_idx].num_tags, mergedTags);
        horizs.push_back(merged);
        verts.erase(verts.begin() + min_idx);
        //lastVert = verts[0];
    }

    vector<Imagen> slides = vector<Imagen>();
    Imagen lastSlide = horizs[0];
    slides.push_back(horizs[0]);    // Añadir a slides
    horizs.erase(horizs.begin());// Eliminar de slides
    while(!horizs.empty()) {
        int best_int = -1;
        int best_idx = 0;
        for (int i=0; i<horizs.size(); i++) {
            int interes = getInteres(lastSlide, horizs[i]);
            if (interes > best_int) {
                best_int = interes;
                best_idx = i;
            }
        }
        slides.push_back(horizs[best_idx]);
        lastSlide = horizs[best_idx];
        horizs.erase(horizs.begin()+best_idx);
        //cout << slides.size() << endl;
    }

    // Escritura salida
    ofstream outFile(argv[2], ofstream::out);
    outFile << slides.size() << endl;
    for (Imagen& slide : slides) {
        outFile << slide.id1;
        if (slide.id2 != -1) {
            outFile << " " << slide.id2 << endl;
        } else {
            outFile << endl;
        }
    }
    outFile.close();

    return 0;
}
