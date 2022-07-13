#define _CRT_SECURE_NO_WARNINGS 1
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,1,2,2,3,4,5,5,6,6 };
//	int tmp = 0;
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 10; i++)
//	{
//		tmp ^= arr[i];  //找出数组中两个不相同数字相异或的值
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if ((arr[i] ^ arr[j]) == tmp)
//			{
//				a = arr[i];
//				b = arr[j];
//				goto flag;
//			}
//		}
//	}
//flag:
//	printf("%d %d\n", a, b);
//	return 0;
//}

//模拟实现strncpy
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;  //记录目标空间的起始地址
//	while (num--)
//	{
//		*dest++ = *src++;
//		if (*dest == '\0')  //如果*dest为0，说明将src的结束字符赋给了dest，这种情况下源字符串的长度小于num
//		{
//			while (num--)
//			{
//				////如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个。(与库函数的实现方式保持一致）
//				*dest++ = 0;
//			}
//			break;
//		}
//	}
//	*dest = '\0';  //在dest的末尾补上结束字符
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10];
//	my_strncpy(arr2, arr1, 4);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[10];
//	strncpy(arr2, arr1, 4);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncat(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;  //记录目标空间的起始地址
//
//	//找到dest末尾
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//
//	//strncpy
//	while (num--)
//	{
//		*dest = *src;
//		if (*dest == '\0')  //如果*dest为0，说明将src的结束字符赋给了dest，这种情况下源字符串的长度小于num
//		{
//			//如果源字字符串的长度小于num，则只复制到终止空字符的内容。(与库函数的实现方式保持一致）
//			return ret; //直接返回
//		}
//		dest++;
//		src++;
//	}
//	*dest = '\0';  //如果循环正常结束，则在dest的末尾补上结束字符
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "ABC";
//	my_strncat(arr1, arr2, 5);
//	printf("%s\n", arr1);
//	return 0;
//}

//动态内存管理
//
//malloc
//#include <stdio.h>
//#include <stdlib.h>  //动态内存管理对应头文件
//#include <string.h>  //strerror对应头文件
//#include <errno.h>   //errno对应头文件
//
//int main()
//{
//	//申请40个字节的空间，交由指针变量p来管理
//	int* p = (int*)malloc(10 * sizeof(int));
//	//malloc申请空间可能会失败，所以要进行判断
//	//申请失败：打印错误信息并退出
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//申请成功：使用
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//使用完：释放
//	free(p);   //释放动态内存开辟的空间
//	p = NULL;  //将p置空，防止野指针
//}

//calloc
//#include <stdio.h>
//#include <stdlib.h>  //动态内存管理对应头文件
//#include <string.h>  //strerror对应头文件
//#include <errno.h>   //errno对应头文件
//
//int main()
//{
//	//申请40个字节的空间，交由指针变量p来管理
//	int* p = (int*)calloc(10, sizeof(int));
//	//calloc申请空间可能会失败，所以要进行判断
//	//申请失败：打印错误信息并退出
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//申请成功：使用
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//使用完：释放
//	free(p);   //释放动态内存开辟的空间
//	p = NULL;  //将p置空，防止野指针
//}

//realloc
#include <stdio.h>
#include <stdlib.h>  //动态内存管理对应头文件
#include <string.h>  //strerror对应头文件
#include <errno.h>   //errno对应头文件
//
//int main()
//{
//	//先开辟一块空间
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//扩容
//	//由于realloc可能会开辟失败，为了防止p指向realloc开辟失败的空间，从而丢失原来空间的情况，这里我们使用临时变量来判断realloc是否开辟成功
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	//申请失败：打印错误信息并退出
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//申请成功：让p指向该空间并使用
//	p = ptr;
//	for (int i = 0; i < 20; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//使用完：释放
//	free(p);   //释放动态内存开辟的空间
//	p = NULL;  //将p置空，防止野指针
//}
//
//void test()
//{
//	int* p = (int*)malloc(INT_MAX);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}

//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i < 5; i++)
//	{
//		*p = i;
//		p++;  //指针变量p自增导致其丢失动态内存的起始地址
//	}
//	free(p);
//}

//void test()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		exit(-1);
//	}
//	free(p);
//
//	//.......
//
//	free(p);//重复释放
//}

void test()
{
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL)
	{
		exit(-1);
	}
	int flag = 0;
	scanf("%d", &flag);
	if (flag == 2)
	{
		//...... --程序逻辑
		return;
	}
	else
	{
		//...... --程序逻辑
	}
	free(p);
	p = NULL;
}

int main()
{
	test();
	return 0;
}