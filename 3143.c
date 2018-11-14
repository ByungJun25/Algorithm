/*
a���ڿ����� b���ڿ��� �ɷ����� �Ѵ�!

a[i]�� b[top]�� ������ push a[i+top]�� b[top]�� stack�� �� �������� ������ ans++�ϰ� i�� i+top+1�� �ٲ�
					   push a[i+top]�� b[top]�� �߰��� �޶����� stack�� ���� i++���� ó������ ���ư�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stack;
int top;
int stack_size;

int ans;
char A[10005];
int alen;
char B[105];

void push(char* stack, char c) {
	stack[top] = c;
	top++;
}

void pop(char* stack) {
	top--;
}

int isfull(char* stack) {
	return stack_size == top ? 1 : 0;
}

void init(char* stack) {
	top = 0;
}

int main() {
	
	int i, t, T;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%s %s", &A, &B);
		
		stack_size = strlen(B);
		alen = strlen(A);
		stack = (char*)malloc(sizeof(char) * stack_size);

		init(stack);
		ans = i = 0;
		while (i < alen) {
			if (A[i] == B[top]) {
				push(stack, A[i]);
				while (!isfull(stack)) {
					if (A[i + top] == B[top])
						push(stack, A[i + top]);
					else
						break;
				}
				if (isfull(stack)) {
					ans++;
					i = i + top;
					init(stack);
				}
				else {
					init(stack);
					i++;
					ans++;
				}

			}
			else {
				ans++;
				i++;
			}
		}
		free(stack);
		printf("#%d %d\n", t, ans);
	}

	return 0;
}