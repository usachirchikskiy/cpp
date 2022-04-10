#include "write_read.h"

void writeData(vector<dataPerCourse> &data)
{
    ofstream out("outputUpdated.txt");
    char *enumStrings[] = {"A", "A+", "A-", "AUD", "B", "B+", "B-", "C", "C+", "C-", "CR", "D", "D+", "D-", "F", "FIN", "INC", "NC", "P", "W", "WD", "WN", "WU"};
    if (out.is_open())
    {
        for (int i = 0; i < data.size(); i++)
        {
            out << data[i].emplid << " " << data[i].courseno << " " << data[i].instructorid << " " << data[i].termid
                << " " << data[i].sectionid
                << " " << enumStrings[data[i].grade] << endl;
        }

        out.close();
    }
}

void write(string result)
{
    ofstream out("output.txt", ios::app);

    if (out.is_open())
    {
        out << result;
        out.close();
    }
}

vector<dataPerCourse> readUpdated(vector<dataPerCourse> &fullData)
{
    vector<dataPerCourse> data = fullData;
    
    string fileExists = "../data/outputUpdated.txt";
    ifstream in(fileExists);
    if(in.is_open()==0){
        in.close();
        return data;
    }

    if (in.is_open())
    {
        string line;
        bool skipFirstLine = true;
        while (getline(in, line))
        {
            if (skipFirstLine)
            {
                skipFirstLine = false;
                continue;
            }
            vector<string> lineSplit = split(line, ',');
            string emplid = lineSplit[0];

            int courseno;
            stringToSomething<string, int>(lineSplit.at(1), courseno);

            string instructorid = lineSplit[2];
            string termid = lineSplit[3];
            string sectionid = lineSplit[4];
            string grade = lineSplit[5];

            dataPerCourse row{emplid, courseno, instructorid, termid, sectionid, getEnumIndex(grade)};
            data.push_back(row);
        }
    }
    return data;
}

vector<dataPerCourse> readCSV()
{
    vector<dataPerCourse> data;

    string files[3] = {"../data/1115.csv", "../data/3115.csv", "../data/3130.csv"};

    for (int i = 0; i < 3; i++)
    {
        ifstream in(files[i]);
        if (in.is_open())
        {
            string line;
            bool skipFirstLine = true;
            while (getline(in, line))
            {
                if (skipFirstLine)
                {
                    skipFirstLine = false;
                    continue;
                }
                vector<string> lineSplit = split(line, ',');
                string emplid = lineSplit[0];

                int courseno;
                stringToSomething<string, int>(lineSplit.at(1), courseno);

                string instructorid = lineSplit[2];
                string termid = lineSplit[3];
                string sectionid = lineSplit[4];
                string grade = lineSplit[5];

                dataPerCourse row{emplid, courseno, instructorid, termid, sectionid, getEnumIndex(grade)};
                data.push_back(row);
            }
        }
    }
    return data;
}

