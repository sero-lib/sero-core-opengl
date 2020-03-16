#ifndef SERO_CORE_OPENGL_CORE_OPENGL_H
#define SERO_CORE_OPENGL_CORE_OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <optional>

namespace sero::core::opengl {

    class Renderer {
        GLFWwindow* window = nullptr;
        int width = 0;
        int height = 0;
        bool attempted_window_creation = false;
        std::string name;

    public:
        static Renderer* instance() {
            static Renderer renderer{};
            return &renderer;
        }

        Renderer() = default;
        ~Renderer() noexcept;
        void initialize(int width, int height, std::string_view name) noexcept;
        std::optional<GLFWwindow*> create_window() noexcept;

        void framebuffer_size_callback(GLFWwindow* window, int width, int height) noexcept;

    };

} // namespace sero::core

#endif //SERO_CORE_OPENGL_CORE_OPENGL_H
