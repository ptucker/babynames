#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int prompt() {
    cout << "Enter the year: ";
    int year;
    cin >> year;
    return year;
}

void readnames(int year, vector<string>& boys, vector<string>&girls) {
    stringstream ss;
    ss << "baby" << year << ".txt";
    string file = ss.str();
    ifstream infile(file);
    string boy, girl;
    int rank;
    while (infile >> rank) {
        infile >> boy;
        infile >> girl;
        boys.push_back(boy);
        girls.push_back(girl);
    }
}

void search(vector<string> names, string name, int year) {
    for (int i=0; i<names.size(); i++) {
        if (name == names[i]) {
            cout << name << " is ranked #" << (i+1) << " in year " << year << endl;
            return;
        }
    }
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