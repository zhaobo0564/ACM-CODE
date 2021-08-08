#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, a[N];

int find_pos(int l, int r) {
    cout << "l = " << l << " r = " << r << endl;
    int i = l, j = r;
    int x = (l + r) / 2;
    cout << "x = " << x << "  " << a[x] << endl;
    while (i <= j) {
        if (i == x) {
            i++;
            continue;
        }
        if (j == x) {
            j--;
            continue;
        }
        while (i < j && a[i] < a[x]) {
            if (i == x) {
                i++;
                continue;
            }
            i++;
        } 
        while (i < j && a[j] > a[x]) {
            if (j == x) {
                j--;
                continue;
            }
            j--;
        }
        if (i < j) {
            cout << "i = " << i << " j = " << j << endl;
            swap(a[i], a[j]);
            i++;
            j--;
        } else {
            break;
        }
    }
    cout << "j = " << j << "x = " << x << endl;
    cout << a[j] << " " << a[x] << endl;
    swap(a[x], a[j]);
    cout << a[j] << " " << a[x] << endl;
    return j;
}

void qsort(int l, int r) {
    if (l >= r) return;
    int pos = find_pos(l, r);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "pos = " << pos << endl;
    qsort(l, pos - 1);
    qsort(pos + 1, r);
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    qsort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}