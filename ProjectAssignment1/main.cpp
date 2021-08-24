
#include <iostream>
#include "BaseClass.h"
#include "Warrior.h"
#include "Archer.h"
#include "CurrentTile.h"
#include <Windows.h>
#include "DoublyItemNode.h"
#include "MonsterBuilder.h"
#include "MonsterDirector.h"
#include "OrcBuilder.h"
#include "KingBuilder.h"
#include "Visitor.h"
#include <stack>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
#include <Windows.h>

//CONTINUATION OF PROJECT ASSIGNMENT 2
using namespace std;

//Queue starts here. Queue will be used to show quests available to the player as some quest are optional
//It is a sort of a guideline
void printQuest(queue <string> sq)
{
    queue <string> q = sq;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop(); // If dont put pop it will loop forever lol
    }
    cout << "\n";
}

void getTileDetails(Tiles current) 
{
    //prints the current tile's event and choices
    current.printEvent();
    current.printChoices();
    
}

//Visitor pattern starts here
Visitor* V1 = nullptr;
Visitor* V2 = nullptr;


//Iterator function to iterate through a string and count the frequency of characters in that string and display it on the console
void riddleIterator(string riddle)
{
    map<char, int> temp;
    map<char, int>::iterator iter;

    for (int i = 0;i < riddle.length();i++)
    {
        temp[riddle[i]]++;
    }
    for (iter = temp.begin();iter != temp.end();iter++)
    {
        cout << iter->first << " - " << iter->second << endl;
    }
}


