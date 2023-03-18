#pragma once

#include "BASIC_min.h"

// ------- BASIC cstd (PLATFORM SPECIFICS) -----------
// This header file contains function that are depends
// on the standard C lib and more robust but on
// different platforms these can be implemented in a
// various platform specific way


// ------- BASIC IO (PLATFORM SPECIFICS) -----------
// this part is supposed to collect all the IO
// function that are not necessarily part of the BASIC
// language and also the implementation could be 
// specific to the patform, however these functions
// such as PRINT/INPUT are so strictly necessary for 
// real life use-cases. Different platforms such as
// ARDUINO or LINUX machines etc. can implement this
// header diferently

#include <iostream>
using namespace std;
void BASIC_print(double x) {
    (long)x == x ? printf("%ld", (long)x) : printf("%lf", x);
}

void BASIC_print(string x) {
    printf("%s", x.c_str());
}

// void BASIC_print(const char* x) {
//     printf("%s", x);
// }

void BASIC_print_all() {}

template<typename T, typename... Args>
void BASIC_print_all(T first, Args... args) {
    BASIC_print(first);
    BASIC_print_all(args...);
}

void BASIC_input(string& inp, const string& prompt = "") {
    BASIC_print(prompt);
    getline(cin, inp);
}

// void BASIC_input(int& inp, const string& prompt = "") {
//     BASIC_print(prompt);
//     cin >> inp;
//     cin.ignore(); // Clear input buffer to remove any newline characters
// }

// void BASIC_input(double& inp, const string& prompt = "") {
//     BASIC_print(prompt);
//     cin >> inp;
//     cin.ignore(); // Clear input buffer to remove any newline characters
// }

void BASIC_input(int& inp, string prompt = "") {
    printf("%s", prompt.c_str());
    scanf("%d", &inp);
    getchar(); // Clear input buffer to remove any newline characters
}

void BASIC_input(double& inp, string prompt = "") {
    printf("%s", prompt.c_str());
    scanf("%lf", &inp);
    getchar(); // Clear input buffer to remove any newline characters
}


#define _PRINT(...) { \
    BASIC_print_all(__VA_ARGS__); \
    BASIC_print("\n"); \
    fflush(stdout); \
}

#define PRINT _PRINT(
#define PRINTL PRINT ""

#define _INPUT(...) BASIC_input(__VA_ARGS__);
#define INPUT _INPUT(

#define _PROMPT(...) { \
    BASIC_print_all(__VA_ARGS__); \
    fflush(stdout); \
}
#define PROMPT _PROMPT(

// ------------------- LIB (platfor specific) ---------------------
// this part is supposed to collect all the platform specific
// or may/may not C/C++ standard utilities and tools that are not 
// necessarily the part of the BASIC language but nice to have

#include <cstdarg>

#define _EXIT(...) exit(__VA_ARGS__);
#define EXIT _EXIT(

