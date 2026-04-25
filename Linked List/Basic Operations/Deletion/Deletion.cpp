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
    if (head == NULL)
        return;

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node *current = head;
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
    current->next = NULL;
    delete current;
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

    print(head);

    Delete(head, 2);

    print(head);

    return 0;
}