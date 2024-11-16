# Vehicle CRUD Project

This project consists of a CRUD (Create, Read, Update, Delete) system to manage vehicle information. The implementation is in the C language and follows a modular structure to facilitate code maintenance and expansion.

## Project Structure

- **`src/`**: Folder containing the project source code.

  - **`view/`**: Folder containing the view-related source code.

    - **`main.c`**: Contains the `main` function, which initializes the program, reads vehicle data from the file, 
    displays the main menu, accepts user input, and writes vehicle data back to the file.

  - **`model/`**: Folder containing the data structures and functions related to vehicle data management.

  - **`controller/`**: Folder containing the functions that handle the logic and operations for managing vehicle data, 
  such as adding, editing, and deleting vehicles.

## Compilation and Execution

To compile and run the project, use the provided `make.sh` script.

- ### On Linux and Windows (using Git Bash or similar):

To compile and run the project:

```bash
./make.sh
```

## Features

The program offers the following functionalities:

1. Search for a vehicle by plate.
2. Add a new vehicle.
3. Edit information of an existing vehicle.
4. Delete a vehicle.
5. List all vehicles.

## Data File

Vehicle data is stored in the `vehicle.csv` file in data folder. This file is read at the program's startup and updated 
at the end of the program's execution.

## Notes

- Make sure to have a C compiler installed on your system (e.g., GCC).

- Vehicle data is stored in an array structure, and the program handles a maximum of 100 vehicles.