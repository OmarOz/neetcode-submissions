class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            string x = strs[i];
            sort(x.begin(),x.end());
            mp[x].push_back(i);
        }
        vector<vector<string>>ans(mp.size());
        int ind=0;
        for(auto it:mp){
            for(int i=0;i<it.second.size();i++){
                ans[ind].push_back(strs[it.second[i]]);
            }
            ind++;
        }
        return ans;
    }
};
