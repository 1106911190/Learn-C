#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct student{
	char 	No[6],name[20],sex[5],age[4];
	char 	className[10],address[40],email[30],QQ[10],tel[15];
	struct student *next;
}student;

student 	*head;

int AddStudent(void);
int DeleteStudent(void);
int RepairStudent(void);
int VerificationIdentity(void);
int maintain(void);
int FindName(void);
int findAddr(void);
int FindNumber(void);
int find(void);
int initStuInfo(void);
void Print(student *);

int initStuInfo(void){
	FILE 	*fp;
	student 	*p1,*p2;
	fp = fopen("FILE.DAT","r");
	if(fp==NULL){
		printf("δ�ܳ�ʼ��ѧ����Ϣ\n");
		fclose(fp);
		return 0;
	}else{
		head = (student*)malloc(sizeof(student));		
		p1 = head;
		while(!feof(fp)){
			p2 = (student*)malloc(sizeof(student));
			fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",p2->No,p2->name,p2->sex,p2->age,p2->className,p2->address,p2->email,p2->QQ,p2->tel);
			p1->next = p2;
			p1 = p2;
		}
		p2->next = NULL;
		fclose(fp);
		return 1;
	}
}

void Print(student *p){
	printf("ѧ�ţ�  %s\n",p->No);
	printf("������  %s\n",p->name);
	printf("�Ա�  %s\n",p->sex);
	printf("���䣺  %s\n",p->age);
	printf("�༶��  %s\n",p->className);
	printf("סַ��  %s\n",p->address);
	printf("E-mail��%s\n",p->email);
	printf("QQ��    %s\n",p->QQ);
	printf("�绰��  %s\n",p->tel);
}

int FindNumber(void){
	char 	sno[20];
	student *p;
	int flag;
	flag = 5;
	p = head->next;
	printf("\n����������Ҫ���ҵ�ѧ��[0001-1000]\n");
	scanf("%s",&sno);
	fflush(stdin);
	while(p){
		if(strcmp(sno,p->No)==0){
			Print(p);
			flag = 1;
			break;
		}
		p = p->next;
	}
	return flag;	
}

int FindName(void){
	char 	sno[20];
	student *p;
	int flag;
	flag = 5;
	p = head->next;
	printf("\n����������Ҫ���ҵ�����\n");
	scanf("%s",&sno);
	fflush(stdin);
	while(p){
		if(strcmp(sno,p->name)==0){
			Print(p);
			flag = 1;
			break;
		}
		p = p->next;
	}
	return flag;
}

int findAddr(void){
	char 	sno[40];
	student *p;
	int flag;
	flag = 5;
	p = head->next;
	printf("\n����������Ҫ���ҵĵ�ַ\n");
	scanf("%s",&sno);
	fflush(stdin);
	while(p){
		if(strcmp(sno,p->address)==0){
			Print(p);
			flag = 1;
			break;
		}
		p = p->next;
	}
	return flag;		
}

int VerificationIdentity(){
	char 	userID[20],passWord[20];
	char	superID[20],superWord[20];
	int 	i,legalUser;
	char	ch;
	FILE 	*fp;
	legalUser = 0;
	fp = fopen("superUser.DAT","r");
	if(fp==NULL){
		printf("\nȨ���ļ������ڣ�����");
	}else{
		do{
			printf("\n�������û���\n");
			i = 0;
			while(isalpha(ch=getch())&&i<20){
				putchar(ch);
				userID[i]=ch;
				i++;
			}
			userID[i]='\0';
			printf("\n����������\n");
			i = 0;
			while(isalpha(ch=getch())&&i<20){
				putchar('*');
				passWord[i]=ch;
				i++;
			}
			passWord[i]='\0';
			rewind(fp);
			while(!feof(fp)){
				fscanf(fp,"%s\t%s\t\n",&superID,&superWord);
				if((strcmp(userID,superID)==0)&&(strcmp(passWord,superWord)==0)){
					legalUser = 1;
					break;
				}
			}
			if(legalUser)
				break;
			else{
				printf("\n����û��������������Ƿ��������룿[y/n]\n");
				ch = getche();
			}
		}while(tolower(ch)=='y');
	}
	return legalUser;
}

