# xstring
Extended set for C strings management.

XSTRING.H
Extended set for C strings management.
2021, By Stefano Braconi - calico.vae@gmail.com
https://github.com/stefanobraconi

Intro:

Thanks for use this library!
This library serve for extended the functionality of strtok function contained in <string.h> (standard C library)
You can split a string through a list of check codes, be they characters or strings

The header contains this define value:

#define MAXSTRINGVALUE 400	
#define MAXPARSE 1000		

this define the max value of a strings and the max number of splitted elements.

----

#define NO_CONTROL_CODE 0	
#define YES_CONTROL_CODE 1	

this serve for xstrwtok function, DON'T MODIFY!

----

#define F 0		
#define T 1		

this serve for boolean condition, DON'T MODIFY!

Funtions specifications:

void strdelch(char *str, char value);
>>> Delete all char <value> in <str>

int strwchk(char *word, char *str, int position);
>>> Search <word> in a string <str> from arbitrary <position> and return 1/true if exist

int xstrtok(char *codeline, char *controlsymbol, int nsymbol, char parsed[][MAXSTRINGVALUE]);
>>> Separates a string <codeline> using a list of n <nsymbol> control characters <controlsymbol>[nsymbol]
>>> Note: splitted array also contain control character separately; see main.c for example.
>>> Return n of splitted element.

int xstrwtok(char *codeline, char controlsymbol[][MAXSTRINGVALUE], int nsymbol, char parsed[][MAXSTRINGVALUE]);
>>> Same of xstrtok but with an array of control code string. See main.c for example.
