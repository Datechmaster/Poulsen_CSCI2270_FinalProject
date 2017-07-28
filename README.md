# Poulsen_CSCI2270_FinalProject
Project for CSCI2270
//Made by Tristan Poulsen
//CSCI2270
//Instructor Montero Quesada
//FINAL PROJECT

PROJECT SUMMARY:
For my final project I'm creating a program that allows for
me to add and remove clients from a linked list. I want it to
print out all current clients and their basic information
count the number of clients, and summarize client data by going through the
list and conducting some math to generate some useful information to me.
For implementing graphs I will be implementing 2 functions that allow the
user to check the smallest path in the graph and the shortest distance
with cost of the shipping of a claim to a client. This program will actually
assist me with a business concept I'm working on.

HOW TO RUN:
Step 1) open terminal and run "g++ -std=c++11 Functions.cpp Graph.cpp  main.cpp -o FinalProject"
in folder with the program files
Step 2) start the program with "FinalProject FinalTestFile.txt" if on a Mac, if on a PC then run "./FinalProject FinalTestFile.txt"
Step 3) The Program is running! Try out the options of:
     1. Add a new Client - This will allow the user to add a new client to the BST
            Enter First Name:
            Jo
            Enter Last Name:
            Kay
            Enter Number of phones:
            1
            Enter Number of laptops:
            3
            Enter Number of tablets:
            4
            Enter Number of tv's:
            2
            .....continue entering device counts
     2. Print client list(keys) - This will allow the user to print and review the list of clients and their # of devices
             Client: Bezzina, Michael, device-count: 27 Client Risk: 0.119259%
             Client: Blart, Seth, device-count: 35 Client Risk: 0.133714%
             Client: Follow, Karly, device-count: 21 Client Risk: 0.132381%
             Client: Gordon, Kate, device-count: 33 Client Risk: 0.12%
             Client: Hollow, John, device-count: 36 Client Risk: 0.118333%
             Client: Jordan, Rachel, device-count: 20 Client Risk: 0.097%
             Client: Kay, Jo, device-count: 37 Client Risk: 0.092973%
             Client: Loesel, Michael, device-count: 30 Client Risk: 0.133333%
             Client: Poulsen, Tristan, device-count: 10 Client Risk: 0.086%
             Client: West, Chris, device-count: 11 Client Risk: 0.0963636%
     3. Delete a client - This will allow the user to delete a client from the list
            Enter Last Name:
            Kay
     4. Count the clients - This will call the count of the number of clients
            Tree contains: 9 clients.
     5. Summarize client data - This will summarize some client data for the user
            Total Clients: 10
            Total Devices: 223
            Total monthly premiums: $2120.36
     6. Find the shortest path for a claim - This will ask for 2 cities and find the shortest path # of cities
            Enter a starting landmark:
            Denver
            Enter an ending landmark:
            Dallas
            Number of stops: 1,  Denver,  Dallas
     7. Calculate a claim distance and cost - This will ask for 2 cities and find the lowest distance and cost of shipping a claim item to a client
            Enter a starting landmark:
            Denver
            Enter an ending landmark:
            Dallas
            Distance: 796, Denver, Dallas
            Cost to ship: $15.92
     8. Quit - This will quit the program
            Goodbye!
            Deleting: Gordon
            Deleting: Follow
            Deleting: Blart
            Deleting: Hollow
            Deleting: Loesel
            Deleting: Jordan
            Deleting: Bezzina
            Deleting: Poulsen
            Deleting: West
            Deleting: Root
Step 4) Press 8 to Quit
Step 5) Thank-you for taking a look at my program, hope you enjoyed

DEPENDENCIES:
My program has no dependencies that I know of other than standard libraries.

SYSTEM REQUIREMENTS:
My Program was tested on both Windows 10 and Mac OS. There aren't any other system requirements.

OPEN ISSUES/BUGS:
I found that the City of LosAngles on the Graph doesn't like to post any
information when Number 6 and Number 7 in the Main Menu are called. It's
the only city that does it and I wasn't able to figure out why in the Graph.