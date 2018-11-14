/*

flag[N]�� �����Ҵ��ϰ� �� ���� 1�� �ʱ�ȭ�Ѵ�
K��ŭ �о�鼭 flag[k]�� 0���� set�Ѵ�.
flag[i]�� 1�� i�� ����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

int* flag;

int main() {

	int t, T;
	int N, K;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d %d", &N, &K);
		flag = (int*)malloc(sizeof(int) * (N+1));
		for (int i = 0; i <= N; i++) {
			flag[i] = 1;
		}

		for (int i = 0; i < K; i++) {
			int k;
			scanf("%d", &k);
			flag[k] = 0;
		}

		printf("#%d ", t);
		for (int i = 1; i <= N; i++) {
			if (flag[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}