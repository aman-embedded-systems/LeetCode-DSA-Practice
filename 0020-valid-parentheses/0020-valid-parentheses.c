bool isValid(char* s) {
    int len = strlen(s);
    
    // An odd length string can never be balanced
    if (len % 2 != 0) {
        return false;
    }
    
    // Allocate stack memory based on max possible opening brackets
    char stack[len];
    int top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        
        // Push opening brackets onto the stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // Handle closing brackets
        else {
            // If stack is empty but we have a closing bracket, it's invalid
            if (top == -1) {
                return false;
            }
            
            char openBracket = stack[top--];
            
            // Check for matching pairs
            if (current == ')' && openBracket != '(') return false;
            if (current == '}' && openBracket != '{') return false;
            if (current == ']' && openBracket != '[') return false;
        }
    }
    
    // If top is -1, all brackets were successfully matched and popped
    return top == -1;
}