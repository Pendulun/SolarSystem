#include "SistemaSolar.hpp"

void SistemaSolar::addPlaneta(Planeta novoPlaneta){
    this->planetas.push_back(novoPlaneta);
}

void SistemaSolar::addEstrela(Astro novaEstrela){
    this->estrelas.push_back(novaEstrela);
}

std::string SistemaSolar::maiorEstrela(){
    std::string maiorEstrela="";
    int maiorRaio=0;
    std::list<Astro>::iterator it;
    for(it=this->estrelas.begin();it!=estrelas.end();it++){
        if(it->getRaio()>maiorRaio){
            maiorRaio=it->getRaio();
            maiorEstrela=it->getNome();
        }
    }
    return maiorEstrela;
}

int SistemaSolar::tempMaiorEstrela(){
    std::string maiorEstrela = this->maiorEstrela();
    std::list<Astro>::iterator it;
    for(it=this->estrelas.begin();it!=estrelas.end();it++){
        if(it->getNome()==maiorEstrela){
            return it->getTempMedia();
        }
    }
    return 0;
}

std::string SistemaSolar::planetaMaisQuente(){
    std::string planetaMaisQuente="";
    int maiorTemp=0;
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(it->getTempMedia()>maiorTemp){
            maiorTemp=it->getTempMedia();
            planetaMaisQuente=it->getNome();
        }
    }
    return planetaMaisQuente;
}

std::string SistemaSolar::planetaMaisFrio(){
    std::string planetaMaisFrio="";
    int menorTemp=0;
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(it==this->planetas.begin()){
            menorTemp=it->getTempMedia();
            planetaMaisFrio=it->getNome();
        }else{
            if(it->getTempMedia()<menorTemp){
                menorTemp=it->getTempMedia();
                planetaMaisFrio=it->getNome();
            }
        }
    }
    return planetaMaisFrio;
}

std::string SistemaSolar::maiorPlaneta(){
    std::string maiorPlaneta="";
    int maiorRaio=0;
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(it->getRaio()>maiorRaio){
            maiorRaio=it->getRaio();
            maiorPlaneta=it->getNome();
        }
    }
    return maiorPlaneta;
}

std::string SistemaSolar::menorPlaneta(){
    std::string menorPlaneta="";
    int menorRaio=0;
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(it==this->planetas.begin()){
            menorRaio=it->getRaio();
            menorPlaneta=it->getNome();
        }else{
            if(it->getRaio()<menorRaio){
                menorRaio=it->getRaio();
                menorPlaneta=it->getNome();
            }
        }
    }
    return menorPlaneta;
}
std::string SistemaSolar::planetaMaisLuas(){
    std::string maiorPlaneta="";
    int maiorLuas=0;
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(it->getNumLuas()>maiorLuas){
            maiorLuas=it->getNumLuas();
            maiorPlaneta=it->getNome();
        }
    }
    return maiorPlaneta;
}

double SistemaSolar::mediaLuas(){
    int numLuas=0;
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        numLuas+=it->getNumLuas();
    }
    double numMedio= (double)(((int)(((numLuas*1.0)/this->planetas.size())*(100)))/(100*1.0));
    return numMedio;
}

int SistemaSolar::numPlanetas(){
    return this->planetas.size();
}

int SistemaSolar::numAstros(){
    std::list<Planeta>::iterator it;
    int numLuas=0;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        numLuas+=it->getNumLuas();
    }
    return numLuas+this->planetas.size()+this->estrelas.size();
}

int SistemaSolar::numPlanetasSolidos(){
    std::list<Planeta>::iterator it;
    int numPlanetasSolidos=0;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(!it->isGasoso()){
         numPlanetasSolidos++;   
        }
    }
    return numPlanetasSolidos;
}

void SistemaSolar::addLuaNoPlaneta(Astro lua, std::string planeta){
    std::list<Planeta>::iterator it;
    for(it=this->planetas.begin();it!=planetas.end();it++){
        if(it->getNome()==planeta){
         it->addLua(lua);
         return;
        }
    }
}

void SistemaSolar::auxCriaAstro(Astro* novoAstro,std::ifstream& leitor){
    std::string tipoComando;
    for(int i=0;i<4;i++){
        leitor>>tipoComando;
        if(tipoComando.compare("Raio")==0){
            std::string raio;
            leitor>>raio;
            novoAstro->setRaio(std::stoi(raio));
        }else if(tipoComando.compare("Temperatura")==0){
            std::string temperatura;
            leitor>>temperatura;
            novoAstro->setTempMedia(std::stoi(temperatura));
        }else if(tipoComando.compare("Gravidade")==0){
            std::string gravidade;
            leitor>>gravidade;
            novoAstro->setGravidade(std::stof(gravidade));
        }else if(tipoComando.compare("Gasoso")==0){
            std::string gasoso;
            leitor>>gasoso;
            if(gasoso.compare("False")==0){
                novoAstro->setGasoso(false);
            }else if(gasoso.compare("True")==0){
                novoAstro->setGasoso(true);
            }
        }
    }
}

void SistemaSolar::criaAstro(SistemaSolar* sistema,std::ifstream& leitor){
    std::string tipo="";
    std::string nome="";
    leitor>>tipo;
    if(tipo.compare("Planeta")==0){
        Planeta novoPlaneta;
        std::string nome;
        leitor>>nome;
        novoPlaneta.setNome(nome);
        auxCriaAstro(&novoPlaneta,leitor);
        sistema->addPlaneta(novoPlaneta);
    }else if(tipo.compare("Lua")==0){
        std::string comando,orbita;
        Astro novaLua;
        std::string nome;
        leitor>>nome;
        novaLua.setNome(nome);
        leitor>>comando>>orbita;
        auxCriaAstro(&novaLua,leitor);
        sistema->addLuaNoPlaneta(novaLua,orbita);
    }else if(tipo.compare("Estrela")==0){
        Astro novaEstrela;
        std::string nome;
        leitor>>nome;
        novaEstrela.setNome(nome);
        auxCriaAstro(&novaEstrela,leitor);
        sistema->addEstrela(novaEstrela);
    }
}








