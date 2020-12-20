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
