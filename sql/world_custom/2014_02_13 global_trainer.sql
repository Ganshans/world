-- http://www.ac-web.org/forums/showthread.php?185058-Reshare-of-Global-Trainer

-- Reference class to add some missing spells you get from quest and some others.
SET @Deathknight :=90001;
SET @Druid :=90001; -- Adding missing spell you get from quest.
SET @Shaman :=90001; -- Adding missing spell you get from quest.
SET @Hunter :=90001; -- Adding missing spell you get from quest.
SET @Mage :=90001; -- Adding missing spell you get from quest.
SET @Warlock :=90001; -- Adding missing spell you get from quest.
SET @Warrior :=90001; -- Adding missing spell you get from quest.
SET @Skills :=90001;
SET @Trainer :=90001;
 
-- Clean Trainer before inserting new NPC,spells & skills.
DELETE FROM `creature` WHERE `id`=@Trainer;
DELETE FROM `creature_template` WHERE `entry`=@Trainer;
DELETE FROM `npc_trainer` WHERE `entry`=@Trainer;
 
-- Create Trainer NPC
INSERT INTO `creature_template` (`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction_A`,`faction_H`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`Health_mod`,`Mana_mod`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) VALUES
(@Trainer, 0, 0, 0, 0, 0, 22931, 0, 0, 0, 'Deckard Cain', 'Trainer Master', '', 0, 80, 80, 0, 35, 35, 51, 1, 1, 1, 0, 1755, 1755, 0, 1504, 1, 1500, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, '', 1);               
 

 

-- Missing spells you get from quest.
INSERT INTO `npc_trainer` (`entry`,`spell`,`spellcost`,`reqskill`,`reqskillvalue`,`reqlevel`) VALUES
(@Druid,5487,0,0,0,10), -- Bear Form
(@Druid,6807,0,0,0,10), --Zermalmen
(@Druid,6795,0,0,0,10), --Knurren
(@Shaman,8071,0,0,0,4), -- Stoneskin Totem Rank 1
(@Shaman,3599,0,0,0,10), -- Searing Totem Rank 1
(@Shaman,5394,0,0,0,20), -- Healing Stream Totem Rank 1
(@Hunter,883,0,0,0,10), -- Call Pet
(@Hunter,2641,0,0,0,10), -- Dismiss Pet
(@Hunter,6991,0,0,0,10), -- Feed Pet
(@Hunter,982,0,0,0,10), -- Revive Pet
(@Hunter,1515,0,0,0,10), -- Tame Beast
(@Mage,61305,0,0,0,60), -- Polymorph (Black Cat)
(@Mage,28272,0,0,0,60), -- Polymorph (Pig)
(@Mage,61721,0,0,0,60), -- Polymorph (Rabbit)
(@Mage,61780,0,0,0,60), -- Polymorph (Turkey)
(@Mage,28271,0,0,0,60), -- Polymorph (Turtle)
(@Mage,61316,0,0,0,80), -- Dalaran Brillance
(@Mage,61024,0,0,0,80), -- Dalaran Intellect
(@Warlock,697,0,0,0,10), -- Summon Voidwalker
(@Warlock,712,0,0,0,20), -- Summon Succubus
(@Warlock,691,0,0,0,30), -- Summon Felhunter
(@Warlock,1122,0,0,0,50), -- Inferno
(@Warlock,18540,0,0,0,60), -- Ritual of Doom
(@Warrior,71,0,0,0,10), -- Defensive Stance
(@Warrior,7386,0,0,0,10), -- Sunder Armor
(@Warrior,355,0,0,0,10), -- Taunt
(@Warrior,2458,0,0,0,30); -- Berserker Stance
 
 
-- Skills
INSERT INTO `npc_trainer` (`entry`,`spell`,`spellcost`,`reqskill`,`reqskillvalue`,`reqlevel`) VALUES
(@Skills,196,0,0,0,1), -- One-Handed Axes
(@Skills,197,0,0,0,1), -- Two-Handed Axes
(@Skills,198,0,0,0,1), -- One-Handed Maces
(@Skills,199,0,0,0,1), -- Two-Handed Maces
(@Skills,200,0,0,0,1), -- Polearms | Stangenwaffe
(@Skills,201,0,0,0,1), -- One-Handed Swords
(@Skills,202,0,0,0,1), -- Two-Handed Swords
(@Skills,227,0,0,0,1), -- Staves
(@Skills,264,0,0,0,1), -- Bows
(@Skills,266,0,0,0,1), -- Guns
(@Skills,1180,0,0,0,1), -- Daggers
(@Skills,2567,0,0,0,1), -- Throwns
(@Skills,5011,0,0,0,1), -- Crossbows
(@Skills,15590,0,0,0,1), -- Fists
(@Skills,8737,0,0,0,40), -- Mail Armor
(@Skills,750,0,0,0,40); -- Plate Armor