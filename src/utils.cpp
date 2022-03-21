#include "utils.h"

vector<string> split(string s, char delim)
{
    vector<string> result;
    stringstream streamName(s);
    string item;

    while (getline(streamName, item, delim))
    {
        result.push_back(item);
    }

    return result;
}
