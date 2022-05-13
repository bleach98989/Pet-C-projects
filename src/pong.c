// I WANT TO PLAY WITH YOU
//
//
//        YOUR FRIEND, AI
#include <stdio.h>

void field(int Xball, int Yball, int leftY, int rightY, int height, int width, int leftScore, int rightScore);
int checkChar(char cmd);
int flagReturn(char cmd, int leftY, int rightY, int height);

int main() {
    // Default coordinates
    // Ball
    int Xball = 40;
    int Yball = 13;
    int Xdir = 1;
    int Ydir = 1;

    int width = 80;
    int height = 25;
    // Rocket 1
    int leftY = 13;
    int leftScore = 0;

    // Rocket 2
    int rightY = 13;
    int rightScore = 0;

    char cmd;

    field(Xball, Yball, leftY, rightY, height, width, leftScore, rightScore);

    while ((leftScore < 21) || (rightScore < 21)) {
    if ((leftScore == 21) || (rightScore == 21)) {
              break;
        }
        scanf("%c", &cmd);

        // If character is in allowed diapason
        if (checkChar(cmd) == 1) {
            printf("\r");
            continue;
        } else {
            // Xball++; Yball++; leftY++;
            // field(Xball, Yball, rightY, leftY);
            if (flagReturn(cmd, leftY, rightY, height) == 1) {
                leftY = leftY - 1;
                printf("move up X");
            } else if (flagReturn(cmd, leftY, rightY, height) == 2) {
                printf("move down X");
                leftY++;
            } else if (flagReturn(cmd, leftY, rightY, height) == 3) {
            printf("move up Y");
                rightY = rightY - 1;
            } else if (flagReturn(cmd, leftY, rightY, height) == 4) {
                printf("move down Y");
                rightY++;
            }

            // Ball

            Xball = Xball + 1 * Xdir;
            Yball = Yball + 1 * Ydir;

            // if left rocket
            if ((Xball == 2) && ((Yball == leftY - 1) || (Yball == leftY) || (Yball == leftY + 1))) {
                Ydir = - Ydir;
            }

            // if right rocket
            if ((Xball == width - 1) && ((Yball == rightY - 1)
                       || (Yball == rightY) || (Yball == rightY + 1))) {
                Xdir = - Xdir;
            }

            // if up ot down
            if ((Yball == height) || (Yball == 1)) {
                Ydir = - Ydir;
            }

            // if left game over
            if (Xball == 1) {
                Xball = 40;
                Yball = 13;
                Xdir = 1;
                Ydir = 1;
                rightScore++;
            }

            // if right game over
            if (Xball == width) {
                Xball = 40;
                Yball = 13;
                Xdir = -1;
                Ydir = 1;
                leftScore++;
            }

            field(Xball, Yball, leftY, rightY, height, width, leftScore, rightScore);
        }
    }

    if (leftScore == 21) {
        printf("\nGAME OVER\n");
        printf("The winner is on the left");
        printf("\nCONGRATULATIONS!\n");
    }

    if (rightScore == 21) {
        printf("\nGAME OVER\n");
        printf("The winner is on the right");
        printf("\nCONGRATULATIONS!\n");
    }
    return 0;
}

void field(int Xball, int Yball, int leftY, int rightY,
        int height, int width, int leftScore, int rightScore) {
    int i, j;

    printf("\033c");
    for (i = 0; i < height + 2; ++i) {  // rows
         for (j = 0; j < width + 2; ++j) {  // columns
             if ((i == 0) && (j == width + 1)) {  // Upsdide new line
                 printf("-\n");
                 continue;
             } else if ((i == 0) && (j != width + 1)) {  // Upside
                 printf("-");
                 continue;
             } else if ((i == height + 1) && (j != width + 1)) {  // Bottom
                 printf("-");
                 continue;
             } else if ((i == height + 1) && (j == width + 1)) {  // Bottom new line
                 printf("-\n");
                 continue;
             } else if ((j == 0) && (i != 0) && (i != height + 1)) {  // Left side
                 printf("|");
                 continue;
             } else if ((j == width + 1) && (i != 0) && (i != height + 1)) {  // Right side
                 printf("|\n");
                 continue;
             } else if ((j == Xball) && (i == Yball)) {  // Ball
                 printf("O");
                 continue;
             } else if ((j == 1) && ((i == leftY - 1) || (i == leftY) || (i == leftY + 1))) {  // Racket 1
                 printf("|");
                 continue;
             } else if ((j == width) && ((i == rightY - 1) || (i == rightY)
                         || (i == rightY + 1))) {  // Racket 2
                 printf("|");
                 continue;
             } else if ((j == 40) && (i != 0) && (i != height + 1)) {  // Middle line
                 printf("|");
                 continue;
             } else {  // Space
                 printf(" ");
                 continue;
             }
         }
    }
    printf("%40d:%d\n", leftScore, rightScore);
    return;
}

int checkChar(char cmd) {
    if ((cmd == 'A') || (cmd == 'Z') || (cmd == 'K') || (cmd == 'M') || (cmd == 'Q') || (cmd == ' ')
         || (cmd == 'a') || (cmd == 'z') || (cmd == 'k') || (cmd == 'm') || (cmd == 'q')) {
        return 0;
    } else {
        return 1;
    }
}

int flagReturn(char cmd, int leftY, int rightY, int height) {
    int flag;
    if ((cmd == 'a') || (cmd == 'A')) {
        if ((leftY - 2) == 0) {
            flag = 5;
            return flag;
        } else {
            flag = 1;
            return flag;
        }
    }
    if ((cmd == 'z') || (cmd == 'Z')) {
        if ((leftY + 2) == height + 1) {
            return 5;
        } else {
            flag = 2;
            return flag;
        }
    }
    if ((cmd == 'k') || (cmd == 'K')) {
        if ((rightY - 2) == 0) {
                return 5;
        } else {
             flag = 3;
             return flag;
        }
    }
    if ((cmd == 'm') || (cmd == 'M')) {
        if (rightY + 2 == height + 1) {
            return 0;
        } else {
            flag = 4;
            return flag;
        }
    }
    if (cmd == ' ') {
        flag = 5;
        return flag;
    }
    return 0;
}
