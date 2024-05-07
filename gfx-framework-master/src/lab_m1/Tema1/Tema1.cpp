#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    cullFace = GL_BACK;
    polygonMode = GL_FILL;

    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;

    // Initialize tx and ty (the translation steps)
    translateX_hex = 0;
    translateY_hex = 0;

    translateX_hex_2 = 0;
    translateX_hex_3 = 0;
    translateX_hex_4 = 0;

    translateX_star = 0;
    translateY_star = 0;

    t_x1 = 70;
    t_y1 = 15;

    cx = corner.x + squareSide / 2;
    cy = corner.y + squareSide / 2;

    // Initialize sx and sy (the scale factors)
    scaleX_romb1 = 1;
    scaleY_romb1 = 1;

    scaleX_hex1 = 1;
    scaleY_hex1 = 1;

    scaleX_hex2 = 1;
    scaleY_hex2 = 1;

    // Initialize angularStep
    angularStep = 0;

    Mesh* red_square = object2D::CreateSquare("red_square", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(red_square);

    Mesh* square1_scene = object2D::CreateSquare("square_scene", corner, squareSide, glm::vec3(0.85f, 0.43f, 0.57f), true);
    AddMeshToList(square1_scene);

    Mesh* square_empty4 = object2D::CreateSquare("square_empty", corner, squareSide, glm::vec3(0.43f, 0.25f, 0.25f));
    AddMeshToList(square_empty4);


    Mesh* life_square = object2D::CreateSquare("life_square", corner, squareSide, glm::vec3(1, 0, 0), true);
    AddMeshToList(life_square);

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -40, 1),  glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 0
            VertexFormat(glm::vec3(40, 0, 1),   glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 1
            VertexFormat(glm::vec3(-40, 0, 1),  glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 2
            VertexFormat(glm::vec3(0, 40, 1),   glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 3

            VertexFormat(glm::vec3(20, 10, 1),  glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 4
            VertexFormat(glm::vec3(20, -10, 1), glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 5
            VertexFormat(glm::vec3(80, 10, 1),  glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 6
            VertexFormat(glm::vec3(80, -10, 1), glm::vec3(0.85f, 0.85f, 0.1f), glm::vec3(0.2, 0.8, 0)), // 7
        };

        vector<unsigned int> indices =
        {
            0, 1, 2,
            1, 3, 2,
            5, 6, 4,
            5, 7, 6,
        };

        CreateMesh("romb1", vertices, indices);
    }


    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -40, 1),  glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 0
            VertexFormat(glm::vec3(40, 0, 1),   glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 1
            VertexFormat(glm::vec3(-40, 0, 1),  glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 2
            VertexFormat(glm::vec3(0, 40, 1),   glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 3
                                                         
            VertexFormat(glm::vec3(20, 10, 1),  glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 4
            VertexFormat(glm::vec3(20, -10, 1), glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 5
            VertexFormat(glm::vec3(80, 10, 1),  glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 6
            VertexFormat(glm::vec3(80, -10, 1), glm::vec3(0.19f, 0.6f, 0.8f), glm::vec3(0.2, 0.8, 0)), // 7
        };

        vector<unsigned int> indices =
        {
            0, 1, 2,
            1, 3, 2,
            5, 6, 4,
            5, 7, 6,
        };

        CreateMesh("romb2", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -40, 1),  glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 0
            VertexFormat(glm::vec3(40, 0, 1),   glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 1
            VertexFormat(glm::vec3(-40, 0, 1),  glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 2
            VertexFormat(glm::vec3(0, 40, 1),   glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 3
                                                          
            VertexFormat(glm::vec3(20, 10, 1),  glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 4
            VertexFormat(glm::vec3(20, -10, 1), glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 5
            VertexFormat(glm::vec3(80, 10, 1),  glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 6
            VertexFormat(glm::vec3(80, -10, 1), glm::vec3(0.13f, 0.55f, 0.13f), glm::vec3(0.2, 0.8, 0)), // 7
        };

        vector<unsigned int> indices =
        {
            0, 1, 2,
            1, 3, 2,
            5, 6, 4,
            5, 7, 6,
        };

        CreateMesh("romb3", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -40, 1),  glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 0
            VertexFormat(glm::vec3(40, 0, 1),   glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 1
            VertexFormat(glm::vec3(-40, 0, 1),  glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 2
            VertexFormat(glm::vec3(0, 40, 1),   glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 3
                                                          
            VertexFormat(glm::vec3(20, 10, 1),  glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 4
            VertexFormat(glm::vec3(20, -10, 1), glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 5
            VertexFormat(glm::vec3(80, 10, 1),  glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 6
            VertexFormat(glm::vec3(80, -10, 1), glm::vec3(0.53f, 0.12f, 0.47f), glm::vec3(0.2, 0.8, 0)), // 7

        };

        vector<unsigned int> indices =
        {
            0, 1, 2,
            1, 3, 2,
            5, 6, 4,
            5, 7, 6,
        };

        CreateMesh("romb4", vertices, indices);
    }


    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -80, 1),   glm::vec3(0.85f, 0.85f, 0.1f)), // 0
            VertexFormat(glm::vec3(80, -40, 1), glm::vec3(0.85f, 0.85f, 0.1f)), // 1
            VertexFormat(glm::vec3(80, 40, 1),glm::vec3(0.85f, 0.85f, 0.1f)), // 2
            VertexFormat(glm::vec3(0, 80, 1), glm::vec3(0.85f, 0.85f, 0.1f)), // 3
            VertexFormat(glm::vec3(-80, 40, 1),  glm::vec3(0.85f, 0.85f, 0.1f)), // 4
            VertexFormat(glm::vec3(-80, -40, 1),   glm::vec3(0.85f, 0.85f, 0.1f)), // 5
            VertexFormat(glm::vec3(0, 0, 1),  glm::vec3(0.85f, 0.85f, 0.1f)), // 6

            VertexFormat(glm::vec3(0, 0, 10),  glm::vec3(1, 0, 0)), // 7            
            VertexFormat(glm::vec3(0, -40 , 10),  glm::vec3(1, 0, 0)), // 8
            VertexFormat(glm::vec3(40, -20, 10), glm::vec3(1, 0, 0)), // 9
            VertexFormat(glm::vec3(40, 20, 10), glm::vec3(1, 0, 0)), // 10
            VertexFormat(glm::vec3(0, 40, 10), glm::vec3(1, 0, 0)), // 11
            VertexFormat(glm::vec3(-40, 20, 10),  glm::vec3(1, 0, 0)), // 12
            VertexFormat(glm::vec3(-40, -20, 10),  glm::vec3(1, 0, 0)), // 13



        };

        vector<unsigned int> indices =
        {
            0, 1, 6,
            1, 2, 6,
            2, 3, 6,
            3, 4, 6,
            4, 5, 6, 
            5, 0, 6,

            8, 9, 7,
            9, 10, 7,
            10, 11, 7,
            11, 12, 7,
            12, 13, 7,
            13, 8, 7,
        };

        CreateMesh("hexagon1", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -80, 1),   glm::vec3(0.19f, 0.6f, 0.8f)), // 0
            VertexFormat(glm::vec3(80, -40, 1),  glm::vec3(0.19f, 0.6f, 0.8f)), // 1
            VertexFormat(glm::vec3(80, 40, 1),   glm::vec3(0.19f, 0.6f, 0.8f)), // 2
            VertexFormat(glm::vec3(0, 80, 1),    glm::vec3(0.19f, 0.6f, 0.8f)), // 3
            VertexFormat(glm::vec3(-80, 40, 1),  glm::vec3(0.19f, 0.6f, 0.8f)), // 4
            VertexFormat(glm::vec3(-80, -40, 1), glm::vec3(0.19f, 0.6f, 0.8f)), // 5
            VertexFormat(glm::vec3(0, 0, 1),     glm::vec3(0.19f, 0.6f, 0.8f)), // 6

            VertexFormat(glm::vec3(0, 0, 10),    glm::vec3(1, 0, 0)), // 7            
            VertexFormat(glm::vec3(0, -40 , 10), glm::vec3(1, 0, 0)), // 8
            VertexFormat(glm::vec3(40, -20, 10), glm::vec3(1, 0, 0)), // 9
            VertexFormat(glm::vec3(40, 20, 10),  glm::vec3(1, 0, 0)), // 10
            VertexFormat(glm::vec3(0, 40, 10),   glm::vec3(1, 0, 0)), // 11
            VertexFormat(glm::vec3(-40, 20, 10), glm::vec3(1, 0, 0)), // 12
            VertexFormat(glm::vec3(-40, -20, 10),glm::vec3(1, 0, 0)), // 13



        };

        vector<unsigned int> indices =
        {
            0, 1, 6,
            1, 2, 6,
            2, 3, 6,
            3, 4, 6,
            4, 5, 6,
            5, 0, 6,

            8, 9, 7,
            9, 10, 7,
            10, 11, 7,
            11, 12, 7,
            12, 13, 7,
            13, 8, 7,
        };

        CreateMesh("hexagon2", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -80, 1),   glm::vec3(0.13f, 0.55f, 0.13f)), // 0
            VertexFormat(glm::vec3(80, -40, 1),  glm::vec3(0.13f, 0.55f, 0.13f)), // 1
            VertexFormat(glm::vec3(80, 40, 1),   glm::vec3(0.13f, 0.55f, 0.13f)), // 2
            VertexFormat(glm::vec3(0, 80, 1),    glm::vec3(0.13f, 0.55f, 0.13f)), // 3
            VertexFormat(glm::vec3(-80, 40, 1),  glm::vec3(0.13f, 0.55f, 0.13f)), // 4
            VertexFormat(glm::vec3(-80, -40, 1), glm::vec3(0.13f, 0.55f, 0.13f)), // 5
            VertexFormat(glm::vec3(0, 0, 1),     glm::vec3(0.13f, 0.55f, 0.13f)), // 6

            VertexFormat(glm::vec3(0, 0, 10),    glm::vec3(1, 0, 0)), // 7            
            VertexFormat(glm::vec3(0, -40 , 10), glm::vec3(1, 0, 0)), // 8
            VertexFormat(glm::vec3(40, -20, 10), glm::vec3(1, 0, 0)), // 9
            VertexFormat(glm::vec3(40, 20, 10),  glm::vec3(1, 0, 0)), // 10
            VertexFormat(glm::vec3(0, 40, 10),   glm::vec3(1, 0, 0)), // 11
            VertexFormat(glm::vec3(-40, 20, 10), glm::vec3(1, 0, 0)), // 12
            VertexFormat(glm::vec3(-40, -20, 10),glm::vec3(1, 0, 0)), // 13



        };

        vector<unsigned int> indices =
        {
            0, 1, 6,
            1, 2, 6,
            2, 3, 6,
            3, 4, 6,
            4, 5, 6,
            5, 0, 6,

            8, 9, 7,
            9, 10, 7,
            10, 11, 7,
            11, 12, 7,
            12, 13, 7,
            13, 8, 7,
        };

        CreateMesh("hexagon3", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0, -80, 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 0
            VertexFormat(glm::vec3(80, -40, 1),  glm::vec3(0.53f, 0.12f, 0.47f)), // 1
            VertexFormat(glm::vec3(80, 40, 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 2
            VertexFormat(glm::vec3(0, 80, 1),    glm::vec3(0.53f, 0.12f, 0.47f)), // 3
            VertexFormat(glm::vec3(-80, 40, 1),  glm::vec3(0.53f, 0.12f, 0.47f)), // 4
            VertexFormat(glm::vec3(-80, -40, 1), glm::vec3(0.53f, 0.12f, 0.47f)), // 5
            VertexFormat(glm::vec3(0, 0, 1),     glm::vec3(0.53f, 0.12f, 0.47f)), // 6

            VertexFormat(glm::vec3(0, 0, 10),    glm::vec3(1, 0, 0)), // 7            
            VertexFormat(glm::vec3(0, -40 , 10), glm::vec3(1, 0, 0)), // 8
            VertexFormat(glm::vec3(40, -20, 10), glm::vec3(1, 0, 0)), // 9
            VertexFormat(glm::vec3(40, 20, 10),  glm::vec3(1, 0, 0)), // 10
            VertexFormat(glm::vec3(0, 40, 10),   glm::vec3(1, 0, 0)), // 11
            VertexFormat(glm::vec3(-40, 20, 10), glm::vec3(1, 0, 0)), // 12
            VertexFormat(glm::vec3(-40, -20, 10),glm::vec3(1, 0, 0)), // 13



        };

        vector<unsigned int> indices =
        {
            0, 1, 6,
            1, 2, 6,
            2, 3, 6,
            3, 4, 6,
            4, 5, 6,
            5, 0, 6,

            8, 9, 7,
            9, 10, 7,
            10, 11, 7,
            11, 12, 7,
            12, 13, 7,
            13, 8, 7,
        };

        CreateMesh("hexagon4", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0   , -40    , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 0
            VertexFormat(glm::vec3(40   , -60   , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 1
            VertexFormat(glm::vec3(30   , -10    , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 2
            VertexFormat(glm::vec3(60   , 20    , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 3
            VertexFormat(glm::vec3(20   , 20    , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 4
            VertexFormat(glm::vec3(0   , 60    , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 5
            VertexFormat(glm::vec3(-20 , 20    , 1),   glm::vec3(0.53f, 0.12f, 0.47f)), // 6
            VertexFormat(glm::vec3(-60  , 20    , 10),  glm::vec3(0.53f, 0.12f, 0.47f)), // 7            
            VertexFormat(glm::vec3(-30  , -10    , 10),  glm::vec3(0.53f, 0.12f, 0.47f)), // 8
            VertexFormat(glm::vec3(-40  , -60   , 10),  glm::vec3(0.53f, 0.12f, 0.47f)), // 9

        };

        vector<unsigned int> indices =
        {
            1, 2, 0,
            4, 5, 6,
            0, 8, 9,
            0, 3, 7,
        };

        CreateMesh("steluta1", vertices, indices);
    }

    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(0   , -40    , 0),   glm::vec3(1, 0.5f, 1)), // 0
            VertexFormat(glm::vec3(40   , -60   , 0),   glm::vec3(1, 0.5f, 1)), // 1
            VertexFormat(glm::vec3(30   , -10    , 0),  glm::vec3(1, 0.5f, 1)), // 2
            VertexFormat(glm::vec3(60   , 20    , 0),   glm::vec3(1, 0.5f, 1)), // 3
            VertexFormat(glm::vec3(20   , 20    , 0),   glm::vec3(1, 0.5f, 1)), // 4
            VertexFormat(glm::vec3(0   , 60    , 0),    glm::vec3(1, 0.5f, 1)), // 5
            VertexFormat(glm::vec3(-20 , 20    , 0),    glm::vec3(1, 0.5f, 1)), // 6
            VertexFormat(glm::vec3(-60  , 20    , 10),  glm::vec3(1, 0.5f, 1)), // 7            
            VertexFormat(glm::vec3(-30  , -10    , 10), glm::vec3(1, 0.5f, 1)), // 8
            VertexFormat(glm::vec3(-40  , -60   , 10),  glm::vec3(1, 0.5f, 1)), // 9

        };

        vector<unsigned int> indices =
        {
            1, 2, 0,
            4, 5, 6,
            0, 8, 9,
            0, 3, 7,
        };

        CreateMesh("steluta_patrate", vertices, indices);
    }
}



void Tema1::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    // Create the VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO = 0;
    // Create the VBO and bind it
    //GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send vertices data into the VBO buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    unsigned int IBO = 0;
    // Create the IBO and bind it
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    // Send indices data into the IBO buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    // Set vertex position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    // Unbind the VAO
    glBindVertexArray(0);

    if (GetOpenGLError() == GL_INVALID_OPERATION)
    {
        cout << "\t[NOTE] : For students : DON'T PANIC! This error should go away when completing the tasks." << std::endl;
        cout << "\t[NOTE] : For developers : This happens because OpenGL core spec >=3.1 forbids null VAOs." << std::endl;
    }

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
}




void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

    // Enable face culling
    glEnable(GL_CULL_FACE);
    // Set face custom culling. Use the `cullFace` variable.
    glCullFace(cullFace);

    RenderEmptySquare();
    RenderSquare();
    RenderLifeSquare();
    RenderHexagon(deltaTimeSeconds);
    RenderProiectil(deltaTimeSeconds);
    RenderRomb();
    RenderResurse();
    RenderResurseNecesare();

    modelMatrix = glm::mat3(1);
    int translate_square = 5;
    modelMatrix *= transform2D::Translate(5, 15);
    modelMatrix *= transform2D::Scale(0.5f, 3.7f);
    RenderMesh2D(meshes["red_square"], shaders["VertexColor"], modelMatrix);


    glDisable(GL_CULL_FACE);
}


void Tema1::FrameEnd()
{
    DrawCoordinateSystem();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
        
    // Add mouse button press event
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}

void Tema1::RenderSquare()
{
    for (int i = 80; i < 361; i = i + 140)
    {
        for (int j = 15; j < 286; j = j + 135)
        {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(i, j);
            RenderMesh2D(meshes["square_scene"], shaders["VertexColor"], modelMatrix);
        }
    }
}

void Tema1::RenderEmptySquare()
{
    for (int i = 150; i < 601; i = i + 150)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(i, 600);
        RenderMesh2D(meshes["square_empty"], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::RenderLifeSquare()
{
    for (int i = 0; i < 281; i = i + 140)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(800 + i, 620);
        modelMatrix *= transform2D::Scale(0.8f, 0.8f);
        RenderMesh2D(meshes["life_square"], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::RenderRomb()
{
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(150, 600);
    modelMatrix *= transform2D::Scale(0.6f, 0.8f);
    modelMatrix *= transform2D::Translate(65, 65);
    scaleX_romb1 -= 0.005f;
    scaleY_romb1 -= 0.005f;
    if (scaleX_romb1 > 0 && scaleY_romb1 > 0)
    {
        modelMatrix *= transform2D::Scale(scaleX_romb1, scaleY_romb1);
        RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(120, 330);
    modelMatrix *= transform2D::Scale(0.6f, 0.8f);
    RenderMesh2D(meshes["romb1"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(300, 600);
    modelMatrix *= transform2D::Scale(0.6f, 0.8f);
    modelMatrix *= transform2D::Translate(65, 65);
    RenderMesh2D(meshes["romb2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(450, 600);
    modelMatrix *= transform2D::Scale(0.6f, 0.8f);
    modelMatrix *= transform2D::Translate(65, 65);
    RenderMesh2D(meshes["romb3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(600, 600);
    modelMatrix *= transform2D::Scale(0.6f, 0.8f);
    modelMatrix *= transform2D::Translate(65, 65);
    RenderMesh2D(meshes["romb4"], shaders["VertexColor"], modelMatrix);
}

void Tema1::RenderHexagon(float deltaTimeSeconds)
{
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1500, 20);
    translateX_hex -= deltaTimeSeconds * 100;
    modelMatrix *= transform2D::Translate(translateX_hex, 45);
    modelMatrix *= transform2D::Scale(0.5f, 0.5f);
    scaleX_hex1 -= 0.004f;
    scaleY_hex1 -= 0.004f;
    if (scaleX_hex1 > 0 && scaleY_hex1 > 0)
    {
        modelMatrix *= transform2D::Scale(scaleX_hex1, scaleY_hex1);
        RenderMesh2D(meshes["hexagon1"], shaders["VertexColor"], modelMatrix);
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1500, 20);
    translateX_hex_2 -= deltaTimeSeconds * 100;
    modelMatrix *= transform2D::Translate(translateX_hex_2 + 100, 45);
    modelMatrix *= transform2D::Scale(0.5f, 0.5f);
    if (1600 + translateX_hex_2 < 50)
    {
        if (scaleX_hex2 > 0 && scaleY_hex2 > 0)
        {
            scaleX_hex2 -= 0.025f;
            scaleY_hex2 -= 0.025f;
        }
    }
    modelMatrix *= transform2D::Scale(scaleX_hex2, scaleY_hex2);
    RenderMesh2D(meshes["hexagon2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1500, 20);
    translateX_hex_3 -= deltaTimeSeconds * 100;
    modelMatrix *= transform2D::Translate(translateX_hex_3 + 200, 45);
    modelMatrix *= transform2D::Scale(0.5f, 0.5f);
    RenderMesh2D(meshes["hexagon3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1500, 20);
    translateX_hex_4 -= deltaTimeSeconds * 100;
    modelMatrix *= transform2D::Translate(translateX_hex_4 + 300, 45);
    modelMatrix *= transform2D::Scale(0.5f, 0.5f);
    RenderMesh2D(meshes["hexagon4"], shaders["VertexColor"], modelMatrix);
}

void Tema1::RenderResurseNecesare()
{
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(170, 580);
    modelMatrix *= transform2D::Scale(0.25f, 0.25f);
    RenderMesh2D(meshes["steluta_patrate"], shaders["VertexColor"], modelMatrix);

    for (int i = 0; i < 31; i = i + 30)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(320 + i, 580);
        modelMatrix *= transform2D::Scale(0.25f, 0.25f);
        RenderMesh2D(meshes["steluta_patrate"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i < 31; i = i + 30)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(470 + i, 580);
        modelMatrix *= transform2D::Scale(0.25f, 0.25f);
        RenderMesh2D(meshes["steluta_patrate"], shaders["VertexColor"], modelMatrix);
    }

    for (int i = 0; i < 61; i = i + 30)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(620 + i, 580);
        modelMatrix *= transform2D::Scale(0.25f, 0.25f);
        RenderMesh2D(meshes["steluta_patrate"], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::RenderResurse()
{
    for (int i = 0; i < 61; i = i + 30)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(815 + i, 600);
        modelMatrix *= transform2D::Scale(0.25f, 0.25f);
        RenderMesh2D(meshes["steluta_patrate"], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::RenderProiectil(float deltaTimeSeconds)
{
    modelMatrix = glm::mat3(1);
    angularStep += deltaTimeSeconds;
    translateX_star += deltaTimeSeconds * 100;
    modelMatrix *= transform2D::Translate(translateX_star, 330);
    modelMatrix *= transform2D::Rotate(glm::radians(angularStep * 100));
    modelMatrix *= transform2D::Scale(0.5f, 0.5f);
    RenderMesh2D(meshes["steluta1"], shaders["VertexColor"], modelMatrix);
}