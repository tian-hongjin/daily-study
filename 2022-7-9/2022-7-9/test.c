#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  //memcmp��Ӧͷ�ļ�
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
//	size_t count = 0;  //���������ȵ��ֽ���
//	while (*(char*)ptr1 == *(char*)ptr2 && count < num)  //һֱѭ����ֱ���ҵ�����ȵ��ֽ�����
//	{
//		count++;  //����һ��ѭ����ʾ��һ���ֽ���ȣ�count++
//		ptr1 = (char*)ptr1 + 1;
//		ptr2 = (char*)ptr2 + 1;
//	}
//	if (count < num)  //���countС��num��˵�������ڴ��ǰnum���ֽ����в���ȵ�����
//		return *(char*)ptr1 - *(char*)ptr2;  //ֱ�ӷ������ݵĲ�ֵ
//	else
//		return 0;  //count����num��˵�����
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
//	void* ret = dest;  //��¼Ŀ��ռ�ĵ�ַ
//	while (num--)  //ѭ����num���ֽڵ����ݳ�ʼ��Ϊָ��ֵ
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
//	void* ret = dest;  //����Ŀ��ռ�ĵ�ַ
//	if (dest < src)
//	{
//		//ǰ -> �� �ȼ���memcpy
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//�� -> ǰ
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