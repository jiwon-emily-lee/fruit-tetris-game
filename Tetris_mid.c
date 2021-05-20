#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //ȸ�� 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //�Ͻ����� 
#define P 80 //�Ͻ�����
#define ESC 27 //�������� 
#define ENTER 13 //����(����Ű)

#define false 0
#define true 1

#define ACTIVE_BLOCK -2 // �����ǹ迭�� ����� ������ ���µ� 
#define CEILLING -1     // ������ �̵��� �� �ִ� ������ 0 �Ǵ� ���� ������ ǥ�� 
#define EMPTY 0         // ������ �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1
#define INACTIVE_BLOCK 2 // �̵��� �Ϸ�� ���ϰ�
#define SBLOCK 3 //  ������ ����

#define MAIN_X 12 //������ ����ũ�� 
#define MAIN_Y 24 //������ ����ũ�� 
#define MAIN_X_ADJ 15 //������ ��ġ���� 
#define MAIN_Y_ADJ 1 //������ ��ġ���� 

#define DEFAULT_FONT_COLOR LIGHT_WHITE

#define BLACK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
#define NAVY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
#define BLUEGREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
#define ORANGE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
#define VIOLET SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
#define GOLD SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
#define ORIGINAL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
#define GRAY SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
#define YELLOWGREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
#define SKYBLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
#define PINK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

#define CIN GetStdHandle(STD_INPUT_HANDLE)
#define COUT GetStdHandle(STD_OUTPUT_HANDLE)

#define MapRow 23
#define MapCol 12
#define PORT 9000

#define STATUS_X_ADJ 2 //��������ǥ�� ��ġ���� 

int STATUS_Y_GOAL; //GOAL ����ǥ����ġY ��ǥ ���� 
int STATUS_Y_LEVEL; //LEVEL ����ǥ����ġY ��ǥ ����
int STATUS_Y_SCORE; //SCORE ����ǥ����ġY ��ǥ ����
int STATUS_Y_FRUIT; //���� ���� ����ǥ����ġY ��ǥ ����

