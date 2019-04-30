#include "Editor.h"
#include <string>
#include <algorithm>

using namespace std;

Editor::Editor(){
    currLine=-1;
    loop();
        
}

void Editor::loop(){
    bool flag=true;
    while(flag){
        string str;
        getline(cin, str);
        if (str=="p"){ // prints the current line (ed maintains a current line)
            d.printCurr(currLine);
        }
        else if (str=="n"){ // prints line number of current line followed by TAB followed by current line
            cout<<currLine+1<<"       ";
            d.printCurr(currLine);
        }

        else if (str=="%p"){ // prints all lines
            d.printAll();
        }
        else if (isNumber(str)){ // makes line #str the current line  
            int i= atoi(str.c_str());       
            if(i>d.numOfLines() || i<=0)
                cout<<"illegal line number!";
            else{
                currLine=i-1;
                d.printCurr(currLine);
            }
        }
        else if (str=="a"){ // appends new text after the current line
            string s;
            getline(cin, s);

            while(s!="."){
                d.insertInto(currLine+1,s);
                currLine++;
                getline(cin, s);
                }
        }
        else if (str=="i"){ // inserts new text before the current line
            if(currLine!=0){
                string s;
                getline(cin, s);
                while(s!="."){
                    d.insertInto(currLine,s);
                    currLine++;
                    getline(cin, s);

                }
            }
            else
                cout<<"illegal choise!\n";
        }
        else if (str=="c"){ // changes the current line for text that follows
            string s;
            getline(cin, s);
            d.changeCurr(currLine,s);
            getline(cin, s);
            if(s!=".")
                cout<<"eror!";
        }
        else if (str=="d"){ // deletes the current line
            d.deleleCurr(currLine);
        }        
        else if (str[0]=='/'){ // /text searches forward after current line for the specified text. The search wraps to the beginning of the buffer and continues down to the current line, if necessary
            int i= d.serch(currLine,str.substr(1,str.size()));
            if(i!=-1){
                d.printCurr(i);
                currLine=i;
            }
            else
                cout<<"?\n";
            
        }
        else if (str.substr(0,2)=="s/" && str[str.length()-1]=='/'){ // s/old/new/ replaces old string with new in current line (google: C++ split or token)
            str=str.substr(2,str.length()-3);
            string oldString,newString;
            string delimiter = "/";
            int i;
            if (d.checkSubString(str,delimiter)) {
                i=str.find(delimiter);
                oldString = str.substr(0, i);

                newString=str.substr(i+1, str.length());

                d.replace(currLine,oldString,newString);
            }
            else
                cout<<"illegal choise!\n";            
        }
        else if (str=="Q"){ // Quits the editor without saving
            flag=false;
        }
        else{
            cout<<"illegal choise!\n";
        }            
    }
}
bool Editor::isNumber(const string& s)
{
    return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}