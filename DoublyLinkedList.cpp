#include<iostream>
using namespace std;

class Node {
    public:
        int coefficient;
        int exponent;
        Node* previous;
        Node* next;

        Node(int coefficient, int exponent) { 
            this->coefficient = coefficient;
            this->exponent = exponent;
            previous = NULL;
            next = NULL;
        }
};

void insertAtTail(Node* &head, Node* &tail, int coefficient, int exponent) {
    if (head == NULL) {
        head = new Node(coefficient, exponent);
        tail = head;
    } else {
        Node* node = new Node(coefficient, exponent);
        node->previous = tail;
        tail->next = node;
        tail = tail->next;
    }
}

void insertAtHead(Node* &head, Node* &tail, int coefficient, int exponent) {
    if (head == NULL) {
        head = new Node(coefficient, exponent);
        tail = head;
    } else {
        Node* node = new Node(coefficient, exponent);
        node->next = head;
        head->previous = node;
        head = head->previous;
    }
}

void getPolynomial(Node* &head, Node* &tail) {
    int coefficient;
    bool addExponent;
    int exponent;
    int addMore;
    while (true) {
        cout << "Enter the coefficient:\t";
        cin >> coefficient;
        cout << "Do you want to add exponent?:\t";
        cin >> addExponent;
        if (addExponent) {
            cout << "Enter the exponent:\t";
            cin >> exponent;
        }
        insertAtTail(head, tail, coefficient, addExponent ? exponent : 0);
        cout << "You want to add more numbers?\n(1: Yes, 0: No)\t";
        cin >> addMore;
        if (addMore == 0) break;
    }
}

Node* add(Node* &tail1, Node* &tail2) {
    Node* head = NULL;
    Node* tail = NULL;
    while (tail1 != NULL && tail2 != NULL) {
        if (tail1->exponent == tail2->exponent) {
            insertAtHead(head, tail, tail1->coefficient + tail2->coefficient, tail1->exponent);
            tail1 = tail1->previous;
            tail2 = tail2->previous;
        } else if (tail1->exponent > tail2->exponent) {
            insertAtHead(head, tail, tail2->coefficient, tail2->exponent);
            tail2 = tail2->previous;
        } else if (tail1->exponent < tail2->exponent) {
            insertAtHead(head, tail, tail1->coefficient, tail1->exponent);
            tail1 = tail1->previous;
        }
    }
    while (tail1 != NULL) {
        insertAtHead(head, tail, tail1->coefficient, tail1->exponent);
        tail1 = tail1->previous;
    }
    while (tail2 != NULL) {
        insertAtHead(head, tail, tail2->coefficient, tail2->exponent);
        tail2 = tail2->previous;
    }
    return head;
}

void displaySum(Node* &head, char var) {
    while (head != NULL) {
        cout << abs(head->coefficient);
        if (head->exponent >= 1) cout << var;
        if (head->exponent > 1) cout << "^" << head->exponent;
        head = head->next;
        if (head != NULL) cout << ((head->coefficient < 0) ? " - " : " + ");
    }
    cout << "\n";
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    cout << "Enter first polynomial:\n";
    getPolynomial(head1, tail1);
    cout << "\nEnter second polynomial:\n";
    getPolynomial(head2, tail2);

    Node* ans = add(tail1, tail2);

    char var;
    cout << "Enter the variable:\t";
    cin >> var;
    displaySum(ans, var);

    return 0;
}

/*
2
1
2
1
3
1
1
1
2
0
0
3
1
2
1
-5
1
1
1
-1
0
0

5x^2 - 2x + 1
*/
