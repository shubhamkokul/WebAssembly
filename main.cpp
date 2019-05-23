#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <emscripten.h>
#include "Addition.h"


using namespace std;


void Addition::setA(int a){
    this->a=a;
}
void Addition::setB(int b){
    this->b=b;
}
void Addition::setC(int c){
    this->c=c;
}

void Addition::add(int a, int b) {
    this->setC(a+b);
}


int addLogic(char *Eqn){

    string Eqnx(Eqn);
    vector<string> EquationText;
    EquationText=Addition::split(Eqn,";");
    int input1 =  stoi(EquationText[0]);
    int input2 = stoi(EquationText[1]);
    Addition* firstValue = new Addition();
    firstValue->setA(input1);
    firstValue->setB(input2);
    firstValue->add(firstValue->getA(),firstValue->getB());
    return firstValue->getC();
}

extern "C"
{
EMSCRIPTEN_KEEPALIVE
void PassEquations(char *Eqn)
{
    string ResultsStr =""+to_string(addLogic(Eqn));
    string script = "SolutionPanel('" + ResultsStr + "')";
    const char *s = script.c_str();
    emscripten_run_script(s);
}
EMSCRIPTEN_KEEPALIVE
}


int main() {
}