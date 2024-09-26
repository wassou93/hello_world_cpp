#include <iostream>
#include <functional>
#include <set>

struct Person 
{
	std::string name;
	int age;
};


int main()
{
	auto compare_by_age = [](const Person& person1, const Person& person2)-> bool {return person1.age < person2.age; };
	std::set<Person, std::function<bool(const Person&, const Person&)>> people(compare_by_age);
	people = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

	for (const auto& person : people)
	{
		std::cout << person.name << " (" << person.age << " years old)\n";
	}

	return 0;
}
