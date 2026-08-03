class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int>v(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            v[i] = nums[(i-k+n)%n];
        }
        nums = v;
    }
};