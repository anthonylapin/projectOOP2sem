//
//  BotPassport.cpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#include "BotPassport.hpp"
BotPassport::BotPassport(string name, string surname, string nationality, unsigned int birthday, unsigned int number, unsigned int expiry_year)
{
    this->name = name;
    this->surname = surname;
    this->nationality = nationality;
    this->birthday = birthday;
    this->number= number;
    this->expiry_year = expiry_year;
    cout << "Bot_Passport sucessfully added!" << endl;
}

BotPassport::BotPassport(): name(names[rand() % (sizeof(names) / sizeof(names[0])) ]), surname(surnames[rand() % (sizeof(surnames) / sizeof(surnames[0]))]), nationality(nationalities[ rand() % (sizeof(nationalities) / sizeof(nationalities[0]))])
{
    
    int counter = 0;
    while(counter == 0)
    {
       birthday = rand() % 3000;
       if(birthday > 1900 && birthday < 2010)
       {
           counter = 1;
       }
    }
    counter = 0;
    while(counter == 0) // generating bot passport_number
    {
        number = rand() % 10000000;
        if(number > 99999)
        {
            counter = 1;
        }
    }
    counter = 0;
    while(counter == 0)
    {
        expiry_year = rand() % 3000;
        if(expiry_year > 2005 && expiry_year < 2030)
        {
            counter = 1;
        }
    }
    
}
void BotPassport::print()
{
    
    cout << "----------------------------------------------------------" << endl;
    cout  << "Passport" << endl;
    cout << "Name" << setw(24) << name << endl;
    cout << "Surname" << setw(21) << surname << endl;
    cout << "Nationality" << setw(17) << nationality << endl;
    cout << "Birthday year" << setw(15) << birthday << endl;
    cout << "Number" << setw(22) << number << endl;
    cout << "Expiry year" << setw(17) << expiry_year << endl;
    cout << "----------------------------------------------------------" << endl;

}
string BotPassport::Get_Name()
{
    return name;
}
string BotPassport::Get_Surname()
{
    return surname;
}
unsigned int BotPassport::Get_Birthday()
{
    return birthday;
}
string BotPassport::Get_Nationality()
{
    return nationality;
}
unsigned int BotPassport::Get_Number()
{
    return number;
}
unsigned int BotPassport::Get_ExpiryYear()
{
    return expiry_year;
}


void BotPassport::Set_ExpiryYear(unsigned int y)
{
    expiry_year = y;
}
void BotPassport::Set_Birthday(unsigned int b)
{
    birthday = b;
}
void BotPassport::Set_Name(string n)
{
    name = n;
}
void BotPassport::Set_Surname(string s)
{
    surname = s;
}
void BotPassport::Set_Nationality(string n)
{
    nationality = n;
}
void BotPassport::Set_Cheater()
{
    if((expiry_year < 2019) && (number < 100000 || number > 999999) && (birthday < 1909 || birthday > 2001))
        cheater = true;
    else
        cheater = false;
}
bool BotPassport::Get_Cheater()
{
    return cheater;
}
void BotPassport::Set_Number(unsigned int n)
{
    number = n;
}
