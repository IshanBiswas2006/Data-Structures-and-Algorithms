# 📚 Stack — Implementation Using Array

## 📌 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO** principle — **Last In, First Out**. The last element inserted is the first one to be removed — just like a stack of plates.

```
        ┌──────┐
        │   5  │  ← TOP (last inserted, first removed)
        ├──────┤
        │   4  │
        ├──────┤
        │   3  │
        ├──────┤
        │   2  │
        ├──────┤
        │   1  │  ← BOTTOM (first inserted, last removed)
        └──────┘
```

> Think of it like a stack of plates — you can only add or remove from the **top**. You can't pull a plate from the middle!

---

## 🧠 LIFO — Last In First Out

```
PUSH order:  1 → 2 → 3 → 4 → 5
POP order:   5 → 4 → 3 → 2 → 1

Last pushed (5) is always popped first! ✅
```

---

## 💡 Why Implement Stack Using an Array?

Instead of using the STL `stack`, here we build our **own stack class from scratch** using a **dynamic array** (`new int[]`). This helps you understand:

- How stack operations actually work **under the hood**
- How `top` pointer manages the current position
- How **overflow** and **underflow** conditions are handled
- Memory allocation using `new` keyword

```
Array:   [ 1 | 2 | 3 | 4 | 5 ]
Index:     0   1   2   3   4
                            ↑
                           top = 4
```

> The `top` variable tracks the index of the topmost element. It starts at **-1** (empty stack).

---

## 🏗️ Class Design — `stack`

```cpp
class stack {
public:
    int *arr;      // Dynamic array to store elements
    int top;       // Index of the top element (-1 = empty)
    int size;      // Maximum capacity of the stack

    stack(int size);            // Constructor — allocates array
    void push(int elements);   // Insert element on top
    void pop();                // Remove top element
    int peek();                // View top element without removing
    bool empty();              // Check if stack is empty
};
```

> The constructor takes the **size** as a parameter, allocates a dynamic array, and initializes `top = -1`.

---

## 💻 Code — `stack_array.cpp`

```cpp
#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int elements)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = elements;
        }
        else
        {
            cout << "Stack is overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.peek() << endl;

    s.pop();

    cout << s.peek() << endl;

    s.pop();

    cout << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << s.peek() << endl;

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
s.push(1):   arr → [1| | | | ]        top = 0
s.push(2):   arr → [1|2| | | ]        top = 1
s.push(3):   arr → [1|2|3| | ]        top = 2
s.push(4):   arr → [1|2|3|4| ]        top = 3
s.push(5):   arr → [1|2|3|4|5]        top = 4   ← Stack is FULL

s.peek():    Returns arr[4] = 5        → prints 5

s.pop():     top-- → top = 3
s.peek():    Returns arr[3] = 4        → prints 4

s.pop():     top-- → top = 2
s.peek():    Returns arr[2] = 3        → prints 3

s.pop():     top-- → top = 1
s.pop():     top-- → top = 0
s.pop():     top-- → top = -1          ← Stack is EMPTY

s.peek():    top < 0 → "Stack is empty" → returns -1

s.empty():   top == -1 → true          → "Stack is empty"
```

---

## 📋 Custom Stack Operations

| Operation   | Method            | Description                                              | Time   |
|-------------|-------------------|----------------------------------------------------------|--------|
| **Push**    | `s.push(val)`     | Insert element on top (checks overflow)                  | `O(1)` |
| **Pop**     | `s.pop()`         | Remove top element by decrementing `top` (checks underflow) | `O(1)` |
| **Peek**    | `s.peek()`        | Returns top element without removing it                  | `O(1)` |
| **Empty**   | `s.empty()`       | Returns `true` if `top == -1`                            | `O(1)` |

> ⚠️ Unlike STL, our `peek()` **returns the value** — combining the behavior of STL's `top()`.

---

## ⚠️ Overflow & Underflow Handling

