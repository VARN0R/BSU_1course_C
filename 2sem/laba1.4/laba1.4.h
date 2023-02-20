#pragma once

float Func1(float x);

float DerivativeFirst(float x);

float DerivativeSecond(float x);




float Func2(float x, float s);

float DerivativeFirst2(float x, float s);

float DerivativeSecond2(float x, float s);


void TangentMethod1(float a = 1, float b = 4, float eps = 1e-6, float Func1(float) = Func1);

void TangentMethod2(float a = 0, float b = 1.5, float eps = 1e-6, float s_start = 1, float s_end = 1.15, float s_eps = 0.05, float Func2(float, float) = Func2);