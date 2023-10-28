/// Copyright 2022  Vada Qarlton
// I WANT TO PLAY WITH YOU
// YOUR FRIEND, AI
#include <stdio.h>
#include <stdlib.h>

void moveRocket();
void moveBall();
void screenRendering();
int checkTablo();
void clearScreen(void);
int rocket_1_Y = 19;
int rocket_2_Y = 5;
int ball_x = 80 / 2;
int ball_y = 25 / 2;
int scPlayer1 = 0;
int scPlayer2 = 0;
int vector_X = -1;
int vector_Y = 1;
int main(void) {
    while (1) {
        screenRendering();
        moveRocket();
        moveBall();
        clearScreen();

        if (checkTablo()) {
            break;
        }
    }
    return 0;
}

void moveRocket() {
    system("stty -icanon");
    char temp;
    switch (temp = getchar()) {
        case 'a' : ((rocket_1_Y - 2) != 0) ? (rocket_1_Y -= 1)
            : rocket_1_Y; break;
        case 'z' : ((rocket_1_Y + 2) != 25 - 1) ? (rocket_1_Y += 1)
            : rocket_1_Y; break;
        case 'k' : ((rocket_2_Y - 2) != 0) ? (rocket_2_Y -= 1)
            : rocket_2_Y; break;
        case 'm' : ((rocket_2_Y + 2) != 25 - 1) ? (rocket_2_Y += 1)
            : rocket_2_Y; break;
    }
}

void screenRendering() {
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 80; ++x) {
            if ((y == 0 && x != 0 && x != 80 - 1) ||
                (y == 3 - 1&& x != 0 && x != 80 - 1)) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != 3 - 1) ||
                        (x == 80 - 1 && y != 0 && y != 3 - 1))) {
                printf("|");
            } else if (x == 5) {
                printf("Press \'Control + c\' to exit");
            } else if (x == 19) {
                printf("Player one: %d | Player two: %d", scPlayer1, scPlayer2);
            }  else if (y == 1 && x < 80 - 55) {
                printf(" ");
            } else if (y != 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int y = 0; y < 25; ++y) {
        for (int x = 0; x < 80; ++x) {
            if ((x == 2 &&
                (y == rocket_1_Y - 1 || y == rocket_1_Y ||
                 y == rocket_1_Y + 1)) ||
                (x == 80 - 3 &&
                (y == rocket_2_Y - 1 || y == rocket_2_Y ||
                 y == rocket_2_Y + 1))) {
                printf("|");
            } else if (x == ball_x && y == ball_y) {
                printf("o");
            } else if ((y == 0 && x != 0 && x != 80 - 1) ||
                        (y == 25 - 1 && x != 0 && x != 80 - 1)) {
                printf("-");
            } else if ((x == 0 && y != 0 && y != 25 - 1) ||
                        (x == 80 - 1 && y != 0 && y != 25 - 1) ||
                        (x == 80 / 2)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void moveBall() {
    if (ball_y == 1 || ball_y == 25 - 2) {
        vector_Y = -(vector_Y);
    }
    if (ball_x == 2 + 1 &&
        (ball_y == rocket_1_Y - 1 ||ball_y == rocket_1_Y  ||
         ball_y == rocket_1_Y + 1)) {
        vector_X = -(vector_X);
    }
    if (ball_x == 80 - 4 &&
        (ball_y == rocket_2_Y - 1 || ball_y == rocket_2_Y  ||
         ball_y == rocket_2_Y + 1)) {
        vector_X = -(vector_X);
    }

    ball_y += vector_Y;
    ball_x += vector_X;
}

int checkTablo() {
    if (ball_x < 2 && ball_y >= 1 && ball_y <= 25) {
        scPlayer2 += 1;
        ball_x = 3;
        ball_y = rocket_1_Y;
    }
    if (ball_x > 80 - 3 && ball_y >= 1 && ball_y <= 25) {
        scPlayer1 += 1;
        ball_x = 80-4;
        ball_y = rocket_2_Y;
    }
    if (scPlayer1 == 21) {
        printf("\n\t Win!!! PLAYER ONE IS WON BY %d TO %d.",
               scPlayer1, scPlayer2);
        return 1;
    } else if (scPlayer2 == 21) {
        printf("\n\t Win!!! PLAYER TWO IS WON BY %d TO %d.",
               scPlayer2, scPlayer1);
        return 1;
    }
    return 0;
}

void clearScreen(void) {
    printf("\33[0d\33[2J");
}



