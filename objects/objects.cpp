#include <iostream>

using namespace std;

class animal {
	
protected:
	int arms;
	int legs;
	
public:
	animal(unsigned int a, unsigned int l) {
		arms = a;
		legs = l;
	}
	
	~animal() {
	}
		
	void eat(animal prey) {
		printf("Eating a prey with %d arms and %d legs! Yummy1\n", prey.arms, prey.legs);
	}
	
	void sleep() {
		printf("zzzz\n");
	}
	
	int getArms() {
		return arms;
	}
	
	int getLegs() {
		return legs;
	}
	
	virtual void makeNoise() {
		printf("scratch scratch\n");
	}
};

class dog : public animal{
	
public:
	dog() : animal(0, 4) {
		
	}
	
	~dog() {

	}
	
	void makeNoise() {
		printf("Woof Woof!\n");
	}
	
};

class spider : public animal {

private: 
	int eyes;
	
public:
	spider(int e) : animal(8, 8) {
		eyes = e;
	}
	
	~spider() {
	}
	
	int getEyes() {
		return eyes;
	}
	
	spider operator=(spider b) {
		spider a(b.getEyes());
		return a;
	}
	
};


// A small file to make sure that I still know 
// what inheritance is :P
int main() {
	
	dog scooby;
	animal rat = animal(2, 2);
	scooby.eat(rat);
	scooby.sleep();
	scooby.makeNoise();
	cout << "Dogs have "
		 << scooby.getArms()
		 << " arms and "
		 << scooby.getLegs()
		 << " legs!"
		 << endl;
		 
	cout << endl;
	
	spider octi(4);
	cout << "Eyes: " << octi.getEyes() << endl;
	
	spider octoo = octi;
	cout << "Octoo also has " << octi.getEyes() << " eyes" << endl;
	cout << endl;
	return 0;
}