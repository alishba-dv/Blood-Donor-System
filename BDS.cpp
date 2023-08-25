#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// attributes for donors

struct join
{
    int date,
        month,
        year;
};
struct donor
{
    string name;
    string blood;
    int donations;
    string id;
    join date;
};
donor person[1000];
// menu for dis[play
void menu()
{
    cout << setw(60) << "------------------------------" << endl;
    cout << setw(60) << "  FCIT BLOOD DONOR SOCIETY   " << endl;
    cout << setw(60) << "------------------------------" << endl;
    cout << "\n 1) Add donor’s record." << endl;
    cout << " 2) Search the donor’s record based on name. (To respond a blood request)" << endl;
    cout << " 3) Search a list of donors based on blood group. (To respond a blood request)" << endl;
    cout << " 4) Update the donor’s record. (After successful donation)" << endl;
    cout << " 5) Remove donor’s record (May be due to medical reasons)." << endl;
    cout << " 6) Exit program." << endl;
    cout << "\nPlease select 1 to 6\n==>";
}
// function to get input from user and saving into text file

void input(struct donor person[], int number)
{
    fstream Datafile;
    Datafile.open("bds_donor_data.txt", ios::out | ios::app);

    if (Datafile)
    {
        for (int i = 0; i < 1000; i++)
        {
            if (i == number)
            {
                break;
                Datafile.close();
            }

            cout << "DONOR#" << i + 1 << ":" << endl;
            cout << "Enter name: ";

            cin >> person[i].name;
            Datafile << person[i].name << " ";

            cout << "Enter blood group: ";
            cin >> person[i].blood;
            Datafile << person[i].blood << " ";
            cout << "Enter number of donations: ";
            cin >> person[i].donations;
            Datafile << person[i].donations << " ";
            cout << "Enter ID of donor#" << i + 1 << ": ";
            cin >> person[i].id;
            Datafile << person[i].id << " ";
            cout << "Enter date of joining FBWS: ";
            cin >> person[i].date.date;
            cout << "Enter month of joining FBWS: ";
            cin >> person[i].date.month;
            cout << "Enter year of joining FBWS: ";
            cin >> person[i].date.year;
            Datafile << person[i].date.date << "-" << person[i].date.month << "-" << person[i].date.year << endl;

            // Datafile.write(reinterpret_cast<char *>(person), sizeof(person));

            //   Datafile.write((char *)&person[i], sizeof(person[i]));
        }
    }
    else
    {
        cout << "File not opened" << endl;
    }
}

// searching the name based record

void searchName(struct donor person[], string search)
{
    fstream Datafile;
    Datafile.open("bds_donor_data.txt", ios::in | ios::app);
    if (Datafile)
    {
        while (!Datafile.eof())
        {

            for (int i = 0; i < 1000; i++)
            {
                // Datafile.read(reinterpret_cast<char *>(person), sizeof(person));
                Datafile >> person[i].name;

                if (search == person[i].name)
                {

                    cout << "DONOR#" << i + 1 << ":" << endl;
                    cout << "Name: " << person[i].name << endl;

                    Datafile >> person[i].blood;
                    Datafile >> person[i].donations;
                    Datafile >> person[i].id; // taking record from data file
                    Datafile >> person[i].date.date;
                    Datafile >> person[i].date.month;
                    Datafile >> person[i].date.year;
                    cout << "Blood group: " << person[i].blood << endl;
                    cout << "Number of Donations: " << person[i].donations << endl;
                    cout << "ID: " << person[i].id << endl;
                    cout << "Date of joining: " << person[i].date.date << "/" << person->date.month << "/" << person[i].date.year << endl;
                    continue;
                }
            }
            break;
        }
    }
    else
    {
        cout << "File Not Opened!" << endl;
    }
}

// function for searching blood group  based record

