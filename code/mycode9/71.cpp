#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100010
int main() {
    cout <<"������ʻ" << endl;
    char s[N];//���ַ�
    long long a[N],b[N],c[N];//���U S C
    long long i,j,n;//����ѭ���ı���
    long long t=0,r=0,u=0;//U S C�ĸ���
    long long cd,count=0;//���ȣ���������
    scanf("%s",&s);
    cd = strlen(s);//ȡ����
    j = 0;
    for ( i=cd-1; i > 3; i--) {
        if(s[i]=='U') {
            a[j]=i;
            j++;
        }
    }
    u=j+1; j=0;

    for(i=a[0];i>2;i--) {
        if(s[i]=='S') {
            b[j]=i;
            j++;
        }
    }
    r=j+1; j=0;
    for(i=b[0];i>1;i--) {
        if(s[i]=='C') {
            c[j]=i;
            j++;
        }
    }
    t=j+1;j=0;n=0;
    for( i=0; i<u; i++) {
        for(j=0;j<r&&b[j]<a[i];j++) {
            while(c[n]<b[j]&&n<t)
                n++;
            count=count+n*(n-1)/2;
        }
    }
    printf("%lld",count);
    return 0;
}
