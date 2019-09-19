#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "console.h"
#define TEXTLEN 128
#pragma comment(lib, "winmm.lib") //mmsystem.h ȣ��(timeGetTime() �Լ� ���)


/////////////////////�Լ�/////////////////////////////////////////////////
void drawhelp();
void print_switchmain();
void print_switchkor();
void print_switcheng();
///////////////////////////////////////////////////////////////////////////
int load_kor_short_textline(const char *);
bool read_kor_short_textfile();
int load_kor_long_textline(const char *);
bool read_kor_long_textfile();
int load_eng_short_textline(const char *);
bool read_eng_short_textfile();
int load_eng_long_textline(const char *);
bool read_eng_long_textfile();
////////////////////////////////////////////////////////////////////////////
int textline_kor_len(char *);
int textline_eng_len(char *);
////////////////////////////////////////////////////////////////////////////
int kor_checktext(char *, char *);
int eng_checktext(char *, char *);
////////////////////////////////////////////////////////////////////////////
int kor_short_run();
int kor_long_run();
int eng_short_run();
int eng_long_run();
/////////////////////////////////////////////////////////////////////////////
int get_rand(int , int);
void freetexts();
/////////////////////////////////////////////////////////////////////////////
void kor_short_main();
void kor_long_main();
void eng_short_main();
void eng_long_main();
///////////////////����//////////////////////////////////////////////////////
int textlines = 0;
char **texts = NULL;
char kor_long[] = "kor_long.txt";
char kor_short[] = "kor_short.txt";
char eng_long[] = "eng_long.txt";
char eng_short[] = "eng_short.txt";
char buff[20];
char taza[10];
//////////////////////////////////////////////////////////////////////////////

