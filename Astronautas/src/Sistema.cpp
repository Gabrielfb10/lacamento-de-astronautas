#include "Sistema.hpp"
#include <iostream>

using namespace std;

string imprimirCpf(string cpf) {
    string cpfFormatado;
    for (int i = 0; i < cpf.size(); i++) {
        cpfFormatado.push_back(cpf[i]);
        if (i==2 || i==5) {
            cpfFormatado.push_back('.');
        } else if (i==8) {
            cpfFormatado.push_back('-');
        }

    }
    return cpfFormatado;
}

string cadastrarAstronauta(vector<Astronauta>& listaAstronautas, string cpf, string nome, int idade) {
    for (int i = 0; i < listaAstronautas.size(); i++) {
        if (listaAstronautas[i].cpf == cpf) {
            return "Nao foi possivel cadastrar esse astronauta, ja existe um cadastro com esse CPF!";
        }
    }

    for (int i = 0; i < cpf.size(); i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return "O CPF deve conter apenas numeros!";
        }
    }

    if (cpf.size() != 11) {
        return "O CPF deve ter 11 numeros!";
    }


    
    Astronauta novoAstronauta(cpf, idade, nome);
    listaAstronautas.push_back(novoAstronauta);
    return "Astronauta com cpf " + imprimirCpf(cpf )+ " foi cadastrado com sucesso!";
}

string cadastrarVoo(vector<Voo>& listaVoos, int codigo) {
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            return "Nao foi possivel cadastrar esse voo, ja existe um cadastro com esse codigo!";
        }
    }

    Voo novoVoo(codigo);
    listaVoos.push_back(novoVoo);
    return "O Voo com codigo " + to_string(codigo) + " foi cadastrado com sucesso!";
}

string adicionarAstronauta(vector<Astronauta>& listaAstronautas, vector<Voo>& listaVoos, string cpf, int codigo) {
    int indiceVoo = -2;
    int indiceAstronauta = -2;


    //Procurando voo
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            if (listaVoos[i].estado == "planejado") {
                indiceVoo = i;
                break;
            }
            indiceVoo++;
            break;
        }
    }

    //Checando se voo existe e esta em planejamento
    if (indiceVoo == -2) {
        return "O Voo de codigo " + to_string(codigo) + " nao existe.";
    } else if (indiceVoo == -1) {
        return "O Voo de codigo " + to_string(codigo) + " existe, mas nao esta mais na fase de planejamento.";
    }

    //Teste de tipo de cpf
    for (int i = 0; i < cpf.size(); i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return "O CPF deve conter apenas numeros!";
        }
    }

    if (cpf.size() != 11) {
        return "O CPF deve ter 11 numeros!";
    }

    //Procurando astronauta
    for (int i = 0; i < listaAstronautas.size(); i++) {
        if (listaAstronautas[i].cpf == cpf) {
            if (listaAstronautas[i].vivo) {
                indiceAstronauta = i;
                break;
            }
            indiceAstronauta++;
            break;
        }
    }

    //Checando se astronauta existe e esta vivo
    if (indiceAstronauta == -2) {
        return "O astrounauta de cpf " + imprimirCpf(cpf) + " nao existe.";
    } else if (indiceAstronauta == -1) {
        return "O astrounauta de cpf " + imprimirCpf(cpf) + " nao esta vivo.";
    }

    //Checando se astronauta já está cadastrado no voo
    for (int i = 0; i < listaVoos[indiceVoo].cpfPassageiros.size(); i++) {
        if (listaVoos[indiceVoo].cpfPassageiros[i] == cpf) {
            return "O Astronauta ja esta nesse voo.";
        }
    }

    //Cadastrando astronauta no voo
    listaVoos[indiceVoo].cpfPassageiros.push_back(cpf);

    return "Astronauta de cpf " + imprimirCpf(cpf) + " foi cadastrado no Voo " + to_string(codigo) + " com sucesso!";
}

