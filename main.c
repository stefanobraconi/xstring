// Demo for xstring.h

#include <stdio.h>   // for printf

#include "xstring.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[50]="Test1, Test2,    Test3! Test4!    Test5;"; // Test string

	strdelch(str, ' '); // delete blank spaces in string

	char splitted[MAXPARSE][MAXSTRINGVALUE]; // declare array of strings

	char symbol[2]= {',','!'}; // Declare control symbol list
	char nsymbol=2; // n symbol

	int n=xstrtok(str,symbol,nsymbol,splitted);

	printf("Source string: %s\n\nand now split...\n\n",str);
	// show the result
	for (int i=0; i<n; i++) {
		printf("%s\n",splitted[i]);
	}
	
	char str2[100]="CYCLE A FOR 10, WHILE testvariable=SQRT(a+10);";
	char splitted2[MAXPARSE][MAXSTRINGVALUE];
	char keywords[MAXPARSE][MAXSTRINGVALUE];
	strcpy(keywords[0],"CYCLE");
	strcpy(keywords[1],"FOR");
	strcpy(keywords[2],"WHILE");
	strcpy(keywords[3],"=");
	strcpy(keywords[4],"SQRT");
	strcpy(keywords[5],"(");
	strcpy(keywords[6],")");
	int nkeyw=7;
	int n2=xstrwtok(str2,keywords,nkeyw,splitted2);
	printf("\n\nSource string: %s\n\nand now split...\n\n",str2);
	// show the result
	for (int i=0; i<n2; i++) {
		printf("%s\n",splitted2[i]);
	}
	
	printf("\n\nEnjoy!");
	return 0;
}