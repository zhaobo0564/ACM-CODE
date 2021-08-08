#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
inline void write(__int128 x){
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
__int128 fn[500];

int main() {
    fn[1] = fn[2] = 1;
    for (int i = 3; i <= 490; i++) {
        fn[i] = fn[i - 1] + fn[i - 2];
    }
    int n;
    while (~scanf("%d", &n) && n >= 0) {
        printf("Hour: %d: ", n);
        write(fn[n]);
        printf("cow(s) affected\n");
    }
}