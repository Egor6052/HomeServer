#include "../lib/Overloads.h"
#include "../lib/Products.h"
#include <string>

void Products::operator=(const Products &valueProduct) {
    std::cout << "Operator '='" << std::endl;
    this->size = valueProduct.size;

    if (this->data != nullptr) {
        delete[] this->data;
    }

    this->data = new int[valueProduct.size];
    for (int i = 0; i < valueProduct.size; i++) {
        this->data[i] = valueProduct.data[i];
    }
    this->name = valueProduct.name;
    this->price = valueProduct.price;
    this->weight = valueProduct.weight;
}

bool Products::operator!=(const Products &valueProduct) const {
    if (this->name != valueProduct.name ||
        this->price != valueProduct.price ||
        this->weight != valueProduct.weight ||
        this->size != valueProduct.size) {
        return true;
    }

    for (int i = 0; i < this->size; i++) {
        if (this->data[i] != valueProduct.data[i]) {
            return true;
        }
    }

    return false;
}

bool Products::operator==(const Products &valueProduct) {
    if (this->name == valueProduct.name &&
        this->price == valueProduct.price &&
        this->weight == valueProduct.weight &&
        this->size == valueProduct.size) {
        return true;
    }
    return false;
}

Products Products::operator+(const Products &valueProduct){
    Products temp;

    temp.price = this->price + valueProduct.price;
    temp.weight = this->weight + valueProduct.weight;
    temp.size = this->size + valueProduct.size;
    temp.data = new int[temp.size];

    for (int i = 0; i < this->size; i++){
        temp.data[i] = this->data[i];
    }
    for (int j = 0; j < valueProduct.size; j++){
        temp.data[this->size + j] = valueProduct.data[j];
    }

    return temp;
}

// Функція для обробки запиту
std::string Overloads::processRequest(const std::string &request) {
    Products product;
    product.setName("Sample Product");
    product.setPrice(100);
    product.setWeight(200);
    product.setData(5);

    return "Processed request: " + request + "\nProduct Info: " + product.getName();
}