class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1])
                ans++;
        }
        map<pair<int,int>, int> mp;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                int a = nums[i-1];
                int b = nums[i];
                if(a > b) swap(a, b);
                mp[{a,b}]++;
            }
        }

        int maxi = 0;
        for(auto it : mp) {
            maxi = max(maxi, it.second);
        }
        return ans + maxi;
    }
};