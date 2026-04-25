# 🗑️ Linked List — Delete at Position

## 📌 What is Delete at Position?

**Delete at Position** removes a node from a **specific index** in the linked list and **frees its memory**. It properly re-links the surrounding nodes so the list remains intact after deletion.

> Think of it like removing a person from a specific spot in a queue — the people behind them close the gap and the queue continues normally.

---

## 🧠 How It Works

### Case 1 — Delete at Position 1 (Head)
```
List: 70->60->50->40->30->20->10->NULL
Delete position 1

  temp = head            → temp points to [70]
  head = head->next      → head now points to [60]
  temp->next = NULL      → disconnect [70]
  delete temp            → free memory of [70]

Result: 60->50->40->30->20->10->NULL ✅
```

### Case 2 — Delete at Middle Position
```
List: 70->60->50->40->30->20->10->NULL
Delete position 2

  Traverse until current = node at position 2:
    previous = [70], current = [60]

  previous->next = current->next  → [70]──→[50]
  current->next = NULL            → disconnect [60]
  delete current                  → free memory of [60]

Result: 70->50->40->30->20->10->NULL ✅
```

### Case 3 — Position Out of Range
```
  current reaches NULL before position
  → return silently (no crash) ✅
```

### Case 4 — Empty List
```
  head == NULL → return immediately ✅
```

---

## 💡 Key Insight — Two Pointer Technique

Your code uses `current` and `previous` pointers to track **two adjacent nodes**:

```
       previous   current
          ↓          ↓
... ──→ [70 | •]──→[60 | •]──→[50 | •]──→ ...

After deletion of current (60):
  previous->next = current->next

... ──→ [70 | •]──→[50 | •]──→ ...   ✅ [60] removed
```

> You need `previous` because singly linked lists can only move **forward** — you can't go back to fix the previous node without tracking it!

---

## ⭐ Destructor — Memory Management

Your `Node` class has a **destructor** — a special function that runs automatically when `delete` is called:

```cpp
~Node()
{
    cout << "Memory is free for node with data " << data << endl;
}
```

```
When delete temp is called:
  → destructor runs automatically
  → prints confirmation message
  → memory is released back to OS ✅
```

> This is important in C++ — without `delete`, the memory stays occupied even after the node is removed from the list. This is called a **memory leak**! ⚠️

---

## 💻 Code — `linked_list_delete.cpp`

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
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Memory is free for node with data " << data << endl;
    }
};

