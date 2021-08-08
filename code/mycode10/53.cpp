#include<bits/stdc++.h>

using namespace std;

#define N 100009
int tmp[N], a[N], b[N];
void change(int arr[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2, size = 0;
    for (int i = mid + 1; i <= end; ++i)
        tmp[++size] = arr[i];
    for (int i = begin; i <= mid; ++i)
        tmp[++size] = arr[i];
    for (int i = 0; i < size; ++i)
        arr[i + begin] = tmp[i + 1];
}

void sort(int arr[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    sort(arr, begin, mid);
    sort(arr, mid + 1, end);
    if (arr[begin] > arr[mid + 1])
        change(arr, begin, end);
}

int main() {
    srand(time(0));
    int n; scanf("%d", &n);

    int t = 3000, f;
    while (1) {
        for (int i = 0; i< n; i++) {
            a[i] = rand() % 1000000 + 1;
            b[i] = a[i];
        }
        sort(a, 0, n - 1);
        f = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                f = 1;
                break;
            }
        }
        if (f == 1) break;
    }
   
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    puts("");
}