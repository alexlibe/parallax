#include "window.hpp"
#include "settings.hpp"
#include "input.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

static void error_callback(int error, const char* description){
    std::cerr << "Error Code: " << error << ", Description: " << description << '\n';
}

// TODO: Set this into an input class
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << "Window: " << window << "\nScancode: " << scancode << "\nMods: " << mods << '\n';

    if(action == GLFW_PRESS){
        switch(key){
            case Input::Keycode::One:
                std::cout << "One\n";
                break;
            case Input::Keycode::Two:
                std::cout << "Two\n";
                break;
            case Input::Keycode::Three:
                std::cout << "Three\n";
                break;
            case Input::Keycode::Four:
                std::cout << "Four\n";
                break;
        }
    }
}

void Window::window_init(){
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()){
        throw std::runtime_error{ "GLFW failed to initialize" };    
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window_ = glfwCreateWindow(640, 480, settings::ENGINE_NAME, NULL, NULL);
    if(!window_){
        glfwTerminate();
        throw std::runtime_error("GLFW failed to create window");
    }

    glfwSetKeyCallback(window_, key_callback);
}

void Window::clean_up(){
    std::cout << "Cleaning GLFW...\n";

    glfwDestroyWindow(window_);
    glfwTerminate();
}
