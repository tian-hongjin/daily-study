#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* left_rotate(char arr[], int n)  //����ֵΪchar*������ʵ����ʽ����
//{
//	assert(arr != NULL);
//	char* ret = arr;  //��¼arr�ĵ�ַ���ڷ���
//	int len = strlen(arr);
//	n %= len;  //ʹ�õ�n�����ַ�������ʱ������ֻ��Ҫ����С��len�Σ����Ч�ʣ�Ҳ����Խ��
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		char tmp = arr[0];   //���ַ����еĵ�һ��λ�õ��ַ��ó���
//		for (j = 0; j < len - 1; j++)   //���ַ���������ǰŲ��һ���ַ�('\0'����)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;  //����һ���ַ��ŵ�ĩβ'\0'��ǰ��
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int n = 0;
//	scanf("%d", &n);
//	left_rotate(arr, n);  //��arr����n���ַ�
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//void reverse(char* left, char* right)  //�����ַ���
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
//char* left_rotate(char arr[], int n)   //����ֵΪchar*������ʵ����ʽ����
//{
//	assert(arr != NULL);
//	char* ret = arr;  //��¼arr�ĵ�ַ���ڷ���
//	int len = strlen(arr);
//	n %= len;   //ʹ�õ�n�����ַ�������ʱ������ֻ��Ҫ����С��len�Σ����Ч�ʣ�Ҳ����Խ��
//	reverse(arr, arr + n - 1);        //��תǰ��n���ַ�
//	reverse(arr + n, arr + len - 1);  //��ת����n���ַ�
//	reverse(arr, arr + len - 1);      //��ת�����ַ���
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int n = 0;
//	scanf("%d", &n);
//	left_rotate(arr, n);  //��arr����n���ַ�
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
//	int y = col - 1;  //�ҵ����Ͻǵ�Ԫ��
//
//	//�ṹ������ĳ�ʼ����ע�����ﲻҪ��ʼ��Ϊ0 0��Ӧ�ó�ʼ��Ϊ�����������������ΪĿ��Ԫ�ؿ�����0 0 ��
//	f.x = -1;
//	f.y = -1;
//
//	int i = 0;
//	int j = 0;
//	for (i = x; i < row; i++) //x<row �����ҵı߽�
//	{
//		for (j = y; j >= 0; j--)  //y>=0 �����ҵı߽�
//		{
//			if (n > arr[x][y])
//				x++;  //���Ŀ��Ԫ�ش������Ͻ�Ԫ�أ���x++��ֱ�Ӳ��ҵڶ��е�Ԫ��
//			else if (n < arr[x][y])
//				y--;  //���Ŀ��Ԫ��С�����Ͻ�Ԫ�أ���y--��ֱ�Ӳ���ǰ��һ�е�Ԫ��
//			else
//			{
//				f.x = x;  //�ҵ��˾�ʹ�ýṹ���¼����
//				f.y = y;
//				return 1;  //�ҵ�����1
//			}
//		}
//	}
//	return 0;  //û�ҵ�����0
//}
//
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int n = 0;  //Ҫ���ҵ�����
//	scanf("%d", &n);
//	int ret = find_num(arr, 3, 3, n);
//	if (ret == 1)
//		printf("arr[%d][%d] = %d\n", f.x, f.y, n);
//	else
//		printf("û�ҵ�\n");
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