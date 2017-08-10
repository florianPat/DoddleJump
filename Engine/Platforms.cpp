#include "Platforms.h"
#include "Colors.h"

Platforms::Platforms(Graphics& graphics) : graphics(graphics), boundingBoxes(maxSize), distX(0.0f, (float)graphics.ScreenWidth - width), 
										   distY(0.0f, (float)graphics.ScreenHeight - height), range()
{
	for(int i = 0; i < boundingBoxes.size(); ++i)
		boundingBoxes[i] = RectF(Vec2{ distX(range), distY(range) }, (float)width, (float)height);
}

void Platforms::update(float dt)
{
	for (auto it = boundingBoxes.begin(); it != boundingBoxes.end(); ++it)
	{
		Vec2 vel(0.0f, 90.81f);
		vel *= dt;
		Vec2 newPos(it->left + vel.x, it->top + vel.y);
		it->setPos(newPos);
		if (it->bottom >= graphics.ScreenHeight)
			*it = RectF(Vec2{ distX(range), 0.0f }, width, height);
	}
}

void Platforms::draw()
{
	for (auto it : boundingBoxes)
	{
		graphics.DrawRect(it, Colors::Blue);
	}
}

std::vector<RectF>& Platforms::getBoundingBoxes()
{
	return boundingBoxes;
}