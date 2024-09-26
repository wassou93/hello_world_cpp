#include <iostream>
#include <ranges>
#include <array>
#include <numeric> 

using namespace std;

int main()
{
    array<int, 6> v{ 0 };
    std::iota(v.begin(), v.end(), 0);
    for (auto number : std::views::iota(0, 10) | std::views::take(5))
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}
