#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>

//struct S
//{
//	int n;
//	int arr[];  //���������Ա
//};
//
//int main()
//{
//	//����
//	//malloc �мӺ�ǰ��Ĳ���Ϊ�ṹ����ͨ��Ա���ٿռ䣬�Ӻź��沿��Ϊ���������Ա���ٿռ�
//	struct S* s = (struct S*)malloc(sizeof(struct S) + 40);
//	if (s == NULL)
//	{
//		perror("malloc");  //perror�������ҵ�������Ϣ����ӡ
//		return 1;
//	}
//
//	//����
//	struct S* ptr = (struct S*)realloc(s, sizeof(struct S) + 80);
//	if (ptr == NULL)
//	{
//		perror("malloc");  //perror�������ҵ�������Ϣ����ӡ
//		return 1;
//	}
//
//	//ʹ��
//	s = ptr;
//	s->n = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		s->arr[i] = i;
//		printf("%d ", s->arr[i]);
//	}
//
//	//����
//	free(s);
//	s = NULL;
//	return 0;
//}
//
//struct S
//{
//	int n;
//	int* arr;  //ָ�����
//};
//
//int main()
//{
//	//����:���ں���������Ľṹ��Ŀռ���ȫ���ڶ����Ͽ��ٵģ�����Ϊ�����̶���ģ����Ч������������Ҳ�ڶ����Ͽ��ٿռ�
//	//Ϊ�ṹ�忪�ٿռ�
//	struct S* s = (struct S*)malloc(sizeof(struct S));
//	if (s == NULL)
//	{
//		perror("malloc");  //perror�������ҵ�������Ϣ����ӡ
//		return 1;
//	}
//
//	//�ýṹ���е�int*����ָ����һ�鿪�ٵĿռ�
//	s->arr = (int*)malloc(20);
//	if (s->arr == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	//����Ϊint*ָ��Ŀռ�
//	int* ptr = (int*)realloc(s->arr, 40);
//	if (ptr == NULL)
//	{
//		perror("realloc");
//		return 1;
//	}
//	s->arr = ptr;
//
//	//ʹ��
//	s->n = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		s->arr[i] = i;
//		printf("%d ", s->arr[i]);
//	}
//
//	//���٣�����ע��Ҫ���ٵ�����ռ�ȫ�����ٵ�
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
//	const char* p = str;  //��str����ָ�����p����֤str����ʼλ�ò��ᶪʧ
//	while (*p >= '0' && *p <= '9' && *p != '\0')  //�ҵ�str�д���ʼλ�ÿ�ʼ�����������ַ��ĸ���
//	{
//		p++;
//		count++;
//	}
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	p = str;  //��p�����û�str��ʼλ��
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
//	//��ֻ����ʽ���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	//��ʧ�ܣ���ӡ������Ϣ������
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�򿪳ɹ���ʹ��
//	fputs("file open example", pf);
//	//ʹ����ϣ��ر�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ��ж�ȡ�ַ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ���д��һ���ַ�
//	fputs("abcdef", pf);
//	fputs("12345", pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ��ж�ȡ�ַ�
//	char arr[20];
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//	fgets(arr, 5, pf);
//	printf("%s\n", arr);
//
//	//�ر��ļ�
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
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ��и�ʽ��д������
//	fprintf(pf, "%s %d %s", stu.name, stu.age, stu.sex);
//
//	//�ر��ļ�
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
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ļ��и�ʽ����ȡ����
//	fscanf(pf, "%s %d %s", stu.name, &(stu.age), stu.sex);
//	printf("%s %d %s\n", stu.name, stu.age, stu.sex);
//
//	//�ر��ļ�
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
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�Զ����Ƶ���ʽ���ļ��и�ʽ��д������
//	fwrite(&stu, sizeof(struct Stu), 1, pf);
//
//	//�ر��ļ�
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
	//���ļ�
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	//�Զ����Ƶ���ʽ���ļ��и�ʽ����ȡ����
	fread(&stu, sizeof(struct Stu), 1, pf);
	printf("%s %d %s\n", stu.name, stu.age, stu.sex);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}