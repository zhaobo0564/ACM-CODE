#include<bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 1; i <= 256; i++) {
       
        for (int j =  1; j <= 256; j++) {
             if (i == j) continue;
             
                ans++;
            
        }
    }
    cout << ans << endl;
}