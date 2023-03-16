# telephone-directory

### 코드
```C
/*
	Member Rnformation Management
	fileName : memberMgmt-구조체.c
	
	Date : 2022.08.04
*/

#include<stdio.h>
#include<stdlib.h> //exit()
#include<windows.h> //system()
#include<string.h> //문자열 처리 

/* 관리자 계정 정보 */ 
const char aId[20] = "admin";
const char aPass[20] = "pass123";

/* 회원 계정 정보 및 초기화 상태*/
#define mMAX 3 //최대 회원수
struct member{
	char mName[20], mPhone[20], mEmail[100];
	int mNum;
};

int mCount=-1; //등록된 회원수 
struct member Member[mMAX]; //Member[0] ~ Member[mMax-1] 까지 구조체 변수가 만들어진다. 

void banner()
{
	puts("********************************");
	puts("** 회원 정보 관리 시스템 시작 **");
	puts("** 환영합니다.                **");
	puts("** 로딩 중....                **");
	puts("** *****************************");
	sleep(3); //3초간 대기 
	system("cls"); //화면 삭제 
}

int check_id_pw(char id[], char pw[])
{
//id, pw 가 관리자가 이면 1을 리턴 
	if( strcmp(id, aId) ==0 && strcmp(pw, aPass) ==0)
		return 1;
	return 0;
}
/*
	로그인이 성공된 화면
*/

// i번째 멤버 출력
void printMember(int i)
{
	puts("-------------------------------"); 
	printf("회원번호 : %d \n", Member[i].mNum);
	printf("회원이름 : %s \n", Member[i].mName);
	printf("전화번호 : %s \n", Member[i].mPhone);
	printf("회원이메일 : %s \n", Member[i].mEmail);
	puts("-------------------------------");
} 

//멤버 조회
//회원의 전체 또는 일부만 출력 
void memSearch()
{
	int i;
	system("cls");
	puts("회원 정보 조회 중 ...");
	
	if(mCount == -1){
		puts("등록된 회원이 없습니다.");
		puts("\n **메뉴로 돌아갑니다. **");
		sleep(1); 
		return; //이전 함수로 돌아간다. 
	}
	
	for(i=0; i <= mCount ; i++) {
		printMember(i); 
	} 
	puts(" 아무키나 누르면 돌아갑니다......");
	getchar(); getchar();
}

void memInsert()
{
	int ch;
	
	system("cls");
	if(mCount+1 >= mMAX){
		puts("회원이 초과되었습니다.");
		puts("회원 가입이 불가능 합니다.");
		sleep(1); //1초 대기 후
		return; 
	}
	puts("** 회원 추가를 시작합니다. **");
	puts("아래 정보를 입력해주세요");
	
	mCount++; //회원 수 증가.
	printf("회원번호 ( %d ) 가 생성되었습니다.", mCount+1);
	
	Member[mCount].mNum = mCount+1; //회원번호를 기록. 
	
	while(1){
		printf("이름 : "); scanf("%s", Member[mCount].mName );
		printf("전화번호 : "); scanf("%s", Member[mCount].mPhone ); 
		printf("이메일 : "); scanf("%s", Member[mCount].mEmail );
		
		puts("해당 정보로 저장할까요?\n");
		printf("\n1. 다시 입력  그외 값(저장) : "); 
		ch = getch(); 
		
		if(ch != '1') //1일때만 while 탈출.
			break;  
	}
	printf("\n** %d 회원정보가 정상적으로 추가되었습니다. \n**", Member[mCount].mNum);
	printf(" %s , %s, %s \n" , Member[mCount].mName , Member[mCount].mPhone , Member[mCount].mEmail );
	sleep(2);
}

//전화번호를 조회해서, 회원의 위치(i)를 반환. 아니면 -1 
int is_Member(){
	int i;
	char phone[20]; 
	
	puts("회원정보에 사용될 전화번호를 입력하세요.");
	printf("전화번호(010-0000-0000) : ");
	scanf("%s", phone);
	for(i=0 ; i<=mCount; i++){ //전화번호와 일치하는 회원 조회. 
		if( strcmp(phone, Member[i].mPhone) == 0 ){
			puts("*일치하는 회원 정보를 찾았습니다.*");
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
		puts("등록된 회원이 없습니다.");
		puts("\n **메뉴로 돌아갑니다. **");
		sleep(1);
		return ; //이전 함수로 돌아간다. 
	}
	
	i = is_Member(); //멤버를 조회해서 위치를 반환 받는다. 
	
	if( i > -1)
		printMember(i);
	else
		puts("일치하는 회원 정보가 없습니다.");	
		 
	puts(" 아무키나 누르면 돌아갑니다......");
	getchar(); getchar(); 
}


void login_success(char id[])
{
	int menu, ch;   //ch = 회원 조회 시 전체조회, 한명 조회를 할 것인지 체크. 
		
	while(1){
		sleep(1);
		system("cls");
		printf("관리자 로그인 : %s\n",id);
		puts(""); //줄바꿈 
		puts("******************");  
		puts("** 1. 회원 조회 **");
		puts("** 2. 회원 추가 **");
		puts("** 3. 회원 수정 **");
		puts("** 4. 회원 탈퇴 **");
		puts("** 5. 로그 아웃 **");
		puts("** 6.  종   료  **");
		puts("******************"); 
		printf("선택 -> ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				puts("회원조회를 선택하셨습니다");
				printf("1.전체 조회, 2.회원조회 : ");
				scanf("%d",&ch);
				if(ch == 1) memSearch();
				else if(ch == 2) oneSearch(); 
				//memSearch();
				break;
			case 2:
				puts("회원추가를 선택하셨습니다");
				memInsert();
				break;
			case 3:
				puts("회원수정을  선택하셨습니다");
				//memEdit();
				break;
			case 4:
				puts("회원탈퇴를 선택하셨습니다");
				//memDelete();
				break;	
			case 5:
				puts("로그아웃 합니다");
				sleep(1);
				return; //이전 함수로 돌아감.
			case 6:
				puts("로그아웃 후 프로그램 종료됩니다.");
				sleep(1); 
				exit(0);//프로그램 종료 
			default:
				puts("다시 선택하세요"); 
		}//swithch
	}//while
}//함수 끝 

void login()
{
	char id[20], pw[20];
	system("cls");
	puts("********************************");
	puts("** 관리자 로그인 화면 입니다. **");
	puts("********************************");
	
	puts(""); //줄바꿈
	printf("관리자 ID : ");
	scanf("%s", id);
	printf("관리자 PW : ");
	scanf("%s", pw);
	
	
	if(check_id_pw(id, pw) ) { //check_id_pw(id, pw) 함수의 리턴 1이면참  
		puts("로그인 성공");
		login_success(id); //로그인 성공 화면으로 이동 
	}
	else
		puts("로그인 실패"); //메시지 출력 후 main()으로 돌아감. 
	
	sleep(1);
}

void init_member()
{
	int i;
	mCount = -1;//가입된 멤버 수 -1
	for(i=0 ; i < mMAX; i++)
		Member[mCount].mNum = -1; //회원 전체의 회원번호가 -1를 세팅.	
} 

int main()
{
	banner();
	init_member();//변수 초기화 함수 호출 
	while(1) {
		login();
		system("cls");
		puts("로그인 창으로 이동합니다.");
		sleep(2);
		system("cls");
	}
	
	return 0;
}
```