int blocks[7][4][4][4] = {
{{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
 {0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}},
{{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0},
 {0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0}},
{{0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0},
 {0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0},{0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0}},
{{0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0}},
{{0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0},{0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0}},
{{0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
 {0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0},{0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0}}
}; //���ϸ�� ���� 4*4������ ������ ǥ�� blcoks[b_type][b_rotation][i][j]�� ��� 

int b_type; //���� ������ ���� 
int b_rotation; //���� ȸ���� ���� 
int b_type_next; //���� ���ϰ� ���� 
int randcolor = 7; //���� ���� ���� ����
int randcolor_next; //���� ���� ���� ����
int inactive_color = 7; //���� ���� ����
int y = 3;
int pay = 0;
int fruit1 = 0;
int fruit2 = 0;
int fruit3 = 0;
int fruit4 = 0;

int main_org[MAIN_Y][MAIN_X]; //�������� ������ �����ϴ� �迭 ����Ϳ� ǥ���Ŀ� main_cpy�� ����� 
int main_cpy[MAIN_Y][MAIN_X]; //�� maincpy�� �������� ����Ϳ� ǥ�õǱ� ���� ������ ������ ���� 
                              //main�� ��ü�� ��� ����Ϳ� ǥ������ �ʰ�(�̷��� �ϸ� ����Ͱ� �����Ÿ�) 
                              //main_cpy�� �迭�� ���ؼ� ���� �޶��� ���� ����Ϳ� ��ħ 
int bx, by; //�̵����� ������ �����ǻ��� x,y��ǥ�� ���� 

int key; //Ű����� �Է¹��� Ű���� ���� 

int speed; //��������ӵ� 
int level; //���� level 
int level_goal; //���������� �Ѿ�� ���� ��ǥ���� 
int cnt; //���� �������� ������ �� ���� ���� 
int score; //���� ���� 
int last_score = 0; //�������������� 
int best_score = 0; //�ְ��������� 

int new_block_on = 0; //���ο� ������ �ʿ����� �˸��� flag 
int crush_on = 0; //���� �̵����� ������ �浹�������� �˷��ִ� flag 
int level_up_on = 0; //���������� ����(���� ������ǥ�� �Ϸ�Ǿ�����) �˸��� flag 
int space_key_on = 0; //hard drop�������� �˷��ִ� flag 

void title(void); //���ӽ���ȭ�� 
void story(void);
void reset(void); //������ �ʱ�ȭ 
void reset_main(void); //���� ������(main_org[][]�� �ʱ�ȭ)
void reset_main_cpy(void); //copy ������(main_cpy[][]�� �ʱ�ȭ)
void draw_map(void); //���� ��ü �������̽��� ǥ�� 
void draw_main(void); //�������� �׸� 
void new_block(void); //���ο� ������ �ϳ� ���� 
void check_key(void); //Ű����� Ű�� �Է¹��� 
void drop_block(void); //������ �Ʒ��� ����Ʈ�� 
int check_crush(int bx, int by, int rotation); //bx, by��ġ�� rotationȸ������ ���� ��� �浹 �Ǵ� 
void move_block(int dir); //dir�������� ������ ������ 
void check_line(void); //���� ����á������ �Ǵ��ϰ� ���� 
void check_level_up(void); //������ǥ�� �޼��Ǿ������� �Ǵ��ϰ� levelup��Ŵ 
void check_game_over(void); //���ӿ������� �Ǵ��ϰ� ���ӿ����� ���� 
void pause(void);//������ �Ͻ�������Ŵ
void shadow_block(void);
void delete_sblock(void);
void score_window(void);//���� ��� â
void buy_fruit(void); // ���� ���� ���
void game_over(void); //**
void game_clear(void);
// void music(void);
INPUT_RECORD rec;
DWORD dwNOER;
POINT Point;
WSADATA Wsa;
SOCKET Server_Socket, Client_Socket, Other_Socket;
SOCKADDR_IN Server_Addr, Client_Addr;
int Client_Addr_Size;
volatile bool SendHappen = false, ReceiveHappen = false, GarbageHappen = false;
volatile bool Mouse_LeftButton = false, Multi = false;
volatile bool SaveHappen = false, LoadHappen = false, ResumeHappen = false, MenuHappen = false;
volatile bool EnterRoomHappen = false, ChangeHappen = false, ExitHappen = false;
volatile bool AcceptHappen = false, ErrorHappen = false, ListenHappen = false;
CONSOLE_CURSOR_INFO CursorInfo = { 1,false };
HANDLE MouseThread, TransmitThread, ClientThread, ServerThread, AcceptThread, MultiThread;
// void music(void);

/////////////////////////////////////////��������ȭ��//////////////////////////


/////////////////////////////////////////////////////////////


void gotoxy(int x, int y) { //gotoxy�Լ� 
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void textcolor(int color_number) //textcolor�Լ�=text ��������
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //Ŀ������� �Լ��� ���Ǵ� ������ 
void setcursortype(CURSOR_TYPE c) { //Ŀ������� �Լ� 
    CONSOLE_CURSOR_INFO CurInfo;

    switch (c) {
    case NOCURSOR:
        CurInfo.dwSize = 1;
        CurInfo.bVisible = FALSE;
        break;
    case SOLIDCURSOR:
        CurInfo.dwSize = 100;
        CurInfo.bVisible = TRUE;
        break;
    case NORMALCURSOR:
        CurInfo.dwSize = 20;
        CurInfo.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

/// ���� /////////////////////////////////////////////////////////////////////////////

int main() {
    int i;

    system("mode con:cols=100 lines=30"); //�ܼ�â ũ�� ���� //**
    srand((unsigned)time(NULL)); //����ǥ���� 
    setcursortype(NOCURSOR); //Ŀ�� ���� 
    title(); //����Ÿ��Ʋ ȣ�� 
    story();
    game_clear();
    reset(); //������ ���� 
    best_score = 0;
    //PlaySound(TEXT("tetris.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    while (1) {
        for (i = 0; i < 5; i++) { //������ ��ĭ�������µ��� 5�� Ű�Է¹��� �� ���� 
            check_key(); //Ű�Է�Ȯ�� 
            shadow_block();
            draw_main(); //ȭ���� �׸� 
            Sleep(speed); //���Ӽӵ�����
            delete_sblock();
            if (crush_on && check_crush(bx, by + 1, b_rotation) == false) Sleep(100);
            //������ �浹���ΰ�� �߰��� �̵��� ȸ���� �ð��� ���� 
            if (space_key_on == 1) { //�����̽��ٸ� �������(hard drop) �߰��� �̵��� ȸ���Ҽ� ���� break; 
                space_key_on = 0;
                break;
            }
        }
        drop_block(); // ������ ��ĭ ���� 
        check_level_up(); // �������� üũ 
        check_game_over(); //���ӿ����� üũ 
        if (new_block_on == 1) new_block(); // �� ���� flag�� �ִ� ��� ���ο� ���� ���� 
        
    }
    PlaySound(NULL, 0, 0);
}

/// Ÿ��Ʋ /////////////////////////////////////////////////////////////////////////////

void title(void) {
    int x = 5; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
    int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
    int cnt; //Ÿ��Ʋ �������� ���� ����  
    Mouse_LeftButton = false;
    setcursortype(NOCURSOR);

    SetConsoleTextAttribute(GetStdHandle(STD_INPUT_HANDLE), ENABLE_MOUSE_INPUT);
    system("mode con cols=100 lines=38 | title 5��)Fruit Tetris");

    int i, j;

    char* Menu[10][6] = {
    { "������� ", "������� "," ������� ","������    ",  "  ��� ",  "    �����" },
    { "������� ", "�������  ","������� ","���   ���   ",  "  ��� ",  "  ������" },
    { "    ���     ", "���         ","     ���     ","���    ���       ","","  ���" },
    { "    ���     ", "���   ","           ���     ","���   ���   ",  "  ��� ","  ���" },
    { "    ���     ", "�������     "," ���     ","������     ", " ��� "," ����� " },
    { "    ���     ", "�������   ","   ���     ","��� ���     ",  "  ��� ","   ����� " },
    { "    ���     ", "���         ","     ���     ","���   ���   ",  "  ��� ","        ���" },
    { "    ���     ", "���         ","     ���     ","���    ��� ",   "   ��� ","         ���" },
    { "    ���     ", "�������   ","   ���     ","���      ��� ", " ��� "," ������" },
    { "    ���     ", "������� ","     ���     ","���       ���", " ���","  �����" },
    };

    gotoxy(x + 12, y + 14); printf("�� Press any key to start ��");

    for (i = 0; i < 10; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 6; j++) {
            switch (j) {
            case 0:
                RED
                    break;
            case 1:
                ORANGE
                    break;
            case 2:
                YELLOW
                    break;
            case 3:
                GREEN
                    break;
            case 4:
                SKYBLUE
                    break;
            case 5:
                VIOLET
                    break;
            }
            printf("%s", Menu[i][j]);
        }
    }

    for (cnt = 0;; cnt++) { //cnt�� 1�� ������Ű�鼭 ��� �ݺ�   
        if (_kbhit()) break;//Ű�Է��� ������ ���ѷ��� ����
    }

    textcolor(7);
    while (_kbhit()) _getch(); //���ۿ� ��ϵ� Ű���� ���� 
}

////////////////////////�ߤ̰��� �κ�//////////////////////////////


/////////////////////////////////////////////////////////////////////////



/// Ŭ���� ///////////////////////////////////////////////////////////////////**

void game_clear(void) {

    system("cls");
    int x = 5;
    int y = 4;
    int cnt;

    textcolor(11);
    for (int j = 20; j >= 5; j--)
    {
        gotoxy(x + 25, y + j); printf(" | �� �� �� �� �� �� |");
        Sleep(50);
    }
    gotoxy(x + 30, y + 2); printf("|��"); //�ǹ�
    gotoxy(x + 30, y + 3); printf("|");
    gotoxy(x + 25, y + 4); printf("��������������������-���������������������� ");
    textcolor(7);
    gotoxy(x + 2, y + 1); printf("��������������������������������������������������������������������������");
    gotoxy(x + 2, y + 2); printf("                 ����                ");
    gotoxy(x + 2, y + 4); printf("               ��������");
    gotoxy(x + 2, y + 11); printf("��������������������������������������������������������������������������");

    for (cnt = 0;; cnt++) //cnt�� 1�� ������Ű�鼭 ��� �ݺ�   
    {
        if (_kbhit()) break; //Ű�Է��� ������ ���ѷ��� ����
        if (x != 18) { //��ȭ�� ���� ���
            x = cnt + 1;
            gotoxy(x + 8, y + 18); printf("   (^^)  ");
            gotoxy(x + 8, y + 19); printf(" �� ( (>  ");
            gotoxy(x + 8, y + 20); printf("   / ��  ");
            Sleep(300);
            gotoxy(x + 8, y + 19); printf("  <) )>  ");
            gotoxy(x + 8, y + 20); printf("   �� ��  ");
            Sleep(300);
            gotoxy(x + 8, y + 19); printf("  <) )��  ");
            Sleep(300);
        }
        else {
            gotoxy(x + 8, y + 18); printf("         ");
            gotoxy(x + 8, y + 19); printf("         ");
            gotoxy(x + 8, y + 20); printf("         ");
            Sleep(300);
            textcolor(14);
            gotoxy(x + 8, y + 18); printf("  $      ");
            Sleep(300);
            gotoxy(x + 8, y + 19); printf("      \\  ");
            textcolor(7);
            Sleep(300);
        }
    }

    while (_kbhit()) _getch();
}



/// ���丮 �� ��� ///////////////////////////////////////////////////////////////////

void story(void) {

    system("cls");
    int x = 5;
    int y = 4;
    int cnt;

    textcolor(7); //���丮
    gotoxy(x + 1, y + 2); printf("202X�� X�� X�ϡ�");
    Sleep(800);
    gotoxy(x + 1, y + 4); printf("�Ͼ���� ���� �ֽİ� ��Ʈ������ ���� ���� ������ �Ǿ� �־��١�");
    Sleep(1800);
    gotoxy(x + 1, y + 6); printf("�̷��� �� �̻� ��������� �� ���� �����غ��� �Ѵ١�!");
    Sleep(1800);

    textcolor(3); //���� ���
    gotoxy(x + 1, y + 12); printf("---------------------------------------------");
    gotoxy(x + 8, y + 14); printf("< How to play >");
    gotoxy(x + 1, y + 16); printf("  ��   : Rotate");
    gotoxy(x + 1, y + 17); printf("��  �� : Left / Right");
    gotoxy(x + 1, y + 18); printf("  ��   : Soft Drop");
    gotoxy(x + 12, y + 16); printf(" SPACE : Hard Drop");
    gotoxy(x + 12, y + 17); printf("   P   : Pause");
    gotoxy(x + 12, y + 18); printf("  ESC  : Quit");
    gotoxy(x + 1, y + 20); printf("---------------------------------------------");

    textcolor(7); //ĳ���� �� ��ǳ��
    gotoxy(x + 40, y + 16); printf("��");
    gotoxy(x + 39, y + 18); printf(" �� ��");
    for (cnt = 0;; cnt++) { //cnt�� 1�� ������Ű�鼭 ��� �ݺ�   
        if (_kbhit()) break; //Ű�Է��� ������ ���ѷ��� ����

        if (cnt % 200 == 0) {
            gotoxy(x + 39, y + 17); printf(" ��|��");
        }
        gotoxy(x + 30, y + 17); printf("               ");
        if ((cnt % 200 - 100) == 0) {
            gotoxy(x + 39, y + 17); printf(" ��|/");
        }
        Sleep(10);
    }
    
    while (_kbhit()) _getch();
}





/// �ʱ�ȭ /////////////////////////////////////////////////////////////////////////////

void reset(void) {

    FILE* file = fopen("score.dat", "rt"); // score.dat������ ���� 
    if (file == 0) { best_score = 0; } //������ ������ �� �ְ������� 0�� ���� 
    else {
        fscanf(file, "%d", &best_score); // ������ ������ �ְ������� �ҷ��� 
        fclose(file); //���� ���� 
    }

    level = 1; //�������� �ʱ�ȭ 
    score = 0;
    pay = -300;
    fruit1 = 0;
    fruit2 = 0;
    fruit3 = 0;
    fruit4 = -1;
    level_goal = 1000;
    key = 0;
    crush_on = 0;
    cnt = 0;
    speed = 100;

    system("cls"); //ȭ������ 
    reset_main(); // main_org�� �ʱ�ȭ 
    draw_map(); // ����ȭ���� �׸�
    draw_main(); // �������� �׸� 
    
    b_type_next = rand() % 7; //�������� ���� ���� ������ �����ϰ� ���� 
    new_block(); //���ο� ������ �ϳ� ����  
    randcolor = rand() % (4 + 1 - 1) + 1; //���� ���� ���� ���� 1-4
    buy_fruit();
    


}

void reset_main(void) { //�������� �ʱ�ȭ  
    int i, j;

    for (i = 0; i < MAIN_Y; i++) { // �������� 0���� �ʱ�ȭ  
        for (j = 0; j < MAIN_X; j++) {
            main_org[i][j] = 0;
            main_cpy[i][j] = 100;
        }
    }
    for (j = 1; j < MAIN_X; j++) { //y���� 3�� ��ġ�� õ���� ���� 
        main_org[3][j] = CEILLING;
    }
    for (i = 1; i < MAIN_Y - 1; i++) { //�¿� ���� ����  
        main_org[i][0] = WALL;
        main_org[i][MAIN_X - 1] = WALL;
    }
    for (j = 0; j < MAIN_X; j++) { //�ٴں��� ���� 
        main_org[MAIN_Y - 1][j] = WALL;
    }
}

void reset_main_cpy(void) { //main_cpy�� �ʱ�ȭ 
    int i, j;

    for (i = 0; i < MAIN_Y; i++) {         //�����ǿ� ���ӿ� ������ �ʴ� ���ڸ� ���� 
        for (j = 0; j < MAIN_X; j++) {  //�̴� main_org�� ���� ���ڰ� ���� �ϱ� ���� 
            main_cpy[i][j] = 100;
        }
    }
}

void draw_map(void) { //���� ���� ǥ�ø� ��Ÿ���� �Լ�  
    int y = 3;             // level, goal, score�� �����߿� ���� �ٲ�� �� ���� �� y���� ���� �����ص� 
                         // �׷��� Ȥ�� ���� ���� ǥ�� ��ġ�� �ٲ� �� �Լ����� �ȹٲ㵵 �ǰ�.. 
    gotoxy(STATUS_X_ADJ, y); printf("---------------------");
    gotoxy(STATUS_X_ADJ, STATUS_Y_LEVEL = y + 2); printf("     LEVEL %5d", level);
    gotoxy(STATUS_X_ADJ, y + 4); printf("---------------------");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 2); printf("��   N E X T �� ");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 3); printf("              ");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 4); printf("              ");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 5); printf("              ");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 6); printf("              ");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 7); printf("��           �� ");
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_SCORE = y + 10); printf("[   ���� ����    ] %6d", score);
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 12); printf("[   ���� ����    ] %6d", pay); //���� ǥ��
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT=y + 14); printf("[ ������ ���� �� ] %6d", fruit1); //���� ���� 100��
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT+2); printf("[ ������ Ű�� �� ] %6d", fruit2); // Ű�� ���� 200��
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT+4); printf("[ ������ �޷� �� ] %6d", fruit3); //�޷� ���� 500��
    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT+6); printf("[ ������ ���� �� ] %6d", fruit4); // ���� ���� 300��
    gotoxy(STATUS_X_ADJ, y + 9); printf("---------------------");
    gotoxy(STATUS_X_ADJ, y + 11); printf("  ��   :      Rotate");
    gotoxy(STATUS_X_ADJ, y + 12); printf("��  �� : Left / Right");
    gotoxy(STATUS_X_ADJ, y + 13); printf("  ��   :   Soft Drop");
    gotoxy(STATUS_X_ADJ, y + 15); printf(" SPACE :   Hard Drop");
    gotoxy(STATUS_X_ADJ, y + 17); printf("   P   :       Pause");
    gotoxy(STATUS_X_ADJ, y + 19); printf("  ESC  :        Quit");
    gotoxy(STATUS_X_ADJ, y + 21); printf("---------------------");
}

