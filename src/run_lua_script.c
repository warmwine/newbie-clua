#include <string.h>

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

void main()
{
    lua_State *luaStatePtr = luaL_newstate();

    if( luaStatePtr == 0 ) {
        return ;
    }

    int bRet = luaL_loadfile( luaStatePtr, "scripts/run_lua_script.lua" );

    if( bRet ) {
        printf( "load file error\n" );
        return ;
    }

    bRet = lua_pcall( luaStatePtr, 0, 0, 0 );

    if( bRet ) {
        printf( "pcall error\n" );
        return ;
    }

    //load lua global variable
    lua_getglobal( luaStatePtr, "strInLua" );//get lua vm global value to top of the virtual stack
    const char* stringInLua = lua_tostring( luaStatePtr, -1 );
    printf( "String In Lua Script is: %s\n", stringInLua );

    //load lua global table
    lua_getglobal( luaStatePtr, "tblInLua" );

    lua_getfield( luaStatePtr, -1, "name" );
    const char* userName = lua_tostring( luaStatePtr, -1 );
    lua_pop( luaStatePtr, 1 );

    lua_getfield( luaStatePtr, -1, "id" );
    int userId = lua_tonumber( luaStatePtr, -2 );
    lua_pop( luaStatePtr, 1 );

    printf( "Table In Lua Script is: {UserName: %s, ID: %d}\n", userName, userId );

    //load lua function
    lua_getglobal( luaStatePtr, "add" );
    lua_pushnumber( luaStatePtr, 10 );
    lua_pushnumber( luaStatePtr, 20 );
    int iRet = lua_pcall( luaStatePtr, 2, 1, 0 ); //2 means param , 1 means return value number

    if( iRet ) {
        const char *pErrorMsg = lua_tostring( luaStatePtr, -1 );
        printf( "%s\n", pErrorMsg );
        lua_close( luaStatePtr );
        return ;
    }

    if( lua_isnumber( luaStatePtr, -1 ) ) {
        float value = lua_tonumber( luaStatePtr, -1 );
        printf( "Return value from lua function add is: %2.2f\n", value );
    }

    //=================== top ===================
    //   3   int：      30
    //   2   table:     tbl
    //   1   string:    Lua is so cool
    //=================== bottom ===================

    lua_close( luaStatePtr );
    return ;
}
