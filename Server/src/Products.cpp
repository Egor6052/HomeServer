#include "../lib/Products.h"

Products::Products() {
    name = "NoName";
    price = 0;
    weight = 0;
    size = 0;
    data = nullptr;
}

Products::~Products() {
    std::cout << "Destructor: " << this << std::endl;
    delete[] data;
}

void Products::setName(std::string valueName) {
    if (!valueName.empty()) {
        name = valueName;
    } else {
        std::cout << "Name is null. But now = NoName." << std::endl;
        name = "NoName";
    }
}

void Products::setPrice(int valuePrice) {
    price = valuePrice;
}

void Products::setWeight(double valueWeight) {
    weight = valueWeight / 1000;
}

void Products::setData(int newSize) {
    if (newSize > 0) {
        delete[] data;
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

std::string Products::getName() {
    return name;
}

int Products::getPrice() {
    return price;
}

double Products::getWeight() {
    return weight;
}

int* Products::getData() {
    return data;
}

int Products::getSize() const {
    return size;
}

void Products::Print() {
    std::cout << this << std::endl;
    std::cout << "Name: " << name << "\nPrice: " << price << " грн"
              << "\nWeight: " << weight << " Кг\n" << std::endl;

    std::cout << "Data [ ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "];" << std::endl;
}
