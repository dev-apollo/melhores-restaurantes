#ifndef MELHORES_RESTAURANTES_HPP
#define MELHORES_RESTAURES_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Restaurante {
    int ano;
    int rank;
    string nome;
    string cidade;
    string pais;
};

struct Usuario {
    string nome;
    string cidade;
    string pais;
};

struct RestaurantesNosAnos{
    string nome;
    int qnt;
};

vector<Restaurante> recuperarRestaurantesPorAno(string endereco, int ano);
void escreverHistorico(string endereco, string titulo, vector<string> restaurantes);
void atualizarUsuario(string endereco, Usuario usuario);
void atualizarLocalizaçãoUsuario(string endereco);
Usuario receberInformacoes();
vector<Restaurante> melhoresRestaurantesProximos(string enderecoRestaurantes, string enderecoUsuario);
void rankingRestaurantesProximos(string enderecoRestaurantes, string enderecoUsuario);
void paisesComMaisRestaurantesEmAno(string endereco, int ano);
vector<string> rankingPaises(vector<string> paises, vector<int> qtdPais);
bool paisNoVetor(string pais, vector<string> paises);
void limparLatitudeLongitude(string enderecoOriginal);
void restaurantesQueMaisAparecemTodosOsAnos(string endereco);
bool restauranteNoVetor(string restaurante, vector<RestaurantesNosAnos> restaurantes);
void aumentarQntRestaurante(vector<RestaurantesNosAnos> &restaurantes, string restaurante);
vector<string> rankingRestaurantes(vector<RestaurantesNosAnos> restaurantes);

#endif