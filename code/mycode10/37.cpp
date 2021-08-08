#include<bits/stdc++.h>
using namespace std;

bool judge(vector<int> &v) {
    for (int i = 0; i < v.size() / 2; i++) {
        if (v[i] != v[v.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

char s[100];

int main() {
    int n; cin >> n;
    for (int i = 0; i <= 9; i++) {
        s[i] = i + '0';
    }
    for (int i = 10; i <= 20; i++) {
        s[i] = 'A' + i - 10;
    }
    for (int i = 1; i <= 300; i++) {
        vector<int> v;
        
        int x = i * i;
        while (x) {
            v.push_back(x % n);
            x = x / n;
        }
        reverse(v.begin(), v.end());
        if (judge(v)) {
            vector<int> v1 = v;
            v.clear();
            
            x = i;
            while (x) {
                v.push_back(x % n);
                x = x / n;
            }
            reverse(v.begin(), v.end());
            for (int j: v) {
                cout << s[j];
            }
            cout << " ";
             for (int j: v1) {
                cout << s[j];
            }
            cout << endl;
        }


    }
    
}