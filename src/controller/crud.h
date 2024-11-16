#include "../model/vehicle.h"

#ifndef __CRUD_H__
#define __CRUD_H__

#define MAX_PLATE_LENGTH 8
#define MAX_STRING_LENGTH 51
#define MAX_STRING_FILE_LENGTH 256

void list_vehicles  ( );
void search_vehicle ( );
void create_vehicle ( );
void edit_vehicle   ( );
void delete_vehicle ( );

#endif 
// __CRUD_H__
