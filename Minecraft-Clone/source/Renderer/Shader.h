#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <iostream>

#include "Misc/Utility.h"
class Shader
{
public:
	Shader(const char* vertexFileName, const char* fragmentFileName);
	void Use();
	void SetVec4(const char* name, glm::vec4 value);
	void SetVec3(const char* name, glm::vec3 value);
	void SetVec2(const char* name, glm::vec2 value);
	void SetMat4(const char* name, glm::mat4 value);
	void SetMat3(const char* name, glm::mat3 value);
	void SetInt(const char* name, int32_t value);
	void SetFloat(const char* name, float value);

private:
	GLuint m_ShaderID;
};

