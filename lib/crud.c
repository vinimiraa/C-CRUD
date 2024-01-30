#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include "crud.h"

int TOTAL_VEHICLES = 0;

void clear_screen ( )
{
    #if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
        system ( "cls"   ); // para Windows - OBS: NAO RECOMENDADO !
    #elif defined(__linux__)
        system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    #elif defined(__APPLE__) && defined(__MACH__)
        system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    #elif defined(unix) || defined(__unix__) || defined(__unix)
        system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    #else
        #error Unknown_OS
    #endif
} // end clear ( )

void pause ( const char * const text )
{
    char x = '0';
    printf("\n%s\n", text);
    do { x = getchar( ); } while ( '\n' != x );
} // end pause ( )

void  print_vehicle  ( Vehicle v  )
{

    printf( "\n%s\n"    , "Vehicle details: " );
    printf( " %s%s\n"    , "Plate: " , v.Plate );
    printf( " %s%s\n"    , "Brand: " , v.Brand );
    printf( " %s%s\n"    , "Model: " , v.Model );
    printf( " %s%d\n"    , "Year : " , v.Year  );
    printf( " %s%.2lf\n" , "Year : " , v.Price );
    printf( " %s%s\n"    , "Type : " , v.Type == Car ? "Car" : "Motorcycle" );
    printf( " %s%s\n"    , "Note : " , v.Note   );

} // end print_vehicle ( )

void   list_vehicles ( Vehicle *v )
{

    printf( "\n%s\n", "// -------- Vehicle List ------- //");

    printf( "\n" );
    printf( "PLATE\t\tBRAND\t\tMODEL\t\tYEAR\t\tPRICE\t\tTYPE\t\tNOTE");
    printf( "\n\n" );
    
    for( int x = 0; x < TOTAL_VEHICLES; x = x + 1 )
    {
        printf(    "%s\t\t" , v[x].Plate );
        printf(    "%s\t\t" , v[x].Brand );
        printf(    "%s\t\t" , v[x].Model );
        printf(    "%d\t\t" , v[x].Year  );
        if( v[x].Price < 1000 )
        {
            printf(   "%.2lf\t\t" , v[x].Price );
        }
        else
        {
            printf(   "%.2lf\t" , v[x].Price );
        }
        if( v[x].Type == Car )
        {
            printf(    "%s\t\t" , "Car" );
        }
        else
        {
            printf(    "%s\t" , "Motorcycle" );
        } // end if
        printf(    "%s"     , v[x].Note  );
        printf( "\n" );
    } // end for

    printf( "\n%s\n", "// ----------------------------- //");

    pause( "Press ENTER to continue." );

} // end list_vehicles ( )

void search_vehicle  ( Vehicle *v )
{

    char plate [ MAX_PLATE_LENGTH ] = "0";
    bool found = false;

    printf( "\n%s\n", "// ------- Search Vehicle ------ //");

    printf ( "\n%s" , "Enter the plate: " );
    scanf  ( "%s" , plate );
    getchar( );

    for( int x = 0; x < TOTAL_VEHICLES; x = x + 1 )
    {
        if( strcmp( plate, v[x].Plate ) == 0 )
        {
            found = true;

            print_vehicle( v[x] );

            x = TOTAL_VEHICLES;
        } // end if
    } // end for

    if( !found )
    {
        printf( "\n%s\n" , " [ ERROR: The plate given doesnt exist. ]" );
    } // end if

    printf( "\n%s\n", "// ----------------------------- //");

    pause( "Press ENTER to continue." );

} // end search_vehicle ( )

