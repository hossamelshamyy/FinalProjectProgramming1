
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

            }
        }
         if(!sum) {
            printf("The last name is not exist :( \n");
           }
           }



    int main()
    {

    load();
    query();
        return 0;
    }

