//
// Created by itamarq on 13/03/2022.
//

#include <iostream>
#include "mat.hpp"
#include <string>
using namespace std;
using namespace ariel;

int main(){
    int col;
    int row;
    char firstSym;
    char secondSym;
    cout << "Please enter desired num of rows. Must be an odd positive integer: \n";
    cin >> row;
    cout << "Please enter desired num of columns. Must be an odd positive integer: \n";
    cin >> col;
    cout << "Please enter first symbol: \n";
    cin >> firstSym;
    cout << "Please enter second symbol: \n";
    cin >> secondSym;
    string designedMat = mat(col, row, firstSym, secondSym);
    cout << designedMat;
    return 0;
}