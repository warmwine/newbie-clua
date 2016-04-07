#include "selene.h"

int main()
{
    sel::State state;
    state.Load( "scripts/cppbinding.lua" );
    printf( "foo is %d\n", int( state["foo"] ) );
    std::string bar3 = state["bar"][3];
    printf( "bar3 is %s\n", bar3.c_str() );
    std::string barkey = state["bar"]["key"];
    printf( "barkey is %s\n", barkey.c_str() );
    return 0;
}
