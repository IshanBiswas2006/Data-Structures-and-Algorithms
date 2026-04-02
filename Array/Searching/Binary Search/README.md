# 🔎 Binary Search

## 📌 What is Binary Search?

Binary Search is a **fast searching algorithm** that works on **sorted arrays**. Instead of checking every element one by one, it repeatedly **divides the search space in half** — eliminating half the remaining elements with each step.

> Think of it like finding a word in a dictionary — you don't read every page. You open the middle, decide if your word comes before or after, and repeat.

---

## ⚠️ Important Prerequisite

> **The array MUST be sorted before applying Binary Search.**  
> It will give wrong results on unsorted arrays.

---

## 🧠 How It Works

```
Array:  [2, 7, 13, 19, 25, 36, 44]   (sorted)
Key:     25
Indices: 0  1   2   3   4   5   6

Step 1 → start=0, end=6, mid=3 → arr[3]=19 < 25 → move start to mid+1=4
Step 2 → start=4, end=6, mid=5 → arr[5]=36 > 25 → move end to mid-1=4
Step 3 → start=4, end=4, mid=4 → arr[4]=25 == 25 ✅ Found! Return index 4
```

---

## 💻 Code — `binary_search.cpp`

```cpp
#include<iostream>
using namespace std;

void Input(int arr[], int count)
{
    cout << "Enter Elements" << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
}

int Binary_Search(int arr[], int key, int count)
{
    int start = 0;
    int end = count - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;    // Find middle index

        if (arr[mid] == key)
        {
            return mid;                 // Key found, return index
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;            // Key is in RIGHT half
        }
        else
        {
            end = mid - 1;              // Key is in LEFT half
        }
    }
    return -1;                          // Key not found
}

void Output(int arr[], int count, int key)
{
    int result = Binary_Search(arr, key, count);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";
}

int main()
{
    int count, key;
    int arr[100];

    cout << "Enter size of array: ";
    cin >> count;

    Input(arr, count);

    cout << "Enter an element to find: ";
    cin >> key;

    Output(arr, count, key);

    return 0;
}
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                      |
|------------------|-----------------|--------------------------------------------------|
| **Best Case**    | `O(1)`          | Key is at the middle index on first check        |
| **Average Case** | `O(log n)`      | Halves the search space each step                |
| **Worst Case**   | `O(log n)`      | Key at the edge or not present at all            |
| **Space**        | `O(1)`          | No extra memory used — iterative approach        |

> 💡 For 1,000,000 elements — Linear Search needs up to **1,000,000 steps**.  
> Binary Search needs at most **20 steps**. That's the power of `O(log n)`!

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Binary_Search(arr, key, count)` | Searches sorted array using divide & conquer, returns index or `-1` |
| `Input(arr, count)` | Takes array elements as user input |
| `Output(arr, count, key)` | Calls Binary Search and prints the result |
| `main()` | Drives the program — takes size, fills array, key, shows result |

---

## 🔍 Variable Roles in Binary Search

| Variable | Role |
|---|---|
| `start` | Left boundary of current search space |
| `end` | Right boundary of current search space |
| `mid` | Middle index — calculated each iteration |

---

## 🖥️ Sample Run

```
Enter size of array: 6
Enter Elements:
3 9 15 22 37 50
Enter an element to find: 22

Element found at index: 3
```

```
Enter size of array: 5
Enter Elements:
1 4 7 10 13
Enter an element to find: 6

Element not found
```

---

## ✅ When to Use Binary Search

| ✅ Use When | ❌ Avoid When |
|---|---|
| Array is **sorted** | Array is **unsorted** |
| Array is **large** | Array is very small (linear is fine) |
| **Fast search** is needed | Data changes frequently (re-sorting needed) |
| Read-heavy operations | Insertions/deletions are frequent |

---

## ⚔️ Binary Search vs Linear Search

| Feature               | Binary Search  | Linear Search |
|-----------------------|----------------|---------------|
| Array must be sorted? | ✅ Yes         | ❌ No         |
| Time Complexity       | `O(log n)` ⚡  | `O(n)`        |
| Best Case             | `O(1)`         | `O(1)`        |
| Space                 | `O(1)`         | `O(1)`        |
| Works on linked list? | ❌ No          | ✅ Yes        |
| Implementation        | Moderate       | Simple        |

---

## 🧮 How Many Steps Does It Take?

| Array Size (n) | Linear Search (max) | Binary Search (max) |
|----------------|---------------------|---------------------|
| 10             | 10 steps            | 4 steps             |
| 100            | 100 steps           | 7 steps             |
| 1,000          | 1,000 steps         | 10 steps            |
| 1,000,000      | 1,000,000 steps     | 20 steps            |
| 1,000,000,000  | 1,000,000,000 steps | 30 steps            |

---

## 📝 Key Takeaways

- Binary Search works by **halving the search space** each iteration.
- It requires the array to be **sorted** — always.
- It returns the **index** of the element if found, otherwise `-1`.
- It is **significantly faster** than Linear Search for large datasets.
- The `while (start <= end)` condition is critical — it ensures we don't miss the last element.
- `mid = (start + end) / 2` recalculates the middle point each pass.

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Searching Section* 🧠