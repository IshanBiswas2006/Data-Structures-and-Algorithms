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
    if (head == NULL)
        return;

    Node *current = head;

    if (position == 1)
    {
        head = current->next;

        if (head != NULL)
            head->prev = NULL;

        current->next = NULL;
        delete current;
        return;
    }

    Node *previous = NULL;
    int count = 1;

    while (count < position && current != NULL)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    previous->next = current->next;

    if (current->next != NULL)
        current->next->prev = previous;

    current->next = NULL;
    current->prev = NULL;
    delete current;
}

void insert_at_head(Node *&head, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        return;
    }
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

    print(head);

    Delete(head, 3);

    print(head);

    return 0;
}