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

vector<int> arr[100005];
vector<int> vis(100005 ,0LL);
vector<int> comp;
void dfs(int v){
    vis[v] = 1;
    for(auto i : arr[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
void sujho()
{
	int n , m ; 
    cin >> n >> m ; 
    for(int i = 0; i < m; i++){
        int a , b; 
        cin >> a >> b; 
        arr[a].pb(b);
        arr[b].pb(a);
    }
    int cnt = 0;
    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            comp.pb(i);
            cnt++;
            dfs(i);
        }
    }
    cout << cnt-1 << endl;
    for(int i = 0 ; i < comp.size()-1; i++){
        cout << comp[i] << " " << comp[i+1] << endl;
    }
}

int32_t main()
 {
 
 fastm_fast;
//  int test;
//  cin >> test;
//  for(int i = 1; i <= test; i++)
  {
    sujho();
  }
 return 0;
 }
