#include<bits/stdc++.h>
using namespace std;

const int N = 40;

int a[N][N], b[N], n, s[N], e[N];

int gauss()
{
    int r,c;
    for(r=1,c=1;c<=n;c++) {
        // ����Ԫ
        int t = r;
        for(int i=r+1;i<=n;i++)
            if(a[i][c])
                t=i;
        if(!a[t][c])continue;//����֤Ψһ��--��һ������Ԫ
        // ������Ԫ����r��
        for(int i=c;i<=n+1;i++)swap(a[t][i],a[r][i]);
        // �õ�r�е�a[r][j]����i�е�a[i][j] ǰ���ǵ�i�е��������1(����Ԫ)
        for(int i=r+1;i<=n;i++)
            for(int j=n+1;j>=c;j--)
            //�ȼ���if(a[i][c]) a[i][j]^=a[r][j]
                a[i][j] ^= a[i][c] & a[r][j];
        //����дa[i][j] ^= a[i][r] & a[r][j];
        //����Ϊ���ܴ����м�����Ԫ����� ��ʱr��++�� c����ѭ����++ ����r!=c
        r++;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) f = 1;
        }
        if (f == 0 && a[i][n + 1] == 0) {
            res = res * 2;              // �����ɱ�Ԫ�ĸ���
        } else if (f == 0 && a[i][n + 1]) {
            return -1;
        }
    }
    return res; // ��ĸ�����
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    cout << gauss() << endl;
}