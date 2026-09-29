class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<long long>s;
        s.push(1e18);
        int n = position.size();
        vector<pair<int,int>>vp(n);
        for(int i=0;i<n;i++){
            vp[i] = {position[i],speed[i]};
        }
        sort(vp.begin(),vp.end());
        for(int i=0;i<n;i++){
            s.push(((target - vp[i].first) * 1e6)/ (vp[i].second));
        }
        int ans=0;
        while(s.size() > 1){
            int curr = s.top();
            s.pop();
            while(s.top() <= curr){
                s.pop();
            }
            ans++;
        }
        return ans;
    }
};
