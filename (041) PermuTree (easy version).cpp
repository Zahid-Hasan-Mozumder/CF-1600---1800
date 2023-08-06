// Problem link: https://codeforces.com/contest/1856/problem/E1
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

int n; 
vvi al;
vvll tmp;
vll decend;

int dfs(int p, int i){
    decend[i] = 1;
    for(auto v : al[i]){
        if(v == p) continue;
        decend[i] += dfs(i, v);
        tmp[i].pb(decend[v]);
    }
    return decend[i];
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

    cin >> n;
    al.clear(); al.resize(n + 1);
    tmp.clear(); tmp.resize(n + 1);
    decend.clear(); decend.resize(n + 1, 0);
    for(int i = 2; i <= n; i++){
        int v; cin >> v;
        al[i].pb(v);
        al[v].pb(i);
    }
    dfs(-1, 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int m = tmp[i].size();
        if(m <= 1) continue;
        sort(tmp[i].begin(), tmp[i].end());
        ll sum = accumulate(tmp[i].begin(), tmp[i].end(), 0ll);
        vll dp(sum + 1, 0);
        dp[0] = 1;
        for(int j = 0; j < m; j++){
            for(int k = sum; k >= 1; k--){
                if(k - tmp[i][j] < 0) break;
                dp[k] += dp[k - tmp[i][j]];
            }
        }
        ll mx = 0;
        for(int j = 1; j <= sum; j++){
            if(dp[j]){
                mx = max(mx, j * (sum - j));
            }
        }
        ans += mx;
    }
    cout << ans << '\n';
}
