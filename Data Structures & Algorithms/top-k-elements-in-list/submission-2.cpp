class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>freq;
        map<int,int>freqArr;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            freqArr[nums[i]]++;
            mx=max(mx,nums[i]);
        }
        for(int i=-1000;i<=mx;i++){
            freq.push_back({freqArr[i],i});
        }
        sort(freq.begin(),freq.end(),greater<>());
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=freq[i].second;
        }
        return ans;
    }
};
