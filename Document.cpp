#include "Document.h"

using namespace std;

Document::Document(){
}

int Document::numOfLines(){
    return myDoc.size();
}

void Document::printCurr(const int line) const{
    if(myDoc.empty())
        cout<<"Document is empty!\n";
    else if(line<=myDoc.size())
        cout<<myDoc.at(line)<<"\n";
    else
       cout<<"Eror in line number: "<<line<<"!\n";
}

void Document::printAll() const{
    for(int i=0; i<myDoc.size(); i++)
        printCurr(i);

    if(myDoc.empty())
        cout<<"Document is empty!\n";
}

void Document::insertInto(const int line , const string & s){
    myDoc.insert(myDoc.begin() + line , s);
}

void Document::changeCurr(const int line, const string & s){
    myDoc.at(line)=s;
}

int Document::serch(const int line, const string & s) const{
    for (int i=line; i<myDoc.size() ; i++){
        if(checkSubString(myDoc.at(i),s)){
            return i;   
        }
    }
    for (int i=0; i<line ; i++){
        if(checkSubString(myDoc.at(i),s))
             return i;   
    }
    return -1;

}

void Document::deleleCurr(const int line){
    myDoc.erase(myDoc.begin() + line);
}

void Document::replace(const int line,const string & oldString, const string & newString){
    string s=myDoc.at(line); 
    if(checkSubString(s,oldString)){
        int i=s.find(oldString);
        s=s.substr(0,i)+newString+s.substr(i+oldString.size() , s.length());
        myDoc.at(line)=s;
    }
    else{
        cout<<oldString<<" does not exist in"<<s<<"!!\n";
    }
}

bool Document::checkSubString(const string & myString, const string & subString) const{
    if(myString.find(subString)!= string::npos)
        return true;
    else
        return false;
}