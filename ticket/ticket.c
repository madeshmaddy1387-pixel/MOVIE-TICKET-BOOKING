#include <stdio.h>

#define ROWS 8
#define COLS 10
#define PRICE 150

struct Movie {
    char name[50];
    int seats[ROWS][COLS];
};

void displaySeats(int seats[ROWS][COLS]) {

    int r, c;

    printf("\n\n                SCREEN THIS WAY\n");
    printf("   -------------------------------------------------\n\n");

    printf("      ");
    for(c = 0; c < COLS; c++)
        printf(" %2d", c + 1);
    printf("\n");

    for(r = 0; r < ROWS; r++) {
        printf("   %c  ", 'A' + r);
        for(c = 0; c < COLS; c++) {
            if(seats[r][c] == 0)
                printf("  O");
            else
                printf("  X");
        }
        printf("\n");
    }

    printf("\n   O = Available     X = Booked\n");
}

int main() {

    struct Movie movies[5] = {
        {"Leo", {0}},
        {"Jailer", {0}},
        {"Vikram", {0}},
        {"Master", {0}},
        {"Thunivu", {0}}
    };

    int choice, ticketCount;
    int totalAmount = 0;
    int booked = 0;
    int totalSeats;
    int r, c, i;

    printf("============================================\n");
    printf("        TAMIL MOVIE BOOKING SYSTEM\n");
    printf("============================================\n\n");

    printf("Available Movies:\n");
    for(i = 0; i < 5; i++)
        printf("%d. %s\n", i + 1, movies[i].name);

    printf("\nSelect Movie (1-5): ");
    scanf("%d", &choice);

    if(choice < 1 || choice > 5) {
        printf("Invalid Selection!\n");
        return 0;
    }

    displaySeats(movies[choice-1].seats);

    printf("\nEnter number of tickets to book: ");
    scanf("%d", &ticketCount);

    totalSeats = ROWS * COLS;

    if(ticketCount > totalSeats) {
        printf("Not enough seats in theatre!\n");
        return 0;
    }

    for(r = 0; r < ROWS; r++) {
        for(c = 0; c < COLS; c++) {

            if(movies[choice-1].seats[r][c] == 0) {

                movies[choice-1].seats[r][c] = 1;
                printf("Seat %c%d Booked\n", 'A'+r, c+1);
                booked++;

                if(booked == ticketCount)
                    break;
            }
        }
        if(booked == ticketCount)
            break;
    }

    totalAmount = booked * PRICE;

    printf("\n============================================\n");
    printf("               BOOKING SUMMARY\n");
    printf("============================================\n");
    printf("Movie Name       : %s\n", movies[choice-1].name);
    printf("Tickets Booked   : %d\n", booked);
    printf("Price Per Ticket : Rs.%d\n", PRICE);
    printf("Total Amount     : Rs.%d\n", totalAmount);
    printf("============================================\n");

    displaySeats(movies[choice-1].seats);

    printf("\nEnjoy Your Movie!\n");

    return 0;
}