void pushATbigin(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void Delete(Node *&head, int position)
{
    if (head == NULL) return;           // Case 4: Empty list

    if (position == 1)                  // Case 1: Delete head
    {
        Node *temp = head;
        head = head->next;              // Move head forward
        temp->next = NULL;              // Disconnect node
        delete temp;                    // Free memory → destructor runs
        return;
    }

    // Case 2 & 3: Traverse to target position
    Node *current = head;
    Node *previous = NULL;
    int count = 1;

    while (count < position && current != NULL)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) return;        // Case 3: Out of range

    previous->next = current->next;     // Bridge the gap
    current->next = NULL;               // Disconnect node
    delete current;                     // Free memory → destructor runs
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;

    pushATbigin(head, 10);
    pushATbigin(head, 20);
    pushATbigin(head, 30);
    pushATbigin(head, 40);
    pushATbigin(head, 50);
    pushATbigin(head, 60);
    pushATbigin(head, 70);

    print(head);           // 70->60->50->40->30->20->10->NULL

    Delete(head, 2);       // Delete node at position 2 (60)

    print(head);           // 70->50->40->30->20->10->NULL

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
Build list (pushATbigin inserts at beginning each time):
  push 10 → [10 | NULL]
  push 20 → [20 | •]──→[10]
  push 30 → [30 | •]──→[20 | •]──→[10]
  push 40 → [40 | •]──→[30 | •]──→[20 | •]──→[10]
  push 50 → [50 | •]──→[40 | •]──→...
  push 60 → [60 | •]──→[50 | •]──→...
  push 70 → [70 | •]──→[60 | •]──→[50 | •]──→[40 | •]──→[30 | •]──→[20 | •]──→[10 | NULL]

print → 70->60->50->40->30->20->10->NULL

─────────────────────────────────────────────
Delete(head, 2):

  head != NULL ✅
  position != 1 → skip head deletion

  Traverse:
    count=1: previous=NULL,  current=[70]
    count=2: previous=[70],  current=[60]  → count == position → STOP

  current != NULL ✅

  previous->next = current->next  →  [70 | •]──→[50 | •]──→...
  current->next = NULL            →  [60 | NULL]  (disconnected)
  delete current                  →  destructor: "Memory is free for node with data 60"

print → 70->50->40->30->20->10->NULL ✅
```

---

## 📊 Complexity Analysis

| Operation               | Time Complexity | Explanation                              |
|-------------------------|-----------------|------------------------------------------|
| **Delete at pos 1**     | `O(1)`          | Just update head pointer                 |
| **Delete at pos P**     | `O(P)`          | Traverse P nodes to reach target         |
| **Delete out of range** | `O(n)`          | Traverses until NULL                     |
| **Space**               | `O(1)`          | No extra memory — deleting frees memory  |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `~Node()` | Destructor — prints confirmation and frees memory when node is deleted |
| `Delete(head, position)` | Removes node at given position, handles all 4 cases |
| `pushATbigin(head, d)` | Inserts new node at beginning of list |
| `print(head)` | Traverses and prints list as `data->data->NULL` |
| `main()` | Builds 7-node list, deletes position 2, prints both states |

---

## 🔑 Variable Roles in Delete()

| Variable | Role |
|---|---|
| `current` | Points to the **node to be deleted** |
| `previous` | Points to the node **just before** current |
| `temp` | Used only for position 1 deletion — holds old head |
| `count` | Tracks current traversal position |

---

## 🖥️ Sample Output

```
70->60->50->40->30->20->10->NULL
Memory is free for node with data 60
70->50->40->30->20->10->NULL
```

> The destructor message appears **between** the two print calls — confirming memory was freed at the right moment! ✅

---

## ⚠️ Why `current->next = NULL` Before `delete`?

```cpp
previous->next = current->next;   // Bridge the gap first
current->next = NULL;             // Isolate the node
delete current;                   // Then free memory
```

> Setting `current->next = NULL` before deleting **isolates** the node completely.  
> Without it, deleting `current` while it still points forward could cause **undefined behavior** in some implementations. Clean disconnection = safe deletion. ✅

---

## 🆚 All Linked List Operations So Far

| Operation           | Time     | Key Pointer Action                        |
|---------------------|----------|-------------------------------------------|
| Insert at Beginning | `O(1)`   | New node → head                           |
| Insert at End       | `O(1)`   | `end->next` → new node                   |
| Insert at Position  | `O(P)`   | Traverse to P-1, link new node in between |
| **Delete at Position** | `O(P)` | Traverse to P, bridge gap, free memory  |

---

## 🗺️ Linked List Operations Roadmap

```
✅ Insert at Beginning
✅ Insert at End
✅ Insert at Position
✅ Delete at Position      ← You are here
🔄 Search in Linked List
🔄 Reverse a Linked List
🔄 Detect a Cycle
```

---

## 📝 Key Takeaways

- Delete uses **two pointers** (`current` and `previous`) to track adjacent nodes.
- Always handle **4 cases** — empty list, position 1, middle, out of range.
- **Position 1 is special** — no `previous` node exists, so `head` must be updated directly.
- Always call `delete` to **free memory** — skipping it causes memory leaks in C++.
- The **destructor** `~Node()` runs automatically when `delete` is called — confirming memory release.
- Set `current->next = NULL` before deleting to **safely isolate** the node.
- `previous->next = current->next` is the **one line** that bridges the gap! 🔑

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists Section* 🧠