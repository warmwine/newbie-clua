cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB_RECURSE LUA_HPP ../../thirdparty/lua/*.hpp)
FILE(GLOB_RECURSE LUA_C ../../thirdparty/lua/*.c)

INCLUDE_DIRECTORIES(../../thirdparty)
INCLUDE_DIRECTORIES(../../thirdparty/lua)

project (BasicUsingLua)
LINK_LIBRARIES(m dl)
add_executable(BasicUsingLua ${LUA_HPP} ${LUA_C} ../../src/basic_using_lua.c)

#RunLuaInC
project (RunLuaScript)
LINK_LIBRARIES(m dl)
add_executable(RunLuaScript ${LUA_HPP} ${LUA_C} ../../src/run_lua_script.c)

#RunCINLua
project (CallCFunction)
LINK_LIBRARIES(m dl)
add_executable(CallCFunction ${LUA_HPP} ${LUA_C} ../../src/run_c_in_lua.c)

#CallCLib
project (loadclib)
LINK_LIBRARIES(m)
add_library(loadclib SHARED ${LUA_HPP} ${LUA_C} ../../src/loadclib.c)

#CPPClass
project (CppClassDemo)
add_executable(CppClassDemo ${LUA_HPP} ${LUA_C} ../../src/cpp_class_userdata.cpp)

#CPPBinding
project (CppBinding)
LINK_LIBRARIES(m)
add_executable(CppBinding ${LUA_HPP} ${LUA_C} ../../src/cppbinding.cpp)
