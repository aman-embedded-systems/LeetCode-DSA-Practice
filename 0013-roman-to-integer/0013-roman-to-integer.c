int getRomanValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0;
    }
}
int romanToInt(char* s) {
    int total = 0;
    int length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        int currentVal = getRomanValue(s[i]);
        
        // If the current value is less than the next value, subtract it
        if (i + 1 < length && currentVal < getRomanValue(s[i + 1])) {
            total -= currentVal;
        } else {
            // Otherwise, add it
            total += currentVal;
        }
    }
    
    return total;
}