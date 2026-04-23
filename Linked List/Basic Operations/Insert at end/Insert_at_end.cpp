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

void print(Node *head)
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

    print(head);

    return 0;
}