// Problem link: https://codeforces.com/problemset/problem/1702/E
// Video tutorial: https://www.youtube.com/watch?app=desktop&v=A4NStCwPZ-Q
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

void dfs(vvi &al, vi &color, bool &flag, int curr, int c){
    color[curr] = c;
    for(auto v : al[curr]){
        if(color[v] == -1){
            dfs(al, color, flag, v, c ^ 1);
        }
        else{
            if(color[curr] == color[v]){
                flag = false;
                return;
            }
        }
    }
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
        int n; cin >> n;
        vvi al(n + 1);
        vi color(n + 1, -1);
        vi deg(n + 1, 0);
        bool flag = true;
        for(int i = 0; i < n; i++){
            int u, v; cin >> u >> v;
            al[u].pb(v);
            al[v].pb(u);
            deg[u]++;
            deg[v]++;
            // As we have only two sets but some value appeared more than 2 pairs,
            // so, it is unable to place them uniquely in the two sets.
            if(deg[u] > 2 || deg[v] > 2){
                flag = false;
            }
        }
        if(flag){
            for(int i = 1; i <= n; i++){
                if(color[i] == -1){
                    dfs(al, color, flag, i, 0);
                }
            }
            if(flag) cout << "Yes" << '\n';
            else cout << "No" << '\n';    
        }
        else cout << "No" << '\n';
    }
}
