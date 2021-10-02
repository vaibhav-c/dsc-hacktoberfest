class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int i = 0;
        while(isalpha(s[i]))
            ++i;
        
        if(k-1 < i) {
            string s1(1, s[k - 1]);
            return s1;
        }
        
        i = 0;
        stack<char> st;
        string res;
        while(i < s.size()) {
            if(isalpha(s[i])) {
                st.push(s[i]);
                res += st.top();
                ++i;
            } 
            else if(isdigit(s[i])) {
                int count  = s[i] - '0', j = 1;
                if(count == 1)
                    res += res;
                else {
                    string temp = res;
                    while(j < count) {
                        res += temp;
                        ++j;
                    }
                }
                
                ++i;
            }
        }
        
        string s1(1,res[k-1]);
        return s1;
    }
};