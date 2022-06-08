#include<iostream>
using namespace std;

class Queue {
    int *arr;
    int head;
    int tail;
    int n;

    public:
        Queue(int n) { 
            this->n = n;
            arr = new int[n]; 
            head = tail = -1;
        }

        void enqueue(int value) {
            if (head == (tail + 1) % n) {
                cout << "Queue is full\n";
                return;
            } 
            if (head == -1) head = 0;
            tail = (tail + 1) % n;
            arr[tail] = value;
        }

        void dequeue() {
            if (head == -1) {
                cout << "No one is here to be served!";
                return;
            }
            if (head == tail) head = tail = -1;
            else head = (head + 1) % n;
            cout << "One customer served";
        }

        void display() {
            if (head == -1) {
                cout << "No one is waiting at Pizza shop\n";
                return;
            }
            
            for (int i = head; i != tail; i = (i + 1) % n) {
                cout << arr[i] << " -- ";
            }
            cout << arr[tail];  
        }
};

int main() {
    int size;
    cout << "Enter the size of queue:\t";
    cin >> size;

    Queue* queue = new Queue(size);

    while (true) {
        int choice;
        cout << "\n\nMenu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice:\t";
        cin >> choice;

        switch (choice) {
            case 0:
                exit(0);
                break;
            case 1:
                int value;
                cout << "Enter customer id:\t";
                cin >> value;
                queue->enqueue(value);
                break;
            case 2:
                queue->dequeue();
                break;
            case 3:
                queue->display();
                break;
            default:
                cout << "Wring choice!\n";
                break;
        }
    }

    return 0;
}
