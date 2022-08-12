#pragma once
#include <glad/glad.h>
class Texture
{
public:
	Texture(const char* fileDirectory);
	void Use()
	{
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}
private:
	GLuint m_TextureID = 0;
};