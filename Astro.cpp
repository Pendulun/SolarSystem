#include "Astro.hpp"


void Astro::setRaio(int novoRaio){
    this->raio=novoRaio;
}

void Astro::setTempMedia(int novaTemperatura){
    this->tempMedia=novaTemperatura;
}

void Astro::setGravidade(float novaGravidade){
    this->gravidade=novaGravidade;
}

void Astro::setNome(std::string novoNome){
    this->nome=novoNome;
}

void Astro::setGasoso(bool ehGasoso){
    this->gasoso=ehGasoso;
}

void Astro::setOrbita(std::string orbitando){
    this->orbita = orbitando;
}

int Astro::getRaio(){
    return this->raio;
}

int Astro::getTempMedia(){
    return this->tempMedia;
}

float Astro::getGravidade(){
    return this->gravidade;
}

std::string Astro::getNome(){
    return this->nome;
}

bool Astro::isGasoso(){
    return this->gasoso;
}

std::string Astro::getOrbitando(){
    return orbita;
}