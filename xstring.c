// Extended set of C string management,  by Stefano Braconi - 2021	calico.vae@gmail.com
// released under GPLv3
// Source Code

#include "xstring.h"

void strdelch(char *str, char value) {
	int idxsource=0;
	int idxdest = 0;
	char strdest[strlen(str)+1];
	while (str[idxsource] != '\0') {
		if (str[idxsource]!=value) {
			strdest[idxdest]=str[idxsource];
			idxdest++;
		}
		idxsource++;
	}
	strdest[idxdest] = '\0';
	strcpy(str, strdest);
}

int strwchk(char *word, char *str, int position) {
	int len = strlen(str);
	if (len - strlen(word) < strlen(word))
		return F;
	if (position > len)
		return F;
	int idxcomp = 0;
	for (int idx = position; idx < position + strlen(word); idx++) {
		if (word[idxcomp] != str[idx])
			return F;
		idxcomp++;
	}
	return T;
}

int xstrtok_check(char value, char *controlsymbol, int nsymbol) {
	for (int i = 0; i < nsymbol; i++)
		if (value == controlsymbol[i])
			return T;
	return F;
}

int xstrtok(char *codeline, char *controlsymbol, int nsymbol, char parsed[][MAXSTRINGVALUE]) {
	int idx_eq = 0; // codeline[idxeq]
	int idx_v = 0;	// parsed[idx_parse][idx_v]
	int idx_parse = 0;
	while (codeline[idx_eq] != '\0') {
		if (xstrtok_check(codeline[idx_eq], controlsymbol, nsymbol) == 1) {
			if (xstrtok_check(codeline[idx_eq - 1], controlsymbol, nsymbol) == 0) {
				parsed[idx_parse][idx_v] = '\0';
				idx_parse++;
			}
			idx_v = 0;
			parsed[idx_parse][idx_v] = codeline[idx_eq];
			parsed[idx_parse][idx_v + 1] = '\0';
			idx_parse++;
		} else {
			parsed[idx_parse][idx_v] = codeline[idx_eq];
			idx_v++;
		}
		idx_eq++;
	}
	return idx_parse+1;
}

int xstrwtok_check(char *target, int idx_target, char controlsymbol[][MAXSTRINGVALUE], int nsymbol, char *ret_control) {
	for (int i=0; i<nsymbol; i++) {
		if(strwchk(controlsymbol[i], target, idx_target)==T) {
			strcpy(ret_control,controlsymbol[i]);   // return controlcode found in *ret_control
			return strlen(ret_control);				// ... and the length of *ret_control
		}
	}
	ret_control[0]='\0';
	return 0;
}

int xstrwtok(char *codeline, char controlsymbol[][MAXSTRINGVALUE], int nsymbol, char parsed[][MAXSTRINGVALUE]) {
	int idx_cl=0; // codeline source index
	int idx_parse=0;
	int idx_v=0;
	int flag=F; // control word found!
	char control_code[MAXSTRINGVALUE]; // control word found is here
	int laststatus=NO_CONTROL_CODE; // set last state in "the last cycle have not found a controlcode
	while (codeline[idx_cl]!='\0') {
		flag=xstrwtok_check(codeline,idx_cl,controlsymbol,nsymbol,control_code);
		if (flag==0) { // no control code found the copy the character 
			parsed[idx_parse][idx_v]=codeline[idx_cl];
			idx_cl++;
			idx_v++;
			laststatus=NO_CONTROL_CODE; // setting last status
		} else { // control code found
			if (idx_parse>0 && laststatus==NO_CONTROL_CODE) { // if last cycle is not a controlcode terminate last string.
				parsed[idx_parse][idx_v]='\0';
				idx_parse++; // ... go in another new split element.
			}
			strcpy(parsed[idx_parse],control_code);
			idx_cl+=strlen(control_code); // or idx_cl+=flag;
			idx_v=0;
			laststatus=YES_CONTROL_CODE;
			idx_parse++;
		}
	}
	return idx_parse+1;
}
