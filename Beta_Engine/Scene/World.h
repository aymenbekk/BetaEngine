#ifndef WORLD_H
#define WORLD_H
#include "Entity.h"




class World
{
public:
	World();
	~World();

private:
	vector<Entity*> chunks;//Entity=Chunk each Chunk has a transform



};




#endif // !WORLD_H
