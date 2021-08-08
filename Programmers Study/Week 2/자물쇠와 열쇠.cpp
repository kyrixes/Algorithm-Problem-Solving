#include <vector>
using namespace std;
 
int keySize, lockSize;
int boardSize;

void rotate (vector<vector<int>> &key) {
    vector<vector<int>> new_key(keySize, vector<int>(keySize));
 
    for (int j = keySize - 1; j >= 0; j--)
        for (int i = 0; i < keySize; i++)
            new_key[i][j] = key[keySize - j - 1][i];
        
    key = new_key;
}

bool check (int x, int y, vector<vector<int>> key, vector<vector<int>> board) {
    for (int i = x; i < x + keySize; i++)
        for (int j = y; j < y + keySize; j++)
            board[i][j] += key[i - x][j - y];
        
    for (int i = keySize - 1; i <= boardSize - keySize; i++)
        for (int j = keySize - 1; j <= boardSize - keySize; j++)
            if (board[i][j] == 1)
                continue;
            else
                return false;
        
    return true;
}
 
bool solution (vector<vector<int>> key, vector<vector<int>> lock) {
 
    keySize = key.size();
    lockSize = lock.size();
    boardSize = lockSize + (keySize - 1) * 2;
    
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    
    for (int i = keySize - 1; i <= boardSize - keySize; i++)
        for (int j = keySize - 1; j <= boardSize - keySize; j++)
            board[i][j] = lock[i - keySize + 1][j - keySize + 1];
        
    for (int r = 0; r < 4; r++) {
        for (int i = 0; i <= boardSize - keySize; i++) {
            for (int j = 0; j <= boardSize - keySize; j++)
                if (check(i, j, key, board))
                    return true;
        }
        rotate(key);
    }
    
    return false;
}
