#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* left_rotate(char arr[], int n)  //返回值为char*，用于实现链式访问
//{
//	assert(arr != NULL);
//	char* ret = arr;  //记录arr的地址用于返回
//	int len = strlen(arr);
//	n %= len;  //使得当n大于字符串长度时我们仍只需要左旋小于len次，提高效率，也避免越界
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		char tmp = arr[0];   //将字符串中的第一个位置的字符拿出来
//		for (j = 0; j < len - 1; j++)   //将字符串整体向前挪动一个字符('\0'不动)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;  //将第一个字符放到末尾'\0'的前面
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int n = 0;
//	scanf("%d", &n);
//	left_rotate(arr, n);  //将arr左旋n个字符
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void reverse(char* left, char* right)  //逆序字符串
//{
//	assert(left && right);
//	while (left <= right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//char* left_rotate(char arr[], int n)   //返回值为char*，用于实现链式访问
//{
//	assert(arr != NULL);
//	char* ret = arr;  //记录arr的地址用于返回
//	int len = strlen(arr);
//	n %= len;   //使得当n大于字符串长度时我们仍只需要左旋小于len次，提高效率，也避免越界
//	reverse(arr, arr + n - 1);        //翻转前面n个字符
//	reverse(arr + n, arr + len - 1);  //翻转后面n个字符
//	reverse(arr, arr + len - 1);      //翻转整个字符串
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int n = 0;
//	scanf("%d", &n);
//	left_rotate(arr, n);  //将arr左旋n个字符
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//
//struct flag
//{
//	int x;
//	int y;
//}f;
//
//int find_num(int arr[3][3], int row, int col, int n)
//{
//	int x = 0;
//	int y = col - 1;  //找到右上角的元素
//
//	//结构体变量的初始化，注意这里不要初始化为0 0，应该初始化为两个无意义的数，因为目标元素可能在0 0 处
//	f.x = -1;
//	f.y = -1;
//
//	int i = 0;
//	int j = 0;
//	for (i = x; i < row; i++) //x<row ：查找的边界
//	{
//		for (j = y; j >= 0; j--)  //y>=0 ：查找的边界
//		{
//			if (n > arr[x][y])
//				x++;  //如果目标元素大于右上角元素，则x++，直接查找第二行的元素
//			else if (n < arr[x][y])
//				y--;  //如果目标元素小于右上角元素，则y--，直接查找前面一列的元素
//			else
//			{
//				f.x = x;  //找到了就使用结构体记录坐标
//				f.y = y;
//				return 1;  //找到返回1
//			}
//		}
//	}
//	return 0;  //没找到返回0
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int n = 0;  //要查找的数字
//	scanf("%d", &n);
//	int ret = find_num(arr, 3, 3, n);
//	if (ret == 1)
//		printf("arr[%d][%d] = %d\n", f.x, f.y, n);
//	else
//		printf("没找到\n");
//	return 0;
//}

//#include <stdio.h>
//
//int gcd(int m, int n)
//{
//	int rem = 0;
//	while (n > 0)
//	{
//		rem = m % n;
//		m = n;
//		n = rem;
//	}
//	return m;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = gcd(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//
//int gcd(int m, int n)
//{
//	if (n == 0)
//		return m;
//	return gcd(n, m % n);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = gcd(a, b);
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//
//int Gcd(int n, int m)
//{
//	if (m == 0)
//		return n;
//	return Gcd(m, n % m);
//}
//
//int Lcm(int n, int m)
//{
//	int max = n > m ? n : m;
//	for (int i = max; ; i++)
//	{
//		if (i % n == 0 && i % m == 0)
//			return i;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	while (scanf("%d %d", &n, &m) == 2)
//	{
//		int gcd = Gcd(n, m);
//		int lcm = Lcm(n, m);
//		printf("%d\n", gcd + lcm);
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		scanf("%d", &n);
		int arr[10][10];
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == 0)
					printf("* ");
				else if (i == n - 1)
					printf("* ");
				else if (j == n - 1)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");
		}
	}
	return 0;
}