int find(void){
	char ch;
	int flag;
	flag = 4;
	while(flag){
		printf("\n\t\t**************************��ѯ*****************************\n");
		printf("\t\t*                         1.ѧ��                          *\n");
		printf("\t\t*                         2.����                          *\n");
		printf("\t\t*                         3.��ַ                          *\n");
		printf("\t\t*                         0.�˳�                          *\n");
		printf("\t\t***********************************************************\n");
		printf("��ѡ��(1/2/3/0):\n");
		ch = getche();
		switch(ch){
			case '1':flag = FindNumber();
				break;
			case '2':flag = FindName();
				break;
			case '3':flag = findAddr();
				break;
			case '0':flag = 0;
				break;
			default:printf("������������������\n");
				flag = 4;
				break;
		}
		if(flag == 5){
			printf("�������ҵ�ѧ��������!\n");
				flag = 1;
		}
	}
	return 1;
}

int AddStudent(void){
	student 	*p2,*p3;
	char		ch;
	int 		addFlag;
	p2 = head->next;
	while(p2->next!=NULL){
		p2 = p2->next;
	}
	ch = 'y';
	while(tolower(ch)=='y'){
		p3 = (student*)malloc(sizeof(student));
		printf("��������������\n");
		printf("ѧ�ţ�");
		scanf("%s",p3->No);
		printf("������");
		scanf("%s",p3->name);
		printf("���䣺");
		scanf("%s",p3->age);
		printf("�Ա�");
		scanf("%s",p3->sex);
		printf("�༶��");
		scanf("%s",p3->className);
		printf("סַ��");
		scanf("%s",p3->address);
		printf("E-mail��");
		scanf("%s",p3->email);
		printf("QQ��");
		scanf("%s",p3->QQ);
		printf("�绰��");
		scanf("%s",p3->tel);
		p3->next = NULL;
		printf("\n��ȷ���������룬[y/n]\n");
		ch = getche();
		if(tolower(ch)=='y'){
			p2->next = p3;
			p2 = p3;
			p3 = NULL;
			printf("\n�����Ϣ�ɹ���\n");
			addFlag = 1;
		}else{
			printf("\nδ�����ѧ����Ϣ��\n");
			addFlag = 0;
		}
		printf("\n�Ƿ������һ��ѧ����Ϣ? [y/n]\n");
		ch = getche();
	}
	return addFlag;
}

int DeleteStudent(void){
	char	ch,stuNo[20];
	int 	deleteFlag;
	student *p,*q;
	ch = 'y';
	do{
		printf("\n�������ɾ����ѧ����ѧ�ţ�");
		gets(stuNo);
		p = head->next;
		q = head;
		while(p!=NULL){
			if(strcmp(p->No,stuNo)){
				q = p;
				p = p->next;
			}else{
				printf("\n��Ҫɾ����ѧ�������ǣ�%s\n",p->name);
				printf("\n�����ٴ�ȷ��[y/n]\n");
				ch = getche();
				if(tolower(ch)=='y'){
					q->next = p->next;
					deleteFlag = 3;
					break;
				}else{
					deleteFlag = 4;
					break;
				}
			}
		}
		if(p==NULL){
			printf("\n��������Ҫɾ����ѧ��������\n");
			deleteFlag = 5;
		}
		printf("\n�Ƿ�ɾ����һ��ѧ������Ϣ?[y/n]\n");
		ch = getche();
	}while(tolower(ch)=='y');
	return deleteFlag;
}

