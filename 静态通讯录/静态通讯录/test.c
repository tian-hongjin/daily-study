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
	printf("��̬ͨѶ¼\n");
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
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		case 1:
			AddPeoInfo(&con);  //�����ϵ����Ϣ
			break;
		case 2:
			DeletePeoInfo(&con);  //ɾ����ϵ����Ϣ
			break;
		case 3:
			SearchPeoInfo(&con);  //������ϵ����Ϣ����ӡ
			break;
		case 4:
			ModifyPeoInfo(&con);  //�޸���ϵ����Ϣ
			break;
		case 5:
			SortContact(&con);  //��ͨѶ¼��������(������)
			break;
		case 6:
			ShowPeoInfo(&con);  //��ʾȫ����ϵ����Ϣ
			break;
		case 7:
			ClearContact(&con);  //���������ϵ��
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (input);
}