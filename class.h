#include <iostream>
#include <string>

#pragma once

using namespace std;


class TermProj {
private:
    const static int tableSize = 5000;
    struct product{
        string StockCode;
        string Description;
        int Quantity;
    };

    product* hashTable[tableSize] ;



public:
    TermProj();
    int hasher(string key);
    void insertProduct(int index,string code, int quantity , string name);
    void printTable();
    void insertionSort();

};



