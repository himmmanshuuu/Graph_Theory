#include<bits/stdc++.h> 
using namespace std ; 

struct queueEntry 
{ 
    int v;     
    int dist;   
}; 
   
int bfs(int move[], int N) 
{ 
    
    bool *visited = new bool[N]; 
    for (int i = 0; i < N; i++) 
        visited[i] = false; 
  

    queue<queueEntry> q; 
  
    
    visited[0] = true; 
    queueEntry s = {0, 0};  
    q.push(s); 
   
    queueEntry qe;  
    while (!q.empty()) 
    { 
        qe = q.front(); 
        int v = qe.v;

        if (v == N-1) 
            break; 
  
        q.pop(); 
        for (int j=v+1; j<=(v+6) && j<N; ++j) 
        { 
            if (!visited[j]) 
            { 
                 
                queueEntry a; 
                a.dist = (qe.dist + 1); 
                visited[j] = true; 
  
                
                if (move[j] != -1) 
                    a.v = move[j]; 
                else
                    a.v = j; 
                q.push(a); 
            } 
        } 
    } 
    if(qe.v != N-1) return -1;
    return qe.dist; 
} 
int main(){
    int t;
    cin >> t ;
    while(t--){
        int n , m ; 
        cin >> n  ;
    
    int arr[101]; 
    
    for(int i = 0 ; i <= 100; ++i){
        arr[i] = -1;
    } 
    
    for(int i = 0 ; i < n; i++){
        int a , b ; 
        cin >> a >> b; 
        a--;
        b--;
        arr[a] = b;
    }
    
    cin >> m ; 
    
    for(int i = 0 ; i < m; ++i){
        int x , y;
        cin >> x >> y ; 
        x--;
        y--;
        arr[x] = y;
    }
    int ans = bfs(arr,100);
    cout << ans << endl;
    }
    return 0 ; 
    
}
