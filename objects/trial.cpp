#include <iostream>

using namespace std;

char* reverse(const char* string) {
	if (!string) return NULL;
	
	unsigned int length = strlen(string);
	char* string2 = (char*) malloc( sizeof(char) * length );
	strcpy(string2, string);

	char* cursor1 = string2;
	char* cursor2 =  string2+length;
	
	while(cursor1 != cursor2) {
		char temp;
		cursor2--;
		temp = *cursor1;
		*cursor1 = *cursor2;
		*cursor2 = temp;
		
		cursor1++;
	}	
	
	return string2;
}

int main() {
	
	const char* string = "My Name is Earl.";
	cout << string << endl;
	
	char* string2 = reverse(string);
	cout << string2 << endl;
}