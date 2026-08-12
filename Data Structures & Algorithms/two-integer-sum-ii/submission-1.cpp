class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int>mp;
        for(int i=0;i<numbers.size();i++){
            mp[numbers[i]]=i+1;
        }
        vector<int>ans(2);
        for(auto it: numbers){
            if(mp[target - it]){
                ans[1] = mp[it];
                ans[0] = mp[target - it];
            }
        }
        return ans;
    }
};
