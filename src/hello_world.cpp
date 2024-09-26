#include <iostream>
#include <vector> 
#include <array>

int main()
{
    // Old way of iterating using pointers

    int arr[] = { 10, 20, 30, 40 };

    for (int* p = arr; p < arr + 4; ++p) {
        std::cout << *p << '\n';
    }

    // New way using STL containers iterator

    std::vector<int> v{ 10, 20, 30, 40, 50, 70 };

    for (std::vector<int>::iterator pos = v.begin(); pos < v.end(); ++pos) {
        std::cout << *pos << '\n';
    }

    std::string s{ "device" };
    int cptr = 0;
    for (std::string::iterator pos = s.begin(); pos < s.end(); ++pos, ++cptr) {
        std::cout << cptr << ": " << *pos << '\n';
    }

    // Iterate over an array

    std::array<int, 6> arr2 = {0, 1, 2, 3, 4, 5};
    for (auto& ele : arr2) {
        std::cout << ele << '\n';
    }

}
 