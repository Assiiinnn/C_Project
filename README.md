# 🚀 LRU Cache Implementation in C

A lightweight, efficient, and robust implementation of a **Least Recently Used (LRU) Cache** in C.

This project demonstrates advanced data structure usage by combining a **Hash Map** (for fast access) and a **Doubly Linked List** (for ordering) to achieve **O(1)** time complexity for both `Get` and `Put` operations.

## 📋 Features

* **Fast Operations**: Constant time `O(1)` for insertions and lookups.
* **Memory Management**: Full dynamic allocation with proper memory cleanup (`lruCacheFree`) to prevent memory leaks.
* **Clean Architecture**: Separated logic (`LRU_Cache.c`) from the interface (`LRU_Cache.h`) and the application code (`main.c`).
* **Cross-Platform**: Works on Linux, macOS, and Windows.

## 📂 Project Structure

| File | Description |
| :--- | :--- |
| `LRU_Cache.h` | **Header file**: Contains structure definitions (`Node`, `LRU`) and function prototypes. |
| `LRU_Cache.c` | **Source file**: Implements the core logic (Hash Map + Doubly Linked List manipulation). |
| `main.c` | **Main entry point**: A demo program that tests the cache functionalities. |
| `Makefile` | **Build script**: Automates compilation using `make`. |
| `.gitignore` | **Git config**: Specifies files to ignore (executables, object files, etc.). |

## 🛠️ Getting Started

### Prerequisites
* **C Compiler**: GCC is recommended (MinGW for Windows).
* **Make**: (Optional) To use the automated build script.

### 1. Compilation

#### Option A: Using Make (Recommended)
If you have `make` installed, simply run:
```bash
make
