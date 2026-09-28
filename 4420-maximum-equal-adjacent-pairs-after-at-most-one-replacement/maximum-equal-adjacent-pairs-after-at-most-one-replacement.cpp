struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        // Combine the two hashes
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1])
                ans++;
        }
        unordered_map<pair<int,int>, int, hash_pair> mp;

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