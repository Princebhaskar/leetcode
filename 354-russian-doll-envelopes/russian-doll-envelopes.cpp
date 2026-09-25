class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(),[](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int n = env.size();
        vector<int>ans;
        ans.push_back(env[0][1]);
        for(int i=1;i<n;i++){
            if(env[i][1] > ans.back()){
                ans.push_back(env[i][1]);
            }
            else{
                int idx = lower_bound(ans.begin(),ans.end() , env[i][1])-ans.begin();
                ans[idx] = env[i][1];
            }
        }
        return ans.size();
    }
};