void draw_main(void) { //������ �׸��� �Լ� 
    int i, j;

    for (j = 1; j < MAIN_X - 1; j++) { //õ���� ��� ���ο������ �������� �������� ���� �׷��� 
        if (main_org[3][j] == EMPTY) main_org[3][j] = CEILLING;
    }
    for (i = 0; i < MAIN_Y; i++) {
        for (j = 0; j < MAIN_X; j++) {
            if (main_cpy[i][j] != main_org[i][j]) { //cpy�� ���ؼ� ���� �޶��� �κи� ���� �׷���.
                                                //�̰� ������ ��������ü�� ��� �׷��� �������� ��¦�Ÿ�
                gotoxy(MAIN_X_ADJ + j, MAIN_Y_ADJ + i);
                switch (main_org[i][j]) {
                case EMPTY: //��ĭ��� 
                    printf("  ");
                    break;
                case CEILLING: //õ���� 
                    printf(". ");
                    break;
                case WALL: //����� 
                    printf("��");
                    break;
                case INACTIVE_BLOCK: //���� ���� ���  
                    textcolor(inactive_color);
                    printf("��");
                    textcolor(7);
                    break;
                case ACTIVE_BLOCK: //�����̰��ִ� ���� ���  
                    textcolor(randcolor);
                    printf("��");
                    textcolor(7);
                    break;
                case SBLOCK:
                    textcolor(randcolor);
                    printf("��");
                    textcolor(7);
                }
            }
        }
    }
    for (i = 0; i < MAIN_Y; i++) { //�������� �׸� �� main_cpy�� ����  
        for (j = 0; j < MAIN_X; j++) {
            main_cpy[i][j] = main_org[i][j];
        }
    }
}

