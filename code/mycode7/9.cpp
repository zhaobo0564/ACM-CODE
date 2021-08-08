#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD 1000000007

ll powmod(ll a, ll k)
{
  ll x = 1;
  while (k > 0)
  {
    if (k % 2 == 1)
    {
      x = x * a % MOD;
    }
    a = a * a % MOD;
    k /= 2;
  }
  return x;
}

int main()
{
  ll H, W;
  cin >> H >> W;
  vector<string> S(H);

  for (ll i = 0; i < H; i++)
  {
    cin >> S[i];
  }

  ll terashi[H][W] = {};
  for (ll i = 0; i < H; i++)
  {
    for (ll j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
      {
        terashi[i][j] = 1;
      }
    }
  }

  for (ll i = 0; i < H; i++)
  {
    ll cnt = 0;
    for (ll j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
      {
        terashi[i][j] += cnt;
        cnt++;
      }
      else
      {
        cnt = 0;
      }
    }
  }

  for (ll i = 0; i < H; i++)
  {
    ll cnt = 0;
    for (ll j = W - 1; j >= 0; j--)
    {
      if (S[i][j] == '.')
      {
        terashi[i][j] += cnt;
        cnt++;
      }
      else
      {
        cnt = 0;
      }
    }
  }

  for (ll j = 0; j < W; j++)
  {
    ll cnt = 0;

    for (ll i = 0; i < H; i++)
    {
      if (S[i][j] == '.')
      {
        terashi[i][j] += cnt;
        cnt++;
      }
      else
      {
        cnt = 0;
      }
    }
  }

  for (ll j = 0; j < W; j++)
  {
    ll cnt = 0;

    for (ll i = H - 1; i >= 0; i--)
    {
      if (S[i][j] == '.')
      {
        terashi[i][j] += cnt;
        cnt++;
      }
      else
      {
        cnt = 0;
      }
    }
  }

  ll N = 0;
  for (ll i = 0; i < H; i++)
  {
    for (ll j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
        N++;
    }
  }

  ll sum = 0;
  for (ll i = 0; i < H; i++)
  {
    for (ll j = 0; j < W; j++)
    {
      if (S[i][j] == '.')
      {
        ll tmp = (MOD + powmod(2, terashi[i][j]) - 1) % MOD;
        tmp = tmp * powmod(2, N - terashi[i][j]);
        sum = (sum + tmp) % MOD;
      }
    }
  }

  cout << sum << endl;
}