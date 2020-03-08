//
//  BotPassport.hpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#ifndef BotPassport_hpp
#define BotPassport_hpp
#include <iomanip>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Color.hpp"
using namespace std;
static const string names[20] = {"Jeremy", "Addison", "Marshall", "Michael", "John", "Calvin", "Lionel", "Dominik", "Tanvin", "Anna", "Katerina", "Andrea", "Rafael", "Rodger", "Bogdan", "Jughead", "Emily", "Barley", "Bobby", "Brayden" };
static const string surnames[] = {"Anderton", "Timlin", "Allen", "White", "Green", "Hailey", "Blackwood", "Bristol", "Lanester", "Snow", "Lincoln", "Milton", "Elton", "Ramsey", "Dayton", "Digby", "Oakley" };
static const string nationalities[] = { "Argentinian", "Armenian", "Bulgarian", "Canadian", "Chinese", "Colombian", "Congolese", "Croatian", "English", "Polish", "American", "German", "French", "Ukranian", "Canadian"};
class BotPassport
{
private:
    string name;
    string surname;
    string nationality;
    unsigned int birthday;
    unsigned int number; // passport number
    unsigned int expiry_year; // expiry date
    bool cheater;
public:
    BotPassport(string name, string surname, string nationality, unsigned int birthday, unsigned int number, unsigned int expiry_year);
    BotPassport();
    string Get_Name();
    string Get_Surname();
    unsigned int Get_Birthday();
    string Get_Nationality();
    unsigned int Get_Number();
    unsigned int Get_ExpiryYear();
    bool Get_Cheater();
    void Set_Cheater();
    void print();
    void Set_ExpiryYear(unsigned int y);
    void Set_Birthday(unsigned int b);
    void Set_Number(unsigned int n);
    void Set_Name(string n);
    void Set_Surname(string s);
    void Set_Nationality(string n);
    
};
#endif /* BotPassport_hpp */
