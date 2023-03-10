#include <iostream>
using namespace std;
#include "laba2.2.v2.h"


int index(int row, int col, int size) {
    return row * size + col;
}   


void inputMatrix(double *Matrix, int rows, int columns){
    cout << "Enter matrix: " << endl;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> Matrix[index(i,j,rows)];
        }
    }
}



void outputMatrix(double *Matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << Matrix[index(i,j,rows)] << " ";
        }
        cout << endl;
    }
}



void Multiplay(double *Matrix, int rows, double *Matrix2, int columns){
     double* resultMatrix = new double[rows * columns];
    
    for(int k = 0; k < rows; k++){        
            for(int pos = 0; pos < columns; pos++){
            int i = 0;
            int j = 0;
            while(i < rows && j < columns){
                resultMatrix[index(k,pos,rows)]= Matrix[index(pos, j++, rows)] * Matrix2[index(i++, pos, rows)];
              	
            }
        }
    }   
	//потому что мы не можем вернуть resultMatrix
	for(int i = 0; i<rows; i++){
        for(int j = 0;j<rows; j++)
            Matrix[index(i,j,rows)] = resultMatrix[index(i,j,rows)];
    }
   
    
}

void Exponentation(double *Matrix, int rows, int columns){
    int exp;
    cout << "Enter number of exponentation: ";
    cin >> exp;
    double* firstInstance = new double[rows * columns];
        for (int i = 0; i < rows; i++){
        
            for(int j = 0;j<rows; j++){
                firstInstance[index(i,j,rows)] = Matrix[index(i,j,rows)];        
            }
        }
    while(exp>1){
        Multiplay(Matrix, rows, firstInstance, columns);
        exp--;
    }
  

}