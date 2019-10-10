#ifndef LIST
#define LIST

#include "base.h"

#include <vector>
#include <memory>

template < class T >
struct List : public Base
{
    std::vector < std::shared_ptr < T > > objects;

    List () { }
    ~List () { }

    void render ()
    {
        for ( auto & object : objects )
        {
            object->render ();
        }
    }

    void set ( float x , float y , int w , int h )
    {
        std::shared_ptr < T > object = std::make_shared < T > ();
        object->set ( x , y , w , h );
        objects.push_back ( std::move ( object ) );
    }

    void move ()
    {
        for ( auto & object : objects )
        {
            object->move ();
        }
    }

    void update ()
    {
        for ( auto & object : objects )
        {
            object->update ();
        }
    }

    void event ( SDL_Event event )
    {
        for ( auto & object : objects )
        {
            object->event ( event );
        }
    }

    bool clear ()
    {
        for ( auto it = objects.begin (); it != objects.end(); )
        {
            if ( ( *it )->clear () ) it = objects.erase ( it );
            else ++it;
        }

        return false;
    }

    uint8 collisionType ()
    {
        return 0;
    }

    void collide ( std::shared_ptr < Base > a , AABB aBox )
    {
        return;
    }

    std::string getPositionHash ( int x , int y )
    {
        return "";
    }

    void adjust ()
    {

    }
};

#endif
