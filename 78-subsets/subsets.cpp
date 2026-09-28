class Solution {
public:	
    void solve(int i ,vector<int>nums ,vector<int>&arr , vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(arr);
            return;
        }
        solve(i+1 , nums , arr, ans);
        arr.push_back(nums[i]);
        solve(i+1, nums , arr, ans);
        arr.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0 ,nums , arr ,ans);
        return ans;
    }
};