void Gauss_elimination(float *a, int m, int n)	//高斯消去法，求解线性方程
{
	int i, j, k;
	float r, t;
	if (m == n)
	{
		printf("此矩阵不是线性方程组的增广矩阵，所以无法求得此解。\n");
		return;
	}
	else
	{
		for (i = 0; i < m; i++)
		{
			r = *(a + n*i + i);				//保存主对角线上的元素
			for (k = i; k <= m; k++)		//i行归一化，各元素除以对角线元素
				*(a + n*i + k) /= r;		//若r绝对值很小可能溢出
			for (j = i + 1; j < m; j++)		//将下三角部分的i列消为0
			{
				t = *(a + n*j + i);
				for (k = i; k < n; k++)
					*(a + n*j + k) -= t * *(a + n*i + k);		//i行乘以-t加到j行，使a[j][i]为0
			}
		}
	}
	for (i = m - 2; i >= 0; i--)			//回代求各a[i][N]
		for (j = m - 1; j>i; j--)			//下标大于i的解a[j][N]已求出
			*(a + n*i + m) -= *(a + n*i + j) * *(a + n*j + m);		//用各a[j][N]回代，求出a[i][N]
		for (i = 0; i < m; i++)
			printf(" x%d= %2.1f\n", i+1, *(a + n*i + m));
}

/*
  使用方法:Gauss_elimination(ma,m,n);
  前提是定义了float ma[N][N];并且已经为ma赋值。
*/
