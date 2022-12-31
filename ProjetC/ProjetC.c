#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
int login(char username[25], char passwords[8])
{
    if (!strcmp(username, "Meriem") && !strcmp(passwords, "jazz123"))
    {
        return 1;
    }
    else
        return 0;
}
struct item
{
    char name[40];
    int qty;
    float price;
};
struct item s;
char productname[40];
long int recsize;
int section() {
    int d;
    printf("\n\nHello Mrs.Meriem, Welcome to your Clothing Management System\n\nChoose which Section do you want to access ?\n\n#Enter Number 1 for Women's Section\n#Enter Number 2 for men's Section\n#Enter Number 3 for Children's Section");
    printf("\n\n Please enter your choice :- ");
    scanf("%d", &d);
    return d;
}
int main()
{
    FILE* fp, * ft;
    int i = 0, r = 0, count = 0, n;
    char username[25], passwords[8], ch, another, choice,c;
logout:
    fflush(stdin);
    count = 0;
    printf("\t\t\t\t\t\t\t   ==============================================\n\t\t\t\t\t\t\t   *WELCOME TO JAZZ'S CLOTHING MANAGEMENT SYSTEM*\n\t\t\t\t\t\t\t   ==============================================");
    printf("\t\t\t\t\t\t\t\t\t                                                            \n\t\t\t\t\t\t\t   TO ACCESS THE SYSTEM, PLEASE YOU NEED TO LOGIN FIRST \n\t\t\t\t\t\t\t   ==============================================");
    printf("\t\t\t\t\t\n\t");

    do {
        n=0;
        printf("\t\t\t\t\t           Enter Your Username:");
        gets(username);
        printf("\n\t\t\t\t\t\t\t   Enter Your Password:");
        while (n<7 && ( (c=getch())!='\r') )
         {
       passwords[n]=c;
       n++;
       printf("*");
       fflush(stdin);
          }
    passwords[n]='\0';

        r = login(username, passwords);
        count++;
        if (r) {
            printf("\t\t\t\t\t\t\t                                   ==============================================\n\t\t\t\t\t\t\t\t#ACCESS GRANTED#\n\n\n");
            break;
        }
        else
            printf("\n\n\t\t\t\t\t\tWRONG USERNAME/PASSWORD----------------ACCESS DENIED, TRY AGAIN :<\n\n\n\n");
    } while (count != 3);
    if (count == 3)
    {
        printf("\n\n/////ALL LOGIN ATTEMPTS FAILED.....PLEASE RESTART THE PROGRAM/////");
        getchar();
        return 0;
    }

switch (section()){
    struct item i;

        system("cls");
    case 1:
        fp = fopen("Women.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("Women.txt", "wb+");
            if (fp == NULL)
            {
                printf("Cannot open file");
                exit(1);
            }
        }
        recsize = sizeof(i);
        while (1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t   **********************************************\n\t\t\t\t\t\t\t*WELCOME TO WOMEN'S SECTION'S DATABASE*\n\t\t\t\t\t\t\t   **********************************************\n\n");
            printf("0. Find item\n");

            printf("1. Add new item to database\n");

            printf("2. Show all items & their descriptions\n");

            printf("3. Modify Item\n");

            printf("4. Delete Item\n");

            printf("5. Go to main menu :\n");

            printf("Your Choice : ");
            fflush(stdin);
            choice = getchar();
            switch (choice)
            {
            case '0':
                system("cls");
                another = 'y';

                while (another == 'y')
                {
                    printf(")->Enter item's name you're looking for :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\tQUANTITY\tRATE\n");
                    printf("\t\t\t\t\t\t\t\t\t____________________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t####################################\n");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1 )
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);

                        }
                    }
                    printf("\n**Look for another item??...(y/n)**");
                    fflush(stdin);
                    another = getchar();
                }

                break;
            case '1':

                system("cls");
                fseek(fp, 0, SEEK_END);
                another = 'y';
                while (another == 'y')
                {
                    printf("____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n)-> Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n)-> %s is available in quantity :- ", i.name);
                    scanf("%d", &i.qty);
                    printf("\n\n)-> Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp);
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n**Add another item ??---(y/n)** ");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\tQUANTITY\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t####################################\n");
                while (fread(&i, recsize, 1, fp) == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t#####################################################\n");
                getchar();
                getchar();

                break;

            case '3':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf(")->Enter item's name, which is to be modified :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n)->Enter new name,quantity and price :-\n");
                            scanf("%s%d%f", i.name, &i.qty, &i.price);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&i, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\n**Modify another item??...(y/n)**");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '4':
                system("cls");
                another = 'y';

                while (another == 'y')
                {
                    printf("\nEnter name of item to be deleted : ");
                    scanf("%s", productname);
                    ft = fopen("WomenTemp.txt", "wb");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) != 0)
                        {
                            fwrite(&i, recsize, 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Women.txt");
                    rename("WomenTemp.txt", "Women.txt");
                    fp = fopen("Women.txt", "rb+");
                    printf("Delete another item(y/n)");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '5':
                fclose(fp);
                system("cls");
                goto logout;
            }
        }


    case 2:
        fp = fopen("Men.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("Men.txt", "wb+");
            if (fp == NULL)
            {
                printf("Cannot open file");
                exit(1);
            }
        }


        recsize = sizeof(i);

        while (1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t   #####################################################\n\t\t\t\t\t\t\t\t*WELCOME TO MEN'S SECTION'S DATABASE*\n\t\t\t\t\t\t\t\t   #####################################################\n\n");
            printf("0. Find item\n");

            printf("1. Add new item to database\n");

            printf("2. Show all items & their descriptions\n");

            printf("3. Modify Item\n");

            printf("4. Delete Item\n");

            printf("5. Go to main menu :\n");

            printf(")>Your Choice : ");
            fflush(stdin);
            choice = getchar();
            switch (choice)
            {
            case '0':
                system("cls");
                another = 'y';

                while (another == 'y')
                {
                    printf(")->Enter item's name you're looking for :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\tQUANTITY\tRATE\n");
                    printf("\t\t\t\t\t\t\t\t\t____________________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t####################################\n");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1 )
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);

                        }
                    }
                    printf("\n**Look for another item??...(y/n)**");
                    fflush(stdin);
                    another = getchar();
                }

                break;
            case '1':
                system("cls");
                fseek(fp, 0, SEEK_END);

                another = 'y';
                while (another == 'y')
                {
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n)>Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n  %s is available in quantity :- ", i.name);
                    scanf("%d", &i.qty);
                    printf("\n\n)>Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp);
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n**Add another item?....(y/n)**");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\t     QUANTITY\t\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t#####################################################\n");
                while (fread(&i, recsize, 1, fp) == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t#####################################################\n");
                getchar();
                getchar();

                break;
            case '3':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf(")->Enter item's name, which is to be modified :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n)->Enter new name,quantity and price :- \n");
                            scanf("%s%d%f", i.name, &i.qty, &i.price);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&i, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\n**Modify another item?...(y/n)**");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\n)->Enter name of item to be deleted: ");
                    scanf("%s", productname);
                    ft = fopen("MenTemp.txt", "wb");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) != 0)
                        {
                            fwrite(&i, recsize, 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Men.txt");
                    rename("MenTemp.txt", "Men.txt");
                    fp = fopen("BOOK.txt", "rb+");
                    printf("Delete another item?...(y/n)");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '5':
                fclose(fp);
                system("cls");
                goto logout;
            }
        }
    case 3:
        fp = fopen("Children.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("Children.txt", "wb+");
            if (fp == NULL)
            {
                printf("Cannot open file");
                exit(1);
            }
        }
        recsize = sizeof(i);
        while (1)
        {
            system("cls");
            printf("\t\t\t\t\t\t\t   #####################################################\n\t\t\t\t\t\t\t*WELCOME TO CHILDREN'S SECTION'S DATABASE*\n\t\t\t\t\t\t\t   #####################################################\n\n");
            printf("0. Find item\n");

            printf("1. Add new item to database\n");

            printf("2. Show all items & their descriptions\n");

            printf("3. Modify Item\n");

            printf("4. Delete Item\n");

            printf("5. Go to main menu :\n");

            printf(")>Your Choice : ");
            fflush(stdin);
            choice = getchar();
            switch (choice)
            {
            case '0':
                system("cls");
                another = 'y';

                while (another == 'y')
                {
                    printf(")->Enter item's name you're looking for :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\tQUANTITY\tRATE\n");
                    printf("\t\t\t\t\t\t\t\t\t____________________________________\n");
                    printf("\t\t\t\t\t\t\t\t\t####################################\n");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1 )
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);

                        }
                    }
                    printf("\n**Look for another item??...(y/n)**");
                    fflush(stdin);
                    another = getchar();
                }

                break;
            case '1':
                system("cls");
                fseek(fp, 0, SEEK_END);


                another = 'y';
                while (another == 'y')
                {
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\n)>Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n)>%s is available in quantity :- ", i.name);
                    scanf("%d", &i.qty);
                    printf("\n\n)>Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp);
                    printf("\n____________________________________________________\n");
                    printf("#####################################################");
                    printf("\n\nAdd another item?...(y/n) ");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '2':
                system("cls");
                rewind(fp);
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\t     QUANTITY\t\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t#####################################################\n");
                while (fread(&i, recsize, 1, fp) == 1)
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.qty, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t#####################################################\n");
                getchar();
                getchar();

                break;

            case '3':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("Enter item's name, whose details are to be modified :- ");
                    scanf("%s", productname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) == 0)
                        {
                            printf("\nEnter new name,quantity and price :- ");
                            scanf("%s%d%f", i.name, &i.qty, &i.price);
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&i, recsize, 1, fp);
                            break;
                        }
                    }
                    printf("\nModify another item(y/n)");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\n)>Enter name of item to be deleted: ");
                    scanf("%s", productname);
                    ft = fopen("ChildrenTemp.txt", "wb");
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)
                    {
                        if (strcmp(i.name, productname) != 0)
                        {
                            fwrite(&i, recsize, 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Children.txt");
                    rename("ChildrenTemp.txt", "Children.txt");
                    fp = fopen("Children.txt", "rb+");
                    printf("Delete another item(y/n)");
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case '5':
                fclose(fp);
                system("cls");
                goto logout;
            }
        }
    default:
        printf("\n\nUNEXPECTED INPUT DETECTED\nREDIRECTING TO LOGIN PAGE.........................................");
        getchar();
        goto logout;
    }
    getchar();
    return 0;
}





