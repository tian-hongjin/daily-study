#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  //strlen对应头文件
//int main()
//{
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>  //assert对应头文件
//
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);   //检查str是否为空指针
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>  //assert对应头文件
//
//size_t my_strlen(const char* str)   //const用于保护源字符串不被修改
//{
//	assert(str != NULL);
//	char* head = str;      //记录字符串开头的地址
//	while (*str++);        //找到字符串结束的地址
//	return str - head - 1; //指针-指针得到元素个数，-1减去\0
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>  //strcpy对应头文件
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = "";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>  //assert对应头文件
//
//char* my_strcpy(char* dest, const char* src)  //const用于保护源字符串
//{
//	assert(dest && src);  //保证传递过来的不是空串
//	char* ret = dest;  //记录目标空间的起始地址
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;  //将末尾的'\0'赋给dest
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = "";
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>  //assert对应头文件
//
//char* my_strcpy(char* dest, const char* src)  //const用于保护源字符串
//{
//	assert(dest && src);  //保证传递过来的不是空串
//	char* ret = dest;  //记录目标空间的起始地址
//	while (*dest++ = *src++);  //连同末尾的'\0'一起赋给了dest
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = "";
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//
//#include <stdio.h>
//#include <string.h>  //strcat对应头文件
//int main()
//{
//	char arr1[] = "world!";
//	char arr2[20] = "hello ";
//	strcat(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
//char* my_strcat(char* dest, const char* src)  //const用于保护源字符串
//{
//	assert(dest && src);  //保证传递过来的不是空串
//	char* ret = dest;  //记录目标空间的起始地址
//	while (*dest != '\0')  //找到目标空间的末尾
//	{
//		dest++;
//	}
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;  //将末尾的'\0'赋给dest
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "world!";
//	char arr2[20] = "hello ";
//	my_strcat(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//
////字符串追加可以分为两部分：1、找到目标字符串的末尾 2、字符串拷贝
//char* my_strcat(char* dest, const char* src)  //const用于保护源字符串
//{
//	assert(dest && src);  //保证传递过来的不是空串
//	char* ret = dest;  //记录目标空间的起始地址
//
//	while (*dest++ != '\0');   //找到目标空间的末尾
//	dest--;  //抵消最后一次自增的副作用
//	while (*dest++ = *src++);  //字符串拷贝
//
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "world!";
//	char arr2[20] = "hello ";
//	my_strcat(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

#include <stdio.h>
#include <assert.h>  //assert对应头文件

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')  //找到字符串中不相等字符的位置
	{
		str1++;
		str2++;
	}
	if (*str1 != '\0' && *str2 != '\0')   //如果此位置不是字符串末尾，则不相等，返回差值
		return *str1 - *str2;
	return 0;  //若前面没返回，说明相等，返回0
}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcdef";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;
}