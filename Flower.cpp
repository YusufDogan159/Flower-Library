#include "Flower.h"
#include <iostream>
using namespace std;


/**
*   Yusuf Dogan
*/


Flower::Flower()
{

}
Flower::Flower(string flowerName)
{
    this->flowerName = flowerName;
    size = 0;
    head =  NULL;
}

Flower::Flower(const Flower& aFlower)
{

}
Flower::~Flower()
{

}
string Flower::getName()
{
    return flowerName;
}

bool Flower::isEmpty() const
{
    if( size == 0 )
        return true;
    else
        return false;
}
int Flower::getLength() const
{
    return size;
}

/**
*
*
*/
bool Flower::add(string feature)
{
    toLower( feature);
    bool isExist = false;
    if( size == 0)
    {
        head = new FeatureNode();
        head->feature = feature;
        head->next = NULL;
        size++;
        return true;
    }
    else
    {
        for(  FeatureNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            if( tempNode->feature == feature)
                isExist = true;
        }

        if( !isExist )
        {
            for(  FeatureNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
            {
                if( tempNode->next == NULL)
                {
                    tempNode->next = new FeatureNode();
                    (tempNode->next)->feature = feature;
                    (tempNode->next)->next = NULL;
                    size++;
                    return true;
                }
            }

        }
        else
            return false;
    }
    return false;
}

/**
*
*
*
*/
bool Flower::remove(string feature)
{
    toLower( feature);
    bool isExist = false;
    if( size == 0)
    {
        return true;
    }
    else
    {
        for(  FeatureNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            if( tempNode->feature == feature)
                isExist = true;
        }
        if( isExist )
        {
            if( head->feature == feature )
            {
                FeatureNode* tempNode2 = head;
                head = head->next;
                delete tempNode2;
                tempNode2 = NULL;
                size--;
                return true;
            }

            for(  FeatureNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
            {
                FeatureNode* nextNode = tempNode->next;
                if( tempNode->next != NULL && nextNode->feature == feature )
                {

                    if( nextNode->next != NULL )
                    {
                        tempNode->next = nextNode->next;
                        delete nextNode;
                        nextNode =  NULL;
                        size--;
                        return true;
                    }
                    else
                    {
                        tempNode->next = NULL;
                        delete nextNode;
                        nextNode =  NULL;
                        size--;
                        return true;
                    }

                }
            }

            return false;
        }
        else
            return false;
    }
}


/**
*
*
*
*/
bool Flower::isFeatureExist( string feature )
{
    bool isExist = false;
    if( size == 0)
    {
        return false;
    }
    else
    {
        for(  FeatureNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            if( tempNode->feature == feature)
                isExist = true;
        }
   }
   return isExist;
}



    /**
    *
    *
    *
    */
    string Flower::printFlower() const
    {
        if( head == NULL )
        {
           return flowerName + ": No feature " ;
        }
        else
        {
            string ff ="";
            for( int i = 'a'; i < 'z' ; i++ )
            {
                for(  FeatureNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
                {
                   if((tempNode->feature).at(0) == i )
                        ff = ff + tempNode->feature + ", ";
                }
            }
            return  flowerName + ": " + ff;
        }
    }

/**
*
*
*/
void Flower::toLower( string& in)
{

	for(int i=0; in[i]!='\0' ; i++)
	{
		if ( in[i] >= 'A' && in[i] <= 'Z')
			in[i] = in[i] + 32;         //converting uppercase to lowercase
	}
}
