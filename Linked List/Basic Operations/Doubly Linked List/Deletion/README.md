# 🗑️ Doubly Linked List — Delete at Position

## 📌 What is This?

This program demonstrates **deletion at a specific position** in a **Doubly Linked List**. It properly removes a node and updates **both** `prev` and `next` pointers of surrounding nodes — keeping the bidirectional chain intact.

> Think of it like removing a carriage from a train — you disconnect it from both the carriage in front AND behind, then close the gap so the train stays connected in both directions.

---

## 🆚 Singly vs Doubly Linked List Deletion

| Step | Singly Linked List         | Doubly Linked List                        |
|------|----------------------------|-------------------------------------------|
| 1    | `previous->next = current->next` | `previous->next = current->next`    |
| 2    | —                          | `current->next->prev = previous`          |
| 3    | `current->next = NULL`     | `current->next = NULL`                    |
| 4    | —                          | `current->prev = NULL`                    |
| 5    | `delete current`           | `delete current`                          |
| Head?| Update `head`              | Update `head` + fix `head->prev = NULL` ✅|

---

## 🧠 How Delete at Position Works

### Case 1 — Delete at Position 1 (Head)
```
List: 5<->4<->3<->2<->1<->NULL

Delete position 1:
  current = head = [5]

  head = current->next      → head now points to [4]
  head->prev = NULL         → [4]'s prev disconnected ✅
  current->next = NULL      → [5] fully isolated
  delete current            → memory freed

Result: 4<->3<->2<->1<->NULL ✅
```

### Case 2 — Delete at Middle Position
```
List: 5<->4<->3<->2<->1<->NULL
Delete position 3 → delete node [3]

  Traverse: previous=[4], current=[3]

  Step 1: previous->next = current->next  → [4]──→[2]
  Step 2: current->next->prev = previous  → [2]'s prev = [4]
          Now: [4]⟷[2] ✅
  Step 3: current->next = NULL            → isolate [3] forward
  Step 4: current->prev = NULL            → isolate [3] backward
  Step 5: delete current                  → memory freed

Result: 5<->4<->2<->1<->NULL ✅
```

### Case 3 — Delete Last Node
```
  current->next == NULL → skip step 2 (no next node to update)
  previous->next = NULL → previous becomes new tail ✅
```

### Case 4 — Empty List or Out of Range
```
  head == NULL → return immediately
  current == NULL → position exceeded list size → return
```

---

## 💡 Key Insight — `head->prev = NULL` After Head Deletion

In a **singly linked list**, deleting the head only needs:
```cpp
head = head->next;
```

In a **doubly linked list**, you also need:
```cpp
head = current->next;
if (head != NULL)
    head->prev = NULL;   // ← critical! New head has no previous node ✅
```

> Without this, the new head's `prev` still points to the deleted node — a **dangling pointer**! ⚠️

---

## 💻 Code — `doubly_ll_delete.cpp`

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
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Delete(Node *&head, int position)
{
    if (head == NULL) return;             // Case 4: Empty list

    Node *current = head;

    if (position == 1)                    // Case 1: Delete head
    {
        head = current->next;             // Move head forward
        if (head != NULL)
            head->prev = NULL;            // Fix new head's prev pointer
        current->next = NULL;             // Isolate deleted node
        delete current;                   // Free memory
        return;
    }

    Node *previous = NULL;
    int count = 1;

    // Traverse to target position
    while (count < position && current != NULL)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) return;          // Case 4: Out of range

    previous->next = current->next;       // Step 1: bridge forward gap

    if (current->next != NULL)
        current->next->prev = previous;   // Step 2: bridge backward gap

    current->next = NULL;                 // Step 3: isolate forward
    current->prev = NULL;                 // Step 4: isolate backward
    delete current;                       // Step 5: free memory
}

void insert_at_head(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL) { head = temp; return; }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

