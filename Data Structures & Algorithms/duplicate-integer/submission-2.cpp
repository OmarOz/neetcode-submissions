class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>freq;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            mx=max(mx,nums[i]);
        }
        for(auto it:freq){
            if(it.second>1){return true;}
        }
        return false;
    }
};
