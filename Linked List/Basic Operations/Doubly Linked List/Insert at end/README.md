# 🔗 Doubly Linked List — Insert at Head & Tail

## 📌 What is This?

This program demonstrates **two insertion operations** on a Doubly Linked List:
- **Insert at Head** — adds a new node at the **front** using a `head` pointer
- **Insert at Tail** — adds a new node at the **back** using a `tail` pointer

Together, `head` and `tail` give you `O(1)` insertion at **both ends** of the list simultaneously!

> Think of it like a train — the `head` is the engine at the front, the `tail` is the last carriage at the back. You can add new carriages to either end instantly.

---

## 🆚 Head vs Tail Insertion

| Feature              | Insert at Head      | Insert at Tail      |
|----------------------|---------------------|---------------------|
| New node position    | Front of list       | Back of list        |
| Pointer updated      | `head`              | `tail`              |
| Order preserved?     | ❌ Reversed         | ✅ Insertion order  |
| Time Complexity      | `O(1)` ✅           | `O(1)` ✅           |
| Links updated        | `temp->next`, `head->prev`, `head` | `tail->next`, `temp->prev`, `tail` |

---

## 🧠 How Insert at Tail Works

### Case 1 — Empty List
```
tail = NULL

Insert 60:
  temp = new Node(60) → [NULL | 60 | NULL]
  tail == NULL → tail = temp

  tail ──→ [NULL | 60 | NULL]
```

### Case 2 — List has nodes
```
... ⟷ [NULL|10|NULL] ←── tail

Insert 60:
  temp = new Node(60) → [NULL | 60 | NULL]

  Step 1: tail->next = temp  →  [•|10|•]──→[NULL|60|NULL]
  Step 2: temp->prev = tail  →  [•|10|•]⟷[•|60|NULL]
  Step 3: tail = temp        →  tail now points to [60]

  ... ⟷ [•|10|•] ⟷ [•|60|NULL] ←── tail ✅
```

---

## 🧠 How Insert at Head Works (Updated Version)

### Case 1 — Empty List
```
  head == NULL → head = tail = temp   ← sets BOTH pointers! ✅
```

### Case 2 — List has nodes
```
head ──→ [NULL|50|•] ⟷ ...

Insert 40:
  temp = new Node(40)
  Step 1: temp->next = head  →  [NULL|40|•]──→[NULL|50|•]⟷...
  Step 2: head->prev = temp  →  [NULL|40|•]⟷[•|50|•]⟷...
  Step 3: head = temp        →  head now points to [40]

head ──→ [NULL|40|•] ⟷ [•|50|•] ⟷ ... ✅
```

---

## 💻 Code — `doubly_linked_list_head_tail.cpp`

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
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;       // Traverse forward using next
    }
    cout << endl;
}

void insertATtail(Node *&tail, int d)
{
    Node *temp = new Node(d);    // Step 1: Create new node

    if (tail == NULL)            // Case 1: Empty list
    {
        tail = temp;
        return;
    }
    tail->next = temp;           // Step 2: Current tail points forward to new node
    temp->prev = tail;           // Step 3: New node points backward to current tail
    tail = temp;                 // Step 4: Update tail to new node
}

void InsertATHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);    // Step 1: Create new node

    if (head == NULL)            // Case 1: Empty list
    {
        head = tail = temp;      // Both head and tail point to only node
        return;
    }
    temp->next = head;           // Step 2: New node points forward to old head
    head->prev = temp;           // Step 3: Old head points backward to new node
    head = temp;                 // Step 4: Update head to new node
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Insert at head — list grows from front
    InsertATHead(head, tail, 10);
    InsertATHead(head, tail, 20);
    InsertATHead(head, tail, 30);
    InsertATHead(head, tail, 40);
    InsertATHead(head, tail, 50);

    print(head);                  // 50 40 30 20 10

    // Insert at tail — list grows from back
    insertATtail(tail, 60);
    insertATtail(tail, 70);

    print(head);                  // 50 40 30 20 10 60 70

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
── INSERT AT HEAD ──────────────────────────────────────

InsertATHead(10): head == NULL → head = tail = [NULL|10|NULL]
  head ──→ [NULL|10|NULL] ←── tail

InsertATHead(20):
  temp->next=head, head->prev=temp, head=temp
  head ──→ [NULL|20|•]⟷[•|10|NULL] ←── tail

InsertATHead(30):
  head ──→ [NULL|30|•]⟷[•|20|•]⟷[•|10|NULL] ←── tail

InsertATHead(40):
  head ──→ [NULL|40|•]⟷[•|30|•]⟷[•|20|•]⟷[•|10|NULL] ←── tail

