
#include "../Components/Component.h"
#include "vector";
using namespace std;

class Entity {

public:


protected:
	vector <Component* > components;
	vector <Entity*> childs;
	Entity* parent =NULL;


};