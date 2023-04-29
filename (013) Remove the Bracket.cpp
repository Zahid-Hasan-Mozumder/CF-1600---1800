// Problem link : https://codeforces.com/problemset/problem/1787/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define plpii pair<ll, pair<int, int>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const int mod = 1e9+7;
//const int mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int n, s;

ll depression(vvll &dp, vpll &x, ll i, ll j){
    if(i == n - 1) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = LLONG_MAX;
    if(j == 0){
        ans = min(ans, depression(dp, x, i + 1, 0) + x[i].ff * x[i + 1].ss);
        ans = min(ans, depression(dp, x, i + 1, 1) + x[i].ff * x[i + 1].ff);    
    }
    else{
        ans = min(ans, depression(dp, x, i + 1, 0) + x[i].ss * x[i + 1].ss);
        ans = min(ans, depression(dp, x, i + 1, 1) + x[i].ss * x[i + 1].ff);
    }
    return dp[i][j] = ans;
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

    int t; cin>>t;
    while(t--){
        cin >> n >> s;
        vll a(n);
        vvll dp(n, vll(2, -1));
        vpll x(n); 
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            if(i == 0){
                x[i].ff = a[i], x[i].ss = 0;
            }
            else if(i == n - 1){
                x[i].ff = a[i], x[i].ss = a[i];
            }
            else{
                if(s >= a[i]) x[i].ff = 0, x[i].ss = a[i];
                else x[i].ff = s, x[i].ss = a[i] - s;
            }
        }
        cout << depression(dp, x, 0, 0) << '\n';
    }
}
