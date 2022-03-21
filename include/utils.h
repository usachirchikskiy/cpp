#ifndef UTILS_H
#define UTILS_H

using namespace std;
#include <vector>
#include <sstream>

//Common functions
vector<string> split(string s, char delim);


//Шаблонные функции всегда надо реализовывать в headers file
template <typename Text, typename TypeToConvert>
void stringToSomething(Text stringText, TypeToConvert &typeConvert)
{
    stringstream syear(stringText);
    syear >> typeConvert;
}

#endif