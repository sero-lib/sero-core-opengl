//
// Created by john on 3/15/20.
//

#include <core-opengl.h>
#include <iostream>

int main() {
    sero::core::opengl::Renderer renderer{};
    renderer.initialize(800, 600, "Renderer");
    auto window = renderer.create_window();

    if (!window.has_value()) {
        std::cout << "Failed to create window" << std::endl;
        return -1;
    }

    while (true) {
        glfwSwapBuffers(window.value());
        glfwPollEvents();
    }
}