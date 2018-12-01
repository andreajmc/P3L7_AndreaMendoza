//
// Created by andrea on 11/30/18.
//

#ifndef LAB7_ANDREAMENDOZA_MATRIZ_H
#define LAB7_ANDREAMENDOZA_MATRIZ_H
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

class Matriz {
public:
    Matriz(int size, const string &name);

    Matriz();

    int getDeterminant(int, int**);
    void initIntMatrix(int**, int);
    void freeIntMatrix();
    void printIntMatrix();
    int** createIntMatrix(int);
    int ** transposeMatrix(int**, int);
    int getSize() const;
    int getDet() const;
    const string &getName() const;
    int **getMatrix() const;


    int** operator| (Matriz M) {
        if (size == M.getSize()) {
            int** answer = createIntMatrix(size);
            int** matrix2 = M.getMatrix();
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    answer[i][j] = matrix[i][j] + matrix2[i][j];
                }
            }
            cout<<endl<<"Suma realizada existósamente."<<endl;
            return answer;
        } else {
            cout<<"No se puede realizar la operación porque las matrices no tienen el mismo tamaño."<<endl;
            return nullptr;
        }
    }

    void operator++ () {
        int k = abs(getDet()-getSize());
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = matrix[i][j]+k;
            }
        }
        cout<<endl<<"Incremento realizado exitósamente."<<endl;

    }

    void operator-- () {
        int k = abs(getDet()-getSize());
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = matrix[i][j]-k;
            }
        }
        cout<<endl<<"Decremento realizado exitósamente."<<endl;
     }

    int** operator> (int k) {
        int** answer = createIntMatrix(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                answer[i][j] = matrix[i][j]*k;
            }
        }
        cout<<endl<<"Multiplicación por escalar realizada exitósamente."<<endl;
        return answer;
    }

    int** operator& (Matriz M) {
        if (size == M.getSize()) {
            int** matrix2 = M.getMatrix();
            int temp = 0;
            int **answer = createIntMatrix(size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    for (int k = 0; k < size; ++k) {
                        temp += matrix[i][k]*matrix2[k][j];
                    }
                    answer[i][j] = temp;
                    temp = 0;
                }
            }
            return answer;
        } else {
            cout<<"No se puede realizar la operación porque las matrices no tienen el mismo tamaño."<<endl;
            return nullptr;
        }
    }

    int** operator+ (Matriz M) {
        if (size == M.getSize()) {
            int** matrix2 = M.getMatrix();
            int** answer = createIntMatrix(size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (i == j) {
                        answer[i][j] = size*(matrix[i][j]-matrix2[i][j]);
                    } else {
                        answer[i][j] = matrix[i][j] + matrix2[i][j];
                    }
                }
            }
            return answer;
        } else {
            cout<<"No se puede realizar la operación porque las matrices no tienen el mismo tamaño."<<endl;
            return nullptr;
        }
    }

    int** operator* (int k) {
        if (k != 0) {
            int det = getDet();
            int** answer = createIntMatrix(size);
            int **auxMatrix = transposeMatrix(matrix, size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    answer[i][j] = (det/k)*matrix[i][j];
                }
            }
            return answer;
        } else {
            cout<<"No se puede realizar la operación porque el número ingresado es 0."<<endl;
            return nullptr;
        }
    }

    void setMatrix(int **matrix);

private:
    int size;
    int det;
    string name;
    int** matrix;
};


#endif //LAB7_ANDREAMENDOZA_MATRIZ_H
