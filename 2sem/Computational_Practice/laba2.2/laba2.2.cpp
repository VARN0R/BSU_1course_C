#include <iostream>
using namespace std;
#include "laba2.2.h"
void inputMatrix(double **Matrix, int rows, int columns){
    cout << "Enter matrix: " << endl;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> Matrix[i][j];
        }
    }
}



void outputMatrix(double **Matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}



void Multiplay(double **Matrix, int rows, double **Matrix2, int columns){
    double **resultMatrix = new double* [rows]{};
    for(int i = 0; i < rows; i++){
        resultMatrix[i] = new double [columns];
    }
    
    for(int k = 0; k < rows; k++){        
            for(int pos = 0; pos < columns; pos++){
            int i = 0;
            int j = 0;
            while(i < rows && j < columns){
                resultMatrix[k][pos] += Matrix[pos][j++] * Matrix2[i++][pos];
              	
            }
        }
    }
	//потому что мы не можем вернуть resultMatrix
	for(int i = 0; i<rows; i++){
        for(int j = 0;j<rows; j++)
            Matrix[i][j] = resultMatrix[i][j];
    }
}

void Exponentation(double **Matrix, int rows, int columns){
    int exp;
    cout << "Enter number of exponentation: ";
    cin >> exp;
    double **firstInstance = new double*[rows]{};
    for(int i = 0; i<rows; i++){
        firstInstance[i] = new double[rows]{};
        for(int j = 0;j<rows; j++)
            firstInstance[i][j] = Matrix[i][j];
    }
    while(exp>1){
        Multiplay(Matrix, rows, firstInstance, columns);
        exp--;
    }

}