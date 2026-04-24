# 🔗 Linked List — Insert at Position

## 📌 What is Insert at Position?

**Insert at Position** places a new node at a **specific index** in the linked list — not just at the beginning or end. It is the most **flexible** insertion operation, handling all cases:

- Position 1 → Insert at **beginning**
- Position n → Insert at **middle**
- Position > size → **Out of range** error

> Think of it like inserting a new person into a specific spot in a queue — everyone from that spot onward shifts back by one.

---

## 🧠 How It Works

### Case 1 — Insert at Position 1 (Beginning)
```
List: 10->20->30->40->NULL
Insert 50 at position 1

  temp = new Node(50)
  temp->next = head  →  [50 | •]──→[10 | •]──→[20 | •]──→...
  head = temp        →  head now points to 50

Result: 50->10->20->30->40->NULL ✅
```

### Case 2 — Insert at Middle Position
```
List: 10->20->30->40->NULL
Insert 50 at position 2

Step 1: Traverse to node BEFORE position 2 (i.e. position 1)
        temp stops at [10]

Step 2: Create new node
        nodeToInsert = new Node(50) → [50 | NULL]

Step 3: nodeToInsert->next = temp->next
        [50 | •]──→[20 | •]──→[30 | •]──→[40 | NULL]

Step 4: temp->next = nodeToInsert
        [10 | •]──→[50 | •]──→[20 | •]──→[30 | •]──→[40 | NULL]

Result: 10->50->20->30->40->NULL ✅
```

### Case 3 — Position Out of Range
```
List has 4 nodes, insert at position 10
  temp reaches NULL before position-1
  → Print "Position out of range" ✅
```

---

## 💡 Key Insight — Stop at `position - 1`

```
To insert at position P, you need to stop at node (P-1)
because you need access to the node BEFORE the gap:

Position: 1    2    3    4
          ↓    ↓    ↓    ↓
         [10]─[20]─[30]─[40]─NULL

Insert at position 2:
  Stop at position 1 (node with 10)
  Link: 10 → 50 → 20 → 30 → 40
             ↑
         new node slides in between
```

---

## 💻 Code — `linked_list_insert_position.cpp`

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
};

void insertAtposition(Node *&head, int position, int d)
{
    // Case 1: Insert at beginning
    if (position == 1)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
        return;
    }

    // Case 2: Traverse to node just before target position
    Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Case 3: Position out of range
    if (temp == NULL)
    {
        cout << "Position out of range\n";
        return;
    }

    // Insert new node between temp and temp->next
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;   // New node points to next node
    temp->next = nodeToinsert;          // Previous node points to new node
}

void insertAtEnd(Node *&head, Node *&end, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        end = temp;
    }
    else
    {
        end->next = temp;
        end = temp;
    }
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
    Node *end = NULL;

    insertAtEnd(head, end, 10);
    insertAtEnd(head, end, 20);
    insertAtEnd(head, end, 30);
    insertAtEnd(head, end, 40);

    print(head);                        // 10->20->30->40->NULL

    insertAtposition(head, 2, 50);      // Insert 50 at position 2

    print(head);                        // 10->50->20->30->40->NULL

    return 0;
}
```

---

## 🔍 Step-by-Step Execution Trace

```
Build list using insertAtEnd:
  head ──→ [10 | •]──→[20 | •]──→[30 | •]──→[40 | NULL] ←── end

print → 10->20->30->40->NULL

─────────────────────────────────────────────
insertAtposition(head, 2, 50):

  position != 1 → skip Case 1

  Traverse to position - 1 = 1:
    temp = head → points to [10]
    count = 1
    count < position-1? → 1 < 1? → NO → stop immediately
    temp is at node [10] ✅

  temp != NULL → no out of range error

  nodeToInsert = new Node(50) → [50 | NULL]

  nodeToInsert->next = temp->next → [50 | •]──→[20 | •]──→...
  temp->next = nodeToInsert      → [10 | •]──→[50 | •]──→[20 | •]──→...

  Final list:
  head ──→ [10 | •]──→[50 | •]──→[20 | •]──→[30 | •]──→[40 | NULL]

print → 10->50->20->30->40->NULL ✅
```

---

## 📊 Complexity Analysis

| Operation              | Time Complexity | Explanation                                    |
|------------------------|-----------------|------------------------------------------------|
| **Insert at pos 1**    | `O(1)`          | Just update head pointer                       |
| **Insert at pos P**    | `O(P)`          | Traverse P-1 nodes to reach target             |
| **Insert at end**      | `O(n)`          | Traverse entire list (without `end` pointer)   |
| **Out of range check** | `O(n)`          | Traverses until NULL                           |
| **Space per Node**     | `O(1)`          | Each node stores data + one pointer            |

---

## 🧩 Function Breakdown

| Function | Purpose |
|---|---|
| `insertAtposition(head, position, d)` | Inserts node at given position, handles all 3 cases |
| `insertAtEnd(head, end, d)` | Appends node to tail using `end` pointer |
| `print(head)` | Traverses and prints list as `data->data->NULL` |
| `main()` | Builds 4-node list, inserts at position 2, prints both states |

---

## 🔑 The Two Critical Pointer Steps

```cpp
nodeToinsert->next = temp->next;   // Step 1: Connect NEW node forward FIRST
temp->next = nodeToinsert;          // Step 2: Connect PREVIOUS node to new node
```

> ⚠️ **Order matters!** If you do Step 2 first, you lose the reference to the next node — creating a broken list.

```
WRONG ORDER:
  temp->next = nodeToInsert        ← lost reference to [20]!
  nodeToInsert->next = temp->next  ← now points to nodeToInsert itself! ❌

CORRECT ORDER:
  nodeToInsert->next = temp->next  ← save reference to [20] first ✅
  temp->next = nodeToInsert        ← then link previous node ✅
```

---

## 🖥️ Sample Output

```
10->20->30->40->NULL
10->50->20->30->40->NULL
```

---

## 🆚 All Three Insertion Types — Compared

| Operation           | Position    | Time     | Needs `end`? | Traversal     |
|---------------------|-------------|----------|--------------|---------------|
| Insert at Beginning | Always 1st  | `O(1)`   | ❌           | None          |
| Insert at End       | Always last | `O(1)`   | ✅ Yes       | None          |
| Insert at Position  | Any index   | `O(P)`   | ❌           | P-1 nodes     |

---

## 🗺️ Linked List Operations Roadmap

```
✅ Insert at Beginning
✅ Insert at End
✅ Insert at Position     ← You are here
🔄 Delete at Beginning
🔄 Delete at End
🔄 Delete at Position
🔄 Search in Linked List
🔄 Reverse a Linked List
🔄 Detect a Cycle
```

---

## 📝 Key Takeaways

- Insert at Position handles **all insertion cases** in one function.
- Always **traverse to position - 1** — you need the node before the gap.
- **Position 1 is a special case** — handled separately since there's no previous node.
- The **order of pointer updates** is critical — connect forward first, then backward.
- Always check for **out-of-range positions** to prevent crashes.
- This combines the logic of both Insert at Beginning and Insert at End! 🧠

---

*Part of the [DSA Learning Repository](../../README.md) — Linked Lists Section* 🧠