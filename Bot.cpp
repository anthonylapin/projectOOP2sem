//
//  Bot.cpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-10.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#include "Bot.hpp"
Bot::Bot()
{
    int choice;
    choice = rand() % 3;
    if(choice == 2)
    {
        card.Set_Name(passport.Get_Name());
        card.Set_Surname(passport.Get_Surname());
        int counter = 0;
        while(counter == 0)
        {
            passport.Set_ExpiryYear(rand() % 2030);
            card.Set_ExpiryYear(rand() % 2030);
            if((passport.Get_ExpiryYear() >= 2019) && (card.Get_ExpiryYear() >= 2019))
                counter = 1;
        }
        counter = 0;
        while(counter == 0)
        {
            card.Set_Situations(situations[ rand() % (sizeof(situations) / sizeof(situations[0]))]);
            if((card.Get_Situation() != "ZzZ") && (card.Get_Situation() != "欺詐者") && (card.Get_Situation() != " :) "))
                counter = 1;
        }
        counter = 0;
        while(counter == 0)
        {
            passport.Set_Birthday(rand() % 2000);
            if(passport.Get_Birthday() > 1940)
                counter = 1;
        }
        counter = 0;
        while(counter == 0)
        {
            passport.Set_Number(rand() % 999999);
            card.Set_Number(rand() % 999999);
            if(passport.Get_Number() >= 100000 && passport.Get_Number() <= 999999 && card.Get_Number() >= 100000 && card.Get_Number() <= 999999)
                counter = 1;
            
        }
    }
    Set_Cheater();
    
    
    
    
    
}

void Bot::Set_CardNameParameters(string name, string surname, unsigned int number, unsigned int expiry_year, unsigned int sum, string situation)
{
    cout << "Setting Insurance Card parameters." << endl;
    card.Set_Name(name);
    card.Set_Number(number);
    card.Set_Surname(surname);
    card.Set_ExpiryYear(expiry_year);
    card.Set_Situations(situation);
    card.Set_Sum(sum);
    
}
void Bot::Set_PassportParameters(string name, string surname, string nationality, unsigned int birthday, unsigned int number, unsigned int  expiry_year)
{
    cout << "Setting Passport Parameters." << endl;
        passport.Set_Name(name);
        passport.Set_Surname(surname);
        passport.Set_Nationality(nationality);
        passport.Set_Birthday(birthday);
        passport.Set_Number(number);
        passport.Set_ExpiryYear(expiry_year);
    
    
}
void Bot::print()
{
    cout << "Customer INFO:" << endl;
    passport.print();
    card.print();
    
}
bool Bot::Get_Cheater()
{
    return cheater;
    
}
void Bot::Set_Cheater()
{
    passport.Set_Cheater();
    card.Set_Cheater();
   if((passport.Get_Name() == card.Get_Name()) && (passport.Get_Surname() == card.Get_Surname()))
   {
       if((!passport.Get_Cheater()) && (!card.Get_Cheater()))
       {
           cheater = false;
       }
       else
           cheater = true;
   }
    else
        cheater = true;
        

}
string Bot::Get_Name()
{
    return passport.Get_Name() + " " + passport.Get_Surname();
}
