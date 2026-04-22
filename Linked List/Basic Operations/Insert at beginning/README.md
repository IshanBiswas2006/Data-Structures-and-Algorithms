# 🔗 Linked List — Insert at Beginning

## 📌 What is a Linked List?

A **Linked List** is a linear data structure where elements (called **nodes**) are stored in memory **non-contiguously**. Each node holds data and a **pointer to the next node**, forming a chain.

```
[10 | •]──→[20 | •]──→[30 | •]──→NULL
  Node 1      Node 2      Node 3
```

> Unlike arrays, linked lists don't need contiguous memory — each node can be anywhere in memory, connected by pointers.

---

## 🆚 Array vs Linked List

| Feature              | Array              | Linked List         |
|----------------------|--------------------|---------------------|
| Memory               | Contiguous ✅       | Non-contiguous      |
| Size                 | Fixed              | Dynamic ✅           |
| Access               | `O(1)` random ✅   | `O(n)` sequential  |
| Insert at beginning  | `O(n)` slow        | `O(1)` fast ✅      |
| Insert at end        | `O(1)` (if space)  | `O(n)`              |
| Memory overhead      | None               | Extra pointer/node  |

---

## 🧠 How a Node Works

Your code defines a `Node` class:

```cpp
class Node {
public:
    int data;       // Stores the value
    Node *next;     // Pointer to the next node

    Node(int data) {
        this->data = data;
        this->next = NULL;   // New node points to nothing
    }
};
```

```
┌──────────────┐
│  data = 10   │
│  next = NULL │
└──────────────┘
     Node
```

---

## 💡 Core Operation — Insert at Beginning

Inserting at the beginning is the **fastest linked list insertion** — `O(1)`:

```
BEFORE:
head ──→ [10 | •]──→ [20 | NULL]

Step 1: Create new node (15)
        [15 | NULL]

Step 2: Point new node's next to current head
        [15 | •]──→ [10 | •]──→ [20 | NULL]

Step 3: Update head to new node
head ──→ [15 | •]──→ [10 | •]──→ [20 | NULL]

AFTER: ✅
```

---

## 💻 Code — `linked_list_insert_begin.cpp`

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;    // Initialize next as NULL
    }
};

// Insert a new node at the beginning of the list
void insertAtbegin(Node *&head, int d)
{
    Node *temp = new Node(d);   // Step 1: Create new node
    temp->next = head;          // Step 2: Point new node to current head
    head = temp;                // Step 3: Update head to new node
}

// Print the entire linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;      // Move to next node
    }
    cout << "NULL" << endl;     // End of list
}

int main()
{
    Node *node1 = new Node(10); // Create first node
    Node *head = node1;         // head points to first node

    print(head);                // 10->NULL

    insertAtbegin(head, 15);    // Insert 15 at beginning
    print(head);                // 15->10->NULL

    insertAtbegin(head, 16);    // Insert 16 at beginning
    print(head);                // 16->15->10->NULL

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
Initial State:
  node1 = new Node(10)
  head ──→ [10 | NULL]

  print → 10->NULL

─────────────────────────────────────────────
insertAtbegin(head, 15):

  temp = new Node(15) → [15 | NULL]
  temp->next = head   → [15 | •]──→[10 | NULL]
  head = temp         → head now points to 15

  print → 15->10->NULL

─────────────────────────────────────────────
insertAtbegin(head, 16):

  temp = new Node(16) → [16 | NULL]
  temp->next = head   → [16 | •]──→[15 | •]──→[10 | NULL]
  head = temp         → head now points to 16

  print → 16->15->10->NULL ✅
```

---

## ⭐ Why `Node *&head` (Pass by Reference)?

```cpp
void insertAtbegin(Node *&head, int d)   // ✅ Reference to pointer
void insertAtbegin(Node *head, int d)    // ❌ Copy of pointer
```

> If you pass the pointer **by value**, changes to `head` inside the function won't reflect outside.  
> Passing by **reference** (`*&`) means the original `head` in `main()` gets updated. ✅

---

## 📊 Complexity Analysis

| Operation          | Time Complexity | Explanation                              |
|--------------------|-----------------|------------------------------------------|
| **Insert at Begin**| `O(1)`          | Just update two pointers — instant!      |
| **Print / Traverse**| `O(n)`         | Must visit every node once               |
| **Space per Node** | `O(1)`          | Each node stores data + one pointer      |
| **Total Space**    | `O(n)`          | `n` nodes in memory                      |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Node(int data)` | Constructor — creates a node with given data, next = NULL |
| `insertAtbegin(head, d)` | Creates new node and inserts it before current head |
| `print(head)` | Traverses and prints entire list as `data->data->NULL` |
| `main()` | Creates initial node, builds list by inserting at beginning |

---

## 🖥️ Sample Output

```
10->NULL
15->10->NULL
16->15->10->NULL
```

> Notice the list grows from the **front** — newest element always appears first! 🔄

---

## 🔑 Key Concepts Introduced

| Concept | What it means |
|---|---|
| `Node` class | Blueprint for each element in the list |
| `head` pointer | Always points to the **first** node |
| `next` pointer | Links one node to the next |
| `NULL` | Marks the **end** of the list |
| `new` keyword | Dynamically allocates memory for each node |
| Pass by reference (`*&`) | Allows function to update the original `head` |

---

## 🗺️ Linked List Operations Roadmap

```
✅ Insert at Beginning     ← You are here
🔄 Insert at End
🔄 Insert at Position
🔄 Delete at Beginning
🔄 Delete at End
🔄 Search in Linked List
🔄 Reverse a Linked List
🔄 Detect a Cycle
```

---

## 📝 Key Takeaways

- A **Linked List** is a chain of nodes connected by pointers.
- Each node has `data` and a `next` pointer.
- `head` always points to the **first node** — it's your entry point to the list.
- **Insert at beginning** is `O(1)` — the fastest insertion in a linked list.
- Always pass `head` by reference (`Node *&head`) so the original pointer updates.
- `NULL` at the last node signals the **end of the list**.
- This is your **first dynamic data structure** — a major milestone! 🎉

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists Section* 🧠