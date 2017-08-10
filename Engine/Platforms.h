#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"
#include "RectF.h"
#include <vector>
#include <random>
#include "FrameTimer.h"

class Platforms
{
	std::mt19937 range;
	std::uniform_real_distribution<float> distX;
	static constexpr float width = 96.0f, height = 16.0f;
	Graphics& graphics;
	std::vector<RectF> boundingBoxes;
	FrameTimer frameTimer;
	static constexpr float spawnDuration = 1.0f;
	float duration = 0.0f;
	bool isInitialized = false;
	int size = 1;
	static constexpr int maxSize = 8;
public:
	Platforms(Graphics& graphics);
	void update(float dt);
	void draw();
	std::vector<RectF>& getBoundingBoxes();
	bool& getIsInitialized();
};