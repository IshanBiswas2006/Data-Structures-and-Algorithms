# 🔗 Doubly Linked List — Insert at Position

## 📌 What is This?

This program combines all three insertion operations for a **Doubly Linked List**:
- ✅ **Insert at Head** — add to front
- ✅ **Insert at Tail** — add to back
- ✅ **Insert at Position** — add at any specific index

Insert at Position is the most **complete and complex** insertion — it handles all edge cases including updating **both** `prev` and `next` pointers bidirectionally, and correctly updating `tail` when inserting at the last position.

---

## 🧠 How Insert at Position Works

### Case 1 — Insert at Position 1 (Head)
```
List: 50⟷40⟷30⟷20⟷10⟷60⟷70
Insert 100 at position 1

  temp = new Node(100)
  temp->next = head     → [NULL|100|•]──→[NULL|50|•]⟷...
  head = temp           → head now points to [100]

Result: 100→50→40→... ✅
```

### Case 2 — Insert at Middle Position
```
List: 50⟷40⟷30⟷20⟷10⟷60⟷70
Insert 100 at position 3

  Traverse to position 2 (position - 1):
  temp stops at [40]

  nodeToInsert = new Node(100)

  Step 1: nodeToInsert->next = temp->next   → [100|•]──→[30]
  Step 2: nodeToInsert->prev = temp         → [40]⟵[100]
  Step 3: temp->next->prev = nodeToInsert   → [30]'s prev = [100]
  Step 4: temp->next = nodeToInsert         → [40]──→[100]

  Result: ...⟷[40]⟷[100]⟷[30]⟷... ✅
```

### Case 3 — Insert at Last Position (updates tail)
```
  temp->next == NULL → inserting after last node
  tail = nodeToInsert     → tail pointer updated ✅
```

### Case 4 — Out of Range
```
  temp reaches NULL before position-1
  → "Position out of range" printed ✅
```

---

## 💡 Key Insight — 4 Pointer Updates for Middle Insert

In a **singly** linked list, inserting needs **2 pointer updates**.  
In a **doubly** linked list, inserting needs **4 pointer updates**:

```
BEFORE:
... ⟷ [40 | •→] [←• | 30 | •→] ⟷ ...

AFTER inserting [100] between [40] and [30]:

Step 1: nodeToInsert->next = temp->next    [100]──→[30]
Step 2: nodeToInsert->prev = temp          [40]⟵──[100]
Step 3: temp->next->prev = nodeToInsert    [30]'s prev = [100]
Step 4: temp->next = nodeToInsert          [40]──→[100]

... ⟷ [40] ⟷ [100] ⟷ [30] ⟷ ... ✅
```

> ⚠️ **Order matters!** Steps 1 & 2 must come before Steps 3 & 4 — otherwise you lose the reference to the next node.

---

## 💻 Code — `doubly_ll_insert_position.cpp`

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
        temp = temp->next;
    }
    cout << endl;
}

void insertATtail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL) { tail = temp; return; }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertATHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL) { head = tail = temp; return; }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtposition(Node *&head, Node *&tail, int position, int d)
{
    // Case 1: Insert at beginning
    if (position == 1)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        return;
    }

    // Traverse to node just before target position
    Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Case 4: Out of range
    if (temp == NULL)
    {
        cout << "Position out of range\n";
        return;
    }

    Node *nodeToinsert = new Node(d);

    nodeToinsert->next = temp->next;    // Step 1: forward link
    nodeToinsert->prev = temp;          // Step 2: backward link to previous

    if (temp->next != NULL)
    {
        temp->next->prev = nodeToinsert; // Step 3: next node links back
    }
    else
    {
        tail = nodeToinsert;             // Case 3: inserting at end → update tail
    }

    temp->next = nodeToinsert;           // Step 4: previous node links forward
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertATHead(head, tail, 10);
    InsertATHead(head, tail, 20);
    InsertATHead(head, tail, 30);
    InsertATHead(head, tail, 40);
    InsertATHead(head, tail, 50);

    print(head);                         // 50 40 30 20 10

    insertATtail(tail, 60);
    insertATtail(tail, 70);

    print(head);                         // 50 40 30 20 10 60 70

    insertAtposition(head, tail, 3, 100);

    print(head);                         // 50 40 100 30 20 10 60 70

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
── BUILD LIST ──────────────────────────────────────────

