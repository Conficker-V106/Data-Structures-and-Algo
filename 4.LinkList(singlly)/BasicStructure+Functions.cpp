#include <iostream>

using namespace std;

struct Node {
    int key;
    int data;
    Node* next;
    Node(int k, int d) : key(k), data(d), next(nullptr) {}
};
void appendNode(Node*& head, int key, int data) {
    Node* newNode = new Node(key, data);
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
void prependNode(Node*& head, int key, int data) {
    Node* newNode = new Node(key, data);
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key) {
            cout << "Node with key " << key << " already exists. Please use a different key." << endl;
            delete newNode; 
            return;
        }
        temp = temp->next;
    }
    newNode->next = head;
    head = newNode;
}
void deleteNode(Node*& head, int key) {
    Node* del = head;
    Node* prev = nullptr;
    if (del != nullptr && del->key == key) {
        head = del->next;
        delete del;
        return;
    }
    while (del != nullptr && del->key != key) {
        prev = del;
        del = del->next;
    }
    if (del == nullptr) {
        cout << "Node with key " << key << " not found." << endl;
        return;
    }
    prev->next = del->next;
    delete del;
}

void updateNode(Node* head, int key, int new_data) {
    Node* ptr = head;
    while (ptr != nullptr && ptr->key != key) {
        ptr = ptr->next;
    }
    if (ptr != nullptr) {
        ptr->data = new_data;
    } else {
        cout << "Node with key " << key << " not found." << endl;
    }
}
void insertNodeAtPosition(Node*& head, int key, int data, int position) {
    Node* newNode = new Node(key, data);
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int currentPosition = 0;
        while (temp != nullptr && currentPosition < position - 1) {
            temp = temp->next;
            currentPosition++;
        }
        if (temp == nullptr) {
            cout << "Position exceeds the length of the list." << endl;
            delete newNode; 
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    appendNode(head, 1, 20);
    appendNode(head, 2, 1);
    appendNode(head, 3, 2);
    appendNode(head, 4, 5);

    prependNode(head, 5, 25);
    prependNode(head, 6, 10);

    deleteNode(head, 3);

    updateNode(head, 6, 30);

    insertNodeAtPosition(head, 7, 99, 2);
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ----> ";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
