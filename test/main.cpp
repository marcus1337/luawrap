
extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
#include "lua.hpp"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    lua_State* L = luaL_newstate();

    std::cout << "hello world, lua\n";

    int tmp;
    std::cin >> tmp;

    return 0;
}