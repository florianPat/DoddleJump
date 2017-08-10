#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"
#include "RectF.h"
#include "Platforms.h"
#include "FrameTimer.h"

class Doodle
{
	Graphics& graphics;
	Keyboard& keyboard;
	Platforms& platforms;
	Vec2 pos;
	RectF boundingBox;
	static constexpr float speed = 100.0f;
	static constexpr float width = 32.0f, height = 64.0f;
	static constexpr float jumpDuration = 4.0f;
	float currentJumpTime = 0.0f;
	bool isJumping = false;
public:
	Doodle(Graphics& graphics, Keyboard& keyboard, Platforms& platforms, Vec2& startingPos);
	void update(float dt, bool* gameOver, bool* platformsShouldMove);
	void draw();
	RectF& getBoundingBox();
};