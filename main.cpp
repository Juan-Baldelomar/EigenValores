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
#include <string>
#include <iostream>

using namespace std;



void ejercicio1(){
    vector<vector<double>> A;
    vector<double> v;
    
    string n = "3";
    string name = "Eigen_" + n + "x" + n + ".txt";
    string outName = "EigenVector_" + n + "x" + n + ".txt";
    
    ReadMatrix(A, "Insumo_Tarea06/"+name);
    v.assign(A.size(), 0.0);
    double lambda;

    PotenciaInversa(A, v, lambda, 0.000001, 6000);

    WriteVector(v, "Out/"+outName);
    ReadMatrix(A, "Insumo_Tarea06/"+name);
    cout << "Valor propio mas pequeño "<< lambda << endl;
    
    cout << "Vector Propio asociado " <<  v << endl;
    printf("%.10f", lambda);

    vector<double> b;
    b.assign(v.size(), 0);

    for (int i = 0; i < v.size(); i++)
        b[i] = lambda * v[i];
    
    Try_Sol(A, b, v);
}

void ejercicio2(){
    
    //variables necesarias
    vector<vector<double>> A;
    vector<vector<double>> eigenvectors;
    vector<double> eigenvalues;

    //entrada
    ReadMatrix(A, "Insumo_Tarea06/Eigen_3x3.txt");
    int nEigen = 3;
    
    //procesamiento
    PotenciaInversaDeflacion(A, eigenvectors, eigenvalues, 0.000001, nEigen, 3000);
    
    //salida
    WriteMatrix(eigenvectors, "Out/N_eigenvectors_3x3_out.txt");
    WriteVector(eigenvalues, "Out/N_eigenvalues_3x3_out.txt");
    cout << "los eigenvalores son "<< eigenvalues << endl;
    cout << "los eigenvectores (almacenados cada uno en una fila) son "<< endl << eigenvectors << endl;

    for (int n = 0; n < nEigen; n++) {
        ReadMatrix(A, "Insumo_Tarea06/Eigen_3x3.txt");
        vector<double> b;
        b.assign(3, 0.0);

        for (int i = 0; i < 3 ; i++)
            b[i] = eigenvalues[n] * eigenvectors[n][i];


        Try_Sol(A, b, eigenvectors[n]);
    }
}


void ejercicio3(){
    
    //variables necesarias
    vector<vector<double>> A;
    vector<vector<double>> eigenvectors;
    vector<double> eigenvalues;

    //entrada
    ReadMatrix(A, "Insumo_Tarea06/Eigen_50x50.txt");
    int nEigen = 10;
    
    //procesamiento
    PotenciaInversaDeflacion(A, eigenvectors, eigenvalues, 0.000001, nEigen, 3000);
    
    //salida
    WriteMatrix(eigenvectors, "Out/N_eigenvectors_50x50_out.txt");
    WriteVector(eigenvalues, "Out/N_eigenvalues_50x50_out.txt");
    cout << "los eigenvalores son "<< eigenvalues << endl;
    cout << "los eigenvectores (almacenados cada uno en una fila) son "<< endl << eigenvectors << endl;

    for (int n = 0; n < nEigen; n++) {
        ReadMatrix(A, "Insumo_Tarea06/Eigen_50x50.txt");
        vector<double> b;
        b.assign(50, 0.0);

        for (int i = 0; i < 50 ; i++)
            b[i] = eigenvalues[n] * eigenvectors[n][i];


        Try_Sol(A, b, eigenvectors[n]);
    }
}


void ejercicio4(){
    vector<vector<double>> A; 
    ReadMatrix(A, "Insumo_Tarea06/Eigen_50x50.txt");
    vector<double> eigenvalues;
    eigenvalues.assign(A.size(), 0.0);
   
    JacobiEigenValues(A, eigenvalues, 0.00001, 5000);

    cout << eigenvalues << endl;
    WriteVector(eigenvalues, "Out/Jacobi_Eigen_50x50.txt");
}


int main() {
    ejercicio4();
    return 0;
}