/// ���� /////////////////////////////////////////////////////////////////////////////

void new_block(void) { //���ο� ���� ����  
    int i, j;

    bx = (MAIN_X / 2) - 1; //���� ���� ��ġx��ǥ(�������� ���) 
    by = 0;  //���� ������ġ y��ǥ(���� ��) 
    b_type = b_type_next; //������������ ������ 
    b_type_next = rand() % 7; //���� ������ ���� 
    inactive_color = randcolor;//���� ���� ����
    randcolor = randcolor_next; //�����̴� ���� ����
    randcolor_next = rand() % (4 + 1 - 1) + 1; //���� ���� ����
    b_rotation = 0;  //ȸ���� 0������ ������ 

    new_block_on = 0; //new_block flag�� ��  
    buy_fruit(); 
    for (i = 0; i < 4; i++) { //������ bx, by��ġ�� ��������  
        for (j = 0; j < 4; j++) {
            if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
        }
    }


    for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú����� �׸� 
        for (j = 0; j < 4; j++) {
            if (blocks[b_type_next][0][i][j] == 1) {
                gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ + 2 + j, i + 6);
                textcolor(randcolor_next);
                printf("��");
                textcolor(7);
            }
            else {
                gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ + 2 + j, i + 6);
                printf("  ");
            }
        }
    }
    textcolor(7);
}

