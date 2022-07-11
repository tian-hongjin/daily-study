#pragma once  //防止头文件重复引用

//头文件的包含
#include <stdio.h>
#include <assert.h>  //assert对应头文件
#include <string.h>  //字符串函数、内存函数对应头文件
#include <stdlib.h>  //qsort对应头文件

//结构的声明

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
	PeoInfo date[MAX];  //储存联系人信息
	int count;          //记录实际联系人数量
}Contact;

//函数的声明
void InitContact(Contact* pc);            //初始化通讯录
void AddPeoInfo(Contact* pc);             //添加联系人信息
void ShowPeoInfo(const Contact* pc);      //显示所有联系人信息
void DeletePeoInfo(Contact* pc);          //删除联系人信息
void SearchPeoInfo(const Contact* pc);    //查找指定联系人信息并打印
void ModifyPeoInfo(Contact* pc);          //修改联系人信息
void SortContact(Contact* pc);            //对通讯录进行排序(按姓名)
void ClearContact(Contact* pc);           //清空所有联系人
