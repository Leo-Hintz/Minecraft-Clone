#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 startPos, glm::vec3 UP, glm::vec3 RIGHT, glm::vec3 FRONT, float FOV, float near, float far, float width, float height);
	void SetRight(glm::vec3 right) { m_Right = right; }
	glm::vec3& GetRight() { return m_Right; }
	void SetFront(glm::vec3 front) { m_Front = front; }
	glm::vec3& GetFront() { return m_Front; }
	void SetUp(glm::vec3 up) { m_Up = up; }
	glm::vec3& GetUp() { return m_Up; }
	void SetPosition(glm::vec3 pos) { m_Pos = pos; }
	glm::vec3 GetPosition() { return m_Pos; }
	void SetFOV(float fov) { m_FOV = fov; }
	void SetWidth(float width) { m_Width = width; }
	void SetHeight(float height) { m_Height = height; }
	const glm::mat4& GetViewMatrix() { return m_ViewMatrix; }
	const glm::mat4& GetProjectionMatrix() { return m_ProjectionMatrix; }
	void CalculateMatrices();
private:
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;


	glm::vec3 m_Right;
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	glm::vec3 m_Pos;

	float m_FOV;
	float m_Near;
	float m_Far;
	float m_Width, m_Height;
};