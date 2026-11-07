#include <iostream>

using namespace std;

class Queue {
private:
    int capacity;
    int head;
    int count;
    int* data;

    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        
        for (int i = 0; i < count; ++i) {
            newData[i] = data[(head + i) % capacity];
        }
        
        delete[] data;
        data = newData;
        head = 0;
        capacity = newCapacity;
        
        cout << "[System] Queue resized to capacity: " << capacity << "\n";
    }

public:
    Queue(int initialCapacity = 2) {
        capacity = initialCapacity;
        head = 0;
        count = 0;
        data = new int[capacity];
    }

    ~Queue() {
        delete[] data;
        data = nullptr;
    }

    // Konstruktor kopiujący wykonujący kopię głęboką
    Queue(const Queue& other) : capacity(other.capacity), head(other.head), count(other.count) {
        data = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            data[i] = other.data[i];
        }
    }

    // Operator przypisania wykonujący kopię głęboką
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            int* newData = new int[other.capacity];
            for (int i = 0; i < other.capacity; ++i) {
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            capacity = other.capacity;
            head = other.head;
            count = other.count;
        }
        return *this;
    }

    void enqueue(int value) {
        if (count == capacity) {
            resize();
        }
        int tail = (head + count) % capacity;
        data[tail] = value;
        count++;
        cout << "Added: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Removed: " << data[head] << endl;
        head = (head + 1) % capacity;
        count--;
    }

    int front() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[head];
    }

    bool isEmpty() const {
        return count == 0;
    }
    
    int size() const {
        return count;
    }

    void display() const {
        if (isEmpty()) {
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

void swapByValue(int a, int b) {
    int temp = a; a = b; b = temp;
}

void swapByPointer(int* a, int* b) {
    int temp = *a; *a = *b; *b = temp;
}

void swapByReference(int& a, int& b) {
    int temp = a; a = b; b = temp;
}

int sumRecursive(const int* arr, int n, int& calls) {
    calls++;
    if (n == 0) return 0;
    return *arr + sumRecursive(arr + 1, n - 1, calls);
}

void passByValue(Queue q) {
    cout << "Inside passByValue, queue size: " << q.size() << endl;
}

void passByReference(const Queue& q) {
    cout << "Inside passByReference, queue size: " << q.size() << endl;
}

void runDemos() {
    cout << "1. Pointers & References (Swap)" << endl;
    int a = 10, b = 20;
    cout << "Init: a=" << a << ", b=" << b << endl;
    swapByValue(a, b);
    cout << "After swapByValue: a=" << a << ", b=" << b << " (no change)" << endl;
    swapByPointer(&a, &b);
    cout << "After swapByPointer: a=" << a << ", b=" << b << " (changed)" << endl;
    swapByReference(a, b);
    cout << "After swapByReference: a=" << a << ", b=" << b << " (changed back)\n" << endl;

    cout << "2. Recursion with Pointer and Reference" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int recursionCalls = 0;
    int sum = sumRecursive(arr, 5, recursionCalls);
    cout << "Sum of array: " << sum << endl;
    cout << "Total recursive calls (via reference): " << recursionCalls << "\n" << endl;

    cout << "3. Passing Objects (Value vs Reference)" << endl;
    Queue demoQueue(2);
    demoQueue.enqueue(100);
    demoQueue.enqueue(200);
    passByValue(demoQueue);
    passByReference(demoQueue);
    cout << "Demo queue survived without memory corruption.\n" << endl;
}

int main(int argc, char const *argv[])
{
    runDemos();

    cout << "FIFO Queue Implementation (Circular Buffer)" << endl;
    Queue myQueue(2);
 
    while (true) {
        cout << "\n1. Add new" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Front" << endl;
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
                int frontValue = myQueue.front();
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