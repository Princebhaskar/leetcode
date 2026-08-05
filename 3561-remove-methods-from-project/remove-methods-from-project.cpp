class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<int>&vis, int k){
        vis[k]=1;
        for(auto it: adj[k]){
            if(!vis[it]){
                dfs(adj, vis, it);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto it: invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        dfs(adj, vis, k);
    
        for(auto it: invocations){
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i])ans.push_back(i);
        }
        return ans;
    }
};