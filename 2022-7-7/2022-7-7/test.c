#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  //strlen��Ӧͷ�ļ�
//int main()
//{
//	char arr[] = "abcdef";
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>  //assert��Ӧͷ�ļ�
//
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);   //���str�Ƿ�Ϊ��ָ��
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
//#include <assert.h>  //assert��Ӧͷ�ļ�
//
//size_t my_strlen(const char* str)   //const���ڱ���Դ�ַ��������޸�
//{
//	assert(str != NULL);
//	char* head = str;      //��¼�ַ�����ͷ�ĵ�ַ
//	while (*str++);        //�ҵ��ַ��������ĵ�ַ
//	return str - head - 1; //ָ��-ָ��õ�Ԫ�ظ�����-1��ȥ\0
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
//#include <string.h>  //strcpy��Ӧͷ�ļ�
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = "";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>  //assert��Ӧͷ�ļ�
//
//char* my_strcpy(char* dest, const char* src)  //const���ڱ���Դ�ַ���
//{
//	assert(dest && src);  //��֤���ݹ����Ĳ��ǿմ�
//	char* ret = dest;  //��¼Ŀ��ռ����ʼ��ַ
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;  //��ĩβ��'\0'����dest
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
//#include <assert.h>  //assert��Ӧͷ�ļ�
//
//char* my_strcpy(char* dest, const char* src)  //const���ڱ���Դ�ַ���
//{
//	assert(dest && src);  //��֤���ݹ����Ĳ��ǿմ�
//	char* ret = dest;  //��¼Ŀ��ռ����ʼ��ַ
//	while (*dest++ = *src++);  //��ͬĩβ��'\0'һ�𸳸���dest
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
//#include <string.h>  //strcat��Ӧͷ�ļ�
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
//char* my_strcat(char* dest, const char* src)  //const���ڱ���Դ�ַ���
//{
//	assert(dest && src);  //��֤���ݹ����Ĳ��ǿմ�
//	char* ret = dest;  //��¼Ŀ��ռ����ʼ��ַ
//	while (*dest != '\0')  //�ҵ�Ŀ��ռ��ĩβ
//	{
//		dest++;
//	}
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;  //��ĩβ��'\0'����dest
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
////�ַ���׷�ӿ��Է�Ϊ�����֣�1���ҵ�Ŀ���ַ�����ĩβ 2���ַ�������
//char* my_strcat(char* dest, const char* src)  //const���ڱ���Դ�ַ���
//{
//	assert(dest && src);  //��֤���ݹ����Ĳ��ǿմ�
//	char* ret = dest;  //��¼Ŀ��ռ����ʼ��ַ
//
//	while (*dest++ != '\0');   //�ҵ�Ŀ��ռ��ĩβ
//	dest--;  //�������һ�������ĸ�����
//	while (*dest++ = *src++);  //�ַ�������
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
#include <assert.h>  //assert��Ӧͷ�ļ�

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')  //�ҵ��ַ����в�����ַ���λ��
	{
		str1++;
		str2++;
	}
	if (*str1 != '\0' && *str2 != '\0')   //�����λ�ò����ַ���ĩβ������ȣ����ز�ֵ
		return *str1 - *str2;
	return 0;  //��ǰ��û���أ�˵����ȣ�����0
}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcdef";
	int ret = my_strcmp(str1, str2);
	printf("%d\n", ret);
	return 0;
}