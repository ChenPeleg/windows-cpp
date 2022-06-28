#ifndef CONTENT_PAGES
#define CONTENT_PAGES
/* ********************
 *   For some reason this class could no be split to
 *   header and implementation files.
 *   So the definitions and implementation are all in one file.
 * *********************/
#include "inventory.hpp"
#include "../images/images.cpp"
#include "common.hpp"
#include "content_monsters.hpp"
#include "item.hpp"
#include "constants.hpp"

using namespace asciiImages;
using namespace constants;

struct Choice
{
       int position;
       int pageNumber;
       char text[100];
       Item requiredItem;
       bool optionBlocked = false;
};

class Page
{

private:
       int imageId;
       int customId;
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2,
              const char *textoptions3, int op3,
              const char *textoptions4, int op4,
              const char *textoptions5, int op5)
       {
              this->setOptions(textoptions1, op1, textoptions2, op2, textoptions3, op3, textoptions4, op4, textoptions5, op5);
       };
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2,
              const char *textoptions3, int op3,
              const char *textoptions4, int op4)
       {
              this->setOptions(textoptions1, op1, textoptions2, op2, textoptions3, op3, textoptions4, op4, "", 0);
       };
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2,
              const char *textoptions3, int op3)
       {
              this->setOptions(textoptions1, op1, textoptions2, op2, textoptions3, op3, "", 0, "", 0);
       };
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2)
       {

              this->setOptions(textoptions1, op1, textoptions2, op2, "", 0, "", 0, "", 0);
       };
       void o(const char *textoptions1, int op1)
       {

              this->setOptions(textoptions1, op1, "", 0, "", 0, "", 0, "", 0);
       };
       void setOptions(const char *textoptions1, int op1,
                       const char *textoptions2, int op2,
                       const char *textoptions3, int op3,
                       const char *textoptions4, int op4,
                       const char *textoptions5, int op5)
       {

              for (int o = 0; o < 5; o++)
              {
                     int currentSize = 0;
                     int optionNumber = 0;
                     const char *optionString = NULL;

                     switch (o)
                     {
                     case 0:
                            currentSize = common::string_size(textoptions1);
                            optionString = textoptions1;
                            optionNumber = op1;
                            break;
                     case 1:
                            currentSize = common::string_size(textoptions2);
                            optionString = textoptions2;
                            optionNumber = op2;
                            break;
                     case 2:
                            currentSize = common::string_size(textoptions3);
                            optionString = textoptions3;
                            optionNumber = op3;
                            break;
                     case 3:
                            currentSize = common::string_size(textoptions4);
                            optionString = textoptions4;
                            optionNumber = op4;
                            break;
                     case 4:
                            currentSize = common::string_size(textoptions5);
                            optionString = textoptions5;
                            optionNumber = op5;
                            break;
                     }
                     int i = 0;
                     for (i = 0; i < currentSize; i++)
                     {
                            this->choices[o].text[i] = optionString[i];
                     };
                     int sizeOfArr = sizeof(this->choices[o]);

                     this->choices[o].text[i] = '\0';
                     for (int d = i + 1; d < sizeOfArr - currentSize; d++)
                     {

                            this->choices[o].text[i] = '\0';
                     }

                     this->choices[o].pageNumber = optionNumber;
              };
       };

       void b(const char *text, ImageEnumb image, int customId)
       {
              this->buildPage(text, image, customId);
       };
       void m(content_monsters::MonsterType mnsType, int nextPage, const char *text = "")
       {
              this->buildPage(text, image, 0, mnsType);
              this->o("", nextPage);
       };
       void buildPage(const char *text, ImageEnumb image, int customId, content_monsters::MonsterType mnsType = content_monsters::MonsterType::none)
       {
              pageMonster = mnsType;
              setCustomId(customId, mnsType);
              int i;
              const int paddingMaxSize = 400;
              int size = common::string_size(text);
              for (i = 0; i < size + 1; i++)
              {
                     this->text[i] = text[i];
              }
              int sizeOfArr = sizeof(this->text);

              this->text[i] = ' ';
              for (int d = i + 1; d < sizeOfArr - size; d++)
              {
                     if (d < paddingMaxSize)
                     {
                            this->text[d] = ' '; // add space padding
                     }
                     else
                     {
                            this->text[d] = '\0'; // end  of meaningfull cahrs
                     }
              }

              this->image = image;
       }
       void setChangedItems(Item itm)
       {
              for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++)
              {
                     if (pageChangesItems[i].itemType == ItemType::NoItem)
                     {
                            pageChangesItems[i] = itm;

                            break;
                     }
              }
       }
       void pageOptionRequiersItems(int optionPageNumber, Item itm, int amount = 1)
       {

              for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++)
              {
                     if (optionPageNumber == choices[i].pageNumber)
                     {
                            choices[i].requiredItem = itm;
                     }
              }
       }

