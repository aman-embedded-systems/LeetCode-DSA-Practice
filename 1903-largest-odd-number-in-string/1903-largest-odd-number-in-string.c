char* largestOddNumber(char* num) {
    
    int n=(int)strlen(num);

    //ASIC 48 is 0 so;
    int end=-1;
    for(int idx=n-1;idx>=0;idx--)
    {
        if((num[idx]-'0')%2==1)
        {
            end=idx;
            break;
        }
    }
    if(end==-1)//there is no Odd Number so for Null Variable Return Null
    {
        char *res=(char*)malloc(1*sizeof(char));
        res[0]='\0';
        return res;
    }
    int start=0; //Scan from right for Leading Zero's
    while(start<end && (num[start]-'0')==0)start++;

    int length=end-start+1;
    char *result=(char*)malloc((length+1)*sizeof(char));
    strncpy(result,num+start,length);
    result[length]='\0';
    return result;
    
}