void check_key(void) {
    key = 0; //Ű�� �ʱ�ȭ  

    if (_kbhit()) { //Ű�Է��� �ִ� ���  
        key = _getch(); //Ű���� ����
        if (key == 224) { //����Ű�ΰ�� 
            do { key = _getch(); } while (key == 224);//����Ű���ð��� ���� 
            switch (key) {
            case LEFT: //����Ű ��������  
                if (check_crush(bx - 1, by, b_rotation) == true) move_block(LEFT);
                break;                            //�������� �� �� �ִ��� üũ �� �����ϸ� �̵�
            case RIGHT: //������ ����Ű ��������- ���� �����ϰ� ó���� 
                if (check_crush(bx + 1, by, b_rotation) == true) move_block(RIGHT);
                break;
            case DOWN: //�Ʒ��� ����Ű ��������-���� �����ϰ� ó���� 
                if (check_crush(bx, by + 1, b_rotation) == true) move_block(DOWN);
                break;
            case UP: //���� ����Ű �������� 
                if (check_crush(bx, by, (b_rotation + 1) % 4) == true) move_block(UP);
                //ȸ���� �� �ִ��� üũ �� �����ϸ� ȸ��
                else if (crush_on == 1 && check_crush(bx, by - 1, (b_rotation + 1) % 4) == true) move_block(100);
            }                    //�ٴڿ� ���� ��� �������� ��ĭ����� ȸ���� �����ϸ� �׷��� ��(Ư������)
        }
        else { //����Ű�� �ƴѰ�� 
            switch (key) {
            case SPACE: //�����̽�Ű �������� 
                space_key_on = 1; //�����̽�Ű flag�� ��� 
                while (crush_on == 0) { //�ٴڿ� ���������� �̵���Ŵ 
                    drop_block();
                    gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_SCORE = y + 10); printf("[   ���� ����    ] %6d", score); //���� ǥ��  
                }
                break;
            case P: //P(�빮��) �������� 
            case p: //p(�ҹ���) �������� 
                pause(); //�Ͻ����� 
                break;
            case ESC: //ESC�������� 
                system("cls"); //ȭ���� ����� 
                exit(0); //�������� 

            }
        }
    }
    while (_kbhit()) _getch(); //Ű���۸� ��� 
}

void drop_block(void) {
    int i, j;

    if (crush_on && check_crush(bx, by + 1, b_rotation) == true) crush_on = 0; //���� ��������� crush flag �� 
    if (crush_on && check_crush(bx, by + 1, b_rotation) == false) { //���� ��������ʰ� crush flag�� ���������� 
        for (i = 0; i < MAIN_Y; i++) { //���� �������� ������ ���� 
            for (j = 0; j < MAIN_X; j++) {
                if (main_org[i][j] == ACTIVE_BLOCK)
                {
                    main_org[i][j] = INACTIVE_BLOCK;
                }
            }
        }
        crush_on = 0; //flag�� �� 
        check_line(); //����üũ�� �� 
        new_block_on = 1; //���ο� �������� flag�� ��    
        return; //�Լ� ���� 
    }
    if (check_crush(bx, by + 1, b_rotation) == true) move_block(DOWN); //���� ��������� ������ ��ĭ �̵� 
    if (check_crush(bx, by + 1, b_rotation) == false) crush_on++; //������ �̵��� �ȵǸ�  crush flag�� ��
}

