#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <cstdlib>

#include "defcls.hpp"
#include "defdata.hpp"
#include "datavector.hpp"
#include "scrman.hpp"

int main()
{
    int esc = 0;
    defcls::Funcs f;
    defcls::Enums e;
    datavector::pessoa_col pcol;
    defdata::vcdata_t vdata;
    std::vector<defdata::pessoa_t>::iterator it;
    std::vector<defdata::pessoa_t>::iterator itM;
    size_t sz = 0;
    size_t szM = 0;
    int szInt;
    int szIntmin;
    int szIntM;

    int tema = e.Escuro;
    scrman::DarkMode();

    while (true)
    { 
        scrman::Menu();
        std::cin >> esc;

        switch (esc)
        {
        case 1:
            defdata::Pessoa p;

            std::system("cls");
            p = scrman::Opc1();
            if (pcol.AdicionarPessoa(p))
                std::cout << "Pessoa adicionada com sucesso" << std::endl;
            else
                std::cout << "Pessoa nao adicionada!" << std::endl;
            std::system("pause");
            break;
        case 2:
            std::system("cls");
            std::cout << "Insira localizacao da pessoa no vector: ";
            std::cin >> sz;

            scrman::ImprimirInfoClassePessoa();
            scrman::ImprimirVector(pcol.pessoaVector, sz);
            std::system("pause");
            break;
        case 3:
            std::system("cls");

            vdata = pcol.VectorInfo();
            scrman::ImprimirInfoClassePessoa();

            for (sz = 0; sz < vdata.size; sz++)
            {
                scrman::ImprimirVector(pcol.pessoaVector, sz);
            }
            std::system("pause");
            break;
        case 4:
            std::system("cls");
            vdata = pcol.VectorInfo();

            std::cout << "Tamanho atual do vector: " << vdata.size << std::endl;
            std::cout << "Tamanho maximo do vector: " << vdata.maxSize << std::endl;
            std::system("pause");
            break;
        case 5:
            std::system("cls");
            std::cout << "Insira indice da pessoa a apagar: ";
            std::cin >> sz;

            szInt = static_cast<int>(sz);
            it = pcol.pessoaVector.begin();
            std::advance(it, szInt);

            pcol.RemoverPessoa(it);

            std::system("pause");
            break;
        case 6:
            std::system("cls");
            std::cout << "Insira indice da pessoa a apagar (Min): ";
            std::cin >> sz;
            std::cout << "Insira indice da pessoa a apagar (Max): ";
            std::cin >> szM;

            szIntmin = static_cast<int>(sz);
            it = pcol.pessoaVector.begin();
            std::advance(it, szIntmin);

            szIntM = static_cast<int>(szM);
            itM = pcol.pessoaVector.begin();
            std::advance(itM, szIntM);

            pcol.RemoverPessoa(it, itM);

            std::system("pause");
            break;
        case 7:
            std::system("cls");

            std::cout << "Insira novo tamanho para o vector: ";
            std::cin >> sz;
            pcol.AlterarTamanhoVector(sz);

            std::system("pause");
            break;
        case 8:
            std::system("cls");
            if (tema == defcls::Enums::ConsTheme::Escuro)
            {
                scrman::LightMode();
                tema = e.Claro;
                
            }
            else
            {
                scrman::DarkMode();
                tema = e.Escuro;
            }
            std::cout << "Tema alterado." << std::endl;
            std::system("pause");
            break;
        case 9:
            std::exit(0);
        default:
            std::system("cls");
            std::cout << "Opcao errada!" << std::endl;
            std::system("pause");
        }
        
    }
    return 0;
}