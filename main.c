#include "myBank.c"
#include <stdio.h>
int currentNumOfBankAccounts=0; //NOTE:i wanted to use extern but i had a warning "extern initilaizer"
#define NumOfAccounts 50

int main(){
    char input;
    double amount=0;
    int id=0;
    float rate=0;
    while(input!='E'){//if the user input isnt E then the program should keep running
printf("Transaction type:\n");
scanf(" %c",&input);
if(input=='O'){//if the user want to open a bank account
    if(currentNumOfBankAccounts<NumOfAccounts){//and the accounts limit has not rached to 50
        printf("Initial deposit:\n");
        scanf("%lf",&amount);
      if(amount>=0){//the amount should be un-negative number
          openBankAccount(amount,currentNumOfBankAccounts);//create an account
          currentNumOfBankAccounts++;//increase the accounts number
      }
      else{
          printf("the amount should be un-negative number,please try again\n");
      }
    }
}
if(input=='B'){//if the user want to see his account balance
    printf("Account number?:\n");
    scanf(" %d",&id);
    if(isLigalID(id)!=1){//the account id can be between 901-950
        printf("invaild Account number, please try again\n");
    }
    else if(isOpen(id)!=1){//if this account is close
        printf("this account is close!\n");
    }
    else{
        myBalance(id);//print this account balance
    }
}
if(input=='D'){//if the user want to make a depoist
printf("Account number?:\n");
scanf(" %d",&id);
if(isLigalID(id)!=1){//there is no such account id
   printf("there is no such account id!\n");
}
else if(isOpen(id)!=1){//this account is close
printf("this account is close!\n");
}

else{
    printf("Amount?:\n");
    scanf(" %lf",&amount);
   if(amount<=0){//the amount should be positive number
   printf("the amount should be positive number,please try again\n");
}
   else{
     Deposit(amount,id);//deposit the amount into this bank account
}

}
}

if(input=='W'){//if the user want to withdrawal amount from the account
    printf("Account number?:\n");
    scanf(" %d",&id);
    if(isLigalID(id)!=1){//and the account id is ligal
        printf("invaild Account number, please try again\n");
    }
    else if(isOpen(id)!=1){//and the account is open
        printf("this account is close!\n");
    }
    else{
        printf("Amount?:\n");
        scanf(" %lf",&amount);
        if(amount>0&&amount<getBalance(id)){//and the amount is not lower then the balance
            withDrawal(amount,id);//withdrawal the amount from the account
        }
        else{
            printf("your balance is lower then your amount!\n");
        }
    }
    }


if(input=='C'){//if the user want to close this account
    printf("Account number?:\n");
    scanf("%d",&id);
    if(isLigalID(id)!=1){//and the account is ligal
        printf("invaild Account number, please try again\n");
    }
    else if(isOpen(id)!=1){//and open
         printf("this account is already close!\n");
    }
    else{
        closeBankAccount(id);//close this account
        printf("your account has been closed\n");
    }
}
if(input=='I'){//if the user want to insert a new rate
    printf("Interest rate?:\n");
    scanf("%f",&rate);
    insertRate(rate);
}
if(input=='P'){//print all the accounts
    printAllAccounts();
}
    }

    
    CloseAll();//close all the accounts(if the input=E)
return 0;

}