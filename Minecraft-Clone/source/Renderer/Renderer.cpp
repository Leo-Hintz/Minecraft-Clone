#include "Renderer.h"

Shader* Renderer::m_BlockShader;


GLuint Renderer::m_VertexArray;

void Renderer::Init()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD!\n";
	}
	m_BlockShader = new Shader("Shader/BlockShader.vert", "Shader/BlockShader.frag");
    glClearColor(0.3, 0.21, 07, 1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
	Vertex vertices[36]
	{  
        {{-0.5f,0.5f,-0.5f,1},{},{}},
        {{ 0.5f,0.5f,-0.5f,1}, {},{}},
        {{0.5f,-0.5f,-0.5f,1}, {},{}},
        {{0.5f,-0.5f,-0.5f,1}, {},{}},
        {{-0.5f,-0.5f,-0.5f,1},{},{}},
        {{-0.5f,0.5f,-0.5f,1},{},{}},
        
        {{-0.5f,0.5f,0.5f,1}, {},{}},
        {{-0.5f,-0.5f,0.5f,1},{},{}},
        {{0.5f,-0.5f,0.5f,1}, {},{}},
        {{0.5f,-0.5f,0.5f,1}, {},{}},
        {{0.5f,0.5f,0.5f,1},{},{}},
        {{-0.5f,0.5f,0.5f,1}, {},{}},

        {{0.5f,0.5f,-0.5f,1}, {},{}},
        {{0.5f,0.5f,0.5f,1},{},{}},
        {{0.5f,-0.5f,0.5f,1}, {},{}},
        {{0.5f,-0.5f,0.5f,1}, {},{}},
        {{0.5f,-0.5f,-0.5f,1}, {},{}},
        {{0.5f,0.5f,-0.5f,1}, {},{}},
        
        {{-0.5f,0.5f,-0.5f,1}, {},{}},
        {{ -0.5f,-0.5f,-0.5f,1},{},{}},
        {{-0.5f,-0.5f,0.5f,1}, {},{}},
        {{-0.5f,-0.5f,0.5f,1}, {},{}},
        {{-0.5f,0.5f,0.5f,1}, {},{}},
        {{-0.5f,0.5f,-0.5f,1}, {},{}},

        {{-0.5f,0.5f,0.5f,1}, {},{}},
        {{-0.5f,0.5f,-0.5f,1},{},{}},
        {{0.5f,0.5f,-0.5f,1}, {},{}},
        {{0.5f,0.5f,-0.5f,1}, {},{}},
        {{0.5f,0.5f,0.5f,1}, {},{}},
        {{-0.5f,0.5f,0.5f,1}, {},{}},
        
        {{-0.5f,-0.5f,0.5f,1}, {},{}},
        {{-0.5f,-0.5f,-0.5f,1},{},{}},
        {{ 0.5f,-0.5f,-0.5f,1}, {},{}},
        {{ 0.5f,-0.5f,-0.5f,1}, {},{}},
        {{0.5f,-0.5f,0.5f,1}, {},{}},
        {{-0.5f,-0.5f,0.5f,1}, {},{}}
	};

    glGenVertexArrays(1, &m_VertexArray);
    glBindVertexArray(m_VertexArray);
	uint32_t vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
    glEnableVertexAttribArray(0);
  
}

void Renderer::RenderBlock(Camera* cam, Texture* tex, int32_t x, int32_t y)
{
    cam->CalculateMatrices();
    glClear(GL_COLOR_BUFFER_BIT);
	tex->Use();
	m_BlockShader->Use();

    glBindVertexArray(m_VertexArray);
    m_BlockShader->SetMat4("viewMatrix", cam->GetViewMatrix());
    m_BlockShader->SetMat4("projectionMatrix", cam->GetProjectionMatrix());
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
