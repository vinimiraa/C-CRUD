#include "crud.h"
#include "cstring.h"
#include "../model/vehicle.h"
#include <stdlib.h>
#include <string.h>

static int N_VEHICLES = 0;
static int MAX_VEHICLES = 100;
const char* FILENAME = "data/vehicles.csv";

bool __file_readline ( char* buffer, int length, FILE* arquivo ) 
{
    bool resp = false;
    if( fgets( buffer, length, arquivo ) != NULL ) 
    {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove '\n'
        buffer[strcspn(buffer, "\r")] = '\0'; // Remove '\r'
        resp = true;
    } // if
    return ( resp );
} // __file_readline ( )

Vehicle** __file_read_csv( const char* filename )
{
    FILE *file = fopen( filename , "rt" );
    Vehicle **v = NULL;

    if( file == NULL )
    {
        printf( "\n%s\n" , "Unable to open the file or the file doesnt exist." );
    }
    else
    {
        char buffer[MAX_STRING_FILE_LENGTH];

        v = (Vehicle**) malloc( MAX_VEHICLES * sizeof( Vehicle* ) );
        
        if( v == NULL )
        {
            printf( "\n%s\n" , "Unable to allocate memory." );
        }
        else
        {
            // read header
            __file_readline( buffer, MAX_STRING_FILE_LENGTH, file );
            
            int x = 0;
            while( __file_readline( buffer, MAX_STRING_FILE_LENGTH, file ) )
            {
                Vehicle *vehicle = vehicle_alloc( );

                char** tokens = str_split( buffer, ';' );

                if( tokens == NULL ) 
                {
                    printf( "\n%s\n" , "Unable to split the string." );
                }
                else
                {
                    vehicle_set( vehicle, tokens[0], tokens[1], tokens[2], atoi(tokens[3]), atof(tokens[4]), 
                                (strcmp(tokens[5], "Car") == 0) ? Car : Motorcycle, tokens[6] );
                    
                    v[x] = vehicle;
                } // if
                x = x + 1;
            } // while
            N_VEHICLES = x;
        } // if
    } // if

    fclose( file );

    return ( v );
} // __file_read_csv ( )

void __file_write_csv( const char* filename, Vehicle** v )
{
    FILE *file = fopen( filename , "wt" );

    if( file == NULL )
    {
        printf( "\n%s\n" , "Unable to open the file or the file doesnt exist." );
    }
    else
    {
        fprintf( file, "%s;%s;%s;%s;%s;%s;%s\n", "Plate", "Brand", "Model", "Year", "Price", "Type", "Note" );

        for( int x = 0; x < N_VEHICLES; x = x + 1 )
        {
            fprintf( file, "%s;%s;%s;%d;%.2lf;%s;%s\n", 
                        vehicle_get_Plate( v[x] ), 
                        vehicle_get_Brand( v[x] ), 
                        vehicle_get_Model( v[x] ), 
                        vehicle_get_Year( v[x] ), 
                        vehicle_get_Price( v[x] ), 
                        (vehicle_get_Type( v[x] ) == Car) ? "Car" : "Motorcycle", 
                        vehicle_get_Note( v[x] ) );
        } // for
    } // if

    fclose( file );
} // __file_write_csv ( )

void __free_vehicles( Vehicle** v )
{
    for( int x = 0; x < N_VEHICLES; x = x + 1 )
    {
        vehicle_free( v[x] );
    } // for
    free( v );
} // __free_vehicles ( )

void search_vehicle(  )
{
    printf( "\n%s\n", "> Search Vehicle");

    Vehicle** v = __file_read_csv( FILENAME );

    char plate[MAX_PLATE_LENGTH];
    printf( "\n%s", "Enter the plate: " );
    scanf( "%s", plate ); getchar( );

    bool found = false;
    for( int x = 0; x < N_VEHICLES && !found; x = x + 1 )
    {
        if( strcmp( plate, vehicle_get_Plate( v[x] ) ) == 0 )
        {
            vehicle_print( v[x] );
            found = true;
        } // if
    } // for

    __free_vehicles( v );
} // search_vehicle ( )

