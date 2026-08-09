class Solution {
public:
    int n;
    int dp[2][101][101];
    int solve(vector<int>& piles,int alice ,int M ,int i){
        if(i>=n)return 0;
        
        if(dp[alice][i][M] != -1)return dp[alice][i][M];

        int stones = 0;
        int result = (alice == 1) ? -1 : INT_MAX;
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(alice == 1) {
                result = max(result, stones + solve(piles, 0, max(M, x) , i+x));
            } else { 
                result = min(result, solve(piles, 1,  max(M, x) ,i+x));
            }   
        }
        return dp[alice][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles,1, 1 , 0);
    }
};