cmake_minimum_required(VERSION 3.17.4)
project(luawrap)
set (CMAKE_CXX_STANDARD 20)

set(LUA_SRC "${PROJECT_SOURCE_DIR}/lua_src")

add_library(${PROJECT_NAME} STATIC
    ${LUA_SRC}/lapi.c
    ${LUA_SRC}/lcode.c
    ${LUA_SRC}/lctype.c
    ${LUA_SRC}/ldebug.c
    ${LUA_SRC}/ldo.c
    ${LUA_SRC}/ldump.c
    ${LUA_SRC}/lfunc.c
    ${LUA_SRC}/lgc.c
    ${LUA_SRC}/llex.c
    ${LUA_SRC}/lmem.c
    ${LUA_SRC}/lobject.c
    ${LUA_SRC}/lopcodes.c
    ${LUA_SRC}/lparser.c
    ${LUA_SRC}/lstate.c
    ${LUA_SRC}/lstring.c
    ${LUA_SRC}/ltable.c
    ${LUA_SRC}/ltm.c
    ${LUA_SRC}/lundump.c
    ${LUA_SRC}/lutf8lib.c
    ${LUA_SRC}/lvm.c
    ${LUA_SRC}/lzio.c
    ${LUA_SRC}/lauxlib.c #Auxiliary functions

    ${LUA_SRC}/lbaselib.c
    ${LUA_SRC}/lcorolib.c
    ${LUA_SRC}/ldblib.c
    ${LUA_SRC}/liolib.c
    ${LUA_SRC}/lmathlib.c
    ${LUA_SRC}/loslib.c
    ${LUA_SRC}/lstrlib.c
    ${LUA_SRC}/ltablib.c
    ${LUA_SRC}/linit.c
    ${LUA_SRC}/loadlib.c

    "${PROJECT_SOURCE_DIR}/src/LuaRegistry.cpp"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${LUA_SRC} "${PROJECT_SOURCE_DIR}/sol2" "${PROJECT_SOURCE_DIR}/include")






