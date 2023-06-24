#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

float ResultFunc(float x, float t, float s);

float Integral(float ResultFunc(float, float, float), float t, float s, float a, float b, int n);

void ResultIntegral(float s1 = 0, float s2 = 0.5, float eps_s = 0.1, float t1 = 0.5, float t2 = 2.5, 
float eps_t = 0.5, int a = 1, int b = 2, float eps = 1e-6);