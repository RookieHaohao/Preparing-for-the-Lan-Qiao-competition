#include<iostream>
#include<vector>

using namespace std;

const int N = 5;
const int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

bool checkWin(const vector<vector<int>> & board, int lastX, int lastY){
	int player = board[lastX][lastY];
	//四个方向检查 
    for(auto dir : DIRECTIONS){
        int count = 1;
        // 向一个方向检查
        int x = lastX + dir[0];
        int y = lastY + dir[1];
        while(x >= 0 && x < N && y >= 0 && y < N && board[x][y] == player){
            count++;
            x += dir[0];
            y += dir[1];
        }
        // 向相反方向检查
        x = lastX - dir[0];
        y = lastY - dir[1];
        while(x >= 0 && x < N && y >= 0 && y < N && board[x][y] == player){
            count++;
            x -= dir[0];
            y -= dir[1];
        }
        if(count >= 5) return true;  // 找到五子连珠
    }
    return false;  // 没有五子连珠
}

int countTotal( vector<vector<int>> & board,int x, int y){
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
	if(y == N) return countTotal(board, x + 1, 0);
	
	int total = 0;
	for(int player = 1; player <= 2; player++){
		board[x][y] = player;
		if(!checkWin(board, x, y)){
			total += countTotal(board, x, y + 1);
		}
		board[x][y] = 0;
	}
	return total;
}

int main(){
	vector<vector<int>> board(N, vector<int>(N, 0));
	cout << countTotal(board, 0, 0) << endl;
}
