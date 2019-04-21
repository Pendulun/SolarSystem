#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include "Astro.hpp"
#include "Planeta.hpp"
#include "SistemaSolar.hpp"

using namespace std;

int main() {
    SistemaSolar novoSistema;
    string file,comando;
        cout<<"File to be read:"<<endl;
        cin>>file;
        ifstream leitor;
        leitor.open(file);
        if(leitor.is_open()){
            while(leitor>>comando){
                if(comando.compare("defastro")==0){
                    novoSistema.criaAstro(&novoSistema,leitor);
                }
            }
            leitor.close();
            cout<<"Biggest star: "<<novoSistema.maiorEstrela()<<endl;
            cout<<"Temperature of biggest star: "<<novoSistema.tempMaiorEstrela()<<endl;
            cout<<"Number of astros: "<<novoSistema.numAstros()<<endl;
            cout<<"Number of planets: "<<novoSistema.numPlanetas()<<endl;
            cout<<"Number of solid planets:"<<novoSistema.numPlanetasSolidos()<<endl;
            cout.precision(2);
            cout<<fixed;
            cout<<"Average of moons: "<<novoSistema.mediaLuas()<<endl;
            cout<<"Planet with biggest number of moons: "<<novoSistema.planetaMaisLuas()<<endl;
            cout<<"Hottest planet: "<<novoSistema.planetaMaisQuente()<<endl;
            cout<<"Coldest planet: "<<novoSistema.planetaMaisFrio()<<endl;
            cout<<"Biggest planet: "<<novoSistema.maiorPlaneta()<<endl;
            cout<<"Smallest planet: "<<novoSistema.menorPlaneta()<<endl;
            system("PAUSE");
        }else{
            cout<<"file could not be open"<<endl;
        }
}