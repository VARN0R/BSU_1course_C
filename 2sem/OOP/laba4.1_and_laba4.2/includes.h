#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#define STR_LIM 20
#define N 10000000
using namespace std;

typedef enum RecognitionStatus {
    PRESENT,
    NOT_PRESENT,
    NOT_RECOGNIZED,
} RecognitionStatus;

string getStatusName(RecognitionStatus status);