#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX	100

void reverse(char* str, unsigned int l) {	

	if (l > 0) {
		char temp;
		char* end = &str[l-1];
		while (str < end) {
			temp = *str;
			*str = *end;
			*end = temp;
			str++;
			end--;
		}
	}
	else {
		return;
	}
}

int main () {
	
	char test_str[100] = "abcdefgh";
	printf("%s\n", test_str);
	
	// now to reverse it
	reverse(test_str, strlen(test_str));
	printf("%s\n", test_str);
	
	return 0;
}