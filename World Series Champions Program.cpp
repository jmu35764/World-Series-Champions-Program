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
        cerr << "Error Opening File!" << std::endl;
    }

   
    while (getline(File1, team))
    {
        teams.push_back(team);
    }
    x = 0;

    while (getline(File2, win))
    {
        winners.push_back(win);
    }

}

void findWinner(string teamname, vector<string> winners)
{
     while (teamname != "quit")
    {
        int counter = 0;
        int y = 0;
        cout << "Enter the name of a team (enter quit to end):" << endl;
        getline(cin, teamname);
        cout << endl;

        for (string val : winners)
        {
            if (teamname == winners[y])
            {
                counter++;
            }
             y++;
        }
        if (teamname != "quit")
        {
            cout << teamname << " won the World Series " << counter << " times." << endl;
        }
          
        else
        {
            cout << endl;
        }
    }
}

    
int main()
{
    string filename1 = "Teams.txt";
    string filename2 = "WorldSeriesWinners.txt";
    vector<string> Teams;
    string Team;
    vector<string> Winners;
    string Winner;
    string teamName;
    
    getTeams(filename1, filename2, Teams, Team, Winners, Winner);
    findWinner(teamName, Winners);

}