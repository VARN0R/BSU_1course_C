#pragma once //Чтобы скомпилилось один раз, дабы избежать ошибок

#include<bits/stdc++.h>

void get_words(char** words, const int MAX, char* sentence, int &counter_words);

void low_registr(char** words, int counter_words, char* str, int length_word);

void sort_words(char** words, int counter_words);