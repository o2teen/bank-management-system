#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char name[50];
    double balance;
};

struct BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Cannot create more accounts.\n");
        return;
    }

    struct BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1;

    printf("Enter account holder's name: ");
    scanf(" %[^
]s", newAccount.name);

    printf("Enter initial balance: ");
    scanf("%lf", &newAccount.balance);

    accounts[accountCount++] = newAccount;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

// Function to deposit money into an account
void depositMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    accounts[accountNumber - 1].balance += amount;
    printf("Deposit successful! New balance: %.2lf\n", accounts[accountNumber - 1].balance);
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrawal successful! New balance: %.2lf\n", accounts[accountNumber - 1].balance);
}

// Function to check account balance
void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Invalid account number.\n");
        return;
    }

    struct BankAccount account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: %.2lf\n", account.balance);
}

// Function to list all accounts
void listAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\nList of Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        struct BankAccount account = accounts[i];
        printf("Account Number: %d, Name: %s, Balance: %.2lf\n", account.accountNumber, account.name, account.balance);
    }
}

int main() {
    int choice;

    printf("Bank Management System\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                listAccounts();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
