#ifndef COMPONENT_H
#define COMPONENT_H



class Component {

public:
	Component();

	virtual void update()=0;
	virtual void Render() {};


};


#endif // !COMPONENT_H
