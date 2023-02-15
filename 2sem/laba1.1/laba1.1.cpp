#include<bits/stdc++.h> 
#include <iomanip>
#include "laba1.1.h"

void input(int** a, int size){
	int row1 = 0;
	int col1 = 0;
	int row2 = size - 1;
	int col2 = size - 1;
	int iter = 1;
	int amount_elements = size * size;
    while (iter <= amount_elements){
		for (int i = col1; i <= col2; i++){
			a[row2][i] = iter++;
		}
		for (int i = row2 - 1; i >= row1; i--){
			a[i][col2] = iter++;
		}
		for (int i = col2 - 1; i >= col1; i--){
			a[row1][i] = iter++;
		}
		for (int i = row1 + 1; i <= row2 - 1; i++){
			a[i][col1] = iter++;
		}
		row1++; col1++; row2--; col2--;
	}
}

void output(int** a, int length){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            std::cout << std::setw(3) << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}