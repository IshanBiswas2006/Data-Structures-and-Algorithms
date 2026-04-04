# 🔍 Linear Search in 2D Array

## 📌 What is This?

This program extends the classic **Linear Search** algorithm to work on a **2D array (matrix)**. It searches through every element row by row, and when the key is found, it returns the **row and column index** of that element.

> Think of it like searching for a specific seat in a cinema hall — you check row by row, seat by seat, until you find it.

---

## 🧠 How It Works

```
2D Array (3x3):
┌────────────────┐
│  1   5   9     │  ← Row 0
│  3   7   2     │  ← Row 1
│  8   4   6     │  ← Row 2
└────────────────┘

Key: 7

Step 1 → Row 0: check 1, 5, 9     → ❌ not found
Step 2 → Row 1: check 3, 7        → ✅ found at (1, 1)
```

---

## 💡 Key Concept — Flat Index to 2D Index

Your code uses a clever trick — it stores the result as a **single flat index** and converts it back to `(row, col)`:

```cpp
// When found:
return i * col + j;      // Convert 2D position → flat index

// In Output:
int r = result / col;    // Recover row
int c = result % col;    // Recover column
```

**Example with col = 3:**
```
Position (1, 1) → flat index = 1*3 + 1 = 4
Recover row     → 4 / 3 = 1  ✅
Recover col     → 4 % 3 = 1  ✅
```

---

## 💻 Code — `2D_linear_search.cpp`

```cpp
#include <iostream>
using namespace std;

void Input(int arr[][50], int col, int row)
{
    cout << "Enter elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void Show(int arr[][50], int row, int col)
{
    cout << "The 2D array:" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;          // New line after each row
    }
}

int Linear_Search(int arr[][50], int key, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == key)
            {
                return i * col + j;    // Return flat index
            }
        }
    }
    return -1;                         // Key not found
}

void Output(int arr[][50], int col, int row, int key)
{
    int result = Linear_Search(arr, key, col, row);

    if (result != -1)
    {
        int r = result / col;          // Recover row from flat index
        int c = result % col;          // Recover col from flat index
        cout << "The element is at index: (" << r << " , " << c << ")";
    }
    else
    {
        cout << "Element not found";
    }
}

int main()
{
    int arr[50][50];
    int c, r, key;

    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Input(arr, c, r);
    Show(arr, r, c);

    cout << "Enter the element to search: ";
    cin >> key;

    Output(arr, c, r, key);

    return 0;
}
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                          |
|------------------|-----------------|------------------------------------------------------|
| **Best Case**    | `O(1)`          | Key found at first element `arr[0][0]`               |
| **Average Case** | `O(n*m / 2)` → `O(n*m)` | Key found somewhere in the middle          |
| **Worst Case**   | `O(n * m)`      | Key at last position or not present at all           |
| **Space**        | `O(1)`          | No extra memory used                                 |

> Where `n` = number of rows, `m` = number of columns.  
> Total elements = `n × m` — all may be visited in the worst case.

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Input(arr, col, row)` | Fills the 2D array with user input row by row |
| `Show(arr, row, col)` | Displays the 2D array in matrix format |
| `Linear_Search(arr, key, col, row)` | Searches for key, returns flat index or `-1` |
| `Output(arr, col, row, key)` | Calls search, converts flat index to `(row, col)` and prints |
| `main()` | Drives the program — takes dimensions, fills, shows, searches |

---

## 🔍 Flat Index Conversion — Visualized

```
2D Array with col=3:

Index:   0   1   2   3   4   5   6   7   8
         ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓
       [ 1,  5,  9,  3,  7,  2,  8,  4,  6 ]  ← flat view

2D view:
  (0,0)(0,1)(0,2)    row 0 → indices 0, 1, 2
  (1,0)(1,1)(1,2)    row 1 → indices 3, 4, 5
  (2,0)(2,1)(2,2)    row 2 → indices 6, 7, 8

Formula:
  flat index = row * col + col_position
  row        = flat index / col
  col        = flat index % col
```

---

## 🖥️ Sample Run

```
Enter rows and columns: 3 3
Enter elements:
1 5 9
3 7 2
8 4 6

The 2D array:
1 5 9
3 7 2
8 4 6

Enter the element to search: 7

The element is at index: (1 , 1)
```

```
Enter rows and columns: 2 3
Enter elements:
10 20 30
40 50 60

The 2D array:
10 20 30
40 50 60

Enter the element to search: 99

Element not found
```

---

## 🆚 1D Linear Search vs 2D Linear Search

| Feature             | 1D Linear Search  | 2D Linear Search     |
|---------------------|-------------------|----------------------|
| Input               | Single array      | Matrix (rows × cols) |
| Loops               | 1 loop            | 2 nested loops       |
| Result              | Index `i`         | Index `(row, col)`   |
| Time Complexity     | `O(n)`            | `O(n × m)`           |
| Space               | `O(1)`            | `O(1)`               |

---

## 📝 Key Takeaways

- 2D Linear Search uses **two nested loops** — one for rows, one for columns.
- The **flat index trick** (`i * col + j`) is a clean way to return a single value and recover `(row, col)` from it.
- Time complexity is `O(n * m)` — every element may be visited.
- Works on **any 2D array** — sorted or unsorted.
- A natural progression from 1D Linear Search — same idea, extended to matrices.

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Searching Section* 🧠