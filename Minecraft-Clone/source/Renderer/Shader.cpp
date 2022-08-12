#include "Shader.h"

Shader::Shader(const char* vertexFileName, const char* fragmentFileName)
{

	m_ShaderID = glCreateProgram();

	std::ifstream file { vertexFileName };

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);


	std::string vertString = LoadFile(vertexFileName);
	const char* vertCode = vertString.c_str();
	int32_t length = vertString.length();
	glShaderSource(vertexShader, 1, &vertCode, &length);
	
	glCompileShader(vertexShader);

	int status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{	
		char infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "[VERTEX SHADER ERROR]: " << infoLog << "\n";
	}


	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragString = LoadFile(fragmentFileName);
	const char* fragCode = fragString.c_str();
	length = fragString.length();
	glShaderSource(fragmentShader, 1, &fragCode, &length);

	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "[FRAGMENT SHADER ERROR]: " << infoLog << "\n";
	}

	glAttachShader(m_ShaderID, vertexShader);
	glAttachShader(m_ShaderID, fragmentShader);

	glLinkProgram(m_ShaderID);

	
	glGetProgramiv(m_ShaderID, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		char infoLog[512];
		glGetProgramInfoLog(m_ShaderID, 512, nullptr, infoLog);
		std::cout << "[SHADER LINKING ERROR]: " << infoLog << "\n";
	}

	glValidateProgram(m_ShaderID);

	glGetProgramiv(m_ShaderID, GL_VALIDATE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char infoLog[512];
		glGetProgramInfoLog(m_ShaderID, 512, nullptr, infoLog);
		std::cout << "[SHADER VALIDATION ERROR]: " << infoLog << "\n";
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Use()
{
	glUseProgram(m_ShaderID);
}

void Shader::SetVec4(const char* name, glm::vec4 value)
{
	glUniform4fv(glGetUniformLocation(m_ShaderID, name), 1, glm::value_ptr(value));
}

void Shader::SetVec3(const char* name, glm::vec3 value)
{
	glUniform3fv(glGetUniformLocation(m_ShaderID, name), 1, glm::value_ptr(value));
}

void Shader::SetVec2(const char* name, glm::vec2 value)
{
	glUniform2fv(glGetUniformLocation(m_ShaderID, name), 1, glm::value_ptr(value));
}

void Shader::SetMat4(const char* name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat3(const char* name, glm::mat3 value)
{
	glUniformMatrix3fv(glGetUniformLocation(m_ShaderID, name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetInt(const char* name, int32_t value)
{
	glUniform1i(glGetUniformLocation(m_ShaderID, name), value);
}

void Shader::SetFloat(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(m_ShaderID, name), value);
}
