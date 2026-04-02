# 🔃 Selection Sort

## 📌 What is Selection Sort?

Selection Sort is a simple comparison-based sorting algorithm. It divides the array into two parts — a **sorted portion** (left) and an **unsorted portion** (right). In each pass, it **selects the minimum element** from the unsorted portion and places it at the correct position in the sorted portion.

> Think of it like organizing playing cards — you scan all cards, pick the smallest one, and place it first. Then repeat for the rest.

---

## 🧠 How It Works

```
Array:  [64, 25, 12, 22, 11]

Pass 1 → Min = 11 (index 4) → Swap with index 0 → [11, 25, 12, 22, 64]
Pass 2 → Min = 12 (index 2) → Swap with index 1 → [11, 12, 25, 22, 64]
Pass 3 → Min = 22 (index 3) → Swap with index 2 → [11, 12, 22, 25, 64]
Pass 4 → Min = 25 (index 3) → No swap needed   → [11, 12, 22, 25, 64]

✅ Sorted!
```

---

## 💻 Code — `selection_sort.cpp`

```cpp
#include <iostream>
using namespace std;

void Input(int n, int arr[])
{
    cout << "Enter numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Output(int arr[], int n)
{
    cout << "The Sorted array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int Selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minindex = i;                   // Assume current index is minimum

        for (int j = i + 1; j < n; j++)    // Scan remaining unsorted part
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;               // Update index of new minimum
            }
        }

        // Swap minimum element with first unsorted element
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
    return 1;
}

int main()
{
    int arr[100];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    Input(n, arr);

    int result = Selection_Sort(arr, n);

    if (result == 1)
    {
        cout << "Sorted array:\n";
        Output(arr, n);
    }

    return 0;
}
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                          |
|------------------|-----------------|------------------------------------------------------|
| **Best Case**    | `O(n²)`         | Still scans entire unsorted portion every pass       |
| **Average Case** | `O(n²)`         | Two nested loops always run regardless of input      |
| **Worst Case**   | `O(n²)`         | Same — no early exit possible                        |
| **Space**        | `O(1)`          | In-place sorting, no extra array needed              |

> ⚠️ Selection Sort always runs in `O(n²)` — it **does not** improve even if the array is already sorted.

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Selection_Sort(arr, n)` | Finds minimum in each pass and swaps it into position |
| `Input(n, arr)` | Takes `n` elements as user input into the array |
| `Output(arr, n)` | Prints the sorted array |
| `main()` | Drives the program — takes size, fills array, sorts, prints |

---

## 🔍 Step-by-Step Trace (Your Code Logic)

```
Outer loop (i): tracks the boundary of the sorted portion
Inner loop (j): scans from i+1 to end to find the minimum

i=0: minindex=0, scan j=1..4 → find min → swap → sorted[0] fixed
i=1: minindex=1, scan j=2..4 → find min → swap → sorted[1] fixed
i=2: minindex=2, scan j=3..4 → find min → swap → sorted[2] fixed
i=3: minindex=3, scan j=4   → find min → swap → sorted[3] fixed
Done! (last element automatically in place)
```

---

## 🖥️ Sample Run

```
Enter size of array: 5
Enter numbers:
64 25 12 22 11

Sorted array:
11 12 22 25 64
```

```
Enter size of array: 4
Enter numbers:
5 3 8 1

Sorted array:
1 3 5 8
```

---

## ✅ When to Use Selection Sort

| ✅ Use When | ❌ Avoid When |
|---|---|
| Array is **small** | Large datasets |
| **Memory is limited** (only 1 swap per pass) | Performance matters |
| Learning / understanding sorting basics | Need a stable sort |
| Minimizing the **number of swaps** matters | Better alternatives available (`std::sort`) |

> 💡 Selection Sort makes at most **O(n) swaps** — making it useful when write operations are costly.

---

## 📊 Comparison with Other Sorts

| Feature             | Selection Sort | Bubble Sort | Insertion Sort |
|---------------------|----------------|-------------|----------------|
| Time (Worst)        | `O(n²)`        | `O(n²)`     | `O(n²)`        |
| Time (Best)         | `O(n²)`        | `O(n)`      | `O(n)`         |
| Swaps               | `O(n)` ✅ min  | `O(n²)`     | `O(n²)`        |
| Stable?             | ❌ No          | ✅ Yes      | ✅ Yes         |
| In-place?           | ✅ Yes         | ✅ Yes      | ✅ Yes         |

---

## 📝 Key Takeaways

- Selection Sort finds the **minimum element** in each pass and places it at the front.
- It always performs **`O(n²)` comparisons** — no optimization for already sorted arrays.
- It makes **fewer swaps** than Bubble Sort, which can be an advantage.
- It is **not stable** — equal elements may change their relative order.
- Great for **learning** sorting fundamentals before tackling Merge Sort or Quick Sort.

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Sorting Section* 🧠
