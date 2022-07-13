#define _CRT_SECURE_NO_WARNINGS 1
//struct tag       //struct：结构体关键字  tag：结构体标签
//{
//	member - list;    //成员列表
//}variable - list;  //变量列表

//struct
//{
//	char name[20];  //名字
//	int age;        //年龄
//	char sex[5];    //性别
//	char id[20];    //学号
//}stu;            //结构体变量

//struct Node
//{
//	int data;
//	struct Node* next;
//};

//struct Point
//{
//	int x;
//	int y;
//}p1;     //声明类型的同时定义变量p1

//#include <stdio.h>
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}

//struct Test
//{
//	char c1;
//	int i;
//};

//#include <stdio.h>
//
//#pragma pack(8)//设置默认对齐数为8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//#pragma pack(1)//设置默认对齐数为1
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//
//int main()
//{
//	//输出的结果是什么？
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}

//#include <stdio.h>
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct S4));
//	return 0;
//}

//#include <stdio.h>
//
//#pragma pack(4)
//struct tagTest1
//{
//	short a;
//	char d;
//	long b;
//	long c;
//};
//struct tagTest2
//{
//	long b;
//	short c;
//	char d;
//	long a;
//};
//struct tagTest3
//{
//	short c;
//	long b;
//	char d;
//	long a;
//};
//#pragma pack()
//
//int main(int argc, char* argv[])
//{
//	struct tagTest1 stT1;
//	struct tagTest2 stT2;
//	struct tagTest3 stT3;
//
//	printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//	return 0;
//}

//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
//
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
//
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//
//int main()
//{
//	print1(s);  //传结构体
//	print2(&s); //传结构体地址
//	return 0;
//}

//#include <stdio.h>
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;;
//}

//#include <stdio.h>
//#include <stddef.h>  //offsetof对应头文件
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//
//int main()
//{
//	printf("%d\t", offsetof(struct S1, c1));
//	printf("%d\t", offsetof(struct S1, i));
//	printf("%d\n", offsetof(struct S1, c2));
//
//	printf("%d\t", offsetof(struct S2, c1));
//	printf("%d\t", offsetof(struct S2, c2));
//	printf("%d\n", offsetof(struct S2, i));
//
//	return 0;
//}

//#include <stdio.h>
//enum Day//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//
//enum Sex//性别
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//enum Color//颜色
//{
//	RED = 3,
//	GREEN,
//	BLUE
//};
//
//int main()
//{
//	printf("%d\n", Mon);
//	printf("%d\n", Tues);
//	printf("%d\n", Wed);
//	printf("%d\n", Thur);
//	printf("--------\n");
//	printf("%d\n", RED);
//	printf("%d\n", GREEN);
//	printf("%d\n", BLUE);
//}

//#include <stdio.h>
//enum Day//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//
//int main()
//{
//	enum Day day = 1;
//}

////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
////联合变量的定义
//union Un un;
//#include <stdio.h>
//
//union Un
//{
//	int i;
//	char c;
//};
//union Un un;
//
//int main()
//{
//	printf("%d\n", &un);
//	printf("%d\n", &(un.i));
//	printf("%d\n", &(un.c));
//}

//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//}

#include <stdio.h>

int Check_Sys()  //规定返回1为小端，返回0位大端
{
	union  //因为联合体只在本函数内调用一次，所以可以声明为匿名联合体
	{
		char c;
		int i;
	}un;

	un.i = 1;
	return un.c;
}

int main()
{
	int ret = Check_Sys();
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
	return 0;
}