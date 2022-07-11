#pragma once  //��ֹͷ�ļ��ظ�����

//ͷ�ļ��İ���
#include <stdio.h>
#include <assert.h>  //assert��Ӧͷ�ļ�
#include <string.h>  //�ַ����������ڴ溯����Ӧͷ�ļ�
#include <stdlib.h>  //qsort��Ӧͷ�ļ�

//�ṹ������

#define MAX 100       //��ϵ�˵��������
#define MAX_NAME 20   //�궨�������ϵ����Ϣ�����Ĵ�С�������Ժ��޸�
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
	PeoInfo date[MAX];  //������ϵ����Ϣ
	int count;          //��¼ʵ����ϵ������
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
