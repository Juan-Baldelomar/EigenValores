/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juan
 *
 * Created on September 22, 2020, 1:22 PM
 */

#include <cstdlib>
#include "Tools.hpp"
#include "Solvers.hpp"

using namespace std;



void ejercicio1(){
    vector<vector<double>> A;
    vector<double> v;

    ReadMatrix(A, "Insumo_Tarea06/Eigen_3x3.txt");
    v.assign(A.size(), 0.0);
    double lambda;

    PotenciaInversa(A, v, lambda, 0.000001, 6000);

    WriteVector(v, "Out/EigenVector_3x3_out.txt");
    ReadMatrix(A, "Insumo_Tarea06/Eigen_3x3.txt");
    cout << "Valor propio mas pequeño "<< lambda << endl;
    
    cout << "Vector Propio asociado " <<  v << endl;
    printf("%.10f", lambda);

    vector<double> b;
    b.assign(v.size(), 0);

    for (int i = 0; i < v.size(); i++)
        b[i] = lambda * v[i];
    
    Try_Sol(A, b, v);
}


int main(int argc, char** argv) {
    ejercicio1();
    return 0;
}

