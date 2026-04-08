# 🔀 Merge Sort

## 📌 What is Merge Sort?

Merge Sort is a **divide and conquer** sorting algorithm. It recursively splits the array into two halves, sorts each half, and then **merges** them back together in sorted order.

> Think of it like sorting a deck of cards by splitting it into two piles, sorting each pile separately, then carefully merging both piles into one sorted deck.

---

## 🧠 How It Works

```
Original: [38, 27, 43, 3, 9, 82, 10]

── DIVIDE ──────────────────────────────────────────

         [38, 27, 43, 3, 9, 82, 10]
                /            \
        [38, 27, 43]       [3, 9, 82, 10]
           /     \            /        \
       [38, 27]  [43]      [3, 9]    [82, 10]
        /    \              /   \      /    \
      [38]  [27]          [3]  [9]  [82]  [10]

── MERGE ───────────────────────────────────────────

      [38]  [27]          [3]  [9]  [82]  [10]
        \    /              \   /      \    /
       [27, 38]  [43]      [3, 9]    [10, 82]
           \       /          \        /
        [27, 38, 43]         [3, 9, 10, 82]
                \                /
          [3, 9, 10, 27, 38, 43, 82] ✅
```

---

## 💡 Core Idea — Divide & Conquer

```
DIVIDE  → Split array in half recursively until single elements remain
CONQUER → Single elements are trivially sorted
MERGE   → Combine two sorted halves into one sorted array
```

> A single element is always sorted — this is the **base case** of the recursion.

---

## 💻 Code — `merge_sort.cpp`

```cpp
#include <iostream>
using namespace std;

void Input(int arr[], int n)
{
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Show(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Merge(int arr[], int low, int mid, int high)
{
    int i = low;         // Pointer for left half
    int j = mid + 1;     // Pointer for right half
    int k = low;         // Pointer for temp array

    int temp[100];

    // Compare elements from both halves and pick smaller
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right half
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy sorted temp back into original array
    for (int p = low; p <= high; p++)
    {
        arr[p] = temp[p];
    }
}

void MergeSort(int arr[], int low, int high)
{
    if (low < high)                        // Base case: single element
    {
        int mid = (low + high) / 2;        // Find middle

        MergeSort(arr, low, mid);          // Sort left half
        MergeSort(arr, mid + 1, high);     // Sort right half

        Merge(arr, low, mid, high);        // Merge both sorted halves
    }
}

void Output(int arr[], int n)
{
    cout << "Sorted Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    Input(arr, n);

    cout << "Original Array:\n";
    Show(arr, n);

    MergeSort(arr, 0, n - 1);

    Output(arr, n);

    return 0;
}
```

---

## 🔍 Step-by-Step Merge Trace

```
Merging [27, 38] and [43]:

i=low=0 → arr[0]=27
j=mid+1=2 → arr[2]=43
temp array starts empty

Step 1: arr[i]=27 < arr[j]=43 → temp[0]=27, i++
Step 2: arr[i]=38 < arr[j]=43 → temp[1]=38, i++
Step 3: i > mid → left half exhausted
        copy remaining right: temp[2]=43

Result: temp = [27, 38, 43] → copied back to arr ✅
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                          |
|------------------|-----------------|------------------------------------------------------|
| **Best Case**    | `O(n log n)`    | Always divides and merges — no early exit            |
| **Average Case** | `O(n log n)`    | Consistent performance regardless of input           |
| **Worst Case**   | `O(n log n)`    | Same — always divides evenly and merges              |
| **Space**        | `O(n)`          | Extra `temp[]` array used during merging             |

> **Why O(n log n)?**
> - Dividing: `log n` levels of recursion
> - Merging: `O(n)` work at each level
> - Total: `n × log n`

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `MergeSort(arr, low, high)` | Recursively divides array into halves |
| `Merge(arr, low, mid, high)` | Merges two sorted halves into one sorted segment |
| `Input(arr, n)` | Takes array elements as user input |
| `Show(arr, n)` | Displays the array |
| `Output(arr, n)` | Prints the final sorted array |
| `main()` | Drives the program — input, show original, sort, show result |

---

## 🔑 Variable Roles in Merge()

| Variable | Role |
|---|---|
| `i` | Pointer scanning the **left** half (`low` to `mid`) |
| `j` | Pointer scanning the **right** half (`mid+1` to `high`) |
| `k` | Pointer writing into `temp[]` |
| `temp[]` | Temporary array to hold merged result before copying back |

---

## 🖥️ Sample Run

```
Enter size: 6
Enter elements:
38 27 43 3 9 82

Original Array:
38 27 43 3 9 82

Sorted Array:
3 9 27 38 43 82
```

```
Enter size: 4
Enter elements:
5 1 4 2

Original Array:
5 1 4 2

Sorted Array:
1 2 4 5
```

---

## ✅ When to Use Merge Sort

| ✅ Use When | ❌ Avoid When |
|---|---|
| **Large datasets** | Memory is very limited (`O(n)` space) |
| **Guaranteed** `O(n log n)` needed | Small arrays (Insertion Sort is faster) |
| Sorting **linked lists** | In-place sorting required |
| **Stable sort** needed | Simple use cases |

---

## 📊 Comparison With All Sorting Algorithms

| Feature             | Merge Sort     | Quick Sort     | Bubble Sort | Insertion Sort | Selection Sort |
|---------------------|----------------|----------------|-------------|----------------|----------------|
| Time (Best)         | `O(n log n)`   | `O(n log n)`   | `O(n)`      | `O(n)`         | `O(n²)`        |
| Time (Average)      | `O(n log n)` ✅| `O(n log n)` ✅| `O(n²)`     | `O(n²)`        | `O(n²)`        |
| Time (Worst)        | `O(n log n)` ✅| `O(n²)`        | `O(n²)`     | `O(n²)`        | `O(n²)`        |
| Space               | `O(n)`         | `O(log n)`     | `O(1)`      | `O(1)`         | `O(1)`         |
| Stable?             | ✅ Yes         | ❌ No          | ✅ Yes      | ✅ Yes         | ❌ No          |
| Strategy            | Divide & Conquer | Divide & Conquer | Comparison | Comparison  | Comparison     |

---

## 🌟 Why Merge Sort is Special

```
✅ Always O(n log n) — no worst case degradation like Quick Sort
✅ Stable sort — equal elements maintain original order
✅ Best choice for sorting Linked Lists
✅ Used in external sorting (sorting data too large for RAM)
✅ Foundation of real-world sorts like Timsort (Python, Java)
```

---

## 📝 Key Takeaways

- Merge Sort uses **divide and conquer** — split, sort, merge.
- It always runs in `O(n log n)` — **consistent and predictable**.
- It requires `O(n)` extra space for the `temp[]` array — trade-off for speed.
- It is a **stable sort** — equal elements keep their relative order.
- The **base case** is `low >= high` — a single element needs no sorting.
- This is your first **recursive sorting algorithm** — a major milestone! 🎉

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Sorting Section* 🧠