/*
<--------------------------------------------------------------------------->
 - Developer(s): Ghostcrawler336, Styler
 - Complete: 100%
 - ScriptName: 'Title System'
 - Comment: Working %100
 <--------------------------------------------------------------------------->*/
#include "ScriptPCH.h"
 
 
enum eRanks
{
          /* Alliance */
        PRIVATE = 1,
        CORPORAL = 2,
        SERGEANT = 3,
        MASTER_SERGEANT = 4,
        SERGEANT_MAJOR = 5,
        KNIGHT = 6,
        KNIGHT_LIEUTENANT = 7,
        KNIGHT_CAPTAIN = 8,
        KNIGHT_CHAMPION = 9,
        LIEUTENANT_COMMANDER = 10,
        COMMANDER = 11,
        MARSHAL = 12,
        FIELD_MARSHAL = 13,
        GRAND_MARSHAL = 14,
        OF_THE_ALLIANCE = 126,
  /* Horde */
    SCOUT = 15,
        GRUNT = 16,
        SERGEANT_H = 17,
        SENIOR_SERGEANT = 18,
        FIRST_SERGEANT = 19,
        STONE_GUARD = 20,
        BLOOD_GUARD = 21,
        LEGIONNAIRE = 22,
        CENTURION = 23,
        CHAMPION = 24,
        LIEUTENANT_GENERAL = 25,
        GENERAL = 26,
        WARLORD = 27,
        HIGH_WARLORD = 28,
        OF_THE_HORDE = 127
};
 
enum eKills
{
        KILLS_1 = 100,
        KILLS_2 = 500,
        KILLS_3 = 1000,
        KILLS_4 = 2000,
        KILLS_5 = 4000,
        KILLS_6 = 5000,
        KILLS_7 = 6000,
        KILLS_8 = 8000,
        KILLS_9 = 10000,
        KILLS_10 = 15000,
        KILLS_11 = 25000,
        KILLS_12 = 40000,
        KILLS_13 = 45000,
        KILLS_14 = 50000,
        KILLS_15 = 75000
};
 
class TitleNpc : public CreatureScript
{
        public:
                TitleNpc() : CreatureScript("TitleNpc"){}
 
                uint32 GetTotalKill(Player* player)
                {
                        QueryResult result = CharacterDatabase.PQuery("SELECT totalKills FROM characters WHERE guid = %u", player->GetGUID());
                        if (result)
                        {
                            Field* field = result->Fetch();
                            if (field)
                                return field[0].GetUInt32();
                        }
                            return NULL;
                }
 
