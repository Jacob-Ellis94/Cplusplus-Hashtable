#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> readCharFile(string filePath) // This is a predefined function given with the assignment. 
{
    ifstream in(filePath);
    char c;
    string w = "";
    vector<string> strings;
    if (!in.eof() && in.fail()) {
        cerr << "<<<!! ERROR - " << filePath << " NOT FOUND !!!>>>" << endl;
        return strings;
    }
    int i = 0;
    if (in.is_open()) {
        while (in.good()) {
            in.get(c);
            c = tolower(c);

            if (!iswalpha(c)&& !iswspace(c)) // An attempt to handle special characters in text files with iswalpha() instead. 
                    continue;

            if (iswalpha(c)) {
                w += c;
            }
            else if (isspace(c)) {
                if (w != "") {
                    strings.push_back(w);
                }
                w = "";
            }

            else if (!isalpha(c))
                continue;
            i++;
        }
        if (w != "") {
            strings.push_back(w);
        }
    }
    in.close();
    return strings;
}


void removeDuplicate(vector<string>& pairedVector) // This function removes the multiple occurences of a specific word. 
                                                //This problem was solved with help from this forum: https://www.techiedelight.com/remove-duplicates-vector-cpp/
{
    auto end = pairedVector.end();
    for (auto i = pairedVector.begin(); i != end; ++i)
    {
        end = remove(i + 1, end, *i); //Complex logic from the forum (unoriginal, though re-purposed). 
    }
    pairedVector.erase(end, pairedVector.end()); 
}

