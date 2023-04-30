#include "header.h"
using namespace std;

void inputMatrix(vector<vector<double>>&Matrix, int rows, int columns){
    cout << "Enter matrix: " << endl;
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cin >> Matrix[i][j];
        }
    }
}

void outputMatrix(vector<vector<double>>&Matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Multiplay(vector<vector<double>>&Matrix, int rows, vector<vector<double>>&Matrix2, int columns){
    vector<vector<double>>resultMatrix(rows, vector<double>(columns));
    
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
        for(int j = 0;j<rows; j++){
            Matrix[i][j] = resultMatrix[i][j];
        }
    }
}

void Exponentation(vector<vector<double>>&Matrix, int rows, int columns){
    int exp;
    cout << "Enter number of exponentation: ";
    cin >> exp;
    vector<vector<double>>firstInstance(rows, vector<double>(rows));
    for(int i = 0; i<rows; i++){
        for(int j = 0;j<rows; j++){
            firstInstance[i][j] = Matrix[i][j];
        }
        cout << endl;
    }
    
    while(exp>1){
        Multiplay(Matrix, rows, firstInstance, columns);
        exp--;
    }

}