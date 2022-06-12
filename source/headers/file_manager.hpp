
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <iostream>
using namespace std;

class FileManager
{
private:
    /* data */
    int FileDataSize;

public:
    FileManager(const char *fileName = "data/savefile.dat", int fileDataSize = 100);

    ~FileManager();
};

FileManager::FileManager(const char *fileName, int fileDataSize) : FileDataSize(fileDataSize)
{
    ofstream outfile;
    outfile.open(fileName);
    // outfile << "abc123" << endl;
    outfile.close();
};

FileManager::~FileManager()
{
}
#endif
