#include <iostream>
#include "Document.h"

class Editor{

public:
    Editor();
    void loop();

private:
    Document d;
    int currLine;
    bool isNumber(const string & s) const;




    
};