#ifndef PLANETA_H
#define PLANETA_H
#include "Astro.hpp"
#include <list>
class Planeta : public Astro{
    public:
        void addLua(Astro);
        int getNumLuas();
    private:
        std::list<Astro> luas;
};
#endif