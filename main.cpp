#include <QCoreApplication>
#include <initkuainrule.h>
#include <expression.h>
#include <custompair.h>
#include <normalform.h>
#include <bitset>
#include <iostream>
#include <fstream>
#include <minijson_writer.hpp>
int main(int argc, char *argv[])
{
    std::cout<<"Start\n\n\n";
    QCoreApplication a(argc, argv);    
    //dfhfdghdfgfgd

    std::filebuf* fout = new std::filebuf;
    std::streambuf* backup = std::cout.rdbuf();
        if(! fout->open("A:\\qtProject\\text.txt", std::ios::out | std::ios::trunc))
            throw std::runtime_error("File A:\\qtProject\\text.txt cannot be opened");
    std::cout.rdbuf(fout);

    //        
    InitKuainRule k(4, {0,1,4,6,7,8,9,14,15});
    NormalForm *result = k.run();
    std::cout << k.print();
    //

    fout->close();
    delete fout;
    std::cout.rdbuf(backup);
    std::cout<<"OK";

    //
    std::cout<<"\n\n\nEnd";
    return a.exec();
}

/*
enum type {disjunction = false, conjuncture = true};
*/

//4, {0,1,4,6,7,8,9,14,15} wiki
//3, {0, 1, 2, 5, 6, 7} http://posibnyky.vntu.edu.ua/kondratenko/3..htm
//4, {1, 3, 5, 7, 14, 15} Лекция 119. Метод Квайна
