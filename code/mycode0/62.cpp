#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], n, t;
set<int> v;


int main(){
    scanf("%d", &t);
    while(t--){
        v.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            v.insert(a[i]);
        }
        a[n + 1] = a[1]; 
        if(v.size() == 1){
            printf("1\n");
            for(int i = 1; i <= n; i++){
                printf("1 ");
            }
            puts("");
        }else{
            if(n % 2 == 0){
                puts("2");
                for(int i = 1; i <= n; i += 2){
                    printf("1 2 ");
                }
                puts("");
            }else{
                int f = 0, f1 = 0;
                for(int i = 1; i <= n; i++){
                    if(a[i] == a[i + 1]){
                        f = i;
                        f1 = i + 1;
                        if(f1 == n + 1){
                            f1 = 1;
                        }
                        break;
                    }
                }
                if(f == 0){
                    puts("3");
                    for (int i = 1; i < n; i++){
                      printf("%d ", (i % 2) + 1);
                    }
                    puts("3");
                }else{
                    puts("2");
                    int cn = 0;
                    for(int i = 1; i <= n; i++){
                        if(i == f1){
                            printf("%d ", (i - 1) % 2 + 1);
                            cn++;
                            continue;
                        }
                        printf("%d ", (i +cn) % 2 + 1);
                    }
                    puts("");
                }
            }
        }
    }
}