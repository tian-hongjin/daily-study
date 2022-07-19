

@[TOC](文章目录)

# 一、总体设计思路

## 1、设计背景

在前面的文章中我们依次学习了结构体、动态内存管理以及文件操作的相关知识，所以我们今天可以分别来编写静态版、动态版和文件版的通讯录，用于对已学知识的应用与巩固，和对我们前面学习效果的检测。

## 2、设计框架

与正常的项目设计一样，我们把程序封装在三个文件中：

<r>

test.c：通讯录的总体逻辑，主要用于对通讯录各功能的测试；

<r>

contact.c：通讯录各种功能的具体实现；

<r>

contact.h：各种必要的声明，包括库函数头文件的声明、自定义结构的声明以及自定义函数的声明；

## 3、功能概述

我们这里设计的通讯录应包含如下功能：

<r>

静态版：通讯录内部联系人的增删查改、对联系人按姓名进行排序、显示通讯录中所有联系人、清空通讯录、退出通讯录；

<r>

动态版：动态版的通讯录与静态版通讯录功能一样，但是内部实现由固定大小改为动态增容；

<r>

文件版：文件版的通讯录与动态版功能与实现方式一样，但是会在程序退出时把联系人信息保存在文件中，在程序运行时把文件中的联系人信息加载到通讯录中；

***

# 二、通讯录（静态版）

## 1、结构体设计

这里我们设计两个结构体：一个用于管理联系人的各种属性，比如姓名、年龄、性别、电话号码、住址；另一个结构体用于管理通讯录，它由一个联系人结构体数组加上一个记录联系人数量的变量构成；由于我们这里设计的是静态版的通讯录，所以联系人结构体数组的大小是固定的。

```c
#define MAX 100       //联系人的最大数量
#define MAX_NAME 20   //宏定义各种联系人信息变量的大小，方便以后修改
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//联系人信息结构体
typedef struct PeoInfo {
	char name[MAX_NAME];  //姓名
	char sex[MAX_SEX];    //性别
	int age;			  //年龄
	char tele[MAX_TELE];  //电话
	char addr[MAX_ADDR];  //住址
}PeoInfo;   //结构体重命名

//通讯录结构体
typedef struct Contact {
	PeoInfo date[MAX];  //储存联系人信息（固定大小）
	int count;          //记录实际联系人数量
}Contact;
```

## 2、初始化通讯录

我们可以使用前面学习的 memset 函数来吧通讯录中存放联系人信息的数组的内容全部初始化为0，然后再把用于记录实际联系人数量的变量置为0，完成通讯录得初始化。

```c
void InitContact(Contact* pc)   //初始化通讯录
{
	assert(pc);
	memset(pc->date, 0, sizeof(pc->date));  //通讯录里面的信息全部初始化为0
	pc->count = 0;
}
```

## 3、添加联系人信息

这里由于通讯录大小是固定的，所以我们在添加联系人的时候要注意检查通讯录是否已满，如果没满才能正常添加，满了就打印提示信息并直接 return。

```c
void AddPeoInfo(Contact* pc)       //添加联系人信息
{
	assert(pc);
	if (pc->count == MAX)  //检查通讯录是否满了
	{
		printf("通讯录已满，无法添加联系人\n");
		return;
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", pc->date[pc->count].name);
		printf("请输入性别:>");
		scanf("%s", pc->date[pc->count].sex);
		printf("请输入年龄:>");
		scanf("%d", &(pc->date[pc->count].age));
		printf("请输入电话:>");
		scanf("%s", pc->date[pc->count].tele);
		printf("请输入住址:>");
		scanf("%s", pc->date[pc->count].addr);

		pc->count++;  //联系人数量++
		printf("添加联系人成功\n");
	}
}
```

## 4、删除联系人信息

这里有两个需要注意的地方：一是需要检查通讯录是否为空，如果为空提示后直接返回；二是我们要检查我们希望删除的这个人是否存在，所以我们需要设计一个find函数来查找联系人，根据find函数的结果来进行后续操作。

```c
void DeletePeoInfo(Contact* pc)          //删除联系人信息
{
	assert(pc);
	if (pc->count == 0)  //通讯录为空直接返回
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要删除的联系人的姓名:>");
		scanf("%s", &name);
		int pos = find_by_name(pc, name);  //检查通讯录中是否有该联系人
		if (pos == -1)
		{
			printf("该联系人不存在\n");
		}
		else
		{
			int i = 0;
			for (i = pos; i < pc->count - 1; i++)
			{
				pc->date[i] = pc->date[i + 1];
			}
			pc->count--;
			printf("删除联系人成功\n");
		}
	}
}
```

