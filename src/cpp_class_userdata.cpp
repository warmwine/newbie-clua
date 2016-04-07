extern "C" {
#include "lua/lua.h"
#include "lua/lualib.h"
#include "lua/lauxlib.h"
}


class CTest
{
public:
    CTest() {};
    virtual ~CTest() {};
    int Add( int x, int y )
    {
        printf( "%p Add: x=%d, y=%d\n", this, x, y );
        return x + y;
    };
};

static int CreateCTest( lua_State* L )
{
    *( CTest** )lua_newuserdata( L, sizeof( CTest* ) ) = new CTest();
    luaL_getmetatable( L, "CTest" );
    lua_setmetatable( L, -2 );
    return 1;
}

static int DestoryCTest( lua_State* L )
{
    delete *( CTest** )lua_topointer( L, 1 );
    return 0;
}

static int CallAdd( lua_State* L )
{
    CTest* pT = *( CTest** )lua_topointer( L, 1 );
    lua_pushnumber( L, pT->Add( lua_tonumber( L, 2 ), lua_tonumber( L, 3 ) ) );
    return 1;
}

int main( int argc, char * argv[] )
{
    lua_State *L = luaL_newstate();
    luaopen_base( L );

    lua_pushcfunction( L, CreateCTest );
    lua_setglobal( L,  "CTest" );

    //creat new metatable
    luaL_newmetatable( L, "CTest" );

    //create gc function
    lua_pushstring( L, "__gc" );
    lua_pushcfunction( L, DestoryCTest );
    lua_settable( L, -3 );

    //create index function
    lua_pushstring( L, "__index" );
    lua_pushvalue( L, -2 );
    lua_settable( L, -3 );

    //create call function
    lua_pushstring( L, "Add" );
    lua_pushcfunction( L, CallAdd );
    lua_settable( L, -3 );
    lua_pop( L, 1 );


    //run
    luaL_dofile( L, "scripts/cpp_class_userdata.lua" );
    lua_close( L );
    return 0;
}
