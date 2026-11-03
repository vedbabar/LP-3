
#include <iostream>
using namespace std;

// Recursive function
int fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative function
int fibIterative(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Recursive Fibonacci: ";
    for (int i = 0; i < n; i++){
        cout << fibRecursive(i) << " ";
    }
    cout << "\nIterative Fibonacci: ";
    for (int i = 0; i < n; i++){
        cout << fibIterative(i) << " ";
    }
    return 0;
}
