DROP TABLE IF EXISTS `character_npcbot`;
CREATE TABLE `character_npcbot` (
  `owner` INT(10) DEFAULT NULL,
  `entry` INT(10) DEFAULT NULL,
  `race` TINYINT(3) DEFAULT NULL,
  `class` TINYINT(3) DEFAULT NULL,
  `roles` TINYINT(3) DEFAULT NULL,
  `equipMhEx` INT(10) DEFAULT NULL,
  `equipOhEx` INT(10) DEFAULT NULL,
  `equipRhEx` INT(10) DEFAULT NULL,
  `equipHead` INT(10) DEFAULT NULL,
  `equipShoulders` INT(10) DEFAULT NULL,
  `equipChest` INT(10) DEFAULT NULL,
  `equipWaist` INT(10) DEFAULT NULL,
  `equipLegs` INT(10) DEFAULT NULL,
  `equipFeet` INT(10) DEFAULT NULL,
  `equipWrist` INT(10) DEFAULT NULL,
  `equipHands` INT(10) DEFAULT NULL,
  `equipBack` INT(10) DEFAULT NULL,
  `equipBody` INT(10) DEFAULT NULL,
  `equipFinger1` INT(10) DEFAULT NULL,
  `equipFinger2` INT(10) DEFAULT NULL,
  `equipTrinket1` INT(10) DEFAULT NULL,
  `equipTrinket2` INT(10) DEFAULT NULL,
  `equipNeck` INT(10) DEFAULT NULL,
  `active` TINYINT(3) DEFAULT NULL,
 PRIMARY KEY  (`owner`,`entry`)
  ENGINE=INNODB DEFAULT CHARSET=utf8;
)