#ifndef OPENFILE_H_INCLUDED
#define OPENFILE_H_INCLUDED

#include <string>
using std::string;

class OpenFile
{

public:
    OpenFile(string path);
    string getText();
    bool next();
    bool finished();
    string getWord();
    void jumpToNextLine();

private:
    string* text;
    string word;
    int position;
};

#endif // OPENFILE_H_INCLUDED
