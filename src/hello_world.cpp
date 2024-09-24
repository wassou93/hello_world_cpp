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
    Dog d;
    Animal* animal = &d;
    animal->speak(); // Outputs "Animal sound"
    std::cout << typeid(animal).name() << std::endl; // this is uses the &RTTI field in the vftable
    std::cout << typeid(*animal).name() << std::endl; // &RTTI: RunTime Type Information address which points to the class name

}

// The entire vftable and RTTI are stored in .rodata area of the program virtual memory
// for more information refer to: https://github.com/navining/gocpp/blob/master/Chapter%206/Virtual-Functions-Static-Binding-and-Dynamic-Binding.md

