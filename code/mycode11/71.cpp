#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL &y){//��չŷ�������ax+by=gcd(a,b)�Ľ�
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    LL x1, y1, gcd = exgcd(b,a%b,x1,y1);
    x = y1, y = x1-a/b*y1;
    return gcd;
}
int main(){
    int n,has_ans=1;
    LL a1,m1,t;//��һ�����̵�ϵ�� ��������
    cin>>n;
    cin>>a1>>m1;//�������һ������
    for(int i = 2,a2,m2; i <= n; i++){//�ϲ���������n-1������
        cin>>a2>>m2;
        LL k01,k02,gcd = exgcd(a1,a2,k01,k02);
        if((m2-m1)%gcd){//��ʱ�޽�
            has_ans = 0;
            break;
        }
        k01 = k01*(m2-m1)/gcd;//�ؽ�
        k01 = (k01 % (a2/gcd) + a2/gcd) % (a2/gcd);//���ؽ�k01ȡ����С��������
        t = a1*a2/gcd;
        m1 += a1*k01;
        cout << m1 << endl;
        a1 = t;
    }
    if(has_ans) cout<<(m1%a1+a1)%a1<<endl;
    else cout<<-1<<endl;
    return 0;
}