int check_crush(int bx, int by, int b_rotation) { //������ ��ǥ�� ȸ�������� �浹�� �ִ��� �˻� 
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) { //������ ��ġ�� �����ǰ� ��������� ���ؼ� ��ġ�� false�� ���� 
            if (blocks[b_type][b_rotation][i][j] == 1 && main_org[by + i][bx + j] > 0) return false;
        }
    }
    return true; //�ϳ��� �Ȱ�ġ�� true���� 
};

void move_block(int dir) { //������ �̵���Ŵ 
    int i, j;

    switch (dir) {
    case LEFT: //���ʹ��� 
        for (i = 0; i < 4; i++) { //������ǥ�� ������ ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) { //�������� ��ĭ���� active block�� ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j - 1] = ACTIVE_BLOCK;
            }
        }
        bx--; //��ǥ�� �̵� 
        break;

    case RIGHT:    //������ ����. ���ʹ����̶� ���� ������ ���� 
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j + 1] = ACTIVE_BLOCK;
            }
        }
        bx++;
        break;

    case DOWN:    //�Ʒ��� ����. ���ʹ����̶� ���� ������ ����
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i + 1][bx + j] = ACTIVE_BLOCK;
            }
        }
        by++;
        break;

    case UP: //Ű���� ���� �������� ȸ����Ŵ. 
        for (i = 0; i < 4; i++) { //������ǥ�� ������ ����  
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        b_rotation = (b_rotation + 1) % 4; //ȸ������ 1������Ŵ(3���� 4�� �Ǵ� ���� 0���� �ǵ���) 
        for (i = 0; i < 4; i++) { //ȸ���� ������ ���� 
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = ACTIVE_BLOCK;
            }
        }
        break;

    case 100: //������ �ٴ�, Ȥ�� �ٸ� ���ϰ� ���� ���¿��� ��ĭ���� �÷� ȸ���� ������ ��� 
              //�̸� ���۽�Ű�� Ư������ 
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i][bx + j] = EMPTY;
            }
        }
        b_rotation = (b_rotation + 1) % 4;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (blocks[b_type][b_rotation][i][j] == 1) main_org[by + i - 1][bx + j] = ACTIVE_BLOCK;
            }
        }
        by--;
        break;
    }
}

/// ���� /////////////////////////////////////////////////////////////////////////////

void check_line(void) {
    int i, j, k, l;
    int block_amount; //������ ���ϰ����� �����ϴ� ���� 
    int combo = 0; //�޺����� �����ϴ� ���� ������ �ʱ�ȭ 

    for (i = MAIN_Y - 2; i > 3;) { //i=MAIN_Y-2 : ���ʺ��� ��ĭ����,  i>3 : õ��(3)�Ʒ����� �˻� 
        block_amount = 0; //���ϰ��� ���� ���� �ʱ�ȭ 
        for (j = 1; j < MAIN_X - 1; j++) { //���� �������� ���ϰ��縦 �� 
            if (main_org[i][j] > 0) {
                block_amount++;
                
            }
        }
        if (block_amount == MAIN_X - 2) { //������ ���� �� ��� 
            if (level_up_on == 0) { //���������°� �ƴ� ��쿡(�������� �Ǹ� �ڵ� �ٻ����� ����) 
                score += 1000 * level; //�����߰� 
                gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_SCORE = y + 10); printf("[   ���� ����    ] %6d", score); //���� ǥ��
                cnt++; //���� �� ���� ī��Ʈ ���� 
                combo++; //�޺��� ����  
            }
            for (k = i; k > 1; k--) { //������ ��ĭ�� ��� ����(������ õ���� �ƴ� ��쿡��) 
                for (l = 1; l < MAIN_X - 1; l++) {
                    if (main_org[k - 1][l] != CEILLING) main_org[k][l] = main_org[k - 1][l];
                    if (main_org[k - 1][l] == CEILLING) main_org[k][l] = EMPTY;
                    //������ õ���� ��쿡�� õ���� ��ĭ ������ �ȵǴϱ� ��ĭ�� ���� 
                }
            }
        }
        else i--;
    }
    if (combo) { //�� ������ �ִ� ��� ������ ���� ��ǥ�� ���� ǥ����  
        if (combo > 1) { //2�޺��̻��� ��� ��� ���ʽ��� �޼����� �����ǿ� ����ٰ� ���� 
            gotoxy(MAIN_X_ADJ + (MAIN_X / 2) - 1, MAIN_Y_ADJ + by - 2); printf("%d COMBO!", combo);
            Sleep(500);
            score += (combo * level * 1000);
            gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_SCORE = y + 10); printf("[   ���� ����    ] %6d", score); //���� ǥ��
            reset_main_cpy(); //�ؽ�Ʈ�� ����� ���� main_cpy�� �ʱ�ȭ.
//(main_cpy�� main_org�� ���� �ٸ��Ƿ� ������ draw()ȣ��� ������ ��ü�� ���� �׸��� ��) 
        }
        //gotoxy(STATUS_X_ADJ, STATUS_Y_GOAL); printf(" GOAL  : %5d", (cnt <= 10) ? 10 - cnt : 0);
        //gotoxy(STATUS_X_ADJ, STATUS_Y_SCORE); printf("        %6d", score);
    }
}

