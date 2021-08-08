#include<iostream>
using namespace std;
int a[1000000]={1};
int b[1000000]={1};
int main(){
	int m;
	while(cin>>m){
		for(int i=0;i<1000000;i++){
			b[i]=1;
		}
		int max=0;
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		for(int i=1;i<m;i++){
			for(int j=0;j<i;j++)
			if(a[i]>a[j]){
				//b[i]=b[j]+1;	
                b[i] = max(b[i], b[j] + 1);
			}
		}
		for(int i=0;i<m;i++){
			if(b[i]>max)max=b[i];
		}
		cout<<max<<endl;
	}
}
