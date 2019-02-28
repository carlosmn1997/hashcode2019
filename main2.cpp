#include <iostream>
#include <fstream>
#include <array>

#define MAX_TAGS 100

using namespace std;

int main(int argc, char** argv) {
    const int maxImgs = 10000;
    //array<Imagen, maxImgs> verts = array<Imagen, maxImgs>();
    //array<Imagen, maxImgs> horizs = array<Imagen, maxImgs>();
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