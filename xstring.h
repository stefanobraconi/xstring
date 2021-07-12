// Extended set of C string management,  by Stefano Braconi - 2021	calico.vae@gmail.com
// released under GPLv3
// Header file

// include guard
#ifndef __XSTRING_H_INCLUDED__
#define __XSTRING_H_INCLUDED__

// included dependencies
#include <string.h>

// you can modify this limits...
#define MAXSTRINGVALUE 400	// max length of strings.
#define MAXPARSE 1000		// max number of parsed string can found.

#define NO_CONTROL_CODE 0	// for xstrwtok function.
#define YES_CONTROL_CODE 1	// ^^^

#define F 0		// false
#define T 1		// true

// Delete all char <value> in <str>
void strdelch(char *str, char value);

// Search <word> in a string <str> from arbitrary <position> and return 1/true if exist
int strwchk(char *word, char *str, int position);

// Check if string element <value> is a separator character <controlsymbol>[nsymbol]. Return 1 if found/true # 0 if not found/false
// this function is a fundamental part of xstrtok function.
int xstrtok_check(char value, char *controlsymbol, int nsymbol);

// Separates a string <codeline> using a list of n <nsymbol> control characters <controlsymbol>[nsymbol]
// Note: splitted array also contain control character separately; see main.c for example.
// Return n of splitted element.
int xstrtok(char *codeline, char *controlsymbol, int nsymbol, char parsed[][MAXSTRINGVALUE]);

// This function serve for xstrwtok and have the same function of xstrtok_check but whith string control instead a character control
int xstrwtok_check(char *target, int idx_target, char controlsymbol[][MAXSTRINGVALUE], int nsymbol, char *ret_control);

// Same of xstrtok but with an array of control code string. See main.c for example.
int xstrwtok(char *codeline, char controlsymbol[][MAXSTRINGVALUE], int nsymbol, char parsed[][MAXSTRINGVALUE]);

#endif // __XSTRING_H_INCLUDED__