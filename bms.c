#include <stdio.h>
#include <string.h>






struct bank {

char Name[20];
int account_number;
char Phone_Number[15];
float Balance;

};



 int Create_Account(struct bank *b, int *count)
{
    if (*count >= 100)
    {
        printf("Bank is full!\n");
        return 1;
    }

    while (getchar() != '\n');// get char reads one charecter from the keybaord

    printf("Enter your name: ");
    fgets(b[*count].Name, sizeof(b[*count].Name), stdin);
    b[*count].Name[strcspn(b[*count].Name, "\n")] = '\0';//strcspn is used to find the first accurance of a particular charector in the string 

    printf("Enter your account number: ");
    scanf("%d", &b[*count].account_number);

    printf("Enter your phone number: ");
    scanf("%14s", b[*count].Phone_Number);

    b[*count].Balance = 0;

    (*count)++;

    printf("Account created successfully!\n");

    return 0;
}




 
 int Display_All_Accounts(struct bank *b, int *count){
    for (int i=0 ;i<*count;i++){

        printf("%s\n %d\n %s\n %f\n",b[i].Name,b[i].account_number,b[i].Phone_Number,b[i].Balance );
        printf("---------------------------------------------------------------\n");

    
    }
return 0;
 }
 int Search_Account(struct bank *b, int *count){

    int accno;
    printf("Enter account number: ");
    scanf("%d",&accno);
   for (int i = 0; i < *count; i++)
{
    if (b[i].account_number == accno)
    {
        printf("%s\n%d\n%s\n%f\n",
               b[i].Name,
               b[i].account_number,
               b[i].Phone_Number,
               b[i].Balance);

        printf("----------------------------------\n");
        return 0;
    }
}

printf("Account not found!\n");
return 1;






 }
 int Deposite_Money(struct bank *b, int *count){

    int accno;
    float bal;


    printf("Enter your account number");
    scanf("%d",&accno);
    printf("Enter the amount to Deposite");
    scanf("%f",&bal);
    
    for (int i=0 ; i<*count;i++){

        if (b[i].account_number==accno){

            b[i].Balance+=bal;

            printf("your amount is deposited successfully ");

            printf("your updated balance is %f" , b[i].Balance);

            return 0;


        }
    }





printf("Account not found!\n");
return 1;

 }
 int Withdraw_Money(struct bank *b, int *count){
    int accno;
    float bal;


    printf("Enter your account number");
    scanf("%d",&accno);
    printf("Enter the amount to Withdraw");
    scanf("%f",&bal);
    
    for (int i = 0; i < *count; i++)
{
    if (b[i].account_number == accno)
    {
        if (b[i].Balance >= bal)
        {
            b[i].Balance -= bal;
            printf("The amount has been withdrawn successfully\n");
            printf("The remaining balance is %.2f\n", b[i].Balance);
            return 0;
        }
        else
        {
            printf("Insufficient balance!\n");
            return 1;
        }
    }
}

printf("Account not found!\n");
return 1;}
 


    


    






int Transfer_Money(struct bank *b, int *count){
    int from_accno;
    int to_accno;
    float bal;


    printf("Enter your account number to transfer money from \n");
    scanf("%d",&from_accno);
    printf("Enter the amount to transfer");
    scanf("%f",&bal);
    printf("Enter your account number to transfer money  to \n");
    scanf("%d",&to_accno);

    for (int i = 0; i < *count; i++)
{
    if (b[i].account_number == from_accno)
    {
        for (int j = 0; j < *count; j++)
        {
            if (b[j].account_number == to_accno)
            {
                if (b[i].Balance >= bal)
                {
                    b[i].Balance -= bal;
                    b[j].Balance += bal;

                    printf("The amount has been sent successfully.\n");
                    printf("The remaining balance is %.2f\n", b[i].Balance);

                    return 0;
                }
                else
                {
                    printf("Insufficient balance!\n");
                    return 1;
                }
            }
        }
    }
}

printf("Account not found!\n");
return 1;}







 int Update_Account(struct bank *b, int *count)
{
    int accno;

    printf("Enter account number: ");
    scanf("%d", &accno);

    for (int i = 0; i < *count; i++)
    {
        if (b[i].account_number == accno)
        {
            while (getchar() != '\n');

            printf("Enter new name: ");
            fgets(b[i].Name, sizeof(b[i].Name), stdin);
            b[i].Name[strcspn(b[i].Name, "\n")] = '\0';

            printf("Enter new phone number: ");
            scanf("%14s", b[i].Phone_Number);

            printf("Account updated successfully!\n");
            return 0;
        }
    }

    printf("Account not found!\n");
    return 1;
}



int Delete_Account(struct bank *b, int *count)
{
    int accno;

    printf("Enter account number: ");
    scanf("%d", &accno);

    for (int i = 0; i < *count; i++)
    {
        if (b[i].account_number == accno)
        {
            for (int j = i; j < *count - 1; j++)
            {
                b[j] = b[j + 1];
            }

            (*count)--;

            printf("Account deleted successfully!\n");
            return 0;
        }
    }

    printf("Account not found!\n");
    return 1;
}
int Save_to_File(struct bank *b, int *count)
{
    FILE *fp;

    fp = fopen("bank.txt", "w");

    if (fp == NULL)
    {
        printf("File could not be opened!\n");
        return 1;
    }

    fprintf(fp, "%d\n", *count);

    for (int i = 0; i < *count; i++)
    {
        fprintf(fp, "%s\n", b[i].Name);
        fprintf(fp, "%d\n", b[i].account_number);
        fprintf(fp, "%s\n", b[i].Phone_Number);
        fprintf(fp, "%f\n", b[i].Balance);
    }

    fclose(fp);

    printf("Data saved successfully!\n");

    return 0;
}



int Load_from_File(struct bank *b, int *count)
{
    FILE *fp;

    fp = fopen("bank.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    fscanf(fp, "%d\n", count);

    for (int i = 0; i < *count; i++)
    {
        fscanf(fp, "%[^\n]\n", b[i].Name);
        fscanf(fp, "%d\n", &b[i].account_number);
        fscanf(fp, "%14s\n", b[i].Phone_Number);
        fscanf(fp, "%f\n", &b[i].Balance);
    }

    fclose(fp);

    printf("Data loaded successfully!\n");

    return 0;
}


int main(void)
{
    struct bank b[100];
    int count=0;
    int choice;
    int breakable=1;
    while(breakable){
    printf("Welocome to banking management system\n");
    printf("Pls enter which operation do you want to perform\n1. Create Account\n2. Display All Accounts\n3. Search Account\n4. Deposit Money\n5. Withdraw Money\n6. Transfer Money\n7. Update Account\n8. Delete Account\n9. Save to File\n10. Load from File\n11. Exit\n Enter your choice\n");


    scanf("%d",&choice);


switch (choice)
{
    case 1:
        Create_Account(b, &count);
        break;

    case 2:
        Display_All_Accounts(b, &count);
        break;

    case 3:
        Search_Account(b, &count);
        break;

    case 4:
        Deposite_Money(b, &count);
        break;

    case 5:
        Withdraw_Money(b, &count);
        break;

    case 6:
        Transfer_Money(b, &count);
        break;

    case 7:
        Update_Account(b, &count);
        break;

    case 8:
        Delete_Account(b, &count);
        break;

    case 9:
        Save_to_File(b, &count);
        break;

    case 10:
        Load_from_File(b, &count);
        break;

    case 11:
       
        {
            printf("Thank you for using Banking Management System!\n");
             breakable=0;
        }
        break;

    default:
        printf("Invalid Choice!\n");
}

    }

    return 0;
}