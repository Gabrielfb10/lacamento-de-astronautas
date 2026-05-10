#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP


#include <string>
#include <vector>

class Astronauta {
public:
    std::string cpf, nome;
    int idade;
    std::vector<int> voosFeitos;
    bool vivo = true;
    bool disponivel = true;

    Astronauta(std::string c, int i, std::string n);
    std::string imprimirCpf();
};

#endif
