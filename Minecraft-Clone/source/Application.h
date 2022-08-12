#pragma once
#include "Layers/GameLayer.h"
#include "Window/Window.hpp"
#include "Events/Event.h"
#include "Layers/Layersystem.h"
class Application : IEventListener
{
public:
	void Run();
	virtual void OnEvent(Event& e) override;
};

