#pragma once
#include <string>
#include <iostream>
#include "Misc/Utility.h"

class Event
{
public:
	virtual void Print() = 0;
	virtual uint32_t GetType() { return m_Type; }
	void Handle() { m_WasHandled = true; }
	const bool& Handled() const { return m_WasHandled; }
protected:
	std::string m_Name = "Event";
	uint32_t m_Type;
	bool m_WasHandled = false;
};

class IEventListener
{
public:
	virtual void OnEvent(Event& e) = 0;
};

enum EventType
{
	WindowResizeEventType, WindowCloseEventType,
	MouseMovedEventType, MouseButtonClickedEventType,
	KeyPressedEventType, KeyReleasedEventType, KeyHeldEventType
};

class KeyPressedEvent : public Event
{
public:
	KeyPressedEvent(int key)
		:m_Type(KeyPressedEventType), m_Key(key)
	{

	}
	virtual void Print() override { std::cout << this->m_Name << "\n"; }
	virtual uint32_t GetType() override { return m_Type; }
	virtual int GetKey() { return m_Key; }
private:
	std::string m_Name = "KeyPressedEvent";
	uint32_t m_Type;
	int m_Key;
};

class KeyReleasedEvent
{

};

class KeyHeldEvent
{

};

class WindowCloseEvent: public Event
{
public:
	WindowCloseEvent()
		:m_Type(WindowCloseEventType)
	{

	}
	virtual void Print() override { std::cout << this->m_Name << "\n"; }
	virtual uint32_t GetType() override { return m_Type; }
private:
	std::string m_Name = "WindowCloseEvent";
	uint32_t m_Type;
};

class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(int width, int height)
		:m_Width(width), m_Height(height), m_Type(EventType::WindowResizeEventType)
	{
	}
	virtual uint32_t GetType() override { return m_Type; }
	virtual void Print() override { std::cout << m_Name << ": " << m_Width	<< ", " << m_Height << "\n"; }
	const int& GetWidth() const { return m_Width; }
	const int& GetHeight() const { return m_Height; }
private:
	std::string m_Name = "WindowResizeEvent";
	uint32_t m_Type;
	int m_Width, m_Height;
};

class MouseMovedEvent : public Event
{
public:
	MouseMovedEvent(double x, double y)
		:m_Type(EventType::MouseMovedEventType), m_Xpos(x), m_Ypos(y)
	{

	}
	virtual uint32_t GetType() override { return m_Type; }
	virtual void Print() override { std::cout << m_Name << ": " << m_Xpos << ", " << m_Ypos << "\n"; }
	const double& GetX() const { return m_Xpos; }
	const double& GetY() const { return m_Ypos; }
private:
	uint32_t m_Type;
	double m_Xpos, m_Ypos;
};

class EventDispatcher
{
public:
	EventDispatcher(uint32_t possibleEventTypes)
		:m_PossibleTypes(possibleEventTypes)
	{

	}
	uint32_t GetTypes() { return m_PossibleTypes; }
private:
	uint32_t m_PossibleTypes;
};