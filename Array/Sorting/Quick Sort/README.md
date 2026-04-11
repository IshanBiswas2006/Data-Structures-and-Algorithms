# ⚡ Quick Sort

## 📌 What is Quick Sort?

Quick Sort is a highly efficient **divide and conquer** sorting algorithm. It works by selecting a **pivot element** and partitioning the array into two parts — elements smaller than the pivot on the left, and elements greater than the pivot on the right. It then recursively sorts both parts.

> Think of it like organizing people by height — pick one person as the reference, send everyone shorter to the left and everyone taller to the right, then repeat for each group.

---

## 🧠 How It Works

```
Original: [5, 3, 8, 1, 9, 2, 7]
Pivot = arr[start] = 5

── PARTITION ───────────────────────────────────────

Count elements ≤ 5: {3, 1, 2} → count = 3
Pivot final index = start + count = 0 + 3 = 3
Swap pivot to index 3:

[3, 3, 8, 5, 9, 2, 7]  ← pivot (5) placed at index 3

Now move smaller elements left, larger right:
Left of index 3:  [1, 2, 3]   all ≤ 5 ✅
Right of index 3: [7, 8, 9]   all > 5 ✅

Result: [1, 2, 3, | 5 | 7, 8, 9]
                    ↑
               pivot in correct position!

── RECURSE ─────────────────────────────────────────

Quick_Sort([1, 2, 3])   → already sorted ✅
Quick_Sort([7, 8, 9])   → already sorted ✅

Final: [1, 2, 3, 5, 7, 8, 9] ✅
```

---

## 💡 Your Partition Strategy — Count-Based

Your code uses a **clever count-based partition** — different from the classic Lomuto or Hoare methods:

```cpp
// Step 1: Count elements ≤ pivot
int count = 0;
for (int i = start + 1; i <= end; i++) {
    if (arr[i] <= pivot) count++;
}

// Step 2: Place pivot at its correct final index
int pivotindex = start + count;
swap(arr[pivotindex], arr[start]);

// Step 3: Fix left and right sides using two pointers
int i = start, j = end;
while (i < pivotindex && j > pivotindex) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot) j--;
    if (i < pivotindex && j > pivotindex)
        swap(arr[i++], arr[j--]);
}
```

> This approach **directly places the pivot** at its correct position first, then fixes the two sides — a very clean and logical implementation! ✅

---

## 💻 Code — `quick_sort.cpp`

```cpp
#include <iostream>
using namespace std;

void Input(int arr[], int n)
{
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Show(int arr[], int n)
{
    cout << "Before Sorted: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int Partition(int arr[], int start, int end)
{
    int pivot = arr[start];       // Choose first element as pivot
    int count = 0;

    // Count how many elements are <= pivot
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // Place pivot at its correct sorted position
    int pivotindex = start + count;
    swap(arr[pivotindex], arr[start]);

    // Fix left side (should be < pivot) and right side (should be > pivot)
    int i = start, j = end;
    while (i < pivotindex && j > pivotindex)
    {
        while (arr[i] < pivot) { i++; }
        while (arr[j] > pivot) { j--; }

        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotindex;
}

void Quick_Sort(int arr[], int start, int end)
{
    if (start >= end)             // Base case: single element or empty
    {
        return;
    }

    int p = Partition(arr, start, end);   // Partition and get pivot index
    Quick_Sort(arr, start, p - 1);        // Recursively sort left half
    Quick_Sort(arr, p + 1, end);          // Recursively sort right half
}

void Output(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    Quick_Sort(arr, start, end);

    cout << "The Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    int arr[100];
    int n;

    cout << "Enter Size of array: ";
    cin >> n;

    Input(arr, n);
    Show(arr, n);
    Output(arr, n);

    return 0;
}
```

---

## 🔍 Detailed Partition Trace

