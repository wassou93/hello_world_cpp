#include <iostream>

class Animal {
public:
    virtual void speak() {
        std::cout << "Animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Bark" << std::endl;
    }
};

int main() {
    Animal* animal = new Dog();
    animal->speak(); // Outputs "Animal sound"
}