## 5、查找联系人(按姓名)

这里函数返回值的设计应该注意，如果我们查找到了就返回该联系人所在位置的下标，但是如果找不到我们不应该返回0，而是应该返回一个无意义的数，比如-1，因为数组是从0下标开始的，我们所查找的联系人可能在0位置处。

```c
//在通讯录中查找指定联系人，找到返回下标，找不到返回-1
static int find_by_name(const Contact* pc, char name[])   //函数用static修饰是为了让该函数只能在本文件内部被使用
{
	assert(pc && name);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
			return i;  //找到返回所在位置下标
	}
	return -1;  //找不到返回-1
}
```

## 6、查找指定联系人

和删除联系人一样，我们需要检查通讯录是否为空，调用find函数判断该联系人是否存在。

```c
void SearchPeoInfo(const Contact* pc)    //查找指定联系人信息并打印
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要查找的联系人的姓名:>");
		scanf("%s", name);
		int pos = find_by_name(pc, name);  //检查通讯录中是否有该联系人
		if (pos == -1)
		{
			printf("该联系人不存在\n");
		}
		else  //打印联系人信息
		{
			printf("%-20s\t%-10s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");  //打印表头
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[pos].name,  //打印数据
				pc->date[pos].sex,
				pc->date[pos].age,
				pc->date[pos].tele,
				pc->date[pos].addr);
		}
	}
}
```

## 7、修改联系人信息

```c
void ModifyPeoInfo(Contact* pc)          //修改联系人信息
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要修改的联系人的姓名:>");
		scanf("%s", name);
		int pos = find_by_name(pc, name);  //检查通讯录中是否有该联系人
		if (pos == -1)
		{
			printf("该联系人不存在\n");
		}
		else
		{
			printf("请输入修改后的姓名:>");
			scanf("%s", pc->date[pos].name);
			printf("请输入修改后的性别:>");
			scanf("%s", pc->date[pos].sex);
			printf("请输入修改后的年龄:>");
			scanf("%d", &(pc->date[pos].age));
			printf("请输入修改后的电话:>");
			scanf("%s", pc->date[pos].tele);
			printf("请输入修改后的住址:>");
			scanf("%s", pc->date[pos].addr);

			printf("成功修改联系人信息\n");
		}
	}
}
```

## 8、排序联系人(按姓名)

我们可以通过调用qsort函数，然后给定排序规则来实现对联系人信息的排序，这里我实现的是按姓名排序，大家通过可以修改排序方法来实现按年龄等其他规则的排序，甚至可以实现出所有排序方法的函数，然后将其放入函数指针数组中，最后通过回调函数的方式实现任意方式的排序。

```c
int cmp_name(const void* e1, const void* e2)  //qsort函数的排序函数
{
	assert(e1 && e2);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)            //对通讯录进行排序(按姓名)
{
	assert(pc);
	//qsort的使用：pc->date表示要排序数据的地址，pc->count表示待排序的元素个数，sizeof(PeoInfo)表示一个元素的大小，cmp_name表示排序的方法
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_name);
}
```

## 9、显示所有联系人信息

```c
void ShowPeoInfo(const Contact* pc)      //显示所有联系人信息
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("当前通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");  //打印表头
		for (i = 0; i < pc->count; i++)
		{
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[i].name,  //打印数据
				pc->date[i].sex,
				pc->date[i].age,
				pc->date[i].tele,
				pc->date[i].addr);
		}
	}
}
```

## 10、清空通讯录

对于静态版的通讯录来说，清空通讯录就相当于初始化通讯录，直接调用该函数即可。

```c
void ClearContact(Contact* pc)           //清空所有联系人
{
	assert(pc);
	InitContact(pc);  //清空相当于把通讯录初始化
}
```

## 11、完整代码

静态版通讯录的完整代码及相关数据文件我放在 GitHub 和 Gitee 上了，有需要的可以自取。

