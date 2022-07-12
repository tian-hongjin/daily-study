#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

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

static void CheckCapacity(Contact* pc)
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
	InitContact(pc);     //把通讯录重新初始化
	printf("成功清空通讯录\n");
}

void DistoryContact(Contact* pc)
{
	assert(pc);
	free(pc->date);   //释放date指向的空间
	pc->date = NULL;  //把date置空，避免出现野指针
}