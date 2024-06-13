#include <iostream>
#include <algorithm>

using namespace std;

int Resource(int A, int B, int C)
{
    int different_type_systems = min({A, B, C});

    A -= different_type_systems;
    B -= different_type_systems;
    C -= different_type_systems;

    int same_type_systems = (A / 3) + (B / 3) + (C / 3);

    A %= 3;
    B %= 3;
    C %= 3;

    if ((A == 2 && B == 2 && C == 0) || (A == 2 && C == 2 && B == 0) || (B == 2 && C == 2 && A == 0))
    {
        same_type_systems += 1;
    }

    return different_type_systems + same_type_systems;
}

int main()
{
    // int A, B, C;
    // std::cout << "Enter the number of small-sized resources: ";
    // std::cin >> A;
    // std::cout << "Enter the number of medium-sized resources: ";
    // std::cin >> B;
    // std::cout << "Enter the number of large-sized resources: ";
    // std::cin >> C;

    // std:: cout << Resource(A, B, C);
    std::cout << Resource(7, 8, 9);
    std::cout << Resource(3, 6, 9);
    std::cout << Resource(7, 9, 9);
    std::cout << Resource(0, 3, 6);
}