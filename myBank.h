void openBankAccount(double,int);
void myBalance(int);
void Deposit(double,int);
void withDrawal(double,int);
void closeBankAccount(int);
void insertRate(float);
void printAllAccounts();
void CloseAll();
double bankAccountStatus[50][3];
//auxiliary methods
void resetAccount(int);
int isOpen(int);
int isLigalID(int);
double getBalance(int);
extern int currentNumOfBankAccounts; 
