class Solution {
public:
    int memo[501][501];
    int solve(int i, int j, vector<int>&piles){
        if(i>j){
            return 0;
        }
        if(memo[i][j] != -1)return memo[i][j];
        int takeLeft = piles[i] - solve(i+1, j, piles);
        int takeRight = piles[j]-solve(i,j-1,piles);

        return memo[i][j] = max(takeLeft, takeRight);
        //return max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n =piles.size();
        memset(memo, -1, sizeof(memo));
        return solve(0,n-1,piles)>0;
    }
};