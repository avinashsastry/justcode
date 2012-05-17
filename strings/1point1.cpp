#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool hasRepeatedChars(char* str) {
	
	char* cursor = str;
	char chars_in_str[100];
	int i=0;

	while(*cursor != '\0') {
		chars_in_str[i] = *cursor;
		printf("%c\n", *cursor);
		for (int j = 0; j < i-1; j++) {
			if (chars_in_str[j] == *cursor) {
				printf("NO\n");
				return false;
			}
		}
		i++;
		cursor++;
	}
	printf("YES\n");
	return true;
}


// Program to determine if a string has all unique characters
int main() {
	
	//Define a string
	char str[100] = "abcdefagh!";
	hasRepeatedChars(str);
	
	return 0;
}