int main()
{
    Node *head = NULL;

    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    insert_at_head(head, 4);
    insert_at_head(head, 5);

    print(head);           // 5<->4<->3<->2<->1<->NULL

    Delete(head, 3);       // Delete node at position 3

    print(head);           // 5<->4<->2<->1<->NULL

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
── BUILD LIST ──────────────────────────────────────────

insert_at_head(1) → [NULL|1|NULL]
insert_at_head(2) → [NULL|2|•]⟷[•|1|NULL]
insert_at_head(3) → [NULL|3|•]⟷[•|2|•]⟷[•|1|NULL]
insert_at_head(4) → [NULL|4|•]⟷[•|3|•]⟷[•|2|•]⟷[•|1|NULL]
insert_at_head(5) → [NULL|5|•]⟷[•|4|•]⟷[•|3|•]⟷[•|2|•]⟷[•|1|NULL]

print → 5<->4<->3<->2<->1<->NULL

── DELETE POSITION 3 ───────────────────────────────────

position != 1 → skip head deletion

Traverse:
  count=1: previous=NULL,  current=[5]
  count=2: previous=[5],   current=[4]
  count=3: previous=[4],   current=[3]  → count == position → STOP

current = [3], previous = [4], current->next = [2]

Step 1: previous->next = current->next  → [4]──→[2]
Step 2: current->next != NULL           → [2]->prev = previous = [4]
        Now: [4]⟷[2] ✅
Step 3: current->next = NULL            → [3] forward link cut
Step 4: current->prev = NULL            → [3] backward link cut
Step 5: delete current                  → [3] memory freed

Final: [NULL|5|•]⟷[•|4|•]⟷[•|2|•]⟷[•|1|NULL]

print → 5<->4<->2<->1<->NULL ✅
```

---

## 🌟 Full Pointer State Visualized

```
BEFORE deletion:

NULL ← [5] ⟷ [4] ⟷ [3] ⟷ [2] ⟷ [1] → NULL
                      ↑
                 to be deleted

AFTER deletion:

NULL ← [5] ⟷ [4] ⟷ [2] ⟷ [1] → NULL
                  ↑
              gap closed in both directions ✅

[3] → completely isolated → [NULL|3|NULL] → deleted
```

---

## 📊 Complexity Analysis

| Operation               | Time Complexity | Explanation                              |
|-------------------------|-----------------|------------------------------------------|
| **Delete at pos 1**     | `O(1)`          | Direct head pointer update               |
| **Delete at pos P**     | `O(P)`          | Traverse P nodes to reach target         |
| **Delete last node**    | `O(n)`          | Traverse entire list                     |
| **Out of range**        | `O(n)`          | Traverses until NULL                     |
| **Space**               | `O(1)`          | No extra memory — freeing reduces usage  |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `Delete(head, position)` | Removes node at given position, updates both prev and next pointers |
| `insert_at_head(head, d)` | Inserts new node at front of list |
| `print(head)` | Traverses and prints list with `<->` arrows showing bidirectional links |
| `main()` | Builds 5-node list, deletes position 3, prints both states |

---

## 🔑 Variable Roles in Delete()

| Variable   | Role |
|------------|------|
| `current`  | Points to the **node being deleted** |
| `previous` | Points to the node **just before** current |
| `count`    | Tracks current traversal position |

---

## 🖥️ Sample Output

```
5<->4<->3<->2<->1<->NULL
5<->4<->2<->1<->NULL
```

> Notice the `<->` arrows in `print()` — they visually represent the **bidirectional** nature of the doubly linked list! 🔗

---

## ⭐ Two Critical `NULL` Checks

```cpp
// Check 1 — After deleting head
if (head != NULL)
    head->prev = NULL;        // New head has no previous node

// Check 2 — After deleting middle node
if (current->next != NULL)
    current->next->prev = previous;   // Only if next node exists
```

> Skipping either check causes **dangling pointers** — one of the most dangerous bugs in C++! ⚠️

---

## 🗺️ Doubly Linked List Operations Roadmap

```
✅ Insert at Head
✅ Insert at Tail
✅ Insert at Position
✅ Delete at Position      ← You are here
🔄 Delete at Head
🔄 Delete at Tail
🔄 Reverse Traversal
```

---

## 📝 Key Takeaways

- Doubly LL deletion needs **5 steps** vs 3 in singly — both `prev` and `next` must be cleaned.
- Always fix `head->prev = NULL` after deleting the head node — prevents dangling pointer.
- Check `current->next != NULL` before updating `current->next->prev` — last node has no next.
- Set **both** `current->next = NULL` and `current->prev = NULL` before `delete` — fully isolates the node.
- The `<->` in `print()` visually confirms bidirectional linking is working correctly.
- Proper memory management with `delete` prevents **memory leaks** in C++. 🔐

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists → Doubly Linked List Section* 🧠