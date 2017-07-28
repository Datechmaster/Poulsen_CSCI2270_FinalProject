#ifndef FINALPROJECT_HEADER_HPP
#define FINALPROJECT_HEADER_HPP
//
// Created by Tristan Poulsen on 7/27/17.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct ClientNode {
    int ranking;
    ClientNode *parent;
    ClientNode *leftChild;
    ClientNode *rightChild;
    int deviceCount;
    int phoneCount;
    int laptopCount;
    int tabletCount;
    int tvCount;
    int desktopCount;
    int miscCount;
    string LastName; //this will be what we are searching from
    string FirstName;
    double clientRisk;
    ClientNode() {};
    ClientNode(int in_ranking, string in_lastname, string in_firstname, int in_phone, int in_laptop
            , int in_tablet, int in_tv, int in_desktop, int in_misc){
        ranking = in_ranking;
        LastName = in_lastname;
        FirstName = in_firstname;
        phoneCount = in_phone;
        tabletCount = in_tablet;
        tvCount = in_tv;
        desktopCount = in_desktop;
        miscCount = in_misc;
    }
};
class ClientTree {
public:
    ClientTree();
    virtual ~ClientTree();
    void addClient(int ranking, string last, string first, int phone, int laptop, int tablet, int tv, int desktop, int misc);
    ClientNode* searchClientTree(ClientNode *node, string last);
    void deletefunc(string last);
    ClientNode *treeMinimum();
    void countClients();
    void printClientList();
    void summarizeClientData();
    int totaldeviceCount = 0; // the TOTAl number of devices a client has
    int ClientNodeCounter = 0;
    double totalPremiums = 0;
private:
    void printClientList(ClientNode *node);
    void countClients(int ClientNodeCounter);
    ClientNode *root;
    void DeleteAll (ClientNode * node);
    void deleteClient(string value);
    ClientNode* search(string searchName);
    ClientNode *treeMinimum(ClientNode *node);
    ClientNode *treeMaximum(ClientNode *node);
    ClientNode *searchRecursive(ClientNode *node, string searchName);
};

#endif //FINALPROJECT_HEADER_HPP
