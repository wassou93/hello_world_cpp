#include <iostream>
#include <vector>

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
}
 