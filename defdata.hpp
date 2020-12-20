#pragma once

namespace defdata
{
    typedef class Pessoa
    {
    public:
        char nome[100];
        int tpRF;
        int idade;
        int idadeT;
    }pessoa_t;

    typedef class VectorData
    {
    public:
        size_t size;
        size_t maxSize;
        
        VectorData() 
        {
            size = 0;
            maxSize = 0;
        }
        VectorData(size_t sz, size_t msz)
        {
            size = sz;
            maxSize = msz;
        }
    }vcdata_t;
}