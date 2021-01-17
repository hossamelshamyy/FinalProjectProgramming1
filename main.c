#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int day;
    int mon;
    int yr;
} DOB;
typedef struct
{
    char firstname[20];
    char lastname[20];
    char address[100];
    char email[40];
    char phone_no[11];
    DOB birth;
} student;
student s[100];
int count=0;
void load()
{
    FILE*f;
    f=fopen("info.txt","r");
    if (f == NULL)
{
    printf("Error! opening file");
        exit(1);
    }
    while(!feof(f))
{
    fscanf(f,"%[^,],",s[count].firstname);
        fscanf(f,"%[^,],",s[count].lastname);
        fscanf(f,"%d-%d-%d,",&s[count].birth.day,&s[count].birth.mon,&s[count].birth.yr);
        fscanf(f,"%[^,],",s[count].address);
        fscanf(f,"%[^,],",s[count].phone_no);
        fscanf(f,"%s",s[count].email);
        count++;
    }
    fclose(f);

}
void query()
{
    int x,i,j,sum=0;
    char str[20];
    printf("please enter the number needed to search for:  ");
    scanf("%s",&str);
    for(i=0; i<count; i++)
    {
        if(!strcmp(str,s[i].lastname)){

                printf("the info of the student:\n");
                printf("%s  ",s[i].firstname);
                printf("%s   ",s[i].lastname);
                printf("%d  ",s[i].birth.day);
                printf("%d  ",s[i].birth.mon);
                printf("%d  ",s[i].birth.yr);
                printf("%s  ",s[i].address);
                printf("%s  ",s[i].phone_no);
                printf("%s  ",s[i].email);
                printf("\n");
sum++;
            }
        }
         if(!sum) {
            printf("The last name is not exist :( \n");
           }
           }


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
