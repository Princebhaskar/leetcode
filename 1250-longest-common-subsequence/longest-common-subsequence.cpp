class Solution {
public:
    int solve(string s1, string s2,int i, int j,vector<vector<int>>&dp){
        if(i>=s1.size()|| j>=s2.size()){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solve(s1,s2,i+1,j+1,dp);
        }else{
            return dp[i][j] =  max(solve(s1,s2,i+1,j,dp) , solve(s1,s2,i,j+1,dp));
        }
    }
    int solveTab(string s1, string s2,  vector<vector<int>>&dp){
        int n1 = s1.size();
        int n2 = s2.size();
        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s1[i] == s2[j])dp[i][j] = 1+ dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int solveMem(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+ prev[j-1];
                }
                else curr[j] = max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        //return solve(text1,text2,0,0,dp);
        //return solveTab(text1 , text2, dp);
        return solveMem(text1, text2);
    }
};