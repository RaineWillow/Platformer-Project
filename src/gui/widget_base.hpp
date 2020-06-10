#ifndef Widget_Base_hpp
#define Widget_Base_hpp

class WidgetBase {
public:
	virtual void update()=0;
	virtual void render()=0;
};

#endif