### Stack Overflow — Pushing when full

```cpp
stack s(3);
s.push(10);    // ✅ OK
s.push(20);    // ✅ OK
s.push(30);    // ✅ OK — stack is now full
s.push(40);    // ❌ "Stack is overflow" — no space left!
```

```
Overflow check:  size - top > 1
When top = 2, size = 3 → 3 - 2 = 1 → NOT > 1 → overflow!
```

### Stack Underflow — Popping when empty

```cpp
stack s(3);
s.pop();       // ❌ "Stack underflow" — nothing to remove!
```

```
Underflow check:  top >= 0
When top = -1 → NOT >= 0 → underflow!
```

---

## 🧩 How Each Function Works

### `push(int elements)`
```
1. Check if there's space:  size - top > 1
2. If yes → increment top, store value at arr[top]
3. If no  → print "Stack is overflow"
```

### `pop()`
```
1. Check if stack has elements:  top >= 0
2. If yes → decrement top (element is logically removed)
3. If no  → print "Stack underflow"
```

> 💡 `pop()` doesn't actually delete the value from memory — it just moves `top` down. The old value is overwritten on the next `push()`.

### `peek()`
```
1. Check if stack has elements:  top >= 0
2. If yes → return arr[top]
3. If no  → print "Stack is empty", return -1
```

### `empty()`
```
1. If top == -1 → return true  (stack is empty)
2. Otherwise    → return false (stack has elements)
```

---

## 📊 Complexity Analysis

| Operation   | Time Complexity | Space Complexity |
|-------------|-----------------|------------------|
| `push()`    | `O(1)`          | `O(1)`           |
| `pop()`     | `O(1)`          | `O(1)`           |
| `peek()`    | `O(1)`          | `O(1)`           |
| `empty()`   | `O(1)`          | `O(1)`           |
| **Overall** | `O(n)` for n ops| `O(n)` for n elements |

> Space is `O(n)` because we allocate an array of size `n` at construction.

---

## 🖥️ Sample Output

```
5
4
3
Stack is empty
-1
Stack is empty
```

---

## 🆚 Array Implementation vs STL Stack

| Feature              | Array (Custom)            | STL `stack<int>`          |
|----------------------|---------------------------|---------------------------|
| **Size**             | Fixed at creation         | Dynamic (grows as needed) |
| **Overflow**         | Must handle manually      | Handled automatically     |
| **Underflow**        | Must handle manually      | Undefined behavior        |
| **Peek/Top**         | `s.peek()` returns value  | `s.top()` returns value   |
| **Pop**              | `s.pop()` — void          | `s.pop()` — void          |
| **Memory**           | Manual (`new int[]`)      | Managed by STL            |
| **Learning Value**   | ⭐ High — understand internals | Lower — abstracted away |
| **Production Use**   | Rarely                    | ✅ Preferred              |

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

## 💡 Possible Improvements

```cpp
// 1. Add a destructor to free memory
~stack() {
    delete[] arr;
}

// 2. Add a size() method
int getSize() {
    return top + 1;
}

// 3. Add a display() method
void display() {
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
```

> ⚠️ The current implementation has a **memory leak** — `new int[]` is used without a corresponding `delete[]`. Always add a destructor in production code!

---

## 📝 Key Takeaways

- Stack follows **LIFO** — Last In, First Out.
- Array-based stack uses a **fixed-size array** and a **`top` pointer** starting at `-1`.
- `push()` increments `top` and stores value — checks for **overflow** (`size - top > 1`).
- `pop()` decrements `top` — checks for **underflow** (`top >= 0`).
- `peek()` returns `arr[top]` without modifying the stack.
- Always handle **overflow** and **underflow** to prevent crashes.
- This implementation helps you understand **how STL stack works internally**! 🎉

---

*Part of the [DSA Learning Repository](../../README.md) — Stacks & Queues Section* 🧠
