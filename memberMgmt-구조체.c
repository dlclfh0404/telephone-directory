/*
	Member Rnformation Management
	fileName : memberMgmt-����ü.c
	
	Date : 2022.08.04
*/

#include<stdio.h>
#include<stdlib.h> //exit()
#include<windows.h> //system()
#include<string.h> //���ڿ� ó�� 

/* ������ ���� ���� */ 
const char aId[20] = "admin";
const char aPass[20] = "pass123";

/* ȸ�� ���� ���� �� �ʱ�ȭ ����*/
#define mMAX 3 //�ִ� ȸ����
struct member{
	char mName[20], mPhone[20], mEmail[100];
	int mNum;
};

int mCount=-1; //��ϵ� ȸ���� 
struct member Member[mMAX]; //Member[0] ~ Member[mMax-1] ���� ����ü ������ ���������. 

void banner()
{
	puts("********************************");
	puts("** ȸ�� ���� ���� �ý��� ���� **");
	puts("** ȯ���մϴ�.                **");
	puts("** �ε� ��....                **");
	puts("** *****************************");
	sleep(3); //3�ʰ� ��� 
	system("cls"); //ȭ�� ���� 
}

int check_id_pw(char id[], char pw[])
{
//id, pw �� �����ڰ� �̸� 1�� ���� 
	if( strcmp(id, aId) ==0 && strcmp(pw, aPass) ==0)
		return 1;
	return 0;
}
/*
	�α����� ������ ȭ��
*/

// i��° ��� ���
void printMember(int i)
{
	puts("-------------------------------"); 
	printf("ȸ����ȣ : %d \n", Member[i].mNum);
	printf("ȸ���̸� : %s \n", Member[i].mName);
	printf("��ȭ��ȣ : %s \n", Member[i].mPhone);
	printf("ȸ���̸��� : %s \n", Member[i].mEmail);
	puts("-------------------------------");
} 

//��� ��ȸ
//ȸ���� ��ü �Ǵ� �Ϻθ� ��� 
void memSearch()
{
	int i;
	system("cls");
	puts("ȸ�� ���� ��ȸ �� ...");
	
	if(mCount == -1){
		puts("��ϵ� ȸ���� �����ϴ�.");
		puts("\n **�޴��� ���ư��ϴ�. **");
		sleep(1); 
		return; //���� �Լ��� ���ư���. 
	}
	
	for(i=0; i <= mCount ; i++) {
		printMember(i); 
	} 
	puts(" �ƹ�Ű�� ������ ���ư��ϴ�......");
	getchar(); getchar();
}

void memInsert()
{
	int ch;
	
	system("cls");
	if(mCount+1 >= mMAX){
		puts("ȸ���� �ʰ��Ǿ����ϴ�.");
		puts("ȸ�� ������ �Ұ��� �մϴ�.");
		sleep(1); //1�� ��� ��
		return; 
	}
	puts("** ȸ�� �߰��� �����մϴ�. **");
	puts("�Ʒ� ������ �Է����ּ���");
	
	mCount++; //ȸ�� �� ����.
	printf("ȸ����ȣ ( %d ) �� �����Ǿ����ϴ�.", mCount+1);
	
	Member[mCount].mNum = mCount+1; //ȸ����ȣ�� ���. 
	
	while(1){
		printf("�̸� : "); scanf("%s", Member[mCount].mName );
		printf("��ȭ��ȣ : "); scanf("%s", Member[mCount].mPhone ); 
		printf("�̸��� : "); scanf("%s", Member[mCount].mEmail );
		
		puts("�ش� ������ �����ұ��?\n");
		printf("\n1. �ٽ� �Է�  �׿� ��(����) : "); 
		ch = getch(); 
		
		if(ch != '1') //1�϶��� while Ż��.
			break;  
	}
	printf("\n** %d ȸ�������� ���������� �߰��Ǿ����ϴ�. \n**", Member[mCount].mNum);
	printf(" %s , %s, %s \n" , Member[mCount].mName , Member[mCount].mPhone , Member[mCount].mEmail );
	sleep(2);
}

