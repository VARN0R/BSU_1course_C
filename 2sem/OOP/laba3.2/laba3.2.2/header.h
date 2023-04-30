#pragma once
#include <iostream>
#include <vector>



void inputMatrix(std::vector<std::vector<double>>&Matrix, int rows, int columns);

void outputMatrix(std::vector<std::vector<double>>&Matrix, int rows, int columns);

void Multiplay(std::vector<std::vector<double>>&Matrix, int rows, std::vector<std::vector<double>>&Matrix2, int columns);

void Exponentation(std::vector<std::vector<double>>&Matrix, int rows, int columns);