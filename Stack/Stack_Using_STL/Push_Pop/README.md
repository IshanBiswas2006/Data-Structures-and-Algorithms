# 📚 Stack — Using STL

## 📌 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO** principle — **Last In, First Out**. The last element inserted is the first one to be removed — just like a stack of plates.

```
        ┌──────┐
        │  50  │  ← TOP (last inserted, first removed)
        ├──────┤
        │  40  │
        ├──────┤
        │  30  │
        ├──────┤
        │  20  │
        ├──────┤
        │  10  │  ← BOTTOM (first inserted, last removed)
        └──────┘
```

> Think of it like a stack of plates — you can only add or remove from the **top**. You can't pull a plate from the middle!

---

## 🧠 LIFO — Last In First Out

```
PUSH order:  10 → 20 → 30 → 40 → 50
POP order:   50 → 40 → 30 → 20 → 10

Last pushed (50) is always popped first! ✅
```

---

## 💡 What is STL Stack?

C++ **STL (Standard Template Library)** provides a ready-to-use `stack` container so you don't need to implement it from scratch.

```cpp
#include <stack>        // Include the stack header
stack<int> s;           // Declare a stack of integers
```

> The STL stack is implemented internally using a **deque** by default — but you use it through a simple, clean interface.

---

## 💻 Code — `stack_stl.cpp`

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;         // Create an empty stack of integers

    // Push elements onto the stack
    s.push(10);           // Stack: [10]
    s.push(20);           // Stack: [10, 20]
    s.push(30);           // Stack: [10, 20, 30]
    s.push(40);           // Stack: [10, 20, 30, 40]
    s.push(50);           // Stack: [10, 20, 30, 40, 50] ← top

    s.pop();              // Removes 50 (top element)
                          // Stack: [10, 20, 30, 40] ← top is now 40

    cout << "Displaying top element: " << s.top() << endl;

    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
s.push(10):  Stack →  [10]            top = 10
s.push(20):  Stack →  [10|20]         top = 20
s.push(30):  Stack →  [10|20|30]      top = 30
s.push(40):  Stack →  [10|20|30|40]   top = 40
s.push(50):  Stack →  [10|20|30|40|50] top = 50

s.pop():     Removes 50
             Stack →  [10|20|30|40]   top = 40

s.top():     Returns 40 (doesn't remove) → prints 40

s.empty():   Stack has 4 elements → false → "Stack is not empty"
```

---

## 📋 STL Stack Operations

| Operation     | Syntax          | Description                                | Time     |
|---------------|-----------------|--------------------------------------------|----------|
| **Push**      | `s.push(val)`   | Insert element on top of stack             | `O(1)`   |
| **Pop**       | `s.pop()`       | Remove top element (does NOT return it)    | `O(1)`   |
| **Top**       | `s.top()`       | Access top element (does NOT remove it)    | `O(1)`   |
| **Empty**     | `s.empty()`     | Returns `true` if stack is empty           | `O(1)`   |
| **Size**      | `s.size()`      | Returns number of elements in stack        | `O(1)`   |

> ⚠️ `pop()` does NOT return the value — it only removes. Use `top()` first to read the value, then `pop()` to remove it.

---

## ⭐ Important — `pop()` vs `top()`

```cpp
// WRONG — pop() returns void, not the value!
int val = s.pop();     // ❌ compile error

// CORRECT — read first, then remove
int val = s.top();     // ✅ get the value
s.pop();               // ✅ then remove it
```

---

## 📊 Complexity Analysis

| Operation   | Time Complexity | Space Complexity |
|-------------|-----------------|------------------|
| `push()`    | `O(1)`          | `O(1)`           |
| `pop()`     | `O(1)`          | `O(1)`           |
| `top()`     | `O(1)`          | `O(1)`           |
| `empty()`   | `O(1)`          | `O(1)`           |
| `size()`    | `O(1)`          | `O(1)`           |
| **Overall** | `O(n)` for n ops| `O(n)` for n elements |

---

## 🖥️ Sample Output

```
Displaying top element: 40
Stack is not empty
```

---

## 🌍 Real-World Applications of Stack

| Application              | How Stack is Used                                  |
|--------------------------|----------------------------------------------------|
| **Undo/Redo**            | Each action pushed — undo pops last action         |
| **Browser Back Button**  | Each page pushed — back button pops to previous    |
| **Function Call Stack**  | Each function call pushed — return pops it         |
| **Expression Evaluation**| Operators and operands pushed/popped               |
| **Balanced Parentheses** | Opening brackets pushed, popped on closing match   |
| **DFS (Graph/Tree)**     | Nodes pushed for depth-first exploration           |

---

## 🆚 Stack vs Queue

| Feature         | Stack               | Queue               |
|-----------------|---------------------|---------------------|
| Principle       | **LIFO** (Last In First Out) | **FIFO** (First In First Out) |
| Insert at       | Top                 | Back (rear)         |
| Remove from     | Top                 | Front               |
| Real-world      | Undo, Call Stack    | Printer Queue, BFS  |
| STL Header      | `<stack>`           | `<queue>`           |

---

## 💡 Printing All Stack Elements

> STL stack doesn't support direct printing — you must pop each element:

```cpp
while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

> ⚠️ This **destroys** the stack — make a copy if you need to keep the original.

---

## 📝 Key Takeaways

- Stack follows **LIFO** — Last In, First Out.
- STL `stack<int>` gives ready-to-use push, pop, top, empty, size — all `O(1)`.
- `pop()` only **removes** — always use `top()` to read before popping.
- Call `empty()` before `top()` or `pop()` to avoid **undefined behavior** on empty stack.
- Stack is used everywhere — undo systems, recursion, expression parsing, DFS.
- This is your **first non-linear ADT (Abstract Data Type)** built using STL! 🎉

---

*Part of the [DSA Learning Repository](../../README.md) — Stacks & Queues Section* 🧠