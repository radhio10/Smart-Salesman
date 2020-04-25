#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

char name[20];
char password[20];
FILE *lp;
FILE *ap;



struct store
{
        char date[20];
    char s_name[20],place[20],i_name[20],d_date[20];
    int quant;
    int n;
    float price;
    };
    struct store ord;



void S_recored()
{
     int count=1,i=0,n,s;
     FILE *rcd;
     rcd=fopen ("Recording.text","a");

    printf("\n\n\t\t\t Enter Date: ");
    scanf("%s",ord.date);
    printf("\n\t\t\t\tEnter store name: ");
    scanf("%s",&ord.s_name);
    printf("\n\t\t\t\tEnter place: ");
    scanf("%s",&ord.place);
    printf("\n\t\t Enter how many item you want to take: ");
    scanf("%d",&s);
     while(i<s)
     {
      printf("\n\t\t\t\tEnter Item Name: ");
      scanf("%s",ord.i_name);
      printf("\n\t\t\t\tEnter Quantity(kg): ");
      scanf("%d",&ord.quant);
      printf("\n\t\t\t\tEnter Price: ");
      scanf("%f",&ord.price);
    printf("\n\t\t\tEnter Delivery Date: ");
    scanf("%s",&ord.d_date);
    i++;
   fwrite(&ord, sizeof(ord), 1, rcd);
    }


    fclose(rcd);

    int a;
    printf("\n\t\t\t  1->To Take Another Order");
    printf("\n\t\t\t  2->TO Back To Home Page");
    printf("\n\t\t\t  0-> EXIT\n");
    printf("\n\t\t\t  Enter Your Chose:");
    fflush(stdin);
    while(scanf("%d",&a))
    {
        if(a==1 || a==2 || a==3)
        {
         if(a==1)
         {
             printf("\n\t\t\t***New Recored Saving***");
             printf("\n\t\t\t_________________________");
             S_recored();
             break;
         }
         if(a==2)
         {
             system("cls");
             home();
             break;
         }
         if(a==0)
         {
             ext();
             break;
         }

        }
        printf("\n\t\t\tINVALID INPUT READ OPTION CAREFULLY: ");
        fflush(stdin);
         fclose(rcd);
    }

}



