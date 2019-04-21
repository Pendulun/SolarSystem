#ifndef SISTEMASOLAR_H
#define SISTEMASOLAR_H
#include "Planeta.hpp"
#include "Astro.hpp"
#include <string>
#include <list>
#include <iostream>
#include <fstream>
class SistemaSolar{
    public:
        std::string maiorEstrela();
        int tempMaiorEstrela();
        std::string planetaMaisQuente();
        std::string planetaMaisFrio();
        std::string maiorPlaneta();
        std::string menorPlaneta();
        std::string planetaMaisLuas();
        double mediaLuas();
        int numPlanetas();
        int numAstros();
        int numPlanetasSolidos();
        void addPlaneta(Planeta);
        void addEstrela(Astro);
        void addLuaNoPlaneta(Astro,std::string);
        void criaAstro(SistemaSolar*,std::ifstream&);
        void auxCriaAstro(Astro*,std::ifstream&);
    private:
        std::list<Planeta> planetas;
        std::list<Astro> estrelas;
};
#endif