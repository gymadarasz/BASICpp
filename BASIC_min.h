#pragma once

// ------------------ BASIC ---------------------
// This is the basics of BASIC, implemented as
// C macros. This header file supposed to works
// independently on any platforms as a minimum,
// it implements everything based on C itself

// Minimal requirements for a minimum BASIC
void basic(void*) {}
#define _BASIC(...) { basic(__VA_ARGS__);
#define BASIC _BASIC(NULL
#define NOT !
#define AND &&
#define OR ||
#define _LET(x) x;
#define LET _LET(
bool BASIC_cond(bool a, bool) {return a;}
#define IF if(BASIC_cond(
#define THEN ,false))
int* BASIC_for_iptr; // <--- TODO make it an array and use for nested FOR loops
#define __FOR(a, b) for (BASIC_for_iptr = &(a); *BASIC_for_iptr<=(b); (*BASIC_for_iptr)++) { 
#define _FOR(...) __FOR(__VA_ARGS__)
#define FOR _FOR(
#define TO ,
#define _NEXT() ;}
#define NEXT _NEXT(
#define _L(x) basic_label_##x:;
#define L _L(
#define _GOTO(x) goto basic_label_##x;
#define GOTO _GOTO(
#define END LET })

// ---------------------------------------
// The following are not "structly" necessary to have a simple BASIC
// but could be handy if you don't want to come back to C/C++

// Minimum C compatible process controls
#define _RETURN(...) return (__VA_ARGS__);
#define RETURN _RETURN(
#define _RET return;
#define RET _RET

#define BEGIN LET { 

#define _SUB(fun) void fun() {
#define SUB _SUB(

#define _GOSUB(fun) fun();
#define GOSUB _GOSUB(

// ELSE, IFELSE, ENDIF: more robust IF conditions
#define ELSE else
#define IFELSE } else
#define ENDIF LET }

// WHILE..DO..ENDWHILE as C while loop
#define WHILE while(BASIC_cond(
#define DO ,false))
#define ENDWHILE LET }

// SFOR..STEP: For loops are able to use STEP (positive integers only)
#define __SFOR(a, b, s) for (BASIC_for_iptr = &(a); *BASIC_for_iptr<=(b); (*BASIC_for_iptr)+=(s)) { 
#define _SFOR(...) __SFOR(__VA_ARGS__)
#define SFOR _SFOR(
#define STEP ,

// LINE, LABEL: Handy macros for "L" as LINE and "L" as LABEL
#define LINE _L(
#define LABEL _L(

// ------------------- LIB (platfor independent) ---------------------
// simple linear congruential generator algorithm
// to generate a pseudo-random number based on a given seed value
// need: int seed = time(NULL); // from <cmath>
#define RND(seed, min, max) ((unsigned int)(seed = (seed * 1103515245 + 12345) % 2147483648U) % ((max) - (min) + 1) + (min))

#define NOR(a, b) (!((a) || (b)))

