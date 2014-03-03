/*
Custom command: Startpaket für neue Spieler
Geschrieben von: Kaev
Für: Crazy
Bitte nicht entfernen.
*/
 
class aa_startpaket : public CommandScript
{
public:
    aa_startpaket() : CommandScript("aa_startpaket") { }
 
    ChatCommand* GetCommands() const OVERRIDE
    {
        static ChatCommand commandTable[] =
        {
            { "startpaket",           rbac::RBAC_PERM_COMMAND_GM_FLY,         false,  &HandleStartPaket,              "", NULL },
            { NULL,             0,                  false,  NULL,                            "", NULL }
        };
        return commandTable;
    }
 
    static bool HandleStartPaket(ChatHandler* handler, const char* /*args*/)
    {
	Player* player = handler->GetSession()->GetPlayer();
    	    if (!player)
            return false;
 
                Player* target = player->GetSelectedPlayer();
                if (!target)
                        return false;
 
                target->SetLevel(80);
                target->AddItem(41599, 2);
                target->AddItem(23162, 1);
                target->learnSpell(34091, false);
                target->learnSpell(54197, false);
                target->UpdateSkillsToMaxSkillsForLevel();
                target->SetMoney(target->GetMoney() + 10000);
 
        return true;
    }
};
 
void AddSC_aa_startpaket()
{
    new aa_startpaket();
}