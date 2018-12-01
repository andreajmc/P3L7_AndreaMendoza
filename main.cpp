#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Matriz.h"
#include <vector>
#include <string.h>


using std::vector;

vector <string> tokenize(string, char, vector<Matriz>);

int main() {
    int flag = 0;
    vector<Matriz> Matrices;
    while (flag != 5) {
        cout<<"----MENÚ----"<<endl<<
        endl<<"(1) Crear Matrices." <<
        endl<<"(2) Listar Matrices." <<
        endl<<"(3) Eliminar Matrices."<<
        endl<<"(4) Operar Matrices."<<
        endl<<endl<<"(5) Salir."<<
        endl<<"Ingrese el número correspondiente a su opción: ";
        cin>>flag;

        if (flag == 1) {
            int size = 0;
            string name;
            cout<<endl<<"Ingrese el tamaño de la matriz (2 o 3): ";
            cin>>size;
            if (size < 2 || size > 3) {
                cout<<endl<<"Ha ingresado un tamaño inválido. Inténtelo de nuevo: ";
                cin>>size;
            }
            cout<<endl<<"Ingrese el nombre de la matriz: ";
            cin>>name;
            Matrices.emplace_back(size,name);
            cout<<endl<<"Matriz creada exitósamente."<<endl;
        } else if (flag == 2) {
            cout<<endl<<"-- LISTA DE MATRICES --"<<endl;
            for (const auto &item : Matrices) {
                cout<<"- "<<item.getName()<<"   Size: "<<item.getSize();
            }
            cout<<endl;
        } else if (flag == 3) {
            int del = 0;
            cout<<endl<<"-- MATRICES DISPONIBLES --"<<endl;
            for (int i = 0; i < Matrices.size(); ++i) {
                cout<<i+1<<".-"<< Matrices.at(i).getName();
            }
            cout<<endl<<"¿Qué matriz desea eliminar? Ingrese el número correspondiente: ";
            cin>>del;
            --del;
            Matrices.at(del).freeIntMatrix();
            Matrices.erase(Matrices.begin()+del,Matrices.begin()+del+1);
        } else if (flag == 4) {
            string op;
            char operators [] = {'|','>','&','+','*'};
            cout<<"Ingrese la operación que desea realizar: ";
            cin>>op;
            for (int i = 0; i < 7; ++i) {
                char test = operators[i];
                if (op.find(test) != std::string::npos) {
                    vector<string> mNames;
                    char c = operators[i];
                    mNames = tokenize(op, c, Matrices);
                    Matriz A, B;
                    for (const auto &item : Matrices) {
                        if (item.getName() == mNames[1]) {
                            A = item;
                        } else if (item.getName() == mNames[2]) {
                            B = item;
                        }
                    }
                    if (i == 0) {
                        Matriz temp = Matriz(A.getSize(), op);
                        temp.setMatrix(A|B);
                        temp.printIntMatrix();
                        Matrices.push_back(temp);
                        break;
                    } else if (i == 1) {
                        Matriz temp = Matriz(A.getSize(), op);
                        int x = 0;
                        cout<<"Ingrese un escalar: ";
                        cin>>x;
                        temp.setMatrix(A>x);
                        temp.printIntMatrix();
                        Matrices.push_back(temp);
                        break;
                    } else if (i == 2) {
                        Matriz temp = Matriz(A.getSize(), op);
                        temp.setMatrix(A&B);
                        temp.printIntMatrix();
                        Matrices.push_back(temp);
                        break;
                    } else if (i == 3) {
                        Matriz temp = Matriz(A.getSize(), op);
                        temp.setMatrix(A+B);
                        temp.printIntMatrix();
                        Matrices.push_back(temp);
                        break;
                    } else if (i == 4) {
                        Matriz temp = Matriz(A.getSize(), op);
                        int x = 0;
                        cout<<"Ingrese un escalar: ";
                        cin>>x;
                        temp.setMatrix(A*x);
                        temp.printIntMatrix();
                        Matrices.push_back(temp);
                        break;
                    }
                }
                if (i == 5) {
                    cout<<"Ha ingresado una operación inválida.";
                }
            }
            string test = "++";
            string test2 = "--";
            if (op.find(test) != std::string::npos) {
                string name;
                for (char i : op) {
                    if (i != '+') {
                        name += i;
                    } else {
                        break;
                    }
                }
                Matriz A;
                for (const auto &item : Matrices) {
                    if (item.getName() == name) {
                        A = item;
                    }
                }
                ++A;
                A.printIntMatrix();
            } else if (op.find(test2) != std::string::npos) {
                string name;
                for (char i : op) {
                    if (i != '-') {
                        name += i;
                    } else {
                        break;
                    }
                }
                Matriz A;
                for (const auto &item : Matrices) {
                    if (item.getName() == name) {
                        A = item;
                    }
                }
                --A;
                A.printIntMatrix();
            }
        } else {
            cout<<"Ha ingresado una opción inválida.";
        }
    }

}

vector<string> tokenize(string op, char del, vector <Matriz> Matrices) {
    string name;
    bool f = false;

    for (char i : op) {
        if (i == del) {
            f = true;
        }

        if (f) {
            name += i;
        }
    }
    Matriz A;
    for (const auto &item : Matrices) {
        if (item.getName() == name) {
            A = item;
        }
    }
}