void multiply_matrix(int *a, int m1, int n1, int *b, int m2, int n2, int *c)		//矩阵相乘
{
	int i, j, k;
	for (i = 0; i < m1; i++)
		for (j = 0; j < n2; j++)
			for (k = 0; k < n1; k++)
				*(c + n2*i + j) += *(a + n1*i + k) * *(b + n2*k + j);
}
/*
  参数说明：m1和n1为矩阵a的行和列；m2和n2为矩阵b的行和列；
  前提n1 == m2,才能运行该程序;
  使用方式：multiply_matrix(ma,m1,n1,mb,m2,n2,mc);
  mc的声明：int mc[N][N] = { 0 };
*/
