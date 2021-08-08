#include<bits/stdc++.h>
using namespace std;

int t, a[100], n;

vector<int>odd, even;

int main(){
    scanf("%d", &t);
    while(t--){
        odd.clear();
        even.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if(a[i] % 2 == 0){
                even.push_back(a[i]);
            }else{
                odd.push_back(a[i]);
            }
        }
        if(even.size() % 2 == 0 && odd.size() % 2 == 0){
            puts("Yes");
        }else if(even.size() % 2 == 0){
            puts("No");
        }else if(odd.size() % 2 == 0){
            puts("No");
        }else{
            int f = 0;
            for(int i = 0; i < odd.size(); i++){
                for(int j = 0; j < even.size(); j++){
                    if(abs(odd[i] - even[j]) == 1){
                        f = 1;
                        break;
                    }
                }
                if(f)break;
            }
            if(f){
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }
}