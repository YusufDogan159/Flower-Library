#include "FlowerList.h"


/**
*   Yusuf Dogan
*/

FlowerList::FlowerList()
{
    head = NULL;
    size =0;
}

FlowerList::~FlowerList()
{
    //dtor
}
FlowerList::FlowerList(const FlowerList& aList)
{

}
bool FlowerList::isEmpty() const
{
    if ( head == NULL || size == 0 )
        return true;
    else
        return false;
}
int FlowerList::getLength() const
{
    return size;
}
bool FlowerList::retrieve(string flowerName, Flower& flower) const
{

}
bool FlowerList::add(string flowerName)
{
    toLower(flowerName);
    if( size == 0)
        {
            head = new FlowerNode();
            head->f = Flower( flowerName );
            head->next = NULL;
            size++;
            return true;
        }
    else
    {
        for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            if( (tempNode->f).getName() == flowerName )
                return false;

            if( tempNode->next == NULL)
            {
                tempNode->next = new FlowerNode();
                (tempNode->next)->f =  Flower( flowerName);
                (tempNode->next)->next = NULL;
                size++;
                return true;
            }
        }
    }
    return false;
}

/**
*
*
*/
bool FlowerList::remove(string flowerName)
{
   toLower(flowerName);
   if( size == 0)
    {
        return false;
    }
    else
    {

        if(( head->f).getName() == flowerName )
        {
            FlowerNode* tempNode2 = head;
            head = head->next;
            delete tempNode2;
            tempNode2 = NULL;
            size--;
            return true;
        }

        for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            FlowerNode* nextNode = tempNode->next;

            if( nextNode != NULL && (nextNode->f).getName() == flowerName )
            {

                tempNode->next = nextNode->next;
                delete nextNode;
                nextNode =NULL;
                size--;
                return true;
            }
        }
        return false;
    }
    return false;
}

/**
*
*
*/
void FlowerList::listFlowers() const
{
    if( head != NULL)
    {
        for( int i = 'a'; i < 'z' ; i++ )
        {
            for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
            {
                if((tempNode->f).getName().at(0) == i )
                {
                    cout << ((tempNode->f).printFlower()) << endl;
                }
            }
       }
    }
    else
         cout << "Library is empty!" << endl;
}

/**
*
*
*
*/
void FlowerList::addFeatureToFlower(string name,string feature)
{
    toLower(name);
    bool isExist = false;
    for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
    {
        if( (tempNode->f).getName() == name )
        {
            isExist = true;
        }
    }


    if( isExist)
    {
        for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            if( (tempNode->f).getName() == name )
            {
                if((tempNode->f).add(feature))
                {
                    cout << feature << " is added into " << name << endl;
                }
                else
                {
                   cout << feature << "  already exists in " << name << endl;
                }
            }
        }
    }
    else
        cout << name << "  is not found in Library " << endl;
}

/**
*
*
*
*/
void FlowerList::removeFeatureFromFlower(string name, string feature)
{
    toLower(name);
    bool isExist = false;
    for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
    {
        if( (tempNode->f).getName() == name )
        {
            isExist = true;
        }
    }


    if( isExist)
    {
        for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
        {
            if( (tempNode->f).getName() == name )
            {
                if((tempNode->f).remove(feature))
                {
                    cout << feature << " is removed from " << name << endl;
                }
                else
                {
                    cout << feature << " does not exist in " << name << endl;
                }
            }
        }
    }
    else
        cout << name << "  is not found in Library " << endl;
}


/**
*
*
*
*/
void FlowerList::listFeatures(string name)const
{
    bool isExist = false;
    FlowerNode* toBeListed;

    for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
    {
        if( (tempNode->f).getName() == name )
        {
            toBeListed = tempNode;
            isExist = true;
        }
    }
    if( isExist )
        cout << (toBeListed->f).printFlower() << endl;
    else
        cout << name << " does not exist in the Library " <<endl;
}


/**
*
*
*
*/
 void FlowerList::findFlowers(string feature) const
 {
    string flowers = "";
    int count = 0;
    for(  FlowerNode* tempNode = head; tempNode != NULL; tempNode = tempNode->next )
    {
        if(( tempNode->f).isFeatureExist( feature ))
        {
            flowers = flowers + (tempNode->f).getName() + ", " ;
            count++;
        }
    }

    if( !count )
        cout << feature << " flowers: there is no such flower " << endl;
    else
        cout << feature << " flowers: " << flowers  <<endl ;
}



/**
*
*
*/
void FlowerList::toLower( string& in)
{

	for(int i=0; in[i]!='\0' ; i++)
	{
		if ( in[i] >= 'A' && in[i] <= 'Z')
			in[i] = in[i] + 32;         //converting uppercase to lowercase
	}
}