void check_level_up(void) {
    int i, j;

    if (cnt >= 10) { //�������� 10�پ� ���־���. 10���̻� ���� ��� 
        draw_main();
        level_up_on = 1; //������ flag�� ��� 
        level += 1; //������ 1 �ø� 
        cnt = 0; //���� �ټ� �ʱ�ȭ   

        for (i = 0; i < 4; i++) {
            gotoxy(MAIN_X_ADJ + (MAIN_X / 2) - 3, MAIN_Y_ADJ + 4);
            printf("             ");
            gotoxy(MAIN_X_ADJ + (MAIN_X / 2) - 2, MAIN_Y_ADJ + 6);
            printf("             ");
            Sleep(200);

            gotoxy(MAIN_X_ADJ + (MAIN_X / 2) - 3, MAIN_Y_ADJ + 4);
            printf("��LEVEL UP!��");
            gotoxy(MAIN_X_ADJ + (MAIN_X / 2) - 2, MAIN_Y_ADJ + 6);
            printf("��SPEED UP!��");
            Sleep(200);
        }
        reset_main_cpy(); //�ؽ�Ʈ�� ����� ���� main_cpy�� �ʱ�ȭ.
//(main_cpy�� main_org�� ���� �ٸ��Ƿ� ������ draw()ȣ��� ������ ��ü�� ���� �׸��� ��) 

        for (i = MAIN_Y - 2; i > MAIN_Y - 2 - (level - 1); i--) { //�������������� �� ����-1�� ����ŭ �Ʒ��� ���� ������ 
            for (j = 1; j < MAIN_X - 1; j++) {
                main_org[i][j] = INACTIVE_BLOCK; // ���� �������� ��� ä��� 
                gotoxy(MAIN_X_ADJ + j, MAIN_Y_ADJ + i); // ���� �����.. �̻����̰� 
                printf("��");
                Sleep(20);
            }
        }
        Sleep(100); //�������� �����ֱ� ���� delay 
        check_line(); //�������� ��� ä��� �����
//.check_line()�Լ� ���ο��� level up flag�� �����ִ� ��� ������ ����.         
        switch (level) { //�������� �ӵ��� ��������. 
        case 2:
            speed = 50;
            break;
        case 3:
            speed = 25;
            break;
        case 4:
            speed = 10;
            break;
        case 5:
            speed = 5;
            break;
        case 6:
            speed = 4;
            break;
        case 7:
            speed = 3;
            break;
        case 8:
            speed = 2;
            break;
        case 9:
            speed = 1;
            break;
        case 10:
            speed = 0;
            break;
        }
        level_up_on = 0; //������ flag����

        gotoxy(STATUS_X_ADJ, STATUS_Y_LEVEL); printf("     LEVEL %5d", level); //����ǥ�� 
        //gotoxy(STATUS_X_ADJ, STATUS_Y_GOAL); printf(" GOAL  : %5d", 10 - cnt); // ������ǥ ǥ�� 

    }
}




void check_game_over(void) { //**
    int i;

    int x = 5;
    int y = 5;

    for (i = 1; i < MAIN_X - 2; i++) {
        if (main_org[3][i] > 0) { //õ��(������ ����° ��)�� inactive�� �����Ǹ� ���� ����
            //PlaySound(NULL, 0, 0);
            //PlaySound(TEXT("over.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            for (int j = 1; j < MAIN_Y - 1; j++)
            {
                gotoxy(MAIN_X_ADJ + 1, j + MAIN_Y_ADJ); printf("�ǢǢǢǢǢǢǢǢǢ�");
                Sleep(30);
            }
            game_over();
            system("cls");
            score_window();
            while (_kbhit()) _getch();
            key = _getch();
            reset();
            //PlaySound(NULL, 0, 0);
            //PlaySound(TEXT("tetris.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            //PlaySound(NULL, 0, 0);
            //PlaySound(TEXT("tetris.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
    }
}

void pause(void) { //���� �Ͻ����� �Լ� 
    int i, j;

    int x = 14;
    int y = 9;
    PlaySound(NULL, 0, 0);
    for (i = 1; i < MAIN_X - 2; i++) { //���� �Ͻ����� �޼��� 
        gotoxy(x, y + 0); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
        gotoxy(x, y + 1); printf("                               ");
        gotoxy(x, y + 2); printf(" ��                       ��   ");
        gotoxy(x, y + 3); printf("         P A U S E           ");
        gotoxy(x, y + 4); printf(" ��                       ��   ");
        gotoxy(x, y + 5); printf("  Press any key to resume    ");
        gotoxy(x, y + 6); printf("                               ");
        gotoxy(x, y + 7); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
    }
    _getch(); //Ű�Է½ñ��� ��� 

    system("cls"); //ȭ�� ����� ���� �׸� 
    //PlaySound(TEXT("tetris.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    reset_main_cpy();
    draw_main();
    draw_map();
    
    for (i = 1; i < 3; i++) { //���ӻ���ǥ�ÿ� ������ ���ú����� �׸� 
        for (j = 0; j < 4; j++) {
            if (blocks[b_type_next][0][i][j] == 1) {
                gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ + 2 + j, i + 6);
                textcolor(randcolor_next);
                printf("��");
                textcolor(7);
            }
            else {
                gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ + 2 + j, i + 6);
                printf("  ");
            }
        }
    }
    if (randcolor == 1) {
        fruit1--;
        pay -= 100;
    }
    else if (randcolor == 2) {
        fruit2--;
        pay -= 200;
    }
    else if (randcolor == 3) {
        fruit3--;  
        pay -= 500;    
    }
    else {
        fruit4--;       
        pay -= 300;    
    }
    buy_fruit();

}

