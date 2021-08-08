#include<bits/stdc++.h>
using namespace std;
const int N = 100007;
int a[N], n;

void heapfy(int a[], int len, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxIdx = index;
    if (left < len && a[left] > a[maxIdx]) {
        maxIdx = left;
    }
    if (right < len && a[right] > a[maxIdx]) {
        maxIdx = right;
    }
    if (maxIdx != index) {
        swap(a[maxIdx], a[index]);
        heapfy(a, len, maxIdx);
    }
}

void heapSort(int a[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        heapfy(a, size, i);
    }
 
    for (int i = size - 1; i >= 1; i--) {
        swap(a[0], a[i]);
        heapfy(a, i, 0);
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    heapSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}