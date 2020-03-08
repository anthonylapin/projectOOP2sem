//
//  Bot_InsuranceCard.cpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#include "Bot_InsuranceCard.hpp"
InsuranceCard::InsuranceCard(string name, string surname, unsigned int number, unsigned int expiry_year, unsigned int sum, string situation)
{
    if((number < 100000 && number > 999999) || (expiry_year < 2000 || expiry_year > 2030) || (sum < 1))
    {
        cout << "Wrong Parameters." << endl;
    }
    else
    {
        this->name = name;
        this->surname = surname;
        this->number = number;
        this->expiry_year = expiry_year;
        this->sum = sum;
        this->situation = situation;
    }
}
InsuranceCard::InsuranceCard():name(names1[rand() % (sizeof(names1) / sizeof(names1[0])) ]), surname(surnames1[rand() % (sizeof(surnames1) / sizeof(surnames1[0]))]), situation(situations[ rand() % (sizeof(situations) / sizeof(situations[0]))])
{
    int counter = 0;
    while(counter == 0)
    {
        number = rand() % 1000000;
        if(number > 9999)
        {
            counter = 1;
        }
    }
    
    counter = 0;
    while(counter == 0)
    {
        expiry_year = rand() % 2026;
        if(expiry_year > 2005)
        {
            counter = 1;
        }
    }
    
    counter = 0;
    while(counter == 0)
    {
        sum = rand() % 1000000;
        if(sum > 1000)
        {
            counter = 1;
        }
        
    }
    
    
}

void InsuranceCard::print()
{
    cout << "----------------------------------------------------------" << endl;
    cout << "Insurance Card" << endl;
    cout << "Name" << setw(24) << name << endl;
    cout << "Surname" << setw(21) << surname << endl;
    cout << "ID" << setw(26) << number << endl;
    cout << "Expiry year" << setw(17) << expiry_year << endl;
    cout << "Sutuation" << setw(19) << situation << endl;
    cout << "Obtained money" << setw(13) << sum << "$" << endl;
    cout << "----------------------------------------------------------" << endl;
}

string InsuranceCard::Get_Name()
{
    return name;
}

string InsuranceCard::Get_Surname()
{
    return surname;
}

string InsuranceCard::Get_Situation()
{
    return situation;
}
unsigned int InsuranceCard::Get_Number()
{
    return number;
}
unsigned int InsuranceCard::Get_ExpiryYear()
{
    return expiry_year;
}
unsigned int InsuranceCard::Get_Sum()
{
    return expiry_year;
}


void InsuranceCard::Set_Name(string n)
{
    name = n;
}
void InsuranceCard::Set_Surname(string n)
{
    surname = n;
}
void InsuranceCard::Set_ExpiryYear(unsigned int y)
{
    expiry_year = y;
}
void InsuranceCard::Set_Situations(string s)
{
    situation = s;
}
void InsuranceCard::Set_Cheater()
{
    if((expiry_year < 2019) && ((number < 100000) || (number > 999999)) && ((situation == "ZzZ") || (situation == "欺詐者") || (situation == " :) ")) )
        cheater = true;
    else
        cheater = false;
}
bool InsuranceCard::Get_Cheater()
{
    return cheater;
}
void InsuranceCard::Set_Number(unsigned int n)
{
    number = n;
}
void InsuranceCard::Set_Sum(unsigned int s)
{
    sum = s;
}
