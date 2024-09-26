#include <iostream>
#include <set>

struct Person
{
    std::string name;
    int age;
};

int main()
{
    auto compare_by_age = [](const Person& person1, const Person& person2)-> bool {return person1.age < person2.age; };
    std::set<Person, decltype(compare_by_age)> people(compare_by_age);
    people = { {"Alice", 30}, {"Bob", 25}, {"Charlie", 35} };

    for (const auto& person : people)
    {
        std::cout << person.name << " (" << person.age << " years old)\n";
    }
    
    std::cout << typeid(compare_by_age).name() << std::endl;

    return 0;
}
