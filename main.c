#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int day,month,year;
} Date;

typedef struct
{
    char *firstname,*lastname,*address,*email,*phone;
    Date* birth;
} Contact;

Contact* c[100];
static int count=-1;
int isSaved = 0;

int validatePhone(char* phone){
    if(phone[0] == '0'){
        if(phone[1] == '1' && strlen(phone) == 11)
            return 1;
        else if(phone[1] != '0' && strlen(phone) == 9)
            return 1;
    }
    return 0;
}
int validateMail(char* mail){
    int atCouter = 0;
    int dotCounter = 0;
    int len = strlen(mail);
    for(int i = 0;i<len ; i++){
        if(mail[i] == '@'){
            if(i<=len-3)
                atCouter++;
            else return 0;
        }
        else if(mail[i] == '.'){
            if(i <= len-2)
                dotCounter++;
            else return 0;
        }
    }
    if(atCouter == 1 && dotCounter ==1)
        return 1;
    return 0;

}

int validateDate(int day,int month,int year){
    if(year>=1900 && year<=2021){
        if(month>=1 && month<=12){
            if((day>=1 && day<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                return 1;
            else if((day>=1 && day<=30) && (month==4 || month==6 || month==9 || month==11))
                return 1;
            else if((day>=1 && day<=28) && (month==2))
                return 1;
            else if(day==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                return 1;
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
Date* createDate(int day,int month,int year){
    if(validateDate(day,month,year)){
        Date * date = malloc(sizeof(Date));
        date->day = day;
        date->month = month;
        date->year = year;
        return date;
    }
    else return 0;
}

Contact* createContact(char* firstname,char* lastname,char* address,char* email,char* phone,Date* birth){
    Contact* contanct = malloc(sizeof(Contact));
    contanct->firstname = firstname;
    contanct->lastname = lastname;
    contanct->address = address;
    contanct->email = email;
    contanct->phone = phone;
    contanct->birth = birth;
    return contanct;
}

void load()
{
    FILE*f;
    f=fopen("/home/hossam/Workplace/QtProjects/FinalProjectProgramming1/info.txt","r");
    if (f == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    while(!feof(f))
    {
        count++;
        char *firstname = malloc(sizeof (char*)),*lastname = malloc(sizeof (char*)),*address = malloc(sizeof (char*)),*email = malloc(sizeof (char*)),*phone_no = malloc(sizeof (char*));
        int day,month,year;
        fscanf(f,"%[^,],",firstname);
        fscanf(f,"%[^,],",lastname);
        fscanf(f,"%d-%d-%d,",&day,&month,&year);
        fscanf(f,"%[^,],",address);
        fscanf(f,"%[^,],",phone_no);
        fscanf(f,"%s",email);
        c[count] = createContact(firstname,lastname,address,email,phone_no,createDate(day,month,year));
    }

    fclose(f);

}


void query()
{
    int i,sum=0;
    char *str = malloc(sizeof (char*));
    printf("please enter the student last name needed to search for:  ");
    scanf("%s",str);
    for(i=0; i<=count; i++){
        if(!strcmp(str,c[i]->lastname)){
            //printf("The info of the contact: %s %s %d %d %d %s %s %s\n",c[i]->firstname,c[i]->lastname,c[i]->birth->day,c[i]->birth->month,c[i]->birth->year,c[i]->address,c[i]->phone_no,c[i]->email);
            printf("The info of the contact: ");
            printf("%s,",c[i]->firstname);
            printf("%s,",c[i]->lastname);
            printf("%d-",c[i]->birth->day);
            printf("%d-",c[i]->birth->month);
            printf("%d,",c[i]->birth->year);
            printf("%s,",c[i]->address);
            printf("%s,",c[i]->phone);
            printf("%s\n",c[i]->email);
            sum++;
        }
    }
    if(!sum) {
        printf("The last name is not exist :( \n");
    }

}
void add(){
    char *firstname = malloc(sizeof (char*)),*lastname = malloc(sizeof (char*)),*address = malloc(sizeof (char*)),*email = malloc(sizeof (char*)),*phone = malloc(sizeof (char*));
    int day,month,year;
    printf("First name : ");
    scanf("%s",firstname);
    printf("Last name : ");
    scanf("%s",lastname);
    printf("Address : ");
    getchar();
    gets(address);
    printf("email : ");
    scanf("%s",email);
    while(!validateMail(email)){
        printf("please enter correct email : ");
        scanf("%s",email);
    }
    printf("Phone : ");
    scanf("%s",phone);
    while(!validatePhone(phone)){
        printf("please enter correct phone number : ");
        scanf("%s",phone);
    }
    printf("Birth day : ");
    scanf("%d",&day);
    printf("Birth month : ");
    scanf("%d",&month);
    printf("Birth year : ");
    scanf("%d",&year);
    while(!validateDate(day,month,year)){
        printf("You entered inccorect date please try again \n");
        printf("Birth day : ");
        scanf("%d",&day);
        printf("Birth month : ");
        scanf("%d",&month);
        printf("Birth year : ");
        scanf("%d",&year);
    }
    count++;
    c[count] = createContact(firstname,lastname,address,strcat(email,"\n"),phone,createDate(day,month,year));
    printf("Contact added successfully.\n");
}

void Swapcontact(Contact*c, Contact*c2)
{
    Contact temp = *c;
    *c = *c2;
    *c2 = temp; 
}

void SortByLname()
{
  int i=0, j=0;

  for(i=0; i<=count; i++)
  {
    for(j=i+1; j<count; j++)
    {
      if(strcmp(c[i]->lastname,c[j]->lastname)>0)
      {
        Swapcontact(c[i],c[j]);
      }
  }
}
  for(i=0; i<=count; i++){
    printf("%s,",c[i]->firstname);
    printf("%s,",c[i]->lastname);
    printf("%d-",c[i]->birth->day);
    printf("%d-",c[i]->birth->month);
    printf("%d,",c[i]->birth->year);
    printf("%s,",c[i]->address);
    printf("%s,",c[i]->phone);
    printf("%s\n",c[i]->email);
        
  }
}

void SortByDOB()
{
  int i=0, j=0;

  for(i=0; i<=count; i++)
  {
    for(j=i+1; j<count; j++)
    {
      if(c[i]->birth->year > c[j]->birth->year)
      {
        Swapcontact(c[i],c[j]);
      }
      else if (c[i]->birth->year == c[j]->birth->year)
      {
        if(c[i]->birth->month > c[j]->birth->month)
        {
          Swapcontact(c[i],c[j]);
        }
        else if (c[i]->birth->month == c[j]->birth->month)
        {
          if(c[i]->birth->day > c[j]->birth->day)
          {
            Swapcontact(c[i],c[j]);
          }
        }  
      }
  }
}

for(i=0; i<=count; i++){
    printf("%s,",c[i]->firstname);
    printf("%s,",c[i]->lastname);
    printf("%d-",c[i]->birth->day);
    printf("%d-",c[i]->birth->month);
    printf("%d,",c[i]->birth->year);
    printf("%s,",c[i]->address);
    printf("%s,",c[i]->phone);
    printf("%s\n",c[i]->email);
        
  }

}

void print ()
{
  int choice = 0;
  printf("Choose the sorting type:\n1-Sort by Last Name  2-Sort by date of birth\n");
  while (choice != 1 && choice != 2){
    scanf("%d",&choice);
    if (choice == 1){
      SortByLname();
      break;
    }
    else if (choice == 2){
      SortByDOB();
      break;
    }
    printf("Please choose a valid option (1 or 2)\n");
  }    
}

int save()
{
    FILE*f;
    f=fopen("/home/hossam/Workplace/QtProjects/FinalProjectProgramming1/saved.txt","w");
    int i;
    for ( i = 0; i <= count ; i++){
        fprintf(f,"%s,",c[i]->firstname);
        fprintf(f,"%s,",c[i]->lastname);
        fprintf(f,"%d-%d-%d,",c[i]->birth->day,c[i]->birth->month,c[i]->birth->year);
        fprintf(f,"%s,",c[i]->address);
        fprintf(f,"%s,",c[i]->phone);
        fprintf(f,"%s",c[i]->email);
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
            load();
            break;
        case 2:
            query();
            break;
        case 3:
            add();
            break;
        case 4:
            // delete();
            break;
        case 5:
            // modify();
            break;
        case 6:
            print();
            break;
        case 7:
            save();
            break;
        case 8:
            quit();
            break;
        }
    }
    return 0;
}

