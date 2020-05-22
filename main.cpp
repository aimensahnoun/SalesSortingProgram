#include <iostream>
#include <fstream>
#include <string>
#include<chrono>
#include "TermProj.h"

using namespace std;


void readFile(TermProj inst){
    int line = 0;
    ifstream retail;
    retail.open("../OnlineRetail.csv");

    while(retail.good()){
        if(line == 0){
            retail.ignore(300,'\n');
            line ++;
        }else{

            string StockCode;
            string Description ;
            string Quantity ;
            retail.ignore(300,';');
            getline(retail , StockCode , ';');
            getline(retail , Description , ';');
            getline(retail , Quantity , ';');
            retail.ignore(300,';');
            retail.ignore(300,';');
            retail.ignore(300,';');
            retail.ignore(300,'\n');



            if(StockCode.length() == 0)
            {
                break;
            }
            else {
                int index = inst.hasher(StockCode);
               inst.insertProduct(index, StockCode, stoi(Quantity), Description);
            }





        }


    }

    retail.close();

}


int main() {

    /*
     * Project Group:
     * Özge Akdemir-1803128
     * Aimen Sahnoun-1801539
     * */

    auto B = chrono::steady_clock::now();
    TermProj test;
    readFile(test);

    test.insertionSort();
    test.printTable();

    auto E = chrono::steady_clock::now();
    cout << "Total Elapsed Time In Seconds : "
         << chrono::duration_cast<chrono::seconds> (E-B).count()
         << " Sec";
    return 0;
}