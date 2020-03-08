#include "Level.hpp"
int Level::Count = 0;

/*Level::Level(int botnumber, int level_num)
{
    if(botnumber < 1 || level_num < 1)
    {
        cout << endl << "Wrong number of bots. Try again." << endl;
    }
    else
    {
        cout << "level " << level_num << "sucessfully added." << endl;
        level_no = level_num;
        bot_number = botnumber;
       // Set_BotNumber();
        cout << "You can add no more than "<< bot_number << " bots" << endl;
        
        //Set_Bots();
    }
}
void Level::add_bot(string insurance_name, string insurance_surname, unsigned int insurance_number, unsigned int insurance_expiry_year, unsigned int insurance_sum, string insurance_situation, string passport_name, string passport_surname, string passport_nationality, unsigned int passport_birthday, unsigned int passport_number, unsigned int passport_expiry_year)
{
    if(insurance_number < 100000 || insurance_number > 999999 || passport_number < 100000 || passport_number > 999999 || insurance_expiry_year < 2019 || insurance_expiry_year > 2030 || passport_expiry_year < 2019 || passport_expiry_year > 2030 || passport_number < 100000 || passport_number > 999999 || insurance_sum < 1 || passport_birthday < 1900 || passport_birthday > 2018 || passport_name != insurance_name || passport_surname != insurance_surname)
    {
        cout << "Wrong parameters." << endl;
    }
    else
    {
        
        if(bot_number < 1)
        {
            cout << "You cannot add more bots to this level" << endl;
        }
        else
        {
            bot_number--;
            cout << "You can add " << bot_number << " bots to this level" << endl;
            cout << "Bot sucessfully added." << endl;
            Bot bot1;
            bot1.Set_CardNameParameters(insurance_name, insurance_surname, insurance_number, insurance_expiry_year, insurance_sum, insurance_situation);
            bot1.Set_PassportParameters(passport_name, passport_surname, passport_nationality, passport_birthday, passport_number,  passport_expiry_year);
            bots.push_back(bot1);
        }
        
        
    }
}*/
Level::Level()
{
    Set_Parameters();
    //start();
}
void Level::Set_Parameters() // setting level parameters
{
    Count++;
    id = Count;
    Set_BotNumber();
    
    
}
int Level::GetID()
{
    return id;
}
void Level::Set_BotNumber()
{
    if(id == 1)
        bot_number = 4;
    else if(id == 2)
        bot_number = 5;
    else
    {
        if((id % 2) == 0)
            bot_number = id * 2 - 2;
        else
            bot_number = id * 2 - 1;
    }
}
void Level::Set_Bots()
{
    for(int i = 0; i < bot_number; i++)
    {
        Bot bot;
        bots.push_back(bot);
    }
}

int Level::Get_BotSize()
{
    return bot_number;
}


void Level::start()
{
    if(bots.size() == 0)
    {
        cout << "Cannot start level without bots on it =)" << endl;
    }
    else
    {
        int right = 0, wrong = 0;
        int choice;
        for(int i = 0; i < bot_number; i++)
        {
            cout << "New customer entered your office. Check him out.\n";
            bots[i].print();
            cout << "1.APPROVE\t2.REJECT" << endl;
            cout << "Your choice: ";
            int counter = 0;
            cin >> choice;
            while(counter == 0)
            {
                if(choice == 1 || choice == 2)
                    counter = 1;
                else if(choice != 1 || choice != 2)
                {
                    cout << "\nTry again!\n";
                    if(!cin.good())
                    {
                        //cout << "Not an integer." << endl;
                        cin.clear();
                        cin.ignore(2147483647, '\n'); // NB: preferred method for flushing cin
                    }
                    cin >> choice;
                    cout << endl;
                }
            }
            
            if(choice == 1)
            {
                if(!bots[i].Get_Cheater())
                {
                    cout << "YOU OBTAIN 10$!" << endl;
                    right++;
                }
                else
                {
                    cout << "YOU LOST 10$!" << endl;
                    wrong++;
                }
                
            }
            else if(choice == 2)
            {
                if(bots[i].Get_Cheater())
                {
                    cout << "YOU OBTAIN 10$!" << endl;
                    right++;
                }
                else
                {
                    cout << "YOU LOST 10$!" << endl;
                    wrong++;
                }
            }
        }
        cout << "You have done " << right << " correct cases and " << wrong << " incorrect cases." << endl;
        cout << "You have to pay taxes:\n" << "5$ FOR LIGHT\n" << "5$ FOR FOOD\n";
        Set_ObtainedSkill(right, wrong);
        Obtain(right, wrong);
    }
    
    
    
    
}


void Level::Obtain(int right, int wrong)
{
    obtained_money = Taxes(right*10 - wrong*10);
}
int Level::Taxes(int s)
{
    s = s - 10;
    return s;
}



void Level::Set_ObtainedSkill(int right, int wrong)
{
    ( right / (right + wrong) ) > 0.6 ? obtained_skill = 0.1: obtained_skill = 0;
}
double Level::Get_ObtainedSkill(){
    return obtained_skill;
}


int Level::Get_ObtainedMoney()
{
    return obtained_money;
}
unsigned int Level::Right(unsigned int right)
{
    return right;
}
unsigned int Level::Wrong(unsigned int wrong)
{
    return wrong;
}


Level::~Level()
{
    bots.clear();
}
void Level::print()
{
    if(bots.size() == 0)
    {
        cout << "there is no bots in this level." << endl;
    }
    for(int i = 0; i < bots.size() ; i++)
    {
        bots[i].print();
    }
}
void Level::remove_bot(string name)
{
    for(int i = 0; i < bot_number; i++)
    {
        if(name == bots[i].Get_Name())
        {
            bots.erase(bots.begin() + i);
            cout << "Bot deleted." << endl;
            break;
        }

    }
}