[完整代码地址 -- GitHub](https://github.com/tian-hongjin/daily-study/tree/master/通讯录（静态版）)

[完整代码地址 -- Gitee](https://gitee.com/tian-hongjin/code/tree/master/通讯录（静态版）)

***

# 二、通讯录（动态版）

我们发现静态版的通讯录存在两个缺陷：一是数组大小是固定的，导致当我们联系人比较少的时候会造成空间浪费，联系人比较多的时候又存储不下；二是我们的联系人信息并没有存储在文件中，都是临时的，每次我们程序重新运行的时候都需要重新添加联系人;

<r>

我们通过把静态版通讯录改造成动态版通讯录来解决空间浪费与不足的问题；

<r>

动态版通讯录与静态版通讯录的实现基本相同，只是把固定数组大小变为了可动态增容，相应需要改变的地方函数有：通讯录结构体、初始化函数、增加联系人信息函数(需要判断是否需要增容)、清空联系人信息函数；需要增加的函数有：检查容量函数(容量满了就增容)、销毁通讯录函数。

## 1、结构体设计

存放联系人信息的结构体不变，需要改动的是通讯录结构体，我们之前是在通讯录结构体中定义了一个固定大小的联系人结构体数组，用于存放联系人信息，但是现在我们用将其改为动态增容的，所以我们需要定义一个联系人指针变量，指向动态开辟的一块空间，来存放联系人信息；同时，我们还需要一个capacity变量，来记录当前通讯录的容量，如果当前联系人数量与其相等，我们就增容。

```c
#define DEFAULT_SZ 5    //默认联系人个数
#define CRE_SZ 2        //每次扩容的倍数
#define MAX_NAME 20     //宏定义各种联系人信息变量的大小，方便以后修改
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//联系人信息结构体
typedef struct PeoInfo {
	char name[MAX_NAME];  //姓名
	char sex[MAX_SEX];    //性别
	int age;			  //年龄
	char tele[MAX_TELE];  //电话
	char addr[MAX_ADDR];  //住址
}PeoInfo;   //结构体重命名

//通讯录结构体
typedef struct Contact {
	PeoInfo* date;     //定义一个ProInfo的指针，指向为其动态开辟的空间
	int count;         //记录实际联系人数量
	int capacity;      //记录当前通讯录得容量，满了就扩容
}Contact;
```

## 2、初始化通讯录

我们可以使用 malloc 函数来为 date 指针开辟空间，然后再使用 memset 函数将其内容全部初始化为0，我们也可以使用 calloc 函数，在开辟空间的同时把内存初始化为0。

```c
void InitContact(Contact* pc)   //初始化通讯录
{
	assert(pc);
	pc->date = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));  //调用calloc函数，开辟空间的同时完成初始化
	//若果申请失败，打印错误信息后直接返回
	if (pc->date == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	//如果申请成功
	pc->count = 0;
	pc->capacity = DEFAULT_SZ;
}
```

## 3、检查通讯录容量

比较通讯录结构体中的实际联系人数量和当前通讯录容量，如果二者相等，就使用 malloc 函数对通讯录进行扩容，这里我们一次扩容两倍，大家也可以通过修改 CRE_SZ 或者修改 calloc 函数参数来改变一次每扩容的大小。

```c
static void CheckCapacity(Contact* pc)  //函数用static修饰是为了让该函数只能在本文件内部被使用
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		//这里用另一个指针变量ptr接受realloc的返回值，避免开辟失败导致pc的指向丢失
		PeoInfo* ptr = (PeoInfo*)realloc(pc->date, pc->capacity * CRE_SZ * sizeof(PeoInfo));  //一次扩容CRA_SZ倍
		//开辟失败
		if (ptr == NULL)
		{
			printf("CheckCapacity::%s\n", strerror(errno));
			return;
		}
		//开辟成功
		pc->date = ptr;
		pc->capacity *= CRE_SZ;
		printf("扩容成功\n");
	}
}
```

## 4、清空联系人信息

与静态版通讯录不同，由于我们的空间是动态申请的，如果直接调用初始化通讯录函数会导致我们之前申请的空间得不到释放，从而造成内存泄漏，所以我们应该先调用销毁通讯录函数释放掉之前开辟的空间，再调用初始化通讯录函数。

```c
void ClearContact(Contact* pc)           //清空所有联系人
{
	assert(pc);
	DistoryContact(pc);  //销毁通讯录
	InitContact(pc);     //把通讯录重新初始化
	printf("成功清空通讯录\n");
}
```

## 5、销毁通讯录

```c
void DistoryContact(Contact* pc)
{
	assert(pc);
	free(pc->date);   //释放date指向的空间
	pc->date = NULL;  //把date置空，避免出现野指针
}
```

## 6、完整代码

动态版通讯录的完整代码及相关数据文件我放在 GitHub 和 Gitee 上了，有需要的可以自取。

[完整代码地址 -- GitHub](https://github.com/tian-hongjin/daily-study/tree/master/通讯录（动态版）)

[完整代码地址 -- Gitee](https://gitee.com/tian-hongjin/code/tree/master/通讯录（动态版）)

***

# 三、通讯录（文件版）

我们发现动态版的通讯录存在一个缺陷，那就是我们的联系人信息并没有存储在文件中，都是临时的，每次我们程序重新运行的时候都需要重新添加联系人;

<r>

我们通过把动态版通讯录改造成文件版通讯录来解决联系人信息存储问题；

<r>

文件版通讯录在动态版的基础上增加了两个步骤：一是在销毁通讯录之前把联系人信息存放到 contact.txt 中，避免程序退出后联系人信息丢失；二是在初始化通讯录的时候把 contact.txt 文件中的联系人信息存储到通讯录中；相应需要改变的函数有：初始化通讯录函数；相应需要增加的函数有：加载联系人信息函数、保存联系人信息函数。

## 1、保存联系人信息

```c
void SavePeoInfo(const Contact* pc)      //保存联系人信息
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "w");  //以"W"的形式把联系人信息保存到contact.txt中
	if (pfWrite == NULL)
	{
		perror("SavePeoInfo");
		return;
	}
	//存储信息
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fprintf(pfWrite, "%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].age,
			pc->date[i].tele,
			pc->date[i].addr);
	}

	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
}
```

## 2、初始化通讯录

```c
void InitContact(Contact* pc)   //初始化通讯录
{
	assert(pc);
	pc->date = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));  //调用calloc函数，开辟空间的同时完成初始化
	//若果申请失败，打印错误信息后直接返回
	if (pc->date == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	//如果申请成功
	pc->count = 0;
	pc->capacity = DEFAULT_SZ;

	LoadPeoInfo(pc);  //加载联系人信息
}
```

## 3、加载联系人信息

```c
void LoadPeoInfo(Contact* pc)  //加载联系人信息
{
	assert(pc);
	FILE* pfRead = fopen("contact.txt", "r");  //以"r"的方式把contact.txt中的信息读到通讯录中
	if (pfRead == NULL)
	{
		perror("LoadPeoInfo");
		return;
	}
	while (fscanf(pfRead, "%s %s %d %s %s", pc->date[pc->count].name,
		pc->date[pc->count].sex,
		&(pc->date[pc->count].age),
		pc->date[pc->count].tele,
		pc->date[pc->count].addr) != EOF)
	{
		pc->count++;
		CheckCapacity(pc);
	}

	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
}
```

## 4、完整代码

### test.c

```c
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("****************************************\n");
	printf("*******   1.Add       2.del      *******\n");
	printf("*******   3.search    4.Modify   *******\n");
	printf("*******   5.sort      6.show     *******\n");
	printf("*******   7.clear     0.exit     *******\n");
	printf("****************************************\n");
}

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
	CLEAR,
};

int main()
{
	printf("通讯录（文件版）\n");
	int input = 0;
	Contact con;  //创建通讯录变量
	InitContact(&con);  //初始化通讯录
	do
	{
		menu();  //菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			SavePeoInfo(&con);  //保存联系人信息
			DistoryContact(&con);  //销毁通讯录，防止内存泄露
			printf("退出通讯录\n");
			break;
		case ADD:
			AddPeoInfo(&con);  //添加联系人信息
			break;
		case DEL:
			DeletePeoInfo(&con);  //删除联系人信息
			break;
		case SEARCH:
			SearchPeoInfo(&con);  //查找联系人信息并打印
			break;
		case MODIFY:
			ModifyPeoInfo(&con);  //修改联系人信息
			break;
		case SORT:
			SortContact(&con);  //对通讯录进行排序(按姓名)
			break;
		case SHOW:
			ShowPeoInfo(&con);  //显示全部联系人信息
			break;
		case CLEAR:
			ClearContact(&con);  //清空所有联系人
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);
}
```

### contact.c

```c
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void LoadPeoInfo(Contact* pc)  //加载联系人信息
{
	assert(pc);
	FILE* pfRead = fopen("contact.txt", "r");  //以"r"的方式把contact.txt中的信息读到通讯录中
	if (pfRead == NULL)
	{
		perror("LoadPeoInfo");
		return;
	}
	while (fscanf(pfRead, "%s %s %d %s %s", pc->date[pc->count].name,
		pc->date[pc->count].sex,
		&(pc->date[pc->count].age),
		pc->date[pc->count].tele,
		pc->date[pc->count].addr) != EOF)
	{
		pc->count++;
		CheckCapacity(pc);
	}

	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(Contact* pc)   //初始化通讯录
{
	assert(pc);
	pc->date = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));  //调用calloc函数，开辟空间的同时完成初始化
	//若果申请失败，打印错误信息后直接返回
	if (pc->date == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	//如果申请成功
	pc->count = 0;
	pc->capacity = DEFAULT_SZ;

	LoadPeoInfo(pc);  //加载联系人信息
}

void CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		//这里用另一个指针变量ptr接受realloc的返回值，避免开辟失败导致pc的指向丢失
		PeoInfo* ptr = (PeoInfo*)realloc(pc->date, pc->capacity * CRE_SZ * sizeof(PeoInfo));  //一次扩容CRA_SZ倍
		//开辟失败
		if (ptr == NULL)
		{
			printf("CheckCapacity::%s\n", strerror(errno));
			return;
		}
		//开辟成功
		pc->date = ptr;
		pc->capacity *= CRE_SZ;
		printf("扩容成功\n");
	}
}

void AddPeoInfo(Contact* pc)       //添加联系人信息
{
	assert(pc);
	CheckCapacity(pc);  //检查容量，看是否需要扩容

	printf("请输入姓名:>");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入性别:>");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("请输入电话:>");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入住址:>");
	scanf("%s", pc->date[pc->count].addr);

	pc->count++;  //联系人数量++
	printf("添加联系人成功\n");
}

void ShowPeoInfo(const Contact* pc)      //显示所有联系人信息
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("当前通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");  //打印表头
		for (i = 0; i < pc->count; i++)
		{
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[i].name,  //打印数据
				pc->date[i].sex,
				pc->date[i].age,
				pc->date[i].tele,
				pc->date[i].addr);
		}
	}
}

//在通讯录中查找指定联系人，找到返回下标，找不到返回-1
static int find_by_name(const Contact* pc, char name[])   //函数用static修饰是为了让该函数只能在本文件内部被使用
{
	assert(pc && name);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
			return i;  //找到返回所在位置下标
	}
	return -1;  //找不到返回-1
}

void DeletePeoInfo(Contact* pc)          //删除联系人信息
{
	assert(pc);
	if (pc->count == 0)  //通讯录为空直接返回
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要删除的联系人的姓名:>");
		scanf("%s", &name);
		int pos = find_by_name(pc, name);  //检查通讯录中是否有该联系人
		if (pos == -1)
		{
			printf("该联系人不存在\n");
		}
		else
		{
			int i = 0;
			for (i = pos; i < pc->count - 1; i++)
			{
				pc->date[i] = pc->date[i + 1];
			}
			pc->count--;
			printf("删除联系人成功\n");
		}
	}
}

void SearchPeoInfo(const Contact* pc)    //查找指定联系人信息并打印
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要查找的联系人的姓名:>");
		scanf("%s", name);
		int pos = find_by_name(pc, name);  //检查通讯录中是否有该联系人
		if (pos == -1)
		{
			printf("该联系人不存在\n");
		}
		else  //打印联系人信息
		{
			printf("%-20s\t%-10s\t%-5s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");  //打印表头
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[pos].name,  //打印数据
				pc->date[pos].sex,
				pc->date[pos].age,
				pc->date[pos].tele,
				pc->date[pos].addr);
		}
	}
}

void ModifyPeoInfo(Contact* pc)          //修改联系人信息
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("请输入要修改的联系人的姓名:>");
		scanf("%s", name);
		int pos = find_by_name(pc, name);  //检查通讯录中是否有该联系人
		if (pos == -1)
		{
			printf("该联系人不存在\n");
		}
		else
		{
			printf("请输入修改后的姓名:>");
			scanf("%s", pc->date[pos].name);
			printf("请输入修改后的性别:>");
			scanf("%s", pc->date[pos].sex);
			printf("请输入修改后的年龄:>");
			scanf("%d", &(pc->date[pos].age));
			printf("请输入修改后的电话:>");
			scanf("%s", pc->date[pos].tele);
			printf("请输入修改后的住址:>");
			scanf("%s", pc->date[pos].addr);

			printf("成功修改联系人信息\n");
		}
	}
}

int cmp_name(const void* e1, const void* e2)  //qsort函数的排序函数
{
	assert(e1 && e2);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)            //对通讯录进行排序(按姓名)
{
	assert(pc);
	//qsort的使用：pc->date表示要排序数据的地址，pc->count表示待排序的元素个数，sizeof(PeoInfo)表示一个元素的大小，cmp_name表示排序的方法
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_name);
}

void ClearContact(Contact* pc)           //清空所有联系人
{
	assert(pc);
	DistoryContact(pc);  //销毁通讯录

	//重新初始化通讯录
	pc->date = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));  //调用calloc函数，开辟空间的同时完成初始化
	//若果申请失败，打印错误信息后直接返回
	if (pc->date == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	//如果申请成功
	pc->count = 0;
	pc->capacity = DEFAULT_SZ;
	printf("成功清空通讯录\n");
}

void DistoryContact(Contact* pc)
{
	assert(pc);
	free(pc->date);   //释放date指向的空间
	pc->date = NULL;  //把date置空，避免出现野指针
}

void SavePeoInfo(const Contact* pc)      //保存联系人信息
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "w");  //以"W"的形式把联系人信息保存到contact.txt中
	if (pfWrite == NULL)
	{
		perror("SavePeoInfo");
		return;
	}
	//存储信息
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fprintf(pfWrite, "%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].age,
			pc->date[i].tele,
			pc->date[i].addr);
	}

	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
}
```

### contact.h

```c
#pragma once  //防止头文件重复引用

//头文件的包含
#include <stdio.h>
#include <assert.h>  //assert对应头文件
#include <string.h>  //字符串函数、内存函数对应头文件
#include <stdlib.h>  //qsort对应头文件
#include <stdlib.h>  //动态内存管理函数对应头文件
#include <errno.h>   //errno对应头文件

//结构的声明

#define DEFAULT_SZ 5    //默认联系人个数
#define CRE_SZ 2        //每次扩容的倍数
#define MAX_NAME 20     //宏定义各种联系人信息变量的大小，方便以后修改
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//联系人信息结构体
typedef struct PeoInfo {
	char name[MAX_NAME];  //姓名
	char sex[MAX_SEX];    //性别
	int age;			  //年龄
	char tele[MAX_TELE];  //电话
	char addr[MAX_ADDR];  //住址
}PeoInfo;   //结构体重命名

//通讯录结构体
typedef struct Contact {
	PeoInfo* date;     //定义一个ProInfo的指针，指向为其动态开辟的空间
	int count;         //记录实际联系人数量
	int capacity;      //记录当前通讯录得容量，满了就扩容
}Contact;

//函数的声明
void InitContact(Contact* pc);            //初始化通讯录
void CheckCapacity(Contact* pc);          //检查通讯录容量
void AddPeoInfo(Contact* pc);             //添加联系人信息
void ShowPeoInfo(const Contact* pc);      //显示所有联系人信息
void DeletePeoInfo(Contact* pc);          //删除联系人信息
void SearchPeoInfo(const Contact* pc);    //查找指定联系人信息并打印
void ModifyPeoInfo(Contact* pc);          //修改联系人信息
void SortContact(Contact* pc);            //对通讯录进行排序(按姓名)
void ClearContact(Contact* pc);           //清空所有联系人
void DistoryContact(Contact* pc);         //销毁通讯录
void SavePeoInfo(const Contact* pc);      //保存联系人信息
void LoadPeoInfo(Contact* pc);            //加载联系人信息
```

大家也可以去 GitHub 和 Gitee 上获取完整代码。

[完整代码地址 -- GitHub](https://github.com/tian-hongjin/daily-study/tree/master/通讯录（文件版）/通讯录（文件版）)

[完整代码地址 -- Gitee](https://gitee.com/tian-hongjin/code/tree/master/通讯录（文件版）/通讯录（文件版）)

***

