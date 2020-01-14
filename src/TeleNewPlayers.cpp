#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

class TeleNewPlayers : public PlayerScript
{
public:
	TeleNewPlayers() : PlayerScript("TeleNewPlayers") {}

	void OnLogin(Player *player) override
	{
		if (sConfigMgr->GetBoolDefault("TeleNewPlayers.Enable", false) && sConfigMgr->GetBoolDefault("TeleNewPlayers.Announce", false))
		{
			ChatHandler(player->GetSession()).SendSysMessage("El modulo |cff4CFF00TeleportNuevos |r ha sido activado.");
		}
	}

	void OnFirstLogin(Player *player) override
	{
		if (sConfigMgr->GetBoolDefault("TeleNewPlayers.Enable", false))
		{
			if (sConfigMgr->GetBoolDefault("TeleNewPlayers.EnableClean", false))
			{
				for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
					player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
				/*for (uint8 slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
					player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
				for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; slot++)
					player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
				for (uint8 slot = BANK_SLOT_ITEM_START; slot < BANK_SLOT_ITEM_END; slot++)
					player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
				for (uint8 slot = BANK_SLOT_BAG_START; slot < BANK_SLOT_BAG_END; slot++)
					player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
				for (uint8 slot = BUYBACK_SLOT_START; slot < BUYBACK_SLOT_END; slot++)
					player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
	
				player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 2586, true);
				player->EquipNewItem(EQUIPMENT_SLOT_FEET, 11508, true);
				player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 12064, true);*/
			}
			uint32 mapid = 0;
			float posx = 0;
			float posy = 0;
			float posz = 0;
			float orientation = 0;
			if (!(player->GetTeamId() == TEAM_HORDE))
			{
				mapid = sConfigMgr->GetIntDefault("TeleNewPlayers.Location.Alliance.MapID", 571);
				posx = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.PosX", 5813.83f);
				posy = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.PosY", 448.933f);
				posz = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.PosZ", 658.751f);
				orientation = sConfigMgr->GetFloatDefault("TeleNewPlayers.Location.Alliance.Orientation", 1.31092f);
			}
			else
			{
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

void AddTeleNewPlayersScripts()
{
	new TeleNewPlayers();
}
