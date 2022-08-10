#ifndef FLOWERLIST_H
#define FLOWERLIST_H
#include "Flower.h"
#include <iostream>
#include <string>
using namespace std;


/**
*   Yusuf Dogan
*/
class FlowerList{
    public:
        FlowerList();
        FlowerList(const FlowerList& aList);
        ~FlowerList();
        bool isEmpty() const;
        int getLength() const;
        bool retrieve(string flowerName, Flower& flower) const;
        bool add(string flowerName);
        bool remove(string flowerName);
        void listFlowers() const;
        void addFeatureToFlower(string name,string feature);
        void removeFeatureFromFlower(string name, string feature);
        void listFeatures(string name) const;
        void findFlowers(string feature) const;
        void  toLower( string& in);


    private:
        struct FlowerNode{
        Flower f;
        FlowerNode* next;
        };
        int size;
        FlowerNode* head; //the flowers are stored in a sorted singly linear linked list

};


#endif // FLOWERLIST_H
