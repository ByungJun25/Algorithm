/*
H[i]�� hi���� ���� �����Ѵ�.
Dp[i]�� hi������ ��� �� ���� �� �� �ִ� ������ ������ �����Ѵ�.
curve�� ������ �߼��� �����Ѵ�. Ŀ���� �ִ� �߼��� UP, �۾����� ������ DOWN
check�� ������ �������� �� �� �ִ� ���� �����Ѵ�.

i<j�϶�, dp[j] = dp[i]�̰�, curve[i]==curve[j]�̸� check += 1; �ƴϸ� check = 0; 
i>j�̸�, dp[j] = dp[i] + check;
*/
#include <stdio.h>
#include <stdlib.h>

#define UP 1
#define DOWN 0

int* H;
int* DP;
int* curve;
int check;

int main(void)
{
	int test_case;
	int T;

	int N;
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &N);
		
		H = (int*)malloc(sizeof(int) * N);
		DP = (int*)malloc(sizeof(int) * N);
		curve = (int*)malloc(sizeof(int)*N);

		for (int i = 0; i < N; i++) {
			scanf("%d", &H[i]);
			if (i > 0) {
				if (H[i - 1] > H[i]) curve[i] = DOWN;
				else curve[i] = UP;
			}
			else
				curve[i] = UP;
		}

		DP[0] = 0;
		check = 0;
		for (int i = 1; i < N; i++) {
			if (curve[i] == UP) {
				DP[i] = DP[i - 1];
				if (curve[i - 1] == curve[i])
					check++;
				else
					check = 1;
			}
			else {
				DP[i] = DP[i - 1] + check;
			}
		}

		printf("#%d %d\n", test_case, DP[N - 1]);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}