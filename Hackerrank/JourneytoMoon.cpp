#include<bits/stdc++.h> 
#define int long long int
using namespace std;


vector<int> v[1000000];
    int vis[1000000] = {0};
    
void dfs(int n , int &cnt){
    cnt++;
    vis[n] = 1;
    for(auto i : v[n]){
        if(!vis[i]){
            dfs(i , cnt);
        }
    }
}

signed main(){
    int n , p; 
    cin >> n >> p;
    
    for(int i = 0 ; i < p ; ++i){
        
        int a , b ; 
        cin >> a >> b ; 
        
        v[a].push_back(b);
        v[b].push_back(a);

    }
    vector<int> res;
    int cnt = (n*(n-1)/2);
    for(int i = 0 ; i < n; i++){
        if(!vis[i]){
          int count = 0;
            dfs(i,count);
            cnt -= (count*(count-1)/2);
        }
    }
    cout << cnt << endl;
    return 0;
}