int main()
{
    int classChoice;
    string classChanges;
    bool gameStatus = TRUE;

    //Initialize Things needed for Tiles
    string choice1, choice2, choice3,choice4;
    Map map;
    CurrentTile playerTile;

    //testing riddle
    string riddle = "TheLichKing";
    long riddleSolution;
    
    // Initialize Doubly Item Node
    typedef DoublyItemNode <string>::itemNode StringNode;
    string item[3] = { "Key","Potion","Dagger"};
    
    StringNode n1(item[0]); // Initialize the head node
    StringNode n2(item[1]); 
    StringNode n3(item[2]);
    
    //Initialize things needed for monster builder
    MonsterDirector monsterDirector;
    OrcBuilder orc;
    KingBuilder king;

    //Initialize things needed for the quests
    queue <string> quests;
    string questlist[] = { "1) Escape the prison cell!","2) Kill the Orc! <Optional>","3) Solve the Riddle!","4) Search the Throne Room <Optional>","5) Defeat the Lich King <DANGER!!!>" };
    string questdone[] = { "Escape the prison cell! <COMPLETED>","Kill the Orc! <COMPLETED>","Solve the Riddle! <COMPLETED>","Search the Throne Room <COMPLETED>","Defeat the Lich King <COMPLETED!!!>" };
    quests.push(questlist[0]);
    quests.push(questlist[1]);
    quests.push(questlist[2]);
    quests.push(questlist[3]);
    quests.push(questlist[4]);

    //Initialize things needed to write to file
    ofstream writeFile;
    writeFile.open("score.txt",fstream::app);
    
    //Initialize api to start playing background music in the program 
    bool played = PlaySound(TEXT("halo.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

    //Initialize string variable name for user to input name
    string name;
    cout << "Welcome to Scuff Souls Version 1.0 now with QoL Updates!" << endl;
    cout << "(DISCLAIMER: BACKGROUND MUSIC USED IS FROM THE HALO GAME OWNED BY MICROSOFT. I AM JUST USING IT FOR MY PROJECT TO DEMONSTRATE MY ABILITY TO USE AN API TO PLAY MUSIC) Don't sue me pls" << endl;
    cout << "please enter your name:";
    cin >> name;
    cout << "Please choose a class: " << endl;
    cout << "1: Warrior" << endl;
    cout << "2: Archer" << endl;
    cout << "Enter your class choice: ";
    
    // Initialize Player object
    cin >> classChoice;
    BaseClass * player = NULL;
    
    //Initialize Stack for ammo 
    stack <int> ammo; // using integer data type for ammo so that can push 1,2,3,4,5 ammos
    

        
    switch (classChoice) 
    {
    case 1:
    {
        int score = 0;
        Warrior warrior(name); // initialize the warrior class with the player's name
        V1 = new VisitorDesc();// calling the VisitorDesc function to describe the class
        player = &warrior; // reference the player pointer to the warrior object
        player->accept(*V1);
        player->printStatus();
        cout << "Would you like to make any changes to your HP and Damage stats before moving on? Type Yes to edit changes or No to continue" << endl;
        cout << "Enter choice here: ";
        cin >> classChanges;
        if (classChanges == "Yes")
        {
            system("cls");
            cout << "Type Damage followed by a value to increase Damage or HP followed by a value to increase HP " << endl;
            cout << "Enter command here(NOTE YOU CAN ONLY CHANGE ONE STATS): ";
            cin >> *player;
        }
        else
        {
            // Does nothing so that can break out of the if else loop
        }
        player->printStatus();
        Sleep(2000);
        
       while (gameStatus == TRUE) 
        {
           //starting node
           system("cls");
           getTileDetails(*playerTile.current); // prints out the current node which is the head node or starting node
           cout << "Type Help to view help" << endl;
           cout << "Type Quest to view current objectives" << endl;
           cout << "Choice: ";
           cin >> choice1;
           
               if (choice1 == "Show") 
               {
                   for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = pn->getNext())
                   {
                       cout << "========================================" << endl;
                       cout << pn->getItemName() << " " << endl;
                       cout << "========================================" << endl;
                   }
                   cout << "Type the item name to use it or Type Close to close the inventory " << endl;
                   cout << "Choice: ";
                   cin >> choice2;
                   if (choice2 == "Key") 
                   {
                       system("cls");
                       quests.pop();
                       quests.emplace(questdone[0]);
                       score += 20;
                       playerTile.current = playerTile.current->Forward; // Moves to the next node from t1 to t2
                       
                       
                   }
                   if (choice2 == "Potion") 
                   {
                       cout << "You Drink the potion and you can feel your health slowly regenerating" << endl;
                       score -= 10;
                       player->plusHP(3);
                       player->printStatus();
                       n2.itemNodeRemove();
                       Sleep(2500);
                   }
                   if (choice2 == "Dagger")
                   {
                       cout << "You Equip a dagger and somehow you can feel a surge of power going through you" << endl;
                       score -= 10;
                       player->plusDMG(5);
                       player->printStatus();
                       //each time the player uses a dagger one ammo will be deducted from the ammo stack using the pop() function
                       ammo.pop();
                       if (ammo.empty()) 
                       {
                           //once all ammos are used up the dagger item will be removed from the doublyItemNode list
                           n3.itemNodeRemove();
                       }
                       
                       Sleep(2500);
                   }
                   else if (choice2 == "Close")
                   {
                       // Does nothing but closes the inventory so that it doesnt stay in the choice1 == "Show" Loop and the player can enter the next command.
                   }
                   
               }
               // Monster event
               else if (choice1 == "Confront") 
               {
                   system("cls");
                   monsterDirector.createNewMonster(&orc);
                   monsterDirector.printMobEvent();
                   quests.pop();
                   
                   do 
                   {
                       cout << "What do you wanna do next? Type: Attack to attck the monster " << endl;
                       cin >> choice3;
                       //bool attack = PlaySound(TEXT("attack.wav"), NULL, SND_SYNC);// play attack sound when attacking(not uncluded becuase it will cause the BGM to stop playing)
                      
                       //First attack
                       //player gets attacked by the monster
                       player->pReceiveDMG(monsterDirector.calMobDMG());
                       //Monster gets attacked by the player
                       monsterDirector.calDMGTaken(player->getDmg());
                       if (monsterDirector.calMobHP() > 0) 
                       {
                           cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                       }
                       if (player->getHp() > 0)
                       {
                           cout << "Your HP left is: " << player->getHp() << endl;
                       }
                       if (player->getHp() <= 0) 
                       {
                           cout << "Your HP left is: " << player->getHp() << endl;
                           cout << "You died" << endl;
                           gameStatus = false;
                           Sleep(1000);
                           break;
                           
                       }
                       if (monsterDirector.calMobHP() <= 0)
                       {
                           cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                           cout << "You have slain the Orc, Type Move to move on to the next area" << endl;
                           score += 500;
                           cout << "Choice: ";
                           cin >> choice4;
                           if (choice4 == "Move")
                           {
                               system("cls");
                               quests.emplace(questdone[1]);
                               playerTile.current = playerTile.current->Forward;
                           }
                       }

                   } while (monsterDirector.calMobHP() > 0);
                   
               }
               else if (choice1 == "King")
               {
                   system("cls");
                   quests.pop();
                   quests.emplace(questdone[4]);
                   monsterDirector.createNewMonster(&king);
                   monsterDirector.printMobEvent();

                   do
                   {
                       cout << "What do you wanna do next? Type: Attack to attck the monster " << endl;
                       cin >> choice3;
                       //bool attack = PlaySound(TEXT("attack.wav"), NULL, SND_SYNC);// play attack sound when attacking(not uncluded becuase it will cause the BGM to stop playing)

                       //First attack
                       //player gets attacked by the monster
                       player->pReceiveDMG(monsterDirector.calMobDMG());
                       //Monster gets attacked by the player
                       monsterDirector.calDMGTaken(player->getDmg());
                       if (monsterDirector.calMobHP() > 0)
                       {
                           cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                       }
                       if (player->getHp() > 0)
                       {
                           cout << "Your HP left is: " << player->getHp() << endl;
                       }
                       if (player->getHp() <= 0)
                       {
                           cout << "Your HP left is: " << player->getHp() << endl;
                           cout << "You died" << endl;
                           gameStatus = false;
                           Sleep(1000);
                           break;
                       }
                       if (monsterDirector.calMobHP() <= 0)
                       {
                           score += 1000;
                           writeFile << name << "\t" << score << "\n";
                           writeFile.close();
                           cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                           cout << "You have slain the Lich King, Type Move to move on to the next area" << endl;
                           cout << "Choice: ";
                           cin >> choice4;
                           if (choice4 == "Move")
                           {
                               system("cls");
                               playerTile.current = playerTile.current->Forward;
                           }
                       }

                   } while (monsterDirector.calMobHP() > 0);

               }
               else if (choice1 == "Riddle")
               {
               //Call the iterator function to count the frequency of characters in the riddle string and display it on the screen
               riddleIterator(riddle);
               quests.pop();
               quests.emplace(questdone[2]);
               cout << "Type in the solution here: ";
               cin >> riddleSolution;
               if(riddleSolution == 111111221 )
               {
                   score += 500;
                   cout << "You solved the riddle and the door opens, You move forward happily but you somehow you can feel a scarily chill down your spine";
                   playerTile.current = playerTile.current->Forward;
                   Sleep(3000);
               }
               else
               {
                   score -= 100;
                   cout << "Riddle solution is wrong, please try again";
                   Sleep(3000);
               }
               }
               else if (choice1 == "Move")
               {
                   system("cls");
                   quests.pop();
                   playerTile.current = playerTile.current->Forward; // Moves to the next node from t2 to t3 to t4 and so on until the while loop is broken
               }
               else if (choice1 == "Search")
               {
                   score += 500;
                   cout << "You searched around the area in the throne room and you found a potion and 3 daggers!" << endl;
                   quests.pop();
                   quests.emplace(questdone[3]);
                   // Adds both items to the DoublyItemNode list which is potion and dagger
                   n1.append(n2);
                   n2.append(n3);
                   

                   //When the dagger is added on the item list it will add 3 usabilities or ammos for the players to use into ammo stack using push()
                   ammo.push(1);
                   ammo.push(2);
                   ammo.push(3);

                   Sleep(2000);
                   playerTile.current = playerTile.current->Forward;
               }
               else if (choice1 == "Quit")
               {
                   gameStatus = false;
               }
               else if (choice1 == "Help")
               {
                   score -= 10;
                   cout << "Type Move to Move" << endl;
                   cout << "Type Show to open Inventory" << endl;
                   cout << "Type the item's name to use the item after opening inventory" << endl;
                   cout << "Type Attack to attack the monsters" << endl;
                   cout << "Type Confront to attack the Orc" << endl;
                   cout << "Type King to attack the Lich King" << endl;
                   cout << "Type Quit to quit the game" << endl;
                   cout << "Type Search to search a room (Only for specific rooms)" << endl;
                   cout << "Type Riddle to solve a riddle (Only for specific rooms)" << endl;
                   cout << "Basically just read the instructions on the screen and you will be fine." << endl;
                   Sleep(7000);
               }
               else if (choice1 == "Quest")
               {
                   cout << "*****QUEST*****" << endl;
                   printQuest(quests);
                   cout << "***************" << endl;
                   Sleep(5000);
               
               }
             
        }
       system("cls");
       cout << "Your Total Score: " << score << endl;
       cout << "Game over" << endl;
       break;
            
    }
    case 2:
    {
        int score = 0;
        Archer archer(name);// initialize the archer class with the player's name
        V2 = new VisitorDesc();// calling the VisitorDesc function to describe the class
        player = &archer; // reference the player pointer to the warrior object
        player->accept(*V2);
        player->printStatus();
        cout << "Would you like to make any changes to your HP and Damage stats before moving on? Type Yes to edit changes or No to continue" << endl;
        cout << "Enter choice here: ";
        cin >> classChanges;
        if (classChanges == "Yes")
        {
            system("cls");
            cout << "Type Damage followed by a value to increase Damage or HP followed by a value to increase HP " << endl;
            cout << "Enter command here(NOTE YOU CAN ONLY CHANGE ONE STATS): ";
            cin >> *player;
        }
        else 
        {
            // Does nothing so that can break out of the if else loop
        }
        player->printStatus();
        Sleep(2000);

        while (gameStatus == TRUE)
        {
            //starting node
            system("cls");
            getTileDetails(*playerTile.current); // prints out the current node which is the head node or starting node
            cout << "Type Help to view help" << endl;
            cout << "Type Quest to view current objectives" << endl;
            cout << "Choice: ";
            cin >> choice1;


            if (choice1 == "Show")
            {
                for (const StringNode* pn = &n1; pn != &StringNode::NIL; pn = pn->getNext())
                {
                    cout << "========================================" << endl;
                    cout << pn->getItemName() << " " << endl;
                    cout << "========================================" << endl;
                }
                cout << "Type the item name to use it or Type Close to close the inventory " << endl;
                cout << "Choice: ";
                cin >> choice2;
                if (choice2 == "Key")
                {

                    system("cls");
                    quests.pop();
                    quests.emplace(questdone[0]);
                    score += 20;
                    playerTile.current = playerTile.current->Forward; // Moves to the next node from t1 to t2

                }
                if (choice2 == "Potion")
                {
                    cout << "You Drink the potion and you can feel your health slowly regenerating" << endl;
                    score -= 10;
                    player->plusHP(3);
                    player->printStatus();
                    n2.itemNodeRemove();
                    Sleep(2500);
                }
                if (choice2 == "Dagger")
                {
                    cout << "You Equip a dagger and somehow you can feel a surge of power going through you" << endl;
                    score -= 10;
                    player->plusDMG(5);
                    player->printStatus();
                    //each time the player uses a dagger one ammo will be deducted from the ammo stack using the pop() function
                    ammo.pop();
                    if (ammo.empty())
                    {
                        //once all ammos are used up the dagger item will be removed from the doublyItemNode list
                        n3.itemNodeRemove();
                    }

                    Sleep(2500);
                }
                else if (choice2 == "Close")
                {
                    // Does nothing but closes the inventory so that it doesnt stay in the choice1 == "Show" Loop and the player can enter the next command.
                }

            }
            // Monster event
            else if (choice1 == "Confront")
            {
                system("cls");
                monsterDirector.createNewMonster(&orc);
                monsterDirector.printMobEvent();
                quests.pop();

                do
                {
                    cout << "What do you wanna do next? Type: Attack to attck the monster " << endl;
                    cin >> choice3;
                    //bool attack = PlaySound(TEXT("attack.wav"), NULL, SND_SYNC);// play attack sound when attacking(not uncluded becuase it will cause the BGM to stop playing)

                    //First attack
                    //player gets attacked by the monster
                    player->pReceiveDMG(monsterDirector.calMobDMG());
                    //Monster gets attacked by the player
                    monsterDirector.calDMGTaken(player->getDmg());
                    if (monsterDirector.calMobHP() > 0)
                    {
                        cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                    }
                    if (player->getHp() > 0)
                    {
                        cout << "Your HP left is: " << player->getHp() << endl;
                    }
                    if (player->getHp() <= 0)
                    {
                        cout << "Your HP left is: " << player->getHp() << endl;
                        cout << "You died" << endl;
                        gameStatus = false;
                        Sleep(1000);
                        break;

                    }
                    if (monsterDirector.calMobHP() <= 0)
                    {
                        score += 500;
                        cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                        cout << "You have slain the Orc, Type Move to move on to the next area" << endl;
                        cout << "Choice: ";
                        cin >> choice4;
                        if (choice4 == "Move")
                        {
                            system("cls");
                            quests.emplace(questdone[1]);
                            playerTile.current = playerTile.current->Forward;
                        }
                    }

                } while (monsterDirector.calMobHP() > 0);

            }
            else if (choice1 == "King")
            {
                system("cls");
                quests.pop();
                quests.emplace(questdone[4]);
                monsterDirector.createNewMonster(&king);
                monsterDirector.printMobEvent();

                do
                {
                    cout << "What do you wanna do next? Type: Attack to attck the monster " << endl;
                    cin >> choice3;
                    //bool attack = PlaySound(TEXT("attack.wav"), NULL, SND_SYNC);// play attack sound when attacking(not uncluded becuase it will cause the BGM to stop playing)

                    //First attack
                    //player gets attacked by the monster
                    player->pReceiveDMG(monsterDirector.calMobDMG());
                    //Monster gets attacked by the player
                    monsterDirector.calDMGTaken(player->getDmg());
                    if (monsterDirector.calMobHP() > 0)
                    {
                        cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                    }
                    if (player->getHp() > 0)
                    {
                        cout << "Your HP left is: " << player->getHp() << endl;
                    }
                    if (player->getHp() <= 0)
                    {
                        cout << "Your HP left is: " << player->getHp() << endl;
                        cout << "You died" << endl;
                        gameStatus = false;
                        Sleep(1000);
                        break;
                    }
                    if (monsterDirector.calMobHP() <= 0)
                    {
                        score += 1000;
                        writeFile << name << "\t" << score << "\n";
                        writeFile.close();
                        cout << "Monster HP: " << monsterDirector.calMobHP() << endl;
                        cout << "You have slain the Lich King, Type Move to move on to the next area" << endl;
                        cout << "Choice: ";
                        cin >> choice4;
                        if (choice4 == "Move")
                        {
                            system("cls");
                            playerTile.current = playerTile.current->Forward;
                        }
                    }

                } while (monsterDirector.calMobHP() > 0);

            }
            else if (choice1 == "Riddle")
            {
                //Call the iterator function to count the frequency of characters in the riddle string and display it on the screen
                riddleIterator(riddle);
                quests.pop();
                quests.emplace(questdone[2]);
                cout << "Type in the solution here: ";
                cin >> riddleSolution;
                if (riddleSolution == 111111221)
                {
                    score += 500;
                    cout << "You solved the riddle and the door opens, You move forward happily but you somehow you can feel a scarily chill down your spine";
                    playerTile.current = playerTile.current->Forward;
                    Sleep(3000);
                }
                else
                {
                    score -= 100;
                    cout << "Riddle solution is wrong, please try again";
                    Sleep(3000);
                }
            }
            else if (choice1 == "Move")
            {
                system("cls");
                quests.pop();
                playerTile.current = playerTile.current->Forward; // Moves to the next node from t2 to t3 to t4 and so on until the while loop is broken
            }
            else if (choice1 == "Search")
            {
                score += 500;
                cout << "You searched around the area in the throne room and you found a potion and 3 daggers!" << endl;
                quests.pop();
                quests.emplace(questdone[3]);
                // Adds both items to the DoublyItemNode list which is potion and dagger
                n1.append(n2);
                n2.append(n3);

                //When the dagger is added on the item list it will add 3 usabilities or ammos for the players to use into ammo stack using push()
                ammo.push(1);
                ammo.push(2);
                ammo.push(3);

                Sleep(2000);
                playerTile.current = playerTile.current->Forward;
            }
            else if (choice1 == "Quit")
            {
                gameStatus = false;
            }
            else if (choice1 == "Help")
               {
               score -= 10;
               cout << "Type Move to Move" << endl;
               cout << "Type Show to open Inventory" << endl;
               cout << "Type the item's name to use the item after opening inventory" << endl;
               cout << "Type Attack to attack the monsters" << endl;
               cout << "Type Confront to attack the Orc" << endl;
               cout << "Type King to attack the Lich King" << endl;
               cout << "Type Quit to quit the game" << endl;
               cout << "Type Search to search a room (Only for specific rooms)" << endl;
               cout << "Type Riddle to solve a riddle (Only for specific rooms)" << endl;
               cout << "Basically just read the instructions on the screen and you will be fine." << endl;
               Sleep(7000);
               }
            else if (choice1 == "Quest")
               {
               cout << "*****QUEST*****" << endl;
               printQuest(quests);
               cout << "***************" << endl;
               Sleep(5000);

               }



        }
        system("cls");
        cout << "Your Total Score: " << score << endl;
        cout << "Game over" << endl;
        break;
    }
   
    }

    //Release memory
   /* if (player != nullptr)
    {
        delete player;
    }
    if (V1 != nullptr)
    {
        delete V1;
    }
    if (V2 != nullptr)
    {
        delete V2;
    }*/
    // Keep getting error here when trying to release memory
   
}


