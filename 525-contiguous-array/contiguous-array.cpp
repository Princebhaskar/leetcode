class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)nums[i]=-1;
        }
        vector<int>pre(n,nums[0]);
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        unordered_map<int,int>mp;
        int maxi =0;
        for(int i=0;i<n;i++){
            if(pre[i]==0)maxi = i+1;
            if(mp.find(pre[i]) != mp.end()){
                maxi = max(maxi , i-mp[pre[i]]);
            }else{
                mp[pre[i]]= i;
            }
        }
        return maxi;
    }
};