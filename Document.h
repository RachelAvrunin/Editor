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
    void printCurr(int line);
    void printAll();
    void insertInto(int line, const string & s);
    void changeCurr(int line, const string & s);
    int serch(int line, const string & s);
    void deleleCurr(int line);
    void replace (int line,const string & oldString, const string & newString);
    bool checkSubString(const string & myString, const string & subString);
};



