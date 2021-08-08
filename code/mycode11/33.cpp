#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];

vector<int> v;

int main() {
    
    int n, k; cin >> n >> k;
    if (k == 0) {
        for (int i = 1; i <= n; i++ ) {
            printf("%d ", i);
        }
        puts("");
        return 0;
    }
    if (n == 2) {
        if (k == 0) {
            puts("1 2");
        } else {
            puts("-1");
        }
    } else if (n == 3) {
        if (k == 0) {
            puts("1 2 3");
        } else {
            puts("-1");
        }
    } else if (n == 4) {
        if (k == 0) {
            puts("1 2 3 4");
        } else if (k == 1) {
            puts("2 4 1 3");
        } else  {
            puts("-1");
        } 
    } else if (n == 5) {
        if (k == 0) {
            puts("1 2 3 4 5");
        } else if (k == 1) {
            puts("2 4 1 3 5");
        } else {
            puts("-1");
        }
    } else {
        if (k == n / 2) {
            for (int i = 2; i <= n; i += 2) {
                if (i == 6) continue;
             //   printf("%d ", i);
                v.push_back(i);
            }
          //  printf("6 3 ");
            v.push_back(6);
            v.push_back(3);
            for (int i = 1; i <= n; i += 2) {
                if (i == 3) continue;
             //   printf("%d ", i);
                v.push_back(i);
            }
        } else {
            //printf("2 ");
            v.push_back(2);
            int i = 4;
            for (i = 4; i <= n; i += 2) {
             //   printf("%d ", i);
                v.push_back(i);
                k--;
                if (k == 0) break;
            }
            for (int j = 1; j <= i; j += 2) {
             //   printf("%d ", j);
                v.push_back(j);
            }
            for (int j = i + 1; j <= n; j++) {
              //  printf("%d ", j);
                v.push_back(j);
            }
          
        }
        for (int I: v) {
            cout << I << " ";
        }
        cout << endl;
    }
   
  
    
 //   cout << ans << endl;
}