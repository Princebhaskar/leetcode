class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(501,0);
        int ans=0, i=0;
        for(int j=0;j<n;j++){
            int c = nums[j];
            bool flag1 =true, flag2=true;

            while(flag1 || flag2 ){
                flag1=false;
                flag2=false;
                for(int a=1;a<=500;a++){
                    int b = c-a;
                    if(b<1 || b>500)continue;
                    if(a==b){
                        if(hash[a]>=2){
                            flag1= true;
                            break;
                        }
                    }else{
                        if(hash[a]>=1 && hash[b] >= 1){
                            flag1 =true;
                            break;
                        }
                    }
                }
                
                for(int b=1;b<=500;b++){
                    if(hash[b]==0)continue;
                    int a = c + b;
                    if(a>500)continue;
                    if(hash[a] >= 1){
                        flag2= true;
                        break;
                    }
                }

                if(flag1 || flag2){
                    hash[nums[i]]--;
                    i++;
                }
            }
            hash[c]++;
            ans= max(ans, j-i+1);
        }
        return ans;
    }
};