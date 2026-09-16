class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int>hash(1e5+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i] >0 && nums[i]<=1e5)hash[nums[i]]=1;
        }
        int ans =0;
        for(int i=1;i<=1e5;i++){
            if(hash[i]==0){
                return i;
            }
        }
        return 1e5+1;
    }
};