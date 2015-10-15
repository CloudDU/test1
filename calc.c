/*
 需求：实现计算器的基本功能；
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define PI 3.141592653589793

void quit()
{
	printf("是否继续？（0退出，其他键继续）\n");
	if (getch() == 0)
		exit(0);
}

void add()	//加法运算
{
	int i, n;	//n保存运算数的个数
	long long aa[MAX], sum = 0;
	printf("<<<<<加法运算>>>>>\n");
	printf("请你输入加数的个数：");
	scanf_s("%d", &n);
	printf("请输入%d个加数：\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%lld", &aa[i]);
		sum += aa[i];
	}
	printf("加法运算结果为：%lld\n",sum);
	
	quit();
}

void minus()	//减法运算
{
	int i, n;	//n保存减数个数
	long long ma, mb[MAX];
	printf("<<<<<减法运算>>>>>\n");
	printf("请你输入被减数：");
	scanf_s("%lld", &ma);
	printf("请输入减数个数:");
	scanf_s("%d", &n);
	printf("请输入%d个减数：\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%lld", &mb[i]);
		ma -= mb[i];
	}
	printf("减法运算结果为：%lld\n", ma);
	quit();
}

void multiply()	//乘法运算
{
	int i, n;	//n保存运算数的个数
	long long aa[MAX], mulnum = 1;
	printf("<<<<<乘法运算>>>>>\n");
	printf("请你输入乘数的个数：");
	scanf_s("%d", &n);
	printf("请输入%d个乘数：\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%lld", &aa[i]);
		mulnum *= aa[i];
	}
	printf("乘法运算结果为：%lld\n",	mulnum);

	quit();
}

void divided()	//除法运算
{
	int i, n;	//n保存除数个数
	long float da, db[MAX];
	printf("<<<<<除法运算>>>>>\n");
	printf("请你输入被除数：");
	scanf_s("%lf", &da);
	printf("请输入除数个数:");
	scanf_s("%d", &n);
	printf("请输入%d个除数：\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%lf", &db[i]);
		da /= db[i];
	}
	printf("除法运算结果为：%.10lf\n", da);
	quit();
}

void remaind()
{
	int i, n;	//n保存减数个数
	long  ra, rb[MAX];
	printf("<<<<<求余运算>>>>>\n");
	printf("请你输入被除数：");
	scanf_s("%ld", &ra);
	printf("请输入除数个数:");
	scanf_s("%d", &n);
	printf("请输入%d个除数：\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%ld", &rb[i]);
		ra %= rb[i];
	}
	printf("求余运算结果为：%ld\n", ra);
	quit();
}

void TentoOther()
{
	int i, zn, q, m, n;
	int a[MAX], b[MAX];
	double sn, xn;
	printf("请输入要转换的十进制数：");
	scanf_s("%lf", &sn);
	printf("请输入要转换的进制数：");
	scanf_s("%d", &q);

	zn = (int)sn;	//zn保存输入的十进制数的整数部分
	xn = sn - zn;	//xn保存输入的十进制数的小数部分
//	printf("整数部分是：%d;小数部分是：%lf\n", zn, xn);
	
	for (i = 0; zn !=0; i++)	//数组a保存q进制的整数部分
	{
		//整数部分采用辗转求余的方式
		a[i] = zn % q;		
		zn /= q;
	}
	m = i - 1;	//
	for (i = 0; xn != 0 && i < 30; i++)
	{
		//整数部分采用辗转求积的方式
		b[i] = (int)(xn * q);
		xn = xn * q - (int)(xn * q);
	}
	n = i;	//

	printf("%f的%d进制数为：", sn, q);
	for (i = m; i >= 0; i--)
	{
		switch (a[i])	//输出数值时整数部分某位若大于9，则以字母的形式出现
		{
		case 10:printf("A"); break;
		case 11:printf("B"); break;
		case 12:printf("C"); break;
		case 13:printf("D"); break;
		case 14:printf("E"); break;
		case 15:printf("F"); break;
		default:printf("%d", a[i]);
		}
	}
	if (sn != 0)	//如果是小数，则标上小数点
	{
		printf(".");
		for (i = 0; i < n; i++)	
		{
			switch (b[i])	//输出数值时整数部分某位若大于9，则以字母的形式出现
			{
			case 10:printf("A"); break;
			case 11:printf("B"); break;
			case 12:printf("C"); break;
			case 13:printf("D"); break;
			case 14:printf("E"); break;
			case 15:printf("F"); break;
			default:printf("%d", b[i]);
			}
		}
	}
	getch();
	printf("\n");
}

void OtherToTen()
{
	/*
	int i, n;
	char num[MAX];
	gets(num);
	n = strlen(num);
	for (i = 0; i < n; i++)
		printf("%d", num[i]);
		*/
	printf("sorry ~.~ ! DNF...please wait....");
}

void jinzhi()
{
	int c;
	printf("<<<<<进制转换运算>>>>>\n");
	printf("1.十进制数转换其他进制\n");
	printf("2.其他进制数转换十进制\n");
	printf("0.退出\n");
	printf("请选择：");

	scanf_s("%d", &c);
	system("cls");
	while (c != 0)
	{
		if (c >= 0 && c <= 2)
		{
			break;
		}
		else
		{
			printf("您输入有误请重新输入\n");
			scanf_s("%d", &c);
		}
	}
	switch (c)
	{
	case 1:TentoOther(); break;
	default:break;
	}
}

