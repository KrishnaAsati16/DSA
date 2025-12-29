#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* first = nullptr;
int countNodes = 0;

// Initialize list
void init() {
    first = nullptr;
    countNodes = 0;
}

// Create first node
void createFirst(int val) {
    first = new Node;
    first->data = val;
    first->next = first;
    countNodes = 1;
}

// Add node at end
void addNode(int val) {
    if (!first) {
        createFirst(val);
        return;
    }

    Node* temp = first;
    while (temp->next != first) {
        temp = temp->next;
    }

    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = first;
    temp->next = newNode;

    countNodes++;
}

// Display circular list
void display() {
    if (!first) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = first;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != first);

    cout << endl;
}

// Josephus logic
void JOSH(int n) {
    if (!first || n <= 0) return;

    Node* temp = first;
    Node* prev = nullptr;

    while (countNodes > 1) {
        for (int i = 1; i < n; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == first)
            first = first->next;

        prev->next = temp->next;
        delete temp;
        temp = prev->next;
        countNodes--;
    }

    cout << "\nWinner is: " << first->data << endl;
}

int main() {
    int choice, value, lucky;

    init();

    cout << "Enter data for first node: ";
    cin >> value;
    createFirst(value);

    while (true) {
        cout << "\nMenu\n";
        cout << "1. Add Node\n";
        cout << "5. Josephus\n";
        cout << "6. Display\n";
        cout << "12. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                addNode(value);
                break;

            case 5:
                cout << "Enter lucky number (< " << countNodes << "): ";
                cin >> lucky;
                JOSH(lucky);
                break;

            case 6:
                display();
                break;

            case 12:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
