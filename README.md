# C Vector

A dynamic array implementation written in C23.

This project implements a vector data structure using dynamic memory allocation. It provides basic operations for managing a collection of integers.

## Features

- Initialize a vector.
- Append elements dynamically.
- Remove the last element.
- Retrieve elements by index.
- Handle invalid indices and allocation failures.
- Release allocated memory.

## Project Structure

- `main.c` — Demonstrates and tests the vector implementation.
- `vector.h` — Declares the vector structure and public functions.
- `vector.c` — Implements the vector operations.
- `Makefile` — Defines the build instructions.
- `.gitignore` — Specifies files Git should ignore.

## Requirements

- A C23-compatible C compiler, such as Clang.
- GNU Make.

## Building

Clone the repository and navigate to its directory.

Run:

```sh
make
```

## Memory Management

The vector uses dynamically allocated memory.

Call `vector_destroy()` when you are finished using a vector to release its allocated memory.

Initialize each vector with `vector_init()` before using it.
