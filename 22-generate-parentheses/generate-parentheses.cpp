class Solution {
public:
    vector<string> solve(vector<string>&ans ,string s,int open, int close , int n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return {};
        }
        if(open < n)solve(ans,s+'(' , open+1, close , n);
        if(close < open)solve(ans,s+')', open ,close+1, n);

        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        return solve(ans, "" ,0,0, n);
    }
};