void sinx()
{
	double x, y;
	
	printf("<<<<<正弦运算>>>>>\n");
	printf("请输入度数:");
	scanf_s("%lf", &x);
	x = x * PI /180;
	y = sin(x);
	printf("sin(%lf)=%lf\n", x, y);
	getch();
	quit();
}

void arcsinx()
{
	double x, y;

	printf("<<<<<反正弦运算>>>>>\n");
	printf("请输入值:");
	scanf_s("%lf", &x);
	y = asin(x);	//在c语言中的math.h头文件中包含了反正弦函数asin()
	y = y * 180 / PI;
	printf("arcsin(%lf)=%lf\n", x, y);
	getch();
	quit();
}

void cosx()
{
	double x, y;

	printf("<<<<<余弦运算>>>>>\n");
	printf("请输入度数:");
	scanf_s("%lf", &x);
	x = x * PI / 180;
	y = cos(x);
	printf("cos(%lf)=%lf\n", x, y);
	getch();
	quit();
}

void arccosx()
{
	double x, y;

	printf("<<<<<反余弦运算>>>>>\n");
	printf("请输入值:");
	scanf_s("%lf", &x);
	y = acos(x);	//在c语言中的math.h头文件中包含了反余弦函数acos()
	y = y * 180 / PI;
	printf("arccos(%lf)=%lf\n", x, y);
	getch();
	quit();
}

void tanx()
{
	double x, y;

	printf("<<<<<正切运算>>>>>\n");
	printf("请输入值:");
	scanf_s("%lf", &x);
	x = x * PI / 180;
	y = tan(x);	
	printf("tan(%lf)=%lf\n", x, y);
	getch();
	quit();
}

void arctanx()
{
	double x, y;

	printf("<<<<<反正切运算>>>>>\n");
	printf("请输入值:");
	scanf_s("%lf", &x);
	y = atan(x);	//在c语言中的math.h头文件中包含了反正切函数atan()
	y = y * 180 / PI;
	printf("arctan(%lf)=%lf\n", x, y);
	getch();
	quit();
}

void ln()
{
	double x, y;

	printf("<<<<<ln运算>>>>>\n");
	printf("请输入值:");
	scanf_s("%lf", &x);
	y = log(x);
	printf("ln(%lf)=%.10lf\n", x, y);
	getch();
	quit();
}


void log10x()
{
	double x, y;

	printf("<<<<<log10运算>>>>>\n");
	printf("请输入值:");
	scanf_s("%lf", &x);
	y = log10(x);
	printf("log10(%lf)=%.10lf\n", x, y);
	getch();
	quit();
}


void powx()
{
	double a, x, y;

	printf("<<<<<指数运算>>>>>\n");

	printf("请输入a:");
	scanf_s("%lf", &a);
	if(a != 1 && a > 0)
	{	
		printf("请输入x：");
		scanf_s("%lf", &x);
		y = pow(a, x);
		printf("%lf^%lf=%.10lf\n", a, x, y);
	}	

	getch();
	quit();
}

void sqrtx()
{
	double x, y;

	printf("<<<<<开方运算>>>>>\n");

	printf("请输入:");
	scanf_s("%lf", &x);
	if (x >= 0)
	{
		y = sqrt(x);
		printf("%lf的开方=%.10lf\n", x, y);
	}
	getch();
	quit();
}

void calc_menu()	//主界面的显示函数
{
	int c;
	system("cls");
	printf("*****************************************\n");
	printf("*\t\t简易计算器\t\t*\n");
	printf("*****************************************\n");
	printf("按任意键进入\n");
	getch();
	system("cls");
	printf("欢迎使用简易计算器，请选择运算方式：\n");
	printf("1.加法\t\t2.减法\n");
	printf("3.乘法\t\t4.除法\n");
	printf("5.求余\t\t6.进制转换\n");
	printf("7.正弦\t\t8.反正弦\n");
	printf("9.余弦\t\t10.反余弦\n");
	printf("11.正切\t\t12.反正切\n");
	printf("13.ln\t\t14.log10\n");
	printf("15.指数函数\t16开方运算\n");
	printf("0.退出\n");
	printf("\n请选择您要进行的计算\n");

	scanf_s("%d",&c);
	system("cls");
	while (c != 0)
	{
		if (c >= 0 && c <= 16 )
		{
			break;
		}
		else
		{
			printf("您输入有误请重新输入\n");
			scanf_s("%d",&c);
		}
	}
	switch (c)
	{
	case 1:
		add(); calc_menu(); break;
	case 2:
		minus(); calc_menu(); break;
	case 3:
		multiply(); calc_menu(); break;
	case 4:
		divided(); calc_menu(); break;
	case 5:
		remaind(); calc_menu(); break;
	case 6:
		jinzhi(); calc_menu(); break;
	case 7:
		sinx(); calc_menu();  break;
	case 8:
		arcsinx(); calc_menu(); break;
	case 9:
		cosx(); calc_menu(); break;
	case 10:
		arccosx(); calc_menu(); break;
	case 11:
		tanx();  calc_menu();  break;
	case 12:
		arctanx(); calc_menu();  break;
	case 13:
		ln(); calc_menu();  break;
	case 14:
		log10x(); calc_menu(); break;
	case 15:
		powx(); calc_menu(); break;
	case 16:
		sqrtx(); calc_menu(); break;
	case 0:
		quit(); break;
	}

}


int main(void)
{
	system("color 1F");
	calc_menu();

	getchar();
	return 0;
}
