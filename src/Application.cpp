#include "Application.h"

#include "ChatPanel.h"

Application::Application(int _width, int _height, const char* _name){
    glfwInit();
    winHandle = glfwCreateWindow(1000, 1000, "fuck", NULL, NULL);
    glfwMakeContextCurrent(winHandle);
	glewInit();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(winHandle, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Application::run(){
	glClearColor(0.2, 0.2f, 0.3f, 1);

    ChatPanel P_chat;
    P_chat.addMsg(chatMSG("Fuck"));
    P_chat.addMsg(chatMSG("Fuckfaw"));
    P_chat.addMsg(chatMSG("Fuckwaf"));
    while (!glfwWindowShouldClose(winHandle)) {
		glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0,0});
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0,0});
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.2f, 0.2f, 0.2f, 0.8f));
		
        P_chat.render();

        ImGui::Begin("List");
		
		ImGui::End();

        ImGui::PopStyleColor();
        ImGui::PopStyleVar(2);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
		glfwSwapBuffers(winHandle);
		glfwPollEvents();
	}
}

Application::~Application(){}


