char* intToRoman(int num) {
    // Parallel arrays mapping values to their Roman numeral representations in descending order
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // Allocate enough memory for the largest possible Roman numeral string under 4000
    // "MMMCMXCIX" (3999) takes 9 characters + 1 for null-terminator = 10 bytes.
    // Allocating 16 bytes provides a safe buffer.
    char* result = (char*)malloc(16 * sizeof(char));
    result[0] = '\0'; // Initialize as an empty string
    
    // Loop through the values and append the symbols as many times as possible
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
    
    return result;
}