
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <iostream>
using namespace std;

class FileManager
{
private:
    int FileDataSize;
    const char *FileName;
    long getFileLength(fstream &fileRef);

public:
    FileManager(const char *fileName = "data/savefile.dat", int fileDataSize = 100);
    ~FileManager();
    void add(const char *textToWrite);
    long GetFileLength();
    fstream openFile();
};

/*** Class ***/

FileManager::FileManager(const char *fileName, int fileDataSize) : FileDataSize(fileDataSize), FileName(fileName)
{
}
long FileManager::getFileLength(fstream &fileRef)
{

    fileRef.seekg(0, fileRef.end);
    return fileRef.tellg();
}
long FileManager::GetFileLength()
{
    long len = 0;
    fstream file = openFile();
    len = getFileLength(file);
    file.close();
    return len;
}
fstream FileManager::FileManager::openFile()
{

    fstream file;
    file.open(FileName);
    return file;
}
void FileManager::add(const char *textToWrite)
{

    fstream file = openFile();
    file << textToWrite;
    file.close();
}

FileManager::~FileManager()
{
}
#endif
