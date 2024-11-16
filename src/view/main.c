#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../controller/crud.h"

void menu_options( void )
{   
    printf( "\n%s\n" , "---------------------------------" );
    printf(   "%s\n" , "CRUD Vehicle by Vinicius Miranda." );
    printf(   "%s\n" , "---------------------------------" );
    printf(   "%s\n" , "> Start                          " );
    printf(   "%s\n" , " 1 - Search a vehicle.           " );
    printf(   "%s\n" , " 2 - Add a vehicle.              " );
    printf(   "%s\n" , " 3 - Edit a vehicle.             " );
    printf(   "%s\n" , " 4 - Delete a vehicle.           " );
    printf(   "%s\n" , " 5 - List all vehicles.          " );
    printf(   "%s\n" , " 0 - Exit programm.              " );
    printf(   "%s"   , "Option: "                          );
} // menu_options ( )

void readline( char *buffer, int size )
{
    if( fgets( buffer, size, stdin ) != NULL )
    {
        buffer[strcspn(buffer, "\n")] = 0;
        buffer[strcspn(buffer, "\r")] = 0;
    } // if
} // readline ( )

int read_option( void )
{
    char input[80];
    int option = 0;
    readline( input, 80 );
    if( strcmp( input, "" ) != 0 ) {
        option = atoi( input );
    } else {
        option = -1;
    } // if
    return ( option );
} // read_option ( )

void excute_option( int option )
{
    switch ( option )
    {
    case 0:
        printf( "\n%s\n" , "Exiting the programm." );
        break;
    case 1:
        search_vehicle( );  
        break;
    case 2:
        create_vehicle( );     
        break;
    case 3:
        edit_vehicle( );
        break;
    case 4:
        delete_vehicle( );
        break;
    case 5:
        list_vehicles( );
        break;
    default:
        printf( "\n%s\n" , "Invalid option." );
        break;
    } // switch
} // excute_option ( )

int main( void  )
{
    int option = 0;

    do
    {
        menu_options( );
        option = read_option( );
        excute_option( option );
    } while ( option != 0 ); // do while
    
    return ( 0 );
} // main_menu ( )