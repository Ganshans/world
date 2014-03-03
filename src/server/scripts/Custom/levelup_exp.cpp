#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Player.h"

class custom_CongratsOnLevel : public PlayerScript
{
public:
    custom_CongratsOnLevel() : PlayerScript("custom_CongratsOnLevel") { }

    void OnLevelChanged(Player* player, uint8 newLevel)
    {
        uint32 money, item, item2, spell;

        switch(++newLevel)
        {
            case 10: 
		money = 100; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 20: 
		money = 150; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 30: 
		money = 200; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 40: 
		money = 250; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 50: 
		money = 350; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 60: 
		money = 450; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 70: 
		money = 500; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            case 80: 
		money = 1000; 
		item = 34054;
		item2 = 34054;
		spell = 29175;
		break;
            default: 
		return;
        }


        player->ModifyMoney(money*GOLD);
	player->AddItem(item, 1);
        player->AddItem(item2, 1);
	Aura* aura = player->AddAura(spell, player);
	aura->SetDuration(1800 * IN_MILLISECONDS);
    }
};

void AddSC_custom_CongratsOnLevel()
{
    new custom_CongratsOnLevel();
}
