#include "ChatPanel.h"

void MsgPanel::render(chatMSG& _msg, int _id){
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {5,5});
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.5f, 0.5f, 0.5f, 0.8f));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {5,5});

    ImGui::BeginChild(_id, {ImGui::GetContentRegionAvail().x, 50});
    ImGui::Text(_msg.text);
    ImGui::EndChild();

    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
}

ChatPanel::ChatPanel() {};

void ChatPanel::render(){
    ImGui::Begin("Chat", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
        ImVec2 sizez = ImGui::GetContentRegionAvail();

        ImGui::BeginChild("messages", {sizez.x, sizez.y - 100}, false, ImGuiWindowFlags_AlwaysUseWindowPadding);
            for(size_t i = 0; i < msgs.size(); ++i){
                MsgPanel::render(msgs[i], i);
            }
        ImGui::EndChild();
        
        ImGui::BeginChild("message_entering",{sizez.x, 100}, false,ImGuiWindowFlags_AlwaysUseWindowPadding);
            char txt[256];
	        ImGui::InputTextMultiline("",txt,256,ImGui::GetContentRegionAvail());
        ImGui::EndChild();
	ImGui::End();
}

void ChatPanel::addMsg(chatMSG& _msg){
    msgs.emplace_back(_msg);
}


ChatPanel::~ChatPanel() {};