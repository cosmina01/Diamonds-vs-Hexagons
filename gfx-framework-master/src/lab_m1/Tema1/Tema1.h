#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
     public:
        Tema1();
        ~Tema1();

        void Init() override;

     private:
        void CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);

        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX_hex, translateY_hex, translateY_star;
        float translateX_star = 120;
        float translateX_hex_2, translateX_hex_3, translateX_hex_4;
        float scaleX_romb1, scaleY_romb1;
        float scaleX_hex1, scaleY_hex1;
        float scaleX_hex2, scaleY_hex2;
        float angularStep;

        float t_x1, t_y1;


        GLenum cullFace;
        GLenum polygonMode;

        void Tema1::RenderSquare();
        void Tema1::RenderEmptySquare();
        void Tema1::RenderLifeSquare();
        void Tema1::RenderRomb();
        void Tema1::RenderHexagon(float deltaTimeSeconds);
        void Tema1::RenderResurseNecesare();
        void Tema1::RenderResurse();
        void Tema1::RenderProiectil(float deltaTimeSeconds);

        // TODO(student): If you need any other class variables, define them here.

    };
}   // namespace m1
