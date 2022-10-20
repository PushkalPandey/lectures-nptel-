#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define mii map<int, int>
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps fixed << setprecision(y) << x
bool isSquare(int x)
{
    int y = sqrt(x);
    return y * y == x;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    return (ceil(log2(n)) == floor(log2(n)));
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}
ll computeXOR1ton(ll n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}
ll countSetBits(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += (n & 1);
        n >> 1;
    }
    return ans;
}
int getIthBit(ll n, ll i)
{
    ll mask = (1 << i);
    int ans = ((n & i) > 0) ? 1 : 0;
    return ans;
}
void setIthBit(ll &n, ll i)
{
    ll mask = (1 << i);
    n = n | mask;
}
void clearIthBit(ll &n, ll i)
{
    ll mask = ~(1 << i);
    n = n & mask;
}
void updateIthBitWithv(ll &n, ll i, ll v)
{
    clearIthBit(n, i);
    ll mask = v << i;
    n = n | mask;
}
void clearLeftIBits(ll &n, ll i)
{
    ll mask = (~0) << i;
    n = n & mask;
}
void clearRangeItoJBits(ll &n, ll i, ll j) // from rigth i to j left
{
    ll ma = (~0) << (j + 1);
    ll mb = ~((~0) << i);
    ll mask = ma | mb;
    n = n & mask;
}
ll power_opt(ll a, ll n)
{
    ll ans = 1;
    while (n > 0)
    {
        int lst_bit = (n & 1);
        if (lst_bit)
        {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}
int *parent, *rnk;
void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}
void DisjSet(int n)
{
    rnk = new int[n];
    parent = new int[n];
    makeSet(n);
}
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void Union(int x, int y)
{
    int xset = find(x);
    int yset = find(y);
    if (xset == yset)
        return;
    if (rnk[xset] < rnk[yset])
    {
        parent[xset] = yset;
    }
    else if (rnk[xset] > rnk[yset])
    {
        parent[yset] = xset;
    }
    else
    {
        parent[yset] = xset;
        rnk[xset] = rnk[xset] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
        ll m, n;
        ll s1=0, s2=0, c1=0, c2=0;
        cin>>m;
        vector<ll> a1(m);
        for(ll i=0; i<m; i++)
        {
            cin>>a1[i];
            c1+=a1[i];
            s1=max(s1, c1);
        }
        cin>>n;
        vector<ll> a2(n);
        for(ll i=0; i<n; i++)
        {
            cin>>a2[i];
            c2+=a2[i];
            s2=max(s2, c2);
        }
        cout<<s1+s2<<endl;
    }
    return 0;
}
