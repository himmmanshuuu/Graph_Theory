#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define loop(i,n) for(int i=0;i<(n);i++)
#define loopf(a,b,i) for(int i=(a);i<=(b);i++)
#define loopb(a,b,i) for(int i=(a);i>=(b);i--)
#define forcin(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define rev(s) reverse(s.begin(),s.end())
#define vmax(v) *max_element(v.begin(),v.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define setbits(x) __builtin_popcountll(x)
#define fastm_fast ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL)
#define pb emplace_back
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

char arr[1005][1005];
bool vis[1005][1005];
int row ;
int col ;
int x[] = {0 , -1 , 0 , 1};
int y[] = {1 , 0 ,-1 , 0 };

bool isvalid(int i , int j){
   if(i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == '.')
      return true;
   else
      return false;
}

void dfs(int i , int j){

   vis[i][j] = 1;

   int dx , dy ;

   for(int k = 0 ; k < 4; k++){
      dx = i+x[k];
      dy = j+y[k];

      if(isvalid(dx , dy) && !vis[dx][dy]){
         dfs(dx,dy);
      }
   }

}

void sujho()
{
  
    cin >> row >> col ; 

   for(int i = 0; i < row; i++){
      for(int j = 0 ; j < col ; j++){
         cin >> arr[i][j];
         vis[i][j] = 0 ;
      }
   }

   int cnt = 0 ;

   for(int i = 0; i < row; i++){
      for(int j = 0 ; j < col ; j++){
         if(arr[i][j] == '.' && vis[i][j] == 0){
            cnt++;
            //debug(cnt);
            dfs(i,j);
         }
      }
   }
   cout << cnt << endl;
}
int32_t main()
 {
//  fastm_fast;
//  int test;
//  cin >> test;
//  for(int i = 1; i <= test; i++)
 {
     //cout << "Case #"<< test << ":";
     sujho();
 }
 return 0;
 }
