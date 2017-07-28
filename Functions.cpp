#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "header.hpp"
//
// Created by Tristan Poulsen on 7/27/17.
//

//Prints the client list function
void ClientTree::printClientList() {
    if (root == nullptr) {
        cout << "Movie Inventory is empty" << endl;
    }
    else {
        printClientList(root);
    }
}
// printMovieInventory() function definition
void ClientTree::printClientList(ClientNode *node){
    if (node == nullptr) {
        return;
    }
    else {
        printClientList(node->leftChild);
        if (node->LastName == "Root"){

        }
        else{
            cout << "Client: " << node->LastName<< ", " << node->FirstName << ", device-count: " << node->deviceCount;
            cout << " Client Risk: " << node->clientRisk << "%" << endl;
        }
        printClientList(node->rightChild);
    }
}

//Client Constructor
ClientTree::ClientTree() {
    root = nullptr;
}

//Client distructor
ClientTree::~ClientTree() {
    DeleteAll(root);
}

//Delete all function
void ClientTree::DeleteAll(ClientNode *node) {
    if (node == nullptr) {
        return;
    }
    else {
        DeleteAll(node->leftChild);
        DeleteAll(node->rightChild);
        cout << "Deleting: " << node->LastName << endl;
        delete node;
    }
}

//Add client function
void ClientTree::addClient(int ranking, string last, string first, int phone, int laptop, int tablet, int tv, int desktop, int misc){
    ClientNode *addNode = new ClientNode;
    addNode->ranking = ranking;
    addNode->LastName = last;
    addNode->FirstName = first;
    addNode->phoneCount = phone;
    addNode->laptopCount = laptop;
    addNode->tabletCount = tablet;
    addNode->tvCount = tv;
    addNode->desktopCount = desktop;
    addNode->miscCount = misc;
    addNode->leftChild = nullptr;
    addNode->rightChild = nullptr;
    addNode->clientRisk = (((.2 * phone)+(.08 * laptop)+(.2 * tablet)+(.06 * tv)+(.06 * desktop)+(.08 * misc))/(phone+laptop+tablet+tv+desktop+misc));
    addNode->deviceCount = (phone+laptop+tablet+tv+desktop+misc);
    totaldeviceCount = totaldeviceCount + (phone+laptop+tablet+tv+desktop+misc);
    totalPremiums = totalPremiums + ((7.99 * phone)+(19.8 * laptop)+(7.99 * tablet)+(5.99 * tv)+(8.99 * desktop)+(4.99 * misc));
    if (root == nullptr){
        root = addNode;
        addNode->parent = nullptr;
        ClientNodeCounter++;
    }
    else{
        ClientNode *foundMovie = searchClientTree(root, last);
        if (last < foundMovie->LastName) {
            if (foundMovie->leftChild == nullptr) {
                foundMovie->leftChild = addNode;
                addNode->parent = foundMovie;
                ClientNodeCounter++;
            }
        }
        else
        {
            if (foundMovie->rightChild == nullptr) {
                foundMovie->rightChild = addNode;
                addNode->parent = foundMovie;
                ClientNodeCounter++;
            }
        }
    }
}

//Searches the Client Tree for a client with the designated last name
ClientNode *ClientTree::searchClientTree(ClientNode *node, string last) {
    if (node->LastName == last) {
        return node->parent;
    }
    else if (node->LastName > last) {
        if (node->leftChild == nullptr) {
            return node;
        }
        return searchClientTree(node->leftChild, last);
    }
    else {
        if (node->rightChild == nullptr) {
            return node;
        }
        return searchClientTree(node->rightChild, last);
    }
}

//Function that calls the delete client function
void ClientTree::deletefunc(string last){
    deleteClient(last);
}

