#include "selene.h"

#include <iostream>

int main()
{
    sel::State state;
    state.Load( "scripts/use_lua_as_option.lua" );

    while( true ) {
        std::cout << "Input UserName:";
        std::string name;
        std::cin >> name;

        std::cout << "Input Passwd:";
        std::string pass;
        std::cin >> pass;


        std::string realpass = state["list"][name.c_str()];

        if( realpass == pass ) {
            std::cout << "Logged in" << std::endl;
            break;
        } else {
            std::cout << "Wrong username or passwd" << std::endl;
        }
    }

    return 0;
}
