#include<iostream>
#include"Account.h"

int main()
{
    Account myAccount1("Pauline .C. Chepkorir");

    myAccount1.inputPin();


    cin.ignore();
    cin.get();

    cout << endl;
    return 0;

}