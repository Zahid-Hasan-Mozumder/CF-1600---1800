// Problem link: https://codeforces.com/contest/1730/problem/B
// video editorial: https://www.youtube.com/watch?v=JpItlEPYrao&t=583s
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        ll n; cin >> n;
        vector<double> x(n), rt(n);
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++) cin >> rt[i];
        double ans = -1;
        double low = 0, high = 2e18;
        int limit = 100;
        while(limit--){
            double mid = (low + high) / 2;
            vector<pair<double, double>> seg(n);
            for(int i = 0; i < n; i++){
                double travelTime = mid - rt[i];
                seg[i].ff = x[i] - travelTime;
                seg[i].ss = x[i] + travelTime;
            }
            bool crossed = false;
            double l = LLONG_MIN, r = LLONG_MAX;
            for(int i = 0; i < n; i++){
                l = max(l, seg[i].ff);
                r = min(r, seg[i].ss);
                if(l > r){
                    crossed = true;
                    break;
                }
            }
            if(crossed){
                low = mid;
            }
            else{
                ans = r;
                high = mid;
            }
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}
