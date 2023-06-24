// Problem link: https://codeforces.com/contest/1842/problem/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const int N = 2e5 + 5;
const int sz = 1e6 + 2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int n;
vvi dp;
vi r;

int depression(int i, int state){
    if(i == n) return 0;
    if(dp[i][state] != -1) return dp[i][state];
    int res = 0;
    if(state){
        if(r[i] != -1){
            res = max(res, depression(r[i], 1) + (r[i] - i));
        }
        res = max(res, depression(i + 1, 0));
    }
    else{
        if(r[i] != -1){
            res = max(res, depression(r[i], 1) + (r[i] - i + 1));
        }
        res = max(res, depression(i + 1, 0));
    }
    return dp[i][state] = res;
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
        cin >> n;
        vi last(n + 1, - 1);
        r.clear(); r.resize(n, -1);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(last[x] != -1){
                r[last[x]] = i;
            }
            last[x] = i;
        }
        dp.clear(); dp.resize(n + 1, vi(2, -1));
        int mx = 0;
        mx = depression(0, 0);
        cout << mx << '\n';
    }
}
