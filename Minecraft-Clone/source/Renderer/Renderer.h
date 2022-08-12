#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Textures/Texture.h"
#include "Shader.h"
#include "Camera/Camera.h"

struct Vertex
{
	glm::vec4 pos;
	glm::vec2 texCoords;
	glm::vec3 normal;
};

class Renderer
{
public:
	static void Init();
	static void RenderBlock(Camera* cam, Texture* block, int32_t x, int32_t y);
private:
	static Shader* m_BlockShader;

	
	static GLuint m_VertexArray;
};
