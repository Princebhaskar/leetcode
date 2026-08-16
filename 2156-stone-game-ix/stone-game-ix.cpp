class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n= stones.size();
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for(int i=0;i<n;i++){
            int t = stones[i]%3;
            if(t==0)zeros++;
            if(t==1)ones++;
            if(t==2)twos++;
        }
        if(zeros%2==0)return ones >0 && twos>0;
        else return abs(twos-ones)>2;
    }
}; 