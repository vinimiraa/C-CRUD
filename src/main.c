#include "../lib/menu.h"

int main( void )
{
    Vehicle v [ MAX_VEHICLES ];

    read_from_file ( v, "vehicles.txt" );

    main_menu ( v );

    write_to_file ( v, "vehicles.txt" );

    return 0;
} // end main ( )
