cmake_minimum_required(VERSION 3.17.4)
project(luawrap LANGUAGES C)

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
)

target_include_directories(${PROJECT_NAME} PUBLIC ${LUA_SRC})




