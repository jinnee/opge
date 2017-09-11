#ifndef ABSTRACTGAME_H
#define	ABSTRACTGAME_H

class AbstractGame 
{
    public:

        virtual void init() = 0;
        virtual void freeResources() = 0;
        virtual void render() = 0;
        virtual void update(double deltaTime) = 0;
};


#endif	/* ABSTRACTGAME_H */

