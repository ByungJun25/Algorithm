/*
input data�� room�̶�� 2���� �迭�� �����Ѵ�.
N^2 ũ���� 1���� �迭 cnt�� 0���� �ʱ�ȭ �Ǿ��ִ�.

room[0][0]���� room[N][N]���� Ž���Ѵ�.
room[i][j]�� ���� cnt[room[i][j]-1]�� ���� 1���� ũ�� cnt[room[i][j]]�� ���� cnt[room[i][j]-1]�� -1�� �ȴ�.
1�����̸� ���� Ž������ ���� ���̹Ƿ� ���� �� �� �̵��� �� �ִ��� ����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

int N;
int** room;
int* cnt;

void passRoom(int i, int j, int value) {
	int flag = 0;

	if (i > 0 && flag == 0) {
		if (value + 1 == room[i - 1][j]) {
			passRoom(i - 1, j, room[i - 1][j]);
			flag = 1;
		}
	}

	if (j > 0 && flag == 0) {
		if (value + 1 == room[i][j - 1]) {
			passRoom(i, j - 1, room[i][j - 1]);
			flag = 1;
		}
	}

	if (i < N-1 && flag == 0) {
		if (value + 1 == room[i + 1][j]) {
			passRoom(i + 1, j, room[i + 1][j]);
			flag = 1;
		}
	}

	if (j < N-1 && flag == 0) {
		if (value + 1 == room[i][j + 1]) {
			passRoom(i, j + 1, room[i][j + 1]);
			flag = 1;
		}
	}

	if (flag == 0)
		cnt[value] = 1;
	else
		cnt[value] = cnt[value + 1] + 1;
}

int main(void)
{
	int test_case;
	int T;
	int result_number;
	int result_count;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		room = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; i++)
			room[i] = (int*)malloc(sizeof(int) * N);
		cnt = (int*)malloc(sizeof(int)*(N*N + 1));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &room[i][j]);
				cnt[i*N + j + 1] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cnt[room[i][j] - 1] > 1 && room[i][j] != 1)
					cnt[room[i][j]] = cnt[room[i][j] - 1] - 1;
				else
					passRoom(i,j,room[i][j]);
			}
		}

		result_number = 1;
		result_count = cnt[1];
		for (int i = 2; i <= N * N; i++) {
			if (cnt[result_number] < cnt[i]) {
				result_number = i;
				result_count = cnt[i];
			}
		}
		
		free(cnt);
		for (int i = 0; i < N; i++)
			free(room[i]);
		free(room);

		printf("#%d %d %d\n", test_case, result_number, result_count);

	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}