void game_over(void) {

    system("cls");
    int x = 5;
    int y = 4;
    int cnt;

    textcolor(12); //���ӿ��� ȭ��
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 3);  printf("  ����       ��     ��     ��  �����");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 4);  printf("��           ��  ��   ��� ���  �����");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 5); printf("��     ��   �����  ��  �� ��  ��   ");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 6); printf("  ����    ��    ��  ��     ��  �����");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 8); printf("  ����    ��    ��  �����   ����");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 9); printf("��      ��  ��    ��  �����   ��    ��");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 10); printf("��      ��   ��  ��   ��         ����");
    gotoxy(MAIN_X_ADJ - 1, MAIN_Y_ADJ + 11); printf("  ����       ��     �����   ��    ��");

    textcolor(7); //���ӿ��� ���丮
    gotoxy(MAIN_X_ADJ + 4, MAIN_Y_ADJ + 19); printf("��������������������������������������");
    gotoxy(MAIN_X_ADJ + 5, MAIN_Y_ADJ + 20); printf("���� ��: %d      ", score);
    gotoxy(MAIN_X_ADJ + 4, MAIN_Y_ADJ + 21); printf("��������������������������������������");
    gotoxy(MAIN_X_ADJ + 6, MAIN_Y_ADJ + 22); printf("|| ");
    gotoxy(MAIN_X_ADJ + 6, MAIN_Y_ADJ + 23); printf("|| ");
    if (score < 500)
    {
        gotoxy(MAIN_X_ADJ + 6, MAIN_Y_ADJ + 24); printf("|| OTL");
        Sleep(1000);
        gotoxy(MAIN_X_ADJ + 10, MAIN_Y_ADJ + 23); printf(".(( �� ������ ���ڶ� ))");
    }
    else if (score > 500 && score < 1000)
    {
        gotoxy(MAIN_X_ADJ + 6, MAIN_Y_ADJ + 24); printf("|| ��");
        Sleep(1000);
        gotoxy(MAIN_X_ADJ + 10, MAIN_Y_ADJ + 23); printf(".(( ���� ������ ))");
    }
    else
    {
        gotoxy(MAIN_X_ADJ + 6, MAIN_Y_ADJ + 24); printf("|| ��");
        Sleep(1000);
        gotoxy(MAIN_X_ADJ + 10, MAIN_Y_ADJ + 23); printf(".(( ���ݸ� ��!! ))");
    }
}


void shadow_block(void) // ������ ����
{
    int shadowY = 0;
    while (1)
    {
        if (check_crush(bx, shadowY + 1, b_rotation) == true)
            ++shadowY;
        if (by >= shadowY)
            ++shadowY;
        if (check_crush(bx, shadowY + 1, b_rotation) == false)
        {
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 4; x++)
                {
                    if (blocks[b_type][b_rotation][y][x] == 1
                        && main_org[y + shadowY][bx + x] == 0)
                        main_org[y + shadowY][bx + x] = SBLOCK;
                }
            }
            shadowY = 0;
            break;
        }
    }
    return;
}

void delete_sblock(void)
{
    for (int i = 0; i < MAIN_Y - 1; i++) { //delete
        for (int j = 0; j < MAIN_X - 1; j++) {
            if (main_org[i][j] == SBLOCK)
            {
                main_org[i][j] = EMPTY;
            }
        }
    }
    return;
}

void score_window(void)
{
    int y = 3;
    int final_score = 0;
    final_score = score - pay;
    gotoxy(MAIN_X_ADJ + 1, MAIN_Y_ADJ + 11); printf("[   ���� �� ��    ] %6d��", score);
    
    gotoxy(MAIN_X_ADJ + 1, MAIN_Y_ADJ + 12); printf("[    ���� ����    ] %6d", pay);
    gotoxy(MAIN_X_ADJ + 1, MAIN_Y_ADJ + 13); printf("[      ������     ] %6d", final_score);
    gotoxy(MAIN_X_ADJ + 1, MAIN_Y_ADJ + 14); printf("    Press any key   ");
    gotoxy(MAIN_X_ADJ + 1, MAIN_Y_ADJ + 15); printf("    to restart..    ");
    gotoxy(MAIN_X_ADJ + 1, MAIN_Y_ADJ + 16); printf("                    ");
}

void buy_fruit(void)
{
    if (randcolor == 1) {
        fruit1++;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT); printf("[ ������ ���� �� ] %6d", fruit1);
        pay += 100;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 12); printf("[   ���� ����    ] %6d", pay);

    }
    else if (randcolor == 2) {
        fruit2++;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT+2); printf("[ ������ Ű�� �� ] %6d", fruit2);
        pay += 200;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 12); printf("[   ���� ����    ] %6d", pay);
    }
    else if (randcolor == 3) {
        fruit3++;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT+4); printf("[ ������ �޷� �� ] %6d", fruit3);
        pay += 500;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 12); printf("[   ���� ����    ] %6d", pay);
    }
    else {
        fruit4++;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, STATUS_Y_FRUIT+6); printf("[ ������ ���� �� ] %6d", fruit4);
        pay += 300;
        gotoxy(STATUS_X_ADJ + MAIN_X + MAIN_X_ADJ, y + 12); printf("[   ���� ����    ] %6d", pay);
    }
}