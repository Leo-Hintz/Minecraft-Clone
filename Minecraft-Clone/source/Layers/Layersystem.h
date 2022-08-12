#pragma once
#include <queue>
#include "Events/Event.h"

class Layer
{
public:
	virtual bool RecieveEvent(Event& e) = 0;
	virtual void OnUpdate() = 0;
	virtual void Draw() = 0;
};

class Layersystem
{
public:
	static void begin()
	{
		m_Layers.begin();
	}
	static void pop()
	{
		m_Layers.pop_back();
	}
	static void push(Layer* layer)
	{
		m_Layers.push_back(layer);
	}
	static void DispatchEvent(Event& e)
	{

		for (int i = 0; i < m_Layers.size(); i++)
		{
			if (e.Handled()) return;
			
			if (m_Layers[i]->RecieveEvent(e))
			{
				e.Handle();
			}
		}
	}
	static void UpdateLayers()
	{
		for (int i = 0; i < m_Layers.size(); i++)
		{
			m_Layers[i]->OnUpdate();
		}
	}
	static void DrawLayers()
	{
		for (int i = m_Layers.size() - 1; i >= 0; i--)
		{
			m_Layers[i]->Draw();
		}
	}
private:
	static std::vector<Layer*> m_Layers;
};
