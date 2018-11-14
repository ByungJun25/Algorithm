#include <stdio.h>
#include <stdlib.h>

int N;
int* number;
int* DP;

int len_max;
int len;
int main() {

	scanf("%d", &N);
	number = (int*)malloc(sizeof(int) * N);
	DP = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
		DP[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		len = 0;
		for (int j = 0; j < i; j++) {
			if (number[i] < number[j]) {
				if (len < DP[j])
					len = DP[j];
			}
		}

		DP[i] = len + 1;
		
		len_max = len_max < DP[i] ? DP[i] : len_max;
	}

	printf("%d\n", len_max);

	return 0;
}