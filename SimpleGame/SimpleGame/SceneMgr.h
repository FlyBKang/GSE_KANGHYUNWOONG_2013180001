#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Renderer.h"
#define MAX 50
#define BREAK 10
class SceneMgr
{
	bool check[MAX];
	Object obj[MAX];
public:
	SceneMgr();
	~SceneMgr();
	void SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int  mod);
	void Checking();
	void Rendering(Renderer *g_Renderer,int n);
};