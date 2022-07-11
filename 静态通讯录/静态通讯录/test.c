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

int main()
{
	printf("静态通讯录\n");
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
		case 0:
			printf("退出通讯录\n");
			break;
		case 1:
			AddPeoInfo(&con);  //添加联系人信息
			break;
		case 2:
			DeletePeoInfo(&con);  //删除联系人信息
			break;
		case 3:
			SearchPeoInfo(&con);  //查找联系人信息并打印
			break;
		case 4:
			ModifyPeoInfo(&con);  //修改联系人信息
			break;
		case 5:
			SortContact(&con);  //对通讯录进行排序(按姓名)
			break;
		case 6:
			ShowPeoInfo(&con);  //显示全部联系人信息
			break;
		case 7:
			ClearContact(&con);  //清空所有联系人
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);
}