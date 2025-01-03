#include<iostream>
#include<vector>

using namespace std;

const int N = 5;
const int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

bool checkWin(const vector<vector<int>> & board, int x, int y){
	int player = board[x][y];
	//四个方向检查 
    for(auto dir : DIRECTIONS){
        int count = 1;
        // 向一个方向检查
        int dx = dir[0], dy = dir[1];
        int nx = x + dx, ny = y + dy;
        while(nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == player){
            count++;
            nx += dx;
            ny += dy;
        }
        // 向相反方向检查
        dx = -dir[0];
        dy = -dir[1];
        nx = x + dx, ny = y + dy;
        while(nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == player){
            count++;
            nx += dx;
            ny += dy;
        }
        // 如果在某个方向上连续相同棋子达到5个
        if(count >= 5) return true;
    }
	return false;
}

void printBoard(const vector<vector<int>>& board) {
	cout << "\n**************************\n";
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << " " << board[i][j];
		}
		cout<<"\n";
	}
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
		if(black != 13) {
			return 0;
		}
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


