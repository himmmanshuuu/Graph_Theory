#include<bits/stdc++.h> 
using namespace std; 
vector<long> v[10000000];
vector<long> vis(1000000,0); 

void dfs(int n ,int &node){
    node++;
    vis[n] = 1; 
    for(auto i : v[n]){
        if(!vis[i]){
            dfs(i,node);
        }
    }
}
int main(){
    int t ; 
    cin >> t ; 
    while(t--){
        int n , m , clib ,  croad ; 
        cin >> n >> m >> clib >> croad ;
        for(int i = 0 ; i < m ; ++i){
            int a , b ; 
            cin >> a >> b ; 
            v[a].push_back(b); 
            v[b].push_back(a);
        } 
        long res = 0 ;
        int node = 0; 
        for(int i = 1; i <= n; ++i){
            if(vis[i] == 0){
                 node = 0;
                dfs(i,node);
            res += clib;
            if(clib <= croad){
                res += (node - 1)*clib;
            }
            else{
                res += (node-1)*croad;
            } 
            }
        }
        cout << res << endl;
        for(int i = 1 ; i <= n; i++)
        {
            v[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}
