# Vehicle CRUD Project

This project consists of a CRUD (Create, Read, Update, Delete) system to manage vehicle information. The implementation is in the C language and follows a modular structure to facilitate code maintenance and expansion.

## Project Structure

- **`src/`**: Folder containing the project source code.

  - **`main.c`**: Contains the `main` function, which initializes the program, reads vehicle data from the file, displays the main menu, accepts user input, and writes vehicle data back to the file.

- **`lib/`**: Folder containing project modules.

  - **`menu.h` and `menu.c`**: Define and implement functions related to the main menu of the program.

  - **`crud.h` and `crud.c`**: Define and implement functions related to vehicle manipulation (add, edit, delete, etc.).

- **`test/`**: Folder containing tests or files related to tests.

  - **`vehicle.txt`**: General file used in tests.

  - **`vehicle.txt`**: File with vehicle data used in tests.

- **`app/`**: Folder containing the program executable.

  - **`program`**: Executable generated after compilation.

## Compilation and Execution

To compile the project, use the following command:

- ### On Linux:

```bash
gcc lib/*.c src/*.c -o app/program
```

To run the program:

```bash
./app/program
```

- ### On Windows:

 ```bash
gcc lib/*.c src/*.c -o app/program
```

To run the program:

```bash
cd app
program
```

## Features

The program offers the following functionalities:

1. List all vehicles.
2. Search for a vehicle by plate.
3. Add a new vehicle.
4. Edit information of an existing vehicle.
5. Delete a vehicle.

## Data File

Vehicle data is stored in the `vehicle.txt` file. This file is read at the program's startup and updated at the end of the program's execution.

## Notes

- Make sure to have a C compiler installed on your system (e.g., GCC).

- Vehicle data is stored in an array structure, and the program handles a maximum of 100 vehicles.