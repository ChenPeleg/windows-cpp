#ifndef VIEWS_ENGINE
#define VIEWS_ENGINE

namespace view_engine
{
    class ConsoleView
    {
    private:
        char *rows[][];
        int charsPerRow;
        int numOfRows;

    public:
        views_engine(int charsPerRow, int numOfRows)
        {
            this->charsPerRow = charsPerRow;
            this->numOfRows = numOfRows;
            // this->rows
        };
        ~views_engine(){

        };
    };

    void trimRows()
    {
    }
}

#endif