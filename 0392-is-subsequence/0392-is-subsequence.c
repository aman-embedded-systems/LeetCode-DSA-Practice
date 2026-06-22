bool isSubsequence(char* s, char* t) {
    int n=strlen(s);
    int idx=0;
    for(int idy=0;idy<strlen(t) && idx<n;idy++)
    {
        if(s[idx]==t[idy])
        {
            idx++;
        }
    }
    return n==idx;
}