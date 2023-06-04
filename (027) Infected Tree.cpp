// Problem link: https://codeforces.com/problemset/problem/1689/C
/-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int n;
vi child;
vvi al;
vll dp;

int dfs(int p, int i){
    int cnt = 0;
    vi cc;
    for(auto v : al[i]){
        if(v == p) continue;
        cc.pb(v);
        cnt += (dfs(i, v) + 1);
    }
    if(cc.size() == 0){
        dp[i] = 0;
    }
    else if(cc.size() == 1){
        dp[i] = child[cc[0]];
    }
    else if(cc.size() == 2){
        dp[i] = max(dp[i], child[cc[0]] + dp[cc[1]]);
        dp[i] = max(dp[i], child[cc[1]] + dp[cc[0]]);
    }
    return child[i] = cnt;
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
        child.clear(); 
        al.clear();
        dp.clear();
        
        cin >> n;
        child.resize(n + 1, 0); 
        al.resize(n + 1);
        dp.resize(n + 1, -1);
        
        for(int i = 0; i < n - 1; i++){
            int u, v; cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
        }
        dfs(-1, 1);
        cout << dp[1] << '\n';
    }
}
