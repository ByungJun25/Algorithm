/* �� �غ��� �ǰδ�.
** ���带 4���� ���� �� �� ������ ����� -> ������ �ű� -> �������� Ȯ��. -> �ٽ� �����
** 1. ����̱� 2. �ű�� 3. ������ Ȯ��
** 1. ����̱�
**	��ͽἭ. 1- 1- 1- 1- .... 1- 2- 1- 1-.... ������
**	����϶��� ���° ����̴���, ���� ����  �Ķ� ���� ��ġ, ���� ���带 �Ѱ� ��
**
** 2. �ű�� 
**	�׳� �ű�� �ɵ�. BFS�� DFS �� �ʿ䵵 ���ڴ�. (�ƴϾ�� ����)
**	���带 �ѱ�� �ű⼭ �ű��.
**	�������� �ű涧��, ���ʿ� �ִ� �� ���� �ű��, ���������� �ű涧�� �����ʿ� �մ� �� ����..
**	�Ķ����� ������ ������ Ż��. �Ķ����� �Ⱥ����� �������� ������ ���
** 3. �������� Ȯ��
**	�Ķ� �� ������ �ٷ� ����Լ� break. ���� �� ������ ��� �� ���� ��, flag ����
*/

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLUE 0

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

int dirrow[4] = { -1,0,1,0 };
int dircol[4] = { 0,-1,0,1 };

int N, M;

typedef struct ball {
	int row;
	int col;
}ball;

int ans;

void copyMatrix(char** orgin, char** copy) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy[i][j] = orgin[i][j];
		}
	}
}

ball rolling(ball curball, char** board, int dir, int color) {

	ball nextball = curball;
	while (board[nextball.row + dirrow[dir]][nextball.col + dircol[dir]] == '.') {
		nextball.row += dirrow[dir];
		nextball.col += dircol[dir];
	}

	board[curball.row][curball.col] = '.';
	if (board[nextball.row + dirrow[dir]][nextball.col + dircol[dir]] == 'O') {
		nextball.row = -1; nextball.col = -1;
	}
	else {
		if (color == RED)
			board[nextball.row][nextball.col] = 'R';
		else if(color == BLUE)
			board[nextball.row][nextball.col] = 'B';
	}

	return nextball;
}

void tilt(int cnt, ball curRed, ball curBlue, char** origin) {

	char** tempBoard;
	ball nextRed;
	ball nextBlue;
	
	if (cnt > 10)
		return;

	tempBoard = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++)
		tempBoard[i] = (char*)malloc(sizeof(char) * M);

	for (int i = 0; i < 4; i++) {
		switch (i) {
		case UP:
			copyMatrix(origin, tempBoard);
			if (curRed.row < curBlue.row) {
				nextRed = rolling(curRed, tempBoard, UP, RED);
				nextBlue = rolling(curBlue, tempBoard, UP, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, UP, BLUE);
				nextRed = rolling(curRed, tempBoard, UP, RED);
			}
			if (nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		case DOWN:
			copyMatrix(origin, tempBoard);
			if (curRed.row > curBlue.row) {
				nextRed = rolling(curRed, tempBoard, DOWN, RED);
				nextBlue = rolling(curBlue, tempBoard, DOWN, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, DOWN, BLUE);
				nextRed = rolling(curRed, tempBoard, DOWN, RED);
			}
			if(nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		case LEFT:
			copyMatrix(origin, tempBoard);
			if (curRed.col < curBlue.col) {
				nextRed = rolling(curRed, tempBoard, LEFT, RED);
				nextBlue = rolling(curBlue, tempBoard, LEFT, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, LEFT, BLUE);
				nextRed = rolling(curRed, tempBoard, LEFT, RED);
			}
			if (nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		case RIGHT:
			copyMatrix(origin, tempBoard);
			if (curRed.col > curBlue.col) {
				nextRed = rolling(curRed, tempBoard, RIGHT, RED);
				nextBlue = rolling(curBlue, tempBoard, RIGHT, BLUE);
			}
			else {
				nextBlue = rolling(curBlue, tempBoard, RIGHT, BLUE);
				nextRed = rolling(curRed, tempBoard, RIGHT, RED);
			}
			if (nextBlue.row != -1 && nextBlue.col != -1) {
				if (nextRed.row != -1 && nextBlue.col != -1) {
					tilt(cnt + 1, nextRed, nextBlue, tempBoard);
				}
				else {
					ans = ans < cnt ? ans : cnt;
				}
			}
			break;
		}	
	}

	for (int i = 0; i < N; i++)
		free(tempBoard[i]);
	free(tempBoard);
}

int main() {

	char** board;
	ball Red;
	ball Blue;
	char dump;
	scanf("%d %d\n", &N, &M);
	
	board = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++)
		board[i] = (char*)malloc(sizeof(char) * M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &board[i][j]);

			if (board[i][j] == 'R') {
				Red.row = i; Red.col = j;
			}

			if (board[i][j] == 'B') {
				Blue.row = i; Blue.col = j;
			}
		}
		scanf("%c", &dump);
	}

	ans = 99;
	tilt(1, Red, Blue, board);

	if (ans == 99)
		printf("-1\n");
	else
		printf("%d\n", ans);

	for (int i = 0; i < N; i++)
		free(board[i]);
	free(board);

	return 0;
}