
# Library Management System

This is a simple Library Management System built in C++ that allows users to manage a collection of books. The program supports adding books to the library, viewing all books, lending out books, returning lent books, and saving/loading the library data to/from a file.

## Features

- Add a Book: Allows the user to add a new book to the library with details such as book ID, title, and author.
- View All Books: Displays all books in the library with their status (available or lent out).
- Lend a Book: Lends out a book to a user if it is available.
- Return a Book: Marks a book as returned if it was previously lent out.
- Save and Load Library Data**: Saves the current state of the library to a file and loads the data back when the program restarts.

## How to Use

1. **Clone the Repository**
  -Clone the repository to your local machine using the following command:

  ```bash
  git clone https://github.com/your-username/library-management-system.git
  ```
2. **Compile the programm**
  -Open your teminal, navigate to the project folder and write:
  ```bash
    g++ -o library_system library_system.cpp
  ```