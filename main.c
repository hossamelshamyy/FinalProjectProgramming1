#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned int day,month,year;
} Date ;

typedef struct{
    char* firstName;
    char* lastName;
    Date* birthDate;
    char* adress;
    char* phoneNum;
    char* email;

} Directory ;

int main()
{
    printf("Welcome in telephone book program...\n");

    while(1){
        printf("\nChoose the number of corresponding option do you want :-\n");

        printf("1 -> Read from file\n");
        printf("2 -> Search\n");
        printf("3 -> Add\n");
        printf("4 -> Delete\n");
        printf("5 -> Modify\n");
        printf("6 -> Print\n");
        printf("7 -> Save\n");
        printf("8 -> Quit\n");

        int choice;
        printf("Enter a number : ");
        scanf("%d",&choice);
        while (choice<1 || choice >8 ) {
            printf("\nPlease enter a correct option number :-\n");
            printf("Enter a number : ");
            scanf("%d",&choice);
        }

        switch (choice) {
        case 1:
            // load();
            break;
        case 2:
            // search();
            break;
        case 3:
            // add();
            break;
        case 4:
            // delete();
            break;
        case 5:
            // modify();
            break;
        case 6:
            // print();
            break;
        case 7:
            // save();
            break;
        case 8:
            // quit();
            break;
        }
    }
    return 0;
}
