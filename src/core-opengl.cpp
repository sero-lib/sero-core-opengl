#include <functional>
#include "core-opengl.h"

namespace sero::core::opengl {
    void size_callback(GLFWwindow* window, int width, int height)
    {
        Renderer::instance()->framebuffer_size_callback(window, width, height);
        // make sure the viewport matches the new window dimensions; note that width and
        // height will be significantly larger than specified on retina displays.
        glViewport(0, 0, width, height);
    }

    std::optional<GLFWwindow *> Renderer::create_window() noexcept {
        if (!this->window) {
            return std::nullopt;
        }
        return window;
    }

    Renderer::~Renderer() noexcept {
        glfwTerminate();
    }

    void Renderer::initialize(int _width, int _height, std::string_view _name) noexcept {
        name = _name;
        width = _width;
        height = _height;
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        window = glfwCreateWindow(width, height, _name.begin(), nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, size_callback);
    }

    void Renderer::framebuffer_size_callback(GLFWwindow *, int _width, int _height) noexcept {
        width = _width;
        height = _height;
    }
} // namespace sero