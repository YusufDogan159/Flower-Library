#ifndef FLOWER_H
#define FLOWER_H
#include <iostream>
using namespace std;

/**
*   Yusuf Dogan
*/

class Flower{

    public:
        Flower();
        Flower(string flowerName);
        Flower(const Flower& aFlower);
        ~Flower();
        bool isEmpty() const;
        int getLength() const ;
        bool add(string feature);
        bool remove(string feature);
        bool isFeatureExist( string feature );
        string printFlower() const;
        string getName();
        void toLower( string& in);

    private:
        struct FeatureNode{
        string feature;
        FeatureNode* next;
        };
        int size;
        string flowerName;
        FeatureNode *head; //the features are stored in a sorted singly linear linked list

};

#endif // FLOWER_H
