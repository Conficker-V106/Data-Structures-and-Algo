#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void appendNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void moveEvenBeforeOdd(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;
    Node* current = head;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    if (evenHead == nullptr) {
        head = oddHead;
    } else {
        evenTail->next = oddHead;
        head = evenHead;
    }

    if (oddTail != nullptr) {
        oddTail->next = nullptr;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "------>";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    appendNode(head, 17);
    appendNode(head, 15);
    appendNode(head, 8);
    appendNode(head, 12);
    appendNode(head, 10);
    appendNode(head, 5);
    appendNode(head, 4);
    appendNode(head, 1);
    appendNode(head, 7);
    appendNode(head, 6);

    cout << "List Before:" << endl;
    printList(head);

    moveEvenBeforeOdd(head);

    cout << "List After:" << endl;
    printList(head);

    while (head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
