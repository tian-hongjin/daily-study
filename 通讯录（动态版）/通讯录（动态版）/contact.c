#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void InitContact(Contact* pc)   //��ʼ��ͨѶ¼
{
	assert(pc);
	pc->date = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));  //����calloc���������ٿռ��ͬʱ��ɳ�ʼ��
	//��������ʧ�ܣ���ӡ������Ϣ��ֱ�ӷ���
	if (pc->date == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return;
	}
	//�������ɹ�
	pc->count = 0;
	pc->capacity = DEFAULT_SZ;
}

static void CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		//��������һ��ָ�����ptr����realloc�ķ���ֵ�����⿪��ʧ�ܵ���pc��ָ��ʧ
		PeoInfo* ptr = (PeoInfo*)realloc(pc->date, pc->capacity * CRE_SZ * sizeof(PeoInfo));  //һ������CRA_SZ��
		//����ʧ��
		if (ptr == NULL)
		{
			printf("CheckCapacity::%s\n", strerror(errno));
			return;
		}
		//���ٳɹ�
		pc->date = ptr;
		pc->capacity *= CRE_SZ;
		printf("���ݳɹ�\n");
	}
}

void AddPeoInfo(Contact* pc)       //�����ϵ����Ϣ
{
	assert(pc);
	CheckCapacity(pc);  //������������Ƿ���Ҫ����

	printf("����������:>");
	scanf("%s", pc->date[pc->count].name);
	printf("�������Ա�:>");
	scanf("%s", pc->date[pc->count].sex);
	printf("����������:>");
	scanf("%d", &(pc->date[pc->count].age));
	printf("������绰:>");
	scanf("%s", pc->date[pc->count].tele);
	printf("������סַ:>");
	scanf("%s", pc->date[pc->count].addr);

	pc->count++;  //��ϵ������++
	printf("�����ϵ�˳ɹ�\n");
}

void ShowPeoInfo(const Contact* pc)      //��ʾ������ϵ����Ϣ
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("��ǰͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");  //��ӡ��ͷ
		for (i = 0; i < pc->count; i++)
		{
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[i].name,  //��ӡ����
				pc->date[i].sex,
				pc->date[i].age,
				pc->date[i].tele,
				pc->date[i].addr);
		}
	}
}

//��ͨѶ¼�в���ָ����ϵ�ˣ��ҵ������±꣬�Ҳ�������-1
static int find_by_name(const Contact* pc, char name[])   //������static������Ϊ���øú���ֻ���ڱ��ļ��ڲ���ʹ��
{
	assert(pc && name);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
			return i;  //�ҵ���������λ���±�
	}
	return -1;  //�Ҳ�������-1
}

void DeletePeoInfo(Contact* pc)          //ɾ����ϵ����Ϣ
{
	assert(pc);
	if (pc->count == 0)  //ͨѶ¼Ϊ��ֱ�ӷ���
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	else
	{
		char name[MAX_NAME];
		printf("������Ҫɾ������ϵ�˵�����:>");
		scanf("%s", &name);
		int pos = find_by_name(pc, name);  //���ͨѶ¼���Ƿ��и���ϵ��
		if (pos == -1)
		{
			printf("����ϵ�˲�����\n");
		}
		else
		{
			int i = 0;
			for (i = pos; i < pc->count - 1; i++)
			{
				pc->date[i] = pc->date[i + 1];
			}
			pc->count--;
			printf("ɾ����ϵ�˳ɹ�\n");
		}
	}
}

void SearchPeoInfo(const Contact* pc)    //����ָ����ϵ����Ϣ����ӡ
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("������Ҫ���ҵ���ϵ�˵�����:>");
		scanf("%s", name);
		int pos = find_by_name(pc, name);  //���ͨѶ¼���Ƿ��и���ϵ��
		if (pos == -1)
		{
			printf("����ϵ�˲�����\n");
		}
		else  //��ӡ��ϵ����Ϣ
		{
			printf("%-20s\t%-10s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "סַ");  //��ӡ��ͷ
			printf("%-20s\t%-10s\t%-5d\t%-12s\t%-30s\n", pc->date[pos].name,  //��ӡ����
				pc->date[pos].sex,
				pc->date[pos].age,
				pc->date[pos].tele,
				pc->date[pos].addr);
		}
	}
}

void ModifyPeoInfo(Contact* pc)          //�޸���ϵ����Ϣ
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[MAX_NAME];
		printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
		scanf("%s", name);
		int pos = find_by_name(pc, name);  //���ͨѶ¼���Ƿ��и���ϵ��
		if (pos == -1)
		{
			printf("����ϵ�˲�����\n");
		}
		else
		{
			printf("�������޸ĺ������:>");
			scanf("%s", pc->date[pos].name);
			printf("�������޸ĺ���Ա�:>");
			scanf("%s", pc->date[pos].sex);
			printf("�������޸ĺ������:>");
			scanf("%d", &(pc->date[pos].age));
			printf("�������޸ĺ�ĵ绰:>");
			scanf("%s", pc->date[pos].tele);
			printf("�������޸ĺ��סַ:>");
			scanf("%s", pc->date[pos].addr);

			printf("�ɹ��޸���ϵ����Ϣ\n");
		}
	}
}

int cmp_name(const void* e1, const void* e2)  //qsort������������
{
	assert(e1 && e2);
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)            //��ͨѶ¼��������(������)
{
	assert(pc);
	//qsort��ʹ�ã�pc->date��ʾҪ�������ݵĵ�ַ��pc->count��ʾ�������Ԫ�ظ�����sizeof(PeoInfo)��ʾһ��Ԫ�صĴ�С��cmp_name��ʾ����ķ���
	qsort(pc->date, pc->count, sizeof(PeoInfo), cmp_name);
}

void ClearContact(Contact* pc)           //���������ϵ��
{
	assert(pc);
	DistoryContact(pc);  //����ͨѶ¼
	InitContact(pc);     //��ͨѶ¼���³�ʼ��
	printf("�ɹ����ͨѶ¼\n");
}

void DistoryContact(Contact* pc)
{
	assert(pc);
	free(pc->date);   //�ͷ�dateָ��Ŀռ�
	pc->date = NULL;  //��date�ÿգ��������Ұָ��
}