#include <functional>
#include "core-opengl/core-opengl.h"

namespace sero::core::opengl {
    void Renderer::size_callback(GLFWwindow* window, int width, int height)
    {
        if (!Renderer::instance()->resize_callback) {
            Renderer::instance()->set_viewport(0, 0, width, height);
            return;
        }
        Renderer::instance()->resize_callback.value()(window, width, height);
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
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        set_viewport(0, 0, width, height);
        glfwSetFramebufferSizeCallback(window, size_callback);
    }

    bool Renderer::window_should_close() const noexcept {
        return glfwWindowShouldClose(window);
    }

    void Renderer::tick() noexcept {
        swap_buffers();
        poll_events();
        process_events();
    }

    void Renderer::poll_events() const noexcept {
        glfwPollEvents();
    }

    void Renderer::swap_buffers() noexcept {
        glfwSwapBuffers(window);
    }

    void Renderer::set_viewport(int x, int y, int _width, int _height) noexcept {
        glViewport(x, y, width, height);
    }

    void Renderer::process_events() noexcept {

    }
} // namespace sero