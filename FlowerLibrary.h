#ifndef FLOWERLIBRARY_H
#define FLOWERLIBRARY_H
#include "FlowerList.h"
#include <iostream>
using namespace std;


/**
*   Yusuf Dogan
*/


class FlowerLibrary{
    public:
        FlowerLibrary();
        ~FlowerLibrary();
        void addFlower(string name);
        void removeFlower(string name);
        void listFlowers() const;
        void listFeatures(string name) const;
        void addFeature(string name,string feature);
        void removeFeature(string name, string feature);
        void findFlowers(string feature) const;
        void toLower( string& in );
    private:
        FlowerList flowers;

};

#endif // FLOWERLIBRARY_H
