class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans= INT_MIN;
        int n = nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!= nums[i+1]){
                    ans = nums[i];
                    break;
                }
            }
            if(i==n-1){
                if(nums[i] != nums[i-1]){
                    ans = nums[i];
                    break;
                }
            }
            if(i>0 && i<n-1){
                if(nums[i]==nums[i-1] || nums[i]==nums[i+1]){
                    continue;
                }
                else{
                    ans = nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};