#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include "Events/Event.h"

#define WindowEventTypes EventType::WindowCloseEvent | EventType::WindowResizeEvent

struct WindowData
{
public:
	int width, height;
	bool windowClosed = false;
	std::vector<IEventListener*> m_EventListeners;
	double x, y;
};

class Window
{
public:
	static void Init() { glfwInit(); }
	Window(int width, int height, const char* title);
	~Window();
	bool& ShouldWindowClose() { return m_Data.windowClosed; }
	void OnUpdate();
	WindowData& GetWindowData() { return m_Data; }
	void PollInput();
private:
	GLFWwindow* m_Window;
	int m_Width, m_Height;
	const char* m_Title;
	WindowData m_Data;

	//Events
//	EventReciever  m_EventReciever;
};

