#pragma once
#include "Layersystem.h"
#include "Renderer/Renderer.h"
#include <GLFW/glfw3.h>
class GameLayer : public Layer
{
public:
	GameLayer();
	virtual bool RecieveEvent(Event& e) override;
	virtual void OnUpdate() override;
	virtual void Draw() override;
private:
	void CameraMovement();
	Texture* tex;
	Camera* cam;

};

