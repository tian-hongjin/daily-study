#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>

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
//	char str[50];  //����һ���ַ����飬�����洢�ӽṹ���ж�ȡ������
//	//��һ���ʽ��������ת��Ϊ�ַ���
//	sprintf(str, "%s %d %s", stu.name, stu.age, stu.sex);
//	printf("%s\n", str);
//	//��һ���ַ����е����ݸ�ʽ��
//	struct Stu stu1 = { 0 };
//	sscanf(str, "%s %d %s", stu1.name, &(stu1.age), stu1.sex);
//	printf("%s %d %s\n", stu1.name, stu1.age, stu1.sex);
//	return 0;
//}

//int main()
//{
//	//��д����ʽ���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//���ַ� 'a' - 'z' д���ļ���ȥ
//	int i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	//�Զ�����ʽ���ļ�
//	FILE* pf1 = fopen("test.txt", "r");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�����ļ�ָ��ָ�����һ���ַ�
//	fseek(pf1, -1, SEEK_END);
//	//�������ַ�
//	char ch = fgetc(pf1);
//	printf("%c\n", ch);
//	//�ر��ļ�
//	fclose(pf1);
//	pf1 = NULL;
//	return 0;
//}

//int main()
//{
//	int n;
//	FILE* pFile;
//	char buffer[27];
//	//�Զ�д�ķ�ʽ���ļ�
//	pFile = fopen("myfile.txt", "w+");
//	//���ַ� 'A' - 'Z' д�뵽�ļ���
//	for (n = 'A'; n <= 'Z'; n++)
//		fputc(n, pFile);
//	//ʹ�ļ�ָ��ص��ļ���ʼλ��
//	rewind(pFile);
//	//������
//	fread(buffer, 1, 26, pFile);
//	buffer[26] = '\0';
//	puts(buffer);
//	//�ر��ļ�
//	fclose(pFile);
//	pFile = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//	int c; //��c����Ϊint��ʹ������������EOF(-1)
//	FILE* fp = fopen("test.txt", "r");
//	if (!fp)
//	{
//		perror("File opening failed");
//		return EXIT_FAILURE;
//	}
//	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//	while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//	{
//		putchar(c);
//	}
//	//ѭ��������˵���ļ���ȡʧ�ܣ��ж���ʲôԭ�������
//	if (ferror(fp))  //ferror(fp)Ϊ�棬˵���ɶ�ȡʧ������
//		puts("I/O error when reading");
//	else if (feof(fp))  //feof(fp)Ϊ�棬˵���������ļ�β����
//		puts("End of file reached successfully");
//	fclose(fp);
//	fp = NULL;
//}

//enum  //����������
//{
//	SIZE = 5
//};
//
//int main(void)
//{
//	double a[SIZE] = { 1.,2.,3.,4.,5. };
//	FILE* fp = fopen("test.bin", "wb");
//	fwrite(a, sizeof * a, SIZE, fp); // ���ļ����Զ����Ƶ���ʽд��һ�����������
//	fclose(fp);
//	fp = NULL;
//
//	double b[SIZE];
//	fp = fopen("test.bin", "rb");
//	size_t ret_code = fread(b, sizeof * b, SIZE, fp); // ���ļ��ж�ȡ�����Ƶ�����
//	if (ret_code == SIZE) {  //���fread�����ķ���ֵ���ڲ���SIZE��˵��������ȡ
//		puts("Array read successfully, contents: ");
//		for (int n = 0; n < SIZE; ++n)
//			printf("%f ", b[n]);
//		putchar('\n');
//	}
//	else   //����������������ļ�β
//	{
//		if (feof(fp))  //��ʾ�����ļ�β
//			printf("Error reading test.bin: unexpected end of file\n");
//		else if (ferror(fp))  //��ʾ��������
//			perror("Error reading test.bin");
//	}
//	fclose(fp);
//	fp = NULL;
//}

#include <stdio.h>
#include <windows.h>
//VS2019 WIN11��������
int main()
{
	FILE* pf = fopen("test.txt", "w");
	fputs("abcdef", pf);//�Ƚ�����������������
	printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
	Sleep(10000);
	printf("ˢ�»�����\n");
	fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
	//ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
	printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
	Sleep(10000);
	fclose(pf);
	//ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
	pf = NULL;
	return 0;
}