string removerAstronauta (vector<Astronauta>& listaAstronautas, vector<Voo>& listaVoos, string cpf, int codigo)  {
    int indiceVoo = -2;
    int indiceAstronauta = -2;

    //Procurando voo
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            if (listaVoos[i].estado == "planejado") {
                indiceVoo = i;
                break;
            }
            indiceVoo = -1;
            break;
        }
    }

    //Checando se voo existe e esta em planejamento
    if (indiceVoo == -2) {
        return "O Voo de codigo " + to_string(codigo) + " nao existe.";
    } else if (indiceVoo == -1) {
        return "O Voo de codigo " + to_string(codigo) + " existe, mas nao esta mais na fase de planejamento.";
    }

    //Teste de tipo de cpf
    for (int i = 0; i < cpf.size(); i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return "O CPF deve conter apenas numeros!";
        }
    }

    if (cpf.size() != 11) {
        return "O CPF deve ter 11 numeros!";
    }

    //Procurando astronauta
    for (int i = 0; i < listaAstronautas.size(); i++) {
        if (listaAstronautas[i].cpf == cpf) {
            indiceAstronauta = i;
            break;
        }
    }

    //Checando se astronauta existe
    if (indiceAstronauta == -2) {
        return "O astrounauta de cpf " + imprimirCpf(cpf) + " nao existe.";
    }

    //Checando se astronauta já está cadastrado no voo
    for (int i = 0; i < listaVoos[indiceVoo].cpfPassageiros.size(); i++) {
        if (listaVoos[indiceVoo].cpfPassageiros[i] == cpf) {
            listaVoos[indiceVoo].cpfPassageiros.erase(listaVoos[indiceVoo].cpfPassageiros.begin() + i);
            return "Astronauta de cpf " + imprimirCpf(cpf) + " removido do Voo " + to_string(codigo) + " com sucesso!";
        }
    }

    //Caso em que
    return "O Astronauta nao esta nesse voo.";


}

string lancarVoo (vector<Voo>& listaVoos, vector<Astronauta>& listaAstronautas, int codigo) {
    int indiceVoo = -2;
    string cpfAstronautaIndisponivel;

    //Procurando voo
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            if (listaVoos[i].estado == "planejado") {
                indiceVoo = i;
                break;
            }
            indiceVoo = -1;
            break;
        }
    }

    //Checando se voo existe, se esta em planejamento e se tem astronautas cadastrados
    if (indiceVoo == -2) {
        return "O Voo de codigo " + to_string(codigo) + " nao existe.";
    } else if (indiceVoo == -1) {
        return "O Voo de codigo " + to_string(codigo) + " existe, mas nao esta mais na fase de planejamento.";
    } else if (listaVoos[indiceVoo].cpfPassageiros.empty()) {
        return "O Voo de codigo " + to_string(codigo) + " nao possui passageiro cadastrados.";
    }

    for (int i = 0; i < listaVoos[indiceVoo].cpfPassageiros.size(); i++) {
        int contador = 0;
        for (int j = 0; j < listaAstronautas.size(); j++) {
            if (listaAstronautas[j].cpf == listaVoos[indiceVoo].cpfPassageiros[i] && listaAstronautas[j].vivo && listaAstronautas[j].disponivel) {
                break;
            }
            contador++;
        }

        if (contador == listaAstronautas.size()) {
            cpfAstronautaIndisponivel = listaVoos[indiceVoo].imprimirCpf(i);
            return "O Astronautas " + cpfAstronautaIndisponivel + " nao esta apto para o voo.";
        }
    }


    for (int i = 0; i < listaVoos[indiceVoo].cpfPassageiros.size(); i++) {
        for (int j = 0; j < listaAstronautas.size(); j++) {
            if (listaAstronautas[j].cpf == listaVoos[indiceVoo].cpfPassageiros[i]) {
                listaAstronautas[j].disponivel = false;
                listaAstronautas[j].voosFeitos.push_back(codigo);
                break;
            }
        }
    }

    listaVoos[indiceVoo].estado = "em curso";

    return "Voo " + to_string(codigo) + " lanaado com sucesso!";
}

