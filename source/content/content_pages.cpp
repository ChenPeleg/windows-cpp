#ifndef CONTENT_PAGES
#define CONTENT_PAGES

namespace content_pages
{
    struct Page
    {
        Page(char *text, char options[5][100], int imageId, int customId)
        {
            this->text = text;
            this->imageId = imageId;
            this->customId = customId;
            this->options = options;
            for (int i; i < 5; i++)
            {
                this->options[i] = options[i];
            }
        }
        char *text;
        char options[5][100];
        int imageId;
        int customId;
    };
    Page *pages[200];
    // pages[0] = new Page(
    //     "You wakeup in an old room. Can't remember How you got here. What do you want to do?",
    //     {"Look for a way out", "Search my clothes", "Prey to God"},
    //     0,
    //     0);

}

#endif