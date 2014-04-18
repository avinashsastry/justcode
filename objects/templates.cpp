#include <iostream>

using namespace std;

template <class someType> class calc {
	public:
	someType multiply(someType a, someType b);
};

template <class someType> someType calc<someType>::multiply(someType a, someType b) {
	return a*b;
}

class animal{

private:
	int a;
	int b;
};

int main() {
	
	calc <float> fcalc;
	cout << "Product: " << 	fcalc.multiply(5.2f, 3.2f) << endl;
	
	calc <int> icalc;
	cout << "Int product: " << icalc.multiply(4, 3) << endl;
	
	// Create a q of calcs!
	objectQ <animal> fQ = objectQ <animal> (4);

	return 0;
}