string explodirVoo (vector<Voo>& listaVoos, vector<Astronauta>& listaAstronautas, int codigo) {
    int indiceVoo = -2;

    //Procurando voo
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            if (listaVoos[i].estado == "em curso") {
                indiceVoo = i;
                break;
            }
            indiceVoo = -1;
            break;
        }
    }

    //Checando se voo existe e se esta em curso
    if (indiceVoo == -2) {
        return "O Voo de codigo " + to_string(codigo) + " nao existe.";
    } else if (indiceVoo == -1) {
        return "O Voo de codigo " + to_string(codigo) + " existe, mas nao esta em curso.";
    }

    //Mudando estado do voo
    listaVoos[indiceVoo].estado = "finalizado com explosao";

    //Matando todos tripulantes e os deixando indisponíveis
    for (int i = 0; i < listaVoos[indiceVoo].cpfPassageiros.size(); i++) {
        for (int j = 0; j < listaAstronautas.size(); j++) {
            if (listaAstronautas[j].cpf == listaVoos[indiceVoo].cpfPassageiros[i]) {
                listaAstronautas[j].vivo = false;
                //Já esta disponivel pois o voo esta em curso
                break;
            }
        }
    }

    return "Voo " + to_string(codigo) + " explodido com sucesso!";

}

string finalizarVoo (vector<Voo>& listaVoos, vector<Astronauta>& listaAstronautas, int codigo) {
    int indiceVoo = -2;

    //Procurando voo
    for (int i = 0; i < listaVoos.size(); i++) {
        if (listaVoos[i].codigo == codigo) {
            if (listaVoos[i].estado == "em curso") {
                indiceVoo = i;
                break;
            }
            indiceVoo = -1;
            break;
        }
    }

    //Checando se voo existe e se esta em curso
    if (indiceVoo == -2) {
        return "O Voo de codigo " + to_string(codigo) + " nao existe.";
    } else if (indiceVoo == -1) {
        return "O Voo de codigo " + to_string(codigo) + " existe, mas nao esta em curso.";
    }

    //Mudando estado do voo
    listaVoos[indiceVoo].estado = "finalizado com sucesso";

    //Deixando todos os tripulantes disponíveis
    for (int i = 0; i < listaVoos[indiceVoo].cpfPassageiros.size(); i++) {
        for (int j = 0; j < listaAstronautas.size(); j++) {
            if (listaAstronautas[j].cpf == listaVoos[indiceVoo].cpfPassageiros[i]) {
                listaAstronautas[j].disponivel = true;
                break;
            }
        }
    }

    return "Voo " + to_string(codigo) + " finalizado com sucesso!";

}

void listarVoos(vector<Voo>& listaVoos, vector<Astronauta>& listaAstronautas) {
    vector<string> estados = {"planejado", "em curso", "finalizado com sucesso", "finalizado com explosao"};

    for (int i = 0; i < estados.size(); i++) {
        int contador = 0 ;
        cout << "=====Voos " << estados[i] << "=====" << "\n";
        for (int j = 0; j < listaVoos.size(); j++) {
            if (listaVoos[j].estado == estados[i]) {
                contador++;
                cout << "= Voo  " << listaVoos[j].codigo << "\n";
                cout << "-Estado: " << listaVoos[j].estado << "\n";
                cout << "-Astronautas nesse voo: "  << "\n";
                for (int k = 0; k < listaVoos[j].cpfPassageiros.size(); k++) {
                    for (int l = 0; l < listaAstronautas.size(); l++) {
                        if (listaAstronautas[l].cpf == listaVoos[j].cpfPassageiros[k]) {
                            cout << "--" << listaAstronautas[l].nome << " - " << listaAstronautas[l].imprimirCpf() << "\n";
                            break;
                        }
                    }
                }

            }
        }
        if (contador==0) {
            cout << "Nenhum voo registrado." << "\n";
        }
    }
}

void listarMortos (vector<Astronauta>& listaAstronautas) {

    cout << "=====Astronautas Mortos=====" << "\n";
    int contador = 0;
    for (int i = 0; i < listaAstronautas.size(); i++) {

        if (!listaAstronautas[i].vivo) {
            contador++;
            cout << listaAstronautas[i].nome << " - " << listaAstronautas[i].imprimirCpf() << "\n";
            cout << "+Codigos dos Voos que fez parte: ";
            for (int j = 0; j < listaAstronautas[i].voosFeitos.size(); j++) {
                cout << listaAstronautas[i].voosFeitos[j];
                if (j +1 == listaAstronautas[i].voosFeitos.size()) {
                    cout << ".\n";
                } else {
                    cout << ", ";
                }
            }
        }
    }

    if (contador==0) {
        cout << "Nenhum Astronauta registrado esta morto ." << "\n";
    }
}