// Problem link: https://codeforces.com/problemset/problem/1896/D
// Video explanation: https://www.youtube.com/watch?v=BF7xc6qHHpE
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

//const ll mod = 1e9 + 7;
const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

vll a, tree;

void build(int ind, int l, int r){
    if(l == r){
        tree[ind] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * ind + 1, l, m);
    build(2 * ind + 2, m + 1, r);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

void update(int ind, int l, int r, int i, ll v){
    if(l > i || r < i) return;
    if(l == r){
        a[l] = v;
        tree[ind] = v;
        return;
    }
    int m = (l + r) / 2;
    update(2 * ind + 1, l, m, i, v);
    update(2 * ind + 2, m + 1, r, i, v);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

ll calculate(int ind, int l, int r, int lll, int rrr){
    if(rrr < l || r < lll) return 0;
    if(lll <= l && r <= rrr) return tree[ind];
    int m = (l + r) / 2;
    return calculate(2 * ind + 1, l, m, lll, rrr) 
              + calculate(2 * ind + 2, m + 1, r, lll, rrr);
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
        ll n, q; cin >> n >> q;
        a.clear(); a.resize(n);
        tree.clear(); tree.resize(4 * n);
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1) mp[i] = 1;
        }
        build(0, 0, n - 1);
        while(q--){
            int typ; cin >> typ;
            if(typ == 1){
                ll x; cin >> x;
                ll sum = calculate(0, 0, n - 1, 0, n - 1);
                if(x > sum){
                    cout << "NO" << '\n';
                }
                else{
                    ll diff = sum - x;
                    if(diff & 1){
                        ll mx = 0;
                        if(mp.size()){
                            ll l = mp.begin()->ff;
                            l++;
                            ll r = n - 1;
                            if(l <= r) mx = max(mx, calculate(0, 0, n - 1, l, r));    
                            
                            l = 0;
                            r = mp.rbegin()->ff;
                            r--;
                            if(l <= r) mx = max(mx, calculate(0, 0, n - 1, l, r));    
                        }
                        if(x > mx) cout << "NO" << '\n';
                        else cout << "YES" << '\n';
                    }
                    else cout << "YES" << '\n';
                }
            }
            else{
                int i; ll v;
                cin >> i >> v;
                i--;
                if(a[i] != v){
                    if(a[i] == 1){
                        mp.erase(i);
                    }
                    else{
                        mp[i] = 1;
                    }
                }
                update(0, 0, n - 1, i, v);
            }
        }
    }
}
