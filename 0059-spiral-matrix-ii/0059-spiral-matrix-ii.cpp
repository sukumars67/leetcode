class Solution {
public:
    int iStart = 0, jStart = 0; // Starting indices for the next spiral layer

    // Recursive DFS to fill the matrix in spiral order
    void dfs(vector<vector<int>>& matrix, int i, int j, int n, int start, int& side) {
        if (i < 0 || j < 0 || i >= n || j >= n || matrix[i][j] != 0) { // Base case to check boundaries and already filled cells
            side = side % 4 + 1; // Change direction (1=right, 2=down, 3=left, 4=up)
            // Check if a full spiral cycle is completed
            if (i == iStart && j == jStart) {
                iStart++; jStart++; // Move to the next inner layer
                i = iStart; j = jStart; // Reset starting indices for the new layer
                // Stop recursion if all layers are processed
                if ((n % 2 == 0 && iStart > n / 2 - 1) || (n % 2 == 1 && iStart > n / 2)) {
                    return;
                }
            } else {
                return; // Stop further recursion for the current path
            }
        }

        matrix[i][j] = start; // Fill the current cell with the current number

        // Recur in the current direction
        if (side == 1) dfs(matrix, i, j + 1, n, start + 1, side); // Move right
        if (side == 2) dfs(matrix, i + 1, j, n, start + 1, side); // Move down
        if (side == 3) dfs(matrix, i, j - 1, n, start + 1, side); // Move left
        if (side == 4) dfs(matrix, i - 1, j, n, start + 1, side); // Move up
    }

    // Generate the n x n spiral matrix
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)); // Initialize an empty matrix (O(n^2) space)
        int start = 1; // Starting number to fill
        int side = 1; // Direction to start with
        dfs(matrix, 0, 0, n, start, side); // Start recursive filling
        return matrix; // Return the filled matrix
    }
};