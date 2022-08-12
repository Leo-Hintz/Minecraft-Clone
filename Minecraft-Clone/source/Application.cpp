#include "Application.h"

void Application::Run()
{
	Window::Init();
	Window window = Window(1920, 1080, "Minecraft");
	window.GetWindowData().m_EventListeners.push_back(this);
	Renderer::Init();

	GameLayer* layer = new GameLayer();
	Layersystem::push(layer);


	while (!window.ShouldWindowClose())
	{
		window.OnUpdate();
		window.PollInput();
		Layersystem::UpdateLayers();
		Layersystem::DrawLayers();
	}
}

void Application::OnEvent(Event& e)
{
	Layersystem::DispatchEvent(e);
}
