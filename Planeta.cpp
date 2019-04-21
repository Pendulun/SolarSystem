#include "Planeta.hpp"

void Planeta::addLua(Astro novaLua){
    this->luas.push_back(novaLua);
}

int Planeta::getNumLuas(){
    return this->luas.size();
}