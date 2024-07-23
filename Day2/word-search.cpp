class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Iterate over the board to find the starting point
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base case: If we reach the end of the word, we found a match
        if (index == word.size()) {
            return true;
        }
        
        // Check if i, j are within the bounds of the board and the current cell matches the character of the word
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark the current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore neighboring cells
        bool found = (backtrack(board, word, i + 1, j, index + 1) ||
                      backtrack(board, word, i - 1, j, index + 1) ||
                      backtrack(board, word, i, j + 1, index + 1) ||
                      backtrack(board, word, i, j - 1, index + 1));
        
        // Restore the original value of the current cell
        board[i][j] = temp;
        
        return found;
    }
};