public:
       bool isFight = false;
       char text[500];
       Choice choices[MAX_NUMBER_OF_OPTIONS];
       Item pageChangesItems[MAX_NUMBER_OF_OPTIONS];

       ImageEnumb image;
       content_monsters::MonsterType pageMonster;

       ~Page()
       {
              //  delete this;
       }
       void setCustomId(int customId, content_monsters::MonsterType mnsType)

       {
              this->customId = customId;
              switch (mnsType)
              {
              case content_monsters::MonsterType::none:
                     this->isFight = false;
                     break;
              default:
                     this->isFight = true;
                     break;
              }
       }
       void updateOptionsFromInventory(Inventory &inv)
       {
              for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++)
              {
                     if (choices[i].requiredItem.itemType != ItemType::NoItem)
                     {
                            int cnt = inv.count(choices[i].requiredItem.itemType);
                            if (cnt < choices[i].requiredItem.amount)
                            {
                                   choices[i].optionBlocked = true;
                            }
                     };
              }
       }
       void updateOptionsForMenu(int lastPage)
       {
       }

       static Page getPages(int pageNumber = 1)
       {
              Page p;

              switch (pageNumber)
              {

              case 1:
                     p.b("Walking from the hills you embark on a big journy. You see Two roads ahed of you.", ImageEnumb::palmTree, 1);
                     p.o("Go Right ", 2,
                         "Go Left ", 6);

                     p.setChangedItems(Item(ItemType::shield, 1));
                     break;

              case 2:
                     p.b("You go right and down. You see a skull. What do you want to do?", ImageEnumb::worm, 1);
                     p.o("Break It with sword ", 5,
                         "Break It with shield ", 6,
                         "Leave It ", 7);
                     p.pageOptionRequiersItems(5, Item(ItemType::Sword));
                     p.pageOptionRequiersItems(6, Item(ItemType::shield));
                     break;

              case 3:
                     p.b("Tou look around the room. In the cornner you see a small peace of paper.", ImageEnumb::none, 1);
                     p.o("Read the paper", 4,
                         "Go through the door", 2);
                     break;
              case 4:
                     p.b("The paper has strage writings on it and it sais: ...don't touch the golden goose", ImageEnumb::none, 1);
                     p.o(
                         "Go through the door", 2);
                     break;
              case 5:
                     p.b("You go upstairs. At the end of the stairs, you see a door with a big rope hanging from the cieling. On the Floor you find a big sword", ImageEnumb::none, 1);
                     p.o(
                         "Pull the Rope", 2,
                         "Open the door", 7);
                     p.setChangedItems(Item(ItemType::Sword, 1));
                     break; //
              case 6:
                     p.b("Going down the stairs you start smelling old wine. Looks like to are getting close to the wine celler. You hear voices at the distance", ImageEnumb::none, 1);
                     p.o(
                         "Get close and try to call", 2,
                         "Stay put and listen to the voices", 2);
                     break;
              case 7:
                     p.b("Fight The Worm Moster!", ImageEnumb::worm, 1000);
                     p.m(content_monsters::MonsterType::blobhMonster, 2);
                     p.o("Open the door", 2,
                         "Look around", 3);
                     break;
                     // StartScreenOptions
              case 10001:
                     p.b("        WHISPERING FOREST       ", ImageEnumb::candleAnimation, 1000);

                     p.o("         Load Last Save      ", 1,
                         "         Start New Game        ", 1,
                         "         Load Game        ", 10003,
                         "         Options        ", 10005);
                     break;
                     // in-game Options
              case 10002:
                     p.b("        WHISPERING FOREST       ", ImageEnumb::candleAnimation, 1000);

                     p.o("         Continue        ", 1,
                         "         Start New Game        ", 1,
                         "         Load Game        ", 10003,
                         "         Save Game        ", 10004,
                         "         Options        ", 10005);
                     break;
              case 10003:
                     p.b("   WHISPERING FOREST - LOAD GAME    ", ImageEnumb::candleAnimation, 1000);

                     p.o("         Slot A        ", 11111,
                         "         Slot B        ", 11112,
                         "         Slot C       ", 11113,
                         "         Back      ", 10002,
                         "         Options        ", 10005);
                     break;

              case 10004:
                     p.b("   WHISPERING FOREST - SAVE GAME    ", ImageEnumb::candleAnimation, 1000);

                     p.o("         Slot A        ", 11111,
                         "         Slot B        ", 11112,
                         "         Slot C       ", 11113,
                         "         Back      ", 10002,
                         "         Options        ", 10005);
                     break;
              case 10005:
                     p.b("    WHISPERING FOREST - OPTIONS       ", ImageEnumb::candleAnimation, 1000);

                     p.o("         Sound On      ", 11111,
                         "         Sound off     ", 1,
                         "         About      ", 10003,
                         "         Back      ", 10002);
                     break;
              }

              return p;
       };
};

#endif