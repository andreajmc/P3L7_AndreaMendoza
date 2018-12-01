//
// Created by andrea on 11/30/18.
//

#include "Matriz.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

Matriz::Matriz(int size, const string &name) : size(size), name(name) {
    matrix = createIntMatrix(size);
    initIntMatrix(matrix, size);
    det = getDeterminant(size, matrix);
}

Matriz::Matriz() {}

int Matriz::getDeterminant(int size, int** matrix) {
    if (size == 2) {
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    } else if (size == 3) {
        return matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]) -
               matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]) +
               matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);
    }
}

void Matriz::initIntMatrix(int** matrix,int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << endl << "Ingrese un elemento para la matriz: ";
            cin >> matrix[i][j];
        }
    }
}

void Matriz::freeIntMatrix(){
    for(int i=0;i<size;i++){
        delete[] matrix[i];
        matrix[i]= nullptr;
    }
    delete[] matrix;
    matrix= nullptr;
}

int** Matriz::createIntMatrix(int size){
    int** retVal= nullptr;
    retVal=new int*[size];
    for(int i=0;i<size;i++){
        retVal[i]=new int [size];
    }
    return retVal;
}

void Matriz::printIntMatrix() {
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"  "<<matrix[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int **Matriz::transposeMatrix(int ** matrix, int size) {
    int** temp = createIntMatrix(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = temp[j][i];
        }
    }
    return temp;
}

int Matriz::getSize() const {
    return size;
}

int Matriz::getDet() const {
    return det;
}

const string &Matriz::getName() const {
    return name;
}

int **Matriz::getMatrix() const {
    return matrix;
}

void Matriz::setMatrix(int **matrix) {
    Matriz::matrix = matrix;
}