                bool OnGossipHello(Player* player, Creature* creature)
                {
                        player->PlayerTalkClass->ClearMenus();
                        player->ADD_GOSSIP_ITEM(10, "PVP Titles", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                        player->ADD_GOSSIP_ITEM(0, "Nevermind..", GOSSIP_SENDER_MAIN, 5000);
                        player->PlayerTalkClass->SendGossipMenu(8, creature->GetGUID());
                            return true;
                }
 
                bool OnGossipSelect(Player* Player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
                {
              switch (uiAction)
                        {
                        case GOSSIP_ACTION_INFO_DEF+1:
                                {
                                        if (Player->GetTeam() == ALLIANCE)
                                {
                                        Player->PlayerTalkClass->ClearMenus();
                                        Player->ADD_GOSSIP_ITEM(4, "Private", GOSSIP_SENDER_MAIN, PRIVATE);
                                        Player->ADD_GOSSIP_ITEM(4, "Corporal", GOSSIP_SENDER_MAIN, CORPORAL);
                                        Player->ADD_GOSSIP_ITEM(4, "Sergeant", GOSSIP_SENDER_MAIN, SERGEANT);
                                        Player->ADD_GOSSIP_ITEM(4, "Master Sergeant", GOSSIP_SENDER_MAIN, MASTER_SERGEANT);
                                        Player->ADD_GOSSIP_ITEM(4, "Sergeant Major", GOSSIP_SENDER_MAIN, SERGEANT_MAJOR);
                                        Player->ADD_GOSSIP_ITEM(4, "Knight", GOSSIP_SENDER_MAIN, KNIGHT);
                                        Player->ADD_GOSSIP_ITEM(4, "Knight Lieutenant", GOSSIP_SENDER_MAIN, KNIGHT_LIEUTENANT);
                                        Player->ADD_GOSSIP_ITEM(4, "Knight Captain", GOSSIP_SENDER_MAIN, KNIGHT_CAPTAIN);
                                        Player->ADD_GOSSIP_ITEM(4, "Knight Champion", GOSSIP_SENDER_MAIN, KNIGHT_CHAMPION);
                                        Player->ADD_GOSSIP_ITEM(4, "Lieutenant Commander", GOSSIP_SENDER_MAIN, LIEUTENANT_COMMANDER);
                                        Player->ADD_GOSSIP_ITEM(4, "Commander.", GOSSIP_SENDER_MAIN, COMMANDER);
                                        Player->ADD_GOSSIP_ITEM(4, "Marshal", GOSSIP_SENDER_MAIN, MARSHAL);
                                        Player->ADD_GOSSIP_ITEM(4, "Field Marshal", GOSSIP_SENDER_MAIN, FIELD_MARSHAL);
                                        Player->ADD_GOSSIP_ITEM(4, "Grand Marshal", GOSSIP_SENDER_MAIN, GRAND_MARSHAL);
                                        Player->ADD_GOSSIP_ITEM(0, "Nevermind..", GOSSIP_SENDER_MAIN, 1000);
                                        Player->PlayerTalkClass->SendGossipMenu(9, creature->GetGUID());
                                }
                        else
                        {
                                        Player->PlayerTalkClass->ClearMenus();
                                        Player->ADD_GOSSIP_ITEM(4, "Scout", GOSSIP_SENDER_MAIN, SCOUT);
                                        Player->ADD_GOSSIP_ITEM(4, "Grunt", GOSSIP_SENDER_MAIN, GRUNT);
                                        Player->ADD_GOSSIP_ITEM(4, "Sergeant", GOSSIP_SENDER_MAIN, SERGEANT_H);
                                        Player->ADD_GOSSIP_ITEM(4, "Senior Sergeant", GOSSIP_SENDER_MAIN, SENIOR_SERGEANT);
                                        Player->ADD_GOSSIP_ITEM(4, "First Sergeant", GOSSIP_SENDER_MAIN, FIRST_SERGEANT);
                                        Player->ADD_GOSSIP_ITEM(4, "Stone Guard", GOSSIP_SENDER_MAIN, STONE_GUARD);
                                        Player->ADD_GOSSIP_ITEM(4, "Blood Guard", GOSSIP_SENDER_MAIN, BLOOD_GUARD);
                                        Player->ADD_GOSSIP_ITEM(4, "Legionnaire", GOSSIP_SENDER_MAIN, LEGIONNAIRE);
                                        Player->ADD_GOSSIP_ITEM(4, "Centurion", GOSSIP_SENDER_MAIN,CENTURION);
                                        Player->ADD_GOSSIP_ITEM(4, "Champion", GOSSIP_SENDER_MAIN, CHAMPION);
                                        Player->ADD_GOSSIP_ITEM(4, "Lieutenant General", GOSSIP_SENDER_MAIN, LIEUTENANT_GENERAL);
                                        Player->ADD_GOSSIP_ITEM(4, "General", GOSSIP_SENDER_MAIN, GENERAL);
                                        Player->ADD_GOSSIP_ITEM(4, "Warlord", GOSSIP_SENDER_MAIN, WARLORD);
                                        Player->ADD_GOSSIP_ITEM(4, "High Warlord", GOSSIP_SENDER_MAIN, HIGH_WARLORD);
                                        Player->ADD_GOSSIP_ITEM(0, "Nevermind..", GOSSIP_SENDER_MAIN, 1000);
                                        Player->PlayerTalkClass->SendGossipMenu(9, creature->GetGUID());
                        }
                        Player->PlayerTalkClass->SendGossipMenu(9425, creature->GetGUID());
                        }break;
 
                                case PRIVATE:
                                        {
                                            if (GetTotalKill(Player) >= KILLS_1)
                                                Player->SetTitle(sCharTitlesStore.LookupEntry(1));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }break;
 
                                case CORPORAL:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_2)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(2));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case SERGEANT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_3)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(3));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case MASTER_SERGEANT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_4)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(4));
                                                else
                                                Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case SERGEANT_MAJOR:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_5)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(5));
                                                else
                                                  Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case KNIGHT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_6)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(6));
                                                else
                                                  Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case KNIGHT_LIEUTENANT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_7)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(7));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case KNIGHT_CAPTAIN:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_8)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(8));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case KNIGHT_CHAMPION:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_9)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(9));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case LIEUTENANT_COMMANDER:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_10)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(10));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case COMMANDER:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_11)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(11));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case MARSHAL:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_12)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(12));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case FIELD_MARSHAL:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_13)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(13));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case GRAND_MARSHAL:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_14)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(14));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case SCOUT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_1)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(15));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case GRUNT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_2)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(16));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case SERGEANT_H:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_3)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(17));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case SENIOR_SERGEANT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_4)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(18));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case FIRST_SERGEANT:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_5)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(19));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case STONE_GUARD:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_6)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(20));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case BLOOD_GUARD:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_7)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(21));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case LEGIONNAIRE:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_8)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(22));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case CENTURION:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_9)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(23));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case CHAMPION:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_10)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(24));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case LIEUTENANT_GENERAL:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_11)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(25));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case GENERAL:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_12)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(26));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case WARLORD:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_13)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(27));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                case HIGH_WARLORD:
                                        {
                                                if (GetTotalKill(Player) >= KILLS_14)
                                                        Player->SetTitle(sCharTitlesStore.LookupEntry(28));
                                                else
                                                        Player->GetSession()->SendNotification("You dont have enough kills");
                                        }
                                break;
                                Player->PlayerTalkClass->SendCloseGossip();
 
                                case 1000:
                                        Player->PlayerTalkClass->SendCloseGossip();
                        }
                            return true;
                }
};
 
void AddSC_TitleNpc()
{
        new TitleNpc();
}