Vehicle* read_vehicle(  )
{
    Vehicle *v = vehicle_alloc( );
    if( v == NULL )
    {
        printf( "\n%s\n", "Unable to allocate memory." );
    } 
    else
    {
        char plate[MAX_PLATE_LENGTH];
        char brand[MAX_STRING_LENGTH];
        char model[MAX_STRING_LENGTH];
        int year;
        double price;
        type type;
        char note[MAX_STRING_LENGTH];

        do
        {   
            printf ( "%s" , "Enter the plate: " );
            scanf  ( "%s", plate );
            getchar( );

            if( strlen( plate ) < 7 || strlen( plate ) > 7 )
            {
                printf("%s\n", "The plate length is invalid. Enter another plate.");
            } // if
        } while ( ( strlen( plate ) < 7 || strlen( plate ) > 7 ) ); // do while
        
        printf( "%s" , "Enter the brand: " );
        scanf( "%s", brand ); getchar( );
        
        printf( "%s" , "Enter the model: " );
        scanf( "%s", model ); getchar( );

        do
        {
            printf( "%s" , "Enter the year: " );
            scanf( "%d", &year ); getchar( );
            if( year < 0 || year < 1900 )
            {
                printf( "%s\n" , "Please enter a valid year." );
            } // if
        } while ( year < 0 || year < 1900 ); // do while
        
        do
        {
            printf( "%s" , "Enter the price: " );
            scanf( "%lf", &price ); getchar( );
            if( price <= 0 )
            {
                printf( "%s\n" , "Please enter a valid price." );
            } // if
        } while ( price <= 0 ); // do while
        
        do
        {
            printf( "%s" , "Enter the type( 0 - Car, 1 - Motorcycle ): " );
            scanf( "%d", (int*)&type ); getchar( );
            if( type < 0 || type > 1 )
            {
                printf( "%s\n" , "Please enter a valid type." );
            } // if
        } while ( type < 0 || type > 1 ); // do while
        
        printf( "%s" , "Enter the note: " );
        scanf( "%80[^\n]", note ); getchar( );

        vehicle_set( v, plate, brand, model, year, price, type, note );
    } // if
    return ( v );
} // read_vehicle ( ) 

void create_vehicle(  )
{
    printf( "\n%s\n", "> Create Vehicle");

    Vehicle** v = __file_read_csv( FILENAME );

    Vehicle *vehicle = read_vehicle( );

    v[N_VEHICLES] = vehicle;
    N_VEHICLES = N_VEHICLES + 1;

    __file_write_csv( FILENAME, v );

    __free_vehicles( v );
} // create_vehicle ( )

void edit_vehicle(  )
{
    printf( "\n%s\n", "> Edit Vehicle");

    Vehicle** v = __file_read_csv( FILENAME );

    char plate[MAX_PLATE_LENGTH];
    printf( "\n%s", "Enter the plate: " );
    scanf( "%s", plate ); getchar( );

    bool found = false;
    for( int x = 0; x < N_VEHICLES && !found; x = x + 1 )
    {
        if( strcmp( plate, vehicle_get_Plate( v[x] ) ) == 0 )
        {
            vehicle_print( v[x] );
            Vehicle *vehicle = read_vehicle( );
            vehicle_free( v[x] );
            v[x] = vehicle;
            found = true;
        } // if
    } // for

    __file_write_csv( FILENAME, v );

    __free_vehicles( v );
} // edit_vehicle ( )

void delete_vehicle(  )
{
    printf( "\n%s\n", "> Delete Vehicle");

    Vehicle** v = __file_read_csv( FILENAME );

    char plate[MAX_PLATE_LENGTH];
    printf( "\n%s", "Enter the plate: " );
    scanf( "%s", plate ); getchar( );

    bool found = false;
    for( int x = 0; x < N_VEHICLES && !found; x = x + 1 )
    {
        if( strcmp( plate, vehicle_get_Plate( v[x] ) ) == 0 )
        {
            vehicle_free( v[x] );
            for( int y = x; y < N_VEHICLES - 1; y = y + 1 )
            {
                v[y] = v[y + 1];
            } // for
            N_VEHICLES = N_VEHICLES - 1;
            found = true;
        } // if
    } // for

    __file_write_csv( FILENAME, v );

    __free_vehicles( v );
} // delete_vehicle ( )

void list_vehicles(  )
{
    printf( "\n%s\n", "> List Vehicles");

    Vehicle** v = __file_read_csv( FILENAME );

    for( int x = 0; x < N_VEHICLES; x = x + 1 )
    {
        if( vehicle_exists( v[x] ) )
        {
            vehicle_print( v[x] );
        } // if
    } // for

    __free_vehicles( v );
} // list_vehicles ( )
