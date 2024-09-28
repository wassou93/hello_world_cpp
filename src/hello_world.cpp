#include <concepts>
#include <list>
#include <iostream>
#include <ranges>
#include <vector>

template<typename Container>
void print_container_types()
{
	using IteratorType = typename std::ranges::iterator_t<Container>;
	using ValueType1 = typename std::ranges::range_value_t<Container>;
	using ValueType2 = typename Container::value_type;
	std::cout << "Iterator Type: " << typeid( IteratorType ).name() << std::endl;
	std::cout << "Value Type 1: " << typeid( ValueType1 ).name() << std::endl;
	std::cout << "Value Type 2: " << typeid( ValueType2 ).name() << std::endl;
}

template <typename Container>
void insert_example( Container &cont, typename Container::iterator it ) {
	auto inserter_it = std::inserter( cont, it );
	*inserter_it = typename Container::value_type{};
}

template <typename Container>
void insert_example_cxx20( Container &cont, std::ranges::iterator_t<Container> it ) {
	auto inserter_it = std::inserter( cont, it );
	*inserter_it = typename Container::value_type{};
}

template <std::ranges::range R>
void print_elements( const R &range ) {
	for ( const auto &elem : range ) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::string str = "hello";
	std::vector<std::string> list_str = { "first", "second" };
	std::vector<int> list_ints = { 1, 2, 3 };

	std::string dst;
	std::copy( str.begin(), str.begin(), std::inserter( str, str.begin() ) );

	print_container_types<decltype( str )>();
	std::cout << std::endl;
	print_container_types<decltype( list_str )>();
	std::cout << std::endl;
	print_container_types<decltype( list_ints )>();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << typeid( std::string::allocator_type ).name() << std::endl;
	std::cout << typeid( std::vector<int>::allocator_type ).name() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << typeid( std::string::size_type ).name() << std::endl;
	std::cout << typeid( std::vector<int>::size_type ).name() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << typeid( std::string::traits_type ).name() << std::endl;


	std::vector<int> vec = { 1, 2, 3 };
	insert_example( vec, vec.begin() );
	insert_example_cxx20( vec, vec.begin() );

	for ( const auto &val : vec ) {
		std::cout << val << " ";
	}

	std::vector<int> _vec = { 1, 2, 3, 4, 5 };
	std::list<int> _lst = { 6, 7, 8, 9, 10 };

	print_elements( _vec );
	print_elements( _lst );

	std::cin.get();
}
