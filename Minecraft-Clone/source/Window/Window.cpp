#include "Window.hpp"

Window::Window(int width, int height, const char* title)
	:m_Width(width), m_Height(height), m_Title(title)
{
	m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);

	glfwSetWindowUserPointer(m_Window, &m_Data);
	glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
	{
		WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
		data->windowClosed = true;
		WindowCloseEvent e;
		for (auto& eventListener : data->m_EventListeners)
		{
			eventListener->OnEvent(e);
		}
	});
	glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
	{
		WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
		data->width = width;
		data->height = height;
		glViewport(0, 0, width, height);
		WindowResizeEvent e = WindowResizeEvent(width, height);
		for (auto& eventListener : data->m_EventListeners)
		{
			eventListener->OnEvent(e);
		}
	});
	glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double x, double y)
	{
		WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
		data->x = x;
		data->y = y; 
		MouseMovedEvent e = MouseMovedEvent(x, y);
		for (auto& eventListener : data->m_EventListeners)
		{
			eventListener->OnEvent(e);
		}
	});
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
 }

void Window::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void Window::PollInput()
{
	if (glfwGetKey(m_Window, GLFW_KEY_W))
	{
		KeyPressedEvent e = KeyPressedEvent(GLFW_KEY_W);
		for (auto& eventListener : m_Data.m_EventListeners)
		{
			eventListener->OnEvent(e);
		}
	}
	if (glfwGetKey(m_Window, GLFW_KEY_S))
	{
		KeyPressedEvent e = KeyPressedEvent(GLFW_KEY_S);
		for (auto& eventListener : m_Data.m_EventListeners)
		{
			eventListener->OnEvent(e);
		}
	}
	if (glfwGetKey(m_Window, GLFW_KEY_A))
	{
		KeyPressedEvent e = KeyPressedEvent(GLFW_KEY_A);
		for (auto& eventListner : m_Data.m_EventListeners)
		{
			eventListner->OnEvent(e);
		}
	}
	if (glfwGetKey(m_Window, GLFW_KEY_D))
	{
		KeyPressedEvent e = KeyPressedEvent(GLFW_KEY_D);
		for (auto& eventListner : m_Data.m_EventListeners)
		{
			eventListner->OnEvent(e);
		}
	}
}
