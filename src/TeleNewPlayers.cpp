/**
    This plugin can be used for common player customizations
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class TeleNewPlayers : public PlayerScript{
public:

    TeleNewPlayers() : PlayerScript("TeleNewPlayers") { }

    void OnLogin(Player* player) override {
        if (sConfigMgr->GetBoolDefault("TeleNewPlayers.Enable", false) && sConfigMgr->GetBoolDefault("TeleNewPlayers.Announce", false)) {
            ChatHandler(player->GetSession()).SendSysMessage("# Modulo |cff4CFF00TeleNewPlayers |r habilitado:\n##### Teletransporta a los nuevos jugadores al lugar escogido.");
        }
    }
	
	void OnFirstLogin(Player* player) override {
        if (sConfigMgr->GetBoolDefault("TeleNewPlayers.Enable", false)) {
			uint32 mapid = 0;
			float posx = 0;
			float posy = 0;
			float posz = 0;
			float orientation = 0;
			if (!(player->GetTeamId() == TEAM_HORDE)){
				mapid = sConfigMgr->GetIntDefault("TeleNewPlayers.Location.Alliance.MapID", 571);
				posx = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.PosX", 5813.83f);
				posy = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.PosY", 448.933f);
				posz = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.PosZ", 658.751f);
				orientation = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.Orientation", 1.31092f);
			}else{
				mapid = sConfigMgr->GetIntDefault("TeleNewPlayers.Location.Horde.MapID", 571);
				posx = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Horde.PosX", 5813.83f);
				posy = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Horde.PosY", 448.933f);
				posz = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Horde.PosZ", 658.751f);
				orientation = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Horde.Orientation", 1.31092f);
			}
            player->TeleportTo(mapid, posx, posy, posz, orientation);
        }
    }
};

void AddTeleNewPlayersScripts() {
    new TeleNewPlayers();
}

