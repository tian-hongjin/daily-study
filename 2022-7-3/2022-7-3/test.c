#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdio.h>
#include <string.h>

////ģ��ʵ��strcpy
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(src);
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

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a + 0));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(a[1]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(*&a));
//	printf("%d\n", sizeof(&a + 1));
//	printf("%d\n", sizeof(&a[0]));
//	printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));	//6
//	//arr��������sizeof�ڲ��������������飬��СΪ6���ֽ�
//	printf("%d\n", sizeof(arr + 0));	//4/8
//	//arr������Ԫ�صĵ�ַ��4/8���ֽ�
//	printf("%d\n", sizeof(*arr));		//1
//	//arr������Ԫ�ص�ַ����������ô����һ��Ԫ�أ���СΪ1���ֽ�
//	printf("%d\n", sizeof(arr[1]));    //1
//	//arr[1]��������ڶ���Ԫ�أ�1���ֽ�
//	printf("%d\n", sizeof(&arr));	//4/8
//	//&arrȡ�����������ַ��4/8���ֽ�
//	printf("%d\n", sizeof(&arr + 1));	//4/8
//	//&arrȡ����������ĵ�ַ��&arr+1����һ�����飬ָ�������������Ŀռ䣬4/8���ֽ�
//	printf("%d\n", sizeof(&arr[0] + 1));	///4/8
//	//&arr[0]������Ԫ�ص�ַ��+1����ڶ���Ԫ�ص�ַ��4/8���ֽ�
//	printf("%d\n", strlen(arr));	//���ֵ
//	//arr������Ԫ�ص�ַ������ӵ�һ��Ԫ�ؿ�ʼ���ַ�������
//	//strlen�����\0��ǰ�ַ��ĸ�������Ϊ�ַ������в�������\0������strlen��һֱ����Ѱ�ң�ֱ������\0�������ǲ�֪���������ռ�����ݣ�����Ϊ���ֵ��
//	printf("%d\n", strlen(arr + 0));	//���ֵ
//	//arr+0������Ԫ�ص�ַ������ӵ�һ��Ԫ�ؿ�ʼ���ַ�������
//	//���ֵԭ��ͬ��
//	printf("%d\n", strlen(*arr));	//error
//	//strlen�����Ĳ�����һ����ַ���������ǰѵ�һ��Ԫ�ؼ�'a'����strlen��������ôstrlen�ͻ��'a'��ASCII��ֵ(97)���ɵ�ַ���ã�����97���ĵ�ַ�����������ǣ��Ӷ����Ұָ�����⣬����
//	printf("%d\n", strlen(arr[1]));	//error
//	//ԭ�����������
//	printf("%d\n", strlen(&arr));	//���ֵ
//	//&arr��Ȼȡ����������ĵ�ַ������Ȼ��ָ����Ԫ�أ����Ժ������strlen(arr)һ��
//	printf("%d\n", strlen(&arr + 1));	//���ֵ
//	//&arrȡ����������ĵ�ַ��+1�����������飬ָ�������������Ŀռ䣬�����ǲ�֪������ռ��ʱ����\0��������Ȼ�����ֵ
//	printf("%d\n", strlen(&arr[0] + 1));	//���ֵ
//	//&arr[0]+1����ڶ���Ԫ�ص�ַ����Ȼ�����ֵ
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));	//7
//	//arr�����������飬��Ϊ�ַ���ĩβ���Զ���һ��\0������arr�������߸�Ԫ��
//	printf("%d\n", sizeof(arr + 0));	//4/8
//	printf("%d\n", sizeof(*arr));	//1
//	printf("%d\n", sizeof(arr[1]));	//1
//	printf("%d\n", sizeof(&arr));	//4/8
//	printf("%d\n", sizeof(&arr + 1));	//4/8
//	printf("%d\n", sizeof(&arr[0] + 1));	//4/8
//
//	printf("%d\n", strlen(arr));	//6
//	//strlen�����ַ���ĩβ��\0ֹͣ��ǰ��һ��6��Ԫ��
//	printf("%d\n", strlen(arr + 0));	//6
//	printf("%d\n", strlen(*arr));	//error
//	printf("%d\n", strlen(arr[1]));    //error
//	printf("%d\n", strlen(&arr));	//6
//	printf("%d\n", strlen(&arr + 1));	//���ֵ
//	//&arrȡ����������ĵ�ַ��+1�����������飬����ռ������δ֪���������
//	printf("%d\n", strlen(&arr[0] + 1));	//5
//	//&arr[0]+1�ǵڶ���Ԫ�صĵ�ַ����������strlen������Ϊ5
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));	//4/8
//	//"abcdef"�ǳ����ַ�����char* p = "abcdef" �������ǰ��ַ�����'a'�ĵ�ַ����P������4/8
//	printf("%d\n", sizeof(p + 1));	//4/8
//	//p+1�����ַ�'b'�ĵ�ַ��4/8
//	printf("%d\n", sizeof(*p));    //1
//	printf("%d\n", sizeof(p[0]));	//1
//	printf("%d\n", sizeof(&p));    //4/8
//	//&pȡ������p�ĵ�ַ����һ������ָ�룬����ַ��С��Ȼ��4/8
//	printf("%d\n", sizeof(&p + 1));    //4/8
//	//&p+1����p���ڿռ��������Ŀռ�
//	printf("%d\n", sizeof(&p[0] + 1));    //4/8
//	//&p[0] <==> &(*(p+0)) <==> p������'a'�ĵ�ַ
//
//	printf("%d\n", strlen(p));    //6
//	printf("%d\n", strlen(p + 1));    //5
//	printf("%d\n", strlen(*p));    //error
//	printf("%d\n", strlen(p[0]));    //error
//	printf("%d\n", strlen(&p));    //���ֵ
//	//&pȡ������p�ĵ�ַ�����������������ǲ�ȷ���ģ�
//	//1����֪��p�ĵ�ַ���Ƿ����ĸ��ֽڴ�С������0��p�ĵ�ַ����0x14ffff44��Ҳ������0x1400ff00
//	//2����֪��p�ĺ���ռ������
//	//����strlen�������ֵ�������
//	printf("%d\n", strlen(&p + 1));    //���ֵ
//	//&p+1������p�ĵ�ַ��ֱ��������p���Ŀռ䣬����������ĵ�һ�㲻ȷ�������ڶ�����Ȼ����
//	printf("%d\n", strlen(&p[0] + 1));    //5
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//	//printf("%d\n", sizeof(p));
//	//printf("%d\n", sizeof(p + 1));
//	//printf("%d\n", sizeof(*p));
//	//printf("%d\n", sizeof(p[0]));
//	//printf("%d\n", sizeof(&p));
//	//printf("%d\n", sizeof(&p + 1));
//	//printf("%d\n", sizeof(&p[0] + 1));
//
//	//printf("%d\n", strlen(p));
//	//printf("%d\n", strlen(p + 1));
//	//printf("%d\n", strlen(*p));
//	//printf("%d\n", strlen(p[0]));
//	printf("%d\n", strlen(&p));
//	printf("%d\n", strlen(&p + 1));
//	printf("%d\n", strlen(&p[0] + 1));
//	return 0;
//}

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));	//48
	//a��������sizeof�ڲ�����ʾ������ά����Ĵ�С��3*4*4=48
	printf("%d\n", sizeof(a[0][0]));	//4
	//a[0][0]�����һ��Ԫ�أ�����ռ4���ֽ�
	printf("%d\n", sizeof(a[0]));	//16
	//��ά����������������Ӧһά�����������
	//�����a[0]�����ά�����һ�е�������
	//һά�������������������sizeof�ڲ�����������һά���飬4*4=16
	printf("%d\n", sizeof(a[0] + 1));	//4/8
	//a[0]�����һ�е�������
	//a[0]���ǵ�������sizeof�ڲ�������������������Ԫ�ص�ַ����a[0][0]�ĵ�ַ
	//����a[0]+1��������ڶ���Ԫ��a[0][1]�ĵ�ַ��4/8
	printf("%d\n", sizeof(*(a[0] + 1)));	//4
	//������ڶ���Ԫ�ؽ�ĵ�ַ���õõ��ڶ���Ԫ�أ����δ�С4���ֽ�
	printf("%d\n", sizeof(a + 1));    //4/8
	//a������Ԫ�ؼ���һ�еĵ�ַ��a+1����һ�У�ָ��ڶ��У��ڶ��еĵ�ַ4/8
	printf("%d\n", sizeof(*(a + 1)));	//16
	//��һ�еĵ�ַ+1ָ��ڶ��еĵ�ַ�������õõ��ڶ���
	printf("%d\n", sizeof(&a[0] + 1));	//4/8
	//&a[0]ȡ����һ�еĵ�ַ��+1ָ��ڶ��еĵ�ַ
	printf("%d\n", sizeof(*(&a[0] + 1)));	//16
	//�Եڶ��еĵ�ַ�����õõ������ڶ���
	printf("%d\n", sizeof(*a));	//16
	//a������Ԫ�ؼ���һ�еĵ�ַ�������õõ���һ��
	printf("%d\n", sizeof(a[3]));	//16
	//sizeof�����ݴ�Сʱֻ��ע���ݵ����ͣ�����ע���ݵ�����
	//������Ȼ����a[3]Խ���ˣ����Ǹ���a[3]���������ͣ�int (*)[4] -- ����ָ�룬�������a[3]�Ĵ�С
	//a[3]����һά�������������������sizeof�ڲ�������������Ĵ�С
	return 0;
}