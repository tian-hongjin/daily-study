#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>

//struct S
//{
//	int n;
//	int arr[];  //柔性数组成员
//};
//
//int main()
//{
//	//开辟
//	//malloc 中加号前面的部分为结构体普通成员开辟空间，加号后面部分为柔性数组成员开辟空间
//	struct S* s = (struct S*)malloc(sizeof(struct S) + 40);
//	if (s == NULL)
//	{
//		perror("malloc");  //perror函数，找到错误信息并打印
//		return 1;
//	}
//
//	//扩容
//	struct S* ptr = (struct S*)realloc(s, sizeof(struct S) + 80);
//	if (ptr == NULL)
//	{
//		perror("malloc");  //perror函数，找到错误信息并打印
//		return 1;
//	}
//
//	//使用
//	s = ptr;
//	s->n = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		s->arr[i] = i;
//		printf("%d ", s->arr[i]);
//	}
//
//	//销毁
//	free(s);
//	s = NULL;
//	return 0;
//}
//
//struct S
//{
//	int n;
//	int* arr;  //指针变量
//};
//
//int main()
//{
//	//开辟:由于含柔性数组的结构体的空间完全是在堆区上开辟的，所以为了最大程度上模拟其效果，这里我们也在堆区上开辟空间
//	//为结构体开辟空间
//	struct S* s = (struct S*)malloc(sizeof(struct S));
//	if (s == NULL)
//	{
//		perror("malloc");  //perror函数，找到错误信息并打印
//		return 1;
//	}
//
//	//让结构体中的int*变量指向另一块开辟的空间
//	s->arr = (int*)malloc(20);
//	if (s->arr == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	//扩容为int*指向的空间
//	int* ptr = (int*)realloc(s->arr, 40);
//	if (ptr == NULL)
//	{
//		perror("realloc");
//		return 1;
//	}
//	s->arr = ptr;
//
//	//使用
//	s->n = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		s->arr[i] = i;
//		printf("%d ", s->arr[i]);
//	}
//
//	//销毁：这里注意要开辟的两块空间全部销毁掉
//	free(s->arr);
//	free(s);
//	s = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//#include <math.h>
//
//int my_atoi(const char* str)
//{
//	assert(str);
//	int count = 0;
//	const char* p = str;  //把str赋给指针变量p，保证str的起始位置不会丢失
//	while (*p >= '0' && *p <= '9' && *p != '\0')  //找到str中从起始位置开始连续的数字字符的个数
//	{
//		p++;
//		count++;
//	}
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	p = str;  //将p重新置会str开始位置
//	for (i = count - 1, j = 0; i >= 0; i--, j++)
//	{
//		sum += (p[j] - 48) * (int)pow(10, i);
//	}
//	return sum;
//}
//
//int main()
//{
//	char str[] = "12345abcdef";
//	int ret = my_atoi(str);
//	printf("%d\n", ret);
//	return 0;
//}

#include <stdio.h>
//int main()
//{
//	//以只读形式打开文件
//	FILE* pf = fopen("test.txt", "w");
//	//打开失败，打印错误信息并返回
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//打开成功，使用
//	fputs("file open example", pf);
//	//使用完毕，关闭
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//从文件中读取字符
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//向文件中写入一行字符
//	fputs("abcdef", pf);
//	fputs("12345", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//从文件中读取字符
//	char arr[20];
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//};
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//向文件中格式化写入数据
//	fprintf(pf, "%s %d %s", stu.name, stu.age, stu.sex);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//};
//
//int main()
//{
//	struct Stu stu = { 0 };
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//从文件中格式化读取数据
//	fscanf(pf, "%s %d %s", stu.name, &(stu.age), stu.sex);
//	printf("%s %d %s\n", stu.name, stu.age, stu.sex);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[10];
//};
//
//int main()
//{
//	struct Stu stu = { "zhangsan", 20, "nan" };
//	//打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//以二进制的形式向文件中格式化写入数据
//	fwrite(&stu, sizeof(struct Stu), 1, pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

struct Stu
{
	char name[20];
	int age;
	char sex[10];
};

int main()
{
	struct Stu stu = { 0 };
	//打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//以二进制的形式从文件中格式化读取数据
	fread(&stu, sizeof(struct Stu), 1, pf);
	printf("%s %d %s\n", stu.name, stu.age, stu.sex);

	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}