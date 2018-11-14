/* �׷����� bfs�� �̿��ؼ� Ǯ���.
** n�� ������ (n+1)x(n+1)�� �迭�� ����� ��� adjMatrix��
** �տ����� ������ a�� b���̿� edge�� ��������
** ���� ���տ� ���ԵǾ� �ִ����� ã�� ������ a�� �������� bfs Ž���� �ؼ� b�� �ִ��� Ȯ��
*/

#include <stdio.h>
#include <stdlib.h>


int** adjMat;
int n, m;

int* visit;
int* queue;
int rear, front;

int breadthFirstSearch(int vertex, int target)
{
	int i;
	int flag = 0;

	visit[vertex] = 1;
	queue[rear++] = vertex;
	while (front < rear)
	{

		vertex = queue[front++];
		if (vertex == target) {
			flag = 1;
			break;
		}
			
		for (i = 1; i <= n; i++)
		{
			if (adjMat[vertex][i] == 1 && !visit[i])
			{
				visit[i] = 1;
				queue[rear++] = i;
			}
		}
	}

	return flag;
}

int main() {

	int t, T;
	int a, b, opt;
	int flag;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d %d", &n, &m);
		printf("#%d ", t + 1);
		adjMat = (int**)malloc(sizeof(int*) * (n + 1));
		for (int i = 0; i <= n; i++)
			adjMat[i] = (int*)malloc(sizeof(int) * (n + 1));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				adjMat[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &opt, &a, &b);
			
			//�տ����϶�
			if (opt == 0) {
				//edge ����
				adjMat[a][b] = 1;
				adjMat[b][a] = 1;
			}
			//���� �������� Ȯ���ϴ� �����϶�
			else if (opt == 1) {
				visit = (int*)malloc(sizeof(int) * (n + 1));
				queue = (int*)malloc(sizeof(int) * (n + 1));
				for (int i = 0; i <= n; i++) {
					visit[i] = 0;  queue[i] = 0;
				}

				front = 0;  rear = 0;
				flag = breadthFirstSearch(a,b);
				printf("%d", flag);

				free(visit);
				free(queue);
			}
			else {
				printf("error!\n");
				printf("%d��° TestCase���� %d��° ����\n", t + 1, m + 1);
			}
		}

		for (int i = 0; i <= n; i++)
			free(adjMat[i]);
		free(adjMat);
		printf("\n");
	}

	return 0;
}