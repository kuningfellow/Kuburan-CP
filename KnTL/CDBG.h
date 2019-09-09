#ifndef DEBUG
#include<windows.h>
HANDLE DEBUGHANDLECOLOR = GetStdHandle(STD_OUTPUT_HANDLE);
#define DEBUG(...) {fflush(stdout);fflush(stderr);SetConsoleTextAttribute(DEBUGHANDLECOLOR,10);__VA_ARGS__ fflush(stdout);fflush(stderr);SetConsoleTextAttribute(DEBUGHANDLECOLOR,15);}
#endif
