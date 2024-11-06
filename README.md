# Contact Manager in C

This project is a simple contact agenda developed in the C programming language. It allows the user to:

- Add contacts.
- List all contacts.
- Search for contacts by name.
- Delete contacts by name.

Contacts are stored in a text file (`contacts.txt`) to ensure data persistence between program executions.

## Table of Contents

- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Compilation and Execution](#compilation-and-execution)
- [Program Usage](#program-usage)
- [Implementation Details](#implementation-details)
- [Additional Notes](#additional-notes)

## Project Structure

```
contact_manager/
├── Makefile
├── README.md
├── include/
│   └── contact.h
├── src/
│   ├── main.c
│   └── contact.c
└── build/
```

- **Makefile**: Build file to compile the project.
- **README.md**: Project documentation.
- **include/contact.h**: Header file with definitions and function prototypes.
- **src/main.c**: Contains the `main()` function and the main menu logic.
- **src/contact.c**: Implementation of functions to manage contacts.
- **build/**: Directory where the executable and object files are generated.

## Prerequisites

- **C Compiler**: Requires `gcc` or any other compatible C compiler.
- **Operating System**: The project is developed for Unix-like systems (Linux, macOS). It may require adaptations for Windows.
- **Make**: Build tool to execute the `Makefile`.

## Compilation and Execution

### Compile the Program

1. Open a terminal and navigate to the `contact_manager` project directory.

2. Execute the `make` command to compile the program:

   ```bash
   make
   ```

   This will generate the `contact_manager` executable in the `build/` directory.

### Run the Program

1. After compiling, run the program with the following command:

   ```bash
   ./build/contact_manager
   ```

## Program Usage

When you run the program, you will see a menu with the following options:

```
====================================
        Contact Manager             
====================================
1. Add Contact
2. List Contacts
3. Find Contact
4. Delete Contact
5. Exit
Choose an option:
```

### Available Options

1. **Add Contact**: Allows you to add a new contact by requesting name, phone number, and email address.

2. **List Contacts**: Displays all contacts stored in the `contacts.txt` file.

3. **Find Contact**: Searches for contacts by the name entered.

4. **Delete Contact**: Deletes a contact by specifying the exact name.

5. **Exit**: Exits the program.

### Usage Example

#### Add a Contact

```
Choose an option: 1
Add the contact name: Juan Perez
Add the contact phone: 555-1234
Add the contact email: juan.perez@example.com
Contact saved successfully!
```

#### List Contacts

```
Choose an option: 2
List of Contacts:
--------------------------------------------------
Contact 1:
Name: Juan Perez
Phone: 555-1234
Email: juan.perez@example.com
--------------------------------------------------
```

#### Search for a Contact

```
Choose an option: 3
Enter the name to search: Juan
Search Results:
--------------------------------------------------
Name: Juan Perez
Phone: 555-1234
Email: juan.perez@example.com
--------------------------------------------------
```

#### Delete a Contact

```
Choose an option: 4
Enter the name of the contact to delete: Juan Perez
Contact 'Juan Perez' deleted successfully.
```

## Implementation Details

### Contact Storage

- Contacts are saved in a text file called `contacts.txt` in the same directory where the program is executed.
- Each contact is stored on a line in CSV format:

  ```
  Name,Phone,Email
  ```

### Main Functions

- **add_contact()**: Requests the contact's data and saves it to `contacts.txt`.
- **list_contacts()**: Reads the `contacts.txt` file and displays all contacts.
- **find_contact()**: Searches and displays contacts that match the entered name.
- **delete_contact()**: Deletes a contact from the `contacts.txt` file by exact name.

### Input Handling

- `scanf()` is used to read user inputs.
- The input buffer is cleared after each `scanf()` to avoid issues with subsequent inputs.
- It is validated that inputs do not exceed the maximum defined size for each field (50 characters).

### Format and Style

- ANSI escape sequences are used to color the output in the terminal.
- Color constants are defined in `contact.h`.

## Additional Notes

- **Spaces in Names**: To allow names with spaces, you can modify the input reading by using `fgets()` instead of `scanf()`.

  ```c
  printf("Add the contact name: ");
  if (fgets(name, sizeof(name), stdin) == NULL) {
      // Handle error
  }
  // Remove the trailing newline character
  name[strcspn(name, "\n")] = 0;
  ```

- **Compatibility**: ANSI escape sequences may not work in all terminals. If you experience strange characters, you can remove or modify the color constants.

- **Security**: This is an educational project and does not handle all security cases. It should not be used in production environments.

- **Future Enhancements**:
  - Implement additional validations on input fields (e.g., email format).
  - Improve the user interface and user experience.
  - Use more advanced data structures or integrate a database to handle large volumes of contacts.

## Contact

If you have questions or suggestions about this project, feel free to contact me.

Thank you for using the Contact Manager in C!
