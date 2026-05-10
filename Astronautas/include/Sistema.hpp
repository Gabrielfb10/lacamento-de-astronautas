#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <string>
#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"

std::string imprimirCpfGlobal(std::string cpf); // Renomeado para não conflitar mentalmente, opcional.

std::string cadastrarAstronauta(std::vector<Astronauta>& listaAstronautas, std::string cpf, std::string nome, int idade);
std::string cadastrarVoo(std::vector<Voo>& listaVoos, int codigo);
std::string adicionarAstronauta(std::vector<Astronauta>& listaAstronautas, std::vector<Voo>& listaVoos, std::string cpf, int codigo);
std::string removerAstronauta(std::vector<Astronauta>& listaAstronautas, std::vector<Voo>& listaVoos, std::string cpf, int codigo);
std::string lancarVoo(std::vector<Voo>& listaVoos, std::vector<Astronauta>& listaAstronautas, int codigo);
std::string explodirVoo(std::vector<Voo>& listaVoos, std::vector<Astronauta>& listaAstronautas, int codigo);
std::string finalizarVoo(std::vector<Voo>& listaVoos, std::vector<Astronauta>& listaAstronautas, int codigo);

void listarVoos(std::vector<Voo>& listaVoos, std::vector<Astronauta>& listaAstronautas);
void listarMortos(std::vector<Astronauta>& listaAstronautas);

#endif