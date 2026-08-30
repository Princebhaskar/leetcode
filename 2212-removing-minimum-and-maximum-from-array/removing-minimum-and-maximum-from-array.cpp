class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int idx1 = max_element(nums.begin(), nums.end()) - nums.begin();
        int idx2 = min_element(nums.begin(), nums.end()) - nums.begin();
        if(idx1 <= idx2){
            int a = idx2+1;
            int b = n - idx1;
            int c = idx1+1 + (n-idx2);
            return min({a,b,c});
        }else{
            int a = idx1+1;
            int b = n - idx2;
            int c = idx2+1 + (n-idx1);
            return min({a,b,c});
        }
    }
};