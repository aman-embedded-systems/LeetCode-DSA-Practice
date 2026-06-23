class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //first find out how many Freq for each Strings,
        vector<int>res;
        vector<int>freqs(26,0);
        vector<int>freqp(26,0);

        int sizeS=s.size();
        int sizeP=p.size();

        if(sizeP>sizeS)
        {
            return res;
        }
        for(int idx=0;idx<sizeP;idx++)
        {
            freqs[s[idx]-'a']++;
            freqp[p[idx]-'a']++;
        }
        if(freqs==freqp)
        {
            res.push_back(0);
        }
        //Slide the Window
        for(int idx=sizeP;idx<sizeS;idx++)
        {
            freqs[s[idx]-'a']++;
            freqs[s[idx-sizeP]-'a']--;
            if(freqs==freqp)
            {
                res.push_back(idx-sizeP+1);
            }
        }
        return res;
    }
};