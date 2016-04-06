#include <iostream>
#include <string.h>

extern "C"
{
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
}
int main()
{
    char buff[256] = {0};
    int error;
    lua_State *L = luaL_newstate();
    luaL_openlibs( L );

    while( fgets( buff, sizeof( buff ), stdin ) != NULL ) {
        error = luaL_loadbuffer( L, buff, strlen( buff ), "line" )
                || lua_pcall( L, 0, 0, 0 );

        if( error ) {
            fprintf( stderr, "%s", lua_tostring( L, -1 ) );
            lua_pop( L, 1 );
        }
    }

    lua_close( L );
    return 0;
}
