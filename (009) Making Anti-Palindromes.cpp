// Problem link: https://codeforces.com/contest/1822/problem/E
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int MOD = 998244353;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

bool cmp(pii &a, pii &b){
    if(a.ss == b.ss)
        return a.ff < b.ff;
    return a.ss > b.ss;
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
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        if(n & 1) cout<< -1 << '\n';
        else{
            map<char, int> mp;
            bool flag = true;
            for(int i=0; i<n; i++){
                mp[s[i]]++;
                if(mp[s[i]] > n/2){
                    flag = false;
                }
            }
            if(flag){
                mp.clear();
                int i=0, j = n-1;
                while(i < j){
                    if(s[i] == s[j]){
                        mp[s[i]]++;
                    }
                    i++;
                    j--;
                }
                vi a;
                for(auto it : mp){
                    a.pb(it.ss);
                }
                if(a.size() == 0) cout<< 0 << '\n';
                else{
                    sort(a.begin(), a.end());
                    int sum = 0;
                    for(int k=0; k<a.size() - 1; k++){
                        sum += a[k];
                    }
                    int mx = a[a.size() - 1];
                    if(mx >= sum){
                        int extra = mx - sum;
                        cout<< sum + extra << '\n';
                    }
                    else{
                        int ans = (sum + mx + 1) / 2;
                        cout<< ans << '\n';
                    }
                }
            }
            else{
                cout<< -1 << '\n';
            }
        }
    }
}