```
Array: [5, 3, 8, 1, 9, 2, 7], start=0, end=6
pivot = arr[0] = 5

Step 1 — Count elements ≤ 5:
  arr[1]=3 ≤ 5 ✅  count=1
  arr[2]=8 ≤ 5 ❌
  arr[3]=1 ≤ 5 ✅  count=2
  arr[4]=9 ≤ 5 ❌
  arr[5]=2 ≤ 5 ✅  count=3
  arr[6]=7 ≤ 5 ❌
  count = 3

Step 2 — Place pivot at correct index:
  pivotindex = 0 + 3 = 3
  swap(arr[3], arr[0]) → swap(1, 5)
  Array: [1, 3, 8, 5, 9, 2, 7]

Step 3 — Fix left & right with two pointers:
  i=0, j=6

  i scans right:  arr[0]=1 < 5 → i=1
                  arr[1]=3 < 5 → i=2
                  arr[2]=8 — STOP (not < pivot)

  j scans left:   arr[6]=7 > 5 → j=5
                  arr[5]=2 — STOP (not > pivot)

  swap(arr[2], arr[5]) → swap(8, 2)
  Array: [1, 3, 2, 5, 9, 8, 7]
  i=3, j=4 → loop ends (i not < pivotindex)

Pivot 5 is now at index 3 — correct position! ✅
Left:  [1, 3, 2] all < 5 ✅
Right: [9, 8, 7] all > 5 ✅
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                              |
|------------------|-----------------|----------------------------------------------------------|
| **Best Case**    | `O(n log n)`    | Pivot always divides array into two equal halves         |
| **Average Case** | `O(n log n)`    | Random pivot lands near the middle on average            |
| **Worst Case**   | `O(n²)`         | Pivot is always the smallest or largest (already sorted) |
| **Space**        | `O(log n)`      | Recursive call stack — no extra array needed             |

> ⚠️ Worst case happens when array is already sorted and pivot is always `arr[start]`.  
> 💡 Fix: Use **random pivot** or **median-of-three** pivot selection.

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Partition(arr, start, end)` | Counts elements ≤ pivot, places pivot at correct index, fixes sides |
| `Quick_Sort(arr, start, end)` | Recursively sorts left and right of pivot |
| `Input(arr, n)` | Takes array elements as user input |
| `Show(arr, n)` | Displays original unsorted array |
| `Output(arr, n)` | Calls Quick Sort and prints sorted array |
| `main()` | Drives the program — input, show, sort, output |

---

## 🔑 Variable Roles in Partition()

| Variable | Role |
|---|---|
| `pivot` | The reference element — `arr[start]` |
| `count` | Number of elements ≤ pivot (determines pivot's correct index) |
| `pivotindex` | Correct final position of pivot in sorted array |
| `i` | Left pointer — scans for elements ≥ pivot on left side |
| `j` | Right pointer — scans for elements ≤ pivot on right side |

---

## 🖥️ Sample Run

```
Enter Size of array: 6
Enter Elements:
5 3 8 1 9 2

Before Sorted:
5   3   8   1   9   2

The Sorted array:
1   2   3   5   8   9
```

```
Enter Size of array: 5
Enter Elements:
10 7 3 9 1

Before Sorted:
10  7   3   9   1

The Sorted array:
1   3   7   9   10
```

---

## ✅ When to Use Quick Sort

| ✅ Use When | ❌ Avoid When |
|---|---|
| **Large datasets** in memory | Array is already/nearly sorted |
| **Average case** performance matters | Worst case `O(n²)` is unacceptable |
| **In-place** sorting needed | Stable sort is required |
| Cache-friendly performance needed | Guaranteed `O(n log n)` needed (use Merge Sort) |

---

## 📊 Quick Sort vs Merge Sort

| Feature             | Quick Sort        | Merge Sort        |
|---------------------|-------------------|-------------------|
| Time (Best)         | `O(n log n)`      | `O(n log n)`      |
| Time (Average)      | `O(n log n)` ✅   | `O(n log n)` ✅   |
| Time (Worst)        | `O(n²)` ⚠️        | `O(n log n)` ✅   |
| Space               | `O(log n)` ✅     | `O(n)` ⚠️         |
| Stable?             | ❌ No             | ✅ Yes            |
| In-place?           | ✅ Yes            | ❌ No             |
| Strategy            | Divide & Conquer  | Divide & Conquer  |
| Best for            | General purpose   | Linked lists, stable sort |

---

## 📝 Key Takeaways

- Quick Sort uses **divide and conquer** — partition around a pivot, then recurse.
- Your implementation uses a **count-based partition** — counts elements ≤ pivot to find pivot's exact correct index directly.
- The **pivot is placed at its final sorted position** before recursion begins.
- Average case is `O(n log n)` but worst case is `O(n²)` — choose pivot wisely.
- It sorts **in-place** — no extra array like Merge Sort's `temp[]`.
- It uses `O(log n)` stack space for recursion — more memory efficient than Merge Sort.
- One of the **most used sorting algorithms** in real-world applications! 🌍

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Sorting Section* 🧠