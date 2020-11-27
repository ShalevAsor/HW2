#include <stdio.h>
#include "myBank.h"
#define accID 0
#define AMOUNT 1
#define STATUS 2
#define NumOfAccounts 50
#define STARTID 901
#define ENDID 950


//this method create a bank account(only if the accounts number is under 50)
void openBankAccount(double amount,int id ){
    int accountID=901+id;//the accounts id is between 901-950 the input id is between 0-49(for the 2D array)
    bankAccountStatus[id][accID]=accountID;//the first line of this matrix represent the bank accounts id
    bankAccountStatus[id][AMOUNT]=amount;//the second line represent the amount
    bankAccountStatus[id][STATUS]=1;//the third line represent the account status (1=open,0=close)
    printf("your bank account id is: %d\n",accountID);
}
//this method print the current balance of the bank account with the given id
void myBalance(int accountID){
    int id=accountID-STARTID;//match the appropriate id in the 2D array
    printf("The balance of account number %d is:%0.2lf\n",accountID,bankAccountStatus[id][AMOUNT]);
}
//this metohd allows to the user to make deposit into the bank account with the given id
void Deposit(double amount,int accountID){
    int id=accountID-STARTID;
    bankAccountStatus[id][AMOUNT]+=amount;//add the new amount to this account
    printf("the current balance of your account is:%0.2lf\n",bankAccountStatus[id][AMOUNT]);
}
//this method allows to the user to withdrawal money from his account and print the new balance
void withDrawal(double amount,int accountID){
    int id=accountID-STARTID;
    bankAccountStatus[id][AMOUNT]-=amount;
    printf("The new balance is:%0.2lf\n",bankAccountStatus[id][AMOUNT]);
}
//this method close the bank account with the given key
void closeBankAccount(int accountID){
    int id=accountID-STARTID;
    resetAccount(id);
}
//this method updating the amount by the give rate
void insertRate(float rate){
    
    for(int i=0;i<NumOfAccounts;i++){
        if(bankAccountStatus[i][STATUS]!=0){//if this account is open
           bankAccountStatus[i][AMOUNT]*=(1+(rate/100));
        }
    }
}
//this method print all the open accounts amount
void printAllAccounts(){
for(int i=0;i<NumOfAccounts;i++){
    if(bankAccountStatus[i][STATUS]!=0){// the meaning is that account is open
    printf("the balance of account number:%0.0f is:%0.2lf\n",bankAccountStatus[i][accID],bankAccountStatus[i][AMOUNT]);
   }
 }
}

//this method close all the bank accounts that are still open
void CloseAll(){
    for(int i=0;i<NumOfAccounts;i++){
        if(bankAccountStatus[i][STATUS]!=0){
            resetAccount(i);
        }
    }
}

//this method reset the bank accout (not in the interface )/auxiliary method
void resetAccount(int id){
    bankAccountStatus[id][STATUS]=0;//close this account
    bankAccountStatus[id][AMOUNT]=0;//resent the amount
    bankAccountStatus[id][accID]=0;//reset the accountID
}

//this method return 1 if this account is open, else return 0
int isOpen(int accountID){
    int id=accountID -STARTID;
    if(bankAccountStatus[id][STATUS]==1){
        return 1;
    }
    else{
        return 0;
    }
}
//this method return 1 if this id is ligal (901,950) else return 0
int isLigalID(int ID){
    if(ID>=STARTID&&ID<=ENDID){
        return 1;
    }
    else{
        return 0;
    }
}
//this method return the current balance of this bank account
double getBalance(int accountID){
    int id=accountID-STARTID;
    return bankAccountStatus[id][AMOUNT];
}
