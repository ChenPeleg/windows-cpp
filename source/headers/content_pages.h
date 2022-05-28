#ifndef CONTENT_PAGES
#define CONTENT_PAGES
/* ********************
 *   For some reason this class could no be split to
 *   header and implementation files.
 *   So the definitions and implementation are all in one file.
 * *********************/
#include "../images/images.cpp"
#include "common.h"

using namespace imagesEnumb;

class Page
{

private:
       int imageId;
       int customId;

public:
       bool isFight;
       char text[500];
       char options[5][100];
       int optionsNumber[5];
       ImageEnumb image;
       ~Page()
       {
              //  delete this;
       }
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2,
              const char *textoptions3, int op3,
              const char *textoptions4, int op4)
       {
              this->setOptions(textoptions1, op1, textoptions2, op2, textoptions3, op3, textoptions4, op4);
       };
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2,
              const char *textoptions3, int op3)
       {
              this->setOptions(textoptions1, op1, textoptions2, op2, textoptions3, op3, "", 0);
       };
       void o(const char *textoptions1, int op1,
              const char *textoptions2, int op2)
       {

              this->setOptions(textoptions1, op1, textoptions2, op2, "", 0, "", 0);
       };
       void o(const char *textoptions1, int op1)
       {

              this->setOptions(textoptions1, op1, "", 0, "", 0, "", 0);
       };
       void setOptions(const char *textoptions1, int op1,
                       const char *textoptions2, int op2,
                       const char *textoptions3, int op3,
                       const char *textoptions4, int op4)
       {
              // if (this->customId == 1)
              // {
              //        return;
              // }

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
                            break;
                     }
                     int i = 0;
                     for (i = 0; i < currentSize; i++)
                     {
                            this->options[o][i] = optionString[i];
                     };
                     int sizeOfArr = sizeof(this->options[o]);
                     // for ()
                     this->options[o][i] = '\0';
                     for (int d = i + 1; d < sizeOfArr - currentSize; d++)
                     {
                            this->options[o][d] = '\0'; // end  of meaningfull cahrs
                     }

                     this->optionsNumber[o] = optionNumber;
              };
       };

       void b(const char *text, ImageEnumb image, int customId)
       {
              this->buildPage(text, image, customId);
       };
       void buildPage(const char *text, ImageEnumb image, int customId)
       {
              setCustomId(customId);
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

       static Page getPages(int pageNumber = 1)
       {
              Page p;
              p.b("abcImageEnumb::none34", ImageEnumb::none, 1);
              p.o("Open the door", 1,
                  "Look around", 1);

              switch (pageNumber)
              {
              case 1:
                     p.b("Fight The Worm Moster!", ImageEnumb::worm, 1000);
                     p.o("Open the door", 2,
                         "Look around", 3);
                     break;

              case 2:
                     p.b("The door leads to a dark long corridor. At it goes into a staircase. There are stairse goning up and down.", ImageEnumb::elephant, 1);
                     p.o("Go up ", 5,
                         "Go down ", 6);
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
                     p.b("You go upstairs. At the end of the stairs, you see a door with a big rope hanging from the cieling.", ImageEnumb::none, 1);
                     p.o(
                         "Pull the Rope", 1,
                         "Open the door", 1);
                     break;
              case 6:
                     p.b("Going down the stairs you start smelling old wine. Looks like to are getting close to the wine celler. You hear voices at the distance", ImageEnumb::none, 1);
                     p.o(
                         "Get close and try to call", 2,
                         "Stay put and listen to the voices", 2);
                     break;
              }

              return p;
       };
       void setCustomId(int customId)
       {
              this->customId = customId;
              switch (customId)
              {
              case 1000:
                     this->isFight = true;
                     break;
              default:
                     this->isFight = false;
                     break;
              }
       }
};

#endif