
#include <sol/sol.hpp>
#include <cassert>

#include <string>
#include <iostream>

#include "LuaRegistry.h"


void test() {
    LuaRegistry luaRegistry;


}

int main(int argc, char* argv[]) {

    test();

    sol::state lua;

    std::cout << "hello world, lua\n";

    int tmp;
    std::cin >> tmp;

    return 0;
}