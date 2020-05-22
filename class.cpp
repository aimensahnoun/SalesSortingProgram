#include <iostream>
#include <string>
#include <iomanip>
#include "TermProj.h"

using namespace std;

TermProj::TermProj(){
    for(int i = 0 ; i<tableSize ; i++){
        hashTable[i] = new product;
        hashTable[i]->StockCode = "Empty";
        hashTable[i]->Description = "Empty";
        hashTable[i]->Quantity = 0;
    }
}
int TermProj::hasher(string key) {
    int sum;
    int x = 0;

    while(key[x] != '\0'){
        sum += (int)key[x];

        x++;
    }

    return (sum/4)%tableSize;
}

void TermProj::insertProduct(int index,string code, int quantity , string name) {
    int lin =1;
    int i;
    bool done = false;
    while (done==false){
        if(hashTable[index]->StockCode == "Empty") {
            hashTable[index]->StockCode = code;
            hashTable[index]->Quantity = quantity;
            hashTable[index]->Description = name;
            done = true;
        }
        else if(hashTable[index]->StockCode == code ){
            hashTable[index]->Quantity += quantity;
            done = true;
        }
            else{
                 i = index+ lin;
            if(hashTable[i]->StockCode == "Empty"){

                hashTable[i]->StockCode = code;
                hashTable[i]->Quantity = quantity;
                hashTable[i]->Description = name;
                done = true;
            }else if(hashTable[i]->StockCode !=code){
                ++lin;
            }else if(hashTable[i]->StockCode == code){
                hashTable[i]->Quantity += quantity;
                done = true;
            }
        }
    }
}



void TermProj::printTable() {

    cout << "StockCode" << setw(30) <<  "Description" << '\t' << setw(30) << "TotalQuantity"<< "\n";
    for (int i = tableSize-1; i > tableSize-11 ; i--)
    {
        {
            cout << hashTable[i]->StockCode << setw(40) << hashTable[i]->Description<< '\t' << setw(20) << hashTable[i]->Quantity << endl;
        }
    }
}



void TermProj::insertionSort()
{
    int i,  j;
    int tempQ;
    string tempS , tempD;
    for (i = 1; i < tableSize; i++)
    {
        tempQ = hashTable[i]->Quantity;
        tempD = hashTable[i]->Description;
        tempS = hashTable[i]->StockCode;
        j = i - 1;


        while (j >= 0 && hashTable[j]->Quantity > tempQ)
        {
            hashTable[j + 1]->Description = hashTable[j]->Description;
            hashTable[j + 1]->StockCode = hashTable[j]->StockCode;
            hashTable[j + 1]->Quantity = hashTable[j]->Quantity;
            j = j - 1;
        }
        hashTable[j + 1]->Description = tempD;
        hashTable[j + 1]->StockCode = tempS;
        hashTable[j + 1]->Quantity = tempQ;

    }
}





