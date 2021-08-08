#include<iostream>
using namespace std;

int t,n;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int t1=2,ok=0;
		while(1){
			if(t1%2==0){
				if(n%t1==t1/2){
					ok=1;
					if(n>=(t1+1)*t1/2){
						int t2=(n-(t1+1)*t1/2)/t1;
						printf("%d = %d",n,t2+1);
						for(int i=1;i<t1;i++){
							printf(" + %d",t2+i+1);
						}
						printf("\n"); 
					}
					else{
						printf("IMPOSSIBLE\n");
					}
				}
			}
			else{
				if(n%t1==0){
					ok=1;
					if(n>=(t1+1)*t1/2){
						int t2=(n-(t1+1)*t1/2)/t1;
						printf("%d = %d",n,1+t2);
						for(int i=1;i<t1;i++){
							printf(" + %d",1+t2+i);
						}
						printf("\n");
					}
					else{
						printf("IMPOSSIBLE\n");
					}
				}
			}
			if(ok==1)break;
			if(t1>100000||t1>=n){
				printf("IMPOSSIBLE\n");
				break;
			}
			t1++;
		}
	}
	return 0;
}