InsertATHead × 5: 50 40 30 20 10
insertATtail × 2: 60 70 appended

List: [50]⟷[40]⟷[30]⟷[20]⟷[10]⟷[60]⟷[70]
print → 50 40 30 20 10 60 70

── INSERT AT POSITION 3 ────────────────────────────────

insertAtposition(head, tail, 3, 100):

  position != 1 → skip Case 1

  Traverse to position - 1 = 2:
    count=1: temp = [50]
    count=2: temp = [40]  → count == position-1 → STOP

  temp = [40], temp->next = [30]

  nodeToInsert = new Node(100)

  Step 1: nodeToInsert->next = temp->next  → [100]──→[30]
  Step 2: nodeToInsert->prev = temp        → [40]⟵──[100]
  Step 3: temp->next != NULL               → [30]->prev = nodeToInsert
                                           → [100]⟵──[30]
  Step 4: temp->next = nodeToInsert        → [40]──→[100]

  Final: [50]⟷[40]⟷[100]⟷[30]⟷[20]⟷[10]⟷[60]⟷[70]

print → 50 40 100 30 20 10 60 70 ✅
```

---

## 🌟 Full List After All Operations

```
head                                                         tail
 ↓                                                            ↓
[NULL|50|•]⟷[•|40|•]⟷[•|100|•]⟷[•|30|•]⟷[•|20|•]⟷[•|10|•]⟷[•|60|•]⟷[•|70|NULL]

Forward:   50 → 40 → 100 → 30 → 20 → 10 → 60 → 70 → NULL
Backward:  NULL ← 50 ← 40 ← 100 ← 30 ← 20 ← 10 ← 60 ← 70
```

---

## 📊 Complexity Analysis

| Operation               | Time Complexity | Explanation                              |
|-------------------------|-----------------|------------------------------------------|
| **Insert at Head**      | `O(1)`          | Direct pointer update at front           |
| **Insert at Tail**      | `O(1)`          | Direct pointer update at back            |
| **Insert at Position P**| `O(P)`          | Traverse P-1 nodes to reach target       |
| **Out of range check**  | `O(n)`          | Traverses until NULL                     |
| **Space per Node**      | `O(1)`          | data + prev + next pointers              |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Node(int d)` | Constructor — creates node with data, both pointers = NULL |
| `InsertATHead(head, tail, d)` | Inserts at front, sets both pointers if empty |
| `insertATtail(tail, d)` | Appends to back using tail pointer |
| `insertAtposition(head, tail, position, d)` | Inserts at any position with full bidirectional linking |
| `print(head)` | Traverses forward and prints all values |
| `main()` | Builds list using all three operations, prints after each stage |

---

## 🔑 Singly vs Doubly — Insert at Position Differences

| Step | Singly Linked List        | Doubly Linked List                    |
|------|---------------------------|---------------------------------------|
| 1    | `nodeToInsert->next = temp->next` | `nodeToInsert->next = temp->next` |
| 2    | `temp->next = nodeToInsert` | `nodeToInsert->prev = temp`        |
| 3    | —                         | `temp->next->prev = nodeToInsert`     |
| 4    | —                         | `temp->next = nodeToInsert`           |
| Tail?| Not needed                | Update `tail` if inserting at end ✅  |

---

## 🖥️ Sample Output

```
50 40 30 20 10
50 40 30 20 10 60 70
50 40 100 30 20 10 60 70
```

---

## 🗺️ Doubly Linked List Operations Roadmap

```
✅ Insert at Head
✅ Insert at Tail
✅ Insert at Position      ← You are here
🔄 Delete at Head
🔄 Delete at Tail
🔄 Delete at Position
🔄 Reverse Traversal
```

---

## 📝 Key Takeaways

- Doubly Linked List insert at position needs **4 pointer updates** vs 2 in singly linked list.
- Always update `nodeToInsert->next` and `nodeToInsert->prev` **before** updating `temp->next`.
- Check `temp->next != NULL` to know if you're inserting at the **last position** — update `tail` if so.
- Position 1 is always a **special case** — no `prev` node exists.
- The `tail` pointer must be passed to `insertAtposition` so it can be updated when needed.
- All three operations together form a **complete doubly linked list** that can grow from both ends or the middle! 🧠

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists → Doubly Linked List Section* 🧠