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
    if (tail == NULL)
    {
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertATHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);

    if (head == NULL)
    {
        head = tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtposition(Node* &head,Node* &tail, int position, int d)
{
    if(position == 1)
    {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if(temp == NULL)
    {
        cout << "Position out of range\n";
        return;
    }

    Node* nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    nodeToinsert->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = nodeToinsert;
    }
    else
    {
        tail = nodeToinsert;
    }

    temp->next = nodeToinsert;
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

    print(head);

    insertATtail(tail, 60);
    insertATtail(tail, 70);

    print(head);

    insertAtposition(head,tail,3,100);

    print(head);

    return 0;
}