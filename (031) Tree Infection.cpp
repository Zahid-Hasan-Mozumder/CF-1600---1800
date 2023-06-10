// Problem link: https://codeforces.com/problemset/problem/1665/C
// Video editorial: https://www.youtube.com/watch?v=4CZNYIF2nJY
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        vvi al(n + 1);
        for(int i = 2; i <= n; i++){
            int x; cin >> x;
            al[x].pb(i);
            al[i].pb(x);
        }
        vll group;
        group.pb(1);
        for(int i = 1; i <= n; i++){
            if(i == 1){
                if(al[i].size()){
                    group.pb(al[i].size());
                }
            }
            else{
                if(al[i].size() > 1){
                    group.pb(al[i].size() - 1);
                }
            }
        }
        sort(group.rbegin(), group.rend());
        ll ans = -1;
        ll low = 1, high = n + 1;
        while(low <= high){
            ll mid = (low + high) / 2;
            ll rem = 0;
            for(int i = 0; i < group.size(); i++){
                rem += max(0ll, group[i] + i - mid);
            }
            if(rem + group.size() <= mid){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}
