#define _CRT_SECURE_NO_WARNINGS 1
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
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
//		tmp ^= arr[i];  //�ҳ���������������ͬ����������ֵ
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

//ģ��ʵ��strncpy
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* dest, const char* src, size_t num)
//{
//	assert(dest && src);
//	char* ret = dest;  //��¼Ŀ��ռ����ʼ��ַ
//	while (num--)
//	{
//		*dest++ = *src++;
//		if (*dest == '\0')  //���*destΪ0��˵����src�Ľ����ַ�������dest�����������Դ�ַ����ĳ���С��num
//		{
//			while (num--)
//			{
//				////���Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ��׷��0��ֱ��num����(��⺯����ʵ�ַ�ʽ����һ�£�
//				*dest++ = 0;
//			}
//			break;
//		}
//	}
//	*dest = '\0';  //��dest��ĩβ���Ͻ����ַ�
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
//	char* ret = dest;  //��¼Ŀ��ռ����ʼ��ַ
//
//	//�ҵ�destĩβ
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//
//	//strncpy
//	while (num--)
//	{
//		*dest = *src;
//		if (*dest == '\0')  //���*destΪ0��˵����src�Ľ����ַ�������dest�����������Դ�ַ����ĳ���С��num
//		{
//			//���Դ���ַ����ĳ���С��num����ֻ���Ƶ���ֹ���ַ������ݡ�(��⺯����ʵ�ַ�ʽ����һ�£�
//			return ret; //ֱ�ӷ���
//		}
//		dest++;
//		src++;
//	}
//	*dest = '\0';  //���ѭ����������������dest��ĩβ���Ͻ����ַ�
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

//��̬�ڴ����
//
//malloc
//#include <stdio.h>
//#include <stdlib.h>  //��̬�ڴ�����Ӧͷ�ļ�
//#include <string.h>  //strerror��Ӧͷ�ļ�
//#include <errno.h>   //errno��Ӧͷ�ļ�
//
//int main()
//{
//	//����40���ֽڵĿռ䣬����ָ�����p������
//	int* p = (int*)malloc(10 * sizeof(int));
//	//malloc����ռ���ܻ�ʧ�ܣ�����Ҫ�����ж�
//	//����ʧ�ܣ���ӡ������Ϣ���˳�
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//����ɹ���ʹ��
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//ʹ���꣺�ͷ�
//	free(p);   //�ͷŶ�̬�ڴ濪�ٵĿռ�
//	p = NULL;  //��p�ÿգ���ֹҰָ��
//}

//calloc
//#include <stdio.h>
//#include <stdlib.h>  //��̬�ڴ�����Ӧͷ�ļ�
//#include <string.h>  //strerror��Ӧͷ�ļ�
//#include <errno.h>   //errno��Ӧͷ�ļ�
//
//int main()
//{
//	//����40���ֽڵĿռ䣬����ָ�����p������
//	int* p = (int*)calloc(10, sizeof(int));
//	//calloc����ռ���ܻ�ʧ�ܣ�����Ҫ�����ж�
//	//����ʧ�ܣ���ӡ������Ϣ���˳�
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//����ɹ���ʹ��
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//ʹ���꣺�ͷ�
//	free(p);   //�ͷŶ�̬�ڴ濪�ٵĿռ�
//	p = NULL;  //��p�ÿգ���ֹҰָ��
//}

//realloc
#include <stdio.h>
#include <stdlib.h>  //��̬�ڴ�����Ӧͷ�ļ�
#include <string.h>  //strerror��Ӧͷ�ļ�
#include <errno.h>   //errno��Ӧͷ�ļ�
//
//int main()
//{
//	//�ȿ���һ��ռ�
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//����
//	//����realloc���ܻῪ��ʧ�ܣ�Ϊ�˷�ֹpָ��realloc����ʧ�ܵĿռ䣬�Ӷ���ʧԭ���ռ���������������ʹ����ʱ�������ж�realloc�Ƿ񿪱ٳɹ�
//	int* ptr = (int*)realloc(p, 20 * sizeof(int));
//	//����ʧ�ܣ���ӡ������Ϣ���˳�
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//����ɹ�����pָ��ÿռ䲢ʹ��
//	p = ptr;
//	for (int i = 0; i < 20; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	//ʹ���꣺�ͷ�
//	free(p);   //�ͷŶ�̬�ڴ濪�ٵĿռ�
//	p = NULL;  //��p�ÿգ���ֹҰָ��
//}
//
//void test()
//{
//	int* p = (int*)malloc(INT_MAX);
//	*p = 20;//���p��ֵ��NULL���ͻ�������
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
//		*(p + i) = i;//��i��10��ʱ��Խ�����
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
//		p++;  //ָ�����p���������䶪ʧ��̬�ڴ����ʼ��ַ
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
//	free(p);//�ظ��ͷ�
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
		//...... --�����߼�
		return;
	}
	else
	{
		//...... --�����߼�
	}
	free(p);
	p = NULL;
}

int main()
{
	test();
	return 0;
}