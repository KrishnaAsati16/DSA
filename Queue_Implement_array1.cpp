//  // enqueue -> push operation
//  //dequeue-> pop operation

#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int frontIndex;
    int rear;
    int size;

public:
    Queue() {
        size = 10001;
        arr = new int[size];
        frontIndex = 0;
        rear = 0;
    }

    // enqueue -> push
    void enQ(int data) {
        if (rear == size)
         {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
        arr[rear] = data;
        rear++;
        }
}

    // dequeue -> pop
    int deQ() {
        if (frontIndex == rear) 
        {
            return -1;
        }
        else
        {
        int ans = arr[frontIndex];
        frontIndex++;

        if (frontIndex == rear) {
            frontIndex = 0;
            rear = 0;
        }
        return ans;
        }
}

    // front element
    int front() {
        if (frontIndex == rear) 
        {
            return -1;
        }
        else
        {
        return arr[frontIndex];
     }
}

    // is empty
    bool isEmpty() {
        if(frontIndex==rear)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};

int main() {

    Queue q;

    q.enQ(10);
    q.enQ(20);
    q.enQ(30);

  //  cout << "Front element: " << q.front() << endl;

   // cout << "Deleted: " << q.deQ() << endl;

    //cout << "Deleted: " << q.deQ() << endl;

    cout << "Front element: " << q.front() << endl;

    cout << "Is queue empty? " << q.isEmpty() << endl;

    cout << "Deleted: " << q.deQ() << endl;

    cout << "Is queue empty? " << q.isEmpty() << endl;

    return 0;


}


