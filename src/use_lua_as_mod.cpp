#include "selene.h"
#include <unistd.h>
#include <iostream>

int main()
{
    sel::State state{true};
    state.Load( "scripts/use_lua_as_mod.lua" );

    int i = 100000;
    int delta = 0;
    int delta_delta = 1;

    while( true ) {
        state["newPriceComing"]( i );
        i = i - delta;
        delta += 1 * delta_delta;

        if( delta > 10 || delta < -10 ) {
            delta_delta = delta_delta * -1;
        }

        usleep( 500 * 1000 );
    }

    return 0;
}
