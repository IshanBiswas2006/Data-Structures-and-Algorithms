# 🔍 Linear Search

## 📌 What is Linear Search?

Linear Search is the **simplest searching algorithm**. It checks each element of the array **one by one**, from left to right, until it either finds the target element or reaches the end of the array.

> Think of it like looking for a friend in a crowd — you scan each person one by one until you find them.

---

## 🧠 How It Works

```
Array:  [10, 25, 7, 43, 19]
Key:     7

Step 1 → arr[0] = 10 ❌
Step 2 → arr[1] = 25 ❌
Step 3 → arr[2] = 7  ✅ Found! Return index 2
```

---

## 💻 Code — `linear_search.cpp`

```cpp
#include<iostream>
using namespace std;

int Linear_Search(int arr[], int count, int Key)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == Key)
        {
            return i;       // Element found, return index
        }
    }
    return -1;              // Element not found
}

void Input(int arr[], int count)
{
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
}

void Output(int result)
{
    if (result != -1)
        cout << "The element found at index: " << result;
    else
        cout << "The element not found" << endl;
}

int main()
{
    int arr[100];
    int n, key;

    cout << "Enter Size of array: ";
    cin >> n;

    Input(arr, n);

    cout << "Enter Key to find: ";
    cin >> key;

    int result = Linear_Search(arr, n, key);
    Output(result);

    return 0;
}
```

---

## 📊 Complexity Analysis

| Case         | Time Complexity | Explanation                                      |
|--------------|-----------------|--------------------------------------------------|
| **Best Case**  | `O(1)`          | Key found at the first index                     |
| **Average Case** | `O(n/2)` → `O(n)` | Key found somewhere in the middle             |
| **Worst Case** | `O(n)`          | Key is at the last index or not present at all   |
| **Space**      | `O(1)`          | No extra memory used                             |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Linear_Search(arr, count, Key)` | Searches for `Key` in `arr`, returns index or `-1` |
| `Input(arr, count)` | Takes array elements as user input |
| `Output(result)` | Prints whether element was found or not |
| `main()` | Drives the program — takes size, input, key, and shows result |

---

## 🖥️ Sample Run

```
Enter Size of array: 5
Enter Elements:
10 25 7 43 19
Enter Key to find: 43

The element found at index: 3
```

```
Enter Size of array: 4
Enter Elements:
1 2 3 4
Enter Key to find: 9

The element not found
```

---

## ✅ When to Use Linear Search

| ✅ Use When | ❌ Avoid When |
|---|---|
| Array is **unsorted** | Array is large and sorted (use Binary Search) |
| Array is **small** | Performance is critical |
| You need a **simple** solution | Frequent searches on the same data |

---

## 🔁 Compared to Binary Search

| Feature          | Linear Search | Binary Search  |
|------------------|---------------|----------------|
| Array must be sorted? | ❌ No    | ✅ Yes         |
| Time Complexity  | `O(n)`        | `O(log n)`     |
| Implementation   | Simple        | Slightly complex |
| Best for         | Small/unsorted arrays | Large sorted arrays |

---

## 📝 Key Takeaways

- Linear Search works on **any array** — sorted or unsorted.
- It is **not efficient** for large datasets.
- It returns the **index** of the element if found, otherwise `-1`.
- Always a good **starting point** before optimizing with better algorithms.

---

*Part of the [DSA Learning Repository](../README.md) — Arrays Section* 🧠