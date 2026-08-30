class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        multiset<int>s;
        int i=0;
        for(int j=0;j<n;j++){
            while(s.size() < k-1){
                s.insert(nums[j]);
                j++;
            }
            s.insert(nums[j]);
            int maxi = *s.rbegin();
            ans.push_back(maxi);
            s.erase(s.find(nums[i]));
            i++;
        }
        return ans;
    }
};