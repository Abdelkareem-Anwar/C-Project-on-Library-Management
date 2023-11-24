# Book Management Program

This program is designed to manage a list of books with functionalities to add, delete, search by ID or name, and display books sorted or unsorted.

## Getting Started

### Prerequisites

- C Compiler (e.g., GCC)

### Installation

1. Clone or download the repository.
2. Compile the program using a C compiler.

### Usage

1. Run the compiled executable.
2. Follow the on-screen menu for various operations:
    - Insert a book
    - Delete a book by ID
    - Search a book by ID
    - Search a book by name
    - Display all books sorted by name
    - Display all books unsorted

### Functions

- **add_book()**: Adds a book to the list by entering ID, quantity, and name.
- **delete_book()**: Deletes a book from the list by its ID.
- **search_id()**: Searches for a book by its ID and displays its details.
- **search_name()**: Searches for a book by its name and displays its details.
- **sorted_name()**: Displays all books sorted by name.
- **unsorted()**: Displays all books in their current order.

## File Management

- The book details are stored in a file named `mybook.txt`.
- Each line in the file represents a book with ID, quantity, and name separated by tabs.

## Notes

- Ensure that the input for book details follows the specified format.
- Use appropriate input methods to prevent buffer overflow and errors.


