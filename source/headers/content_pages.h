#ifndef CONTENT_PAGES
#define CONTENT_PAGES

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
           const char *textoptions4, int op4);
    void o(const char *textoptions1, int op1,
           const char *textoptions2, int op2,
           const char *textoptions3, int op3);
    void o(const char *textoptions1, int op1,
           const char *textoptions2, int op2);
    void o(const char *textoptions1, int op1);
    void setOptions(const char *textoptions1, int op1, const char *textoptions2, int op2, const char *textoptions3, int op3, const char *textoptions4, int op4);
    void b(const char *text, int imageId, int customId)
    {
        this->buildPage(text, imageId, customId);
    };
    void buildPage(const char *text, int imageId, int customId);
    int string_size(const char *str);
    static Page getPages(int pageNumber = 1);
};

#endif