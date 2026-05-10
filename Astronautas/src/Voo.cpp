#include "Voo.hpp"

Voo::Voo(int c) {
    codigo = c;
}

std::string Voo::imprimirCpf(int indice) {
    std::string cpfFormatado;
    for (int i = 0; i < cpfPassageiros[indice].size(); i++) {
        cpfFormatado.push_back(cpfPassageiros[indice][i]);
        if (i == 2 || i == 5) {
            cpfFormatado.push_back('.');
        } else if (i == 8) {
            cpfFormatado.push_back('-');
        }
    }
    return cpfFormatado;
}