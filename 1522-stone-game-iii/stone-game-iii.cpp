class Solution {
public:
    int solve(vector<int>&nums , int i, vector<int>&dp){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int takeFirst = nums[i]- solve(nums , i+1, dp);
        int takefboth=INT_MIN;
        int takefthree=INT_MIN;
        if(i+1<n){
           takefboth = nums[i]+nums[i+1]-solve(nums, i+2,dp);
        }
        if(i+2<n){
            takefthree = nums[i]+nums[i+1]+nums[i+2]-solve(nums,i+3,dp);
        }
        return dp[i] = max(takeFirst , max(takefboth, takefthree));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(50001, -1);
        if(solve(stoneValue,0, dp)>0){
            return "Alice";
        }else if(solve(stoneValue,0, dp) ==0){
            return "Tie";
        }else{
            return "Bob";
        }
    }
};