#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	freopen("input.txt", "r", stdin);   //ֻ�ı����������ļ�ָ�룬��������ļ������ݣ�����Ҫ��input����ļ���stdin�Ǳ�׼���������ļ�ָ��
	freopen("output.txt", "w", stdout); 
	int n = 1e5, q = 1e5;
	cout << n << ' ' << q << endl;
	int d = 1, c = 0, s = 1e9, t = 0;
	ll ans = 0;
	map<int, ll> mp;
	for (int i = 1; i <= n; ++i)
	{
		if (t) //Ϊ�����Ӳ�ѯ���
		{
			cout << s / d - t << ' ';
			++mp[s / d - t];
			ans = max(ans, mp[s / d - t] * (s / d - t));
			--t;
		}
		else
		{
			cout << s / d << ' ';
			++mp[s / d];
			ans = max(ans, mp[s / d] * (s / d));
			if (++c == d) //Ϊ���ò�ѯsqrt��
			{
				++d, c = 0, ++s;
				while (s % d)
					++s;
				t = 128;
			}
		}
	}
	cout << endl;
	--q;
	int l = 0, r = n - 1;
	cout << l << ' ' << r << endl;
	l = 0, r = 0;
	while ((l ^ ans) % n != 0) //ÿ�β�ѯ1~n
		++l;
	while ((r ^ ans) % n != n - 1)
		++r;
	while (q--)
		cout << l << ' ' << r << endl;

	return 0;
}