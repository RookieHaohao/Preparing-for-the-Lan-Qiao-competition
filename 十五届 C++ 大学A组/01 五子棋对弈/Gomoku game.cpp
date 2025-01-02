#include <iostream>
#include <vector>

using namespace std; 

const int N = 5;  // ���̴�СΪ 5 * 5
const int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};  // �ĸ����򣺺ᡢ�ݡ���б����б

// �ж��Ƿ�����������
bool hasFiveInARow(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;  // �ո�������
            int player = board[i][j];  // ��ǰ���
            // �ĸ�������
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
                if (count >= 5) return true;  // �ҵ���������
            }
        }
    }
    return false;  // û����������
}

// �����㷨��������������������
int countDraws(vector<vector<int>>& board, int x, int y) {
	// ���������ˣ����м��
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
	

    if (y == N) return countDraws(board, x + 1, 0);  // ���У����������һ��

    int totalDraws = 0;
    
    // ���Էź��塢����򲻷�����
    for (int player = 1; player <= 2; player++) {  // 1Ϊ���壬2Ϊ����
        board[x][y] = player;
        if (!hasFiveInARow(board)) {  // ���û���������飬�����
            totalDraws += countDraws(board, x, y + 1);
        }
        board[x][y] = 0;  // �ָ�״̬
    }
    return totalDraws;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));  // ��ʼ�����̣�0Ϊδ���״̬
    int result = countDraws(board, 0, 0);
    cout << "Total number of draw positions: " << result << endl;
    return 0;
}
