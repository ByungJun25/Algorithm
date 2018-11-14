/* 
check�� �������� ������ ������� �� �ִ� ���ڵ��� üũ�Ѵ�. 
	ex) check[700] = true �̸�, �������� ������ 700�� ���� �� �ִٴ� ��
people�� �������� Ű�� �����Ѵ�.
max�� ������� �������� Ű�� ���� �� �� �ִ밪�� �����Ѵ�.

1. 
people�� 1���� N������ ������ ����
max���� �����ؼ� �پ��鼭 check[j]�� ���̸�, check[j+people[i]]�� ��
max�� += people[i]�� ���ش�.
check[people[i]]�� ������ �ٲ�.

2.
check[B]���� ���� ���� ã�´�.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* check;
int* people;
int max;

int main() {
	
	int t, T;
	int N, B;
	bool flag = true;
	int result;
	int i;

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d", &N, &B);
		
		check = (bool*)malloc(sizeof(bool)*(N * 10000 + 1));
		people = (int*)malloc(sizeof(int) * N);

		for (i = 1; i <= N; i++) {
			scanf("%d", &people[i]);
			check[i] = false;
		}
		for (i = N + 1; i <= N * 10000; i++) {
			check[i] = false;
		}

		max = 0;
		for (i = 1; i <= N; i++) {
			for (int j = max; j > 0; j--) {
				if (check[j] == true) {
					check[j + people[i]] = true;
				}
			}
			max += people[i];
			check[people[i]] = true;
		}

		i = B; flag = true;
		while (flag) {
			if (check[i] == true) {
				result = i;
				flag = false;
			}
			i++;
		}

		printf("#%d %d\n", t, result-B);
	}
	return 0;
}