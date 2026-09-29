class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>freq;
        int n=nums.size();
        int l=0,r=0;
        vector<int>ans;
        while(r<n){
            freq[nums[r++]]++;
            if(r-l == k){
                ans.push_back(freq.rbegin()->first);
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){freq.erase(nums[l]);}
                l++;
            }
        }
        return ans;
    }
};
