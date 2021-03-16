#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define loop(i,n) for(int i=0;i<(int)(n);i++)
#define forcin(a,n) for(int i=0;i<n;i++) {cin>>a[i];}
#define rev(s) reverse(s.begin(),s.end())
#define vmax(v) *max_element(v.begin(),v.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define setbits(x) __builtin_popcountll(x)
#define fastm_fast ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int  mod = 1e9 + 7;
const int MAX = 2e5+5;
typedef pair<int, int> pii;
typedef vector<int> vi ;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef map<int,int> mapii ;

int n ; 
int m ;
int ans = 0;
vector<int>adj[(int)1e6+100]; 
vector<bool> vis((int)1e6+100,false);
vector<int> cats;

void dfs(int v , int k = 0){
    vis[v] = true;

    if(cats[v]) k++;
    else k = 0;

    if(k > m) return ;

    if(adj[v].size() == 1 && v != 1){
        ans++;
    }
    else{
        for(auto i : adj[v]){
            if(!vis[i]){
                dfs(i,k);
            }
        }
    }
}

void sujho()
{
    cin >> n >> m ; 
    cats.resize(n+1);
    for(int i = 1 ; i <= n; i++){
        int x ; 
        cin >> x ; 
        cats[i] = x;
    }
    for(int i = 0 ; i < n-1; ++i){
        int a , b ; 
        cin >> a >> b ; 
        adj[a].pb(b); 
        adj[b].pb(a);
    }

    dfs(1);
    
    cout << ans << endl ; 

}

int32_t main()
 {
 
//  fastm_fast;
//  int test;
//  cin >> test;
//  for(int i = 1; i <= test; i++)
  {
    sujho();
  }
 return 0;
 }
