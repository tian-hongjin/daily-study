#define _CRT_SECURE_NO_WARNINGS 1
//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//int* printNumbers(int n, int* returnSize) {
//    // write code here
//    static int arr[100000];
//    int i = 0;
//    for (i = 1; i < (int)pow(10, n); i++)
//    {
//        arr[i - 1] = i;
//    }
//    *returnSize = --i;
//    return arr;
//}

///根据输入的日期，计算是这一年的第几天。保证年份为4位数且日期合法。
//#include <stdio.h>
//int main()
//{
//    int y = 0;
//    int m = 0;
//    int d = 0;
//    int ret = 0;
//    scanf("%d %d %d", &y, &m, &d);
//    int month[12] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//        month[2] += 1;
//    int i = 0;
//    for (i = 0; i < m; i++)
//        ret += month[i];
//    ret += d;
//    printf("%d\n", ret);
//}

//验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
#include <stdio.h>
int main()
{
	int m = 0;
	while (scanf("%d", &m) == 1)
	{
		int n = m * m * m;
		int i = 0;
		for (i = 1; i < n; i++)
		{
			int sum = 0;
			int j = i;
			int count = m;
			while (count--)
			{
				sum += j;
				j += 2;
			}
			if (sum == n)
			{
				count = m;
				j = i;
				while (count--)
				{
					if (count == 0)
						printf("%d", j);
					else
					{
						printf("%d+", j);
						j += 2;
					}
				}
				return 0;
			}
		}
	}
}