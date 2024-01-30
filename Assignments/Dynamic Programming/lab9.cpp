#include <iostream>
#include<climits>
#include <vector>

using namespace std;

void printParenthesis(int i, int j, vector<vector<int>>& bracket, char& matrixName) {
    // Base case: if i and j point to the same matrix, print its name and increment matrixName
    if (i == j) {
        cout << matrixName++;
        return;
    }

    // Print opening parenthesis and recursively print optimal parenthesization inside
    cout << "(";
    printParenthesis(i, bracket[i][j], bracket, matrixName);

    // Recursively print optimal parenthesization for the second part
    printParenthesis(bracket[i][j] + 1, j, bracket, matrixName);

    // Print closing parenthesis
    cout << ")";
}


void matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;

    // m[i][j] will store the minimum number of scalar multiplications needed to compute the product A[i]A[i+1]...A[j]
    vector<vector<int>> m(n, vector<int>(n, 0));

    // bracket[i][j] will store the index of the matrix after which the product is split in the optimal parenthesization
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    // Initialization
    for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;

        // Initialize the minimum cost for multiplying matrices from i to j
        m[i][j] = INT_MAX;

        // Iterate through all possible positions to split the product and find the minimum cost
        for (int k = i; k < j; k++) {
            // Calculate the cost of parenthesizing at position k
            int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];

            // Update the minimum cost and the corresponding splitting position if a lower cost is found
            if (cost < m[i][j]) {
                m[i][j] = cost;
                bracket[i][j] = k;
            }
        }
    }
}

    // Print the optimal parenthesization
    char matrixName = 'A';
    cout << "Optimal Parenthesization is : ";
    printParenthesis(0, n - 1, bracket, matrixName);
    cout << endl;

    // Print the optimal cost
    cout << "Optimal Cost is : " << m[0][n - 1] << endl;
}

int main() {
    // Sample Input 1
    vector<int> p1 = {10, 20, 30, 40, 30};
    cout << "Sample Input 1: [10,20,30,40,30]\n";
    matrixChainOrder(p1);
    cout << "\n";

    // Sample Input 2
    vector<int> p2 = {4, 10, 3, 12, 20, 7};
    cout << "Sample Input 2: [4,10,3,12,20,7]\n";
    matrixChainOrder(p2);
    cout<<"\n";
    
    // Sample Input 3
    vector<int> p3 = {10, 20, 80, 2, 16, 13};
    cout << "Sample Input 3: [10,20,80,2,16,13]\n";
    matrixChainOrder(p3);

    return 0;
}
