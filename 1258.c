/* �� ĭ�� ���ʴ�� ��.
** ���ٰ� 0�� �ƴ� ���� ������ �� ���� �������� �ؼ� sub matrix�� �� x ������ ���
** ����� row_cnt, col_cnt�� ���� cnt[row_cnt] = col_cnt�� ���·� �����
** �׸��� �ش� sub_matix�� matirx���� ��������(0���� �ڵ���)
** Ž���� �����.
** sub_mat ����� ���� ���� sub_matrix�� ��� �Ǵ��� ���
** sub_mat[[i].row -> i's row; sub_mat[i].col = cnt[i's row]�� ����
** sub_mat�� time�� ���� ����
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int row;
	int col;
	int size;
} sub_matrix;

void quickSort(sub_matrix* chem, int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (chem[i].size <= chem[pivot].size && i < last)
			{
				i++;
			}
			while (chem[j].size > chem[pivot].size)
			{
				j--;
			}
			if (i < j)
			{
				temp = chem[i].size;
				chem[i].size = chem[j].size;
				chem[j].size = temp;

				temp = chem[i].col;
				chem[i].col = chem[j].col;
				chem[j].col = temp;

				temp = chem[i].row;
				chem[i].row = chem[j].row;
				chem[j].row = temp;
			}
		}

		temp = chem[pivot].size;
		chem[pivot].size = chem[j].size;
		chem[j].size = temp;

		temp = chem[pivot].col;
		chem[pivot].col = chem[j].col;
		chem[j].col = temp;

		temp = chem[pivot].row;
		chem[pivot].row = chem[j].row;
		chem[j].row = temp;

		quickSort(chem, first, j - 1);
		quickSort(chem, j + 1, last);
	}
}


int main() {

	int T;
	int t;
	int n;
	int i, j;

	int row_cnt = 0;
	int col_cnt = 0;

	int** mat;
	int* cnt;
	sub_matrix* sub_mat;

	int n_submat;

	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		mat = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++)
			mat[i] = (int*)malloc(sizeof(int) * n);
		cnt = (int*)malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
			cnt[i] = 0;

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
			}
		}

		//mat ��� Ž��
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				// sub matrix Ȯ��
				if (mat[i][j] != 0) {
					//�ش� sub matrix�� row, col ���� ���
					int tempj = j;
					while (tempj < n && mat[i][tempj] != 0 ) {
						col_cnt++;
						tempj++;
					}
					int tempi = i;
					while (tempi < n && mat[tempi][j] != 0) {
						row_cnt++;
						tempi++;
					}
					//�ش� sub matrix ����
					for (tempi = i; tempi < i + row_cnt; tempi++) {
						for (tempj = j; tempj < j + col_cnt; tempj++) {
							if (mat[tempi][tempj] == 0) {
								printf("Error!\n");
							}
							mat[tempi][tempj] = 0;
						}
					}
					//�� ���� �� �ʱ�ȭ
					cnt[row_cnt] = col_cnt;
					row_cnt = 0; col_cnt = 0;
				}
			}
		}

		//submatrix�� ���� ���
		n_submat = 0;
		for (i = 0; i < n; i++) {
			if (cnt[i] != 0)
				n_submat++;
		}
		//sub_mat �����
		sub_mat = (sub_matrix*)malloc(sizeof(sub_matrix) * n_submat);
		j = 0;
		for (i = 0; i < n; i++) {
			if (cnt[i] != 0) {
				sub_mat[j].row = i;
				sub_mat[j].col = cnt[i];
				sub_mat[j].size = sub_mat[j].row * sub_mat[j].col;
				j++;
			}
		}

		//����
		quickSort(sub_mat, 0, n_submat-1);

		printf("#%d %d", t + 1, n_submat);
		for (i = 0; i < n_submat; i++) {
			printf(" %d %d", sub_mat[i].row, sub_mat[i].col);
		}
		printf("\n");
		
		for (int i = 0; i < n; i++)
			free(mat[i]);
		free(mat);
		free(cnt);
		free(sub_mat);
	}

	

	return 0;
}