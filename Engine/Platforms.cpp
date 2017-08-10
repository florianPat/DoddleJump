#include "Platforms.h"
#include "Colors.h"

Platforms::Platforms(Graphics& graphics) : graphics(graphics), boundingBoxes(), dist(0.0f, (float)graphics.ScreenWidth - (float)width), range(), frameTimer()
{
	boundingBoxes.emplace_back((RectF(Vec2{ dist(range), 0.0f }, (float)width, (float)height)));
}

void Platforms::update(float dt)
{
	if (!isInitialized)
	{
		duration += frameTimer.Mark();
		if (duration > spawnDuration)
		{
			duration = 0.0f;
			for (int i = size; i < size + 1; ++i)
			{
				boundingBoxes.emplace_back((RectF(Vec2{ dist(range), 0.0f }, (float)width, (float)height)));
			}
			++size;
			if (size == maxSize)
				isInitialized = true;
		}
	}

	for (auto it = boundingBoxes.begin(); it != boundingBoxes.end(); ++it)
	{
		Vec2 vel(0.0f, 90.81f);
		vel *= dt;
		Vec2 newPos(it->left + vel.x, it->top + vel.y);
		it->setPos(newPos);
		if (it->bottom >= graphics.ScreenHeight)
			*it = RectF(Vec2{ dist(range), 0.0f }, width, height);
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

bool & Platforms::getIsInitialized()
{
	return isInitialized;
}
