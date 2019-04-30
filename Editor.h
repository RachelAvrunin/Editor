#include <iostream>
#include "Document.h"

class Editor{

public:
    Editor();
    Document d;
    void loop();

private:
    int currLine;
    bool isNumber(const string& s);




    
};