#include "melhores_restaurante.hpp"

vector<Restaurante> recuperarRestaurantesPorAno(string endereco, int ano)
{
    vector<Restaurante> restaurantes;
    ifstream arquivo(endereco);
    if(!arquivo.is_open()){
        cout<<"Erro."<<endl;
    }
    string linha;
    while(getline(arquivo, linha)){
        istringstream iss(linha);
        string token;
        vector<string> dadosRestaurante;
        while(getline(iss, token, ',')){
            dadosRestaurante.push_back(token);
        }
        if(stoi(dadosRestaurante[0]) == ano){
            Restaurante restaurante = {stoi(dadosRestaurante[0]), stoi(dadosRestaurante[1]), dadosRestaurante[2], dadosRestaurante[3], dadosRestaurante[4]};
            restaurantes.push_back(restaurante);
        }
    }
    arquivo.close();
    return restaurantes;
}

void escreverHistorico(string endereco, string titulo, vector<Restaurante> restaurantes)
{
    ofstream arquivo(endereco, ios::app);
    if(!arquivo.is_open()){
        cout<<"Erro"<<endl;
    }
    arquivo<<titulo<<endl;
    for(Restaurante r: restaurantes){
        arquivo<<r.ano<<","<<r.rank<<","<<r.nome<<","<<r.cidade<<","<<r.pais<<endl;
    }
    arquivo.close();
}

void atualizarUsuario(string endereco, Usuario usuario)
{
    ofstream arquivo(endereco);
    if(!arquivo.is_open()){
        cout<<"Erro"<<endl;
    }
    arquivo<<usuario.nome<<","<<usuario.cidade<<","<<usuario.pais<<""<<endl;
    arquivo.close();
}
;
Usuario receberInformacoes()
{
    Usuario usuario;
    cout<<"Insira seu nome: ";
    getline(cin, usuario.nome);
    cout<<"Insira sua cidade atual: ";
    getline(cin, usuario.cidade);
    cout<<"Insira seu pais atual: ";
    getline(cin, usuario.pais);
    return usuario;
}

vector<Restaurante> melhoresRestaurantesProximos(string enderecoRestaurantes, string enderecoUsuario)
{
    int cont = 0;
    string linha, cidade, token;
    vector<Restaurante> restaurantesProximos;
    ifstream arquivoUsuario(enderecoUsuario);
    if(!arquivoUsuario.is_open()){
        cout<<"Erro"<<endl;
    }
    getline(arquivoUsuario, linha);
    istringstream iss(linha);
    while(getline(iss, token, ',')){
        if(cont == 1){
            cidade = token;
            break;
        }
        cont++;
    }
    arquivoUsuario.close();
    vector<Restaurante> restaurantes = recuperarRestaurantesPorAno(enderecoRestaurantes, 2023);
    for(Restaurante r: restaurantes){
        if(r.cidade == cidade){
            restaurantesProximos.push_back(r);
        }
    }
    return restaurantesProximos;
}

void rankingRestaurantesProximos(string enderecoRestaurantes, string enderecoUsuario)
{
    vector<Restaurante> restaurantes = melhoresRestaurantesProximos(enderecoRestaurantes, enderecoUsuario);
    cout << "Ranking restaurantes proximos" << endl;
    for(int i = 0; i < restaurantes.size(); i++){
        cout<<i+1<<"° - "<<restaurantes[i].nome<<endl;
    }
}

void paisesComMaisRestaurantesEmAno(string endereco, int ano)
{
    vector<string> paises;
    vector<int> qtdPais;
    vector<Restaurante> restaurantes = recuperarRestaurantesPorAno(endereco, ano);
    for(Restaurante r: restaurantes){
        if(!paisNoVetor(r.pais, paises)){
            paises.push_back(r.pais);
        }
    }
    for(string p: paises){
        int cont = 0;
        for(Restaurante r: restaurantes){
            if(p == r.pais){
                cont++;
            }
        }
        qtdPais.push_back(cont);   
    }
    vector<string> top3Paises = rankingPaises(paises, qtdPais);
    int cont = 1;
    for(string p: top3Paises){
        cout<<cont<<" - "<<p<<endl;
        cont++;
    }
}

vector<string> rankingPaises(vector<string> paises, vector<int> qtdPais){
    string top1, top2, top3;
    int top1Valor = 0, top2Valor = 0, top3Valor = 0;
    for(int i = 0; i < paises.size(); i++){
        if(qtdPais[i] > top1Valor){
            top1Valor = qtdPais[i];
            top1 = paises[i];
        }else if(qtdPais[i] < top1Valor && qtdPais[i] > top2Valor){
            top2Valor = qtdPais[i];
            top2 = paises[i];
        }else if(qtdPais[i] < top1Valor && qtdPais[i] < top2Valor && qtdPais[i] > top3Valor){
            top3Valor = qtdPais[i];
            top3 = paises[i];
        }
    }
    vector<string> top3Paises = {top1, top2, top3};
    return top3Paises;
}

bool paisNoVetor(string pais, vector<string> paises){
    for(string p: paises){
        if(p == pais){
            return true;
        }
    }
    return false;
}

void limparLatitudeLongitude(string enderecoOriginal)
{
    ifstream arquivoOriginal(enderecoOriginal); 
    ofstream arquivoCopia("copia.csv");
    if(!arquivoOriginal.is_open() || !arquivoCopia.is_open()){
        cout<<"Erro."<<endl;
    }
    string linha;
    while(getline(arquivoOriginal, linha)){
        istringstream iss(linha);
        string token;
        int cont = 0;
        while(getline(iss, token, ',')){
            if(cont < 4){
                arquivoCopia<<token<<",";
            }else if(cont == 4){
                arquivoCopia<<token<<endl;
            }
            cont++;            
        }
    }
    arquivoOriginal.close();
    arquivoCopia.close();
}
