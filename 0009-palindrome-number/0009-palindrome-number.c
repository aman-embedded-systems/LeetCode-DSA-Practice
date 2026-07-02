bool isPalindrome(int x) {
    int numcpy=x;
    long palindromenum=0;
    if(x==0)
    {
        return 1;
    }
    else if(x<0)
    {
        return false;
    }
    while(numcpy)
    {
        if(palindromenum*10 > INT_MAX || palindromenum < INT_MIN) {
              return false; 
         }
        palindromenum=(palindromenum*10)+(numcpy%10);

        numcpy/=10;
        printf("%d: \n",palindromenum);
    }
   
    return (palindromenum==x);
}