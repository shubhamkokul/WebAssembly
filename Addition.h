//
// Created by 5pk on 5/22/19.
//

#ifndef WEBASSEMBLY_ADDITION_H
#define WEBASSEMBLY_ADDITION_H

using namespace std;

class Addition{

private:
    int a;
    int b;

    int c;

public:
    Addition(){}

    Addition(int a, int b){
        this->a=a;
        this->b=b;
    }

    void setA(int a);

    void setB(int b);

    void setC(int c);

    int getA(){
        return this->a;
    }

    int getB(){
        return this->b;
    }

    int getC(){
        return this->c;
    }

    void add(int a,int b);
    int addLogic(int in1,int in2);
    static vector<std::string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

    ~Addition(){}

};



#endif