//��ȭ��ȣ�� ��ȸ�ؼ�, ȸ���� ��ġ(i)�� ��ȯ. �ƴϸ� -1 
int is_Member(){
	int i;
	char phone[20]; 
	
	puts("ȸ�������� ���� ��ȭ��ȣ�� �Է��ϼ���.");
	printf("��ȭ��ȣ(010-0000-0000) : ");
	scanf("%s", phone);
	for(i=0 ; i<=mCount; i++){ //��ȭ��ȣ�� ��ġ�ϴ� ȸ�� ��ȸ. 
		if( strcmp(phone, Member[i].mPhone) == 0 ){
			puts("*��ġ�ϴ� ȸ�� ������ ã�ҽ��ϴ�.*");
			return i;
		} 
			 
	}
	return -1;
	
}

void oneSearch()
{
	int i;
	system("cls");
	if(mCount == -1){
		puts("��ϵ� ȸ���� �����ϴ�.");
		puts("\n **�޴��� ���ư��ϴ�. **");
		sleep(1);
		return ; //���� �Լ��� ���ư���. 
	}
	
	i = is_Member(); //����� ��ȸ�ؼ� ��ġ�� ��ȯ �޴´�. 
	
	if( i > -1)
		printMember(i);
	else
		puts("��ġ�ϴ� ȸ�� ������ �����ϴ�.");	
		 
	puts(" �ƹ�Ű�� ������ ���ư��ϴ�......");
	getchar(); getchar(); 
}


void login_success(char id[])
{
	int menu, ch;   //ch = ȸ�� ��ȸ �� ��ü��ȸ, �Ѹ� ��ȸ�� �� ������ üũ. 
		
	while(1){
		sleep(1);
		system("cls");
		printf("������ �α��� : %s\n",id);
		puts(""); //�ٹٲ� 
		puts("******************");  
		puts("** 1. ȸ�� ��ȸ **");
		puts("** 2. ȸ�� �߰� **");
		puts("** 3. ȸ�� ���� **");
		puts("** 4. ȸ�� Ż�� **");
		puts("** 5. �α� �ƿ� **");
		puts("** 6.  ��   ��  **");
		puts("******************"); 
		printf("���� -> ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				puts("ȸ����ȸ�� �����ϼ̽��ϴ�");
				printf("1.��ü ��ȸ, 2.ȸ����ȸ : ");
				scanf("%d",&ch);
				if(ch == 1) memSearch();
				else if(ch == 2) oneSearch(); 
				//memSearch();
				break;
			case 2:
				puts("ȸ���߰��� �����ϼ̽��ϴ�");
				memInsert();
				break;
			case 3:
				puts("ȸ��������  �����ϼ̽��ϴ�");
				//memEdit();
				break;
			case 4:
				puts("ȸ��Ż�� �����ϼ̽��ϴ�");
				//memDelete();
				break;	
			case 5:
				puts("�α׾ƿ� �մϴ�");
				sleep(1);
				return; //���� �Լ��� ���ư�.
			case 6:
				puts("�α׾ƿ� �� ���α׷� ����˴ϴ�.");
				sleep(1); 
				exit(0);//���α׷� ���� 
			default:
				puts("�ٽ� �����ϼ���"); 
		}//swithch
	}//while
}//�Լ� �� 

void login()
{
	char id[20], pw[20];
	system("cls");
	puts("********************************");
	puts("** ������ �α��� ȭ�� �Դϴ�. **");
	puts("********************************");
	
	puts(""); //�ٹٲ�
	printf("������ ID : ");
	scanf("%s", id);
	printf("������ PW : ");
	scanf("%s", pw);
	
	
	if(check_id_pw(id, pw) ) { //check_id_pw(id, pw) �Լ��� ���� 1�̸���  
		puts("�α��� ����");
		login_success(id); //�α��� ���� ȭ������ �̵� 
	}
	else
		puts("�α��� ����"); //�޽��� ��� �� main()���� ���ư�. 
	
	sleep(1);
}

void init_member()
{
	int i;
	mCount = -1;//���Ե� ��� �� -1
	for(i=0 ; i < mMAX; i++)
		Member[mCount].mNum = -1; //ȸ�� ��ü�� ȸ����ȣ�� -1�� ����.	
} 

int main()
{
	banner();
	init_member();//���� �ʱ�ȭ �Լ� ȣ�� 
	while(1) {
		login();
		system("cls");
		puts("�α��� â���� �̵��մϴ�.");
		sleep(2);
		system("cls");
	}
	
	return 0;
}
