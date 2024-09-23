#include <iostream>
#include <vector>
#include <algorithm>

static void concat_vecs(std::vector<int>& v, std::vector<int>& newElems) {
	const auto oldSize = v.size();
	v.insert(
		v.cend(),
		std::move_iterator(newElems.begin()),
		std::move_iterator(newElems.end())
	);
	//v.resize(v.size() + newElems.size());
	// and
	//std::copy(
	//	std::move_iterator(newElems.begin()),
	//	std::move_iterator(newElems.end()),
	//	std::next(v.begin(), oldSize)
	//);
	// or
	//std::transform(
	//	std::move_iterator(newElems.begin()),
	//	std::move_iterator(newElems.end()),
	//	std::next(v.begin(), oldSize),
	//	[](auto&& elem) { return elem * 2; }
	//);
}
 
int main()
{
	std::vector<int> list = { 1, 2, 3 };
	std::vector<int> newElems = { 4, 6 };

	concat_vecs(list, newElems);

	for (const auto& element : list) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::cout << "List capacity = " << list.capacity() << std::endl;
}
