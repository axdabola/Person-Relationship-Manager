#pragma once

namespace defcls
{
    class Enums
    {
    public:
        enum TipoIdade
        {
            Menor,
            Maior,
        };

        enum TipoRelacaoF
        {
            Namorada,
            Amiga,
            Desconhecida,
        };

        enum ConsTheme
        {
            Escuro,
            Claro,
        };
    };

    class Funcs
    {
    public:
        int ConvertAgetoEnum(int age)
        {
            Enums e;
            if (age >= 18)
                return e.Maior;
            else
                return e.Menor;
        }
    };
}

/* Cenas random lol
A ca; //class A

std::string nome;
char cba;
register auto a = 0, b = 0, idd=0;
//cin >> a >> b;
std::cout << ca.Soma(a, b) << std::endl << "Que idade tem?: ";

std::cin >> idd;

std::cout << "Qual seu nome?: ";
std::cin >> cba;
std::getline(std::cin, nome);
std::cout << nome << ", ";
MaiorP(idd);

register int* c = new int(1337);
std::cout << *c;
delete c;

srand(time(NULL));
int r = rand() % 100 + 1;
std::cout << std::endl << r;

template <typename T>
const inline T& MaiorP(const T& a)
{
    if (a >= 18)
    {
        std::cout << "Bora beber uma jola\n";
        return 0;
    }
    else
    {
        std::cout << "Vai beber água\n";
        return 0;
    }
}*/
