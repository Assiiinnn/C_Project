# 🚀 LRU Cache Implementation in C

![Build Status](https://github.com/Assiiinnn/C_Project/actions/workflows/test.yml/badge.svg)

An efficient implementation of the **Least Recently Used (LRU) Cache** algorithm in C.

## 📌 Problem Description & LeetCode Reference

**Problem:** Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
* `lRUCacheCreate(int capacity)` Initialize the LRU cache with positive size capacity.
* `lRUCacheGet(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
* `lRUCachePut(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.

**Reference:** [LeetCode #146 - LRU Cache](https://leetcode.com/problems/lru-cache/)

## 🌍 Real-Life Use Case

A classic example of an LRU Cache is a **Web Browser History**:
Imagine your browser can only remember the last 100 pages you visited to let you go "Back".
1.  When you visit a page, it's added to the top of the list.
2.  If you revisit an old page, it moves back to the top (it becomes "recently used").
3.  If you visit a 101st page, the browser "forgets" the oldest page at the bottom of the list to make room.

## 💡 Approach and Explanation

To achieve **O(1)** time complexity, we cannot use a simple array or a simple linked list. We use a **Hybrid Data Structure**:

1.  **Doubly Linked List**: Stores the actual keys and values ordered by usage.
    * **Head**: Most Recently Used (MRU).
    * **Tail**: Least Recently Used (LRU).
2.  **Hash Map (Array of Pointers)**: Stores pointers to the nodes in the linked list.
    * Allows us to jump directly to a node in the list without scanning it.

## ⏱️ Time and Space Complexity

* **Time Complexity:** **O(1)** (Constant time) for both `Put` and `Get` operations.
* **Space Complexity:** **O(C)** where C is the capacity.

## 🛠️ How to Compile and Run Tests

### Prerequisites
* GCC Compiler
* Make (Optional)

### 1. Compilation

**Option A: Using Make (Recommended for Linux/GitHub)**
```bash
make
```
#### Option B: Manual Compilation (No Make installed)
If you do not have `make` installed (common on Windows), you can compile the project manually using GCC.

```bash
gcc main.c LRU_Cache.c -o lru_app
.\lru_app.exe
```
## 🎨 Live Visualization

I have added an interactive frontend to visualize how the LRU Cache algorithm works step-by-step.
**[Click here to try the Live Visualizer](https://assiiinnn.github.io/C_Project/index.html)**

*(Note: The visualizer is a JavaScript simulation of the C logic for demonstration purposes.)*
```bash
git add README.md
git commit -m "Fix case sensitivity in GitHub Pages link"
git push origin main
```
