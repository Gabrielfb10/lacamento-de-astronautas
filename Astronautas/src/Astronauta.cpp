#include "Astronauta.hpp"

Astronauta::Astronauta(std::string c, int i, std::string n) {
    cpf = c;
    idade = i;
    nome = n;
}

std::string Astronauta::imprimirCpf() {
    std::string cpfFormatado;
    for (int i = 0; i < cpf.size(); i++) {
        cpfFormatado.push_back(cpf[i]);
        if (i == 2 || i == 5) {
            cpfFormatado.push_back('.');
        } else if (i == 8) {
            cpfFormatado.push_back('-');
        }
    }
    return cpfFormatado;
}