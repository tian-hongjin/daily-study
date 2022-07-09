#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  //memcmp对应头文件
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3 };
//	int ret = memcmp(arr1, arr2, 3 * sizeof(int));
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//int my_memcmp(const void* ptr1, const void* ptr2, size_t num)
//{
//	assert(ptr2 && ptr2);
//	size_t count = 0;  //用来标记相等的字节数
//	while (*(char*)ptr1 == *(char*)ptr2 && count < num)  //一直循环，直到找到不相等的字节数据
//	{
//		count++;  //进入一次循环表示有一对字节相等，count++
//		ptr1 = (char*)ptr1 + 1;
//		ptr2 = (char*)ptr2 + 1;
//	}
//	if (count < num)  //如果count小于num，说明两块内存的前num个字节中有不相等的数据
//		return *(char*)ptr1 - *(char*)ptr2;  //直接返回数据的差值
//	else
//		return 0;  //count等于num，说明相等
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3 };
//	int ret = my_memcmp(arr1, arr2, 3 * sizeof(int));
//	printf("%d\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//void* my_memset(void* dest, int c, size_t num)
//{
//	assert(dest != NULL);
//	void* ret = dest;  //记录目标空间的地址
//	while (num--)  //循环将num个字节的内容初始化为指定值
//	{
//		*(char*)dest = c;
//		dest = (char*)dest + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	char str[] = "hello world";
//	my_memset(str, 'x', 5);
//	printf("%s\n", str);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//void* my_memmove(void* dest, void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;  //保存目标空间的地址
//	if (dest < src)
//	{
//		//前 -> 后 等价于memcpy
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//后 -> 前
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	my_memmove(arr + 5, arr + 3, 4 * sizeof(int));
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}