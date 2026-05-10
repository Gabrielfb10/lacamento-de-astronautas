#include <iostream>
#include <string>
#include <vector>
#include "Astronauta.hpp"
#include "Voo.hpp"
#include "Sistema.hpp"

using namespace std;

int main() {
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    string comando;

    while (cin >> comando) {
        string mensagemStatus;

        if (comando == "FIM") {
            break;
        }

        if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;

            cin >> cpf >> idade;
            getline(cin>> ws, nome);// O getline serve para pegar todos os dados restantes na linha e o ws garante
                                          // que o cin também considere os espaços.

            mensagemStatus = cadastrarAstronauta(astronautas, cpf, nome, idade);
            cout << mensagemStatus << "\n";
        }

        if (comando == "CADASTRAR_VOO") {
            int codigo;

            cin >> codigo;

            mensagemStatus = cadastrarVoo(voos, codigo);
            cout << mensagemStatus << "\n";

        }

        if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;
            mensagemStatus = adicionarAstronauta(astronautas, voos, cpf, codigo);
            cout << mensagemStatus << "\n";

        }

        if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;

            cin >> cpf >> codigo;
            mensagemStatus = removerAstronauta(astronautas, voos, cpf, codigo);
            cout << mensagemStatus << "\n";
        }

        if (comando == "LANCAR_VOO") {
            int codigo;

            cin >> codigo;
            mensagemStatus = lancarVoo(voos, astronautas, codigo);
            cout << mensagemStatus << "\n";
        }

        if (comando == "EXPLODIR_VOO") {
            int codigo;

            cin >> codigo;
            mensagemStatus = explodirVoo(voos, astronautas, codigo);
            cout << mensagemStatus << "\n";
        }

        if (comando == "FINALIZAR_VOO") {
            int codigo;

            cin >> codigo;
            mensagemStatus = finalizarVoo(voos, astronautas, codigo);
            cout << mensagemStatus << "\n";
        }
        if (comando == "LISTAR_VOOS") {
            if (voos.empty()) {
                cout << "Nao existe nenhum Voo cadastrado.";
            } else {
                listarVoos(voos, astronautas);
            }
        }

        if (comando == "LISTAR_MORTOS") {
            if (astronautas.empty()) {
                cout << "Nao existe nenhum Astronauta cadastrado.";
            } else {
                listarMortos( astronautas);
            }
        }


    }
    return 0;
}