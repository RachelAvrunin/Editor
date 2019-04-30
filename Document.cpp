#include "Document.h"
using namespace std;


Document::Document(){      

}
int Document::numOfLines(){
    return myDoc.size();
}

void Document::printCurr(int i){
    if(myDoc.empty())
        cout<<"Document is empty!\n";
    else if(i<=myDoc.size())
        cout<<myDoc.at(i)<<"\n";
    else
       cout<<"Eror in line number: "<<i<<"!\n";
}

void Document::printAll(){
    for(int i=0; i<myDoc.size(); i++)
        printCurr(i);

    if(myDoc.empty())
        cout<<"Document is empty!\n";
}

void Document::insertInto(int line , const string & s){
    myDoc.insert(myDoc.begin() + line , s);

}

void Document::changeCurr(int line, const string & s){
    myDoc.at(line)=s;
}

int Document::serch(int line, const string & s){
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

void Document::deleleCurr(int line){
    myDoc.erase(myDoc.begin() + line);
}

void Document::replace (int line,const string & oldString, const string & newString){
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

bool Document::checkSubString(const string & myString, const string & subString){
    if(myString.find(subString)!= string::npos)
        return true;
    else
        return false;
}

