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
	printf("ͨѶ¼����̬�棩\n");
	int input = 0;
	Contact con;  //����ͨѶ¼����
	InitContact(&con);  //��ʼ��ͨѶ¼
	do
	{
		menu();  //�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			DistoryContact(&con);  //����ͨѶ¼����ֹ�ڴ�й¶
			printf("�˳�ͨѶ¼\n");
			break;
		case ADD:
			AddPeoInfo(&con);  //�����ϵ����Ϣ
			break;
		case DEL:
			DeletePeoInfo(&con);  //ɾ����ϵ����Ϣ
			break;
		case SEARCH:
			SearchPeoInfo(&con);  //������ϵ����Ϣ����ӡ
			break;
		case MODIFY:
			ModifyPeoInfo(&con);  //�޸���ϵ����Ϣ
			break;
		case SORT:
			SortContact(&con);  //��ͨѶ¼��������(������)
			break;
		case SHOW:
			ShowPeoInfo(&con);  //��ʾȫ����ϵ����Ϣ
			break;
		case CLEAR:
			ClearContact(&con);  //���������ϵ��
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (input);
}