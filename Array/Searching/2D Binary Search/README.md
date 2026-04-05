# 🔎 Binary Search in 2D Array

## 📌 What is This?

This program applies **Binary Search** on a **2D sorted matrix**. Instead of searching element by element, it treats the entire 2D array as a **flat sorted 1D array** and performs binary search — giving a massive speed boost over 2D Linear Search.

> Think of it like finding a specific page in a sorted encyclopedia — you don't read every page. You open the middle, decide which half your answer is in, and repeat.

---

## ⚠️ Important Prerequisite

> **The 2D array MUST be fully sorted** when read row by row (left to right, top to bottom).  
> Example of a valid sorted matrix:
> ```
> 1   3   5
> 7   9  11
> 13  15  17
> ```
> Last element of each row < First element of next row.

---

## 🧠 How It Works

```
Sorted 2D Array (3×3), col=3:

┌──────────────┐
│  1   3   5   │  ← Row 0  (flat: 0,1,2)
│  7   9  11   │  ← Row 1  (flat: 3,4,5)
│ 13  15  17   │  ← Row 2  (flat: 6,7,8)
└──────────────┘

Key: 9
Total elements = 3×3 = 9, so start=0, end=8

Step 1 → mid=4 → r=4/3=1, c=4%3=1 → arr[1][1]=9 == 9 ✅ Found at (1,1)!
```

---

## 💡 Core Idea — Virtual Flat Array

Your code brilliantly maps the 2D matrix to a **virtual 1D array**:

```cpp
int start = 0;
int end = row * col - 1;       // Treat entire matrix as flat array

int mid = start + (end - start) / 2;
int r = mid / col;             // Convert flat mid → row
int c = mid % col;             // Convert flat mid → col
```

**Why `start + (end - start) / 2` instead of `(start + end) / 2`?**
> Prevents **integer overflow** when `start` and `end` are very large numbers. This is a safer formula. ✅

---

## 💻 Code — `2D_binary_search.cpp`

```cpp
#include <iostream>
using namespace std;

void Input(int arr[][50], int row, int col)
{
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

pair<int, int> Binary_Search(const int arr[][50], int row, int col, int key)
{
    int start = 0;
    int end = row * col - 1;          // Total elements - 1

    while (start <= end)
    {
        int mid = start + (end - start) / 2;   // Safe mid calculation
        int r = mid / col;                      // Row of mid element
        int c = mid % col;                      // Col of mid element

        if (arr[r][c] == key)
        {
            return {r, c};                      // Found — return (row, col) pair
        }
        else if (arr[r][c] < key)
        {
            start = mid + 1;                    // Key is in right half
        }
        else
        {
            end = mid - 1;                      // Key is in left half
        }
    }
    return {-1, -1};                            // Not found
}

void Show(int arr[][50], int row, int col)
{
    cout << "The 2D array is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Output(int arr[][50], int row, int col, int key)
{
    pair<int, int> result = Binary_Search(arr, row, col, key);

    if (result.first != -1)
    {
        cout << "The element found at index: ( " << result.first << " , " << result.second << " )";
    }
    else
    {
        cout << "The element is not found";
    }
}

int main()
{
    int arr[50][50];
    int row, col, key;

    cout << "Enter row and col: ";
    cin >> row >> col;

    // Input validation
    if (row <= 0 || col <= 0 || row > 50 || col > 50)
    {
        cout << "Invalid matrix size!" << endl;
        return 0;
    }

    Input(arr, row, col);
    Show(arr, row, col);

    cout << "Enter the element to search: ";
    cin >> key;

    Output(arr, row, col, key);
    return 0;
}
```

---

## 🔍 Step-by-Step Trace

```
Matrix (3×3), col=3:         Flat view:
 1   3   5                   [1, 3, 5, 7, 9, 11, 13, 15, 17]
 7   9  11                    0  1  2  3  4   5   6   7   8
13  15  17

Key = 15
start=0, end=8

Step 1: mid = 0+(8-0)/2 = 4
        r=4/3=1, c=4%3=1 → arr[1][1]=9 < 15 → start=5

Step 2: mid = 5+(8-5)/2 = 6
        r=6/3=2, c=6%3=0 → arr[2][0]=13 < 15 → start=7

Step 3: mid = 7+(8-7)/2 = 7
        r=7/3=2, c=7%3=1 → arr[2][1]=15 == 15 ✅ Return (2,1)
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity      | Explanation                                      |
|------------------|----------------------|--------------------------------------------------|
| **Best Case**    | `O(1)`               | Key is at the middle element on first check      |
| **Average Case** | `O(log(n × m))`      | Halves the search space each step                |
| **Worst Case**   | `O(log(n × m))`      | Key at edge or not present                       |
| **Space**        | `O(1)`               | No extra memory used                             |

> For a 1000×1000 matrix (1,000,000 elements):  
> 2D Linear Search → up to **1,000,000 steps**  
> 2D Binary Search → at most **20 steps** 🚀

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Binary_Search(arr, row, col, key)` | Searches sorted matrix using flat index mapping, returns `pair<int,int>` |
| `Input(arr, row, col)` | Fills the 2D array with user input |
| `Show(arr, row, col)` | Displays the matrix in proper grid format |
| `Output(arr, row, col, key)` | Calls search and prints `(row, col)` result |
| `main()` | Drives program — validates input, fills, shows, searches |

---

## ⭐ Special Features in Your Code

### 1. `pair<int, int>` return type
```cpp
pair<int, int> Binary_Search(...) {
    return {r, c};      // Returns both row and col together
    return {-1, -1};    // Clean way to signal not found
}
```
> Much cleaner than using global variables or output parameters! ✅

### 2. Input Validation
```cpp
if (row <= 0 || col <= 0 || row > 50 || col > 50) {
    cout << "Invalid matrix size!" << endl;
    return 0;
}
```
> Prevents crashes from invalid input — good defensive programming! ✅

### 3. Overflow-safe mid calculation
```cpp
int mid = start + (end - start) / 2;   // ✅ Safe
// vs
int mid = (start + end) / 2;           // ⚠️ Can overflow for large arrays
```

---

## 🖥️ Sample Run

```
Enter row and col: 3 3
Enter the elements:
1 3 5
7 9 11
13 15 17

The 2D array is:
1 3 5
7 9 11
13 15 17

Enter the element to search: 15

The element found at index: ( 2 , 1 )
```

```
Enter row and col: 2 3
Enter the elements:
2 4 6
8 10 12

The 2D array is:
2 4 6
8 10 12

Enter the element to search: 7

The element is not found
```

---

## 🆚 2D Linear Search vs 2D Binary Search

| Feature             | 2D Linear Search   | 2D Binary Search      |
|---------------------|--------------------|-----------------------|
| Array must be sorted?| ❌ No             | ✅ Yes                |
| Time Complexity     | `O(n × m)`         | `O(log(n × m))`       |
| Return type         | flat index         | `pair<int,int>`       |
| Best for            | Unsorted matrices  | Sorted matrices       |
| Overflow safe mid?  | N/A                | ✅ Yes                |
| Input validation?   | ❌ No              | ✅ Yes                |

---

## 📝 Key Takeaways

- 2D Binary Search treats the matrix as a **virtual flat sorted array** using `mid / col` and `mid % col`.
- It requires the matrix to be **fully sorted** row by row.
- Returns a `pair<int, int>` — a clean and modern C++ way to return two values.
- Uses **overflow-safe** mid calculation — `start + (end - start) / 2`.
- Has **input validation** — more robust than basic implementations.
- Time complexity is `O(log(n × m))` — dramatically faster than linear search on large matrices.

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Searching Section* 🧠