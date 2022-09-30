#include <iostream>
#include <string>
using namespace std;

void generateReceipt(string userName)
{
    cout << "Receipt sent by mail to your address on file." << endl;
}

double withdrawMoney(double userBalance, int withdrawAmount)
{
    cout << "How much money do you want to withdraw? $";
    cin >> withdrawAmount;
    if(userBalance - withdrawAmount < 0)
    {
        cout << "You cannot withdraw this amount." << endl;;
    }
    else
    {
        userBalance = userBalance - withdrawAmount;
    }
    return userBalance;
}

int main()
{
    cout << "Hello world!" << endl;
    int userAge(0);
    string userName("No username");
    string userPass("password");
    cout << "Welcome to the login system. Please enter your username: ";
    getline(cin, userName);
    cout << "Please enter your password: ";
    cin >> userPass;
    cout << "Welcome " << userName << ". Please enter your age: ";
    cin >> userAge;
    cout << userName << ", you are " << userAge << " years old." << endl;
    string logOutCommand("y");
    int userCommand(0);
    double userBalance(99645.32);
    int withdrawAmount(0);
    int depositAmount(0);
    string receiptCommand("y");
    do
    {
        cout << "Your actual balance is: $" << userBalance << endl;
        cout << "Here is what you can do:\n1. Withdraw money\n2. Deposit money\n3. Contact your counselor\n4. Order a new card\n5. Order a new cheque\n6. Make a bank transfer\n7. Log out." << endl;
        cout << "Enter your choice (1/2/3/4/5/6/7): ";
        cin >> userCommand;
        switch (userCommand)
        {
        case 1:
            userBalance = withdrawMoney(userBalance, withdrawAmount);
            cout << "You have withdrawn $" << withdrawAmount << " from your account. Your new balance is: $" << userBalance << "." << endl;
            cout << "Do you want to generate a receipt (y/n)? ";
            cin >> receiptCommand;
            if (receiptCommand == "y")
            {
                generateReceipt(userName);
            }
            break;
        case 2:
            cout << "How much money do you want to deposit? $";
            cin >> depositAmount;
            userBalance = userBalance + depositAmount;
            cout << "You have deposited $" << depositAmount << " into your account. Your new balance is: $" << userBalance << "." << endl;
            break;
        case 7:
            cout << "Do you want to log out (y/n)? ";
            cin >> logOutCommand;
            if(logOutCommand == "y")
            {
                cout << "Logged out successfully. Good bye." << endl;
            }
            else
            {
                cout << "Remaining logged in." << endl;
            }
            break;
        default:
            cout << "Your command is unknown." << endl;
            break;
        }
    }
    while(logOutCommand != "y");

    return 0;
}