void searchBlood(struct donor person[], string bloodgroup)
{
    ifstream Datafile;
    Datafile.open("bds_donor_data.txt", ios::in);

    if (Datafile)
    {
        while (!Datafile.eof())
        {
            for (int i = 0; i < 1000; i++)
            {
                Datafile >> person[i].name;
                Datafile >> person[i].blood;

                if (bloodgroup == person[i].blood)
                {
                    cout << "DONOR#" << i + 1 << ":" << endl;
                    cout << "Name: " << person[i].name << endl;
                    cout << "blood: " << person[i].blood << endl;
                    Datafile >> person[i].donations;
                    Datafile >> person[i].id;
                    Datafile >> person[i].date.date;
                    Datafile >> person[i].date.month;
                    Datafile >> person[i].date.year;

                    cout << "Number of Donations: " << person[i].donations << endl;
                    cout << "ID: " << person[i].id << endl;
                    cout << "Date of joining: " << person[i].date.date << "/" << person->date.month << "/" << person[i].date.year << endl;
                    continue;
                }
                break;
            }
        }
    }
}

// function to delete record

void delRecord(struct donor person[], string delID)
{
    string str;
    ofstream tempfile;
    tempfile.open("DelRecord.txt", ios::out);
    fstream Datafile;
    Datafile.open("bds_donor_data.txt");
    while (getline(Datafile, str))
    {
        int pos = 0;
        int index;
        if ((index = str.find(delID, pos)) != string::npos) // to delete a line
        {
            cout << "Record deleted successfully" << endl;
        }
        else if (tempfile)
        {
            tempfile << str << endl;
        }
    }
    remove("bds_donor_data.txt");
    rename("DelRecord.txt", "bds_donor_data.txt");
}
void UpdateRecord(struct donor person[], string UpdateID)
{
    fstream Datafile;
    string str;
    Datafile.open("bds_donor_data.txt");
    ofstream UpdateFile;
    UpdateFile.open("UpdateFile.txt", ios::out);
    int i = 0;
    while (getline(Datafile, str))
    {
        int pos = 0;
        int index;
        if ((index = str.find(UpdateID, pos)) != string::npos)
        {
            cout << "Enter Updated name: ";
            cin >> person[i].name;
            UpdateFile << person[i].name << " ";

            cout << "Enter Updated blood group: ";
            cin >> person[i].blood;
            UpdateFile << person[i].blood << " ";
            cout << "Enter Updated number of donations: ";
            cin >> person[i].donations;
            UpdateFile << person[i].donations << " ";
            cout << "Enter Updated ID of donor#" << i + 1 << ": ";
            cin >> person[i].id;
            UpdateFile << person[i].id << " ";
            cout << "Enter Updated date of joining FBWS: ";
            cin >> person[i].date.date;
            cout << "Enter Updated month of joining FBWS: ";
            cin >> person[i].date.month;
            cout << "Enter Updated year of joining FBWS: ";
            cin >> person[i].date.year;
            UpdateFile << person[i].date.date << "-" << person[i].date.month << "-" << person[i].date.year << endl;
        }
        else if (UpdateFile)
        {
            UpdateFile << str << endl;
        }
    }
    remove("bds_donor_data.txt");
    rename("UpdateFile.txt", "bds_donor_data.txt");
}
int main()

{
    int total_number = 0;

    int choice;
    donor person[1000];
    do
    {
        menu();

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            cout << "Enter number of donors to add: ";
            int number;
            cin >> number;

            system("clear");

            input(person, number);
            break;
        }
        case 2:
        {

            string search;
            cout << "Enter name of donor to search record: ";
            cin >> search;

            searchName(person, search);
            break;
        }
        case 3:
        {
            string bloodgroup;
            cout << "Enter blood group of donor to search record: ";
            cin >> bloodgroup;

            searchBlood(person, bloodgroup);
            break;
        }
        case 4:
        {
            string updateID;
            cout << "Enter ID of donor to update record: ";
            cin >> updateID;
            UpdateRecord(person, updateID);
            break;
        }

        case 5:
        {
            string delID;
            cout << "Enter ID of donor to delete record: ";
            cin >> delID;
            delRecord(person, delID);
            break;
        }
        default:
        {
            cout << "PLEASE ENTER VALID NUMBER!" << endl;
        }
        }

    } while (choice != 6);

    return 0;
}
