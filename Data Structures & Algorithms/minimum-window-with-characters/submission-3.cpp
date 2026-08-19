class Solution {
   public:
    string minWindow(string s, string t) {
        int sz = t.size();
        map<char, int> freq;
        for (auto it : t) {
            freq[it]++;
        }
        int n = s.size();
        int l = 0, r = 0;
        int mnSz = 1e9;
        int currSz = 0;
        string currSt = "";
        int ans[] = {0,0};
        map<char, int> overhead;
        while (l < n) {
            if (freq.find(s[l]) != freq.end()) {
                r = max(r, l);
                while (r < n && currSz < sz) {
                    currSt += s[r];
                    if (freq.find(s[r]) != freq.end()) {
                        if (freq[s[r]] > 0) {
                            currSz++;
                            freq[s[r]]--;
                        } else {
                            overhead[s[r]]++;
                        }
                    }
                    r++;
                }
                if (mnSz > r - l && currSz == sz) {
                    mnSz = r - l;
                    ans[0]=l;
                    ans[1]=r;
                }
            }

            if (freq.find(s[l]) != freq.end()) {
                if (overhead.find(s[l]) != overhead.end() && overhead[s[l]] > 0) {
                    overhead[s[l]]--;
                } else {
                    currSz--;
                    freq[s[l]]++;
                }
            }
            l++;
        }
        return s.substr(ans[0],ans[1]-ans[0]);
    }
};
