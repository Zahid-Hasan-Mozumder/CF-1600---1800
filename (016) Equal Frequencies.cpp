// Problem link : https://codeforces.com/problemset/problem/1781/C
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
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vi d;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                d.pb(i);
                if(n / i != i) d.pb(n / i);
            }
        }
        int mn = INT_MAX;
        string ans;
        for(int i = 0; i < d.size(); i++){
            if(n / d[i] > 26) continue;
            int need = n / d[i];
            int op = 0;
            
            string tmp = s;
            vvi ind(26);
            map<int, int> mp;
            for(int j = 0; j < n; j++){
                ind[tmp[j] - 'a'].pb(j);
                mp[tmp[j] - 'a']++;
            }
            int has = mp.size();
            
            if(need < has){
                vpii a;
                for(auto it : mp){
                    a.pb({it.ss, it.ff});
                }
                sort(a.begin(), a.end());
                vi x;
                for(int j = 0; j < has - need; j++){
                    op += a[j].ff;
                    for(auto it : ind[a[j].ss]) x.pb(it);
                }
                for(int j = has - need; j < has; j++){
                    if(a[j].ff > d[i]){
                        op += a[j].ff - d[i];
                        for(int l = d[i]; l < a[j].ff; l++){
                            x.pb(ind[a[j].ss][l]);
                        }
                    }
                }
                int l = 0;
                for(int j = has - need; j < has; j++){
                    while(ind[a[j].ss].size() < d[i]){
                        ind[a[j].ss].pb(x[l]);
                        tmp[x[l]] = a[j].ss + 'a';
                        l++;
                    }
                }
                //cout<< d[i] << " " << op << " " << tmp << '\n';
                if(op < mn){
                    mn = op;
                    ans = tmp;
                }
            }
            else{
                vpii a;
                for(auto it : mp){
                    a.pb({it.ss, it.ff});
                }
                vi x;
                for(int j = 0; j < a.size(); j++){
                    if(a[j].ff > d[i]){
                        for(int l = d[i]; l < a[j].ff; l++){
                            x.pb(ind[a[j].ss][l]);
                        }
                        op += a[j].ff - d[i];
                    }
                }
                int l = 0;
                for(int j = 0; j < a.size(); j++){
                    if(a[j].ff > 0 && a[j].ff < d[i]){
                        while(ind[a[j].ss].size() < d[i]){
                            ind[a[j].ss].pb(x[l]);
                            tmp[x[l]] = a[j].ss + 'a';
                            l++;
                        }
                    }
                }
                for(int j = 0; j < 26; j++){
                    if(ind[j].size() == 0 && l < x.size()){
                        while(ind[j].size() < d[i]){
                            ind[j].pb(x[l]);
                            tmp[x[l]] = j + 'a';
                            l++;
                        }
                    }
                }
                //cout<< d[i] << " " << op << " " << tmp << '\n';
                if(op < mn){
                    mn = op;
                    ans = tmp;
                }
            }
        }
        cout << mn << '\n';
        cout << ans << '\n';
    }
}
