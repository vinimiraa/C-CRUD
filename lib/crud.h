#ifndef __CRUD_H__
#define __CRUD_H__

#define MAX_PLATE_LENGTH 8
#define MAX_STRING_LENGTH 51
#define MAX_VEHICLES 100

extern int TOTAL_VEHICLES;

typedef enum
{
    Car,        // 0
    Motorcycle  // 1
} type;

typedef struct s_Vehicle
{
    char   Plate [MAX_PLATE_LENGTH] ;
    char   Brand [MAX_STRING_LENGTH];
    char   Model [MAX_STRING_LENGTH];
    int    Year                     ;
    double Price                    ;
    type   Type                     ;
    char   Note  [MAX_STRING_LENGTH];
} Vehicle;

void clear_screen   ( void                      );
void pause          ( const char *const text    );
void print_vehicle  ( Vehicle v                 );
void list_vehicles  ( Vehicle *v                );
void search_vehicle ( Vehicle *v                );
void add_vehicle    ( Vehicle *v                );
void edit_vehicle   ( Vehicle *v                );
void delete_vehicle ( Vehicle *v                );
void read_from_file ( Vehicle *v, char *filename);
void write_to_file  ( Vehicle *v, char *filename);

#endif // __CRUD_H__