/////////////////////�ڿ�ĳ��/////////////////////////////////////////////////
void get_Jawon();
void limit(char *);
bool loa_level(int);
void check_text(char *);
void Jawon_show();
bool check_time();
int get_time();
void reset_game();
///////////////////�ڿ�ĳ�⺯��///////////////////////////////////////////////////////////////////
const char* level[] = {"level1.txt", "level2.txt", "level3.txt", "level4.txt", "level5.txt"};
int lev = 1;
int point = 0;
char* data[5][5];
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	system("cls");
	int num1 = 0;
	print_switchmain();
	printf("\n���ϴ� ����� �����Ͻÿ� : ");
	scanf("%d", &num1);
	fflush(stdin);

	while(num1 != 4)
	{
		if(num1 <= 4 && num1 >0)
		{
			switch(num1)
			{
			case 1 : 
				{
					system("cls");
					int num2 = 0;
					char s[100];
					
					print_switchkor();
					printf("\n���ϴ� ����� �����Ͻÿ� : ");
					scanf("%d", &num2);
					fflush(stdin);

					switch(num2)
					{
					case 1 :
						{
							system("cls");
							textcolor(CC_FONT_YELLOW, 0);
							printf("�ѱ۳���Ÿ���Դϴ�.\n");
							kor_short_main();

						}
			
					case 2 :
						{
							system("cls");
							textcolor(CC_FONT_YELLOW, 0);
							printf("�ѱ۹���(�Ӵ�)Ÿ���Դϴ�.\n");
							kor_long_main();
						}

					case 3 :
						{
							textcolor(CC_FONT_YELLOW, 0);
							printf("\n��� �� �ڷ� ���ư��ϴ�.\n");
							Sleep(2500);
							return main();
						}
					default :
						return main();
					}
					
				}

				return 0;

			case 2 :
				{
					int num2 = 0;
					char s[100];
					system("cls");

					print_switcheng();
					printf("\n���ϴ� ����� �����Ͻÿ� : ");
					scanf("%d", &num2);
					fflush(stdin);

					switch(num2)
					{
					case 1 :
						{
							system("cls");
							printf("�����Ÿ���Դϴ�.\n");
							eng_short_main();
						}
			
					case 2 :
						{
							system("cls");
							printf("�����(�Ӵ�)Ÿ���Դϴ�.\n");
							eng_long_main();
							break;
						}

					case 3 :
						{
							textcolor(CC_FONT_YELLOW, 0);
							printf("\n����� �ڷ� ���ư��ϴ�.\n");
							Sleep(2500);
							return main();
						}
				
					default : 
						return main();
					}

				}
				return 0;

			case 3 :
				system("cls");
				get_Jawon();
				return 0;

			default : 
				return main();
			}
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void drawmain()
{
	textcolor(CC_FONT_GRAY, 0);
	puts("��������������������������������������������������������������������������");
	textcolor(CC_FONT_GREEN, 0);
	puts("                          Ÿ    ��    ��   ��                             ");
	puts("");
	textcolor(CC_FONT_YELLOW, 0);
	puts(" - ������ ��� ���� �Ȱ��� �Է��ϰ� [ENTER] ��������                      ");
	puts(" - �� 1000���� �Ӵ���� ���ɴϴ�. ");
	puts(" - �Է��� �� 0.5�� �� ���� ������ ���ɴϴ�.");
	puts(" - Ÿ�� ������ �������� �ƹ� �Է¾��� [ENTER]�� ���� �ּ���");
	puts(" - �ƹ� �Է¾��� [ENTER]�� ������ �������� ���ư��ϴ�.");
	textcolor(CC_FONT_GRAY, 0);
	puts("��������������������������������������������������������������������������");
	textcolor(CC_FONT_WHITE, 0);
}

void print_switchmain()
{
	textcolor(CC_FONT_GRAY, 0);
	printf("��--------------------------------------------��\n");
	printf("��            TAJA �� Ÿ�����α׷�            ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��             1. �ѱ�Ÿ���Դϴ�.             ��\n"); 
	printf("��             2. ����Ÿ���Դϴ�.             ��\n");
	printf("��             3. �ڿ�ĳ���Դϴ�.             ��\n");
	printf("��             4. �����մϴ�.                 ��\n");
	printf("��                                            ��\n");
	printf("��                 �����մϴ�.                ��\n");
	printf("��--------------------------------------------��\n");
}

void print_switchkor()
{
	textcolor(CC_FONT_GRAY, 0);
	printf("��--------------------------------------------��\n");
	printf("��                                            ��\n");
	printf("��              �ѱ� Ÿ���Դϴ�.              ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��           1. �ѱ۳���Ÿ���Դϴ�.           ��\n");
	printf("��                                            ��\n");
	printf("��           2. �ѱ۹���Ÿ���Դϴ�.           ��\n");
	printf("��                                            ��\n");
	printf("��           3. �ڷε��ư��ϴ�.               ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��--------------------------------------------��\n");
}

void print_switcheng()
{
	textcolor(CC_FONT_GRAY, 0);
	printf("��--------------------------------------------��\n");
	printf("��                                            ��\n");
	printf("��              ���� Ÿ���Դϴ�.              ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��          1. �����Ÿ���Դϴ�.            ��\n");
	printf("��                                            ��\n");
	printf("��          2. �����Ÿ���Դϴ�.            ��\n");
	printf("��                                            ��\n");
	printf("��          3. �ڷε��ư��ϴ�                 ��\n");
	printf("��                                            ��\n");
	printf("��                                            ��\n");
	printf("��--------------------------------------------��\n");
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int get_kor_short_textline(const char *Filename)
{
	FILE *fp;
	fp = fopen(Filename, "r"); 
	if (fp == NULL)
		return -1;

	char s[TEXTLEN];
	int count = 0;

	while (true)
	{
		if (fgets(s, TEXTLEN, fp) == NULL)  
			break;                         
		count++;
	}

	fclose(fp);
	return count;
}

bool read_kor_short_textfile()
{
	textlines = get_kor_short_textline(kor_short);
	int i;

	if (textlines < 1)
	{
		printf("�ѱ۳��� ���� ���� ����\n");
		return main();
	}

	FILE *fp = fopen(kor_short, "r");
	texts = new char*[textlines];

	for (i = 0; i < textlines; i++)
	{
		texts[i] = new char[TEXTLEN];
		memset(texts[i], 0, TEXTLEN);
		if (fgets(texts[i], TEXTLEN, fp) == NULL) 
			break;
	}

	fclose(fp);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int get_kor_long_textline(const char *Filename)
{
	FILE *fp;
	fp = fopen(Filename, "r");
	if (fp == NULL)
		return -1;

	char s[TEXTLEN];
	int count = 0;

	while (true)
	{
		if (fgets(s, TEXTLEN, fp) == NULL)  
			break;                            
		count++;
	}

	fclose(fp);
	return count;
}

bool read_kor_long_textfile()
{
	textlines = get_kor_long_textline(kor_long);
	int i;

	if (textlines < 1)
	{
		printf("�ѱۼӴ� ���� ���� ����\n");
		return main();
	}

	FILE *fp = fopen(kor_long, "r");
	texts = new char*[textlines]; 

	for (i = 0; i < textlines; i++)
	{
		texts[i] = new char[TEXTLEN];
		memset(texts[i], 0, TEXTLEN);
		if (fgets(texts[i], TEXTLEN, fp) == NULL) 
			break;
	}

	fclose(fp);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int get_eng_short_textline(const char *Filename)
{
	FILE *fp;
	fp = fopen(Filename, "r");
	if (fp == NULL)
		return -1;

	char s[TEXTLEN];
	int count = 0;

	while (true)
	{
		if (fgets(s, TEXTLEN, fp) == NULL)  
			break;                            
		count++;
	}

	fclose(fp);
	return count;
}

bool read_eng_short_textfile()
{
	textlines = get_eng_short_textline(eng_short);
	int i;

	if (textlines < 1)
	{
		printf("����� ���� ���� ����\n");
		return main();
	}

	FILE *fp = fopen(eng_short, "r");
	texts = new char*[textlines]; 

	for (i = 0; i < textlines; i++)
	{
		texts[i] = new char[TEXTLEN];
		memset(texts[i], 0, TEXTLEN);
		if (fgets(texts[i], TEXTLEN, fp) == NULL) 
			break;
	}

	fclose(fp);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int get_eng_long_textline(const char *Filename)
{
	FILE *fp;
	fp = fopen(Filename, "r");
	if (fp == NULL)
		return -1;

	char s[TEXTLEN];
	int count = 0;

	while (true)
	{
		if (fgets(s, TEXTLEN, fp) == NULL)  
			break;                            
		count++;
	}

	fclose(fp);
	return count;
}

bool read_eng_long_textfile()
{
	textlines = get_eng_long_textline(eng_long);
	int i;

	if (textlines < 1)
	{
		printf("����Ӵ� ���� ���� ����\n");
		return main();
	}

	FILE *fp = fopen(eng_long, "r");
	texts = new char*[textlines]; 

	for (i = 0; i < textlines; i++)
	{
		texts[i] = new char[TEXTLEN];
		memset(texts[i], 0, TEXTLEN);
		if (fgets(texts[i], TEXTLEN, fp) == NULL) 
			break;
	}

	fclose(fp);
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void freetexts()
{
	if (texts == NULL)
		return;

  
	for (int i=0; i<textlines; i++)
	{
		if (texts[i]) 
		{
			delete [] texts[i];
			texts[i] = NULL;
		}
	}
  
	delete[] texts;

	texts = NULL;
	textlines = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int get_kor_text(char *s)
{
	gets(s);
	int len = (int) strlen(s);
	int e = 0;
	int k = 0;
	int i;

	for(i = 0; i < len; i++)
	{
		if (s[i] < 0) 
			k++;
		else 
			e++;
	}

	return e+(k / 2);
}

int get_eng_text(char *s)
{
	gets(s);
	int len = (int) strlen(s);
	int e = 0;
	int k = 0;
	int i;

	for (i = 0; i < len; i++)
	{
		if (s[i] < 0) 
			k++;
		else 
			e++;
	}

	return e+(k);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int get_rand(int low, int high)
{
	if (high < low)
	{
		int i = high;
		high = low;
		low = i;
	}
	return ((rand()%(high +1 - low)) + low);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int kor_sametext(char *s1, char *s2)
{
	int e = 0;
	int k = 0;
	int i;
	bool send = false;

	textcolor(CC_FONT_WHITE, 0);

	for (i=0; i<TEXTLEN; i++)
	{
		if ((s2[i] == '\0') || (s2[i] == '\n')) 
			send = true;

		if ((s1[i] == '\0') || (s1[i] == '\n')) 
			break;

		if ((s1[i] == s2[i]) && (send == false))
		{
			textcolor(CC_FONT_GREEN, 0);
			printf("%c", s1[i]);
		}

		else
		{
			if (s1[i] < 0) 
				k++;
			else 
				e++;

			textcolor(CC_FONT_RED, 0);
			printf("%c", s1[i]);
		}
	}

	printf("\n");
	return (e + (k / 2));
}

int eng_sametext(char *s1, char *s2)
{
	int e = 0;
	int k = 0;
	int i;
	bool send = false;

	textcolor(CC_FONT_WHITE, 0);

	for (i = 0; i < TEXTLEN; i++)
	{
		if ((s2[i] == '\0') || (s2[i] == '\n')) 
			send = true;

		if ((s1[i] == '\0') || (s1[i] == '\n')) 
			break;

		if ((s1[i] == s2[i]) && (send == false))
		{
			textcolor(CC_FONT_GREEN, 0);
			printf("%c", s1[i]);
		}
		else
		{
			if (s1[i] < 0) 
				k++;
			else 
				e++;

			textcolor(CC_FONT_RED, 0);
			printf("%c", s1[i]);
		}
	}

	printf("\n");
	return (e + k);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int kor_short_run()
{
	char user[TEXTLEN];
	drawmain();

	while (1)
	{
		int taja_count = 0;
		int taja_error = 0;
		unsigned int time = timeGetTime();
		int line = get_rand(0, textlines-1);
		

		Sleep(500);
		textcolor(CC_FONT_GREEN, 0);
		printf(" %s", texts[line]);

		textcolor(CC_FONT_WHITE, 0);
		printf(">");

		taja_count = get_kor_text(user);
		time = timeGetTime() - time;

		if (taja_count == 0)
			return main();

		textcolor(CC_FONT_WHITE, 0);
		printf(" ");
		taja_error = kor_sametext(texts[line], user);
	
		textcolor(CC_FONT_WHITE, 0);
		float t = (float)time / 1000;
		float n = 60 / t;
		int speed = (int)n * taja_count;
		printf("  -- [�Է� ���� : %2d] [��Ÿ : %2d] [�ɸ��ð� : %1.2fs] [�ѱۺд� : %2d��]\n\n", taja_count, taja_error, t, speed);
	}

	return 0;
}

int kor_long_run()
{
	char user[TEXTLEN];
	drawmain();

	while (1)
	{
		int taja_count = 0;
		int taja_error = 0;
		unsigned int time = timeGetTime();
		int line = get_rand(0, textlines-1);
		

		Sleep(500);
		textcolor(CC_FONT_GREEN, 0);
		printf(" %s", texts[line]);

		textcolor(CC_FONT_WHITE, 0);
		printf(">");

		taja_count = get_kor_text(user);
		time = timeGetTime() - time;

		if (taja_count == 0)
			return main();

		textcolor(CC_FONT_WHITE, 0);
		printf(" ");
		taja_error = kor_sametext(texts[line], user);

		textcolor(CC_FONT_WHITE, 0);
		float t = (float)time / 1000;
		float n = 60 / t;
		int speed = (int)n * taja_count;
		printf("  -- [�Է� ���� : %2d] [��Ÿ : %2d] [�ɸ��ð� : %1.2fs] [�ѱۺд� : %2d��]\n\n", taja_count, taja_error, t, speed);
	}
	return 0;

}

//////////////////////////////////////////////////////////////////////////////////////////////////

int eng_short_run()
{
	char user[TEXTLEN];
	drawmain();

	while (1)
	{
		int taja_count = 0;
		int taja_error = 0;
		unsigned int time = timeGetTime();
		int line = get_rand(0, textlines-1);

		Sleep(500);
		textcolor(CC_FONT_GREEN, 0);
		printf(" %s", texts[line]);      

		textcolor(CC_FONT_WHITE, 0);
		printf(">");

		taja_count = get_eng_text(user);
		time = timeGetTime() - time;

		if (taja_count == 0)
			return main();

		textcolor(CC_FONT_WHITE, 0);
		printf(" ");
		taja_error = eng_sametext(texts[line], user);
		
		textcolor(CC_FONT_WHITE, 0);
		float t = (float)time / 1000;
		float n = 60 / t;
		int speed = (int)n * taja_count;
		printf("  -- [�Է� ���� : %2d] [��Ÿ : %2d] [�ɸ��ð� : %1.2fs] [����д� : %2d��]\n\n", taja_count, taja_error, t, speed);
	}
	return 0;
}

int eng_long_run()
{
	char user[TEXTLEN];
	drawmain();

	while (1)
	{
		int taja_count = 0;
		int taja_error = 0;
		int line = get_rand(0, textlines-1);
		unsigned int time = timeGetTime();

		textcolor(CC_FONT_GREEN, 0);
		Sleep(500);
		printf(" %s", texts[line]);

		textcolor(CC_FONT_WHITE, 0);
		printf(">");

		taja_count = get_eng_text(user);
		time = timeGetTime() - time; 

		if (taja_count == 0)
			return main();

		textcolor(CC_FONT_WHITE, 0);
		printf(" ");
		taja_error = eng_sametext(texts[line], user);
	
		textcolor(CC_FONT_WHITE, 0);
		float t = (float)time / 1000;
		float n = 60 / t;
		int speed = (int)n * taja_count;
		printf("  -- [�Է� ���� : %2d] [��Ÿ : %2d] [�ɸ��ð� : %1.2fs] [����д� : %2d��]\n\n", taja_count, taja_error, t, speed);
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void kor_short_main()
{
	srand(timeGetTime());

	if(read_kor_short_textfile())
	{
		kor_short_run();
		freetexts();
	}
	else
	{
		puts("�����͸� �о���� ���Ͽ����ϴ�.");
	}

	puts("���α׷��� �����մϴ�. �����ϼ̽��ϴ�.~ [ENTER]");

	getchar();
}

void kor_long_main()
{
	srand(timeGetTime());

	if(read_kor_long_textfile())
	{
		kor_long_run();
		freetexts();
	}
	else
	{
		puts("�����͸� �о���� ���Ͽ����ϴ�.");
	}

	puts("���α׷��� �����մϴ�. �����ϼ̽��ϴ�.~ [ENTER]");

	getchar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void eng_short_main()
{
	srand(timeGetTime());

	if(read_eng_short_textfile())
	{
		eng_short_run();
		freetexts();
	}
	else
	{
		puts("�����͸� �о���� ���Ͽ����ϴ�.");
	}

	puts("���α׷��� �����մϴ�. �����ϼ̽��ϴ�.~ [ENTER]");

	getchar();
}

void eng_long_main()
{
	srand(timeGetTime());

	if(read_eng_long_textfile())
	{
		eng_long_run();
		freetexts();
	}
	else
	{
		puts("�����͸� �о���� ���Ͽ����ϴ�.");
	}

	puts("���α׷��� �����մϴ�. �����ϼ̽��ϴ�.~ [ENTER]");

	getchar();
}

/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////�ڿ�ĳ��////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////

void limit(char* s)
{
	int x = strlen(s);
	int i;

	for(i = 0; i < x; i++)
	{
		if(s[i] == '\n' || s[i] == '\r')
			s[i] = NULL;
	}
}

bool load_level(int lev)
{
	FILE *fp = fopen(level[lev-1], "r");
	int i, j;

	if (fp == NULL) 
	{
		return false;
	}

	char buff[256];

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(fgets(buff, 256, fp) == NULL)
			{
				fclose(fp);
				printf("level %d.txt�� �ܾ���� 25������ �մϴ�.", lev);
				return false;
			}

			data[i][j] = (char *)malloc(sizeof(char)* (strlen(buff)+1));
			strcpy(data[i][j], buff);
			limit(data[i][j]);
		}
	}

	fclose(fp);
	return true;
}

void check_text(char* w)
{
	int i, j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(strcmp(data[i][j], w) == false )
			{
				free(data[i][j]);
				data[i][j] = " ";
				point++;
				return;
			}
		}
	}
}

void Jawon_show()
{
	system("cls");
	int row;
	int col;
   
	char word[32];
	textcolor(CC_FONT_GREEN, 0);
	printf("%d �ܰ��Դϴ�.\n\n", lev);

	for(row = 0; row < 5; row++)
	{
		for(col = 0; col < 5; col++)
			printf("\t%s", data[row][col]);
		printf("\n");
	}

	textcolor(CC_FONT_YELLOW, 0);
	printf("\n�ܾ��Է�: ");
	scanf("%s", &word);

	check_text(word);
}

bool check_time()
{
	char buff[32];

	while(true)
	{
		printf("\n�ð��� ����Ǿ����ϴ�. �ٽ� �����Ͻðڽ��ϱ�? (��/�ƴϿ�)");
		scanf("%s", buff);
		
		if(strcmp(buff, "��") == false)
		{
			return true;
		}

		else if(strcmp(buff, "�ƴϿ�") == false)
		{
			exit(0);
		}

		else
		{
		  //pass
		}
	}
	return false;
}

int get_time()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	int h = st.wHour * 60 * 60;
	int m = st.wMinute * 60;
	int s = st.wSecond;

	return h + m + s;
} 


void resetGame()
{
	point = 0;
}

void get_Jawon()
{
	int totalLevel = (sizeof(level) / sizeof(char*));
	
    while(lev <= totalLevel)
    {
		resetGame();

		if(load_level(lev) == false )
		{
			printf("level %d.txt ������ �� �� �����ϴ�.", lev);
			system("pause");              //�ý��� ��� ����� ����
			exit(-1);
		}
		int start_time = get_time();

		while(point < 25)
		{
			Jawon_show();
			int elapsed = get_time() - start_time;

/////////////////////////////////////////////////////////////////
			if(elapsed > 50 && lev == 1)

			if(check_time())
				break;

/////////////////////////////////////////////////////////////////
			if(elapsed > 45 && lev == 2) 

			if(check_time()) 
				break; 

/////////////////////////////////////////////////////////////////
			if(elapsed > 40 && lev == 3) 

			if(check_time()) 
				break; 

/////////////////////////////////////////////////////////////////
			if(elapsed > 35 && lev == 4) 

			if(check_time()) 
				break; 

/////////////////////////////////////////////////////////////////
			if(elapsed > 30 && lev == 5)

			if(check_time())
				break;
		}

		if( point == 25 ) 
			lev++; 
	} 

	system("cls");
	printf("\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);	
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.");
	Sleep(500);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�����մϴ�. ��� ������ Ŭ�����Ͽ����ϴ�.\n");
	Sleep(500);
	system("pause");
}