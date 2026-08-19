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
        string ans = "";
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
                    ans = currSt;
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
            if (!currSt.empty()) {
                currSt.erase(0, 1);
            }
            l++;
        }
        return ans;
    }
};
