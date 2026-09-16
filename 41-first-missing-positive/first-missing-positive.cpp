class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int  ans = 1;
        for(int it : nums){
            if(it == ans){
                ans++;
            }
            else if(it>ans){
                return ans;
            }
        }
        return ans;
    }
};