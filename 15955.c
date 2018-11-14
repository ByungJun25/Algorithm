/*
�� üũ����Ʈ���� ���� üũ����Ʈ������ �׷����� ���� BFS ����. �����ϸ� YES, ť�� ��� NO.
�� ������ �ʿ��� �ּ� HP�� ���(weight)
�ּ� HP�� |ix-jx|, |iy-jy|�� �� �� ���� ���̴�.

adj[N][N] �̸� adj[i][j]�� i��° üũ����Ʈ���� j��° üũ����Ʈ�� �� �� �ʿ��� �ּ� HP�� ����Ѵ�.
BFS�� ������, ������, HP�� ���ڸ� ������
��������� ���� HP���ں��� Ŭ ���� �̵��� �� �ִ�.
BFS�� ť�� �켱����ť�� ����ϰ�, Ű���� ���������� ���������� x��, y�� ���� �Ÿ� �� �ּҰ��̴�.
*/
#include <stdio.h>
#include <stdlib.h>

#define WHITE 1
#define BLACK 0

typedef struct _node {
	int x;
	int y;
}node;

typedef struct _queue {
	int node_num;
	int key;
}_queue;

int N, Q;
int** adjMatrix;
int* visit;
int r;

node* checkpoint;
_queue* min_heap;

int get_c_count(int current_index)
{
	if (((current_index * 2) + 1) <= r)
	{
		return 2;
	}
	else if ((current_index * 2) <= r)
	{
		return 1;
	}
	return 0;
}

void push(int got_node_num, int got_key)
{
	int target_index, current_index;
	_queue temp;
	min_heap[++r].key = got_key;
	min_heap[r].node_num = got_node_num;
	current_index = r;
	target_index = current_index / 2;
	while (target_index >= 1 && min_heap[current_index].key < min_heap[target_index].key)
	{
		temp = min_heap[current_index];
		min_heap[current_index] = min_heap[target_index];
		min_heap[target_index] = temp;
		current_index = target_index;
		target_index = current_index / 2;
	}
}
_queue pop()
{
	int c_count, current_index;
	_queue result, lc, rc, temp;
	result = min_heap[1];
	min_heap[1] = min_heap[r--];
	current_index = 1;
	while (1)
	{
		c_count = get_c_count(current_index);
		if (c_count == 0)
		{
			break;
		}
		else if (c_count == 1)
		{
			lc = min_heap[(current_index * 2)];
			if (min_heap[current_index].key > lc.key)
			{
				temp = min_heap[current_index];
				min_heap[current_index] = lc;
				min_heap[current_index * 2] = temp;
				current_index *= 2;
			}
			else
			{
				break;
			}
		}
		else
		{
			lc = min_heap[(current_index * 2)];
			rc = min_heap[((current_index * 2) + 1)];
			if (lc.key < rc.key)
			{
				if (min_heap[current_index].key > lc.key)
				{
					temp = min_heap[current_index];
					min_heap[current_index] = lc;
					min_heap[current_index * 2] = temp;
					current_index *= 2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (min_heap[current_index].key > rc.key)
				{
					temp = min_heap[current_index];
					min_heap[current_index] = rc;
					min_heap[((current_index * 2) + 1)] = temp;
					current_index *= 2;
					current_index++;
				}
				else
				{
					break;
				}
			}
		}
	}
	return result;
}
int isempty()
{
	if (r == 0)
	{
		return 1;
	}
	return 0;
}


// i�������� j�� ���������� x��, y�� ������ �Ÿ� �� �ּҰ�
int calc(int ix, int iy, int jx, int jy) {
	return min(abs(ix - jx), abs(iy - jy));
}

int BFS(int S, int D, int HP) {
	_queue temp;

	visit[S] = BLACK;
	push(S, calc(checkpoint[S].x, checkpoint[S].y, checkpoint[D].x, checkpoint[D].y));

	while (!(isempty())) {
		temp = pop();
		visit[temp.node_num] = BLACK;

		if (D == temp.node_num)
			return 1;
		for (int i = 1; i <= N; i++) {
			if (i != temp.node_num) {
				if (adjMatrix[temp.node_num][i] <= HP && visit[i] == WHITE) {
					push(i, calc(checkpoint[i].x, checkpoint[i].y, checkpoint[D].x, checkpoint[D].y));
				}
			}
		}
	}
	return 0;
}


int main() {

	
	int A, B;
	int S, D, HP;
	int result;

	freopen("input.txt", "r", stdin);

	scanf("%d %d\n", &N, &Q);
	checkpoint = (node*)malloc(sizeof(node) * (N + 1));
	adjMatrix = (int**)malloc(sizeof(int*) * (N+1));
	for (int i = 0; i <= N; i++) {
		adjMatrix[i] = (int*)malloc(sizeof(int) * (N + 1));
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &A, &B);
		checkpoint[i].x = A;
		checkpoint[i].y = B;
	}

	for (int i = 1; i < N; i++) {
		for (int j = i+1; j <= N; j++) {
			int temp;
			temp = calc(checkpoint[i].x, checkpoint[i].y, checkpoint[j].x, checkpoint[j].y);
			adjMatrix[i][j] = temp;
			adjMatrix[j][i] = temp;
		}
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d", &S, &D, &HP);
		min_heap = (_queue*)malloc(sizeof(_queue) * (N+1));
		visit = (int*)malloc(sizeof(int) * (N + 1));

		for (int i = 1; i <= N; i++)
			visit[i] = WHITE;

		r = 0;
		result = BFS(S, D, HP);
		
		if (result == 1)
			printf("YES\n");
		else
			printf("NO\n");

		free(visit);
		free(min_heap);
	}

	free(checkpoint);
	for (int i = 0; i <= N; i++) {
		free(adjMatrix[i]);
	}
	free(adjMatrix);

	return 0;
}