#include "superclass.h"

void new_game_reconfirm(void) {
    system("cls");
    MYSQL db;
    mysql_init(&db);
    if (!mysql_real_connect(&db, "localhost", "root", "123456", "gwangju_sword_master", 0, NULL, 0)) {
        gotoxy(42, 12);
        db_connect_error(&db);
        exit(0);
    }
    gotoxy(42, 12); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("���� ������ ���� �����Ͻðڽ��ϱ�?");
    gotoxy(39, 13);
    printf("[������ ���̺������� �ִٸ� �����˴ϴ�]");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void gender_select(void) {

}
void prologue(void) {
    char** p = (char**)malloc(sizeof(char*));
    *p = "�ȳ��ϼ���";
    for (int i = 0; i < 5; i++) {
        printf("%c", *(*p + i));
    }
    printf("\n");
    free(p);
}