void delet()
{
    printf("\n\n\t\t\t\t *** DELETING ***");
       printf("\n\t\t\t\t_________________");
    FILE *fp1,*fp2;
    struct store ord;
    int found=0, count=0;
    char dt[30];
    fp1=fopen("Recording.text","r");
    fp2=fopen("Temp.txt","w");
    fflush(stdin);
    printf("\n\t\t\tENTER THE DATE YOU WANT TO DELETE:");
    gets(dt);
    while(1)
    {

        fread(&ord, sizeof(ord), 1, fp1);
        if(feof(fp1))
        {
            break;
        }
        if(strcmp(dt,ord.date)==0)
        {
            found=1;
            printf("\n\n\t\t\t\t ***SUCCESSFULLY DELETED***\n");

        }
        else
        {
            fwrite(&ord, sizeof(ord), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        printf("\n\n\t\t\t Sorry Not Found\n");
        delet();
    }
    else
    {
        fp1=fopen("Recording.text","w");
        fp2=fopen("Temp.txt","r");
        while(1)
        {
            fread(&ord, sizeof(ord), 1, fp2);
            if(feof(fp2))
            {
                break;
            }
            fwrite(&ord, sizeof(ord), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp2);
    choise();
}




void show()
{
    FILE *shw;
    int count=1;
    shw=fopen("Recording.text","r");
    while(fread(&ord, sizeof(ord), 1, shw))
    {
     printf("\n\t\t%d. ",count);
     printf("\n\t\t\tOrder date: %s\n\t\t\t\tStore name: %s\n\t\t\t\tAddress: %s\n\t\t\t\tItem name: %s\n\t\t\t\t Quantity: %d\n\t\t\t\tPrice %.2f\n\t\t\t\tDelivery Date: %s\n\t\t\t\t",ord.date,ord.s_name,ord.place,ord.i_name,ord.quant,ord.price,ord.d_date);
     count++;

      }
    fclose(shw);
    int d;

    printf("\n\t\t\t  1->TO Back To Home Page");
    printf("\n\t\t\t  0-> EXIT\n");
    printf("\n\t\t\t  Enter Your Chose:");
          while(scanf("%d",&d))
            {
        if(d==1 || d==0)
        {
         if(d==1)
         {
             system("cls");
             main();
             break;
         }
         if(d==0)
         {
             system("cls");
             ext();
             break;
         }
        }
    }
}





void search()
{
    printf("\n\n\n\t\t\t*** SEARCHING ***  ");
        printf("\n\t\t\t__________________");
    FILE *fptr2;
    fptr2=fopen("Recording.text","r");
    if(fptr2==NULL)
    {
        printf("error");
        exit(1);
    }
    char d[20];
    printf("\n\t\t\tEnter Date To Search Taken Order:");
    scanf("%s",&d);
    while(fread(&ord, sizeof(ord), 1,fptr2))
        {
            if(strcmp(d,ord.date)==0)
                while(1)
                {

        printf("\n\tOrder date: %s\n\t\tStore name: %s\n\t\tAddress: %s\n\t\tItem name: %s\n\t\t Quantity: %d\n\t\tPrice %.2f\n\t\tDelivery Date: %s\n\t\t",ord.date,ord.s_name,ord.place,ord.i_name,ord.quant,ord.price,ord.d_date);

            break;
            }
        }

            if(strcmp(d,ord.date)!=0)
            {
    printf("\n\tSorry not found");
    search();
            }
            option();
        }








void S_function()
{
    system("cls");
    Sleep(500);
    printf("\n\n\t\t\t\t***You have successfully Logged in***");
      printf("\n\t\t\t\t______________________________________");
    Sleep(500);
    printf("\n\t\t\t 1-> Store a new record");
    Sleep(500);
    printf("\n\t\t\t 2-> Quit");
    int num3;
    Sleep(500);
    printf("\n\n\t\t\t Enter Your Chose:");
    scanf("%d",&num3);
    system ("cls");
    switch (num3)
    {
    case 1:
        Sleep(500);
        printf("\n\t\t\t\t***RECORDING***");
        printf("\n\t\t\t\t________________");
        S_recored();
        break;
        case 2:
        Sleep(500);
        ext();
        break;
        default:
            Sleep(500);
             printf("\n\n\t\t\tyour choosing is not valid");
             S_function();
    }
}



void A_function()
{
    system("cls");
    Sleep(500);
    printf("\n\n\t\t\t\t***You have successfully Logged in***");
      printf("\n\t\t\t\t______________________________________");

Sleep(500);
printf("\n\t\t\t 1-> View old record");
Sleep(500);
    printf("\n\t\t\t 2->Search record by Date ");
    Sleep(500);
    printf("\n\t\t\t 3->Delete a Order");
    Sleep(500);
    printf("\n\t\t\t 4-> Quit");
    int num4;
    Sleep(500);
    printf("\n\t\t\t Enter Your Chose:");
    scanf("%d",&num4);
     system ("cls");
     switch (num4)
     {
     case 1:
        Sleep(500);
        printf("\n\n\n\t\t\t***RECORDED ORDER***");
            printf("\n\t\t\t_____________________");
        show();
        break;
     case 2:
         Sleep(500);
        search();
        break;
     case 3:
         Sleep(500);
        delet();
        break;
     case 4:
         Sleep(500);
        printf("\n\t\t\t You have successfully logged out\n");
{
        break;
        default:
            Sleep(500);
            printf("\n\n\t\t\tyour choosing is not valid.");
            A_function();


     }
}
}




void S_login()
{
// match with the saved passwords in file
int num6;
    printf("\n\n\t\t\t\t **SALESMAN LOG IN** ");
       printf("\n\t\t\t\t___________________");
    char pswrd[20];
    int num4;
    ap=fopen("Salesman.text","r");
    Sleep(500);
    printf("\n\n\t\tEnter Salesman name:");
    scanf("%s",&name);
    Sleep(500);
    printf("\n\t\tEnter Password:");
    scanf("%s",&pswrd);
    {
        if(strcmp(pswrd,password)==0) //compare with login function password

             {
            S_function();
             }
            else
            {
                printf("\n\t\t\t***Your password is incorrect***");
                   printf("\n\t\t\t_________________________________");
                printf("\n\n\t\t For Sign Up:- 1");
                printf("\n\t\t Try Again:- 2");
                 printf("\n\t\tChose your panel:");
    scanf("%d",&num6);
    system ("cls");
switch (num6)
    {
    case 1:
        Sleep(500);
        S_signup() ;
        break;
    case 2:
        Sleep(500);
        S_login();
        break;
               default:
             Sleep(500);
             printf("\n\t\t\t***Your choosing is not valid***\n");
             printf("\n\t\t\t_________________________________");

             S_login();



               }


 }

}

}



void A_login()
{

    // match with the saved passwords in file
    int num5;
    printf("\n\n\n\t\t\t\t **ADMIN LOG IN** ");
        printf("\n\t\t\t\t___________________");
    char pswrd1[20];
    lp=fopen("ADMIN.text","r");
    Sleep(500);
    printf("\n\t\t\tEnter name:");
    scanf("%s",&name);
    Sleep(500);
    printf("\n\t\t\tEnter Password:");
    scanf("%s",&pswrd1);


    {
        if(strcmp(pswrd1,password)==0) //compare with login function password
            {
                A_function();
            }
            else
               {
                   printf("\n\t\t\t***Your password is incorrect***");
                   printf("\n\t\t\t_________________________________");
                printf("\n\n\t\t For Sign Up:- 1");
                printf("\n\t\t Try Again:- 2");
                 printf("\n\t\tChose your panel:");
    scanf("%d",&num5);
    system ("cls");
switch (num5)
    {
    case 1:
        Sleep(500);
        A_signup() ;
        break;
    case 2:
        Sleep(500);
        A_login();
        break;
               default:
             Sleep(500);
             printf("\n\t\t\t***Your choosing is not valid***\n");
             printf("\n\t\t\t_________________________________");
             A_login();



               }
               }


    }

}


void A_signup()
{   printf("\n\n\n\t\t\t\t **ADMIN SIGN UP** ");
        printf("\n\t\t\t\t___________________");
    lp= fopen("ADMIN.text","a");
Sleep(500);
    printf("\n\t\t\tEnter Admin name: ");
    scanf("%s",&name);
    char ch;
    int chpos=0;
    Sleep(500);
    printf("\n\t\t\tEnter password(within 8 characters): ");
    while(1)
    {
        ch=getch();
        if(ch==13)//when user press enter (ascii=13)
        {
            break;
        }
        else if(ch==8)//backspace (ascii=8) not allowed
        {
            if(chpos>0)
            {
                chpos--;
                password[chpos]='\0';
                printf("\b \b");
            }
        }
        else if(ch==32||ch==9)//when user press space (ascii=32) or tab(ascii=9)
        {
            continue;
        }
        else
        {
            if(chpos<8)
            {
                password[chpos]=ch;
                chpos++;
                printf("*");
            }
            else
            {
                printf("\n\t\t\t You entered more than 8 characters");
            }
        }
    }
    password[chpos]='\0';
    printf("\n");
    if (strlen(password)==0)
    {
        printf("No password Entered :)");
    }
    else
    {
        Sleep(500);
        printf("\n\t\t\tYou have successfully signed up \t YOUR PASSWORD = %s\n",password);

    }
    fprintf (lp,"%s %s",name,password);
    fclose(lp);
    A_login();
}



void S_signup()
{
    printf("\n\n\n\t\t\t\t **SALESMAN SIGN UP** ");
    printf("\n\t\t\t\t_______________________");
    ap= fopen("Salesman.text","a");
    Sleep(500);
    printf("\n\t\t\tEnter Salesman name:");
    scanf("%s",&name);
    Sleep(500);
    printf("\n\t\t\tEnter Password(within 8 characters):");
    char ch;
    int chpos=0;
    while(1)
    {
        ch=getch();
        if(ch==13)//when user press enter (ascii=13)
        {
            break;
        }
        else if(ch==8)//backspace (ascii=8) not allowed
        {
            if(chpos>0);
            {
                chpos--;
                password[chpos]='\0';
                printf("\b \b");
            }
        }
        else if(ch==32||ch==9)//when user press space (ascii=32) or tab(ascii=9)
        {
            continue;

        }
        else
        {
            if(chpos<8)
            {
                password[chpos]=ch;
                chpos++;
             printf("*");
            }
            else
            {
                printf("\n\t\t\t You Entered more than 8 Characters");
            }
        }

    }
    password[chpos]='\0';
    printf("\n");
    if(strlen(password)==0)
    {
        printf("\n\t\t\tNo Password Entered");
    }
    else
    {
       Sleep(500);
        printf("\n\t\t\tYou have successfully signed up \t Your Password=%s \n",password);
    }

fprintf(ap,"%s %s",name,password);
fclose(ap);
    S_login();
}



void admin()
{
    printf("\n\n\n\t\t\t\t ***Admin Panel***  \n");
        printf("\t\t\t\t__________________");
    int num1;
    Sleep(500);
    printf ("\n\n\t\t\t 1-> Log in \n");
    Sleep(500);
    printf ("\t\t or \n\n\t\t\t 2-> Sign Up\n");
    Sleep(500);
    printf("\n\t\t\tChose your panel:");
    scanf("%d",&num1);
    system ("cls");
    switch(num1)
    {
    case 1:
        Sleep(500);
       A_login();
        break;

    case 2:
        Sleep(500);
        A_signup() ;
        break ;
         default:
             Sleep(500);
             printf("\n\t\t\t***Your choosing is not valid***");
             printf("\n\t\t\t_________________________________");
             admin();

    }
}



void salesman()
{

    int num2;
        printf("\n\n\n\t\t\t\t ***Salesman Panel**** ");
        printf("\n\t\t\t\t_______________________");
    Sleep(500);
    printf ("\n\n\t\t\t 1-> Log in \n");
    Sleep(500);
    printf ("\t\t or \n\n\t\t\t 2-> Sign Up\n");
    Sleep(500);
    printf("\n\t\t\tChose your panel:");
    scanf("%d",&num2);
    system ("cls");
    switch(num2)
    {
    case 1:
        Sleep(500);
       S_login();
        break;

    case 2:
        Sleep(500);
        S_signup() ;
        break ;
        default:
            Sleep(500);
             printf("\n\t\t\t***Your choosing is not valid***\n");
             printf("\t\t\t_________________________________");
             salesman();

    }
}



void home()
{

    int num;
    Sleep(500);
    printf("\n\n\n\t\t\t\t :) ****WELCOME TO SMART SALESMAN**** (:    ");
    printf("\n\t\t\t\t________________________________________");
    Sleep(500);
    printf("\n\n\t\t\t  1-> Admin Panel ");
    Sleep(500);
    printf("\n\t\t\t  2-> Salesman Panel ");
    Sleep(500);
    printf("\n\t\t\t  3-> EXIT Panel ");
    Sleep(500);
    printf("\n\n\t\tChose your panel:");
    scanf("%d",&num);
    system ("cls");
switch (num)
    {
    case 1:
        Sleep(500);
        admin();
        break;
    case 2:
        Sleep(500);
        salesman();
        break;
    case 3:
        Sleep(500);
        ext();
        break;
        Sleep(500);
        default:
            Sleep(500);
             printf("\n\t\t\t***Your choosing is not valid***");
             printf("\n\t\t\t_________________________________");
             home();
    }

}



void main()
{
    home();
}



 COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }



void ext()
{
    gotoxy(40,9);
    printf("\n\t\t\t\t\t *** EXIT***  \n");
      printf("\t\t\t\t\t_____________");
    int c_ext;
    printf("\n\t\t\t\t\t 1->CANCEL EXIT\n");
    printf("\t\t\t\t 2->TO MAKE SURE EXIT\n");
    printf("\t\t\t  Chose your panel: ");
    fflush(stdin);
    while(scanf("%d",&c_ext))
    {
        if(c_ext==1 || c_ext==2)
        {
           if(c_ext==1)
           {
               system("cls");
               main();
               break;
           }
           if(c_ext==2)
           {
               system("cls");
               printf("\n\n\n\t\t\t\t  {**THANKS**}\n");
               printf("\n\t\t\t\t  {**PRESS ANY KEY TO EXIT SUCCESS**}\n");
               exit(EXIT_SUCCESS);
               break;
           }
        }
        printf("\t\t\t\t INVALID INPUT READ OPTION CAREFULLY: ");
        fflush(stdin);
    }
}



void option()
{
    int a;
    printf("\n\t\t\t  1->To Search Another Order");
    printf("\n\t\t\t  2->TO Back To Home Page");
    printf("\n\t\t\t  0-> EXIT\n");
    printf("\n\t\t  Enter Your Chose:");
    fflush(stdin);
    while(scanf("%d",&a))
    {
        if(a==1 || a==2 || a==0)
        {
         if(a==1)
         {
            system("cls");
             search();
             break;
         }
         if(a==2)
         {
             system("cls");
             home();
             break;
         }
         if(a==0)
         {
             ext();
             break;
         }

        }
        else
        printf("\n\t\t\t\t  INVALID INPUT READ OPTION CAREFULLY: ");
        fflush(stdin);
          }

            }



            void choise()
{
    int z;
    printf("\n\t\t\t  1->To Delete Another Order");
    printf("\n\t\t\t  2->TO Back To Home Page");
    printf("\n\t\t\t 0-> EXIT\n");
    printf("\n\t\t  Enter Your Chose:");
    fflush(stdin);
    while(scanf("%d",&z))
    {
        if(z==1 || z==2 || z==0)
        {
         if(z==1)
         {
            system("cls");
             search();
             break;
         }
         if(z==2)
         {
             system("cls");
             home();
             break;
         }
         if(z==0)
         {
             ext();
             break;
         }

        }
        else
        printf("\n\t\t\t\t INVALID INPUT READ OPTION CAREFULLY: ");
        fflush(stdin);
          }

            }









