cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB_RECURSE LUA_HPP ../../thirdparty/lua/*.hpp)
FILE(GLOB_RECURSE LUA_C ../../thirdparty/lua/*.c)

INCLUDE_DIRECTORIES(../../thirdparty)

project (BasicUsingLua)
LINK_LIBRARIES(m)
add_executable(BasicUsingLua ${LUA_HPP} ${LUA_C} ../../src/basic_using_lua.c)

#RunLuaInC
project (RunLuaScript)
LINK_LIBRARIES(m)
add_executable(RunLuaScript ${LUA_HPP} ${LUA_C} ../../src/run_lua_script.c)


project (BasicUsingLuaWithCpp)
add_executable(BasicUsingLuaWithCpp ${LUA_HPP} ${LUA_C} ../../src/main.cpp)
