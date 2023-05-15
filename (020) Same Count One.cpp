// Problem link: https://codeforces.com/problemset/problem/1774/D
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        int n, m; cin >> n >> m;
        vvi a(n, vi(m, 0));
        int tot = 0;
        vector<queue<int>> r(m);
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j]){
                    tot++;
                    r[j].push(i);
                    cnt[i]++;
                }
            }
        }
        if(tot % n) cout << -1 << '\n';
        else{
            int need = tot / n;
            vpipii ans;
            for(int i = 0; i < n; i++){
                int has = cnt[i];
                if(has < need){
                    for(int j = 0; j < m; j++){
                        if(cnt[i] >= need) break;
                        if(a[i][j] == 0){
                            while(true){
                                if(r[j].size() == 0) break;
                                int rr = r[j].front();
                                r[j].pop();
                                if(cnt[rr] > need){
                                    ans.pb({j + 1, {rr + 1, i + 1}});
                                    cnt[rr]--;
                                    a[rr][j] = 0;
                                    a[i][j] = 1;
                                    cnt[i]++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i].ss.ff << " " << ans[i].ss.ss << " " << ans[i].ff << '\n';
            }
        }
    }
}
