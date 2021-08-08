#include<bits/stdc++.h>
using namespace std;

int t, n;

string s;

stack<int> q;
deque <int> g;

int main() {
    ios::sync_with_stdio(0);
    cin >> t;

    while (t--) {
        g.clear();
        cin >> s;
        n = s.length();
        for (int i = 0; i < s.length(); i++) {
           if(s[i] == '*') {
               g.push_back(i);
               continue;
           } 
           if (q.empty()) {
               q.push(i);
           } else {
               if (s[q.top()] == '(') {
                   if (s[i] == ')') {
                       q.pop();
                   } else {
                       q.push(i);
                   }
               } else {
                   q.push(i);
               }
           }
            
        }
        if (q.empty()) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '*') continue;
                cout << s[i];
            }
            cout << '\n';
        } else {
            vector<int>v;
            while (!q.empty()) {
                v.push_back(q.top());
                q.pop();
            }
            int f = 0;
             for (int i = 0; i < v.size(); i++) {
               if (s[v[i]] == '(') {
                   if (g.size() == 0) {
                       f = 1;
                       break;
                   }
                    int cd = g.back();
                    if (cd > v[i]) {
                        s[cd] = ')';
                        g.pop_back();
                    } else {
                        f = 1;
                        break;
                    }
                    
                }
            }

            reverse(v.begin(), v.end());

            for (int i = 0; i < v.size(); i++) {
                 if (s[v[i]] == ')') {
                    if (g.size() == 0) {
                       f = 1;
                       break;
                   }
                    int cd = g.front();
                    if (cd < v[i]) {
                        s[cd] = '(';
                        g.pop_front();
                    } else {
                        f = 1;
                        break;
                    }
                } 
            }

           

            
            if (f) {
                cout << "No solution!\n";
            } else {
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] == '*') continue;
                    cout << s[i];
                }
                cout << '\n';
            }
        }
     

    }
} 