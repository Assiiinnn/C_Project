# 🚀 LRU Cache Implementation in C

![Build Status](https://github.com/Assiiinnn/C_Project/actions/workflows/test.yml)

An efficient implementation of the **Least Recently Used (LRU) Cache** algorithm in C with interactive visualization.

## 📌 Problem Description & LeetCode Reference

**Problem:** Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

* `lRUCacheCreate(int capacity)` Initialize the LRU cache with positive size capacity.
* `lRUCacheGet(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
* `lRUCachePut(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.

**Reference:** [LeetCode #146 - LRU Cache](https://leetcode.com/problems/lru-cache/)

## 🌍 Real-Life Use Case

A classic example of an LRU Cache is a **Web Browser History**:

Imagine your browser can only remember the last 100 pages you visited to let you go "Back".

1. When you visit a page, it's added to the top of the list.
2. If you revisit an old page, it moves back to the top (it becomes "recently used").
3. If you visit a 101st page, the browser "forgets" the oldest page at the bottom of the list to make room.

## 💡 Approach and Explanation

To achieve **O(1)** time complexity, we use a **Hybrid Data Structure**:

1. **Doubly Linked List**: Stores the actual keys and values ordered by usage.
   * **Head**: Most Recently Used (MRU).
   * **Tail**: Least Recently Used (LRU).
2. **Hash Map (Array of Pointers)**: Stores pointers to the nodes in the linked list.
   * Allows us to jump directly to a node in the list without scanning it.

## ⏱️ Time and Space Complexity

* **Time Complexity:** **O(1)** (Constant time) for both `Put` and `Get` operations.
* **Space Complexity:** **O(C)** where C is the capacity.

## 📂 Project Structure

```
C_Project/
├── .github/
│   └── workflows/
│       └── test.yml        # CI/CD pipeline configuration
├── docs/
│   └── index.html          # 🎨 BONUS: Interactive web visualizer
├── src/
│   ├── LRU_Cache.c         # Core LRU implementation
│   └── LRU_Cache.h         # Header file with API definitions
├── tests/
│   ├── input.json          # Test case definitions
│   └── test_lru.c          # Unit test suite
├── .gitignore              # Git ignore rules
├── Makefile                # Build automation
└── README.md               # This file
```

## 🛠️ How to Compile and Run

### Prerequisites

* **GCC Compiler** (MinGW on Windows)
* **Make** (optional but recommended)
* **Git** (for cloning the repository)

### 🔽 Clone the Repository

```bash
git clone https://github.com/Assiiinnn/C_Project.git
cd C_Project
```

### 🏗️ Build and Test

#### Option A: Using Make (Recommended)

```bash
# Build everything (main app + tests)
make

# Run unit tests
make test

# Clean build artifacts
make clean

# Rebuild from scratch
make rebuild
```

#### Option B: Manual Compilation

**On Linux/Mac:**
```bash
# Compile the test executable
gcc -Wall -Wextra -std=c99 -Isrc src/LRU_Cache.c tests/test_lru.c -o test_lru

# Run tests
./test_lru
```

**On Windows (with MinGW):**
```bash
# Compile the test executable
gcc -Wall -Wextra -std=c99 -Isrc src/LRU_Cache.c tests/test_lru.c -o test_lru.exe

# Run tests
test_lru.exe
```

### ✅ Expected Test Output

```
Running LRU Cache Tests...

✓ Basic operations test passed
✓ Single capacity test passed
✓ Update existing test passed
✓ Empty cache test passed
✓ LRU order test passed

✅ All tests passed!
```

## 🎨 **BONUS: Interactive Web Visualization**

We've added an **interactive HTML/JavaScript interface** to visualize how the LRU Cache algorithm works in real-time!

### ✨ Features:
- 🎯 **Step-by-step visualization** of cache operations
- 🎨 **Color-coded nodes** showing MRU to LRU order
- 🔄 **Live animation** of insertions, updates, and evictions
- 📊 **Operation history** with detailed logs
- 🎮 **Interactive controls** to test different scenarios

### 🌐 Try it Live:
**[🚀 Launch the LRU Cache Visualizer](https://assiiinnn.github.io/C_Project/)**

### 💻 Run Locally:

**Method 1: Direct File Opening**
```bash
# On Linux/Mac
open docs/index.html

# On Windows
start docs/index.html

# Or simply double-click docs/index.html
```

**Method 2: Using Python HTTP Server**
```bash
# Start a local web server
python3 -m http.server 8000

# Then open in browser:
# http://localhost:8000/docs/index.html
```

## 🧪 GitHub Actions CI/CD

This project uses **GitHub Actions** for continuous integration. Every push and pull request automatically:

1. ✅ Installs dependencies (GCC, Make)
2. ✅ Compiles the project
3. ✅ Runs the complete test suite
4. ✅ Verifies build artifacts

View the workflow: `.github/workflows/test.yml`

### 📊 Build Badge Status

The badge at the top shows real-time build status:
- 🟢 **Passing**: All tests passed successfully
- 🔴 **Failing**: Build or tests failed
- 🟡 **Building**: Currently running

## 📚 API Reference

### Core Functions

```c
// Create a new LRU Cache with specified capacity
LRUCache* lRUCacheCreate(int capacity);

// Get value by key (returns -1 if not found)
int lRUCacheGet(LRUCache* cache, int key);

// Put key-value pair (evicts LRU item if cache is full)
void lRUCachePut(LRUCache* cache, int key, int value);

// Free all allocated memory
void lRUCacheFree(LRUCache* cache);
```

### Example Usage

```c
#include "LRU_Cache.h"

int main() {
    // Create cache with capacity 2
    LRUCache* cache = lRUCacheCreate(2);
    
    lRUCachePut(cache, 1, 1);  // Cache: {1=1}
    lRUCachePut(cache, 2, 2);  // Cache: {2=2, 1=1}
    
    int val = lRUCacheGet(cache, 1);  // Returns 1
                                       // Cache: {1=1, 2=2}
    
    lRUCachePut(cache, 3, 3);  // Evicts key 2
                                // Cache: {3=3, 1=1}
    
    val = lRUCacheGet(cache, 2);  // Returns -1 (not found)
    val = lRUCacheGet(cache, 3);  // Returns 3
    
    // Clean up
    lRUCacheFree(cache);
    return 0;
}
```

## 🧪 Testing

### Test Coverage

Our test suite (`tests/test_lru.c`) includes:

- ✅ **Basic operations**: Standard put/get operations
- ✅ **Single capacity**: Edge case with capacity = 1
- ✅ **Update existing**: Updating existing keys without eviction
- ✅ **Empty cache**: Getting from empty cache
- ✅ **LRU order**: Verifying correct eviction order

### Test Configuration

Test cases are defined in `tests/input.json` and can be easily extended:

```json
{
  "tests": [
    {
      "name": "Basic Operations",
      "capacity": 2,
      "operations": [
        {"op": "put", "key": 1, "value": 1, "expected": null},
        {"op": "get", "key": 1, "expected": 1}
      ]
    }
  ]
}
```

## 🚀 Quick Start Guide

### For Contributors

```bash
# 1. Fork and clone the repository
git clone https://github.com/YOUR_USERNAME/C_Project.git
cd C_Project

# 2. Create a feature branch
git checkout -b feature/your-feature

# 3. Make your changes and test
make clean
make test

# 4. Commit and push
git add .
git commit -m "Add your feature"
git push origin feature/your-feature

# 5. Create a Pull Request on GitHub
```

### For Users

```bash
# Quick test run
git clone https://github.com/Assiiinnn/C_Project.git
cd C_Project
make test
```

## 🐛 Troubleshooting

### Issue: "make: command not found"
**Solution:** Use manual compilation commands listed above, or install Make:
- **Ubuntu/Debian:** `sudo apt-get install make`
- **Mac:** `xcode-select --install`
- **Windows:** Install [MinGW](https://www.mingw-w64.org/) or use WSL

### Issue: "gcc: command not found"
**Solution:** Install GCC compiler:
- **Ubuntu/Debian:** `sudo apt-get install gcc`
- **Mac:** `xcode-select --install`
- **Windows:** Install [MinGW](https://www.mingw-w64.org/)

### Issue: Tests failing
**Solution:** 
1. Ensure you're in the project root directory
2. Run `make clean` then `make test`
3. Check that all files in `src/` and `tests/` are present

## 📖 Learn More

- [LeetCode Problem #146](https://leetcode.com/problems/lru-cache/)
- [Doubly Linked Lists Explained](https://en.wikipedia.org/wiki/Doubly_linked_list)
- [Cache Replacement Policies](https://en.wikipedia.org/wiki/Cache_replacement_policies)

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes:

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## 📄 License

This project is open source and available under the MIT License.

## 👨‍💻 Author

Made with ❤️ by [Assiiinnn](https://github.com/Assiiinnn)

## 🌟 Acknowledgments

- LeetCode for the original problem
- The C programming community
- All contributors and testers

---

⭐ **If you found this project helpful, please give it a star on GitHub!**

📧 **Questions or suggestions?** Open an issue or reach out!
