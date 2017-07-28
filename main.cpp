#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <limits.h>
//#include "Functions.cpp"
#include "header.hpp"
#include "Graph.h"


using namespace std;
//Made by Tristan Poulsen
//CSCI2270
//Instructor Montero Quesada
//FINAL PROJECT
//Code is property of Tristan Poulsen and
//Real Tech Innovations LLC

vector <vertex> vertices;
int districtIDIndex;
//struct vertex vertices[4];

void printGraph();
void insertEdge(int vertex1, int vertex2, int weight);
void InsertVertex(int vertexKey);
void Dijkstra(int start, int end);

int main(int argc, char *argv[1]) {
// file is passed in as
    // a command-line argument
    //cout << "What is the file key?" << endl;
    ifstream in;
    if (argc != 2) {
        // Display an error message
        cout << "File key not provided" << endl;
        return 0;
    }
    else {
        // open the file
        in.open(argv[1]);
    }
    ClientTree Clients;
    int r = 0;
    int m;
    int desk;
    string f;
    string l;
    int lap;
    int p;
    int tab;
    int tvs;
    string landmark1;
    string landmark2;
    string landmark_1;
    string landmark_2;
    // Declare variables
    string first;
    string last;
    string fkey;
    char ch;
    int rank, phone, laptop, tablet, tv, desktop, misc;
     if (in.is_open()) {
        while (in >> rank) {
            // read ch from file
            in >> ch;
            last = "";
            while (true) {
                ch = in.get();
                if (ch == ',') {
                    break;
                } else {
                    last += ch;
                }
            }
            // read data from the file
            //loop for first key
            first = "";
            while (true) {
                ch = in.get();
                if (ch == ',') {
                    break;
                }
                else {
                    first += ch;
                }
            }
            in >> phone;
            in >> ch;
            in >> laptop;
            in >> ch;
            in >> tablet;
            in >> ch;
            in >> tv;
            in >> ch;
            in >> desktop;
            in >> ch;
            in >> misc;
            //send data to add client
            Clients.addClient(rank, last, first, phone, laptop, tablet, tv, desktop, misc);
        }
    }
    else {
        // display an error message
        cout << "Can not open the file"
             << endl;
        return 0;
    }
    in.close();
    //GRAPHS*************************************************
    ifstream inFile;    //Variable to open text file
    string strLine;     //Variable to store each line of the text file
    string *landmarks;     //Dynamic array to store each landmark
    int **landmarkDistanceValues;      //Dynamic two dimensional array to store distances between landmarks


    int numLines = -1;  //Variable to store the number of lines in the file

    Graph g;    //Create an instance of the graph class

    inFile.open("Cities.txt");    //Open the file to read in the data

    if(inFile.fail())
        cout << "File did not open." << endl;
    else
    {
        //While not at end of the file, get each line and increment the line counter
        while(inFile.good())
        {
            getline(inFile, strLine);
            numLines++;
        }

        //Initialize both dynamic arrays
        landmarks = new string [numLines-1];
        landmarkDistanceValues = new int *[numLines-1]; //Initialize first dimension of two dimension array
        //Initialize second dimension of 2d array
        for(int i = 0; i < numLines-1; i++)
            landmarkDistanceValues[i] = new int[numLines-1];

        //Clear the file and reset to beginning of file to read in data
        inFile.clear();
        inFile.seekg(0, ios::beg);

        //Get the first line of the file
        getline(inFile, strLine);

        //Find all of the commas in the first line
        int comma1 = strLine.find(',');
        int comma2 = strLine.find(',', comma1+1);

        for(int i = 0; i < numLines-1; i++)
        {
            //Loop through just the first line adding in all landmarks to the landmarks array
            landmarks[i] = strLine.substr(comma1+1, comma2-comma1-1);
            comma1 = comma2;
            comma2 = strLine.find(',', comma2+1);
        }


        //Create variable line length to get the last landmark name in the file without getting the extra \r sequence
        //int lineLength = strLine.substr(comma1+1).length();
        //landmarks[numLines-2] = strLine.substr(comma1+1, lineLength-1);

        int index = 0;  //Variable to keep track of all of the lines traversed in the file

        while(inFile.good())
        {
            //Get line in file
            getline(inFile, strLine);

            int comma3 = strLine.find(',');
            int comma4 = strLine.find(',', comma3+1);

            //Loop through the remaining lines and add all numerical values to the 2d array
            //Update the comma values for each numerical value
            for(int i = 0; i < numLines-1; i++)
            {
                landmarkDistanceValues[index][i] = atoi(strLine.substr(comma3+1, comma4-comma3-1).c_str());
                comma3 = comma4;
                comma4 = strLine.find(',', comma4+1);
            }

            index++;
            if(index == numLines-1)
                break;

        }
    }

    inFile.close();

    //Add all landmarks to the graph as vertices
    for(int k = 0; k < numLines-1; k++)
    {
        g.addVertex(landmarks[k]);
    }


    //Loop through the 2d array and add all edges on the graph between vertices
    for(int i = 0; i < numLines-1; i++)
    {
        for(int j = 0; j < numLines-1; j++)
        {
            //Make sure the distance value is greater than 0
            if(landmarkDistanceValues[i][j] > 0)
            {
                g.addEdge(landmarks[i], landmarks[j], landmarkDistanceValues[i][j]);
                //If one edge was already created, set the corresponding value to -10 so two edges are not created for the same vertices
                landmarkDistanceValues[j][i] = -10;

            }
        }
    }
    //**********************************

    // Declare a variable
    int option;
    // This loop displays a menu
    do
    {
        cout << "===Main Menu===" << endl;
        cout << "1. Add a new Client" << endl;
        cout << "2. Print client list(keys)" << endl;
        cout << "3. Delete a client" << endl;
        cout << "4. Count the clients" << endl;
        cout << "5. Summarize client data" << endl;
        cout << "6. Find the shortest path for a claim" << endl;
        cout << "7. Calculate a claim distance and cost" << endl;
        cout << "8. Quit" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "Enter First Name: " << endl;
                cin >> f;
                cout << "Enter Last Name: " << endl;
                cin >> l;
                cout << "Enter Number of phones: " << endl;
                cin >> p;
                cout << "Enter Number of laptops: " << endl;
                cin >> lap;
                cout << "Enter Number of tablets: " << endl;
                cin >> tab;
                cout << "Enter Number of tv's: " << endl;
                cin >> tvs;
                cout << "Enter Number of desktops: " << endl;
                cin >> desk;
                cout << "Enter Number of misc: " << endl;
                cin >> m;
                Clients.addClient(r, l, f, p, lap, tab, tvs, desk, m);
                break;
            case 2:
                Clients.printClientList();
                break;
            case 3:
                cout << "Enter Last Name:" << endl;
                cin >> last;
                if (last == "Root"){
                    cout << "You don't have permission to delete the root" << endl;
                }
                else{
                    Clients.deletefunc(last);
                    Clients.ClientNodeCounter--;
                }
                break;
            case 4:
                Clients.countClients();
                break;
            case 5:
                Clients.summarizeClientData();
                break;
            case 6: {
                //Shortest Path
                //Two variables to keep track of each city
                //Find the shortest path between two cities using breadth-first
                cout << "Enter a starting landmark:" << endl;
                cin >> landmark_1;
                cout << "Enter an ending landmark:" << endl;
                cin >> landmark_2;
                cout << "Number of stops: ";
                g.breadthFirstSearch(landmark_1, landmark_2);
                break;
            }
            case 7: {
                //GRAPH SECTION
                //Find shortest distance between two cities using Dijkstra's algorithm
                cout << "Enter a starting landmark:" << endl;
                cin >> landmark1;
                cout << "Enter an ending landmark:" << endl;
                cin >> landmark2;
                cout << "Distance: ";
                g.dijkstra(landmark1, landmark2);
                break;
            }
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }
    while (option != 8);
    cout << "Goodbye!" << endl;
    return 0;
}

//how to launch..
//g++ -std=c++11 Functions.cpp Graph.cpp  main.cpp -o FinalProject
//FinalProject FinalTestFile.txt