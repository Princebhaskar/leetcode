class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int x = *min_element(nums1.begin() , nums1.end());
        bool foreven = true;
        bool forodd = true;
        for(int i=0;i<n;i++){
            int t = nums1[i]-x;
            if(x%2 !=0){
                if(nums1[i]%2 != 0)continue;
                else if(nums1[i]%2==0  && t%2!=0){
                    continue;
                }else{
                    forodd = false;
                }
            }
            if(x%2 ==0){
                if(nums1[i]%2 ==0)continue;
                else if(nums1[i]%2 !=0  && t%2==0){
                    continue;
                }else{
                   foreven = false; 
                }
            }
        }
        return forodd && foreven;
    }
};