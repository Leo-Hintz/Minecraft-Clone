#include "GameLayer.h"


GameLayer::GameLayer()
{
	tex = new Texture("Textures/Grassblock.png");
	cam = new Camera(glm::vec3(-1.5f, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1), glm::vec3(1, 0, 0), 90.0f, 0.1f, 100.0f, 1920.0f, 1080.0f);
}

bool GameLayer::RecieveEvent(Event& e)
{
	if (e.GetType() == EventType::WindowResizeEventType)
	{
		WindowResizeEvent* resizeEvent = (WindowResizeEvent*) &e;
		cam->SetHeight(resizeEvent->GetHeight());
		cam->SetWidth(resizeEvent->GetWidth());
		return true;
	}
	else if (e.GetType() == EventType::KeyPressedEventType)
	{
		KeyPressedEvent* keyEvent = (KeyPressedEvent*) &e;
		if (keyEvent->GetKey() == 87)
		{
			cam->SetPosition(glm::vec3(cam->GetPosition().x + 1, cam->GetPosition().y, cam->GetPosition().z));
		}
		else if (keyEvent->GetKey() == 83)
		{
			cam->SetPosition(glm::vec3(cam->GetPosition().x - 1, cam->GetPosition().y, cam->GetPosition().z));
		}
		else if (keyEvent->GetKey() == 65)
		{
			cam->SetPosition(glm::vec3(cam->GetPosition().x, cam->GetPosition().y, cam->GetPosition().z - 1));
		}
		else if (keyEvent->GetKey() == 68)
		{
			cam->SetPosition(glm::vec3(cam->GetPosition().x, cam->GetPosition().y, cam->GetPosition().z +  1));
		}
	}
	if (e.GetType() == EventType::MouseMovedEventType)
	{
		MouseMovedEvent* mouseEvent = (MouseMovedEvent*)&e;

	}
}

void GameLayer::OnUpdate()
{

}

void GameLayer::Draw()
{
	Renderer::RenderBlock(cam, tex, 1, 1);
}

void GameLayer::CameraMovement()
{

}
