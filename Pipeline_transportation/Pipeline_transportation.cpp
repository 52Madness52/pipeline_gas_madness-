// Pipeline_transportation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
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

void Menu_print()
{
    cout << "1.Add pipe" << endl;
    cout << "2.Add compressor station" << endl;
    cout << "3.View all items" << endl;
    cout << "4.Edit pipe" << endl;
    cout << "5.Edit compressor station" << endl;
    cout << "6.Save" << endl;
    cout << "7.Upload" << endl;
    cout << "0.Exit" << endl << endl;
}

void Pipeline_print(const Pipeline& pipe)
{
    cout << "Pipe name: " << pipe.pipe_name << endl;
    cout << "Pipe length: " << pipe.pipe_length << endl;
    cout << "Pipe diameter: " << pipe.pipe_diameter << endl;
    cout << "Pipe condition: " << pipe.pipe_condition << endl;
}

void Compressor_print(const Compressor_station& comp)
{
    cout << "Compressor name: " << comp.comp_name << endl;
    cout << "Number of workshops: " << comp.comp_workshops << endl;
    cout << "Number of working workshops: " << comp.comp_workshops_working << endl;
    cout << "Station class: " << comp.comp_station_class << endl;
}

void Pipeline_input(Pipeline& pipe)
{
    string condition;

    cout << "Enter pipe name: ";
    cin >> pipe.pipe_name;

    cout << "Enter pipe length: ";
    cin >> pipe.pipe_length;

    cout << "Enter pipe diameter: ";
    cin >> pipe.pipe_diameter;


    while (condition != "No" || condition != "Yes")
    {
        cout << "Enter pipe condition (Yes/No): ";
        cin >> condition;

        if (condition == "Yes")
        {
            pipe.pipe_condition = true;
            break;
        }
        else if (condition == "No")
        {
            pipe.pipe_condition = false;
            break;
        }
        else
        {
            cout << "invalid input for pipe condition" << endl << endl;
        }
    }
}

void Compressor_input(Compressor_station& comp)
{
    cout << "Enter compressor name: ";
    cin >> comp.comp_name;

    cout << "Enter number of workshops: ";
    cin >> comp.comp_workshops;

    cout << "Enter number of working workshops: ";
    cin >> comp.comp_workshops_working;

    cout << "Enter station class: ";
    cin >> comp.comp_station_class;
}

void Pipe_edit(Pipeline& pipe)
{
    string condition1;

    if (pipe.pipe_condition == true)
    {
        cout << "Current status: Yes" << endl;
    }
    else if (pipe.pipe_condition = false)
    {
        cout << "Current status: No" << endl;
    }

    while (condition1 != "No" || condition1 != "Yes")
    {
        cout << "Enter the new status condition (Yes/No): ";
        cin >> condition1;
        if (condition1 == "Yes")
        {
            pipe.pipe_condition = true;
            break;
        }
        else if (condition1 == "No")
        {
            pipe.pipe_condition = false;
            break;
        }
        else
        {
            cout << "invalid input for pipe condition" << endl;
        }
    }
}

void Compressor_edit(Compressor_station& comp)
{
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
}

void File_save(Pipeline& pipe, Compressor_station& comp)
{
    ofstream file;
    file.open("data_pipe_comp.txt");
    file << pipe.pipe_name << endl;
    file << pipe.pipe_length << endl;
    file << pipe.pipe_diameter << endl;
    file << pipe.pipe_condition << endl;

    file << comp.comp_name << endl;
    file << comp.comp_workshops << endl;
    file << comp.comp_workshops_working << endl;
    file << comp.comp_station_class;
    file.close();
}

void File_upload(Pipeline& pipe, Compressor_station& comp)
{
    ifstream file("data_pipe_comp.txt");
    file >> pipe.pipe_name;
    file >> pipe.pipe_length;
    file >> pipe.pipe_diameter;
    file >> pipe.pipe_condition;
    file >> comp.comp_name;
    file >> comp.comp_workshops;
    file >> comp.comp_workshops_working;
    file >> comp.comp_station_class;
    file.close();
}

int main()
{
    Pipeline pipe{};
    Compressor_station comp{};
    
    int user_inp;

    Menu_print();
    cout << "Enter: ";
    cin >> user_inp;
    
    while (user_inp != 0) 
    {
        switch (user_inp)
        {
        case 0:
        {
            cout << endl;
            cout << "Program terminated." << endl;
            break;
        }
        case 1:
        {
            cout << endl;
            Pipeline_input(pipe);
            break;
        }
        case 2:
        {
            cout << endl;
            Compressor_input(comp);
            break;
        }
        case 3:
        {
            cout << endl;
            Pipeline_print(pipe);
            cout << endl;
            Compressor_print(comp);
            break;
        }
        case 4:
        {   
            cout << endl;
            Pipe_edit(pipe);
            break;
        }
        case 5:
        {
            cout << endl;
            Compressor_edit(comp);
            break;
        }  
        case 6: 
        {
            cout << endl;
            File_save(pipe, comp);
            break;
        }
        case 7: 
        {
            cout << endl;
            File_upload(pipe, comp);
            break;
        }
        }

        Menu_print();
        cout << "Enter: ";
        cin >> user_inp;
    }      
}
