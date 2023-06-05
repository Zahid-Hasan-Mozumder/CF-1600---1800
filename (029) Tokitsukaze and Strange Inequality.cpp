// Problem link: https://codeforces.com/contest/1677/problem/A

// For,   5 3 6 1 4 2

//      0 1 2 3 4 5 6       ----> Indices
// 0 -> 0 0 0 0 0 0 0       
// 1 -> 0 0 0 0 1 1 1       ^ v
// 2 -> 0 0 0 0 0 0 1       | a
// 3 -> 0 0 1 1 1 1 1       | l
// 4 -> 0 0 0 0 0 1 1       | u
// 5 -> 0 1 1 1 1 1 1       | e
// 6 -> 0 0 0 1 1 1 1       | s

//      0 1 2 3 4 5 6       ----> Indices
// 0 -> 0 0 0 0 0 0 0       
// 1 -> 0 0 0 0 1 1 1       ^ v
// 2 -> 0 0 0 0 1 1 2       | a
// 3 -> 0 0 1 1 2 2 3       | l
// 4 -> 0 0 1 1 2 3 4       | u
// 5 -> 0 1 2 2 3 4 5       | e
// 6 -> 0 1 2 3 4 5 6       | s

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        vi p(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        vvll smaller_value(n + 1, vll(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                smaller_value[p[i]][j] += 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n; j++){
                smaller_value[i][j] += smaller_value[i - 1][j];
            }
        }
        ll ans = 0;
        for(int b = 2; b < n - 1; b++){
            for(int c = b + 1; c < n; c++){
                ans += (smaller_value[p[c] - 1][b - 1] - smaller_value[p[c] - 1][0]) * (smaller_value[p[b] - 1][n] - smaller_value[p[b] - 1][c]);
            }
        }
        cout << ans << '\n';
    }
}
