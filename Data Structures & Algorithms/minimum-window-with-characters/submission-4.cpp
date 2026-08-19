class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>countT,window;
        for(char c:t){countT[c]++;}
        int need = countT.size(), have = 0;
        pair<int,int> ans={-1,-1};
        int mnLen = INT_MAX;
        int l = 0;
        for(int r=0;r<s.size();r++){
            window[s[r]]++;
            if(countT.count(s[r]) && window[s[r]] == countT[s[r]]){
                have++;
            }
            while(have == need){
                if(mnLen > r-l+1){
                    mnLen = r-l+1;
                    ans={l,r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return mnLen == INT_MAX?"":s.substr(ans.first,mnLen);
    }
};
