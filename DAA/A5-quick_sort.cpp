#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic Quick Sort
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort
void randomQuickSort(int a[], int low, int high) {
    if (low < high) {
        int randomIndex = low + rand() % (high - low + 1);
        swap(a[randomIndex], a[high]);
        int p = partition(a, low, high);
        randomQuickSort(a, low, p - 1);
        randomQuickSort(a, p + 1, high);
    }
}

int main() {
    srand(time(0));
    int n, a[100], b[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    quickSort(a, 0, n - 1);
    cout << "\nDeterministic Quick Sort:\n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    randomQuickSort(b, 0, n - 1);
    cout << "\nRandomized Quick Sort:\n";
    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
