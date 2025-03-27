#include<iostream>

struct Node {
public:
    int data;
    Node* next;


    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

   void  insertAtHead(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    void insertAtTail(int data) {
        Node *newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        }

        Node *temp = head;

        while (temp != nullptr) {
         temp = temp->next;
         newNode->next = head;
         head = newNode;
        }
    }
        void printList() {
        Node* temp = head;

        while (temp != nullptr) {
            std::cout << temp->data << "<->";
            temp = temp->next;
        }

    }

};


int main()
{
    LinkedList myLL;

    myLL.insertAtHead(0);
    myLL.insertAtTail(1);

    myLL.printList();
}
