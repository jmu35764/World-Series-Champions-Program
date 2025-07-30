// World Series Champions Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void getTeams(string filename1, string filename2, vector<string>& teams, string team, vector<string>& winners, string win)
{
    int x = 0;

    ifstream File1(filename1);
    ifstream File2(filename2);

    if (!File1 && !File2)
    {
        std::cerr << "Error Opening File!" << std::endl;
        //return 1;
    }

   
    while (getline(File1, team))
    {
        teams.push_back(team);
        //cout << teams[x] << endl;
        //x++;

    }
    x = 0;

    cout << endl;

    while (getline(File2, win))
    {
        //cout << "Test" << endl;
        winners.push_back(win);
       // cout << winners[x] << endl;
        //x++;
    }

}

int main()
{
    //int x = 0;
    string filename1 = "Teams.txt";
    string filename2 = "WorldSeriesWinners.txt";
    vector<string> Teams;
    string Team;
    vector<string> Winners;
    string Winner;
    string teamName;
    //int counter = 0;
    
    getTeams(filename1, filename2, Teams, Team, Winners, Winner);

    while (teamName != "quit")
    {
        int counter = 0;
        int x = 0;
        cout << "Enter Team Name" << endl;
        getline(cin, teamName);

        for (string val : Winners)
        {
            //cout << "test" << endl;
            if (teamName == Winners[x])
            {
                //cout << "test" << endl;
                counter++;
            }
            x++;
        }

        cout << teamName << " won the World Series " << counter << " times." << endl;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
