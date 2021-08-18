#include<iostream>
#include"Account.h"


double Account::accountBalance = 5000;

double Account::getAccountBalance()
{
    return accountBalance;
}
Account::Account(string name)

{
    setAccountName(name);

}
void Account::setAccountName(string name)
{
    if (name.length() <= 25)
    {
        accountName = name;
    }
    else
    {
        accountName = name.substr(0, 25);
        cout << "name\"" << name << "\"exceeds maximum length(25)." << "\nlimiting the name to 25 first characters." << endl;
    }
}
string Account::getAccountName()const
{
    return accountName;
}
void Account::creditAccount(double balance)
{

    accountBalance += balance;
}
void Account::debitAccount(double balance)
{
    if (balance <= accountBalance)
    {
        accountBalance -= balance;
    }
    else
    {
        cout << "\nThe debited amount exceeded the           account balance." << endl;
    }
}
void Account::inputPin()
{
    int pin;
    int count = 1;

    cout << "Enter pin:";
    cin >> pin;
    while (count <= 3)
    {
        switch (pin)
        {
        case 3315:
            displayMessage();
            display();
            break;


        default:

            ++count;
            cout << "\nYou entered a wrong pin." << "\nPlease try again.";
            break;
        }

        if (pin == 3315)
        {
            break;
        }
        cout << "\n\nEnter pin:";
        cin >> pin;

        switch (count)
        {
        case 4:

            cout << "\nYour account has been blocked." << "\nContact our offices for help.";
            break;
        }

    }

}

void Account::showMenu()
{
    cout << "********MENU********" << endl;
    cout << "1.Balance " << endl;
    cout << "2.Deposit " << endl;
    cout << "3.withdraw " << endl;
    cout << "4.exit " << endl;
    cout << "********************" << endl;
}
void Account::displayMessage()
{
    for (int row = 1; row <= 3; ++row)
    {
        for (int space = row; space <= 2; ++space)
        {
            cout << setw(5) << " ";
        }
        for (int column = 1; column <= row * 2 - 1; ++column)
        {
            cout << setw(5) << "$";
        }
        cout << endl;
    }



    cout << "\nWELCOME TO CBK" << " " << getAccountName() << "\n\n" << endl;

    int option;

    do
    {
        showMenu();
        cout << "Enter option: ";
        cin >> option;

        system("CLS");

        switch (option)
        {
        case 1:
            cout << endl << "Balance is " << "ksh." << getAccountBalance() << endl;
            break;
        case 2:
            double depositAmount;
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            creditAccount(depositAmount);

            break;
        case 3:
            double withdrawAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;

            debitAccount(withdrawAmount);
            break;

        }
    } while (option != 4);

}
void Account::display()
{
    cout << "\n\nCurrent Account Balance:" << getAccountBalance() << "\n\n THANK YOU FOR CHOOSING CBK.";
}