void    add_vehicle  ( Vehicle *v )
{

    char   plate [ MAX_PLATE_LENGTH  ] = "0" ;
    char   brand [ MAX_STRING_LENGTH ] = "0" ;
    char   model [ MAX_STRING_LENGTH ] = "0" ;
    int    year                        =  0  ;
    double price                       =  0.0;
    type   type                              ;
    char   note  [ MAX_STRING_LENGTH ] = "0" ;
    int x = 0;

    printf( "\n%s\n" , "// -------- Add Vehicle -------- //");

    do
    {   
        x = 0;

        printf ( "\n%s" , "Enter the plate: " );
        scanf  ( "%s", plate );
        getchar( );

        while( x < TOTAL_VEHICLES && strcmp(plate, v[x].Plate) != 0 )
        {
            x = x + 1;
        } // end while

        if( x < TOTAL_VEHICLES )
        {
            printf("\n%s\n", " [ ERROR: The plate already exists. Enter another plate. ]");
        } // end if

        if( strlen( plate ) < 7 || strlen( plate ) > 7 )
        {
            printf("\n%s\n", " [ ERROR: The plate length is invalid. Enter another plate. ]");
        } // end if

    } while ( x < TOTAL_VEHICLES || ( strlen( plate ) < 7 || strlen( plate ) > 7 ) ); // end do while
    
    printf ( "\n%s" , "Enter the brand: " );
    scanf  ( "%s", brand );
    getchar( );
    
    printf ( "\n%s" , "Enter the model: " );
    scanf  ( "%s", model );
    getchar( );

    do
    {
        printf ( "\n%s" , "Enter the year: " );
        scanf  ( "%d", &year );
        getchar( );
        if( year < 0 || year < 1900 )
        {
            printf( "\n%s\n" , " [ ERROR: Please enter a valid year. ]" );
        }
    } while ( year < 0 || year < 1900 ); // end do while
    
    do
    {
        printf ( "\n%s" , "Enter the price: " );
        scanf  ( "%lf", &price );
        getchar( );
        if( price <= 0 )
        {
            printf( "\n%s\n" , " [ ERROR: Please enter a valid price. ]" );
        }
    } while ( price <= 0 ); // end do while
    
    do
    {
        printf ( "\n%s" , "Enter the type( 0 - Car, 1 - Motorcycle ): " );
        scanf  ( "%d", (int*)&type );
        getchar( );
        if( type < 0 || type > 1 )
        {
            printf( "\n%s\n" , " [ ERROR: Please enter a valid type. ]" );
        }
    } while ( type < 0 || type > 1 ); // end do while
    
    printf ( "\n%s" , "Enter the note: " );
    scanf  ( "%50[^\n]", note );
    getchar( );

    strcpy( v[TOTAL_VEHICLES].Plate , plate );
    strcpy( v[TOTAL_VEHICLES].Brand , brand );
    strcpy( v[TOTAL_VEHICLES].Model , model );
            v[TOTAL_VEHICLES].Year  = year   ;
            v[TOTAL_VEHICLES].Price = price  ;
            v[TOTAL_VEHICLES].Type  = type   ;
    strcpy( v[TOTAL_VEHICLES].Note  , note  );

    print_vehicle( v[TOTAL_VEHICLES] );

    TOTAL_VEHICLES = TOTAL_VEHICLES + 1;

    printf( "\n%s\n" , "**Vehicle successfully registered**");

    printf( "\n%s\n" , "// ----------------------------- //");

    pause( "Press ENTER to continue." );

} // end add_vehicle ( )

void edit_vehicle  ( Vehicle *v )
{

    char   plate [ MAX_PLATE_LENGTH  ] = "0" ;
    char   brand [ MAX_STRING_LENGTH ] = "0" ;
    char   model [ MAX_STRING_LENGTH ] = "0" ;
    int    year                        =  0  ;
    double price                       =  0.0;
    type   type                              ;
    char   note  [ MAX_STRING_LENGTH ] = "0" ;
    bool found = false;

    printf( "\n%s\n" , "// -------- Edit Vehicle ------- //");

    printf ( "\n%s" , "Enter the plate: " );
    scanf  ( "%s" , plate );
    getchar( );

    for( int x = 0; x < TOTAL_VEHICLES; x = x + 1 )
    {
        if( strcmp( plate, v[x].Plate ) == 0 )
        {
            found = true;

            print_vehicle( v[x] );

            printf( "\n%s\n" , "Enter the new informations: " );

            printf ( "\n%s" , "Enter the brand: " );
            scanf  ( "%s", brand );
            getchar( );
            
            printf ( "\n%s" , "Enter the model: " );
            scanf  ( "%s", model );
            getchar( );
        
            do
            {
                printf ( "\n%s" , "Enter the year: " );
                scanf  ( "%d", &year );
                getchar( );
                if( year < 0 || year < 1900 )
                {
                    printf( "\n%s\n" , " [ ERROR: Please enter a valid year. ]" );
                }
            } while ( year < 0 || year < 1900 ); // end do while
            
            do
            {
                printf ( "\n%s" , "Enter the price: " );
                scanf  ( "%lf", &price );
                getchar( );
                if( price <= 0 )
                {
                    printf( "\n%s\n" , " [ ERROR: Please enter a valid price. ]" );
                }
            } while ( price <= 0 ); // end do while
            
            do
            {
                printf ( "\n%s" , "Enter the type( 0 - Car, 1 - Motorcycle ): " );
                scanf  ( "%d", (int*)&type );
                getchar( );
                if( type < 0 || type > 1 )
                {
                    printf( "\n%s\n" , " [ ERROR: Please enter a valid type. ]" );
                }
            } while ( type < 0 || type > 1 ); // end do while
            
            printf ( "\n%s" , "Enter the note: " );
            scanf  ( "%50[^\n]", note );
            getchar( );

            strcpy( v[x].Plate , plate );
            strcpy( v[x].Brand , brand );
            strcpy( v[x].Model , model );
                    v[x].Year  = year   ;
                    v[x].Price = price  ;
                    v[x].Type  = type   ;
            strcpy( v[x].Note  , note  );

            print_vehicle( v[x] );

            printf( "\n%s\n" , "**Vehicle updated successfully**");
        } // end if
    } // end for

    if( !found )
    {
        printf( "\n%s\n" , " [ ERROR: The plate given doesnt exist. ]" );
    } // end if

    printf( "\n%s\n" , "// ----------------------------- //");

    pause( "Press ENTER to continue." );

} // end edit_vehicle ( )

