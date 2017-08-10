#include "RectF.h"

RectF::RectF( float left_in,float right_in,float top_in,float bottom_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottom( bottom_in )
{
}

RectF::RectF( const Vec2& topLeft,const Vec2 & bottomRight )
	:
	RectF( topLeft.x,bottomRight.x,topLeft.y,bottomRight.y )
{
}

RectF::RectF( const Vec2& topLeft,float width,float height )
	:
	RectF( topLeft,topLeft + Vec2( width,height ) )
{
}

bool RectF::IsOverlappingWith( const RectF& other ) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

void RectF::setPos(Vec2 & pos)
{
	right = right - left + pos.x;
	bottom = bottom - top + pos.y;
	left = pos.x;
	top = pos.y;
}
