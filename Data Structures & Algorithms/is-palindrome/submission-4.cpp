class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90){s[i]+=32;}
        }
        int l=0,r=s.size()-1;
        while(l<=r){
            if(!(s[l]>=97 && s[l]<=122) && !(s[l] >= 48 && s[l] <= 57)){
                l++;
                continue;
            }
            if(!(s[r]>=97 && s[r] <= 122) && !(s[l] >= 48 && s[l] <= 57)){
                r--;
                continue;
            }
            cout<<s[l]<<"\n";
            cout<<s[r]<<"\n";
            if(s[l]!=s[r]){return false;}
            l++;
            r--;
        }
        return true;
    }
};