int RepairStudent(void){
	int repairFlag;
	char ch,stuNo[20];
	student *p,*q;
	do{
		printf("\n��������޸ĵ�ѧ����ѧ��\n");
		gets(stuNo);
		p = head->next;
		while(p!=NULL){
			if(strcmp(p->No,stuNo)){
				p = p->next;
			}else{
				break;
			}
		}
		if(p!=NULL){
			do{
				printf("\n����Ҫ�޸ĵ�ѧ����ԭʼ��Ϣ�ǣ�\n");
				Print(p);
				printf("\n��������Ҫ�޸ĵ����ݣ�\n");
				printf("1.ѧ�� 2.���� 3.���� 4.�Ա� 5.�༶ 6.סַ 7.E-mail 8.QQ 9.�绰");
				printf("\n��ѡ��:");
				ch = getche();
				switch(ch){
					case '1':printf("\n�������µ����ݣ�\n");
						gets(p->No);
						repairFlag = 6;
						break;
					case '2':printf("\n�������µ����ݣ�\n");
						gets(p->name);
						repairFlag = 6;
						break;
					case '3':printf("\n�������µ����ݣ�\n");
						gets(p->age);
						repairFlag = 6;
						break;
					case '4':printf("\n�������µ����ݣ�\n");
						gets(p->sex);
						repairFlag = 6;
						break;
					case '5':printf("\n�������µ����ݣ�\n");
						gets(p->className);
						repairFlag = 6;
						break;
					case '6':printf("\n�������µ����ݣ�\n");
						gets(p->address);
						repairFlag = 6;
						break;
					case '7':printf("\n�������µ����ݣ�\n");
						gets(p->email);
						repairFlag = 6;
						break;
					case '8':printf("\n�������µ����ݣ�\n");
						gets(p->QQ);
						repairFlag = 6;
						break;
					case '9':printf("\n�������µ����ݣ�\n");
						gets(p->tel);
						repairFlag = 6;
						break;
					default:printf("��������������������롣");
				}
				printf("\n�Ƿ�Ҫ�޸�ѧ����Ϣ?[y/n]\n");
				ch = getche();
			}while(tolower(ch)=='y');
		}else{
			printf("\n��������Ҫ�޸ĵ�ѧ��������\n");
			repairFlag = 0;
		}
		printf("\n�Ƿ�����޸�����ѧ��?[y/n]\n");
		ch = getche();		
	}while(tolower(ch)=='y');
	return repairFlag;
}

int Save(void){
	FILE *fp;
	student *p;
	p = head->next;
	if((fp=fopen("FILE.DAT","w"))==NULL){
		printf("\n�����ļ�����������˶��ļ���\n");
		fclose(fp);
		return 0;
	}else{
		rewind(fp);
		while(p!=NULL){
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",p->No,p->name,p->sex,p->age,p->className,p->address,p->email,p->QQ,p->tel);
			p = p->next;
		}
		fclose(fp);
		return 1;
	}
}

int maintain(void){
	char ch;
	int success,saveFlag,maintainR = 4;
	success = VerificationIdentity();
	if(success == 0){
		printf("\n������Ȩ�û�������\n");
		maintainR = 0;
	}else{
		while(maintainR){
			printf("\n\t\t**************************ά��*****************************\n");
			printf("\t\t*                         1.����                          *\n");
			printf("\t\t*                         2.ɾ��                          *\n");
			printf("\t\t*                         3.�޸�                          *\n");
			printf("\t\t*                         4.����                          *\n");
			printf("\t\t*                         0.�˳�                          *\n");
			printf("\t\t***********************************************************\n");
			printf("��ѡ��(1/2/3/4/0):\n");
			ch = getche();
			switch(ch){
				case '1':maintainR = AddStudent();
					break;
				case '2':maintainR = DeleteStudent();
					break;
				case '3':maintainR = RepairStudent();
					break;
				case '4':maintainR = find();
					break;
				case '0':maintainR = 0;
					break;
				default:printf("������������������\n");
					break;
			}			
		}
		printf("\n��������˶�ѧ����Ϣ��ά����\n");
		printf("����ȷ���Ƿ������Ա������������޸ģ�[y/n]\n");
		ch = getche();
		if(tolower(ch)=='y'){
			saveFlag = Save();
			if(saveFlag){
				maintainR = 4;
			}
			else{
				printf("\n����ʧ��\n");
				maintainR = 4;
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int initFlag,quitFlag,maintainFlag,findFlag;
	char ch;
	quitFlag  = 1;
	initFlag  = initStuInfo();
	if(initFlag)
		while(quitFlag){
			printf("\n\t\t*******************ѧ����Ϣ��ѯϵͳ************************\n");
			printf("\t\t*                     1.��ѯ                              *\n");
			printf("\t\t*                     2.ά��                              *\n");
			printf("\t\t*                     0.�˳�                              *\n");
			printf("\t\t***********************************************************\n");
			printf("��ѡ��(1/2/0):\n");
			ch = getche();
			switch(ch){
				case '1':findFlag = find();
					quitFlag = findFlag;
					break;
				case '2':maintainFlag = maintain();
					quitFlag = maintainFlag;
					break;
				case '0':quitFlag = 0;
					break;
				default:printf("\n�����������������룺\n\n\n");
					break;
			}
		}
	else{
		printf("��ʼ��ѧ����Ϣʧ�ܣ�\n");
		return 1;
	}
	printf("\n�ټ����밴������˳�\n");
	getchar();
	return 0;
}


