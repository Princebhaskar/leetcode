class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum =nums[0];
        unordered_set<int> s;
        for(int i=0 ; i<n ; i++){
            s.insert(nums[i]);
        }
        for(int i=1 ; i<n;i++){
            if(nums[i]== nums[i-1]+1){
                sum += nums[i];
            }
            else break;

        }
        while(s.find(sum) != s.end()){
            sum ++;
        }
        return sum;
    }
};