#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Document {

private:

	vector <string> myDoc;

public:

	Document();
    int numOfLines();
    void printCurr(const int line) const;
    void printAll() const;
    void insertInto(const int line, const string & s);
    void changeCurr(const int line, const string & s);
    int serch(const int line, const string & s) const;
    void deleleCurr(const int line);
    void replace (const int line,const string & oldString, const string & newString);
    bool checkSubString(const string & myString, const string & subString) const;

};