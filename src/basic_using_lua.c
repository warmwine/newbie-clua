#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
int main()
{
    lua_State *luaStatePtr = luaL_newstate();
    lua_pushstring( luaStatePtr, "Lua is so cool~" );
    lua_pushnumber( luaStatePtr, 20.2 );

    if( lua_isstring( luaStatePtr, 1 ) ) {
        const char* luaStringInStack = lua_tostring( luaStatePtr, 1 );
        printf( "%s\n", luaStringInStack );
    }

    if( lua_isnumber( luaStatePtr, 2 ) ) {
        float a = lua_tonumber( luaStatePtr, 2 );
        printf( "%2.2f\n", a );
    }

    lua_close( luaStatePtr );
    return ;
}
