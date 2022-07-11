#define _CRT_SECURE_NO_WARNINGS 1
//求最大公约数和最小公倍数之和（多组输入）
#include <stdio.h>
//int main()
//{
//	long long n = 0;
//	long long m = 0;
//	while (scanf("%lld %lld", &n, &m) == 2)
//	{
//		long long a = n;  //将n和m赋值给a和b，防止使用辗转相除法改变它们的值
//		long long b = m;
//		long long gcd = 0;
//		long long lcm = 0;
//		while (b)  //辗转相除法求最大公约数
//		{
//			long long rem = a % b;
//			a = b;
//			b = rem;
//		}
//		gcd = a;
//		lcm = n * m / gcd;  //最小公倍数 = n * m /最大公约数
//		printf("%lld\n", gcd + lcm);
//	}
//	return 0;
//}

//打印空心正方形
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        char arr[n][n];  //C99的变长数组
//        int i = 0;
//        int j = 0;
//        for (i = 0; i < n; i++)
//        {
//            for (j = 0; j < n; j++)
//            {
//                if (i == 0 || i == n - 1)
//                    arr[i][j] = '*';
//                else if (j == 0 || j == n - 1)
//                    arr[i][j] = '*';
//                else
//                    arr[i][j] = ' ';
//            }
//        }
//        for (i = 0; i < n; i++)
//        {
//            for (j = 0; j < n; j++)
//            {
//                printf("%c ", arr[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//打印剑形
//#include <stdio.h>
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) == 1)
//    {
//        char arr[n][n];
//        int i = 0;
//        int j = 0;
//        for (i = 0; i <= n; i++)
//        {
//            for (j = 2 * (n - i); j > 0; j--)
//                printf(" ");
//            for (j = 0; j <= i; j++)
//                printf("*");
//            printf("\n");
//        }
//        for (i = 1; i <= n; i++)
//        {
//            for (j = 0; j < 2 * i; j++)
//                printf(" ");
//            for (j = n - i + 1; j > 0; j--)
//                printf("*");
//            printf("\n");
//        }
//    }
//    return 0;
//

//#include <stdlib.h>
//#define MAX_SIZE 5
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);

int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}