void delete_vehicle  ( Vehicle *v )
{

    char plate [ MAX_PLATE_LENGTH ];
    char  option = '0';
    bool found  = false;

    printf( "\n%s\n" , "// ------- Delete Vehicle ------ //");

    printf ( "\n%s" , "Enter the plate: " );
    scanf  ( "%s" , plate );
    getchar( );

    for( int x = 0; x < TOTAL_VEHICLES; x = x + 1 )
    {
        if( strcmp( plate , v[x].Plate ) == 0 )
        {
            found = true;

            print_vehicle( v[x] );
            do
            {
                printf ( "\n%s\n" , "Do you want to delete the vehicle ( Y - yes, N - No )?" );
                scanf  ( "%c" , &option );
                getchar( );
            } while( toupper( option ) != 'Y' && toupper( option ) != 'N' );

            if( toupper( option ) == 'Y' )
            {
                for( int y = x+1; y < TOTAL_VEHICLES; y = y + 1 )
                {
                    v[y-1] = v[y];
                } // end for

                TOTAL_VEHICLES = TOTAL_VEHICLES - 1;

                printf( "\n%s\n" , "**Vehicle successfully deleted**" );
            }
            else
            {
                printf( "\n%s\n" , "**Canceled deletion**" );
            } // end if
        } // end if
    } // end for

    if( !found )
    {
        printf( "\n%s\n" , " [ ERROR: The plate given doesnt exist. ]" );
    } // end if

    printf( "\n%s\n" , "// ----------------------------- //");

    pause( "Press ENTER to continue." );

} // end delete_vehicle ( )

void read_from_file ( Vehicle *v, char *filename )
{
    char   plate [ MAX_PLATE_LENGTH  ] = "0" ;
    char   brand [ MAX_STRING_LENGTH ] = "0" ;
    char   model [ MAX_STRING_LENGTH ] = "0" ;
    int    year                        =  0  ;
    double price                       =  0.0;
    char   type  [ MAX_STRING_LENGTH ] = "0" ;
    char   note  [ MAX_STRING_LENGTH ] = "0" ;
    int    quantity                    =  0  ;
    int    x                           =  0  ;

    FILE *file = fopen( filename , "rt" );

    clear_screen( );
    sleep( 1 );
    printf( "\n%s\n" , "// -------- Reading File ------- //");

    if( file == NULL )
    {
        printf( "\n%s\n" , "ERROR: Unable to open the file or the file doesnt exist." );
    }
    else
    {
        fscanf( file, "%d", &quantity ); fgetc( file );

        if( quantity <= 0 )
        {
            printf( "\n%s\n" , "ERROR: Invalid number of vehicles." );
        }
        else
        {
            TOTAL_VEHICLES = quantity;

            x = 0;
            while( !feof( file ) && x < quantity )
            {
                fscanf( file, "%s %s %s %d %lf %s %[^\n]",
                            plate, 
                            brand,
                            model,
                            &year, 
                            &price, 
                            type, 
                            note 
                        );
                
                strcpy( v[x].Plate , plate );
                strcpy( v[x].Brand , brand );
                strcpy( v[x].Model , model );
                        v[x].Year  = year   ;
                        v[x].Price = price  ;
                if( strcmp( type, "Car" ) == 0 )
                {
                    v[x].Type = 0;
                }
                else
                {
                    v[x].Type = 1;
                }
                strcpy( v[x].Note  , note  );

                x = x + 1;
            } // end while

            sleep( 2 );
            printf( "\n%s\n" , "  **File read successfully**" );

        } // end if
    } // end if

    fclose( file );

    printf( "\n%s\n" , "// ----------------------------- //");
    sleep( 2 );

} // end read_from_file ( )

void write_to_file  ( Vehicle *v, char *filename )
{

    FILE *file = fopen( filename , "wt" );

    clear_screen( );
    sleep( 1 );
    printf("\n%s\n", "// -------- Writing to File ------- //");

    fprintf( file, "%d\n", TOTAL_VEHICLES );

    for( int x = 0; x < TOTAL_VEHICLES; x = x + 1 )
    {
        fprintf( file, "%s %s %s %d %.2lf %s %s\n", 
                        v[x].Plate, 
                        v[x].Brand, 
                        v[x].Model,
                        v[x].Year, 
                        v[x].Price, 
                        (v[x].Type == Car) ? "Car" : "Motorcycle", 
                        v[x].Note
                );
    } // end for

    sleep( 2 );
    printf("\n%s\n", "  **File written successfully**");

    printf("\n%s\n", "// ----------------------------- //");
    sleep( 2 );
    clear_screen( );

    fclose( file );

} // end write_to_file ( )