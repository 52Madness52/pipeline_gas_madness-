

#include <iostream>
#include <fstream>
#include <limits>
#include <string>

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


void Int_error(int& value)
{
    while (true)
    {
        if (!(cin >> value))
        {
            cout << "invalid input try again: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        string rest;
        getline(cin, rest);

        if (rest.empty())
        {
            break;
        }

        cout << "invalid input try again: ";
    }
}

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
    cout << "Pipe condition: " << pipe.pipe_condition << endl << endl;
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
    while (!(cin >> pipe.pipe_length))
    {
        cout << "invalid input try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    
    cout << "Enter pipe diameter: ";
    Int_error(pipe.pipe_diameter);


    
    while (condition != "No" || condition != "Yes" || condition != "Y" || condition != "N")
    {
        cout << "Enter pipe condition (Yes/No): ";
        cin >> condition;

        if (condition == "Yes" || condition == "Y")
        {
            pipe.pipe_condition = true;
            break;
        }
        else if (condition == "No" || condition == "N")
        {
            pipe.pipe_condition = false;
            break;
        }
        else
        {
            cout << "invalid input for pipe condition" << endl << endl;
        }
    }

    cout << endl;
}

void Compressor_input(Compressor_station& comp)
{
    cout << "Enter compressor name: ";
    cin >> comp.comp_name;

    cout << "Enter number of workshops: ";
    Int_error(comp.comp_workshops);
  
    cout << "Enter number of working workshops: ";
    Int_error(comp.comp_workshops_working);
     
    cout << "Enter station class: ";
    Int_error(comp.comp_station_class);

    cout << endl;
}

void Pipe_edit(Pipeline& pipe)
{
    string condition_edit;

    if (pipe.pipe_condition == true)
    {
        cout << "Current status: Yes" << endl;
    }
    else if (pipe.pipe_condition = false)
    {
        cout << "Current status: No" << endl;
    }

    while (condition_edit != "No" || condition_edit != "Yes" || condition_edit != "Y" || condition_edit != "N")
    {
        cout << "Enter the new status condition (Yes/No): ";
        cin >> condition_edit;
        if (condition_edit == "Yes" || condition_edit == "Y")
        {
            pipe.pipe_condition = true;
            break;
        }
        else if (condition_edit == "No" || condition_edit == "N")
        {
            pipe.pipe_condition = false;
            break;
        }
        else
        {
            cout << "invalid input for pipe condition" << endl;
        }
    }

    cout << endl;
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
        cout << "New number of working workshops:" << ++comp.comp_workshops_working << endl;
    }
    else if (user_inp_2 == 2 && comp.comp_workshops_working != 0)
    {
        cout << "New number of working workshops:" << --comp.comp_workshops_working << endl;
    }
    else
    {
        cout << "ERROR" << endl << endl;
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
    file << comp.comp_station_class << endl;
    file.close();
}

void File_upload(Pipeline& pipe, Compressor_station& comp)
{
    ifstream file("data_pipe_comp.txt");

    if (!file.is_open())
    {
        cout << "Error: file not found." << endl;
        return;
    }

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
    bool Pipeline_add = false;
    bool Compressor_add = false;

    
    
    do
    {
        Menu_print();
        cout << "Enter: ";
        Int_error(user_inp);

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
            Pipeline_add = true;
            break;

        }
        case 2:
        {
            cout << endl;
            Compressor_input(comp);
            Compressor_add = true;
            break;
        }
        case 3:
        {
            if (Pipeline_add == true)
            {
                Pipeline_print(pipe);
            }
            else
            {
                cout << "Pipe dont find" << endl << endl;
            }
            if (Compressor_add == true)
            {
                Compressor_print(comp);
            }
            else
            {
                cout << endl << "Compressor station dont find" << endl;
            }
            cout << endl;
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
        default:
        {
            cout << "Invalid menu option. Try again" << endl << endl;
            break;
        }
        }
        
    } while (user_inp != 0 || (user_inp < 0 && user_inp > 7));    
}
