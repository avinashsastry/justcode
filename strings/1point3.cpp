#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeDuplicates(char* str, unsigned int l) {
	if (!str) return;
	if (l == 0) return;
	
	// Simplest way: compare each character in the string to every other character
	// remove that character when we find a repeat.
	
	// Store a bit vector - we have 256 possible characters
	// Store a 0 for each initially, 1 when we find that character
	// Total bits needed: min 256 = 32 bytes
	bool repeatValues[256];
	memset((void*)repeatValues, 0, 256*sizeof(bool));
	
	char temp = '!';
	printf("! value: %d\n", repeatValues[(unsigned int)temp]);
	
	char* cursor = str;
	while(*cursor != '\0') {
		if (repeatValues[(unsigned int)*cursor]) {
			//repeated element found
			// remove this abomination
			printf("Found duplicate: %c\n", *cursor);
			strcpy(cursor, cursor+1);
		}
		else {
			// set that we've seen this
			repeatValues[(unsigned int)*cursor] = true;
			cursor++;
		}
	}
}

// Program to find duplicate characters in a string 
// and remove them. No extra copies of the string allowed.
int main () {
	
	//Define test case
	char str[100] = "kaa!bbccddeeffggz";
	
	//Remove duplicates in place
	removeDuplicates(str, strlen(str));
	
	//Print to check
	printf("%s\n", str);
	
	return 0;
}