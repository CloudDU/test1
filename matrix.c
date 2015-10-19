#include<stdio.h>

void input_matrix(int *a, int m, int n)	//输入矩阵
{
	int i, j;
	printf("请输入%d行%d列的矩阵：\n", m, n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", (a + n*i + j));		//将二维数组看成一维进行存储
}
void print_matrix(int *a, int m, int n)	//打印矩阵
{
	int i, j;
	printf("%d行%d列的矩阵：\n", m, n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%4d", *(a + n*i + j));
		printf("\n");
	}
}
int main(void)
{
  int ma[N][N];
	int i, j, m, n;
	printf("请输入矩阵的行、列数：\n");
	scanf("%d%d", &m, &n);		//m表示行，n表示列
	input_matrix(ma, m, n);
	print_matrix(ma, m, n);
}
