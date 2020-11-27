#include "myBank.c"
#include <stdio.h>

int currentNumOfBankAccounts=0; //NOTE:i wanted to use extern but i had a warning "extern initilaizer"
#define NumOfAccounts 50

int main(){
    char input;
    double amount=0;
    int id=0;
    float rate=0;

    printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    while(input!='E'){
    if(scanf(" %c", &input)==1){
    switch(input){
        case 'O':
         if(currentNumOfBankAccounts<NumOfAccounts){//and the accounts limit has not rached to 50
        printf("Please enter amount for deposit:");
       if( scanf("%lf", &amount)==1&&amount>0){//the amount should be un-negative number
          openBankAccount(amount,currentNumOfBankAccounts);//create an account
          currentNumOfBankAccounts++;//increase the accounts number by one
      }
      else{
          printf("Faild to read the amount\n");
          
      }//reprint for the next transaction 
      printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
         }
    break;
    case 'B':
    printf("Please enter account number:");
     scanf(" %d", &id);
    if(isLigalID(id)!=1){//the account id can be between 901-950
        printf("Faild to read the account number\n");
    }
    else if(isOpen(id)!=1){//if this account is close
        printf("This account is closed\n");
    }
    else{
        myBalance(id);//print this account balance
    }
    printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    break;
    case 'D':
    printf("Please enter account number:");
    if(scanf(" %d", &id)!=-1){
    if(isLigalID(id)!=1){//there is no such account id
     printf("Faild to read account number:\n");}
    else if(isOpen(id)!=1){//this account is close
    printf("This account is closed\n");
    }
    else{
    printf("Please enter amount for deposit:");
    scanf(" %lf",&amount);
   if(amount<=0){//the amount should be positive number
   printf("the amount should be positive number,please try again\n");
    }
   else{
     Deposit(amount,id);//deposit the amount into this bank account
    }
    }}
    else{
         printf("Faild to read the account number\n");
    }
     printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    break;
    case 'W':
    printf("Please enter account number:");
    scanf(" %d", &id);
    if(isLigalID(id)!=1){//and the account id is ligal
        printf("Faild to read the account number\n");
    }
    else if(isOpen(id)!=1){//and the account is open
        printf("this account is close!\n");
    }
    else{
        printf("Please enter amount to withdraw:");
        scanf(" %lf", &amount);
        if(amount>0&&amount<getBalance(id)){//and the amount is not lower then the balance
            withDrawal(amount,id);//withdrawal the amount from the account
        }
        else{
            printf("Cannot withdraw more than the balance\n");
        }
    }
    printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    break;
    case 'C':
     printf("Please enter account number:");
      scanf("%d",&id);
    if(isLigalID(id)!=1){//and the account is ligal
        printf("Faild to read the account number\n");
    }
    else if(isOpen(id)!=1){//and open
         printf("this account is already close!\n");
    }
    else{
        closeBankAccount(id);//close this account
        currentNumOfBankAccounts--;//decrease the accounts number
        printf("your account has been closed\n");
    }
    printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    break;
    case 'I':
      printf("please enter interest rate:\n");
     if(scanf("%f", &rate)==1){//verify that the input is a number
     insertRate(rate);
     printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");}
     else{
         printf("Faild to read the inerest\n");
     }
     printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
     break;

     case 'P':
     printAllAccounts();
     printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
     break;

     default:
     printf("Faild to read the transaction\n");
     printf("please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposite\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
      break;


}
}
}
    CloseAll();//close all the accounts(if the input=E)
    return 0;

}
