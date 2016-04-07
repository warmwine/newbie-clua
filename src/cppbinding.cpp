#include "selene.h"

struct Bar {
    int x;
    Bar(int x_) : x(x_) {}
    int AddThis(int y) { return x + y; }
};



int main()
{
    sel::State state;
    state["Bar"].SetClass<Bar, int>("add_this", &Bar::AddThis);

    lua_State *L = lua_open();
    luaL_dofile(L, "scripts/cppbinding.lua");
    lua_close(L);

    return 0;
}
