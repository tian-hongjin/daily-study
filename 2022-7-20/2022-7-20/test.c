#define _CRT_SECURE_NO_WARNINGS 1
//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
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

///������������ڣ���������һ��ĵڼ��졣��֤���Ϊ4λ�������ںϷ���
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

//��֤��Ƴ�˹���������κ�һ������m������������д��m����������֮�͡�
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