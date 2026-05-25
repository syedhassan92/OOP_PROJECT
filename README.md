# OOP Library Management — Final Project 2024

> A simple console-based library management program written in C++ demonstrating object-oriented design.

## Overview

This project implements a small library system using inheritance and polymorphism. It supports multiple book types (EBook, Fictional, CourseBook, Pastpapers, PoliticalBooks), persisting entries to text files and displaying available items.

## Features

- Add books of different types and save their details to separate text files.
- View available books (reads from generated text files).
- Delete books (in-memory) by book number during runtime.
- Demonstrates basic OOP: abstract base class, derived classes, virtual methods, and friend class usage.

## Project Structure

- `projectfinal2024oop.cpp` — Main source file containing all classes and the console menu.
- `CourseBook.txt`, `Ebboks.txt`, `fictional.txt`, `pastpapers.txt`, `Politics.txt` — Data files produced by the program when adding books.

## Key Classes

- `Book` (abstract) — Base class, common book fields and virtual methods.
- `EBooks`, `FictionalBook`, `CourseBook`, `Pastpapers`, `PoliticalBooks` — Derived classes implementing `showDetails()` and `writeToFile()`.
- `Library` — Holds pointers to `Book` objects, adds books, shows available books, and manages memory.
- `LibraryManager` — Contains helper operations such as deleting a book by its number.

## Build (Windows / MinGW / g++)

Open a terminal in the project folder and run:

```bash
g++ -std=c++17 -O2 -o projectfinal projectfinal2024oop.cpp
```

Then run the program:

```bash
./projectfinal    # or projectfinal.exe on Windows
```

## Usage

Follow the interactive console menu to add books, view saved book files, and exit. Book entries are appended to text files in the same directory.

## Notes & Suggestions

- The program writes plain text files for each book type. Back up or remove these files before re-running tests to avoid duplicated entries.
- Consider adding a `.gitignore` to exclude build artifacts (e.g., `projectfinal.exe`, `*.o`) and IDE folders (e.g., `.vscode/`).
- The code contains simple input validation and will throw readable exceptions for several invalid inputs.

## Contributing

Open an issue or submit a pull request with improvements, bug fixes, or refactorings.

