// Problem link: https://codeforces.com/problemset/problem/1810/D
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        ll l = 0LL, r = LLONG_MAX;
        int q; cin >> q;
        while(q--){
            int qt; cin >> qt;
            if(qt == 1){
                ll a, b, n; 
                cin >> a >> b >> n;
                ll x = a - b;
                ll curr_l = (n - 1 > 0) ? x * (n - 1) + b + 1 : 1LL;
                ll curr_r = x * (n - 1) + a;
                if(curr_r < l || curr_l > r){
                    cout << 0;
                }
                else{
                    cout << 1;
                    l = max(l, curr_l);
                    r = min(r, curr_r);
                } 
            }
            else{
                ll a, b;
                cin >> a >> b;
                ll x = a - b;
                if((ll)ceil(max(0LL, l - a) * 1.0 / x) == (ll)ceil(max(0LL, r - a) * 1.0 / x)){
                    cout<< (ll)ceil(max(0LL, l - a) * 1.0 / x) + 1LL;
                }
                else{
                    cout<< -1;
                }
            }
            cout<< " ";
        }
        cout<< '\n';
    }
}
