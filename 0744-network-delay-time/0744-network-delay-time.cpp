class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>> adj[n+1];
       for(auto it: times)
       {
           adj[it[0]].push_back({it[1],it[2]});
       } 
       vector<int> dist(n+1,1e9);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
       dist[k]=0;
       q.push({0,k});
       while(!q.empty())
       {
           int time=q.top().first;
           int node=q.top().second;
           q.pop();
           for(auto it: adj[node])
           {
               int newnode=it.first;
               int newtime=it.second;
               if(time+newtime<dist[newnode])
               {
                   dist[newnode]=time+newtime;
                   q.push({dist[newnode],newnode});
               }
           }
       }
       int maxi=dist[1];
       for(int i=1;i<=n;i++)
       {
           if(dist[i]==1e9) return -1;
           else maxi=max(maxi,dist[i]);
       }
       return maxi;
    }
};