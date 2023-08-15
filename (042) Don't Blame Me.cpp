// Problem link: https://codeforces.com/problemset/problem/1829/H
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define pipll pair<int, pair<ll, ll>>
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvi vector<vector<vector<int>>>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

ll POW_MOD(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW_MOD(a, b/2);
    if(b&1) return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
    else return ((x % mod) * (x % mod)) % mod;
}

int n, k;
vi a;
vvll dp;

ll depression(int i, int x){
    if(i == n){
        int sb = 0;
        int tmp = x;
        while(tmp){
            if(tmp & 1) sb++;
            tmp >>= 1;
        }
        if(sb == k) return 1;
        else return 0;
    }
    if(dp[i][x] != -1) return dp[i][x];
    ll res = 0;
    res += depression(i + 1, (x & a[i]));
    res %= mod;
    res += depression(i + 1, x);
    res %= mod;
    return dp[i][x] = res;
}

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        a.clear(); a.resize(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        dp.clear(); dp.resize(n + 1, vll(65, -1));
        if(k == 6){
            ll cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == 63) cnt++;
            }
            cout << POW_MOD(2, cnt) - 1 << '\n';
        }
        else{
            cout << depression(0, 63) << '\n';
        }
    }
}
