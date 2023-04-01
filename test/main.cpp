
#include <sol/sol.hpp>
#include <cassert>

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    sol::state lua;

    std::cout << "hello world, lua\n";

    int tmp;
    std::cin >> tmp;

    return 0;
}