#include <iostream>
#include <fstream>
#include <array>

using namespace std;

int main(int argc, char** argv) {
    const int maxImgs = 10000;
    array<int, maxImgs> vertics = array<int, maxImgs>();
    array<int, maxImgs> horizs = array<int, maxImgs>();
    ifstream inFile(argv[1], ifstream::in);
    int totalImgs;
    inFile >> totalImgs;
    cout << totalImgs << endl;
    return 0;
}