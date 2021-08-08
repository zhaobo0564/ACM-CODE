#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int x[N];

vector<int> v;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (m--) {
        int l, r; scanf("%d %d", &l, &r);
        x[l]++;
        x[r + 1]--;
    }
    for (int i = 1; i < N - 1; i++) {
        x[i] += x[i - 1]; 
        if (x[i] > 0) {
            v.push_back(x[i]);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int one = n / 10;
 
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
    

}