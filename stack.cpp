#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int _value) {
            value = _value;
            next = NULL;
        }

        Node(int _value, Node* _node) {
            value = _value;
            next = _node;
        }
};

void push(Node* &head, Node* &tail, int value) {
    Node* node = new Node(value);
    if (node == NULL) {
        cout << "Stack overflow!\n";
        return;
    }
    if (head == NULL) head = node;
    if (tail != NULL) tail->next = node;
    tail = node;
}

void pop(Node* &head, Node* &tail) {
    if (head == tail) {
        head = tail = NULL;
        return;
    }
    Node* tempHead = head;

    while (tempHead->next != tail) tempHead = tempHead->next;

    delete tail;
    tail = tempHead;
    tail->next = NULL;
}

void display(Node* &head) {
    Node *tempHead = head;
    vector<int> result;

    while (tempHead != NULL) {
        result.push_back(tempHead->value);
        tempHead = tempHead->next;
    }

    for (int i = result.size() - 1; i >= 0; i--) cout << "|\t" << result[i] <<"\t|\n";
}

int main() {
    Node* head = NULL;
    Node* tail = head;

    while (true) {
        int choice;

        cout << "Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice:\t";

        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter a value:\t";
                int value;
                cin >> value;
                push(head, tail, value);
                break;
            case 2:
                if (head != NULL) pop(head, tail);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Wrong choice\n";
                break;
        }
    }

    return 0;
}
