#ifndef SERO_CORE_OPENGL_CORE_OPENGL_H
#define SERO_CORE_OPENGL_CORE_OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <optional>
#include <mutex>
#include <functional>

namespace sero::core::opengl {

    class Renderer {
    private:
        GLFWwindow* window = nullptr;
        int width = 0;
        int height = 0;
        std::string name;
        std::optional<std::function<void(GLFWwindow*, int, int)>> resize_callback;

        Renderer() = default;

    public:
        static Renderer* instance() {
            static Renderer renderer{};
            return &renderer;
        }

        static void size_callback(GLFWwindow* window, int width, int height);
        ~Renderer() noexcept;
        [[nodiscard]] bool window_should_close() const noexcept;
        void initialize(int width, int height, std::string_view name) noexcept;
        [[nodiscard]] std::optional<GLFWwindow*> create_window() noexcept;
        void tick() noexcept;
        void set_viewport(int x, int y, int width, int height) noexcept;

        void process_events() noexcept;
        void poll_events() const noexcept;
        void swap_buffers() noexcept;

    };

} // namespace sero::core

#endif //SERO_CORE_OPENGL_CORE_OPENGL_H
