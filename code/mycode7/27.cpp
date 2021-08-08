#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

char s[N];
int n, k;

int main() {
    scanf("%s %d", s + 1, &k);
    n = strlen(s + 1);
    vector<char> ans;
  
    int snow = 0, ca = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') {
            snow++;
        } else if (s[i] == '?') {
            ca++;
        } else {
            len++;
        }
    }
    if (len == k) {
        for (int i = 1; i <= n; i++) {
            if (s[i] == '*' || s[i] == '?') {
                continue;
            } else {
                ans.push_back(s[i]);
            }
        }
     
    } else if (len > k) {
        int cnt = len - k;
        for (int i = 1; i <= n; i++) {
            if (cnt && i < n && (s[i + 1] == '?' || s[i + 1] == '*')) {
                cnt--;
                continue;
            } else if (s[i] == '?' || s[i] == '*') {
                continue;
            } else {
                ans.push_back(s[i]);
            }
        }
      
    } else {
        int cnt = k - len;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '?' ) {
                continue;
            } else if (cnt && i > 1 && s[i] == '*') {
                for (int j = 1; j <= cnt; j++) {
                   ans.push_back(s[i - 1]);
                }
                cnt = 0;
            } else if (s[i] == '*') {
                continue;
            } else if (s[i] != '*'  && s[i] != '?') {
                ans.push_back(s[i]);
            }
    
        }
   
 
    }
    if (ans.size() != k) {
        cout << "Impossible\n";
    } else {
        for (auto i: ans) {
            cout << i;
        }
        cout << endl;
    }
    
}


