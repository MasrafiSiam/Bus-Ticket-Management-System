#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SEAT_NUMBER 30
#define MAX_USERS 100
#define USER_DATA_FILE "userdata.txt"

typedef struct
{
    char name[100];
    char email[100];
    char password[20];
} User;

typedef struct
{
    char name[100];
    char number[11];
    char email[100];
    char new_password[20];
} Signup;

void login();
void menu();
void bookSeat();
void cancelBooking();
void displayAvailableSeats();
void displayBookingInfo();
void printMenu();
void logout();
void signup();

bool login_success = false;
int user_count = 0;
int bus[SEAT_NUMBER] = {0};

void initializeUserCount()
{
    FILE *fp = fopen(USER_DATA_FILE, "r");
    if (fp != NULL)
    {
        char file_name[100], file_email[100], file_password[20];
        while (fscanf(fp, "%s %s %s", file_name, file_email, file_password) != EOF)
        {
            user_count++;
        }
        fclose(fp);
    }
}

int main()
{
    initializeUserCount();
    int choice_start;

    while (true)
    {
        printf("======Bus Tickets======\n");
        printf("1. Login\n2. Sign up\n3. Exit\n\nEnter your choice: ");
        scanf("%d", &choice_start);

        switch (choice_start)
        {
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }

        while (login_success)
        {
            printMenu();
            menu();
        }
    }

    return 0;
}

void login()
{
    User user1;
    FILE *fp;
    char file_name[100], file_email[100], file_password[20];

    fp = fopen(USER_DATA_FILE, "r");
    if (fp == NULL)
    {
        printf("No user data file found. Please sign up first.\n");
        return;
    }

    printf("User Name or Email: ");
    scanf("%s", user1.name);
    printf("Password: ");
    scanf("%s", user1.password);

    bool user_found = false;
    while (fscanf(fp, "%s %s %s", file_name, file_email, file_password) != EOF)

    {
        if ((strcmp(file_name, user1.name) == 0 || strcmp(file_email, user1.name) == 0) &&
            strcmp(file_password, user1.password) == 0)
        {
            login_success = true;
            user_found = true;
            printf("\nLogging in as %s...\n\n", file_name);
            break;
        }
    }

    if (!user_found)
    {
        printf("\nInvalid username or password.\n\n");
        login_success = false;
    }

    fclose(fp);
}

void signup()
{
    if (user_count < MAX_USERS)
    {
        User newSignup;
        printf("\nEnter the User Name: ");
        scanf("%s", newSignup.name);
        printf("Enter the User Email: ");
        scanf("%s", newSignup.email);
        printf("Enter the User Password: ");
        scanf("%s", newSignup.password);


        FILE *fp = fopen(USER_DATA_FILE, "r");
        if (fp != NULL)
        {
            char file_name[100], file_email[100], file_password[20];
            while (fscanf(fp, "%s %s %s", file_name, file_email, file_password) != EOF)
            {
                if (strcmp(file_email, newSignup.email) == 0) {
                    printf("An account with this email already exists.\n");
                    fclose(fp);
                    return;
                }
            }
            fclose(fp);
        }

        fp = fopen(USER_DATA_FILE, "a");
        if (fp == NULL)
        {
            printf("Error opening user data file for writing.\n");
            return;
        }

        fprintf(fp, "%s %s %s\n", newSignup.name, newSignup.email, newSignup.password);
        fclose(fp);

        user_count++;
        printf("\nSignup successful!\n");
    }
    else
    {
        printf("User limit reached. Cannot add more users.\n");
    }
}

void bookSeat()
{
    int numSeats, seatNumber;
    printf("How many seats would you like to book? ");
    scanf("%d", &numSeats);

    if (numSeats < 1 || numSeats > SEAT_NUMBER)
    {
        printf("Invalid number of seats.\n");
        return;
    }

    for (int i = 0; i < numSeats; i++)
    {
        printf("Enter seat number to book (1-30): ");
        scanf("%d", &seatNumber);

        if (seatNumber < 1 || seatNumber > SEAT_NUMBER)
        {
            printf("Invalid seat number %d. Please try again.\n", seatNumber);
            i--;
            continue;
        }

        if (bus[seatNumber - 1] == 1)
        {
            printf("Seat %d is already booked. Please choose another seat.\n", seatNumber);
            i--;
        }
        else
        {
            bus[seatNumber - 1] = 1;
            printf("Seat %d booked successfully.\n", seatNumber);
        }
    }

    printf("Booking process completed. Please proceed to payment.\n");
}

void cancelBooking()
{
    int seatNumber;
    printf("Enter seat number to cancel booking (1-30): ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > SEAT_NUMBER)
    {
        printf("Invalid seat number.\n");
        return;
    }

    if (bus[seatNumber - 1] == 0)
    {
        printf("No booking found for seat %d.\n", seatNumber);
    }
    else
    {
        bus[seatNumber - 1] = 0;
        printf("Booking for seat %d cancelled successfully.\n", seatNumber);
    }
}

void displayBookingInfo()
{
    printf("Seat Number\tStatus\n");
    for (int i = 0; i < SEAT_NUMBER; i++)
    {
        printf("%d\t\t%s\n", i + 1, bus[i] == 1 ? "Booked" : "Available");
    }
}

void displayAvailableSeats()
{
    printf("Available Seats:\n");
    int availableCount = 0;
    for (int i = 0; i < SEAT_NUMBER; i++)
    {
        if (bus[i] == 0)
        {
            printf("%d ", i + 1);
            availableCount++;
        }
    }
    if (availableCount == 0)
    {
        printf("All seats are booked.");
    }
    printf("\n");
}

void logout()
{
    printf("Logged out successfully.\n");
    login_success = false;
}

void printMenu()
{
    printf("\n\n1. Book a seat\n");
    printf("2. Cancel booking\n");
    printf("3. Display booking information\n");
    printf("4. Display available seats\n");
    printf("5. Logout\n");
}

void menu()
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            bookSeat();
            break;
        case 2:
            cancelBooking();
            break;
        case 3:
            displayBookingInfo();
            break;
        case 4:
            displayAvailableSeats();
            break;
        case 5:
            logout();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}
