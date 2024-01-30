#include <stdio.h>
#include "crud.h"
#include "menu.h"

void menu_options ( void )
{

    printf( "\n%s\n" , "Choose an option:      " );
    printf( "\n%s\n" , " 0 - Exit programm.    " );
    printf( "\n%s\n" , " 1 - List all vehicles." );
    printf( "\n%s\n" , " 2 - Search a vehicle. " );
    printf( "\n%s\n" , " 3 - Add a vehicle.    " );
    printf( "\n%s\n" , " 4 - Edit a vehicle.   " );
    printf( "\n%s\n" , " 5 - Delete a vehicle. " );

} // end menu_options ( )

void main_menu ( Vehicle *v )
{
    int option = 0;

    do
    {
        // clear default data output
        clear_screen( );

        // print the author
        printf( "\n%s\n", "CRUD by Vinicius Miranda." );

        // print the menu option
        menu_options( );
        
        // read the option
        printf( "\n%s", "Option = " );
        scanf( "%d", &option );
        getchar( );

        // execute the function choosed
        switch ( option )
        {
        case 0:
            printf( "\n%s\n" , "Exiting the programm." );
            break;
        case 1:
            list_vehicles( v );            
            break;
        case 2:
            search_vehicle( v );            
            break;
        case 3:
            add_vehicle( v );            
            break;
        case 4:
            edit_vehicle( v );            
            break;
        case 5:
            delete_vehicle( v );           
            break;
        default:
            printf( "\n%s\n" , " [ ERROR: Invalid option. ] " );
            pause ( "Press Enter to continue." );
            break;
        } // end switch

    } while ( option != 0 ); // end do while
    
} // end main_menu ( )