#include "Camera.h"

Camera::Camera(glm::vec3 startPos, glm::vec3 UP, glm::vec3 RIGHT, glm::vec3 FRONT, float FOV, float near, float far, float width, float height)
	:m_Pos(startPos), m_Front(FRONT), m_Right(RIGHT), m_Up(UP), m_Width(width), m_Height(height), m_FOV(FOV), m_Near(near), m_Far(far)
{
	CalculateMatrices();
}

void Camera::CalculateMatrices()
{
	m_ViewMatrix = glm::lookAt(m_Pos, m_Pos + m_Front, m_Up);
	m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_Width / m_Height, m_Near, m_Far);
}
