#include <iostream>
#include <set>

struct Person 
{
	std::string name;
	int age;

	bool operator<(const Person& other) const
	{
		return age > other.age;
	}
};

int main()
{
	std::set<Person> people = { {"Alice", 30}, {"Bob", 25}, {"Charlie", 35} };

	for (const auto& person : people)
	{
		std::cout << person.name << " (" << person.age << " years old)\n";
	}

	return 0;
}

