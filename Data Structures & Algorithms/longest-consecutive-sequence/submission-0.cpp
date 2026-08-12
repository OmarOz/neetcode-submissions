class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>freq;
        set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(auto it:s){
            freq[it]+=freq[it-1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,freq[nums[i]]);
        }
        return ans;
    }
};
