#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int vis[N];
 bool judge() {
        if (vis['n'] && vis['p'] && vis['y']) {
             return false;
         }
        return true;
    }
 int Maximumlength(string x) {
        // write code here
        
        int l = 0, r = 0, cnt = 0;
       
        for (int i = 0; i < x.length(); i++) {
               
            if (judge()) {

                while (r < x.length() ) {
                    vis[x[r]]++;
                    if (!judge()) {
                        break;
                    }
                    r++;
                }
            }
            
            cnt = max(cnt, r - i);
            vis[x[i]]--;
            
        }
        return cnt;
    }

int main() {
  string s;
  cin >> s;
  cout <<Maximumlength(s) << endl;
}