class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int ans = INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini){
                mini = prices[i];
            }else{
                ans = max(ans, prices[i]-mini);
            }
        }
        if(ans == INT_MIN)return 0;
        return ans;
    }
};