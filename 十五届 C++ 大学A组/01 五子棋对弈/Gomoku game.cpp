#include <iostream>
#include <vector>

using namespace std; 

const int N = 5;  // 棋盘大小为 5 * 5
const int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};  // 四个方向：横、纵、正斜、反斜

// 判断是否有五子连珠
bool hasFiveInARow(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;  // 空格子跳过
            int player = board[i][j];  // 当前玩家
            // 四个方向检查
            for (auto dir : DIRECTIONS) {
                int count = 1;
                for (int k = 1; k < 5; k++) {
                    int x = i + dir[0] * k, y = j + dir[1] * k;
                    if (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == player) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count >= 5) return true;  // 找到五子连珠
            }
        }
    }
    return false;  // 没有五子连珠
}

// 回溯算法：遍历所有棋盘填充情况
int countDraws(vector<vector<int>>& board, int x, int y) {
	// 棋盘填满了，进行检查
    if (x == N) {
		int black = 0;
	    for(int i = 0; i < N; i++){
	       for(int j = 0; j < N; j++){
			  if(board[i][j] == 1){
				  black++;
			   }
		   }
	}
	if(black != 13) return 0;
	return 1;
	}
	

    if (y == N) return countDraws(board, x + 1, 0);  // 换行，继续填充下一行

    int totalDraws = 0;
    
    // 尝试放黑棋、白棋或不放棋子
    for (int player = 1; player <= 2; player++) {  // 1为黑棋，2为白棋
        board[x][y] = player;
        if (!hasFiveInARow(board)) {  // 如果没有五子连珠，则继续
            totalDraws += countDraws(board, x, y + 1);
        }
        board[x][y] = 0;  // 恢复状态
    }
    return totalDraws;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));  // 初始化棋盘，0为未填充状态
    int result = countDraws(board, 0, 0);
    cout << "Total number of draw positions: " << result << endl;
    return 0;
}
