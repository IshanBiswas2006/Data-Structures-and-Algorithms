# 🔗 Doubly Linked List — Insert at Head

## 📌 What is a Doubly Linked List?

A **Doubly Linked List** is a linked list where each node has **two pointers** — one pointing to the **next** node and one pointing to the **previous** node. This allows traversal in **both directions**.

```
NULL ←─ [10 | •|•] ←→ [20 | •|•] ←→ [30 | •|•] ─→ NULL
          prev next      prev next      prev next
```

> Think of it like a two-way street — you can travel forward OR backward, unlike a singly linked list which is a one-way street.

---

## 🆚 Singly vs Doubly Linked List

| Feature                  | Singly Linked List  | Doubly Linked List     |
|--------------------------|---------------------|------------------------|
| Pointers per node        | 1 (`next`)          | 2 (`prev` + `next`) ✅ |
| Traversal direction      | Forward only        | Both directions ✅      |
| Memory per node          | Less                | More (extra pointer)   |
| Delete without traversal | ❌ Need `previous`  | ✅ Use `prev` directly  |
| Insert at head           | `O(1)`              | `O(1)` ✅              |
| Implementation           | Simpler             | Slightly more complex  |

---

## 🧠 How a Doubly Node Works

Your `Node` class has **three fields**:

```cpp
class Node {
public:
    int data;      // Stores the value
    Node *prev;    // Points to PREVIOUS node
    Node *next;    // Points to NEXT node
};
```

```
┌─────────────────────────────┐
│  prev  │  data  │  next     │
│  NULL  │   10   │  NULL     │
└─────────────────────────────┘
          New Node
```

---

## 🧠 How Insert at Head Works

### Case 1 — Empty List (first insertion)
```
head = NULL

Insert 10:
  temp = new Node(10) → [NULL | 10 | NULL]
  head == NULL → head = temp

  head ──→ [NULL | 10 | NULL]
```

### Case 2 — List already has nodes
```
head ──→ [NULL | 10 | NULL]

Insert 20:
  temp = new Node(20) → [NULL | 20 | NULL]

  Step 1: temp->next = head
          [NULL | 20 | •]──→[NULL | 10 | NULL]

  Step 2: head->prev = temp
          [NULL | 20 | •]──→[• | 10 | NULL]
                              ↑
                          prev now points back to 20

  Step 3: head = temp
          head ──→ [NULL | 20 | •]⟷[• | 10 | NULL]

Insert 30:
  temp = new Node(30)
  temp->next = head      →  [NULL | 30 | •]──→[NULL | 20 | •]⟷...
  head->prev = temp      →  [NULL | 30 | •]⟷[• | 20 | •]⟷[• | 10 | NULL]
  head = temp

  head ──→ [NULL|30|•]⟷[•|20|•]⟷[•|10|NULL]
```

---

## 💻 Code — `doubly_linked_list_insert_head.cpp`

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;    // No previous node yet
        this->next = NULL;    // No next node yet
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;    // Move forward using next pointer
    }
    cout << endl;
}

void InsertATHead(Node *&head, int d)
{
    Node *temp = new Node(d);     // Step 1: Create new node

    if (head == NULL)             // Case 1: Empty list
    {
        head = temp;
        return;
    }

    temp->next = head;            // Step 2: New node points forward to old head
    head->prev = temp;            // Step 3: Old head points backward to new node
    head = temp;                  // Step 4: Update head to new node
}

int main()
{
    Node *head = NULL;

    InsertATHead(head, 10);
    InsertATHead(head, 20);
    InsertATHead(head, 30);
    InsertATHead(head, 40);
    InsertATHead(head, 50);

    print(head);                  // 50 40 30 20 10

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
InsertATHead(head, 10):
  head == NULL → head = [NULL|10|NULL]
  List: NULL ← [10] → NULL

InsertATHead(head, 20):
  temp = [NULL|20|NULL]
  temp->next = head       → [NULL|20|•] → [NULL|10|NULL]
  head->prev = temp       → [NULL|20|•] ⟷ [•|10|NULL]
  head = temp
  List: NULL ← [20] ⟷ [10] → NULL

InsertATHead(head, 30):
  temp = [NULL|30|NULL]
  temp->next = head       → [NULL|30|•] → [NULL|20|•] ⟷ [•|10|NULL]
  head->prev = temp       → [NULL|30|•] ⟷ [•|20|•] ⟷ [•|10|NULL]
  head = temp
  List: NULL ← [30] ⟷ [20] ⟷ [10] → NULL

InsertATHead(head, 40):
  List: NULL ← [40] ⟷ [30] ⟷ [20] ⟷ [10] → NULL

InsertATHead(head, 50):
  List: NULL ← [50] ⟷ [40] ⟷ [30] ⟷ [20] ⟷ [10] → NULL

print → 50 40 30 20 10 ✅
```

---

## 📊 Complexity Analysis

| Operation             | Time Complexity | Explanation                              |
|-----------------------|-----------------|------------------------------------------|
| **Insert at Head**    | `O(1)`          | Only pointer updates — no traversal      |
| **Print / Traverse**  | `O(n)`          | Visit every node once                    |
| **Space per Node**    | `O(1)`          | Each node stores data + two pointers     |
| **Total Space**       | `O(n)`          | `n` nodes in memory                      |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Node(int d)` | Constructor — creates node with data, both pointers = NULL |
| `InsertATHead(head, d)` | Creates new node, links it bidirectionally, updates head |
| `print(head)` | Traverses forward using `next` pointer, prints all values |
| `main()` | Builds 5-node doubly linked list, prints result |

---

## 🔑 The Three Pointer Steps — Order Matters!

```cpp
temp->next = head;      // Step 1: New node connects FORWARD to old head
head->prev = temp;      // Step 2: Old head connects BACKWARD to new node
head = temp;            // Step 3: head updated to new front node
```

> ⚠️ **Step 3 must be last!** If you update `head` first, you lose access to the old head node and can't set `head->prev`. Always link first, then update `head`.

---

## 🖥️ Sample Output

```
50 40 30 20 10
```

> Elements appear in **reverse insertion order** — newest element always at the front! 🔄

---

## 🌟 Full Node Structure Visualized

```
Final List:

NULL
 ↑
[NULL | 50 | •]
        ↕
[•  | 40 | •]
        ↕
[•  | 30 | •]
        ↕
[•  | 20 | •]
        ↕
[•  | 10 | NULL]
                ↓
               NULL

Forward:  50 → 40 → 30 → 20 → 10 → NULL
Backward: NULL ← 50 ← 40 ← 30 ← 20 ← 10
```

---

## 🗺️ Doubly Linked List Operations Roadmap

```
✅ Insert at Head          ← You are here
🔄 Insert at Tail
🔄 Insert at Position
🔄 Delete at Head
🔄 Delete at Tail
🔄 Delete at Position
🔄 Reverse Traversal
```

---

## 📝 Key Takeaways

- A **Doubly Linked List** node has both `prev` and `next` pointers.
- `head->prev` is always `NULL` — no node before the first one.
- Last node's `next` is always `NULL` — marks end of list.
- Insert at head requires **3 pointer steps** — link forward, link backward, update head.
- **Order of pointer updates matters** — always update `head` last.
- Doubly linked lists allow **backward traversal** — a major advantage over singly linked lists.
- This is the foundation for **Deque**, **Browser History**, and **LRU Cache** implementations! 🌍

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists Section* 🧠