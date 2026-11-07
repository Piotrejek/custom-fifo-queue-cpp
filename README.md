# Custom FIFO Queue in C++

A dynamic, array-based FIFO (First-In-First-Out) Queue implemented from scratch in C++. This project utilizes a circular buffer approach and features an interactive console menu alongside educational demonstrations of core C++ concepts like memory management, pointers, and references.

Repository: [custom-fifo-queue-cpp](https://github.com/Piotrejek/custom-fifo-queue-cpp)

## Features

### Core Queue Implementation

- **Circular Buffer Architecture:** Efficient array space utilization using modulo arithmetic `(head + count) % capacity`.
- **Dynamic Resizing:** Automatically doubles the array capacity when full, preventing queue overflow.
- **Robust Memory Management:** Implements the Rule of Three (Destructor, Copy Constructor, Copy Assignment Operator) to ensure deep copying and prevent memory leaks.
- **Interactive CLI:** A menu-driven interface to `enqueue`, `dequeue`, `peek`, and `display` the queue states in real-time.

### Educational Demonstrations (`runDemos()`)

- **Pointers vs. References:** A practical comparison of swapping variables by value, pointer, and reference.
- **Recursion:** Array summation using recursive function calls and reference counters.
- **Object Passing (Value vs. Reference):** Demonstrates how passing objects by value triggers the copy constructor and how passing by reference avoids unnecessary memory allocation.

## Technologies

- C++
- Standard C++ Library
- GCC / G++ Compiler

## Project Structure

- `app.cpp` - The main source code containing the Queue class, demonstration functions, and the main loop with the interactive menu.
- `.gitignore` - Excludes compiled binaries and IDE configuration files from version control.
- `README.md` - Project documentation.

## Prerequisites

To compile and run this project, you need:

- A C++ compiler (GCC, Clang, or MSVC).
- A terminal or command-line interface.

## Build and Run

Clone the repository:

```bash
git clone https://github.com/Piotrejek/custom-fifo-queue-cpp.git
cd custom-fifo-queue-cpp
```

### Linux / macOS

Compile the project:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic app.cpp -o app
```

Run the application:

```bash
./app
```

### Windows (CMD / PowerShell)

Compile the project:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic app.cpp -o app.exe
```

Run the application:

```powershell
.\app.exe
```

**Note:** The commands above assume that GCC/G++ is installed and available in your system PATH.

## How It Works

The queue uses a circular buffer to manage elements inside a dynamically allocated array.

- `head` keeps track of the first element in the queue.
- `count` stores the current number of elements.
- `capacity` represents the total allocated array size.

Modulo arithmetic allows the queue to reuse previously freed positions without shifting existing elements. When the buffer becomes full, its capacity is doubled and the existing elements are copied into a new array in the correct FIFO order.

## Usage Example

Upon execution, the program first runs the educational memory demonstrations and then launches the interactive queue menu:

```text
FIFO Queue Implementation (Circular Buffer)

1. Add new
2. Remove
3. Peek
4. Display
5. Exit

Choice: 1
Enter value: 50
Added: 50

Choice: 1
Enter value: 2
Added: 2

Choice: 3
Front value: 50

Choice: 4
Queue elements: 50 2
(Capacity: 2, Size: 2)

Choice: 2
Removed: 50

Choice: 4
Queue elements: 2
(Capacity: 2, Size: 1)

Choice: 5
```

## Concepts Covered

- Object-Oriented Programming (OOP) in C++.
- Dynamic Memory Allocation (`new` / `delete[]`).
- The Rule of Three (Memory Management).
- Circular Arrays and Modulo Arithmetic.
- Pointers and References.
- Recursion.
- Copy Constructors and Assignment Operators.
- Passing Objects by Value and by Reference.
