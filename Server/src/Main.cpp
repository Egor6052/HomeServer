#include <iostream>
#include <string>
#include "../lib/Products.h"

using namespace std;

int main(){

	Products banana;
	banana.setName("Banana");
	banana.setPrice(90);
	banana.setWeight(1500);
	banana.setData(10);
	banana.Print();

	Products persik;
	// persik = banana;
	persik.setName("Persik");
	persik.setPrice(50);
	persik.setData(20);
	
	// bool result = persik == banana;
	bool result = persik != banana;
	if (result){
		cout << "!=" << endl;
	}
	persik.Print();
	
	Products potato = persik + banana;
	potato.Print();
	return 0;
}