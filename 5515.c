/*

month[13]���� i��0���� ������ �ԷµǾ� �ִ�.
1�� 1���� �ݿ����̹Ƿ� month[1]�� ���� ������� 3�� ��
������ month[m]+d/7�� ���� �����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

int month[13] = { 0, 3, 6, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2 };

int main() {

	int t, T;
	int m, d;
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (t = 1; t <= T; t++) {
		scanf("%d %d", &m, &d);
		printf("#%d %d\n", t, (month[m] + d) % 7);
	}

	return 0;
}