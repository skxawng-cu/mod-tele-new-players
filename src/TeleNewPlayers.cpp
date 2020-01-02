/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class TeleNewPlayers : public PlayerScript{
public:

    TeleNewPlayers() : PlayerScript("MyPlayer") { }

    void OnLogin(Player* player) override {
        if (sConfigMgr->GetBoolDefault("MyCustom.enableHelloWorld", false)) {
            ChatHandler(player->GetSession()).SendSysMessage("Hello World from Skeleton-Module!");
        }
    }
};

void AddTeleNewPlayersScripts() {
    new TeleNewPlayers();
}

