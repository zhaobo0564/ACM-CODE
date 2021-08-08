#include<bits/stdc++.h>
using namespace std;

int t, n;
vector<int>v;

long long lcm(long long x, long long y) {
    return x * y / __gcd(x, y);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        v.clear();
        scanf("%d", &n);
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                v.push_back(i);
                if(n / i != i) {
                    v.push_back(n / i);
                }
            }
        }

        int a = -1, b;
        long long minn = LLONG_MAX;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size() - 1; i++) {

            long long cnt = lcm(v[i], n - v[i]);
            if (minn > cnt) {
                minn = cnt;
                a = v[i];
                b = n - v[i];
            }
            
        }
    
        printf("%d %d\n", a, b);

    }
}