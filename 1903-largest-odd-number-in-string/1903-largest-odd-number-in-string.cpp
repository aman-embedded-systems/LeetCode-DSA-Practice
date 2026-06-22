class Solution {
public:
    string largestOddNumber(string num) {
        
        int n=num.size();
        
        for(int idx=n-1;idx>=0;idx--)
        {
            if((num[idx]-'0')%2==1)
            {
                int start=0;

                while(idx<start && (num[start]-'0')==0)start++;

                return num.substr(start,idx-start+1);
            }
        }
        return ""; //No odd Value
    }
};