char* addBinary(char* a, char* b) {
  int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB ? lenA : lenB) + 2; // +1 for possible carry, +1 for '\0'
    
    char* result = (char*)malloc(maxLen * sizeof(char));
    result[maxLen - 1] = '\0';
    
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen - 2;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        
        result[k] = (sum % 2) + '0';
        carry = sum / 2;
        k--;
    }
    
    // Shift result pointer if no carry was added to the most significant position
    return &result[k + 1];  
}