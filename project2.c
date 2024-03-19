#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(); //게임 메뉴 출력
void player1(); //Player1 vs Computer
void player2(); //Player1 vs Player2
void init_board(void); //board 초기화
void print_board(); //board 출력
int win(int player); //승패 판단

int board[3][3]={ {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
int x, y;
int true = 1;
int cnt;

int win(int player) {
	for (x = 0; x < 3; x++) {
		if (board[x][0] != ' ' && board[x][0] == board[x][1] && board[x][1] == board[x][2]) { //가로
			switch (player) {
			case 1:
				printf(" Player1 win!\n");
				break;
			case 2:
				printf(" Computer win!\n");
				break;
			case 3:
				printf(" Player2 win!\n");
				break;
			}
			return true;
		}
	}
	for (y = 0; y < 3; y++) {
		if (board[0][y] != ' ' && board[0][y] == board[1][y] && board[1][y] == board[2][y]) { //세로
			switch (player) {
			case 1:
				printf(" Player1 win!\n");
				break;
			case 2:
				printf(" Computer win!\n");
				break;
			case 3:
				printf(" Player2 win!\n");
				break;
			}
			return true;
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) { //대각선
		switch (player) {
		case 1:
			printf(" Player1 win!\n");
			break;
		case 2:
			printf(" Computer win!\n");
			break;
		case 3:
			printf(" Player2 win!\n");
			break;
		}
		return true;
	}
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) { //대각선
		switch (player) {
		case 1:
			printf(" Player1 win!\n");
			break;
		case 2:
			printf(" Computer win!\n");
			break;
		case 3:
			printf(" Player2 win!\n");
			break;
		}
		return true;
	}
	if (cnt == 9) {
		printf(" draw!\n");
		return true;
	}
	if (cnt == 8) {
		for (x = 0; x < 3; x++) {
			for (y = 0; y < 3; y++) {
					if (((board[x][0] == 'X' && board[x][1] == 'O') || //가로
						(board[x][0] == 'X' && board[x][2] == 'O') ||
						(board[x][1] == 'X' && board[x][0] == 'O') ||
						(board[x][1] == 'X' && board[x][2] == 'O') ||
						(board[x][2] == 'X' && board[x][0] == 'O') ||
						(board[x][2] == 'X' && board[x][1] == 'O')) && 
						((board[0][y] == 'X' && board[1][y] == 'O') || //세로
						(board[0][y] == 'X' && board[2][y] == 'O') ||
						(board[1][y] == 'X' && board[0][y] == 'O') ||
						(board[1][y] == 'X' && board[2][y] == 'O') ||
						(board[2][y] == 'X' && board[0][y] == 'O') ||
						(board[2][y] == 'X' && board[1][y] == 'O'))) { 
						printf(" draw! \n");
					}
					return true;
			}
		}
	}
}
int menu() { 
	int choice;
	printf("\n ------------------------\n");
	printf("     tic-tac-toe game    ");
	printf("\n ------------------------\n");
	printf(" 1. player1\n");
	printf(" 2. player2\n");
	printf(" 3. Exit\n");
	printf(" Enter your choice > ");
	scanf("%d", &choice);

	return choice;
}
void init_board() {
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++) 
			board[x][y] = ' ';
	cnt = 0;
}
void print_board() {
	system("cls");
	printf("\n\n");
	printf("     %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
	printf("   -----------------\n");
	printf("     %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
	printf("   -----------------\n");
	printf("     %c  |  %c  |  %c  \n\n", board[2][0], board[2][1], board[2][2]);
}
void main() {
	int choice;

	while (1) {
		init_board();

		switch (menu()) {
		case 1:
			player1();
			break;
		case 2:
			player2();
			break;
		case 3:
			exit(1);
		}
	}

}
void player1() {
	print_board();
	while (1) {
	START_1:
		printf(" Player1(X) 좌표 입력 > ");
		scanf("%d %d", &x, &y);
		if (board[x][y] != ' ') {
			printf(" 잘못된 위치입니다.\n");
			goto START_1;
		}
		else {
			board[x][y] = 1;
			if (board[x][y] == 1) {
				board[x][y] = 'X';
				++cnt;
				print_board();
				if (win(1) == true)
					return true;
			}
		}
		//Computer(O) 좌표 입력
	START_2:
		srand(time(NULL));
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] != ' ') {
			//printf("잘못된 위치입니다.\n");
			goto START_2;
		}
		else {
			board[x][y] = 2;
			if (board[x][y] == 2) {
				board[x][y] = 'O';
				++cnt;
				print_board();
				if (win(2) == true)
					return true;
			}
		}
	}
}
void player2() {
	print_board();
	while (1) {
	START_1:
		printf(" Player1(X) 좌표 입력 > ");
		scanf("%d %d", &x, &y);
		if (board[x][y] != ' ') {
			printf(" 잘못된 위치입니다.\n");
			goto START_1;
		}
		else {
			board[x][y] = 1;
			if (board[x][y] == 1) {
				board[x][y] = 'X';
				++cnt;
				print_board();
				if (win(1) == true)
					return true;
			}
		}
	START_2:
		printf(" Player2(O) 좌표 입력 > ");
		scanf("%d %d", &x, &y);
		if (board[x][y] != ' ') {
			printf(" 잘못된 위치입니다.\n");
			goto START_2;
		}
		else {
			board[x][y] = 3;
			if (board[x][y] == 3) {
				board[x][y] = 'O';
				++cnt;
				print_board();
				if (win(3) == true)
					return true;
			}
		}
	}
}