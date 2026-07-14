class Solution {
public:
    int reverseBits(int n) {
        int nz=31;
        int res=0;
        int extractbit=0;
        for(int idx=0;idx<32;idx++)
        {
           extractbit= (n>>idx) & 1u;
           res=res|(extractbit<<nz);
           nz--;
        }
        return res;
    }
};