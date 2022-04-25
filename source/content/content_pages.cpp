#ifndef CONTENT_PAGES
#define CONTENT_PAGES

namespace content_pages
{
    class Page;
    Page getPages(int);

    class Page
    {

    public:
        char text[100];
        char options[5][50];
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
        void o(const char *textoptions1, int op1 )
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
                const char *optionString = NULL;

                switch (o)
                {
                case 0:
                    currentSize = this->string_size(textoptions1);
                    optionString = textoptions1;
                    break;
                case 1:
                    currentSize = this->string_size(textoptions2);
                    optionString = textoptions2;
                    break;
                case 2:
                    currentSize = this->string_size(textoptions3);
                    optionString = textoptions3;
                    break;
                case 3:
                    currentSize = this->string_size(textoptions4);
                    optionString = textoptions4;
                    break;
                case 4:
                    break;
                }
                for (int i; i < currentSize; i++)
                {
                    this->options[o][i] = textoptions1[i];
                };
            };
        };

        void b(const char *text, /* Option options[5],*/ int imageId, int customId)
        {
            this->buildPage(text, imageId, customId);
        };
        void buildPage(const char *text, /* Option options[5],*/ int imageId, int customId)
        {
            int size = this->string_size(text);
            for (int i = 0; i < size + 1; i++)
            {
                this->text[i] = text[i];
            }
            //
            this->imageId = imageId;
            this->customId = customId;
            // this->options = options;
            for (int i; i < 5; i++)
            {
                // this->options[i] = options[i];
            };
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
            p.b("The paper has strage writings on it and it sais: '...don't touch the golden goose", 12, 1);
            p.o(
                "Go through the door", 2);
            break;
        
    }

    return p;
};

// pages[0].text = "asdfasg";
}

#endif