#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

static int averageFunc( lua_State *L )
{
    int n = lua_gettop( L );
    double sum = 0;
    int i;

    for( i = 1; i <= n; i++ )
        sum += lua_tonumber( L, i );

    lua_pushnumber( L, sum / n );
    lua_pushnumber( L, sum );

    return 2;
}

static int sayHelloFunc( lua_State* L )
{
    printf( "hello world!\n" );
    return 0;
}

static const struct luaL_Reg myLib[] = {
    {"average", averageFunc},
    {"sayHello", sayHelloFunc},
    {NULL, NULL}
};

int luaopen_libloadclib( lua_State *L )
{
    luaL_openlib( L, "ss", myLib, 0 );
    //luaL_register(L, "ss", myLib);
    return 1;
}
