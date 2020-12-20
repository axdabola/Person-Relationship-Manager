#pragma once

#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

#include "defcls.hpp"
#include "defdata.hpp"
#include "datavector.hpp"

namespace scrman
{
	void ImprimirInfoClassePessoa()
	{
		std::cout << "| Nome | tpRF | Idade | IdadeT |\n";
	}

	void ImprimirVector(std::vector<defdata::pessoa_t> vec, size_t sz)
	{
		std::vector<defdata::pessoa_t>::iterator i;
		int szInt = static_cast<int>(sz);
		i = vec.begin();
		std::advance(i, szInt);

		if (i > vec.end() || i < vec.begin())
		{
			std::cout << "Erro a imprimir vector na posicao: " << szInt;
			return;
		}

		defdata::pessoa_t p = vec.at(sz);

		std::string tpRF;
		std::string idadeT = p.idadeT == defcls::Enums::TipoIdade::Maior ? "Maior" : "Menor";

		switch (p.tpRF)
		{
		case defcls::Enums::TipoRelacaoF::Namorada:
			tpRF = "Namorada";
			break;
		case defcls::Enums::TipoRelacaoF::Amiga:
			tpRF = "Amiga";
			break;
		case defcls::Enums::TipoRelacaoF::Desconhecida:
			tpRF = "Desconhecida";
			break;
		}

		std::cout << p.nome << " | " << tpRF << " | " << p.idade << " | " << idadeT << std::endl;
	}

	// Templates for copy/paste
	// std::cout << "" << std::endl;
	// std::cout << "";

	void Menu()
	{
		std::system("cls");

		//╔═╗║╚╝
		std::cout << "╔══════════════════════════╗" << std::endl;
		std::cout << "║  Gerenciador de Pessoas  ║" << std::endl;
		std::cout << "╚══════════════════════════╝" << std::endl << std::endl;

		std::cout << "1. Adicionar Pessoa (Fem.)" << std::endl;
		std::cout << "2. Ver Pessoa" << std::endl;
		std::cout << "3. Lista Completa de Pessoas" << std::endl;
		std::cout << "4. Informacao do Vector" << std::endl;
		std::cout << "5. Apagar Pessoa" << std::endl;
		std::cout << "6. Apagar Intervalo de Pessoas" << std::endl;
		std::cout << "7. Redimencionar tamanho do Vector" << std::endl;
		std::cout << "8. Alterar tema (Escuro/Claro)" << std::endl;
		std::cout << "9. Sair" << std::endl;
		std::cout << "Escolha uma opcao: ";
	}

	defdata::pessoa_t Opc1()
	{
		defcls::Funcs f;
		defdata::pessoa_t p;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Insira Nome: ";
		std::cin.getline(p.nome, sizeof(p.nome));

		std::cout << "Insira tipo de relação (0 Namorada, 1 Amiga, 2 Desconhecida): ";
		std::cin >> p.tpRF;

		std::cout << "Insira Idade: ";
		std::cin >> p.idade;

		p.idadeT = f.ConvertAgetoEnum(p.idade);

		return p;
	}

	void LightMode()
	{
		std::system("color f0");
	}

	void DarkMode()
	{
		std::system("color 07");
	}
}
