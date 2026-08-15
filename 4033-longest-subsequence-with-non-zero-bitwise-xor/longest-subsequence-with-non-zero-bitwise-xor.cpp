class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int> v = nums;

        int xorsum = 0;
        bool check = false;
        for(auto it: v){
            xorsum ^= it;
            if(it != 0)check = true;
        }
        if(xorsum != 0){
            return v.size();
        }

        if(!check)return 0;
        return v.size()-1;
        
    }
};