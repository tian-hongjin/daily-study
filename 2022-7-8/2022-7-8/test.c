#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  //strncpy对应的头文件
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = "";
//	strncpy(arr2, arr1, sizeof(arr1) / sizeof(arr1[0]) * 1);
//	//sizeof(arr)/sizeof(arr[0]) 求得数组元素个数，*1 乘以每个元素的大小，得到整个数组的字节数
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>  //strncat对应的头文件
//int main()
//{
//	char arr1[] = "world!";
//	char arr2[20] = "hello ";
//	strncat(arr2, arr1, 8 * 1);
//	//sizeof(arr)/sizeof(arr[0]) 求得数组元素个数，*1 乘以每个元素的大小，得到整个数组的字节数
//	printf("%s\n", arr2);
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>  //strncmp对应的头文件
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcq";
//	int len = strncmp(arr2, arr1, 3);
//	printf("%d\n", len);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	//中途匹配失败需要回到str2开头，所以用其他变量标识str2，保证str2的首地址不会丢失
//	const char* p1 = str1;
//	const char* p2 = str2;
//	const char* mark = str1;  //用来标记每次第一个字符成功匹配的位置
//	while (*mark != '\0')
//	{
//		p1 = mark;  //从mark处开始往后匹配
//		p2 = str2;  //每次匹配后p2回到str2开头
//		while (*p1 == *p2 && *p2 != '\0')  //一直往后匹配，直到遇到不相等的字符
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0')  //如果不相等处p2为'\0'(子串全部匹配成功)，则返回Mark处地址
//			return (char*)mark;
//		mark++;  //否则，说明这一次匹配失败，从mark后面一个字节处开始重新匹配
//	}
//	return NULL;  //字符串找完都没有子串就返回空指针
//}
//
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bcd";
//	char* ret = my_strstr(arr1, arr2);
//	printf("%s\n", ret);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* sep = "@.";
//	char email[] = "1684277750@qq.com";
//	char tmp[20] = "";
//	//由于strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都会临时拷贝一份，操作拷贝的数据
//	strcpy(tmp, email);
//	printf("%s\n", strtok(tmp, sep));  //第一次第一个参数传递被切割字符串的首地址
//	printf("%s\n", strtok(NULL, sep));   //第二次及以后第一个参数传递空指针（strtok会记住上一次切割的位置）
//	printf("%s\n", strtok(NULL, sep));
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* sep = "@.";
//	char email[] = "1684277750@qq.com";
//	char tmp[20] = "";
//	//由于strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都会临时拷贝一份，操作拷贝的数据
//	strcpy(tmp, email);
//	char* ret = NULL;  //用来保存strtok函数的返回值
//	for (ret = strtok(tmp, sep);   //初始化部分：第一次传递tmp的地址
//		ret != NULL;               //判断部分：只要strtok的返回值ret不为空，说明继续分割
//		ret = strtok(NULL, sep))   //调整部分：第二次及以上传递NULL
//	{
//		printf("%s\n", ret);  //ret不为空，说明字符串没被分割完，则打印
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>  //strerror的头文件
//int main()
//{
//	printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));
//	printf("%s\n", strerror(5));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>  //strerror对应头文件
//#include <errno.h>   //errno对应头文件
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//		printf("文件打开成功！\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>   //memcpy对应头文件
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[10] = { 0 };
//	memcpy(arr2, arr1, 6 * sizeof(int));
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;  //保存目标空间的地址
//	while (num--)   //以字节为单位进行拷贝
//	{
//		*(char*)dest = *(char*)src;  //强转为char*类型后赋值
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 ,7,8 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr1 + 2, arr1, 4 * sizeof(int));
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

#include <stdio.h>
#include <string.h>  //memmove对应头文件
int main()
{
	int arr1[] = { 1,2,3,4,5,6 ,7,8 };
	int arr2[10] = { 0 };
	memmove(arr1 + 2, arr1, 4 * sizeof(int));
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}