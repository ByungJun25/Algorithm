/*
�������� ����� �� ���� ����Ⱑ �󸶳� ����ִ����� üũ�Ѵ�.
stack�� ���!
�Էµ���Ÿ�� (�̸� ���ÿ� �״´�.
)�϶�, ���� ���� ���� ó���� ���ش���
	(�̸� �������� ��ٴ� �� -> top�� �ε����� ���� ���� ������� �� ��ŭ ������ �����
	)�̸� ����Ⱑ �����ٴ� �� -> ������ �ϳ� �����
���� top�� (�� pop�Ѵ�.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100000];
int input_size;

char* stack;
int top;

void push(char* stack, char data) {
	top++;
	stack[top] = data;
}
void pop(char* stack) {
	top--;
}

int empty(char* stack) {
	if (top == 0)
		return 1;
	else
		return 0;
}

int main(void)
{
	int test_case;
	int T;
	int ans;
	int flag; // ���� �����Ͱ� (���� )���� ����

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", &input);
		input_size = strlen(input);

		stack = (char*)malloc(sizeof(char) * input_size);
		ans = top = 0;

		for (int i = 0; i < input_size; i++) {
			char temp = input[i];
			if (temp == '(') {
				push(stack, temp);
				flag = 0;
			}
			else {
				pop(stack);
				if (flag == 0) {
					ans += top;
				}
				else {
					ans++;
				}
				flag = 1;
			}
		}
		free(stack);

		printf("#%d %d\n", test_case, ans);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}