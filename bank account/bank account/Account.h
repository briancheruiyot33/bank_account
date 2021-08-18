#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H


#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Account
{
private:
    string accountName;

    static double accountBalance;

public:
    Account(string);
    void setAccountName(string);
    string getAccountName()const;
    void creditAccount(double);
    void debitAccount(double);
    void inputPin();
    void showMenu();
    void displayMessage();
    void display();

    static  double getAccountBalance();

};

#endif