InsertATHead(50):
  head ──→ [NULL|50|•]⟷[•|40|•]⟷[•|30|•]⟷[•|20|•]⟷[•|10|NULL] ←── tail

print(head) → 50 40 30 20 10

── INSERT AT TAIL ──────────────────────────────────────

insertATtail(60):
  tail->next = temp    → [•|10|•]──→[NULL|60|NULL]
  temp->prev = tail    → [•|10|•]⟷[•|60|NULL]
  tail = temp          → tail now points to [60]
  head ──→ [NULL|50|•]⟷...⟷[•|10|•]⟷[•|60|NULL] ←── tail

insertATtail(70):
  tail->next = temp    → [•|60|•]──→[NULL|70|NULL]
  temp->prev = tail    → [•|60|•]⟷[•|70|NULL]
  tail = temp          → tail now points to [70]
  head ──→ [NULL|50|•]⟷...⟷[•|60|•]⟷[•|70|NULL] ←── tail

print(head) → 50 40 30 20 10 60 70 ✅
```

---

## 🌟 Full List Visualization

```
After all insertions:

head                                               tail
 ↓                                                  ↓
[NULL|50|•]⟷[•|40|•]⟷[•|30|•]⟷[•|20|•]⟷[•|10|•]⟷[•|60|•]⟷[•|70|NULL]

Forward:   50 → 40 → 30 → 20 → 10 → 60 → 70 → NULL
Backward:  NULL ← 50 ← 40 ← 30 ← 20 ← 10 ← 60 ← 70
```

---

## 📊 Complexity Analysis

| Operation             | Time Complexity | Explanation                            |
|-----------------------|-----------------|----------------------------------------|
| **Insert at Head**    | `O(1)`          | Direct pointer update at front         |
| **Insert at Tail**    | `O(1)`          | Direct pointer update at back          |
| **Print / Traverse**  | `O(n)`          | Visit every node once                  |
| **Space per Node**    | `O(1)`          | data + prev + next pointers            |
| **Total Space**       | `O(n)`          | `n` nodes in memory                    |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Node(int d)` | Constructor — creates node with data, both pointers = NULL |
| `InsertATHead(head, tail, d)` | Inserts at front, handles empty list by setting both `head` and `tail` |
| `insertATtail(tail, d)` | Appends to back using `tail` pointer |
| `print(head)` | Traverses forward and prints all values |
| `main()` | Builds list using both operations, prints before and after tail insertions |

---

## 🔑 Pointer Steps Compared

### Insert at Head:
```cpp
temp->next = head;     // New node → old head (forward link)
head->prev = temp;     // Old head → new node (backward link)
head = temp;           // head moves to new front
```

### Insert at Tail:
```cpp
tail->next = temp;     // Old tail → new node (forward link)
temp->prev = tail;     // New node → old tail (backward link)
tail = temp;           // tail moves to new back
```

> Notice the **symmetry** — head and tail operations are mirrors of each other! 🪞

---

## ⭐ Key Difference — Empty List Handling

```cpp
// InsertATHead — sets BOTH head and tail
if (head == NULL) {
    head = tail = temp;   // ← single node is both head AND tail ✅
}

// insertATtail — sets only tail
if (tail == NULL) {
    tail = temp;          // ← only sets tail (head not managed here)
}
```

> In `main()`, `InsertATHead` is called first — so when the list is empty, it correctly sets **both** `head` and `tail`. Then `insertATtail` safely assumes `head` is already set. ✅

---

## 🖥️ Sample Output

```
50 40 30 20 10
50 40 30 20 10 60 70
```

> First print: 5 head insertions — newest at front  
> Second print: 2 tail insertions appended at back ✅

---

## 🗺️ Doubly Linked List Operations Roadmap

```
✅ Insert at Head
✅ Insert at Tail          ← You are here
🔄 Insert at Position
🔄 Delete at Head
🔄 Delete at Tail
🔄 Delete at Position
🔄 Reverse Traversal
```

---

## 📝 Key Takeaways

- Using both `head` and `tail` pointers gives `O(1)` insertion at **both ends**.
- Insert at Head and Insert at Tail are **mirror operations** of each other.
- When the list is **empty**, the first node is both `head` and `tail` — always handle this case.
- `head->prev` is always `NULL` — nothing before the first node.
- `tail->next` is always `NULL` — nothing after the last node.
- The `prev` pointer is what makes doubly linked lists powerful — backward linking enables deletion and reverse traversal without extra traversal.
- This structure is the foundation of a **Deque (Double-Ended Queue)**! 🌍

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists → Doubly Linked List Section* 🧠