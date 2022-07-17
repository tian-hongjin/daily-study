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
//	char str[50];  //定义一个字符数组，用来存储从结构体中读取的数据
//	//将一组格式化的数据转换为字符串
//	sprintf(str, "%s %d %s", stu.name, stu.age, stu.sex);
//	printf("%s\n", str);
//	//将一个字符串中的数据格式化
//	struct Stu stu1 = { 0 };
//	sscanf(str, "%s %d %s", stu1.name, &(stu1.age), stu1.sex);
//	printf("%s %d %s\n", stu1.name, stu1.age, stu1.sex);
//	return 0;
//}

//int main()
//{
//	//以写的形式打开文件
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//将字符 'a' - 'z' 写到文件中去
//	int i = 0;
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	//以读的形式打开文件
//	FILE* pf1 = fopen("test.txt", "r");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//设置文件指针指向最后一个字符
//	fseek(pf1, -1, SEEK_END);
//	//读出该字符
//	char ch = fgetc(pf1);
//	printf("%c\n", ch);
//	//关闭文件
//	fclose(pf1);
//	pf1 = NULL;
//	return 0;
//}

//int main()
//{
//	int n;
//	FILE* pFile;
//	char buffer[27];
//	//以读写的方式打开文件
//	pFile = fopen("myfile.txt", "w+");
//	//将字符 'A' - 'Z' 写入到文件中
//	for (n = 'A'; n <= 'Z'; n++)
//		fputc(n, pFile);
//	//使文件指针回到文件起始位置
//	rewind(pFile);
//	//读数据
//	fread(buffer, 1, 26, pFile);
//	buffer[26] = '\0';
//	puts(buffer);
//	//关闭文件
//	fclose(pFile);
//	pFile = NULL;
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//	int c; //把c定义为int，使其有能力接受EOF(-1)
//	FILE* fp = fopen("test.txt", "r");
//	if (!fp)
//	{
//		perror("File opening failed");
//		return EXIT_FAILURE;
//	}
//	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
//	{
//		putchar(c);
//	}
//	//循环结束，说明文件读取失败，判断是什么原因结束的
//	if (ferror(fp))  //ferror(fp)为真，说明由读取失败引起
//		puts("I/O error when reading");
//	else if (feof(fp))  //feof(fp)为真，说明由遇到文件尾引起
//		puts("End of file reached successfully");
//	fclose(fp);
//	fp = NULL;
//}

//enum  //匿名联合体
//{
//	SIZE = 5
//};
//
//int main(void)
//{
//	double a[SIZE] = { 1.,2.,3.,4.,5. };
//	FILE* fp = fopen("test.bin", "wb");
//	fwrite(a, sizeof * a, SIZE, fp); // 向文件中以二进制的形式写入一个数组的数据
//	fclose(fp);
//	fp = NULL;
//
//	double b[SIZE];
//	fp = fopen("test.bin", "rb");
//	size_t ret_code = fread(b, sizeof * b, SIZE, fp); // 从文件中读取二进制的数据
//	if (ret_code == SIZE) {  //如果fread函数的返回值等于参数SIZE，说明正常读取
//		puts("Array read successfully, contents: ");
//		for (int n = 0; n < SIZE; ++n)
//			printf("%f ", b[n]);
//		putchar('\n');
//	}
//	else   //否则，遇到错误或者文件尾
//	{
//		if (feof(fp))  //表示遇到文件尾
//			printf("Error reading test.bin: unexpected end of file\n");
//		else if (ferror(fp))  //表示遇到错误
//			perror("Error reading test.bin");
//	}
//	fclose(fp);
//	fp = NULL;
//}

#include <stdio.h>
#include <windows.h>
//VS2019 WIN11环境测试
int main()
{
	FILE* pf = fopen("test.txt", "w");
	fputs("abcdef", pf);//先将代码放在输出缓冲区
	printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
	Sleep(10000);
	printf("刷新缓冲区\n");
	fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
	//注：fflush 在高版本的VS上不能使用了
	printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
	Sleep(10000);
	fclose(pf);
	//注：fclose在关闭文件的时候，也会刷新缓冲区
	pf = NULL;
	return 0;
}