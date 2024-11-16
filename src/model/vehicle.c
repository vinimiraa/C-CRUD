#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool vehicle_exists( Vehicle *v )
{
    bool exists = false;
    if( v != NULL ) 
    {
        exists = true;
    } // if
    return ( exists );
} // vehicle_exists ( )

Vehicle* vehicle_alloc( )
{
    Vehicle *v = ( Vehicle* ) malloc( sizeof( Vehicle ) );
    if( v != NULL ) 
    {
        v->Plate[0] = '\0';
        v->Brand[0] = '\0';
        v->Model[0] = '\0';
        v->Year     = 0;
        v->Price    = 0.0;
        v->Type     = Car;
        v->Note[0]  = '\0';
    } // if
    return ( v );
} // vehicle_alloc ( )

void vehicle_free( Vehicle *v )
{
    if( v != NULL ) 
    {
        free( v );
    } // if
} // vehicle_free ( )

void vehicle_print( Vehicle *v )
{
    if( vehicle_exists( v ) ) 
    {
        printf( "\n" );
        printf( "Plate: %s\n"  , v->Plate );
        printf( "Brand: %s\n"  , v->Brand );
        printf( "Model: %s\n"  , v->Model );
        printf( "Year.: %d\n"  , v->Year );
        printf( "Price: %.2f\n", v->Price );
        printf( "Type.: %s\n"  , ( v->Type == Car ) ? "Car" : "Motorcycle" );
        printf( "Note.: %s\n"  , v->Note );
    } // if
} // vehicle_print ( )

void vehicle_set( Vehicle *v, char *plate, char *brand, char *model, int year, double price, type type, char *note )
{
    if( vehicle_exists( v ) )
    {
        vehicle_set_Plate( v, plate );
        vehicle_set_Brand( v, brand );
        vehicle_set_Model( v, model );
        vehicle_set_Year( v, year );
        vehicle_set_Price( v, price );
        vehicle_set_Type( v, type );
        vehicle_set_Note( v, note );
    } // if
} // init_Vehicle ( )

void vehicle_set_Plate( Vehicle *v, char *plate )
{
    if( vehicle_exists( v ) )
    {
        strncpy( v->Plate, plate, MAX_PLATE_LENGTH );
        v->Plate[MAX_PLATE_LENGTH] = '\0';
    } // if
} // vehicle_set_Plate ( )

void vehicle_set_Brand( Vehicle *v, char *brand )
{
    if( vehicle_exists( v ) )
    {
        strncpy( v->Brand, brand, MAX_STRING_LENGTH );
        v->Brand[MAX_STRING_LENGTH] = '\0';
    } // if
} // vehicle_set_Brand ( )

void vehicle_set_Model( Vehicle *v, char *model )
{
    if( vehicle_exists( v ) )
    {
        strncpy( v->Model, model, MAX_STRING_LENGTH );
        v->Model[MAX_STRING_LENGTH] = '\0';
    } // if
} // vehicle_set_Model ( )

void vehicle_set_Year( Vehicle *v, int year )
{
    if( vehicle_exists( v ) )
    {
        v->Year = year;
    } // if
} // vehicle_set_Year ( )

void vehicle_set_Price( Vehicle *v, double price )
{
    if( vehicle_exists( v ) )
    {
        v->Price = price;
    } // if
} // vehicle_set_Price ( )

void vehicle_set_Type( Vehicle *v, type type )
{
    if( vehicle_exists( v ) )
    {
        v->Type = type;
    } // if
} // vehicle_set_Type ( )

void vehicle_set_Note( Vehicle *v, char *note )
{
    if( vehicle_exists( v ) )
    {
        strncpy( v->Note, note, MAX_STRING_LENGTH );
        v->Note[MAX_STRING_LENGTH] = '\0';
    } // if
} // vehicle_set_Note ( )

char* vehicle_get_Plate( Vehicle *v )
{
    char *plate = NULL;
    if( vehicle_exists( v ) )
    {
        plate = v->Plate;
    } // if
    return ( plate );
} // vehicle_get_Plate ( )

char* vehicle_get_Brand( Vehicle *v )
{
    char *brand = NULL;
    if( vehicle_exists( v ) )
    {
        brand = v->Brand;
    } // if
    return ( brand );
} // vehicle_get_Brand ( )

char* vehicle_get_Model( Vehicle *v )
{
    char *model = NULL;
    if( vehicle_exists( v ) )
    {
        model = v->Model;
    } // if
    return ( model );
} // vehicle_get_Model ( )

int vehicle_get_Year( Vehicle *v )
{
    int year = 0;
    if( vehicle_exists( v ) )
    {
        year = v->Year;
    } // if
    return ( year );
} // vehicle_get_Year ( )

double vehicle_get_Price( Vehicle *v )
{
    double price = 0.0;
    if( vehicle_exists( v ) )
    {
        price = v->Price;
    } // if
    return ( price );
} // vehicle_get_Price ( )

type vehicle_get_Type( Vehicle *v )
{
    type type = Car;
    if( vehicle_exists( v ) )
    {
        type = v->Type;
    } // if
    return ( type );
} // vehicle_get_Type ( )

char* vehicle_get_Note( Vehicle *v )
{
    char *note = NULL;
    if( vehicle_exists( v ) )
    {
        note = v->Note;
    } // if
    return ( note );
} // vehicle_get_Note ( )

Vehicle* vehicle_clone( Vehicle *v )
{
    Vehicle *clone = NULL;
    if( vehicle_exists( v ) )
    {
        clone = vehicle_alloc( );
        if( vehicle_exists( clone ) )
        {
            vehicle_set( clone, v->Plate, v->Brand, v->Model, v->Year, v->Price, v->Type, v->Note );
        } // if
    } // if
    return ( clone );
} // vehicle_clone ( )

int vehicle_compare( Vehicle *v1, Vehicle *v2 )
{
    int cmp = false;
    if( vehicle_exists( v1 ) && vehicle_exists( v2 ) )
    {
        cmp = strcmp( v1->Plate, v2->Plate );
    } // if
    return ( cmp );
} // vehicle_compare ( )
