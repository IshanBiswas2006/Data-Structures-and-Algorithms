# 🃏 Insertion Sort

## 📌 What is Insertion Sort?

Insertion Sort builds the sorted array **one element at a time** by picking each element and **inserting it into its correct position** among the already sorted elements to its left.

> Think of it like sorting playing cards in your hand — you pick one card at a time and slide it into the right spot among the cards you're already holding.

---

## 🧠 How It Works

```
Array:  [5, 3, 8, 1, 2]

Pass 1 → key=3  → [3, 5, 8, 1, 2]   ← 3 inserted before 5
Pass 2 → key=8  → [3, 5, 8, 1, 2]   ← 8 already in place
Pass 3 → key=1  → [1, 3, 5, 8, 2]   ← 1 inserted at the front
Pass 4 → key=2  → [1, 2, 3, 5, 8]   ← 2 inserted between 1 and 3

✅ Sorted!
```

---

## 💻 Code — `insertion_sort.cpp`

```cpp
#include<iostream>
using namespace std;

void Input(int arr[], int count)
{
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
}

int Insertion_Sort(int arr[], int count)
{
    for (int i = 1; i < count; i++)
    {
        int key = arr[i];       // Element to be inserted into sorted portion
        int j = i - 1;

        // Shift elements greater than key one position to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;       // Place key in its correct position
    }
    return 0;
}

void Output(int arr[], int count)
{
    Insertion_Sort(arr, count);

    cout << "Sorted array is: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[100];
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    Input(arr, n);
    Output(arr, n);

    return 0;
}
```

---

## 🔍 Step-by-Step Trace (Your Code Logic)

```
Array: [5, 3, 8, 1, 2]

i=1, key=3, j=0
  arr[0]=5 > 3 → shift → [5, 5, 8, 1, 2], j=-1
  place key → arr[0]=3 → [3, 5, 8, 1, 2]

i=2, key=8, j=1
  arr[1]=5 < 8 → stop immediately
  place key → arr[2]=8 → [3, 5, 8, 1, 2]

i=3, key=1, j=2
  arr[2]=8 > 1 → shift, arr[1]=5 > 1 → shift, arr[0]=3 > 1 → shift
  j=-1 → place key → arr[0]=1 → [1, 3, 5, 8, 2]

i=4, key=2, j=3
  arr[3]=8 > 2 → shift, arr[2]=5 > 2 → shift, arr[1]=3 > 2 → shift
  arr[0]=1 < 2 → stop
  place key → arr[1]=2 → [1, 2, 3, 5, 8] ✅
```

---

## 📊 Complexity Analysis

| Case             | Time Complexity | Explanation                                         |
|------------------|-----------------|-----------------------------------------------------|
| **Best Case**    | `O(n)`          | Array already sorted — inner while loop never runs  |
| **Average Case** | `O(n²)`         | Random order — shifting happens on average          |
| **Worst Case**   | `O(n²)`         | Reverse sorted — maximum shifting every pass        |
| **Space**        | `O(1)`          | In-place sorting — no extra array needed            |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Insertion_Sort(arr, count)` | Picks each element and inserts it into correct position in sorted left portion |
| `Input(arr, count)` | Takes array elements as user input |
| `Output(arr, count)` | Calls Insertion Sort and prints the sorted array |
| `main()` | Drives the program — takes size, fills array, sorts and prints |

---

## 🔑 Variable Roles

| Variable | Role |
|---|---|
| `i` | Current index — separates sorted (left) and unsorted (right) portions |
| `key` | The element being inserted into its correct position |
| `j` | Scans backwards through sorted portion to find where `key` belongs |

---

## 🖥️ Sample Run

```
Enter size of array: 5
Enter Elements:
5 3 8 1 2

Sorted array is:
1 2 3 5 8
```

```
Enter size of array: 4
Enter Elements:
1 2 3 4

Sorted array is:
1 2 3 4
```
> ☝️ Second example finishes instantly — array already sorted, while loop never triggers → `O(n)` best case! ✅

---

## ✅ When to Use Insertion Sort

| ✅ Use When | ❌ Avoid When |
|---|---|
| Array is **small** | Large datasets |
| Array is **nearly sorted** | Performance is critical |
| **Online sorting** (elements arrive one by one) | Many elements need sorting |
| Need a **stable** sort | Better alternatives available |

> 💡 Insertion Sort is used inside **Timsort** — Python's and Java's built-in sort — for small subarrays because it's blazing fast on nearly sorted data!

---

## 📊 Comparison With Other Sorts

| Feature             | Insertion Sort | Bubble Sort    | Selection Sort |
|---------------------|----------------|----------------|----------------|
| Time (Best)         | `O(n)` ✅      | `O(n)` ✅      | `O(n²)`        |
| Time (Worst)        | `O(n²)`        | `O(n²)`        | `O(n²)`        |
| Stable?             | ✅ Yes         | ✅ Yes         | ❌ No          |
| Early Exit?         | ✅ Yes         | ✅ Yes         | ❌ No          |
| Best for            | Nearly sorted  | Nearly sorted  | Min writes     |
| In-place?           | ✅ Yes         | ✅ Yes         | ✅ Yes         |

---

## 📝 Key Takeaways

- Insertion Sort works like **sorting cards in hand** — pick one, slide it left until it fits.
- It maintains a **sorted left portion** and grows it one element at a time.
- Best case is `O(n)` — if array is already sorted, the while loop never executes.
- It is a **stable sort** — equal elements keep their original relative order.
- Used in real-world hybrid sorts like **Timsort** for small arrays.
- The `key` variable is critical — it holds the element being placed while shifting happens.

---

*Part of the [DSA Learning Repository](../../README.md) — Arrays → Sorting Section* 🧠