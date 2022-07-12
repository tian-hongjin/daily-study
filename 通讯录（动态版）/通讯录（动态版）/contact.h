#pragma once  //��ֹͷ�ļ��ظ�����

//ͷ�ļ��İ���
#include <stdio.h>
#include <assert.h>  //assert��Ӧͷ�ļ�
#include <string.h>  //�ַ����������ڴ溯����Ӧͷ�ļ�
#include <stdlib.h>  //qsort��Ӧͷ�ļ�
#include <stdlib.h>  //��̬�ڴ��������Ӧͷ�ļ�
#include <errno.h>   //errno��Ӧͷ�ļ�

//�ṹ������

#define DEFAULT_SZ 5    //Ĭ����ϵ�˸���
#define CRE_SZ 2        //ÿ�����ݵı���
#define MAX_NAME 20     //�궨�������ϵ����Ϣ�����Ĵ�С�������Ժ��޸�
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

//��ϵ����Ϣ�ṹ��
typedef struct PeoInfo {
	char name[MAX_NAME];  //����
	char sex[MAX_SEX];    //�Ա�
	int age;			  //����
	char tele[MAX_TELE];  //�绰
	char addr[MAX_ADDR];  //סַ
}PeoInfo;   //�ṹ��������

//ͨѶ¼�ṹ��
typedef struct Contact {
	PeoInfo* date;     //����һ��ProInfo��ָ�룬ָ��Ϊ�䶯̬���ٵĿռ�
	int count;         //��¼ʵ����ϵ������
	int capacity;      //��¼��ǰͨѶ¼�����������˾�����
}Contact;

//����������
void InitContact(Contact* pc);            //��ʼ��ͨѶ¼
void AddPeoInfo(Contact* pc);             //�����ϵ����Ϣ
void ShowPeoInfo(const Contact* pc);      //��ʾ������ϵ����Ϣ
void DeletePeoInfo(Contact* pc);          //ɾ����ϵ����Ϣ
void SearchPeoInfo(const Contact* pc);    //����ָ����ϵ����Ϣ����ӡ
void ModifyPeoInfo(Contact* pc);          //�޸���ϵ����Ϣ
void SortContact(Contact* pc);            //��ͨѶ¼��������(������)
void ClearContact(Contact* pc);           //���������ϵ��
void DistoryContact(Contact* pc);         //����ͨѶ¼
