#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> cnt(2e5, 0);
        vector<ll> dp(n+1, 0);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++) {
            cnt[v[i]] ++;
        }
        dp[0] = 0;
        dp[1] = cnt[1];
        for(ll i = 2; i <=n; i++) {
            dp[i] = max(i * cnt[i] + dp[i - 2], dp[i - 1]);
        }
        cout << dp[n];
    return 0;
}
