#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int l,int h){
    int pivot = v[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[h]);
    return i+1;
}

void quickSort(vector<int>&v,int l,int h){
    if(l<h){
        int p=partition(v,l,h);
        quickSort(v,l,p-1);
        quickSort(v,p+1,h);
    }
}
void rand_quickSort(vector<int>&v,int l,int h){
    if(l<h){
        int r = l+rand()%(h-l+1);
        swap(v[r],v[h]);
        int p=partition(v,l,h);
        rand_quickSort(v,l,p-1);
        rand_quickSort(v,p+1,h);
    }
}
int main() {
    srand(time(0));
    int n;
    vector<int>a(n),b(n);
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
    rand_quickSort(b, 0, n - 1);
    cout << "\nRandomized Quick Sort:\n";
    for (int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
