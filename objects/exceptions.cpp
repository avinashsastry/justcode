#include <iostream>
#include <exception>
using namespace std;

class error : public exception {

	virtual const char* what() const throw() {
		return "What is some generic name in exception I guess.";		
	}
};

int main() {
	
	error majorError;
	try {
		throw majorError;
	}
	catch (exception &e){
		cout << e.what() << endl;
	}
	return 0;
}