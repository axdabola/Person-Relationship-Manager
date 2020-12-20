#pragma once

#include <iostream>
#include <vector>
#include <iterator>

#include "defdata.hpp"
#include "defcls.hpp"

#define VECTOR_SIZE 50

namespace datavector
{
    typedef class PessoaCol 
    {
    public:
        const size_t v_sz = VECTOR_SIZE;

        std::vector<defdata::Pessoa> pessoaVector;
        std::vector<defdata::Pessoa>::iterator i;

        /// <summary>
        /// Def. ctor, vector size: VECTOR_SIZE (define)
        /// </summary>
        PessoaCol()
        {
            pessoaVector.reserve(v_sz);
        }

        /// <summary>
        /// Non-def ctor, vector size definido pelo user.
        /// </summary>
        /// <param name="vector_sz"></param>
        PessoaCol(size_t vector_sz)
        {
            pessoaVector.reserve(vector_sz);
        }

        /// <summary>
        /// Adiciona uma Pessoa ao Vector
        /// </summary>
        /// <param name="p">Obj. tipo pessoa_t (class defdata::Pessoa)</param>
        /// <returns></returns>
        bool AdicionarPessoa(defdata::pessoa_t p)
        {
            try
            {
                for (size_t sz = 0; sz < pessoaVector.size(); sz++)
                {
                    if (VerificarRep(pessoaVector.at(sz), p))
                        return false;
                }
                pessoaVector.push_back(p);
                return true;
            }
            catch (const std::exception& ex)
            {
                std::cout << ex.what();
                return false;
            }
        }
        /// <summary>
        /// Remover Pessoa
        /// </summary>
        /// <param name="i">Obj. Iterator (Loc. do Obj. Pessoa no Vector)</param>
        void RemoverPessoa(std::vector<defdata::pessoa_t>::iterator i)
        {
            try
            {
                if (i >= pessoaVector.begin() && i <= pessoaVector.end())
                    pessoaVector.erase(i);
                else
                    throw std::out_of_range("Iterador out of vector range");
            }
            catch (const std::out_of_range& ex)
            {
                std::cout << ex.what();
            }
        }

        /// <summary>
        /// Remover Pessoa dentro de intervalo
        /// </summary>
        /// <param name="min">Intervalo minimo: Obj. Iterator (Loc. do Obj. Pessoa no Vector)</param>
        /// <param name="max">Intervalor maximo: Obj. Iterator (Loc. do Obj. Pessoa no Vector)</param>
        void RemoverPessoa(std::vector<defdata::pessoa_t>::iterator min, std::vector<defdata::pessoa_t>::iterator max)
        {
            try
            {
                if (min >= max)
                    throw std::out_of_range("Min. iterator value higher than Max. iterator value");
                if (min < pessoaVector.begin() || min > pessoaVector.end())
                    throw std::out_of_range("Min. iterador out of vector range");
                if (max < pessoaVector.begin() || max > pessoaVector.end())
                    throw std::out_of_range("Max. iterador out of vector range");

                pessoaVector.erase(min, max);
            }
            catch (const std::out_of_range& ex)
            {
                std::cout << ex.what();
            }
        }

        /// <summary>
        /// Informação do vector
        /// </summary>
        /// <returns>Obj. tipo vcdata_t (class defdata::VectorData)</returns>
        defdata::vcdata_t VectorInfo()
        {
            return defdata::vcdata_t(pessoaVector.size(), pessoaVector.max_size());
        }

        /// <summary>
        /// Alterar max_size() do vector
        /// </summary>
        /// <param name="sz">Var. tipo size_t</param>
        void AlterarTamanhoVector(size_t sz)
        {
            pessoaVector.resize(sz);
        }

    private:
        bool VerificarRep(defdata::pessoa_t p, defdata::pessoa_t cmp)
        {
            if (p.nome == cmp.nome && p.idade == cmp.idade && p.tpRF == cmp.tpRF)
                return true;
            return false;
        }
    }pessoa_col;
}