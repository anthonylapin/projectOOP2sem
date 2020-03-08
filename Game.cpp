//
//  Game.cpp
//  ProjectOOP
//
//  Created by Anton Lapin on 2019-05-11.
//  Copyright © 2019 Anton Lapin. All rights reserved.
//

#include "Game.hpp"
Game::Game()
{
    preview();
    slow_print("Loading game...\n\n\n",80);
    slow_print("Generating levels...\n\n\n",80);
    Set_Levels();
    Set_Player();
}
void Game::Set_Player()
{
    player = new Player;
    player->Set_UserName();
    slow_print("Your username is " + player->Get_UserName() + "\n\n", 50);
}
void Game::preview()
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
    slow_print("  __ _| | (_) __ _ _ __  ____",5);
    cout<<endl;
    slow_print(" / _` | | | |/ _` | '_ \\|_  /",5);
    cout<< endl;
    slow_print("| (_| | | | | (_| | | | |/ /",5);
    cout<< endl;
    slow_print(" \\__,_|_|_|_|\\__,_|_| |_/___|",5);
    cout<<endl<<endl;
    slow_print("  _",20);
    cout << endl;
    slow_print(" (_)_ __  ___ _   _ _ __ __ _ _ __   ___ ___",5);
    cout << endl;
    slow_print(" | | '_ \\/ __| | | | '__/ _` | '_ \\ / __/ _ \\", 5);
    cout<< endl;
    slow_print(" | | | | \\__ \\ |_| | | | (_| | | | | (_|  __/",5);
    cout << endl;
    slow_print(" |_|_| |_|___/\\__,_|_|  \\__,_|_| |_|\\___\\___|",5);
    cout << endl << endl;
    slow_print("  ___ ___  _ __ ___  _ __   __ _ _ __  _   _", 5);
    cout << endl;
    slow_print(" / __/ _ \\| '_ ` _ \\| '_ \\ / _` | '_ \\| | | |", 5);
    cout << endl;
    slow_print("| (_| (_) | | | | | | |_) | (_| | | | | |_| |",5);
    cout << endl;
    slow_print(" \\___\\___/|_| |_| |_| .__/ \\__,_|_| |_|\\__, |",5);
    cout << endl;
    slow_print("                    |_|                |___/", 5);
    cout << endl << endl;
    string message = "Dear Player, welcome to the game!\nFirst of all, write your nickname in format NAME SURNAME.\n";
    slow_print(message, 50);
}
void Game::rules()
{
    
    slow_print("\t\t\t\t\t GAME RULES\n", 10);
    slow_print("\nYou are playing role play game where your role is a worker in insurance company called Allianze. You are serving the customers, who come to you to obtain money for their insurance. In each day of your work there are different number of people. They’re showing you their passports and insurance cards. If everything is good, you can approve them and give them money for their insurance case. But due to the calibre, respectability and status of your company, there are lots of fraud people who want to cheat and get money for fake insurance. These ones you have to reject. If you was wrong in your decision and you reject right people or approve cheaters, you will obtain penalties. One penalty costs you 10$. For every right decision you also get 10$. At the end of each day you will get your salary taking into account taxes for light in your office and food for you.\n1.Go back to menu.\n",5);
}

void Game::start()
{
    for(int i = 0; i < levels.size(); i++)
    {
        slow_print("DAY " + to_string(levels[i].GetID()), 50);
        levels[i].Set_Bots();
        slow_print("\nToday you have " + to_string(levels[i].Get_BotSize()) + " customers.\n", 50);
        levels[i].start();
        player->Set_Skill(levels[i].Get_ObtainedSkill());
        if(levels[i].Get_ObtainedSkill() != 0)
        {
            slow_print("\nYOU HAVE BOOSTED YOUR SKILL ON 0.1!\n", 50);
            
        }
        player->Set_Savings(levels[i].Get_ObtainedMoney());
        cout << endl;
        slow_print(player->print(),50);
        if(player->Get_Savings() < 0)
        {
            slow_print( "GAME OVER! YOU LOST!\n", 40);
            break;
        }
    }
    GameOver();
    remove_playerInfo();
    
 /*slow_print("\n1.Back to menu\n", 10);
    int choice;
    do
    {
        cin >> choice;
        if(choice == 1)
        {
            menu();
        }
        if(choice != 1)
        {
            slow_print("\nTry again!\n",50);
            if(!cin.good())
            {
                //cout << "Not an integer." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin
            }
        }
        
    }while(choice != 1);*/
    
}



