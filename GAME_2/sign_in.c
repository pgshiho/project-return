#include "superclass.h"
#include "db_event.h"

#pragma comment (lib,"libmariadb.lib")

void sign_in(void) {
	char query[255];
	while (true) {
		char id[30], password[30], password_confirm[30];
		MYSQL db_key;
		while (true) {
			ASCII_Art_print();
			mysql_init(&db_key);
			gotoxy(42, 15);
			printf("Sing up\n");
			if (!mysql_real_connect(&db_key, "localhost", "root", "123456", "gwangju_sword_master", 0, NULL, 0)) {
				gotoxy(42, 12);
				db_connect_error(&db_key);
				exit(0);
			}
			gotoxy(40, 16);
			printf("ID:");
			gotoxy(34, 18);
			printf("Password:");
			gotoxy(35, 20);
			printf("Confirm:");
			gotoxy(43, 16);
			CursorView(1);
			scanf_s(" %[^\n]", id, sizeof(char) * 30);
			gotoxy(43, 18);
			scanf_s(" %[^\n]", password, sizeof(char) * 30);
			gotoxy(43, 20);
			scanf_s(" %[^\n]", password_confirm, sizeof(char) * 30);
			if (strcmp(password, password_confirm) == 0) {
				break;
			}
			sprintf(query, "SELECT id FROM gwangju_sword_master.account WHERE id = '%s'", id);
			if (mysql_query(&db_key, query)) {
				fprintf(stderr,"Duplicate ID verification failed: %s\n",mysql_error(&db_key));
				Sleep(3000);
				exit(0);
			}
			MYSQL_RES* result = mysql_store_result(&db_key);
			MYSQL_ROW row = mysql_fetch_row(result);
			if (row == id) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				system("cls");
				gotoxy(42, 15);
				CursorView(0);
				printf("Sing in\n");
				gotoxy(43, 17);
				printf("�̹� �����ϴ� ���̵�(ID) �Դϴ�");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				Sleep(3000);
				mysql_close(&db_key);
				system("cls");
				continue;
			}
			else {
				system("cls");
				continue;
			}
		}
		for (int i = 0; i < 255; i++) {
			query[i] = NULL;
		}
		sprintf(query, "INSERT INTO gwangju_sword_master.account(id, password) VALUES('%s', '%s')", id, password);
		if (mysql_query(&db_key, query)) {
			fprintf(stderr, "Query execution failed: %s\n", mysql_error(&db_key));
			Sleep(3000);
			exit(0);
		}
		sign_up();
	}
}