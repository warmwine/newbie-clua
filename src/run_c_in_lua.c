#include <stdio.h>

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"


lua_State* L;
static int average( lua_State *L )
{
    int n = lua_gettop( L );
    int i;
    double sum = 0;

    for( i = 1; i <= n; i++ ) {
        sum += lua_tonumber( L, i );
    }

    //push to result to stack
    lua_pushnumber( L, sum / n );
    lua_pushnumber( L, sum );
    //2 is return value number,
    //lua will pop them from the top of the stack after reading
    return 2;
}

int main( int argc, char *argv[] )
{
    L = luaL_newstate();
    luaL_openlibs( L );
    lua_register( L, "average", average ); //register c function
    luaL_dofile( L, "scripts/run_c_in_lua.lua" );
    lua_close( L );

    printf( "Press enter to exit…" );
    getchar();
    return 0;
}
