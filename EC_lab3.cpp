#include <iostream>
#include <iomanip>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    virtual void displayDetails() const {
        std::cout << "Account Details for Account (ID: " << accountNumber << "):\n";
        std::cout << "Holder: " << accountHolder << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }

    std::string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "Interest Rate: " << std::fixed << std::setprecision(2) << (interestRate * 100) << "%\n";
    }

    void withdraw(double amount) override {
        const double minBalance = 100;  // Minimum balance requirement for savings account
        if (balance - amount >= minBalance) {
            balance -= amount;
        } else {
            std::cout << "Withdrawal failed. Minimum balance requirement not met.\n";
        }
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "Overdraft Limit: $" << std::fixed << std::setprecision(2) << overdraftLimit << "\n";
    }

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
        } else {
            std::cout << "Withdrawal failed. Overdraft limit exceeded.\n";
        }
    }
};

CurrentAccount operator+(CurrentAccount& current, SavingsAccount& savings) {
    double transferAmount = 300;
    if (savings.getBalance() >= transferAmount) {
        current.deposit(transferAmount);
        savings.withdraw(transferAmount);
    } else {
        std::cout << "Transfer failed. Insufficient funds in Savings account.\n";
    }
    return current;
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << "Account Details for Account (ID: " << acc.getAccountNumber() << "):\n";
    os << "Holder: " << acc.getAccountHolder() << "\n";
    os << "Balance: $" << std::fixed << std::setprecision(2) << acc.getBalance() << "\n";
    return os;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);
    
    std::cout << "Account Details after deposit and withdrawal:\n";

    savings.displayDetails();
    current.displayDetails();

    current = current + savings;
    
    std::cout << "Account Details after transfer:\n";

    savings.displayDetails();
    current.displayDetails();

    return 0;
}