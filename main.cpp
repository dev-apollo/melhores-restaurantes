#include "melhores_restaurante.hpp"

int main(){
    int option = 1;
    atualizarUsuario("usuario.txt", receberInformacoes());
    do{
        cout<<"[1] - Atualizar localizacao"<<endl<<"[2] - Rankear restaurantes proximos"<<endl<<"[3] - Verificar paises com mais restaurantes em X ano"<<endl<<"[4] - Limpar latitude e longitude do arquivo"<<endl<<"[5] - Verificar restaurantes que aparecem mais vezes ao longo dos anos"<<endl<<"[0] - Sair"<<endl<<"Selecione uma das opcoes acima: ";
        cin>>option;
        switch(option){
            case 1: {
                atualizarLocalizacaoUsuario("usuario.txt");
                break;
            }
            case 2: {
                rankingRestaurantesProximos("WorldsBestRestaurants.csv", "usuario.txt");
                break;
            }
            case 3: {
                int ano = 0;
                do{
                    cout<<"Insira o ano entre 2002 e 2023: ";
                    cin>>ano;
                }while(ano > 2023 || ano < 2002);
                paisesComMaisRestaurantesEmAno("WorldsBestRestaurants.csv", ano);
                break;
            }
            case 4: {
                limparLatitudeLongitude("WorldsBestRestaurants.csv");
                break;
            }
            case 5: {
                restaurantesQueMaisAparecemTodosOsAnos("WorldsBestRestaurants.csv");
                break;
            }
            case 0: {
                cout<<"Saindo...";
                break;
            }
            default: {
                cout<<"Opcao invalida."<<endl;
                break;
            }
        }
    }while(option != 0);
}