class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it: s){
            if(st.size()>0 && it == ')' && st.top() == '('){st.pop();}
            else if(st.size()>0 && it == '}' && st.top() == '{'){st.pop();}
            else if(st.size()>0 && it == ']' && st.top() == '[' ){st.pop();}
            else{
                st.push(it);
            }       
            cout<<it<<" "<<st.size()<<"\n";    
        }
        return st.size() == 0;
    }
};
