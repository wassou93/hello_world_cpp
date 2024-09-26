#include <iostream>
#include <set>

struct Person 
{
	std::string name;
	int age;
};
struct CompareByAge {
	bool operator()(const Person& a, const Person& b) const {
		return a.age < b.age;
	}
};

int main()
{
	std::set<Person, CompareByAge> people = { { "Alice", 30 }, { "Bob", 25 }, { "Charlie", 35 } };

	for (const auto& person : people)
	{
		std::cout << person.name << " (" << person.age << " years old)\n";
	}

	return 0;
}

