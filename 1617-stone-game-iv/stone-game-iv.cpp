class Solution {
public:
    int dp[2][100001];
    bool solve(int n , int alice, vector<int>&st){
        if(n == 0 && alice)return false;
        if(n==0 && !alice)return true;
    
        if(dp[alice][n] != -1)return dp[alice][n];
        if(alice){
            bool path1 = false;
            for(auto it: st){
                if(it <= n){
                    n-= it; 
                    path1 = path1 || solve(n, 0, st);
                    n += it;
                }
            }
            return dp[alice][n]  = path1;
        }
        else{
            bool path2 = true;
            for(auto it : st){
                if(it<= n){
                    n-= it;
                    path2 = path2 && solve(n, 1, st);
                    n += it;
                }
            }
            return dp[alice][n] =  path2;
        }
    }
    bool winnerSquareGame(int n) {
        vector<int>st;
        for(int i = 1; i * i <= n; i++) {
            st.push_back(i * i);
        }
        memset(dp, -1, sizeof(dp));
        return solve(n , 1 , st);
    }
};