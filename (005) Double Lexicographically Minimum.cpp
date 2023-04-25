// Problem link: https://codeforces.com/contest/1799/problem/C
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
        string s; cin >> s;
        sort(s.begin(), s.end());
        string l, m, r;
        int i = 0;
        bool cng = false;
        while(i < s.size()){
            if(i + 1 < s.size() && s[i] == s[i + 1]){
                l.pb(s[i+1]);
                r.pb(s[i]);
                i += 2;
            }
            else{
                if(i + 1 >= s.size()) break;
                else if(s[i] != s[i + 1]){
                    l.pb(s[i + 1]);
                    r.pb(s[i]);
                    i += 2;
                    cng = true;
                    break;
                }
            }
        }
        set<int> st;
        while(i < s.size()){
            m.pb(s[i]);
            st.insert(s[i] - 'a');
            i++;
        }
        if(st.size() == 1 && cng){
            int ind = m.size() / 2;
            if(m[0] == l[l.size() - 1] && r.size()) swap(m[ind], r[r.size() - 1]);
        }
        reverse(r.begin(), r.end());
        string ans = l + m + r;
        cout << ans << '\n';
    }
}
