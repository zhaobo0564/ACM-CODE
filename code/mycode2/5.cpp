#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int t, a[N], n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int l = 1, r = n; 
        int aa = 0, b = 0, maxn = 0, op = 1;
        while(1){
        //    cout << "maxn " << maxn << endl;
        //     for(int i = l; i <= r; i++ ){
        //         cout << a[i] << " ";
        //     }
          // cout << endl;
            if(op % 2 == 1){
                int sum = 0, f= 0;
                for(int i = l ; i <= r; i++){
                    sum += a[i];
                 //   cout << "sum = " << sum << " maxn = " << maxn << endl;
                    if(sum> maxn){
                        f = 1;
                        aa += sum;
                        l = i + 1;
                        break;
                    }
                }
                if(f == 0){
                    aa += sum;
                    break;
                }
                maxn = sum;
            }else{
                int sum = 0, f = 0;
                for(int i = r; i >= l; i--){
                    sum += a[i];
                    if(sum > maxn){
                        r = i - 1;
                        b += sum;
                        f = 1;
                        break;
                    }
                }
                if(f == 0){
                    b += sum;
                    break;
                }
                maxn = sum;
            }
            if(l > r)break;
            op++;
        }
    
        printf("%d %d %d\n", op, aa, b);
    

    }
}