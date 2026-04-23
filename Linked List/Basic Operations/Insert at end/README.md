# 🔗 Linked List — Insert at End

## 📌 What is Insert at End?

**Insert at End** (also called **append**) adds a new node at the **tail** of the linked list. Unlike insert at beginning, the new node becomes the **last node** — maintaining the order of insertion.

> Think of it like a queue at a ticket counter — every new person joins at the **back** of the line, preserving the order everyone arrived.

---

## 🆚 Insert at Beginning vs Insert at End

| Feature                | Insert at Beginning | Insert at End       |
|------------------------|---------------------|---------------------|
| New node position      | Front (head)        | Back (tail)         |
| Order preserved?       | ❌ Reversed         | ✅ Insertion order  |
| Time Complexity        | `O(1)`              | `O(1)` with `end` pointer ✅ |
| Extra pointer needed?  | ❌ No               | ✅ `end` pointer    |

---

## 🧠 How It Works

### Case 1 — Empty List (first insertion)
```
head = NULL, end = NULL

Insert 10:
  temp = new Node(10) → [10 | NULL]
  head == NULL → head = temp, end = temp

  head ──→ [10 | NULL] ←── end
```

### Case 2 — List already has nodes
```
head ──→ [10 | NULL] ←── end

Insert 20:
  temp = new Node(20) → [20 | NULL]
  end->next = temp    → [10 | •]──→[20 | NULL]
  end = temp          → end now points to 20

  head ──→ [10 | •]──→[20 | NULL] ←── end

Insert 30:
  temp = new Node(30) → [30 | NULL]
  end->next = temp    → [10 | •]──→[20 | •]──→[30 | NULL]
  end = temp          → end now points to 30

  head ──→ [10 | •]──→[20 | •]──→[30 | NULL] ←── end ✅
```

---

## 💡 Key Insight — The `end` Pointer

Without an `end` pointer, inserting at the end requires **traversing the entire list** every time → `O(n)`.

With an `end` pointer, you always know **exactly where the tail is** → `O(1)`! ✅

```cpp
// Without end pointer — O(n) every insert
Node *temp = head;
while (temp->next != NULL) temp = temp->next;  // traverse to end
temp->next = newNode;

// With end pointer — O(1) every insert ✅
end->next = newNode;
end = newNode;
```

---

## 💻 Code — `linked_list_insert_end.cpp`

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
        this->next = NULL;    // New node points to nothing
    }
};

void insertAtEnd(Node *&head, Node *&end, int d)
{
    Node *temp = new Node(d);       // Step 1: Create new node

    if (head == NULL)               // Case 1: Empty list
    {
        head = temp;                // New node is both head and end
        end = temp;
    }
    else                            // Case 2: List has nodes
    {
        end->next = temp;           // Step 2: Link current end to new node
        end = temp;                 // Step 3: Update end to new node
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;          // Move to next node
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;              // Empty list initially
    Node *end = NULL;               // No tail yet

    insertAtEnd(head, end, 10);
    insertAtEnd(head, end, 20);
    insertAtEnd(head, end, 30);
    insertAtEnd(head, end, 40);

    print(head);                    // 10->20->30->40->NULL

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
Start: head = NULL, end = NULL

─────────────────────────────────────────────
insertAtEnd(head, end, 10):
  temp = new Node(10)
  head == NULL → head = temp, end = temp
  head ──→ [10 | NULL] ←── end

─────────────────────────────────────────────
insertAtEnd(head, end, 20):
  temp = new Node(20) → [20 | NULL]
  end->next = temp    → [10 | •]──→[20 | NULL]
  end = temp          → end points to 20
  head ──→ [10 | •]──→[20 | NULL] ←── end

─────────────────────────────────────────────
insertAtEnd(head, end, 30):
  temp = new Node(30) → [30 | NULL]
  end->next = temp    → [10 | •]──→[20 | •]──→[30 | NULL]
  end = temp          → end points to 30
  head ──→ [10 | •]──→[20 | •]──→[30 | NULL] ←── end

─────────────────────────────────────────────
insertAtEnd(head, end, 40):
  temp = new Node(40) → [40 | NULL]
  end->next = temp    → [10 | •]──→[20 | •]──→[30 | •]──→[40 | NULL]
  end = temp          → end points to 40
  head ──→ [10 | •]──→[20 | •]──→[30 | •]──→[40 | NULL] ←── end ✅
```

---

## 📊 Complexity Analysis

| Operation            | Time Complexity | Explanation                                    |
|----------------------|-----------------|------------------------------------------------|
| **Insert at End**    | `O(1)` ✅       | `end` pointer gives direct access to tail      |
| **Insert (no end)**  | `O(n)`          | Would need to traverse entire list every time  |
| **Print / Traverse** | `O(n)`          | Must visit every node once                     |
| **Space per Node**   | `O(1)`          | Each node stores data + one pointer            |
| **Total Space**      | `O(n)`          | `n` nodes in memory                            |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Node(int data)` | Constructor — creates node with given data, next = NULL |
| `insertAtEnd(head, end, d)` | Appends new node to tail, handles empty list case |
| `print(head)` | Traverses and prints list as `data->data->NULL` |
| `main()` | Initializes empty list, inserts 4 nodes, prints result |

---

## 🔑 Variable Roles

| Variable | Role |
|---|---|
| `head` | Points to the **first** node — entry point of the list |
| `end` | Points to the **last** node — allows `O(1)` tail insertion |
| `temp` | Temporary pointer to the newly created node |

---

## ⭐ Two Pointers — `head` and `end`

```
head ──→ [10 | •]──→[20 | •]──→[30 | •]──→[40 | NULL] ←── end
           ↑                                    ↑
     entry point                           tail pointer
   (never changes                      (moves with each
    unless empty)                        new insertion)
```

> `head` lets you **traverse** the list.  
> `end` lets you **append** in `O(1)` without traversing.  
> Together they make the list efficient from both ends! ✅

---

## 🖥️ Sample Output

```
10->20->30->40->NULL
```

> Elements appear in **insertion order** — exactly as added! 🔄

---

## 🔗 Insert at Beginning vs Insert at End — Side by Side

```
Insert at Beginning (15, 16 into list with 10):
  head ──→ [16 | •]──→[15 | •]──→[10 | NULL]
  Order: REVERSED — newest first

Insert at End (10, 20, 30, 40):
  head ──→ [10 | •]──→[20 | •]──→[30 | •]──→[40 | NULL] ←── end
  Order: PRESERVED — oldest first ✅
```

---

## 🗺️ Linked List Operations Roadmap

```
✅ Insert at Beginning
✅ Insert at End          ← You are here
🔄 Insert at Position
🔄 Delete at Beginning
🔄 Delete at End
🔄 Search in Linked List
🔄 Reverse a Linked List
🔄 Detect a Cycle
```

---

## 📝 Key Takeaways

- **Insert at End** appends a new node to the tail of the list.
- Using an `end` pointer makes it `O(1)` — without it, it would be `O(n)`.
- Always handle the **empty list case** (`head == NULL`) separately.
- Elements are stored in **insertion order** — unlike insert at beginning.
- Both `head` and `end` are passed by **reference** (`Node *&`) so updates reflect in `main()`.
- `end->next` always points to `NULL` — it's always the last node.

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists Section* 🧠