#include <stdio.h>
#include <stdbool.h>

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#define MAX_PLATE_LENGTH 9
#define MAX_STRING_LENGTH 81

typedef enum
{
    Car,
    Motorcycle
} type;

typedef struct s_Vehicle
{
    char   Plate[MAX_PLATE_LENGTH];
    char   Brand[MAX_STRING_LENGTH];
    char   Model[MAX_STRING_LENGTH];
    int    Year;
    double Price;
    type   Type;
    char   Note[MAX_STRING_LENGTH];
} Vehicle;

bool vehicle_exists( Vehicle *v );
Vehicle* vehicle_alloc( );
void vehicle_free( Vehicle *v );
void vehicle_print( Vehicle *v );
void vehicle_set( Vehicle *v, char *plate, char *brand, char *model, int year, double price, type type, char *note );
void vehicle_set_Plate( Vehicle *v, char *plate );
void vehicle_set_Brand( Vehicle *v, char *brand );
void vehicle_set_Model( Vehicle *v, char *model );
void vehicle_set_Year( Vehicle *v, int year );
void vehicle_set_Price( Vehicle *v, double price );
void vehicle_set_Type( Vehicle *v, type type );
void vehicle_set_Note( Vehicle *v, char *note );
char* vehicle_get_Plate( Vehicle *v );
char* vehicle_get_Brand( Vehicle *v );
char* vehicle_get_Model( Vehicle *v );
int vehicle_get_Year( Vehicle *v );
double vehicle_get_Price( Vehicle *v );
type vehicle_get_Type( Vehicle *v );
char* vehicle_get_Note( Vehicle *v );
Vehicle* vehicle_clone( Vehicle *v );
int vehicle_compare( Vehicle *v1, Vehicle *v2 );

#endif 
// __VEHICLE_H__