//Deletes a client from the tree
void ClientTree::deleteClient(string value){
    ClientNode *node = search(value);
    if (node==nullptr) {
        cout<<"Movie not found"<<endl;
        return;
    }
    if (node != root) {
        if (node->leftChild == nullptr && node->rightChild == nullptr) {//no children
            if (node->parent->leftChild == node) {//node is a left child
                node->parent->leftChild = nullptr;
            } else { //node is a right child
                node->parent->rightChild = nullptr;
            }
        } else if (node->leftChild != nullptr && node->rightChild != nullptr) {//two children
            ClientNode *min = treeMinimum(node->rightChild);//replacement min right subtree
            if (min == node->rightChild) {//replacement node rightChild
                if (node->parent->leftChild == node) {//node is a leftChild
                    node->parent->leftChild = min;
                    min->parent = node->parent;
                    min->leftChild = node->leftChild;
                    min->leftChild->parent = min;
                } else {//node is a rightChild
                    node->parent->rightChild = min;//connecting 45 to 90
                    min->parent = node->parent;//connecting 90 to 45
                    min->leftChild = node->leftChild; //shifting 54
                    min->leftChild->parent = min;//shilfting 54
                }
            } else {//replacement is not the rightChild of node e.g. 12
                if (node->parent->leftChild == node) {//node is leftChild
                    min->parent->leftChild = min->rightChild;//detaching min
                    //linking min rightChild, next should have a conditional
                    if (min->rightChild != nullptr) min->rightChild->parent = min->parent;
                    min->parent = node->parent;//linking min to parent
                    node->parent->leftChild = min;//linking parent to min
                    min->leftChild = node->leftChild;//linking min to left child
                    node->leftChild->parent = min;//linking left child to min
                    min->rightChild = node->rightChild;//linking min to right child
                    node->rightChild->parent = min;//linking right child to min
                } else {//node is rightChild e.g. 56 with 60 (not in the example)
                    min->parent->leftChild = min->rightChild;//detaching min from parent
                    //linking min rightChild, next should have a conditional
                    if (min->rightChild != nullptr) min->rightChild->parent = min->parent;
                    min->parent = node->parent;//linking min to parent
                    node->parent->rightChild = min;//linking parent to min
                    min->leftChild = node->leftChild;//linking min to left child 54
                    node->leftChild->parent = min;//linking left child 54 to min
                    min->rightChild = node->rightChild;//linking min to right child
                    node->rightChild->parent = min;//linking right child to min
                }
            }
        } else {//one child
            if (node->parent->leftChild == node) {//node is leftChild
                if (node->leftChild != nullptr) {//node has a leftChild
                    node->leftChild->parent = node->parent;
                    node->parent->leftChild = node->leftChild;
                } else {//node has a rightChild
                    node->rightChild->parent = node->parent;
                    node->parent->leftChild = node->leftChild;
                }
            } else {//node is rightChild
                if (node->leftChild != nullptr) {//node has a left child
                    node->leftChild->parent = node->parent;//linking leftChild
                    node->parent->rightChild = node->leftChild;//detaching node
                } else {//node has a rightChild
                    node->rightChild->parent = node->parent;//linking rightChild
                    node->parent->rightChild = node->rightChild;//detaching node
                }
            }
        }
    } else {//node to delete is root so node->parent = nullptr
        //replacement node is the new root
        //parent of replacement is nullptr
        if (node->leftChild == nullptr && node->rightChild == nullptr) {//no children,
            root = nullptr;
        }// root without children just need to be deallocated
        else if (node->leftChild != nullptr && node->rightChild != nullptr) {//two children
            ClientNode *min = treeMinimum(node->rightChild);//replacement min right subtree
            if (min == node->rightChild) {//replacement node rightChild
                min->parent = node->parent;
                min->leftChild = node->leftChild;
                min->leftChild->parent = min;
            } else {//replacement is not the rightChild of node, but it is a leftChild of a node

                //linking min rightChild, next should have a conditional
                if (min->rightChild != nullptr) {
                    min->rightChild->parent = min->parent;
                    min->parent->leftChild = min->rightChild;
                }
                min->parent = node->parent;//linking min to parent
                //node->parent->leftChild = min;//linking parent to min
                min->leftChild = node->leftChild;//linking min to left child
                node->leftChild->parent = min;//linking left child to min

                min->rightChild = node->rightChild;//linking min to right child
                node->rightChild->parent = min;//linking right child to min
            }
            root = min;
        } else {//one child
            if (node->leftChild == nullptr) {//node has a rightChild
                node->rightChild->parent = node->parent;
                root = node->rightChild;
            } else {//node has a leftChild, don't have a substitute in the right subtree
                //find a max in left subtree;
                ClientNode *max = treeMaximum(node->leftChild);//replacement min right subtree
                /*if (min == node->rightChild){//replacement node rightChild

                    min->parent = node->parent;
                    min->leftChild = node->leftChild;
                    min->leftChild->parent = min;

                }else {//replacement is not the rightChild of node, but it is a leftChild of a node

                    //linking min rightChild, next should have a conditional
                    if (min->rightChild!=nullptr) {
                        min->rightChild->parent = min->parent;
                        min->parent->leftChild = min->rightChild;

                    }
                    min->parent = node->parent;//linking min to parent
                    //node->parent->leftChild = min;//linking parent to min
                    min->leftChild = node->leftChild;//linking min to left child
                    node->leftChild->parent = min;//linking left child to min

                    min->rightChild = node->rightChild;//linking min to right child
                    node->rightChild->parent = min;//linking right child to min
                */
                root = max;
            }
        }
        delete node;
    }
}

//Checks the tree minimum
ClientNode* ClientTree::treeMinimum(ClientNode *node){
    if (node==nullptr) return nullptr;
    else {
        while (node->leftChild != nullptr){
            node = node->leftChild;
        }
        return node;
    }
}

//Checks the tree maximum
ClientNode* ClientTree::treeMaximum(ClientNode *node){
    if (node==nullptr) return nullptr;
    else {
        while (node->rightChild != nullptr){
            node = node->rightChild;
        }
        return node;
    }
}

//Search's the tree function recursivly for the DELETE Function
ClientNode *ClientTree::searchRecursive(ClientNode *node, string searchName){
    if(node==nullptr)return nullptr;//if tree is empty
    if (node->LastName==searchName) return node;
    else if(node->LastName > searchName)
        return searchRecursive(node->leftChild,searchName);
    else
        return searchRecursive(node->rightChild, searchName);
}

//Calls the private search tree function
ClientNode *ClientTree::search(string searchName){
    return searchRecursive(root, searchName);
}

//Counter function that calls a return for the count of clients in the tree
void ClientTree::countClients(int ClientNodeCounter){

    //movieNodeCounter = getCount(node);
    cout << "Tree contains: " << ClientNodeCounter << " " << "clients." << endl;
}
void ClientTree::countClients() {
    countClients(ClientNodeCounter);
}

//Function that summarizes the client data
void ClientTree::summarizeClientData(){
    cout << "Total Clients: " << ClientNodeCounter << endl;
    cout << "Total Devices: " << totaldeviceCount << endl;
    cout << "Total monthly premiums: $" << totalPremiums << endl;
}