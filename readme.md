
# Library Management System

This is a simple Library Management System built in C++ that allows users to manage a collection of books. The program supports adding books to the library, viewing all books, lending out books, returning lent books, and saving/loading the library data to/from a file.

The system uses C++ features like classes, vectors, file I/O, and user interaction to provide an efficient way of managing a small library.

## Features

- **Add a Book**: Allows the user to add a new book to the library with details such as book ID, title, and author.
- **View All Books**: Displays all books in the library with their status (available or lent out).
- **Lend a Book**: Lends out a book to a user if it is available.
- **Return a Book**: Marks a book as returned if it was previously lent out.
- **Save and Load Library Data**: Saves the current state of the library to a file and loads the data back when the program restarts.

## How to Use

### 1. **Clone the Repository**:
   - Clone the repository to your local machine using the following command:
     ```bash
     git clone https://github.com/your-username/library-management-system.git
     ```

### 2. **Compile the Program**:
   - Open your terminal, navigate to the project folder, and compile the C++ program using:
     ```bash
     g++ -o library_system library_system.cpp
     ```

### 3. **Run the Program**:
   - Once compiled, run the program with:
     ```bash
     ./library_system
     ```

### 4. **Use the Menu**:
   - The program presents the following options:
     - **1. Add Book**: Add a new book to the library.
     - **2. View Books**: View the list of all books in the library.
     - **3. Lend Book**: Lend a book by entering its ID.
     - **4. Return Book**: Return a book by entering its ID.
     - **5. Save and Exit**: Save the current library state to a file and exit the program.

### 5. **Library File**:
   - The program reads and writes the library data to a file named `library.txt`. This file will be created and updated automatically as books are added, lent, or returned.

## Code Explanation

- **Book Class**: The `Book` class holds the attributes of each book, such as `id`, `title`, `author`, and `isLent` (whether the book is lent out or not). It also has a method to display book details.
  
- **Main Functions**:
  - `addBook()`: Prompts the user to input the book ID, title, and author, and adds the book to the library.
  - `viewBooks()`: Displays the list of all books with their details and availability status.
  - `lendBook()`: Allows the user to lend a book by providing its ID (if it's available).
  - `returnBook()`: Allows the user to return a book by providing its ID (if it's currently lent out).
  - `saveLibraryToFile()`: Saves the current state of the library to a text file (`library.txt`).
  - `loadLibraryFromFile()`: Loads the library data from `library.txt` into the program when it starts.

## Example Usage

Here’s a sample output when running the program:

```
--- Library Management System ---
1. Add Book
2. View Books
3. Lend Book
4. Return Book
5. Save and Exit
Enter your choice: 1
Enter book ID: 101
Enter book title: C++ Programming
Enter author name: John Doe
Book added successfully.

--- Library Management System ---
1. Add Book
2. View Books
3. Lend Book
4. Return Book
5. Save and Exit
Enter your choice: 2
ID: 101 | Title: C++ Programming | Author: John Doe | Status: Available

--- Library Management System ---
1. Add Book
2. View Books
3. Lend Book
4. Return Book
5. Save and Exit
Enter your choice: 3
Enter book ID to lend: 101
Book lent successfully.

--- Library Management System ---
1. Add Book
2. View Books
3. Lend Book
4. Return Book
5. Save and Exit
Enter your choice: 4
Enter book ID to return: 101
Book returned successfully.

--- Library Management System ---
1. Add Book
2. View Books
3. Lend Book
4. Return Book
5. Save and Exit
Enter your choice: 5
Library saved to library.txt.
Exiting...
```

## Contributing

If you want to contribute to this project, you can fork this repository, make improvements, or submit a pull request. You can also file issues for bugs or feature requests.

## License

This project is open-source and available under the [MIT License](LICENSE).
