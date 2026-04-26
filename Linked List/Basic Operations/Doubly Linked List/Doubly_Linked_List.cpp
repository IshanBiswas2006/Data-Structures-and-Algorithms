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

void InsertATHead(Node *&head, int d)
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

    InsertATHead(head, 10);
    InsertATHead(head, 20);
    InsertATHead(head, 30);
    InsertATHead(head, 40);
    InsertATHead(head, 50);

    print(head);
    return 0;
}