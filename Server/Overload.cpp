#include <iostream>
#include <string.h>
#include "Overload.h"

using namespace std;

class Products{
private:
	string name;
	int price;
	double weight;

	int size;
	int *data;
public:
	// Constructor;
	Products(){
		name = "NoName";
		price = 0;
		weight = 0;

		size = 0;
		data = nullptr;

	}
	// Distructor; 
	~Products(){
		cout << "Distructor: " << this << endl;
		delete [] data;
	}
	
	void setName(string valueName){
		name = valueName;
	}
	void setPrice(int valuePrice){
		price = valuePrice;
	}
	void setWeight(double valueWeight){
		weight = valueWeight;
	}
	void setData(int newSize) {
        if (newSize > 0) {
            delete[] data;  // Звільняємо старий масив
            data = new int[newSize];
            size = newSize;
            for (int i = 0; i < size; ++i) {
                data[i] = i + 1;
            }
        } else {
            size = 0;
            data = nullptr;
        }
    }

    

	string getName(){
		return name;
	}
	int getPrice(){
		return price;
	}
	double getWeight(){
		return weight;
	}
	int* getData() {
        return data;
    }

    int getSize() const {
        return size;
    }


	void Print(){
		cout << this << endl;
		cout << "Name: " << name << "\n" << "Price: " << price << " грн" << "\n" << "Weight: " << weight / 1000 << " Кг" << "\n" << endl;

		cout << "Data [ ";
		for (int i = 0; i < size; i++){
			cout << data[i] << " " ;
		}
		cout << "];" << endl;
	}

	// Peregruzka =;
	void operator = (const Products &valueProduct){
		cout << "Operator '='" << endl;
		this->size = valueProduct.size;

		// Якщо данні у новому масиві є;
		if (this->data != nullptr){
			delete [] this->data;
		}

		this->data = new int[valueProduct.size];
		for(int i = 0; i < valueProduct.size; i++){
			this->data[i] = valueProduct.data[i];
	
		}
	}
};

// Функція для обробки запиту
string processRequest(const string& request) {
    Products product;
    product.setName("Sample Product");
    product.setPrice(100);
    product.setWeight(200);
    product.setData(5);
    return "Processed request: " + request + "\nProduct Info: " + product.getName();
}

// int main(){

// 	Products banana;
// 	banana.setName("Banana");
// 	banana.setPrice(90);
// 	banana.setWeight(1500);
// 	banana.setData(10);
// 	banana.Print();

// 	Products persik;
// 	persik = banana;

// 	persik.Print();
// 	return 0;
// }