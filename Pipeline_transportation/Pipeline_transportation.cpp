// Pipeline_transportation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using namespace std;

struct Pipeline
{
    string pipe_name;
    double pipe_length;
    int pipe_diameter;
    bool pipe_condition;
};

struct Compressor_station
{
    string comp_name;
    int comp_workshops;
    int comp_station_class;

};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Pipeline pipe;
    pipe.pipe_name;
    pipe.pipe_length;
    pipe.pipe_diameter;
    pipe.pipe_condition;

    Compressor_station comp;
    comp.comp_name;
    comp.comp_workshops;
    comp.comp_station_class;
    
    int user_inp;

    cout << "1.Add pipe" << endl;
    cout << "2.Add compressor station" << endl;
    cout << "3.View all items" << endl;
    cout << "4.Edit pipe" << endl;
    cout << "5.Edit compressor station" << endl;
    cout << "6.Save" << endl;
    cout << "7.Upload" << endl;
    cout << "0.Exit" << endl;

    cin >> user_inp;

    
}
