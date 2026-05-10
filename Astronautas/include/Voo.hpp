//
// Created by gabig on 06/05/2026.
//

#ifndef VOO_HPP
#define VOO_HPP

#include <string>
#include <vector>

class Voo {
public:
    int codigo;
    std::vector<std::string> cpfPassageiros;
    std::string estado = "planejado";

    Voo(int c);
    std::string imprimirCpf(int indice);
};

#endif
