
#include "Texture.h"
#define STB_IMAGE_IMPLENTATION
#include "stb_image.h"
#include <iostream>

Texture::Texture(const char* fileDirectory)
{
	int x, y, channels;
	unsigned char* texData = stbi_load(fileDirectory, &x, &y, &channels, 4);
	glGenTextures(1, &m_TextureID);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(texData);
}
