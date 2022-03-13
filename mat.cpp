//
// Created by itamarq on 06/03/2022.
//

#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace ariel {
    const int low_value = 33;
    const int upper_value = 126;
    void validateInput(int col, int row, char firstSym, char secondSym) {
        if (col <= 0 || row <= 0 || (int) col != col || (int) row != row || col % 2 == 0 || row % 2 == 0) {
            throw invalid_argument("Mat size is always odd");
        }if( firstSym < low_value || firstSym >upper_value || secondSym < low_value || secondSym > upper_value){
            throw invalid_argument("Symbol ascii value must be between 33 and 126");
        }
    }

    string mat(int col, int row, char firstSym, char secondSym) {
        validateInput(col, row, firstSym, secondSym);
        bool flag_first_sym = true;
        vector <vector<char>> mat(row, vector<char>(col));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = firstSym;

            }
        }

        int left = 1;
        int right = col - 2;
        int top = 1;
        int bottom = row - 2;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                mat[top][i] = secondSym;
                mat[bottom][i] = secondSym;

            }
            for (int i = top; i <= bottom; ++i) {

                mat[i][right] = secondSym;
                mat[i][left] = secondSym;

            }
            flag_first_sym = !flag_first_sym;
            top+=2;
            bottom-=2;
            right-=2;
            left+=2;
        }

        string design;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                design += mat[i][j];
            }
            design += '\n';
        }
        return design;
    }



}