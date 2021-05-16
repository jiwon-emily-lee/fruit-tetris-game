void story(void) {

    system("cls");
    int x = 5;
    int y = 4;
    int cnt;

    textcolor(7); //스토리
    gotoxy(x + 1, y + 2); printf("202X년 X월 X일…");
    Sleep(800);
    gotoxy(x + 1, y + 4); printf("일어나보니 나의 주식과 비트코인은 전부 휴지 조각이 되어 있었다…");
    Sleep(1800);
    gotoxy(x + 1, y + 6); printf("이렇게 된 이상 과일장수로 새 삶을 시작해보려 한다…!");
    Sleep(1800);

    textcolor(3); //게임 방법
    gotoxy(x + 1, y + 12); printf("---------------------------------------------");
    gotoxy(x + 8, y + 14); printf("< How to play >");
    gotoxy(x + 1, y + 16); printf("  △   : Rotate");
    gotoxy(x + 1, y + 17); printf("◁  ▷ : Left / Right");
    gotoxy(x + 1, y + 18); printf("  ▽   : Soft Drop");
    gotoxy(x + 12, y + 16); printf(" SPACE : Hard Drop");
    gotoxy(x + 12, y + 17); printf("   P   : Pause");
    gotoxy(x + 12, y + 18); printf("  ESC  : Quit");
    gotoxy(x + 1, y + 20); printf("---------------------------------------------");

    textcolor(7); //캐릭터 및 말풍선
    gotoxy(x + 40, y + 16); printf("○");
    gotoxy(x + 39, y + 18); printf(" ┌ ┐");
    for (cnt = 0;; cnt++) { //cnt를 1씩 증가시키면서 계속 반복   
        if (_kbhit()) break; //키입력이 있으면 무한루프 종료

        if (cnt % 200 == 0) {
            gotoxy(x + 39, y + 17); printf(" ┘|└");
        }
        gotoxy(x + 30, y + 17); printf("          ");
        if ((cnt % 200 - 100) == 0) {
            gotoxy(x + 39, y + 17); printf(" ＼|/");
        }
        Sleep(10);
    }
   
    while (_kbhit()) _getch();
}
