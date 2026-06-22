class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int n=s.length();
        for(int idx=0;idx<t.length() && i<n;idx++)
        {
            if(s[i]==t[idx])
            {
              i++;
            }
           
        }
        return n==i;
    }
};