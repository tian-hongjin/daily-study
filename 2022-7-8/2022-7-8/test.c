#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  //strncpy��Ӧ��ͷ�ļ�
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[10] = "";
//	strncpy(arr2, arr1, sizeof(arr1) / sizeof(arr1[0]) * 1);
//	//sizeof(arr)/sizeof(arr[0]) �������Ԫ�ظ�����*1 ����ÿ��Ԫ�صĴ�С���õ�����������ֽ���
//	printf("%s\n", arr2);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>  //strncat��Ӧ��ͷ�ļ�
//int main()
//{
//	char arr1[] = "world!";
//	char arr2[20] = "hello ";
//	strncat(arr2, arr1, 8 * 1);
//	//sizeof(arr)/sizeof(arr[0]) �������Ԫ�ظ�����*1 ����ÿ��Ԫ�صĴ�С���õ�����������ֽ���
//	printf("%s\n", arr2);
//	return 0;
//}
//
//#include <stdio.h>
//#include <string.h>  //strncmp��Ӧ��ͷ�ļ�
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
//	//��;ƥ��ʧ����Ҫ�ص�str2��ͷ������������������ʶstr2����֤str2���׵�ַ���ᶪʧ
//	const char* p1 = str1;
//	const char* p2 = str2;
//	const char* mark = str1;  //�������ÿ�ε�һ���ַ��ɹ�ƥ���λ��
//	while (*mark != '\0')
//	{
//		p1 = mark;  //��mark����ʼ����ƥ��
//		p2 = str2;  //ÿ��ƥ���p2�ص�str2��ͷ
//		while (*p1 == *p2 && *p2 != '\0')  //һֱ����ƥ�䣬ֱ����������ȵ��ַ�
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0')  //�������ȴ�p2Ϊ'\0'(�Ӵ�ȫ��ƥ��ɹ�)���򷵻�Mark����ַ
//			return (char*)mark;
//		mark++;  //����˵����һ��ƥ��ʧ�ܣ���mark����һ���ֽڴ���ʼ����ƥ��
//	}
//	return NULL;  //�ַ������궼û���Ӵ��ͷ��ؿ�ָ��
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
//	//����strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ����һ�ݣ���������������
//	strcpy(tmp, email);
//	printf("%s\n", strtok(tmp, sep));  //��һ�ε�һ���������ݱ��и��ַ������׵�ַ
//	printf("%s\n", strtok(NULL, sep));   //�ڶ��μ��Ժ��һ���������ݿ�ָ�루strtok���ס��һ���и��λ�ã�
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
//	//����strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ����һ�ݣ���������������
//	strcpy(tmp, email);
//	char* ret = NULL;  //��������strtok�����ķ���ֵ
//	for (ret = strtok(tmp, sep);   //��ʼ�����֣���һ�δ���tmp�ĵ�ַ
//		ret != NULL;               //�жϲ��֣�ֻҪstrtok�ķ���ֵret��Ϊ�գ�˵�������ָ�
//		ret = strtok(NULL, sep))   //�������֣��ڶ��μ����ϴ���NULL
//	{
//		printf("%s\n", ret);  //ret��Ϊ�գ�˵���ַ���û���ָ��꣬���ӡ
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>  //strerror��ͷ�ļ�
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
//#include <string.h>  //strerror��Ӧͷ�ļ�
//#include <errno.h>   //errno��Ӧͷ�ļ�
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
//		printf("�ļ��򿪳ɹ���\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>   //memcpy��Ӧͷ�ļ�
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
//	void* ret = dest;  //����Ŀ��ռ�ĵ�ַ
//	while (num--)   //���ֽ�Ϊ��λ���п���
//	{
//		*(char*)dest = *(char*)src;  //ǿתΪchar*���ͺ�ֵ
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
#include <string.h>  //memmove��Ӧͷ�ļ�
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