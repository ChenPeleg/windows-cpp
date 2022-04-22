#ifndef CONTENT_PAGES
#define CONTENT_PAGES

namespace content_pages
{
    class Page;
    Page getPages();

    class Page
    {

    public:
        char text[100];
        char options[5][50];
        int imageId;
        int customId;

        buildPage(const char *text, /* Option options[5],*/ int imageId, int customId)
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
            }
            return 0;
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

    Page getPages()
    {
        Page thepage;
        thepage.buildPage("abc1234", 12, 1);
        return thepage;
    };

    // pages[0].text = "asdfasg";

}

#endif