// Pipeline_transportation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    int comp_workshops_working;
    int comp_station_class;
};

int main()
{
    Pipeline pipe{};
    Compressor_station comp{};
    
    int user_inp;

    cout << "1.Add pipe" << endl;
    cout << "2.Add compressor station" << endl;
    cout << "3.View all items" << endl;
    cout << "4.Edit pipe" << endl;
    cout << "5.Edit compressor station" << endl;
    cout << "6.Save" << endl;
    cout << "7.Upload" << endl;
    cout << "0.Exit" << endl;

    cout << "Enter: ";
    cin >> user_inp;
    
    while (user_inp != 0) 
    {
        switch (user_inp)
        {
        case 0:
            cout << "Program terminated." << endl;
            break;
        case 1:
            cout << "Enter pipe name: ";
            cin >> pipe.pipe_name;

            cout << "Enter pipe length: ";
            cin >> pipe.pipe_length;

            cout << "Enter pipe diameter: ";
            cin >> pipe.pipe_diameter;

            cout << "Enter pipe condition: ";
            cin >> pipe.pipe_condition;
            break;
        case 2:
            cout << "Enter compressor name: ";
            cin >> comp.comp_name;

            cout << "Enter number of workshops: ";
            cin >> comp.comp_workshops;

            cout << "Enter number of working workshops: ";
            cin >> comp.comp_workshops_working;

            cout << "Enter station class: ";
            cin >> comp.comp_station_class;
            break;
        case 3:
            cout << "Pipe name: " << pipe.pipe_name << endl;
            cout << "Pipe length: " << pipe.pipe_length << endl;
            cout << "Pipe diameter: " << pipe.pipe_diameter << endl;
            cout << "Pipe condition: " << pipe.pipe_condition << endl;

            cout << "Compressor name: " << comp.comp_name << endl;
            cout << "Number of workshops: " << comp.comp_workshops << endl;
            cout << "Number of working workshops: " << comp.comp_workshops_working << endl;
            cout << "Station class: " << comp.comp_station_class << endl;
            break;

        case 4:
            cout << "Current status:" << pipe.pipe_condition << endl;
            cout << "Enter the new status:";
            cin >> pipe.pipe_condition;
            break;
        case 5:
            int user_inp_2;
            cout << "Total workshops:" << comp.comp_workshops << endl;
            cout << "Working workshops:" << comp.comp_workshops_working << endl;

            cout << "What do you want to do ?" << endl;
            cout << "1.Start a workshop" << endl;
            cout << "2.Stop a workshop" << endl;

            cout << "Enter: ";
            cin >> user_inp_2;

            if (user_inp_2 == 1 && (comp.comp_workshops_working < comp.comp_workshops))
            {
                cout << "New number of working workshops:" << ++comp.comp_workshops_working;
            }
            else if (user_inp_2 == 2 && comp.comp_workshops_working != 0)
            {
                cout << "New number of working workshops:" << --comp.comp_workshops_working;
            }
            else
            {
                cout << "ERROR" << endl;
            }
            break;
        case 6:
            break;
        case 7:
            break;

        }
        cout << "Enter: ";
        cin >> user_inp;
    }      
}