void Game::menu()
{
    unsigned int choice;
    slow_print("\t\t\t\t\t\t MENU\n", 50);
    slow_print("Choose one of the possible options:\n",50);
    slow_print("1.Start the game.\n", 50);
    slow_print("2.Player's information.\n", 50);
    slow_print("3.Rules.\n",50);
    slow_print("4.Quit.\n",50);
    slow_print("Choice: ", 50);
    do
    {
        cin >> choice;
        if(choice == 1)
        {
            start();
            break;
            
            
        }
        else if(choice == 2)
        {
            slow_print(player->print(), 50);
            slow_print("\n1.Return to menu.\nChoice: ",50);
            do
            {
                cin >> choice;
                if(choice == 1)
                {
                    menu();
                }
                if(choice != 1)
                {
                    slow_print("\nTry again!\n", 50);
                    if(!cin.good())
                    {
                      //  cout << "Not an integer." << endl;
                        cin.clear();
                        cin.ignore(2147483647, '\n'); // NB: preferred method for flushing cin
                    }
                }
            }while(choice != 1);
            
        }
        else if(choice == 3)
        {
            rules();
            slow_print("\n1.Return to menu.\nChoice: ",50);
            do
            {
                cin >> choice;
                if(choice == 1)
                {
                    menu();
                }
                if(choice != 1)
                {
                    slow_print("\nTry again!\n", 50);
                    if(!cin.good())
                    {
                        //  cout << "Not an integer." << endl;
                        cin.clear();
                        cin.ignore(2147483647, '\n'); // NB: preferred method for flushing cin
                    }
                }
            }while(choice != 1);
        }
        else if(choice == 4)
        {
            break;
            //exit(0);
        }
        //else if(
        else
        {
            slow_print("\nTry again!\n", 50);
            if(!cin.good())
            {
               // cout << "Not an integer." << endl;
                cin.clear();
                cin.ignore(2147483647, '\n'); // NB: preferred method for flushing cin
            }
        }
    }
    while((choice != 1) || (choice != 2) || (choice != 3) || (choice != 4));
}

void Game::slow_print(const string& message, unsigned int millis_per_char)
{
    for (const char c: message)
    {
        // flush is used to make sure the buffer is emptied to the terminal immediately
        cout << c << flush;
        
        // Ask the thread to sleep for at least n millis.
        sleep_for(milliseconds(millis_per_char));
    }
}
void Game::Set_Levels()
{
    int levelNo = 5;
    for(int i = 0; i < levelNo; i++)
    {
        Level level;
        levels.push_back(level);
    }
}
void Game::GameOver()
{
    slow_print("GAME OVER!\nGAME RECORDS:\n", 20);
    slow_print("OBTAINED MONEY IN TOTAL: " + to_string(player->Get_Savings()) + "$",20);
    slow_print("\nTHANK YOU FOR PLAYING GAME!\nCreated by Anton Lapin on 2019\nCopyright @ 2019 Anton Lapin. All rights reserved." ,20);
    slow_print("\n........................\n", 20);
}
void Game::playerInfo()
{
    slow_print(player->print(), 30);
}
void Game::remove_playerInfo()
{
    slow_print("Deleting player's records.", 10);
    player->Set_DefaultParameters();
}
Game::~Game()
{
    cout << endl << "Quiting game.........." << endl;
    delete player;
    levels.clear();
}
