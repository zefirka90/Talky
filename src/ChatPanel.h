#include "glIncl.h"

struct chatMSG{
    chatMSG(const char* _text) : text(_text){};
    const char* text;
};

class MsgPanel{
public:
    MsgPanel() = default;
    static void render(chatMSG& _msg, int _id);
    ~MsgPanel() = default;
};

class ChatPanel{
public:
    ChatPanel();
    void render();
    void addMsg(chatMSG& _msg);
    ~ChatPanel();
private:
    std::vector<chatMSG> msgs;
};
