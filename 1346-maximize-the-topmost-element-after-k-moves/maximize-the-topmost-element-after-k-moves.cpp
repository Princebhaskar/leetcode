class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
       if(k>=1 && k%2!=0 && nums.size()==1)return -1;
       if(k>=1 && k%2==0 && nums.size()==1)return nums[0];
       if(k > nums.size())return *max_element(nums.begin(), nums.end()); 
       int maxi=0;
       for(int i=0;i<k-1;i++){
            maxi =max(maxi, nums[i]);
       }
       if(nums[k] > maxi)maxi = nums[k];
       return maxi;
    }
};