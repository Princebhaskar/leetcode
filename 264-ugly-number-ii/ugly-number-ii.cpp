class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long>vis;
        priority_queue<long long,vector<long long>, greater<long long>>pq;
        pq.push(1);
        vis.insert(1);
        vector<int>ans;
        while(ans.size()<n){
            int top = pq.top();
            ans.push_back(top);
            pq.pop();
            long long x = 1LL*top*2;
            if(!vis.count(x)){
                pq.push(x);
                vis.insert(x);
            }
            long long y = 1LL*top*3;
            if(!vis.count(y)){
                pq.push(y);
                vis.insert(y);
            }
            long long z =1LL*top*5;
            if(!vis.count(z)){
                pq.push(z);
                vis.insert(z);
            }
        }
        return ans[n-1];
    }
};