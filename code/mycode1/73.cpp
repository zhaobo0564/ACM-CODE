#include<iostream>
using namespace std;

int t,n;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n%2==1){
			printf("n=%d+%d\n",n/2,n/2+1);
		}
		else{
			if(n%3==0){
				printf("n=%d+%d+%d\n",n/3-1,n/3,n/3+1);
			}
			else if(n%3==1){
				if(n>=10){
					printf("n=%d+%d+%d+%d\n",n/4-1,n/4,n/4+1,n/4+2);
				}
				else{
					printf("IMPOSSIBLE\n");
				}
			}
			else{
				if(n>=15){
					printf("n=%d+%d+%d+%d+%d\n",n/5-2,n/5-1,n/5,n/5+1,n/5+2);
				}
				else{
					printf("IMPOSSIBLE\n");
				}
			}
		}
	}
}
