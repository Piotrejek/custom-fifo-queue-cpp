#include <iostream>

using namespace std;

class Queue {
private:
    int capacity;
    int head;
    int count;
    int* data;

public:
    Queue(int initialCapacity = 5) {
        capacity = initialCapacity;
        head = 0;
        count = 0;
        data = new int[capacity];
    }

    ~Queue() {
        delete[] data;
        data = nullptr;
    }

    // TODO: Implement copy constructor and assignment operator (Rule of Three) to prevent shallow copy
    // TODO: Implement dynamic resizing when queue is full

    void enqueue(int value) {
        if (count == capacity) {
            cout << "Queue is full! (Resizing not implemented yet)" << endl;
            return;
        }
        int tail = (head + count) % capacity;
        data[tail] = value;
        count++;
        cout << "Added: " << value << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Removed: " << data[head] << endl;
        head = (head + 1) % capacity;
        count--;
    }

    int peek() const {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[head];
    }

    void display() const {
        if (count == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; ++i) {
            cout << data[(head + i) % capacity] << " ";
        }
        cout << "\n(Capacity: " << capacity << ", Size: " << count << ")" << endl;
    }
};

// TODO: Add reference and pointer demonstration functions (swap, recursion)

int main(int argc, char const *argv[])
{
    cout << "FIFO Queue Implementation" << endl;
    Queue myQueue(5);
 
    while (true) {
        cout << "\n1. Add new" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value: ";
                cin >> value;
                myQueue.enqueue(value);
                break;
            }
            case 2:
                myQueue.dequeue();
                break;
            case 3: {
                int frontValue = myQueue.peek();
                if (frontValue != -1) {
                    cout << "Front value: " << frontValue << endl;
                }
                break;
            }
            case 4:
                myQueue.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Choose a valid option" << endl;
                break;
        }
    }
    
    return 0;
}