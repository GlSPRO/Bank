#include <iostream>
#include <Windows.h>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    // Конструктор с параметрами
    BankAccount(int accNumber, double initialBalance, double initialInterestRate) {
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = initialInterestRate;
    }

    // Функция для внесения средств на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Средства успешно зачислены.\n";
        }
        else {
            std::cout << "Ошибка: внесите сумму больше нуля.\n";
        }
    }

    // Функция для снятия средств со счета
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Средства успешно сняты.\n";
        }
        else {
            std::cout << "Ошибка: недостаточно средств на счете или сумма для снятия меньше или равна нулю.\n";
        }
    }

    // Функция для получения текущего баланса
    double getBalance() {
        return balance;
    }

    // Функция для расчета и возврата суммы процентов
    double getInterest() {
        return balance * interestRate * (1.0 / 12.0);
    }

    // Функция для обновления процентной ставки
    void setInterestRate(double rate) {
        interestRate = rate;
        std::cout << "Процентная ставка успешно обновлена.\n";
    }

    // Функция для получения процентной ставки
    double getInterestRate() {
        return interestRate;
    }

    // Функция для получения номера банковского счета
    int getAccountNumber() {
        return accountNumber;
    }

    // Дружественная функция для перевода средств между счетами
    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

// Реализация дружественной функции transfer
bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        std::cout << "Перевод успешно выполнен.\n";
        return true;
    }
    else {
        std::cout << "Ошибка: недостаточно средств на счете для перевода или сумма для перевода меньше или равна нулю.\n";
        return false;
    }
}

int main() {
    // Пример использования класса BankAccount
    BankAccount acc(123456, 1000.0, 0.05);
    SetConsoleCP(1251);
    setlocale(0, "");


    std::cout << "Начальный депозит: " << acc.getBalance() << std::endl;
    std::cout << "Изначальная процентная ставка: " << acc.getInterestRate() << std::endl;

    acc.setInterestRate(0.1); // 10% процентная ставка
    std::cout << "Баланс с учетом процентов: " << acc.getBalance() + acc.getInterest() << std::endl;

    double interest = acc.getInterest();
    std::cout << "Сумма накопленных процентов: " << interest << std::endl;
    acc.deposit(interest); // Зачисляем накопленные проценты на счет
    std::cout << "Баланс после зачисления накопленных процентов: " << acc.getBalance() << std::endl;

    return 0;
}






