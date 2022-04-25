#ifndef CONTENT_PAGES
#define CONTENT_PAGES

namespace content_pages
{
    class Page;
    Page getPages(int);

    class Page
    {

    public:
        char text[500];
        char options[5][100];
        int optionsNumber[5];
        int imageId;
        int customId;
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

            for (int o = 0; o < 5; o++)
            {
                int currentSize = 0;
                int optionNumber = 0;
                const char *optionString = NULL;

                switch (o)
                {
                case 0:
                    currentSize = this->string_size(textoptions1);
                    optionString = textoptions1;
                    optionNumber = op1;
                    break;
                case 1:
                    currentSize = this->string_size(textoptions2);
                    optionString = textoptions2;
                    optionNumber = op2;
                    break;
                case 2:
                    currentSize = this->string_size(textoptions3);
                    optionString = textoptions3;
                    optionNumber = op3;
                    break;
                case 3:
                    currentSize = this->string_size(textoptions4);
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
                for (int d = i + 1; d < sizeOfArr - currentSize; d++)
                {
                    this->options[o][d] = '\0'; // end  of meaningfull cahrs
                }

                this->optionsNumber[o] = optionNumber;
            };
        };

        void b(const char *text, /* Option options[5],*/ int imageId, int customId)
        {
            this->buildPage(text, imageId, customId);
        };
        void buildPage(const char *text, /* Option options[5],*/ int imageId, int customId)
        {
            int i;
            const int paddingMaxSize = 400;

            int size = this->string_size(text);
            for (i = 0; i < size + 1; i++)
            {
                this->text[i] = text[i];
            }
            int sizeOfArr = sizeof(this->text);
            // for ()
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

            //
            this->imageId = imageId;
            this->customId = customId;
        }
        int string_size(const char *str)
        {
            // const char *str = "Hello World !";
            int Size = 0;
            while (str[Size] != '\0')
                Size++;
            return Size;
        }
    };

    Page getPages(int pageNumber = 1)
    {
        Page p;
        p.b("abc1234", 12, 1);
        p.o("Open the door", 1,
            "Look around", 1);

        switch (pageNumber)
        {
        case 1:
            p.b("You wake up in a small room with one door.", 12, 1);
            p.o("Open the door", 2,
                "Look around", 3);
            break;

        case 2:
            p.b("The door leads to a dark long corridor. At it goes into a staircase. There are stairse goning up and down.", 12, 1);
            p.o("Go up", 1,
                "Go down", 1);
            break;

        case 3:
            p.b("Tou look around the room. In the cornner you see a small peace of paper.", 12, 1);
            p.o("Read the paper", 4,
                "Go through the door", 2);
            break;
        case 4:
            p.b("The paper has strage writings on it and it sais: ...don't touch the golden goose", 12, 1);
            p.o(
                "Go through the door", 2);
            break;
        }

        return p;
    };

    // pages[0].text = "asdfasg";
}

#endif