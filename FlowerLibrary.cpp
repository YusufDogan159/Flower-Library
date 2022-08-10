#include "FlowerLibrary.h"

/**
*   Yusuf Dogan
*/

FlowerLibrary::FlowerLibrary()
{

}

FlowerLibrary::~FlowerLibrary()
{
    //dtor
}
void FlowerLibrary::addFlower(string name)
{
    toLower(name);

    if( flowers.add( name ))
        cout << name << " has been added into Library" << endl;
    else
        cout << name << " cannot be added into the library because it already exists." << endl;

}
void FlowerLibrary::removeFlower(string name)
{
    toLower(name);

    if( flowers.remove( name ))
        cout << name << " has been removed from Library" << endl;
    else
        cout << name << " cannot be removed  because it's not in the Library." << endl;
}
void FlowerLibrary::listFlowers() const
{
    flowers.listFlowers();
}
void FlowerLibrary::listFeatures(string name) const
{
    flowers.listFeatures(name);
}
void FlowerLibrary::addFeature(string name,string feature)
{
    flowers.addFeatureToFlower(name, feature);
}
void FlowerLibrary::removeFeature(string name, string feature)
{
    flowers.removeFeatureFromFlower(name, feature);
}
void FlowerLibrary::findFlowers(string feature) const
{
    flowers.findFlowers( feature);
}
void FlowerLibrary::toLower( string& in)
{

	for(int i=0; in[i]!='\0' ; i++)
	{
		if ( in[i] >= 'A' && in[i] <= 'Z')
			in[i] = in[i] + 32;         //converting uppercase to lowercase
	}
}
