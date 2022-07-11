#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact* pc)   //初始化通讯录
{
	assert(pc);
	memset(pc->date, 0, sizeof(pc->date));  //通讯录里面的信息全部初始化为0
	pc->count = 0;
}

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
	return *(char*)e1 - *(char*)e2;
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
	InitContact(pc);  //清空相当于把通讯录初始化
}