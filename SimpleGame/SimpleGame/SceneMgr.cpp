#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {}
SceneMgr::~SceneMgr() {}
void SceneMgr::Checking() {
	for (int i = 0; i < MAX; ++i)
	{
		if(obj[i].GetLife()>0)
		for (int j = 0; j < MAX; ++j)
		{
			if (i == j)
				continue;
			if(obj[i].GetTeam() == obj[j].GetTeam())
				continue;
			if ((obj[i].GetLife()>0&& obj[j].GetLife()>0) && (obj[i].GetTime()>0 && obj[j].GetTime()>0))
				if (
					(obj[i].GetY() + (obj[i].GetSize()/2) > obj[j].GetY()) && (obj[i].GetY() - (obj[i].GetSize() / 2) < obj[j].GetY())
					)
				{
					if (
						(obj[i].GetX() + (obj[i].GetSize() / 2) > obj[j].GetX()) && (obj[i].GetX() - (obj[i].GetSize() / 2) < obj[j].GetX())
						)
					{
						if (obj[i].GetMod() == 4 && obj[j].GetMod() == 1)
						{
							obj[i].SetLife(obj[i].GetLife() - obj[j].GetLife());
							obj[j].SetLife(0);
							cout << "Team" << obj[i].GetTeam() << "�� ���� HP" << obj[i].GetLife() << endl;
						}
						if (obj[i].GetMod() == 0 && obj[j].GetMod() == 1)
						{
							obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
							obj[i].SetLife(0);
						}
						if (obj[i].GetMod() == 6 && obj[j].GetMod() == 1)
						{
							if (obj[i].GetArrow() != j)
							{
								obj[j].SetLife(obj[j].GetLife() - obj[i].GetLife());
								obj[i].SetLife(0);
							}
						}
						if (obj[i].GetMod() == 4 && obj[j].GetMod() == 6)
						{
							obj[i].SetLife(obj[i].GetLife() - obj[j].GetLife());
							obj[j].SetLife(0);
							cout << "Team"<<obj[i].GetTeam()<<" ���� HP" << obj[i].GetLife() << endl;
						}
					}
				}
		}
	}
}
int SceneMgr::Moding(int n)
{
	for (int i = 0; i < MAX; ++i)
		if (obj[i].GetMod() == 1&& obj[i].GetLife() >0 && obj[i].GetTime() >0)
		{
			n++;
			SceneSet(n, obj[i].GetX(), obj[i].GetY(),0, OBJECT_ARROW,obj[i].GetTeam());
			obj[n].SetArrow(i);
		}
	n++;
	return n;
}

void SceneMgr::Rendering(int n)
{
	if (n >= MAX)
		n = MAX;
	for (int i = 0;i<n;++i)
	{
		obj[i].Update(10.0);
		obj[i].Draw(g_Renderer);
	}
}
void SceneMgr::SceneSet(int n, float x, float y, float z, float size, float r, float g, float b, float a, float vx, float vy, int l, int lt, int  mod,int t) 
{
	if (n >= MAX)
		n = n%MAX;
	obj[n].Set(x,y,z,size,r,g,b,a,vx,vy,l,lt,mod,t); 
	if (mod == 4)
		if(obj[n].GetTeam() == 1)
			obj[n].SetTexture(Building_texCharacter1);
		else
			obj[n].SetTexture(Building_texCharacter2);
}
void SceneMgr::Rising()
{
	g_Renderer = new Renderer(Horizontal, Vertical);
}
void SceneMgr::Ending()
{
	delete(g_Renderer);
}

void  SceneMgr::TextureMaping()
{
	Building_texCharacter1 = g_Renderer->CreatePngTexture("Textures/texture2.png");
	Building_texCharacter2 = g_Renderer->CreatePngTexture("Textures/texture1.png");
}