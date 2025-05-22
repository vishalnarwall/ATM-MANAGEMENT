#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class ATM
{
private:
    double balance;

public:
    ATM() : balance(0.0) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Successfully deposited: $" << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void checkBalance()
    {
        cout << "Current balance: $" << balance << endl;
    }
};

int main()
{

    string correctPIN = "1234";
    string enteredPIN;

    cout << "Enter your PIN: ";
    cin >> enteredPIN;

    if (enteredPIN != correctPIN)
    {
        cout << "Incorrect PIN. Access denied." << endl;
        return 0;
    }

    srand(time(0));
    int otp = rand() % 900000 + 100000;

    cout << "\nOTP sent (for demo): " << otp << endl;

    int enteredOTP;
    cout << "Enter the OTP: ";
    cin >> enteredOTP;

    if (enteredOTP == otp)
    {

        ATM atm;
        int choice;
        double amount;

        do
        {
            cout << "\nATM Menu:\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != 4);
    }
    else
    {
        cout << "Incorrect OTP Access denied";
    }
    return 0;
}