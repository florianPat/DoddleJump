#include "Doddle.h"
#include "Colors.h"

Doodle::Doodle(Graphics& graphics, Keyboard& keyboard, Platforms& platforms, Vec2& startingPos) : graphics(graphics), keyboard(keyboard), pos(startingPos),
																			boundingBox(pos, width, height), platforms(platforms)
{
}

void Doodle::update(float dt, bool* gameOver, bool* platformsShouldMove)
{
	Vec2 vel(0.0f, 90.81f * dt);

	if (keyboard.KeyIsPressed(VK_LEFT))
	{
		vel.x -= speed * dt;
	}
	if (keyboard.KeyIsPressed(VK_RIGHT))
	{
		vel.x += speed * dt;
	}

	auto platformBoxes = platforms.getBoundingBoxes();
	for (auto it : platformBoxes)
	{
		//TODO: Update this that you have to be ON the platform!!
		if (boundingBox.IsOverlappingWith(it))
			isJumping = true;

		if (isJumping)
		{
			*platformsShouldMove = true;
			currentJumpTime += dt;
			if (currentJumpTime > jumpDuration)
			{
				isJumping = false;
				currentJumpTime = 0.0f;
			}
			else
			{
				vel.y -= speed * dt;
			}

			break;
		}
		else
			*platformsShouldMove = false;
	}

	Vec2 newPos(boundingBox.left + vel.x, boundingBox.top + vel.y);
	boundingBox.setPos(newPos);

	if (boundingBox.left < 0.0f)
	{
		newPos.x = 0.0f;
		boundingBox.setPos(newPos);
	}
	else if (boundingBox.right > graphics.ScreenWidth)
	{
		newPos.x = graphics.ScreenWidth - width;
		boundingBox.setPos(newPos);
	}
	
	if (boundingBox.bottom > graphics.ScreenHeight)
	{
		*gameOver = true;
		return;
	}
	else if (boundingBox.top < 0.0f)
	{
		newPos.y = 0.0f;
		boundingBox.setPos(newPos);
	}

	*gameOver = false;
}

void Doodle::draw()
{
	graphics.DrawRect(boundingBox, Colors::Green);
}

RectF & Doodle::getBoundingBox()
{
	return boundingBox;
}
