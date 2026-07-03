int myAtoi(char* s) {
    int i=0;
    int sign=1;
    long result=0; 

    //step 1 skip leading whitespace
    while(s[i]==' '){
        i++;
    }
    //step 2 check for sign
    if(s[i]=='-'||s[i]=='+')
    {
        if(s[i]=='-')
        {
            sign=-1;
        }
        i++;
    }
    //step 3 //convert digits and Handle Potential overflow
    while(s[i]>='0'&&s[i]<='9')
    {
        // 1. Accumulate the digit first!
        result = result * 10 + (s[i] - '0');
        //2. then check if it overflowed
    if(sign==1 && result>INT_MAX)
    {
        return INT_MAX;
    }
    if(sign==-1 && -result<INT_MIN)
    {
        return INT_MIN;
    }
    i++;
    }
    return (int)(result*sign);

}