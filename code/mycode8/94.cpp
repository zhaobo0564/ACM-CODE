#include<bits/stdc++.h>
using namespace std;

string s;

stack<char> q;

int main() {
    int n;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        if (q.size() < 2) {
            q.push(s[i]);
        } else {
            char fi = q.top();
            q.pop();
            char se = q.top();
            if (se == 'f' && fi == 'o' && s[i] == 'x') {
                q.pop();
            } else {
                q.push(fi);
                q.push(s[i]);
            }
        }
        
    }
    cout << q.size() << endl;
}