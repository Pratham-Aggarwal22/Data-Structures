#include <iostream>
#include <chrono>
using namespace std;

// Inefficient recursive algorithm
int inefficientFibonacci(int n) {
    if (n <= 1)  // If n = 0 or 1, return n only
    {
        return n;
    } 
    else 
    {
        return inefficientFibonacci(n - 1) + inefficientFibonacci(n - 2); // recursive call
    }
}

// Efficient algorithm using iterative approach
int efficientFibonacci(int n) {
    if (n <= 1)
    {
        return n;
    }
    int a = 0;
    int b = 1; // Initializing first two variables
    int result = 0;
    for (int i = 2; i <= n; ++i)
    {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Inefficient Fibonacci time calculation
    auto start1 = chrono::high_resolution_clock::now();
    int inefficientResult = inefficientFibonacci(n);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end1 - start1;

    // Efficient Fibonacci time calculation
    auto start2 = chrono::high_resolution_clock::now();
    int efficientResult = efficientFibonacci(n);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2;

    cout<<"\nInput: "<< n;
    cout<<"\nOutput: "<<endl;
    cout << "Inefficient Fibonacci: " << inefficientResult << endl;
    cout << "Efficient Fibonacci: " << efficientResult << endl;
    cout<<"Time: "<<endl;
    cout << "Inefficient algorithm: " << elapsed1.count() << " seconds" << endl;
    cout << "Efficient algorithm: " << elapsed2.count() << " seconds" << endl;

    return 0;
}
