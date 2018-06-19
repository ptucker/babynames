#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//Get the year from the user. It'd be good here to do more error checking
// before returning a year (e.g. the year is in a valid range)
int prompt() {
    cout << "Enter the year: ";
    int year;
    cin >> year;
    return year;
}

//Read the file for the boys and girls names
void readnames(int year, vector<string>& boys, vector<string>&girls) {
    stringstream ss;
    //Build out the filename based on the year.
    ss << "baby" << year << ".txt";
    string file = ss.str();
    ifstream infile(file);
    string boy, girl;
    int rank;
    //Read the rank unti there are no more values
    while (infile >> rank) {
        infile >> boy;
        infile >> girl;
        boys.push_back(boy);
        girls.push_back(girl);
    }
}

//Search the vector for the given name
void search(vector<string> names, string name, int year) {
    for (int i=0; i<names.size(); i++) {
        if (name == names[i]) {
            //Once we find it, output the result and leave the function
            cout << name << " is ranked #" << (i+1) << " in year " << year << endl;
            return;
        }
    }
    //If we get here, we didn't find it. Tell the user.
    cout << "The name " << name << " is not ranked in year " << year << endl;
}

int main() {
    int year = prompt();
    vector<string> boys;
    vector<string> girls;
    readnames(year, boys, girls);

    char gender;
    cout << "Enter the gender: ";
    cin >> gender;

    string name;
    cout << "Enter the name: ";
    cin >> name;

    if (gender == 'm' || gender == 'M')
        search(boys, name, year);
    else
        search(girls, name, year);

    return 0;
}