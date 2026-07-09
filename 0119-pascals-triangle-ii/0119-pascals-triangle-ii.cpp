class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize the vector with size (rowIndex + 1) filled with 1s
        vector<int> row(rowIndex + 1, 1);
        
        // Iterate through each row up to rowIndex
        for (int i = 1; i < rowIndex; ++i) {
            // Update from right to left to prevent overwriting values needed for the current iteration
            for (int j = i; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        return row;
    }
};