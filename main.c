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
} Contact;
Contact c[100];
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
    fscanf(f,"%[^,],",c[count].firstname);
        fscanf(f,"%[^,],",c[count].lastname);
        fscanf(f,"%d-%d-%d,",&c[count].birth.day,&c[count].birth.mon,&c[count].birth.yr);
        fscanf(f,"%[^,],",c[count].address);
        fscanf(f,"%[^,],",c[count].phone_no);
        fscanf(f,"%s",c[count].email);
        count++;
    }
    fclose(f);

}


void query()
{
    int x,i,j,sum=0;
    char str[20];
    printf("please enter the student last name needed to search for:  ");
    scanf("%s",&str);
    for(i=0; i<count; i++)
    {
        if(!strcmp(str,c[i].lastname)){

                printf("the info of the student:\n");
                printf("%s  ",c[i].firstname);
                printf("%s   ",c[i].lastname);
                printf("%d  ",c[i].birth.day);
                printf("%d  ",c[i].birth.mon);
                printf("%d  ",c[i].birth.yr);
                printf("%s  ",c[i].address);
                printf("%s  ",c[i].phone_no);
                printf("%s  ",c[i].email);
                printf("\n");
                sum++;
            }
    }
         if(!sum) {
            printf("The last name is not exist :( \n");
           }
}

int isSaved = 0;
int save()
{
    FILE*f;
    f=fopen("Contacts.txt","w");
   int i;
   for ( i = 0; i < count; i++)
   {
        fprintf(f,"%s,",c[i].firstname);
        fprintf(f,"%s,",c[i].lastname);
        fprintf(f,"%d-%d-%d,",&c[i].birth.day,&c[i].birth.mon,&c[i].birth.yr);
        fprintf(f,"%s,",c[i].address);
        fprintf(f,"%s,",c[i].phone_no);
        fprintf(f,"%s\n",c[i].email);      
   }
   isSaved=1;
    fclose(f);
    return isSaved ;
}

void quit(){
    if (isSaved)
    {
        exit(0);
    }else{
        char answer[2] ;
        int i;
        printf("Warning!! your changes will be discarded\n NOTE: answer as follow\n do you want to exit anyways(y/n) ? ");
        scanf("%s",answer);
        if (!strcmp(answer , "y"))
        {
            exit(0); 
        }
        
        
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
