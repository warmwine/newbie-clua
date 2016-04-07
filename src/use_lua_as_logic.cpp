#include "selene.h"
#include <iostream>

struct Bar {
    int x;
    Bar( int x_ ) : x( x_ ) {}
    int AddThis( int y )
    {
        return x + y;
    }
};



int main()
{
    sel::State state{true};
    state["Bar"].SetClass<Bar, int>( "add_this", &Bar::AddThis );
    state.Load( "scripts/use_lua_as_logic.lua" );
    return 0;
}
