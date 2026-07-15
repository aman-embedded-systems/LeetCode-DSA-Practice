class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int prevValue = 0;
        int currentValue = 0;
        
        // Iterate from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            // Determine the integer value of the current Roman numeral
            switch(s[i]) {
                case 'I': currentValue = 1; break;
                case 'V': currentValue = 5; break;
                case 'X': currentValue = 10; break;
                case 'L': currentValue = 50; break;
                case 'C': currentValue = 100; break;
                case 'D': currentValue = 500; break;
                case 'M': currentValue = 1000; break;
            }
            
            // If the current value is less than the previous, subtract it (e.g., IV = 5 - 1 = 4)
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                // Otherwise, add it (e.g., VI = 5 + 1 = 6)
                total += currentValue;
            }
            
            // Update prevValue for the next iteration
            prevValue = currentValue;
        }
        
        return total;
    }
};