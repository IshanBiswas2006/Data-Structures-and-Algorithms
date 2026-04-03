# 🫧 Bubble Sort

## 📌 What is Bubble Sort?

Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly **compares adjacent elements** and swaps them if they are in the wrong order. After each pass, the **largest unsorted element "bubbles up"** to its correct position at the end.

> Think of it like bubbles rising in water — the heaviest bubbles sink, the lightest rise to the top, one pass at a time.

---

## 🧠 How It Works

```
Array:  [5, 3, 8, 1, 2]

Pass 1 → [3, 5, 1, 2, 8]   ← 8 bubbled to the end
Pass 2 → [3, 1, 2, 5, 8]   ← 5 bubbled to its place
Pass 3 → [1, 2, 3, 5, 8]   ← 3 bubbled to its place
Pass 4 → [1, 2, 3, 5, 8]   ← no swaps → early exit ✅

✅ Sorted!
```

---

## 💻 Code — `bubble_sort.cpp`

```cpp
#include <iostream>
using namespace std;

void Input(int arr[], int count)
{
    cout << "Enter elements: " << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
}

int Bubble_Sort(int arr[], int count)
{
    int i, j;
    int swaps = 0;
    bool swapped;

    for (i = 0; i < count - 1; i++)
    {
        swapped = false;                        // Reset flag each pass

        for (j = 0; j < count - i - 1; j++)    // Last i elements already sorted
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);       // Swap adjacent elements
                swaps++;
                swapped = true;
            }
        }

        if (!swapped) break;                    // No swaps = already sorted, exit early
    }
    return swaps;                               // Returns total number of swaps made
}

void Output(int arr[], int count)
{
    int result = Bubble_Sort(arr, count);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter size of array: ";
    cin >> n;

    Input(arr, n);
    Output(arr, n);

    return 0;
}
```

---

## ⭐ Key Optimization — Early Exit

Your implementation uses a `swapped` flag — this is the **optimized version** of Bubble Sort!

```cpp
bool swapped;
// ...
if (!swapped) break;   // If no swaps happened, array is already sorted!
```

> Without this flag — Bubble Sort always runs `O(n²)` even on a sorted array.  
> **With this flag** — if the array is already sorted, it exits after just **1 pass** → `O(n)` best case! ✅

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                        |
|------------------|-----------------|----------------------------------------------------|
| **Best Case**    | `O(n)`          | Array already sorted — `swapped` flag exits early  |
| **Average Case** | `O(n²)`         | Random order — two nested loops run fully          |
| **Worst Case**   | `O(n²)`         | Array sorted in reverse — maximum swaps needed     |
| **Space**        | `O(1)`          | In-place sorting — no extra array needed           |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Bubble_Sort(arr, count)` | Sorts array using adjacent swaps, returns total swap count |
| `Input(arr, count)` | Takes array elements as user input |
| `Output(arr, count)` | Calls Bubble Sort and prints the sorted array |
| `main()` | Drives the program — takes size, fills array, sorts and prints |

---

## 🔍 Step-by-Step Trace (Your Code Logic)

```
Outer loop (i): tracks how many elements are sorted at the end
Inner loop (j): compares adjacent pairs from index 0 to count-i-2

i=0: compare all pairs → largest element reaches end
i=1: compare up to second-last → second largest settles
i=2: compare up to third-last → and so on...
swapped=false at any pass → BREAK early ✅
```

---

## 🖥️ Sample Run

```
Enter size of array: 5
Enter elements:
5 3 8 1 2

Sorted array:
1 2 3 5 8
```

```
Enter size of array: 4
Enter elements:
1 2 3 4

Sorted array:
1 2 3 4
```
> ☝️ Second example exits after 1 pass because `swapped` stays `false` — early exit working! ✅

---

## ✅ When to Use Bubble Sort

| ✅ Use When | ❌ Avoid When |
|---|---|
| Array is **small** | Large datasets |
| Array is **nearly sorted** | Performance is critical |
| Learning sorting fundamentals | Production code |
| Counting swaps matters | Better alternatives available |

---

## 📊 Comparison With Other Sorts

| Feature             | Bubble Sort    | Selection Sort | Insertion Sort |
|---------------------|----------------|----------------|----------------|
| Time (Best)         | `O(n)` ✅      | `O(n²)`        | `O(n)`  ✅     |
| Time (Worst)        | `O(n²)`        | `O(n²)`        | `O(n²)`        |
| Swaps               | `O(n²)`        | `O(n)` ✅      | `O(n²)`        |
| Stable?             | ✅ Yes         | ❌ No          | ✅ Yes         |
| Early Exit?         | ✅ Yes         | ❌ No          | ✅ Yes         |
| In-place?           | ✅ Yes         | ✅ Yes         | ✅ Yes         |

---

## 📝 Key Takeaways

- Bubble Sort **compares adjacent elements** and swaps them if out of order.
- After every pass, the **largest remaining element settles** at the end.
- The `swapped` flag in your code makes it **optimized** — best case becomes `O(n)`.
- It is a **stable sort** — equal elements maintain their original relative order.
- Returns the **total number of swaps** made — useful for analysis.
- Great for **learning** but rarely used in real-world applications.

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Sorting Section* 🧠