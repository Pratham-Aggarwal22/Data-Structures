#include <iostream>
using namespace std;

class Stack {
private:
    int arr[10];
    int top;

public:
    // Constructor
    Stack() {
        top = 0; 
    }


    void push(int value) {
        if (top < 9)  // Checking if the stack is not full
        {
            arr[top++] = value; // Incrementing top by 1 and giving it a value from the parameter
        } 
        else 
        {
            cout << "STACK IS FULL!" << endl; // if stack is full
        }
    }

    void pop() {
        if (top > 0)  // Checking if the stack is not empty
        {
            arr[--top]; // Decrementing the top (Pointing to the next lower element)
            cout << "Popped item is: " << arr[top] << endl;  // printing the last element of array
            // The element even after popping remians in the array but is removed from active stack.
             
        } 
        else 
        {
            cout << "STACK IS EMPTY!" << endl;
        }
    }

    void peek() {
        if (top > 0)
        {
            cout << "Peeked item is: " << arr[top-1] << endl; // printing the top element of stack
        } 
        else 
        {
            cout << "STACK IS EMPTY!" << endl;
        }
    }

    void print() {
        if (top > 0) {
            cout << "Items in the stack: ";
            for (int i = top-1; i >= 0; --i) // Looping through bottom to top of the ARRAY. 
            {
                cout << arr[i];
                if (i != 0) 
                {
                    cout << ", ";
                }
            }
            cout << endl;
        } 
        else 
        {
            cout << "STACK IS EMPTY" << endl;
        }
    }
};

int main() 
{
    Stack stack;
    
    stack.push(20);
    stack.push(40);
    stack.push(60);
    stack.push(70);

    stack.print();
    
    stack.pop();
    
    stack.peek();
    
    stack.print();

    return 0;
}
