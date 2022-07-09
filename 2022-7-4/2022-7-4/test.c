#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//模拟实现strlen
//size_t my_strlen(const char* ptr)
//{
//	assert(ptr != NULL);
//	char* head = ptr;
//	while (*ptr++);
//	return ptr - head - 1;
//}
//
//int main()
//{
//	char arr[] = "hello bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//模拟实现strcpy

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++);
//	return ret;
//}
//
//int main()
//{
//	char arr1[] = "hello bit";
//	char arr2[20] = "";
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//模拟实现strcat

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++);
	dest--;
	while (*dest++ = *src++);
	return ret;
}

int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "bit";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}