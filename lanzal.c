
//----------Landzaltier: At The Age's End------------//


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
int storytriggers[512];
int playerchoice;
int schedulerchoice;
int battleseed=0;
int itemseed=0;
int gainedrune=0;
int lostprofits=0;
int battleresults=0;
int winlose=1;
int inshop=0;
int maxparty=0;
int battleloops=0;
int floatSwap;
int monstersSlain=0;
char names[48][128];
int shopsopen=0;
int cookables;
int theChef;
int theMeal;
int deadNPCcount=0;
int bodycount=0;
int currentjob[2];
int mapmax=1;

struct intangibles
{
	char priority1Script[128];
	char priority2Script[128];
	char priority3Script[128];
	char priority4Script[128];
	};


struct intangibles Dialogue[1024];


struct tangibles
{int idnumber;
	int type;
		// 0 - Craft
	// 1 - Ingredient
	// 2 - Wpn 
	// 3 - shield 
	// 4 - accessory
	// 5 - flask
	// 6 - Material for Craft
	// 7 - consumable
	// 8 - water 
	// 9 - KEY ITEM
	// 10 - Gift
	
	int quantity;
	int purchasePrice;
	char name[20];
	int keyItem;
	int levelNeeded;
	float affRequired;
	char classRequired;
	int element;
	int offeredValue;
	int drainedValue;
	int drainedValue2;
	
	char description[512];
	char objectfile[22];
	};
struct tangibles items[1024];
struct tangibles recipes[256];
struct tangibles skills[256];
struct tangibles missions[256];


struct lesserEntities
{
char name[23];
int type;	
char description[512];
int vessel_id;
int level;
float Affs[24];	
int EXPoffered;
int runeOffered;
int droppedItem;
int HP;
int maxHP;
int attack;
int defense;
};
struct lesserEntities monsters[512];
	
struct Entity
{
char name[23];
int age;
char gender;
char race;
char description[512];
char job;
int vessel_id;
int level;
int fame;
int debt;
int deadline;
int debted;
int dead;
char class;
char status;
char avatarfile[20];
int hometown;
//subarea = town/world_areas//
int sub_area_location[3];
int weapon;
int shield;
int accessory;
int EXP;
int EXPneeded;
int EXPoffered;
int HP;
int maxHP;
int MP;
int maxMP;
int attack;
int defense;
int fatigue;
int maxfatigue;
float Affs[23];
int heldRune;
int wallet;
int rent;
int desiredOption;
char priorities[4];
int followUnitId;
int partynumber;
int inventory[512];
int SkillsUnlocked[256];
int RecipesUnlocked[256];
int checkitem[5];
};
struct Entity Vessels[1024];
struct Entity Shops[24];
	
float humanAffs[24]; 
float elfAffs[24]; 
float spiritAffs[24]; 
float demihumanAffs[24];
int rwloops;
float maleAffs[24];
float femaleAffs[24];

int printDialogue(int Character, int jobNumber, int npcPriority)
{
	//to-do
	//pass the character, the jobnumber/storynumber, 
	//for story quests/character dialogue
	//if npc is set to true then npcs evaluate the player and respond accordingly or random.
if (npcPriority==4)
	{
	printf("\n%s\n",Dialogue[Character].priority4Script);
}
if (npcPriority==3)
	{
	printf("\n%s\n",Dialogue[Character].priority3Script);
}
if (npcPriority==2)
	{
	printf("\n%s\n",Dialogue[Character].priority2Script);
}

if (npcPriority==1)
	{
	printf("\n%s\n",Dialogue[Character].priority1Script);
	}
	
	//for random encounter dialogues  
	return 0;
	}
	
	void initGuilds()
	{
		}
	
void initMonsters()
	{
int innerloop2;
		
 	for(innerloop2=0;innerloop2<=4;innerloop2++)
	{monsters[innerloop2].type=0;
monsters[innerloop2].runeOffered=1;monsters[innerloop2].EXPoffered=1;monsters[innerloop2].maxHP=1;
		monsters[innerloop2].HP=1;monsters[innerloop2].attack=1;
		monsters[innerloop2].defense=1;
		monsters[innerloop2].level=444;
strcpy(monsters[innerloop2].name, "RosterMonster/bugged");
strcpy(monsters[innerloop2].description, "Nil");
monsters[innerloop2].vessel_id=0;
monsters[innerloop2].droppedItem=0;
}
//daytime
monsters[5].type=0;monsters[5].runeOffered=5;monsters[5].droppedItem=59;monsters[5].EXPoffered=3;monsters[5].maxHP=10;
		monsters[5].HP=0;monsters[5].attack=7;monsters[5].level=2;
		monsters[5].defense=1;monsters[5].vessel_id=1;
strcpy(monsters[5].name, "Slime");
strcpy(monsters[5].description, "Slimey Boi...");

 
//daytime monster
monsters[6].type=0;monsters[6].runeOffered=50;monsters[6].droppedItem=59;monsters[6].EXPoffered=8;monsters[6].maxHP=15;
		monsters[6].HP=0;monsters[6].attack=10;monsters[6].level=3;
		monsters[6].defense=2;monsters[6].vessel_id=6;
strcpy(monsters[6].name, "King Martin");
strcpy(monsters[6].description, "A very territorial critter with Deadly Claws. Has no problem standing up to almost any other Monster.");
//see also 
//nighttime monster
monsters[7].type=0;monsters[7].runeOffered=80;monsters[7].droppedItem=59;monsters[7].EXPoffered=12;monsters[7].maxHP=40;
		monsters[7].HP=0;monsters[7].attack=12;monsters[7].level=5;
		monsters[7].defense=3;monsters[7].vessel_id=7;
strcpy(monsters[7].name, "Shalewolf");
strcpy(monsters[7].description, "A peculiarly vicious breed of small wolf found all along the eastern mountains.");
//nighttime
monsters[8].type=0;monsters[8].runeOffered=200;monsters[8].droppedItem=29;monsters[8].EXPoffered=75;monsters[8].maxHP=150;
		monsters[8].HP=0;monsters[8].attack=20;monsters[8].level=5;
		monsters[8].defense=10;monsters[8].vessel_id=8;
strcpy(monsters[8].name, "Mountain Troll");
strcpy(monsters[8].description, "A oddly reclusive Cave-Dwelling Troll that prefers to avoid Human Settlements.");
//daytime
monsters[9].type=0;monsters[9].runeOffered=200;monsters[9].droppedItem=29;monsters[9].EXPoffered=45;monsters[9].maxHP=100;
		monsters[9].HP=0;monsters[9].attack=10;monsters[9].level=4;
		monsters[9].defense=9;monsters[9].vessel_id=9;
strcpy(monsters[9].name, "Mountain Dweller");
strcpy(monsters[9].description, "Another oddly reclusive Cave-Dwelling Troll that prefers to avoid Human Settlements.");

	for(innerloop2=10;innerloop2<=511;innerloop2++)
	{monsters[innerloop2].type=0;monsters[innerloop2].runeOffered=5;monsters[innerloop2].droppedItem=59;monsters[innerloop2].EXPoffered=1;monsters[innerloop2].maxHP=10;
		monsters[innerloop2].HP=0;monsters[innerloop2].attack=7;monsters[innerloop2].level=222;
		monsters[innerloop2].defense=1;monsters[innerloop2].vessel_id=5;
		
strcpy(monsters[innerloop2].name, "Nil mons");
strcpy(monsters[innerloop2].description, "nil descript");
}

		}
void initMissions()
{
strcpy(missions[0].description,"Bugged Mission");

missions[0].idnumber=0;
	missions[0].type=0;
	missions[0].drainedValue=0;
	missions[0].drainedValue2=0;
	missions[0].levelNeeded=0;
	missions[0].affRequired=0;
	missions[0].offeredValue=0;
	missions[0].purchasePrice=0;
	missions[0].keyItem=0;
	missions[0].element=0;// mission status flag 0 null 1 inprogress/complete 2 - finished
	
	
strcpy(missions[2].description,"Who's The Lazy One!?");

missions[2].idnumber=2;
	missions[2].type=0;
	missions[2].drainedValue=59;//Gelatin
	missions[2].drainedValue2=60;//YellowOnion
	missions[2].levelNeeded=0;
	missions[2].affRequired=0.0;
	missions[2].offeredValue=33;//gives player a s. flask
	missions[2].purchasePrice=5;//gives player Rune
	missions[2].keyItem=2;// Gives Recipe or Skill.
	missions[2].element=0;// mission status flag 0 null 1 inprogress/complete 2 - finished
	
	
	
strcpy(missions[3].description,"Helping out the Community");

missions[3].idnumber=3;
	missions[3].type=0;
	missions[3].drainedValue=59;//Gelatin
	missions[3].drainedValue2=60;//YellowOnion
	missions[3].levelNeeded=0;
	missions[3].affRequired=0.0;
	missions[3].offeredValue=55;//gives player a s. flask
	missions[3].purchasePrice=5;//gives player Rune
	missions[3].keyItem=2;// Gives Recipe or Skill.
	missions[3].element=0;// mission status flag 0 null 1 inprogress/complete 2 - finished
	}

int resolveJob(int jobtype, int jobnumber)
{int jloops;
	printf("Mission: %s\n",missions[jobnumber].description);
	
	
	
	if(missions[jobnumber].element==1)
	{
	
	switch (jobtype)
	{//collection mission w 2 needed items
		case 0:
	
for (jloops=0;jloops<511;jloops++)
{
	if (Vessels[0].inventory[jloops]==missions[jobnumber].drainedValue)
	{
	Vessels[0].inventory[jloops]=missions[jobnumber].offeredValue;
jloops=511;
}}
	
for (jloops=0;jloops<511;jloops++)
{
if (Vessels[0].inventory[jloops]==missions[jobnumber].drainedValue2)
	{
	Vessels[0].inventory[jloops]=0;jloops=511;
}}


// mission payouts for select missions/triggering

if (jobnumber==2)
{storytriggers[0]=3;
	mapmax+=1;
	storytriggers[1]=1;	Vessels[missions[jobnumber].idnumber].priorities[3]=0;
	Vessels[0].priorities[0]=0;
	currentjob[1]=0;
	}
	
		
missions[jobnumber].element=2;
Vessels[0].wallet+=missions[jobnumber].purchasePrice;
Vessels[0].EXP+=missions[jobnumber].purchasePrice;
		break;

		default:
		break;
		}
	}
	
	
	
	if((missions[jobnumber].element!=1)&&(missions[jobnumber].element!=2))
	{printf("Mission Requirements not Fufilled");}
	
	return 0;
	
		}
void initDialogues()
{
	int settext=0;
	
		strcpy(Dialogue[settext].priority4Script,"Too bad I Can't");
		strcpy(Dialogue[settext].priority3Script,"Congratulations! to... me!?");
		strcpy(Dialogue[settext].priority2Script,"This Mission going wel... No Nevermind...");
		strcpy(Dialogue[settext].priority1Script,"I'm on a Mission. No time to dilly-dally!");
		
	settext=1;
		strcpy(Dialogue[settext].priority4Script,"You were looking for me? That Makes me Happy.");
		strcpy(Dialogue[settext].priority3Script,"HIHIHIHI!!!");
		strcpy(Dialogue[settext].priority2Script,"Congratulating!!!");
		strcpy(Dialogue[settext].priority1Script,"Mission Debriefing!!!");
		
		settext=2;
		strcpy(Dialogue[settext].priority4Script,"Joining you!!!");
		strcpy(Dialogue[settext].priority3Script,"Hi.");
		strcpy(Dialogue[settext].priority2Script,"Thanks. Looks like your not completely good for Nothing. Hahahaha...");
		strcpy(Dialogue[settext].priority1Script,"Hey Lazy. you collected the Ingredients for Tonight's Dinner yet? I need One more Onion and One more Gelatin.");
		
		settext=3;
		strcpy(Dialogue[settext].priority4Script,"Joining you!!!");
		strcpy(Dialogue[settext].priority3Script,"Hi.");
		strcpy(Dialogue[settext].priority1Script,"Look These Woods might just have a few Wolves that stray to close to The Village.");
		strcpy(Dialogue[settext].priority2Script,"Hey Rookie. You Aren't going into the Woods without a Weapon are you?.");
		
		
		
		
	for (settext=4;settext<=1023;settext++)
	{
		strcpy(Dialogue[settext].priority4Script,"Joining you!!!");
		strcpy(Dialogue[settext].priority3Script,"Hi.");
		strcpy(Dialogue[settext].priority2Script,"Thanks. Looks like your not completely good for Nothing. Hahahaha...");
		strcpy(Dialogue[settext].priority1Script,"Hey Lazy. you collected the Ingredients for Tonight's Dinner yet? I need One more Onion and One more Gelatin.");
		}
	}

int missionConditions(int jobtype, int jobnumber)
{	
	if(jobnumber!=0)
	{int onefortwo=0;
	int twofortwo=0;
	// print mission struct//
	printf("Mission : %s \n", missions[jobnumber].description);

	printf("Mission Type : %d \nMission Number : %d\n", jobtype, jobnumber);

	switch (jobtype)
	{
		case 0:
		printf("COLLECTION MISSION\n");
		printf("Client : %s\n",Vessels[missions[jobnumber].idnumber].name);
		printf("Item Required : %s \n",items[missions[jobnumber].drainedValue].name);
	printf("Item Required : %s \n",items[missions[jobnumber].drainedValue2].name);

int jloops;
for (jloops=0;jloops<511;jloops++)
{
	if ((Vessels[0].inventory[jloops]==missions[jobnumber].drainedValue))
	{printf("Found Quest item 1 : %s in inventory[%d]\n",items[missions[jobnumber].drainedValue].name,jloops);
	onefortwo=1;jloops=511;
}
}
for (jloops=0;jloops<511;jloops++)
{

	if (Vessels[0].inventory[jloops]==missions[jobnumber].drainedValue2)
	{printf("Found Quest item 2 : %s in inventory[%d]\n",items[missions[jobnumber].drainedValue2].name,jloops);
	twofortwo=1;jloops=511;
}
}
if ((onefortwo==1)&&(twofortwo==1))
{missions[jobnumber].element=1;Vessels[missions[jobnumber].idnumber].priorities[3]=2;
 }

	
else if ((twofortwo==0)||(onefortwo==0))
{missions[jobnumber].element=0;
	//set NPC priority back to waiting for player?//
	}

break;
		
		default:
		break;
		}
	
	//check conditions 
	
	//Trigger storytriggers
	
	//never return anything;
}
printf("Mission Status : %d \n in Progress - 0  Complete - 1 \n", missions[jobnumber].element);
	

	return 0;
	}
//init skills and recipes
void initSkills(){
	int sloops;
	for (sloops=0;sloops<=511;sloops++)
	{
		storytriggers[sloops]=0;
		}
	storytriggers[0]=1;
	
	//elements -0 NULL
//	1- fire
//	2- water
//  3 - wind
//	4 - earth
//	5 - electricity
// 6- light
// 7- sound
// 8 - darkness

strcpy(skills[0].name,"Nullify Existence");

	skills[0].type=8;
	skills[0].drainedValue=1;
	skills[0].affRequired=5.0;
	skills[0].offeredValue=99999;
	skills[0].element=7;
	
strcpy(skills[1].name,"Bandage");

	skills[1].type=7;
	skills[1].drainedValue=10;
	skills[1].affRequired=0.0;
	skills[1].offeredValue=20;
	
	
strcpy(skills[2].name,"Ignite");

	skills[2].type=8;
	skills[2].drainedValue=20;
	skills[2].levelNeeded=4;
	skills[2].affRequired=0.45;
	skills[2].offeredValue=205;
	skills[2].element=1;

strcpy(skills[3].name,"Rush");

	skills[3].type=2;
	skills[3].drainedValue=10;
	skills[3].affRequired=0.00;
	skills[3].offeredValue=8;
	skills[3].element=0;
	
strcpy(skills[4].name,"Double Slash");

	skills[4].type=2;
	skills[4].drainedValue=15;
	skills[4].affRequired=0.15;
	skills[4].offeredValue=15;
	skills[4].element=0;
	
strcpy(skills[5].name,"Douse");

	skills[5].type=8;
	skills[5].drainedValue=10;
	
	skills[5].levelNeeded=2;
	skills[5].affRequired=0.45;
	skills[5].offeredValue=12;
	skills[5].element=2;
	
strcpy(skills[6].name,"Gust");

	skills[6].type=8;
	skills[6].drainedValue=5;
	skills[6].levelNeeded=1;
	skills[6].affRequired=0.45;
	skills[6].offeredValue=6;
	skills[6].element=3;
	//skills[6].quantity=73;
	
strcpy(skills[7].name,"Entrench");

	skills[7].type=8;
	skills[7].drainedValue=15;
	skills[7].levelNeeded=3;
	skills[7].affRequired=0.45;
	skills[7].offeredValue=15;
	skills[7].element=4;
	
strcpy(skills[8].name,"Spark");

	skills[8].type=8;
	skills[8].drainedValue=15;
	skills[8].levelNeeded=3;
	skills[8].affRequired=0.85;
	skills[8].offeredValue=28;
	skills[8].element=5;
	
strcpy(skills[9].name,"Glow");

	skills[9].type=8;
	skills[9].drainedValue=10;
	skills[9].affRequired=0.5;
	skills[9].offeredValue=0;
	skills[9].element=6;
	
strcpy(skills[10].name,"Binaural");

	skills[10].type=8;
	skills[10].drainedValue=10;
	skills[10].affRequired=0.5;
	skills[10].offeredValue=0;
	skills[10].element=8;
	
strcpy(skills[11].name,"Anti-Candle");

	skills[11].type=8;
	skills[11].drainedValue=15;
	skills[11].affRequired=0.5;
	skills[11].offeredValue=0;
	skills[11].element=9;
	
	
strcpy(skills[12].name,"Clearshot");

	skills[12].type=0;
	skills[12].drainedValue=5;
	skills[12].affRequired=0.5;
	skills[12].offeredValue=7;
	skills[12].element=0;
	
	
	
	
	
for (rwloops=13;rwloops<=255;rwloops++)
{strcpy(skills[rwloops].name,"Rush");

	skills[rwloops].type=2;
	skills[rwloops].drainedValue=6;
	
	skills[rwloops].offeredValue=8;
}



 
strcpy(recipes[0].name,"Nothing");
recipes[0].idnumber=0;
	recipes[0].type=7;
	recipes[0].drainedValue2=0;
	recipes[0].drainedValue=0;
	recipes[0].offeredValue=0;
	recipes[0].quantity=0;
recipes[0].affRequired=0.0;

strcpy(recipes[1].name,"Apple Juice");
recipes[1].idnumber=22;
	recipes[1].type=7;
	recipes[1].drainedValue2=100;
	recipes[1].drainedValue=23;
	recipes[1].offeredValue=22;
	recipes[1].quantity=1;

strcpy(recipes[2].name,"Bread");
recipes[2].idnumber=22;
	recipes[2].type=7;
	recipes[2].drainedValue2=100;//water
	recipes[2].drainedValue=61;//fleur
	recipes[2].offeredValue=65;
	recipes[2].quantity=1;

strcpy(recipes[3].name,"Oak Pike");
recipes[3].idnumber=22;
	recipes[3].type=2;
	recipes[3].drainedValue2=62;//animal tooth?
	recipes[3].drainedValue=1;//oak branch
	recipes[3].affRequired=0.35;
	recipes[3].offeredValue=66;
	recipes[3].quantity=1;

strcpy(recipes[4].name,"Maple Guards");
recipes[4].idnumber=22;
	recipes[4].type=4;
	recipes[4].drainedValue2=2;//maple branch
	recipes[4].drainedValue=68;//cordage
	recipes[4].offeredValue=28;//maple Gurads
	recipes[4].quantity=1;


strcpy(recipes[5].name,"Bone Knife");
recipes[5].idnumber=29;
	recipes[5].type=2;
	recipes[5].drainedValue2=5;//small bone
	recipes[5].affRequired=0.5;
	recipes[5].levelNeeded=1;
	recipes[5].drainedValue=1;//oak branch
	recipes[5].offeredValue=29;//bone knife
	recipes[5].quantity=1;

strcpy(recipes[6].name,"Battle Gloves");
recipes[6].idnumber=29;
	recipes[6].type=2;
	recipes[6].drainedValue2=63;//small animal fur
	recipes[6].drainedValue=68;//cordage
	recipes[6].offeredValue=29;//
	recipes[6].quantity=1;


strcpy(recipes[7].name,"Oak Staff");
recipes[7].idnumber=70;
	recipes[7].type=2;
	recipes[7].drainedValue2=70;//common mana stone
	recipes[7].drainedValue=1;//Oak branch
	recipes[7].offeredValue=54;//Oak Staff
	recipes[7].quantity=1;


strcpy(recipes[8].name,"Practice Sword");
recipes[8].idnumber=72;
	recipes[8].type=2;
	recipes[8].drainedValue2=68;//
	recipes[8].drainedValue=1;//
	recipes[8].offeredValue=72;//
	recipes[8].quantity=1;

strcpy(recipes[9].name,"Practice Bow");
recipes[9].idnumber=57;
	recipes[9].type=2;
	recipes[9].drainedValue2=2;
	recipes[9].drainedValue=68;
	recipes[9].offeredValue=57;
	recipes[9].quantity=1;


strcpy(recipes[10].name,"Pelt Scarf");
recipes[10].idnumber=76;
	recipes[10].type=4;
	recipes[10].drainedValue2=63;
	recipes[10].drainedValue=68;
	recipes[10].offeredValue=76;
	recipes[10].quantity=1;



for (rwloops=11;rwloops<=255;rwloops++)
{strcpy(recipes[rwloops].name,"Nil Recipe");
recipes[rwloops].idnumber=256;
	recipes[rwloops].type=0;
	recipes[rwloops].drainedValue2=0;//maple branch
	recipes[rwloops].drainedValue=0;//cordage
	recipes[rwloops].offeredValue=0;//maple Gurads
	recipes[rwloops].quantity=0;
}


}
int seedEnemies(int playersLocation)//enemyseeder
{int enemy=0;
int chanceEnemy=0;
chanceEnemy=rand()%2;
if (chanceEnemy!=0)
{chanceEnemy=1;}
	switch(playersLocation)
{
	case 0:
	enemy=5;
	
	break;
	
	case 1:
	enemy=5;
	enemy+=chanceEnemy;
	break;

case 2:
	enemy=6;
	enemy-=chanceEnemy;
	break;
	
	
case 4:
	enemy=6;
	enemy+=chanceEnemy;
	break;
	
	case 5:
	enemy=8;
	break;

default:
break;
}

//check location and seeds enemyroster[0,1,2,3,4] as per enemymaxparty	
	
	return enemy;
	}
int battle()//battle func triggered by scheduler recieving 1
{
	
system("clear");
system("reset");

	
	itemseed=0;
	int enemymaxparty=0;
	int bonusdamage=0;
	gainedrune=0;
	int enemyRoster[5];enemymaxparty=rand()%5;
	
for (battleloops=0;battleloops<=4;battleloops++)
{	monsters[battleloops].HP=0;}

for (battleloops=0;battleloops<=enemymaxparty;battleloops++)
{
enemyRoster[battleloops]=seedEnemies(Vessels[0].sub_area_location[2]);
printf("%d",enemyRoster[battleloops]);
//ALL monsters[battleloops].stats = monsters[enemyroster[battleloops]].stats

monsters[battleloops].EXPoffered=monsters[enemyRoster[battleloops]].EXPoffered;
monsters[battleloops].defense=monsters[enemyRoster[battleloops]].defense;
monsters[battleloops].attack=monsters[enemyRoster[battleloops]].attack;
	monsters[battleloops].maxHP=monsters[enemyRoster[battleloops]].maxHP;
	monsters[battleloops].HP=monsters[enemyRoster[battleloops]].maxHP;	
	monsters[battleloops].type=monsters[enemyRoster[battleloops]].type;
	monsters[battleloops].runeOffered=monsters[enemyRoster[battleloops]].runeOffered;	
	monsters[battleloops].droppedItem=monsters[enemyRoster[battleloops]].droppedItem;
	gainedrune+=rand()%monsters[battleloops].runeOffered;
	}	
	
	monstersSlain=enemymaxparty;
	
	lostprofits=0;
	int escapeflag=0;
	int action=0;
int turncount=0;
int enemystarget=0;
int loopflag=0;
int checkdamage=0;
int checkreflect=0;
int battleSelect[7];
	//gen number of and fight monsters party turn based//
	//Rewrite as switchcase?//
	do{
	printf("\n IN BATTLE\n");enemystarget=rand()%((maxparty)+1);
		//printf("%s\t vs \t%s\n",Vessels[0].name,monsters[0].name);
	printf("\n1 - fight 2 - Flee 3- Defend 4- Skill/Magic\n");
	
	for (battleloops=0;battleloops<=maxparty;battleloops++)
	{
		printf("%s\tHP: %d of %d \t\n",Vessels[battleloops].name,Vessels[battleloops].HP,Vessels[battleloops].maxHP);
		printf("\tFatigue: %d of %d \t\n",Vessels[battleloops].fatigue,Vessels[battleloops].maxfatigue);
if (Vessels[battleloops].MP<0)
{Vessels[battleloops].MP=0;}
if (Vessels[battleloops].HP<0)
{Vessels[battleloops].HP=0;}

		printf("\tMP: %d of %d \t\n",Vessels[battleloops].MP,Vessels[battleloops].maxMP);

	}
	for (battleloops=0;battleloops<=enemymaxparty;battleloops++)
	{if (monsters[battleloops].HP<0)
		{monsters[battleloops].HP=0;
	
	}
		printf("%s\t HP: %d of %d \t\n",monsters[enemyRoster[battleloops]].name,monsters[battleloops].HP,monsters[battleloops].maxHP);
	}
	scanf("%d",&action);
				
	
	if (action==1)
	{
		battleSelect[0]=maxparty+1;
		do{printf("\nWho will Attack?\n");
		scanf("%d",&battleSelect[0]);}while(battleSelect[0]>maxparty||((Vessels[battleSelect[0]].HP<=0)||(Vessels[battleSelect[0]].fatigue>Vessels[battleSelect[0]].maxfatigue)));
	
	battleSelect[1]=enemymaxparty+1;
	do{printf("\nAttack which Enemy?\n");
		scanf("%d",&battleSelect[1]);}while(battleSelect[1]>enemymaxparty);
			
		printf("\n Turn : %d %s Attacked %s\n",turncount,Vessels[battleSelect[0]].name,monsters[enemyRoster[battleSelect[1]]].name);
		monsters[battleSelect[1]].HP-=((Vessels[battleSelect[0]].attack+Vessels[battleSelect[0]].weapon)-(monsters[battleSelect[1]].defense));
				Vessels[battleSelect[0]].fatigue+=10;
				Vessels[battleSelect[0]].Affs[10]+=0.0001;
				action=9;
		}
				
			
			
		
	 if (action==3)
	{
		printf("\n Turn %d: Party is Defending\n",turncount);		
			
		
			for (battleloops=0;battleloops<=enemymaxparty;battleloops++)
			{
			
				
				if (monsters[battleloops].HP>0)
				{
				
				if (monsters[battleloops].HP>0){checkdamage=1;enemystarget=rand()%(maxparty+1);
			checkdamage+=1+(checkdamage+monsters[battleloops].attack);
				checkdamage-=1+(checkdamage-Vessels[enemystarget].defense);
			checkdamage-=1-(Vessels[enemystarget].shield);}	
			printf("CHECKDAMAGE: %d\n",checkdamage);
			//Vessels[enemystarget].defense+Vessels[enemystarget].shield);
			if ((checkdamage<0)&&(checkreflect!=1))
			{checkdamage=0;printf("CHECKDAMAGE TRIGGERED");
			
			}
			
			else if((checkdamage>=2)&&(checkreflect!=1))
			{
	printf("\nvalid damage: %d,",monsters[battleloops].attack-(Vessels[enemystarget].defense+Vessels[enemystarget].shield));
Vessels[enemystarget].HP-=(monsters[battleloops].attack-(Vessels[enemystarget].defense+Vessels[enemystarget].shield));
	Vessels[enemystarget].fatigue+=10;checkdamage=0;
			}
			
			 if ((checkdamage==1)&&(checkreflect!=1))
			{
			Vessels[enemystarget].HP-=checkdamage;
			Vessels[enemystarget].fatigue+=10;
	checkdamage=0;
			}	
			else if(checkreflect==1)
				{		printf("\n Turn : %d %s Took Damage\n",turncount,Vessels[enemystarget].name);
		//Write more Depth to this case and only return damage part of the time based on level// 
		Vessels[enemystarget].HP-=(monsters[battleloops].attack-(Vessels[enemystarget].defense+Vessels[enemystarget].shield)); 
					Vessels[enemystarget].fatigue+=10;
					}
					
	}	}
	turncount+=1;
	action-=3;
	for(battleloops=0;battleloops<=maxparty;battleloops++)
	{	
		//double check this//
	printf("\n Turn : %d Party Recovered: %d HP\n",turncount,Vessels[battleloops].level);
Vessels[battleloops].HP+=Vessels[battleloops].level;
		
		if(Vessels[battleloops].HP>Vessels[battleloops].maxHP)
		{Vessels[battleloops].HP=Vessels[battleloops].maxHP;
			}
		}
	}
	
	
			
	 if (action==4)
	{
			
	printf("SKILLS & MAGIC\n");
	
	
		do{printf("\nWho will USE? : ");
		scanf("%d",&battleSelect[0]);}while(battleSelect[0]>maxparty||((Vessels[battleSelect[0]].HP<=0)||(Vessels[battleSelect[0]].fatigue>Vessels[battleSelect[0]].maxfatigue)));
	
	
	
	for (battleloops=0;battleloops<=255;battleloops++)
	{
		if (Vessels[battleSelect[0]].SkillsUnlocked[battleloops]!=0)
		{printf("\n%d %s element: %d MP Cost: %d",battleloops,skills[battleloops].name,skills[battleloops].element,skills[battleloops].drainedValue);
			}
		
		}do{printf("\nWhich Skill or Spell? : ");
		
			scanf("%d",&battleSelect[1]);}while((Vessels[battleSelect[0]].SkillsUnlocked[battleSelect[1]]!=1)&&(Vessels[battleSelect[0]].MP>skills[battleSelect[1]].drainedValue));
	
		printf("%s",skills[battleSelect[1]].name);
		switch (skills[battleSelect[1]].type)
		{	
	if (skills[battleSelect[1]].levelNeeded>Vessels[battleSelect[0]].level)
	{printf("\nLevel Requirements not Met!\n");action=0;loopflag=1;break; 
		}
			case 2: 
		
	do{printf("\nAttack which Enemy?\n");
		scanf("%d",&battleSelect[2]);}while(battleSelect[2]>enemymaxparty);
		
			
	if (skills[battleSelect[1]].drainedValue>Vessels[battleSelect[0]].MP)
	{action=0;printf("\nNot Enough MP left!\n");loopflag=1;break; 
		}
	
			if(monsters[battleSelect[2]].type!=skills[battleSelect[1]].type){bonusdamage+=2;}
			
			monsters[battleSelect[2]].HP-=(skills[battleSelect[1]].offeredValue+bonusdamage);	
			
				Vessels[battleSelect[0]].MP-=skills[battleSelect[1]].drainedValue;
	Vessels[battleSelect[0]].fatigue+=25;
			bonusdamage=0;
			break;
			
			case 8: 
			
	// elemental magic is usually aoe destructive all enemies are attacked but not all enemies are weak/damaged by elements.
	// some magic can pin point targets directly at massive  cost for the control. type 9 skills.//
	do{printf("\nAttack which Enemy?\n");
		scanf("%d",&battleSelect[2]);}while(battleSelect[2]>enemymaxparty);
		
					
	if (skills[battleSelect[1]].drainedValue>Vessels[battleSelect[0]].MP)
	{action=0;printf("\nNot Enough MP left!\n");loopflag=1;break; 
		}
			
			monsters[battleSelect[2]].HP-=skills[battleSelect[1]].offeredValue;	
				Vessels[battleSelect[0]].MP-=skills[battleSelect[1]].drainedValue;
	
			break;
			
			
			case 7: 
			
	
	do{printf("\nHeal Which Ally?\n");
		scanf("%d",&battleSelect[2]);}while(battleSelect[2]>maxparty);
				
	if (skills[battleSelect[1]].drainedValue>Vessels[battleSelect[0]].MP)
	{action=0;
		printf("\nNot Enough MP left!\n");
		loopflag=1;
		break; 
		}
	
			Vessels[battleSelect[2]].HP+=skills[battleSelect[1]].offeredValue;	
				Vessels[battleSelect[0]].MP-=skills[battleSelect[1]].drainedValue;
			if (Vessels[battleSelect[2]].HP>Vessels[battleSelect[2]].maxHP)
			{Vessels[battleSelect[2]].HP=Vessels[battleSelect[2]].maxHP;}
			break;
			default:
			break;
			
		}	
	
	if (loopflag==1)
	{loopflag=0;printf("LOOPFLAG TRIGGERED");
		battleloops=0;
		action=0;}
		action=9;
	}
	
	if (action==9)
	{
		printf("Enemies Turn\n");
		
			
				for (battleloops=0;battleloops<=enemymaxparty;battleloops++)
	{
			if(monsters[battleloops].HP<1)
	{monsters[battleloops].HP=0;checkdamage=0;}
			
			if(monsters[battleloops].HP>=1)
		{enemystarget=rand()%(maxparty+1);
		printf("\nenemystarget: %d",enemystarget);
			{
				if (monsters[battleloops].HP>0){
				printf("\n Turn : %d %s Took Damage from Enemy[%d]",turncount,Vessels[enemystarget].name,battleloops);
				checkdamage=0;
				checkdamage+=monsters[battleloops].attack;
				checkdamage-=Vessels[enemystarget].defense;}
				
			if ((checkdamage<1)&&(checkreflect!=1))
			{checkdamage=1;
			printf("\nCHECKDAMAGE TRIGGERED %d",checkdamage);Vessels[enemystarget].fatigue+=10;
			Vessels[enemystarget].HP-=checkdamage;}
				
			
				else if(checkreflect==1)
				{printf("\nCHECK REFLECT TRIGGERED");
				Vessels[enemystarget].HP-=(monsters[battleloops].attack-Vessels[enemystarget].defense);		}
			
	if ((checkdamage>1)&&(checkreflect!=1))
			{
			printf("\nvalid damage: %d",checkdamage);
			Vessels[enemystarget].HP-=checkdamage;
			Vessels[enemystarget].fatigue+=10;checkdamage=1;}
}
	}
	}			
		
				turncount+=1;action=0;
		}
		
	else if (action==2)
	{escapeflag=2;}
		if (monsters[0].HP<1&&monsters[1].HP<1&&monsters[2].HP<1&&monsters[3].HP<1&&monsters[4].HP<1)
		{battleloops=0;checkdamage=1;escapeflag=3;}
			
		
else if (Vessels[0].HP<1||Vessels[0].fatigue>=Vessels[0].maxfatigue)
		{escapeflag=1;}
			
	
	
			
	else if ((action!=1)||(action!=2)||(action!=3)||(action!=0)||(action!=4)||(action!=9))
	{action=0;}
	
	}while (escapeflag==0);
		
	 
	
	if (escapeflag==1)
	{battleseed=1;}
	
	
	
	else if (escapeflag==2)
	{battleseed=4;}
	
	else if (escapeflag==3)
	{battleseed=3;}
	return battleseed;
	}

int initOptions3(){

printf("\nOptions for Scheduler : 1 - Adventure, 2- Freewalk 3 - shop\n 4- Search Entities 5 - Use Item\n6 - Crafting 7- Smithing 8- Cooking\n9 - Increment/Decrement Map\n");
	printf("10 - Gift, 11 - M. Debriefing\n");
	playerchoice=0;
	schedulerchoice=0;
	scanf("%d",&playerchoice);
	schedulerchoice+=playerchoice;
		return schedulerchoice;
}


int initOptions2(){

printf("\nOptions for Scheduler : 0 - Rest, 2- Freewalk : ");
	playerchoice=0;
	schedulerchoice=0;
	scanf("%d",&playerchoice);

	schedulerchoice+=playerchoice;
	
	

		return schedulerchoice;
}

void initShops(){
	
for (shopsopen=0;shopsopen<=23;shopsopen++)
	{
		for (int stockcount=0;stockcount<511;stockcount++)
		{Shops[shopsopen].inventory[stockcount]=0;}
}
	
	printf("Init Shops : \twallet\t\tbank\t\tclass\tfame\n");
	
	shopsopen=0;
	strcpy(Shops[shopsopen].name,"Shaleside Market ");
		Shops[shopsopen].sub_area_location[0]=0;
		Shops[shopsopen].sub_area_location[1]=1;
		Shops[shopsopen].sub_area_location[2]=1;
		Shops[shopsopen].wallet=250;Shops[shopsopen].heldRune=2200;Shops[shopsopen].fame=25;Shops[shopsopen].class='g';
		printf("%s : %d\t%d\t%c\t%d\n",Shops[shopsopen].name,Shops[shopsopen].wallet,Shops[shopsopen].heldRune,Shops[shopsopen].class,Shops[shopsopen].fame);
	Shops[shopsopen].inventory[0]=22;
	Shops[shopsopen].inventory[1]=25;
	Shops[shopsopen].inventory[2]=37;
	Shops[shopsopen].inventory[3]=38;
	Shops[shopsopen].inventory[4]=74;
	Shops[shopsopen].inventory[5]=59;
	Shops[shopsopen].inventory[6]=60;
	Shops[shopsopen].inventory[7]=29;
	shopsopen+=1;

	
	strcpy(Shops[shopsopen].name,"Fragaria General ");
		Shops[shopsopen].class='g';Shops[shopsopen].wallet=500;Shops[shopsopen].heldRune=3500;Shops[shopsopen].fame=80;Shops[shopsopen].class='g';
		printf("%s : %d\t%d\t%c\t%d\n",Shops[shopsopen].name,Shops[shopsopen].wallet,Shops[shopsopen].heldRune,Shops[shopsopen].class,Shops[shopsopen].fame);
	shopsopen+=1;
	Shops[shopsopen].sub_area_location[0]=2;
		Shops[shopsopen].sub_area_location[1]=0;
		Shops[shopsopen].sub_area_location[2]=0;
//
//Meet KEY-NPC Arms Collector Beast Girl
//
	strcpy(Shops[shopsopen].name,"Flowering Battler ");
		Shops[shopsopen].class='b';Shops[shopsopen].wallet=800;Shops[shopsopen].heldRune=3500;Shops[shopsopen].fame=80;
		printf("%s : %d\t%d\t%c\t%d\n",Shops[shopsopen].name,Shops[shopsopen].wallet,Shops[shopsopen].heldRune,Shops[shopsopen].class,Shops[shopsopen].fame);
	shopsopen+=1;
	Shops[shopsopen].sub_area_location[0]=3;
		Shops[shopsopen].sub_area_location[1]=0;
		Shops[shopsopen].sub_area_location[2]=0;
//

//23rd shop is Special
//An Entity can get access by being offered a Membership//
//KEY-NPC Shady Business Loli.
shopsopen=23;
strcpy(Shops[shopsopen].name,"Under-World Market : ???");
		Shops[shopsopen].wallet=9999999;Shops[shopsopen].heldRune=0;Shops[shopsopen].class='g';
printf("%s : %d\t%d\t%c\t%d\n",Shops[shopsopen].name,Shops[shopsopen].wallet,Shops[shopsopen].heldRune,Shops[shopsopen].class,Shops[shopsopen].fame);

	Shops[shopsopen].sub_area_location[0]=99;
		Shops[shopsopen].sub_area_location[1]=0;
		Shops[shopsopen].sub_area_location[2]=0;
	system("clear");
	system("reset");
	}

int initOptions(){

printf("\nOptions for Scheduler : 0 - Rest, 1 - Adventure 2-Freewalk 3 - Shop \n 4- Search Entities 5 - Use Item\n6 - Crafting 7- Smithing 8- Cooking\n9 - Increment/Decrement Map\n");
printf("10 - Gift, 11 - M. Debriefing\n");
	playerchoice=0;
	schedulerchoice=0;
	scanf("%d",&playerchoice);
	schedulerchoice+=playerchoice;

		
		
		return schedulerchoice;
}

void initItemsAndNames()
{
int genitems=0;
	
	


items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Nothing/Bugged Item");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=5;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].quantity=0;
		items[genitems].classRequired='n';
		items[genitems].offeredValue=0;
	items[genitems].drainedValue=0;		
genitems+=1;		
//1
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Oak Branch");
strcpy(items[genitems].description,"A Solid Oak Branch. Could be used for Crafting or Firewood.");
		items[genitems].purchasePrice=1;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].quantity=1;
		items[genitems].classRequired='n';
		items[genitems].offeredValue=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
//2

items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Maple Branch");
		items[genitems].purchasePrice=2;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;	

//3
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Cherry Branch");
		items[genitems].purchasePrice=5;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		

//4

items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Walnut Branch");
		items[genitems].purchasePrice=20;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
		
//5

items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Small Bone");
		items[genitems].purchasePrice=15;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		

//6//
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Large Bone");
		items[genitems].purchasePrice=150;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
//7

items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Dragon Bone");
		items[genitems].purchasePrice=500;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
		
		//8
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Abominable Bone");
		items[genitems].purchasePrice=750;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
			//9					
		
items[genitems].type=6;
	items[genitems].idnumber=9;
		strcpy(items[genitems].name,"Malachite");
		items[genitems].purchasePrice=30;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.5;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
								
	//10				
		
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Ferric Earth");
		items[genitems].purchasePrice=15;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.75;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
				
	//11
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Bog Silver");
		strcpy(items[genitems].description,"Relatively Pure Silver Strands. Found in a Swampy Bogs by Fortunate Adventurers. Also found by UN-fortunate Adventurers.");
		items[genitems].purchasePrice=1500;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
				
//12
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Argentite");
		items[genitems].purchasePrice=750;
		items[genitems].levelNeeded=25;
		items[genitems].affRequired=0.65;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
				
//13
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Veiny Quartz");
		items[genitems].purchasePrice=350;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
			
			//14
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Mithril Crystal");
		items[genitems].purchasePrice=750;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;	

		//15	
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Gold Nugget");
		items[genitems].purchasePrice=1550;
		items[genitems].levelNeeded=50;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;		
	//16
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Iron Bar");
		items[genitems].purchasePrice=250;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;					
		
		//17
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Steel Bar");
		items[genitems].purchasePrice=350;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;					
		
		//18
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Copper Ingot");
		items[genitems].purchasePrice=200;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;					
		
		
		//19
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Silver Bar");
		items[genitems].purchasePrice=1250;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;					
		
		
	
	//20//	
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Gold Finger");
		items[genitems].purchasePrice=7000;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=0;
	items[genitems].drainedValue=0;		
genitems+=1;	
//21
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Mithril Shard");
		items[genitems].purchasePrice=2500;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;					
		
		//22	
items[genitems].type=13;
	items[genitems].idnumber=22;
		strcpy(items[genitems].name,"Apple Juice");
		strcpy(items[genitems].description,"Plain ol' Apple Juice...");
		items[genitems].purchasePrice=75;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=30;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
		
		//23
items[genitems].type=7;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Apple");
		strcpy(items[genitems].description,"A little bit Tart. Perfect for Pies!");
		items[genitems].purchasePrice=8;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=10;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
		
		//24	
items[genitems].type=12;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Pear");
		strcpy(items[genitems].description,"Quite Bitter... Or is it Acrid?");
		items[genitems].purchasePrice=12;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=10;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
		//25	
items[genitems].type=13;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Pear Juice");
		strcpy(items[genitems].description,"A Rich, Refreshing Beverage... Best Served Sweetened and Chilled.");
		items[genitems].purchasePrice=95;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=12;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
		
				//26//
items[genitems].type=9;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Priscilla's Necklace");
		strcpy(items[genitems].description,"A memento of Orva's Mother. Priscilla.");
		items[genitems].purchasePrice=30000;
		items[genitems].levelNeeded=100;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=1;
		items[genitems].element=0;
		items[genitems].offeredValue=500;
		items[genitems].classRequired='m';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
		
		//27
items[genitems].type=2;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Maple Pike");
		strcpy(items[genitems].description,"A Crude Stabbing Weapon crafted from a Maple Branch");
		items[genitems].purchasePrice=100;
		items[genitems].levelNeeded=1;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='t';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//28
items[genitems].type=3;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Maple Guards");
		strcpy(items[genitems].description,"Wooden Arm & Leg Guards. Made by Noobs, for Noobs...");
		items[genitems].purchasePrice=150;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
		
		//29
items[genitems].type=2;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Bone Knife");
		strcpy(items[genitems].description,"A Small Knife Fashioned from Animal Bone. Can do more Damage than you think!");
		items[genitems].purchasePrice=400;
		items[genitems].levelNeeded=2;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=5;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;


		//30
items[genitems].type=4;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Copper Bracelet ");
		strcpy(items[genitems].description,"A Mana Catalyzing Accessory. Equipable by Mages Only.");
		items[genitems].purchasePrice=550;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='m';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//31//
items[genitems].type=14;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Coffee");
		strcpy(items[genitems].description,"Imported at High Cost from the Easteren Provinces. This Odd Nut, when roasted, makes a most Delectable Beverage that Reduces Fatigue.Please Note that Short-Term Over-Consumption may present Health Risks.");
		items[genitems].purchasePrice=1200;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=300;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//32
items[genitems].type=13;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Hot Cocoa");
		strcpy(items[genitems].description,"An absolute hit with the Party on cold Winter Nights.");
		items[genitems].purchasePrice=700;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=200;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//33
items[genitems].type=5;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Small Flask");
		strcpy(items[genitems].description,"A Small Container for Holding Water.");
		items[genitems].purchasePrice=200;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
items[genitems].type=5;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Medium Flask");
		strcpy(items[genitems].description,"Hold up to 4 portions of Water.");
		items[genitems].purchasePrice=1000;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=4;
		items[genitems].classRequired='n';
		items[genitems].quantity=4;
	items[genitems].drainedValue=0;		
genitems+=1;
//35
items[genitems].type=5;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Water Orb");
		strcpy(items[genitems].description,"Holds 10 portions of Water.");
		items[genitems].purchasePrice=3500;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=10;
		items[genitems].classRequired='n';
		items[genitems].quantity=10;
	items[genitems].drainedValue=0;		
genitems+=1;
//36//
items[genitems].type=5;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Vessel of Streams");
		strcpy(items[genitems].description,"Hold 15 Water.");
		items[genitems].purchasePrice=7000;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=1;
		items[genitems].element=0;
		items[genitems].offeredValue=15;
		items[genitems].classRequired='n';
		items[genitems].quantity=15;
	items[genitems].drainedValue=0;		
genitems+=1;
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Kindling Bundle");
		strcpy(items[genitems].description,"Used with Flint to light a Fire at a Fire Pit.");
		items[genitems].purchasePrice=10;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//38
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Flint");
		strcpy(items[genitems].description,"Used with Kindling to light a Fire.");
		items[genitems].purchasePrice=10;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
items[genitems].type=7;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Strawberrys");
		strcpy(items[genitems].description,"Found all around Fragaria. Loved all around The Provinces.");
		items[genitems].purchasePrice=250;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=25;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//40
items[genitems].type=14;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Pigeon Grapes");
		strcpy(items[genitems].description,"These Small Purple Grapes grow Everywhere. I mean EVERYWHERE!!!");
		items[genitems].purchasePrice=100;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=25;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//41
items[genitems].type=12;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Watermelon");
		strcpy(items[genitems].description,"King of the Picnic. Spitting out the Seeds is half the Fun!");
		items[genitems].purchasePrice=400;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=30;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//42
items[genitems].type=13;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Raspberry");
		strcpy(items[genitems].description,"The fruit which bore the Name of the Provincial Capital. Sadly it is now seldom found in the Rubus Plains.");
		items[genitems].purchasePrice=800;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=50;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;


//43// 
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Mint");
		strcpy(items[genitems].description,"A Highly-Prized herb for its aromatic and flavors.");
		items[genitems].purchasePrice=1000;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//44 
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Cocoa");
		strcpy(items[genitems].description,"Common-Place in Baking. My Personal Preference.");
		items[genitems].purchasePrice=1000;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//45
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Vanilla");
		strcpy(items[genitems].description,"This is REAL Extract. Common-Place in Baking.");
		items[genitems].purchasePrice=1000;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//46
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Wheat");
		strcpy(items[genitems].description,"Luscious Grains of Wheat ready for Milling.");
		items[genitems].purchasePrice=25;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//47
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Barley");
		strcpy(items[genitems].description,"Fine Barley");
		items[genitems].purchasePrice=75;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//48

items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Beef Cut");
		strcpy(items[genitems].description,"Meat.Meat.Meat.Meat. Meat is the Best!");
		items[genitems].purchasePrice=525;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//49

items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Bird Meat");
		strcpy(items[genitems].description,"Some people Roast it. Some people Fry it.");
		items[genitems].purchasePrice=45;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//50
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Salmon");
		strcpy(items[genitems].description,"This Fresh-Water Variety makes a Nice, Personal Sized Dish.");
		items[genitems].purchasePrice=90;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;

//51
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Scrap Iron");
		strcpy(items[genitems].description,"Commercial/Industrial Waste. Good Crafters/Smiths know to RECYCLE!");
		items[genitems].purchasePrice=40;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=2.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//52
items[genitems].type=6;
	items[genitems].idnumber=0;
		strcpy(items[genitems].name,"Scrap Steel");
		strcpy(items[genitems].description,"Commercial/Industrial Waste. Perfectly Good Steel, but Re-Purposing it requires Expertise.");
		items[genitems].purchasePrice=90;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=0;		
genitems+=1;
//53
items[genitems].type=10;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Wooden Arrow");
		strcpy(items[genitems].description,"Lacking an Arrowhead and Fashioned from imperfect sources of Wood. These Arrows do little for Extra Damage.");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='a';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//54
items[genitems].type=2;
	items[genitems].idnumber=55;
		strcpy(items[genitems].name,"Oak Staff");
		strcpy(items[genitems].description,"Old Oak's still got some Mana left in 'em!");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.00;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='m';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//55//
items[genitems].type=2;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Iron Knife");
		strcpy(items[genitems].description,"High-Maintenance and Weak Performance. ");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=2;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=3;
		items[genitems].classRequired='b';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;


//56
items[genitems].type=2;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Practice Bow");
		strcpy(items[genitems].description,"All the Cool Kiddies have one. Don't aim it at me!!!");
		items[genitems].purchasePrice=135;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='a';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//57//
items[genitems].type=2;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Maple Shortbow");
		strcpy(items[genitems].description,"Go Hunt me some Dinner!");
		items[genitems].purchasePrice=400;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.55;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=5;
		items[genitems].classRequired='a';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//58
items[genitems].type=3;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Walnut Guards");
		strcpy(items[genitems].description,"Good Impact and Pierce Resitance, but their a little bit heavy.");
		items[genitems].purchasePrice=550;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.35;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=4;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//59
items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Gelatin");
		strcpy(items[genitems].description,"Commonly used as a Cooking Ingredient.");
		items[genitems].purchasePrice=10;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.15;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//60//
items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Yellow Onion");
		strcpy(items[genitems].description,"Sweetens up nice when Cooked. Nothing special about these Onions...");
		items[genitems].purchasePrice=10;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.15;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//61
items[genitems].type=6;
	items[genitems].idnumber=10;
		strcpy(items[genitems].name,"Flour");
		strcpy(items[genitems].description,"Commonly used in Baking. Needs just a Pinch of Salt.");
		items[genitems].purchasePrice=35;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//62
items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Large Animal Tooth");
		strcpy(items[genitems].description,"Commonly used for Tools or Weapons.");
		items[genitems].purchasePrice=25;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//63
items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Small Animal Fur");
		strcpy(items[genitems].description,"Commonly used for Armor or Accessories.");
		items[genitems].purchasePrice=55;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//64
items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"Large Animal Fur");
		strcpy(items[genitems].description,"Sells for a Nice Price.");
		items[genitems].purchasePrice=255;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=1.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//65
items[genitems].type=7;
	items[genitems].idnumber=2;
		strcpy(items[genitems].name,"Plain Bread");
		strcpy(items[genitems].description,"Bland... it's Bland... So Bland... ...");
		items[genitems].purchasePrice=20;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=25;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//66
items[genitems].type=2;
	items[genitems].idnumber=66;
		strcpy(items[genitems].name,"Oak Pike");
		strcpy(items[genitems].description,"A basic Weapon.");
		items[genitems].purchasePrice=50;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//67
items[genitems].type=14;
	items[genitems].idnumber=67;
		strcpy(items[genitems].name,"Tobacco");
		strcpy(items[genitems].description,"The Absolute Best, (along with Drinks), after a Good Meal. ");
		items[genitems].purchasePrice=500;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=3.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=500;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//68
items[genitems].type=6;
	items[genitems].idnumber=68;
		strcpy(items[genitems].name,"Cordage");
		strcpy(items[genitems].description,"Cotton rope with little thickness.");
		items[genitems].purchasePrice=75;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//69

items[genitems].type=2;
	items[genitems].idnumber=69;
		strcpy(items[genitems].name,"Battle Gloves");
		strcpy(items[genitems].description,"They make for Poor Oven Mitts...");
		items[genitems].purchasePrice=250;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=2;
		items[genitems].classRequired='d';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;

//70
items[genitems].type=6;
	items[genitems].idnumber=70;
		strcpy(items[genitems].name,"Common Mana-Stone");
		strcpy(items[genitems].description,"A form of Mana-Source found in a very weak Crystalline State-of-Matter. \n Sometimes Explodes if Dropped before Refinement.");
		items[genitems].purchasePrice=50;
		items[genitems].levelNeeded=10;
		items[genitems].affRequired=1.55;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//71
items[genitems].type=6;
	items[genitems].idnumber=71;
		strcpy(items[genitems].name,"Charcoal");
		strcpy(items[genitems].description,"Leftovers of Partially-Burned Organics. Has Immense Industrial Utility.");
		items[genitems].purchasePrice=1;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.05;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=0;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//72
items[genitems].type=2;
	items[genitems].idnumber=72;
		strcpy(items[genitems].name,"Practice Sword");
		strcpy(items[genitems].description,"Better get Practicing!");
		items[genitems].purchasePrice=10;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='b';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//73//
items[genitems].type=15;
	items[genitems].idnumber=73;
		strcpy(items[genitems].name,"Book of Fervent Winds");
		strcpy(items[genitems].description,"Those who Comprehend will be One day become \nA gentle, Graceful Spirit with Regard.\n  Basic Wind Magic Tome.\n Teaches Attack Magic 'Gust' Usually the first Spell for many aspiring Magi.");
		items[genitems].purchasePrice=150;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.15;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=6;
		items[genitems].classRequired='m';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//74
items[genitems].type=15;
	items[genitems].idnumber=74;
		strcpy(items[genitems].name,"Book of Still Waters");
		strcpy(items[genitems].description,"Those who Comprehend will keep their Minds\n Calm under Pressure. Basic Water Magic Tome.\n Teaches Attack Magic 'Douse'.");
		items[genitems].purchasePrice=350;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.15;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=5;
		items[genitems].classRequired='m';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
genitems+=1;
//75
items[genitems].type=9;
	items[genitems].idnumber=75;
		strcpy(items[genitems].name,"Wooden Guild Crest");
		strcpy(items[genitems].description,"Permits Guild-Leaders to recruit a New Entry.");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.5;//manageaff;
		items[genitems].keyItem=1;
		items[genitems].element=0;
		items[genitems].offeredValue=5;//Recruit character 5
		items[genitems].classRequired='m';
		items[genitems].quantity=0;
	items[genitems].drainedValue=0;		
genitems+=1;
//76
items[genitems].type=4;
	items[genitems].idnumber=76;
		strcpy(items[genitems].name,"Pelt Scarf");
		strcpy(items[genitems].description,"So Comfy. So Fluffy. but... it kinda Stinks...");
		items[genitems].purchasePrice=80;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.0;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=0;
	items[genitems].drainedValue=0;		
genitems+=1;


/////
//100
//////
genitems=100;
items[genitems].type=8;
	items[genitems].idnumber=100;
		strcpy(items[genitems].name,"Water");
		strcpy(items[genitems].description,"Gathered from a Viable Source, Life cannot exist without it... ");
		items[genitems].purchasePrice=100;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.25;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
items[genitems].drainedValue=1;		
	
genitems=101;
items[genitems].type=9;
	items[genitems].idnumber=101;
		strcpy(items[genitems].name,"Player's Necklace");
		strcpy(items[genitems].description,"A Gift given to you by Orva for your Birthday... You seem to cherish this Deeply...");
		items[genitems].purchasePrice=30;
		items[genitems].levelNeeded=90;
		items[genitems].affRequired=4.00;
		items[genitems].keyItem=1;
		items[genitems].element=0;
		items[genitems].offeredValue=100;
		items[genitems].classRequired='n';
		items[genitems].quantity=1;
items[genitems].drainedValue=1;		
	
	
	
		for (genitems=77;genitems<=99;genitems++)
	{

items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"unnamed items");
		strcpy(items[genitems].description,"nil descript");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.65;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='a';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		
		}
		
		
		for (genitems=102;genitems<=1023;genitems++)
	{

items[genitems].type=6;
	items[genitems].idnumber=1;
		strcpy(items[genitems].name,"unnamed items");
		strcpy(items[genitems].description,"nil descript");
		items[genitems].purchasePrice=0;
		items[genitems].levelNeeded=0;
		items[genitems].affRequired=0.65;
		items[genitems].keyItem=0;
		items[genitems].element=0;
		items[genitems].offeredValue=1;
		items[genitems].classRequired='a';
		items[genitems].quantity=1;
	items[genitems].drainedValue=1;		

		
		}


		strcpy(names[0],"\nShaleside: South Woods\n");
		strcpy(names[1],"\nShaleside: Village Center\n");
		strcpy(names[2],"\nShaleside: North Woods\n");
		
		for (genitems=3;genitems<=47;genitems++)
	{
		
		strcpy(names[genitems],"\nnullname\n");
		
		}
		
		
	}
	
void printItemStats(int lookup)
	{	
		printf("name :%s\n",items[lookup].name);
		printf("Description: %s\n",items[lookup].description);
		switch(items[lookup].type)
		
		{
			case 7:
			printf("type: HP Consumable\n");
	
			printf("HP Gained: %d\n",items[lookup].offeredValue);
	break;
	
	case 1:
	printf("Material For Cooking\n");
	
		//No longer Used
			printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
		
		case 2:
			printf("Equipable Weapon\n");
		printf("Class needed for Equip: %c\n",items[lookup].classRequired);
		printf("Level needed for Equip: %d\n",items[lookup].levelNeeded);
		printf("Affinity needed for Equip: %.3f\n",items[lookup].affRequired);
			printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
		case 3:
			printf("Equipable Shield\n");
	printf("Class needed for Equip: %c\n",items[lookup].classRequired);
		printf("Level needed for Equip: %d\n",items[lookup].levelNeeded);
		printf("Affinity needed for Equip: %.3f\n",items[lookup].affRequired);
			printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
			case 4:
			printf("Equipable Defense Accessories\n");
	printf("Class needed for Equip: %c\n",items[lookup].classRequired);
		printf("Level needed for Equip: %d\n",items[lookup].levelNeeded);
		printf("Affinity needed for Equip: %.3f\n",items[lookup].affRequired);
			printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
	
	
			case 8:
			printf("Equipable Attack Accessories\n");
	printf("Class needed for Equip: %c\n",items[lookup].classRequired);
		printf("Level needed for Equip: %d\n",items[lookup].levelNeeded);
		printf("Affinity needed for Equip: %.3f\n",items[lookup].affRequired);
			printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
	
	case 5:
			printf("Water Vessels\n");
	
	printf("5 - SEMIKEY ITEM WATER %d\n",items[lookup].keyItem);
			printf("Capacity: %d\n",items[lookup].offeredValue);
	break;
			case 6:
			printf("General Goods\n");
	
		//printf("Level needed for Crafting: %d\n",items[lookup].levelNeeded);
		//printf("Affinity needed for Crafting: %.3f\n",items[lookup].affRequired);
		//	printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
	
	case 9:
			printf("Non-Equip Key Item\n");
	
	printf("1 - KEY ITEM : %d\n",items[lookup].keyItem);
	printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
	
	case 10:
			printf("Gift\n");
	
	printf("1 - KEY ITEM : %d\n",items[lookup].keyItem);
		printf("Purchase Price: %d\n",items[lookup].levelNeeded);
			printf("1 - Male Gift 2- Female Gift 3 - neutral Gift \n 4 - Key Gift %d\n",items[lookup].offeredValue);
			
	break;
			case 11:
			printf("type: Material For Smithing\n");
	
		printf("Level needed for Smithing: %d\n",items[lookup].levelNeeded);
		printf("Affinity needed for Smithing: %.3f\n",items[lookup].affRequired);
			printf("Offered Value: %d\n",items[lookup].offeredValue);
	break;
			case 15:
			printf("type: Magical Tome\n");
	
		printf("Level needed to Learn Spell : %d\n",items[lookup].levelNeeded);
		printf("Affinity needed to Learn Spell: %.3f\n",items[lookup].affRequired);
			printf("Spell Learned: %s\n",skills[items[lookup].offeredValue].name);
	break;
	
	
			case 12:
			printf("type: MP Consumable\n");
	
			printf("MP Reduced: %d\n",items[lookup].offeredValue);
	break;
	
			case 13:
			printf("type: HP/MP/FAT Consumable\n");
	
			printf(" HP/MP/FAT Reduced: %d\n",items[lookup].offeredValue);
	break;
			
			case 14:
			printf("type: Fatigue Consumable\n");
	
			printf("Fatigue Reduced: %d\n",items[lookup].offeredValue);
	break;
	default:
	printf("General Goods\n");
	
	printf("offeredValue: %d\n",items[lookup].offeredValue);
	
	
	break;
	}
		
		
		printf("Base Item Price: %d\n",items[lookup].purchasePrice);
		
	printf("\n");
	
		
		}

void initAffs()
{
	humanAffs[0]=0.25;elfAffs[0]=0.15;spiritAffs[0]=0.05;demihumanAffs[0]=0.4;
	humanAffs[1]=0.15;elfAffs[1]=0.15;spiritAffs[1]=0.25;demihumanAffs[1]=0.05;
	humanAffs[2]=0.25;elfAffs[2]=0.15;spiritAffs[2]=0.05;demihumanAffs[2]=0.4;	
	humanAffs[3]=0.25;elfAffs[3]=0.15;spiritAffs[3]=0.05;demihumanAffs[3]=0.4;
	humanAffs[4]=0.25;elfAffs[4]=0.25;spiritAffs[4]=0.25;demihumanAffs[4]=0.25;
	humanAffs[5]=0.15;elfAffs[5]=0.25;spiritAffs[5]=0.4;demihumanAffs[5]=0.05;
	humanAffs[6]=0.15;elfAffs[6]=0.25;spiritAffs[6]=0.4;demihumanAffs[6]=0.05;
	humanAffs[7]=0.15;elfAffs[7]=0.25;spiritAffs[7]=0.4;demihumanAffs[7]=0.05;
	humanAffs[8]=0.15;elfAffs[8]=0.25;spiritAffs[8]=0.4;demihumanAffs[8]=0.05;
	humanAffs[9]=0.05;elfAffs[9]=0.25;spiritAffs[9]=0.4;demihumanAffs[9]=0.15;
	humanAffs[10]=0.25;elfAffs[10]=0.4;spiritAffs[10]=0.15;demihumanAffs[10]=0.05;
	humanAffs[11]=0.4;elfAffs[11]=0.4;spiritAffs[11]=0.15;demihumanAffs[11]=0.05;
	humanAffs[12]=0.25;elfAffs[12]=0.4;spiritAffs[12]=0.05;demihumanAffs[12]=0.15;
	humanAffs[13]=0.4;elfAffs[13]=0.15;spiritAffs[13]=0.05;demihumanAffs[13]=0.25;
	humanAffs[14]=0.4;elfAffs[14]=0.25;spiritAffs[14]=0.05;demihumanAffs[14]=0.15;
	humanAffs[15]=0.25;elfAffs[15]=0.15;spiritAffs[15]=0.4;demihumanAffs[15]=0.05;
	humanAffs[16]=0.4;elfAffs[16]=0.05;spiritAffs[16]=0.15;demihumanAffs[16]=0.25;
	humanAffs[17]=0.25;elfAffs[17]=0.05;spiritAffs[17]=0.15;demihumanAffs[17]=0.4;
	humanAffs[18]=0.15;elfAffs[18]=0.25;spiritAffs[18]=0.05;demihumanAffs[18]=0.4;
	humanAffs[19]=0.15;elfAffs[19]=0.4;spiritAffs[19]=0.05;demihumanAffs[19]=0.25;
	humanAffs[20]=0.4;elfAffs[20]=0.15;spiritAffs[20]=0.05;demihumanAffs[20]=0.25;
		
	maleAffs[0]=0.4;femaleAffs[0]=0.15;	
	maleAffs[1]=0.15;femaleAffs[1]=0.4;	
	maleAffs[2]=0.4;femaleAffs[2]=0.15;	
	maleAffs[3]=0.4;femaleAffs[3]=0.15;	
	maleAffs[4]=0.15;femaleAffs[4]=0.4;	
	maleAffs[5]=0.15;femaleAffs[5]=0.4;	
	maleAffs[6]=0.15;femaleAffs[6]=0.4;	
	maleAffs[7]=0.15;femaleAffs[7]=0.4;	
	maleAffs[8]=0.15;femaleAffs[8]=0.4;
	maleAffs[9]=0.15;femaleAffs[9]=0.4;	
	maleAffs[10]=0.15;femaleAffs[10]=0.4;		
	maleAffs[11]=0.4;femaleAffs[11]=0.15;		
	maleAffs[12]=0.15;femaleAffs[12]=0.4;		
	maleAffs[13]=0.4;femaleAffs[13]=0.15;	
	maleAffs[14]=0.15;femaleAffs[14]=0.4;	
	maleAffs[15]=0.15;femaleAffs[15]=0.4;	
	maleAffs[16]=0.4;femaleAffs[16]=0.15;	
	maleAffs[17]=0.4;femaleAffs[17]=0.15;	
	maleAffs[18]=0.15;femaleAffs[18]=0.4;	
	maleAffs[19]=0.15;femaleAffs[19]=0.4;	
	maleAffs[20]=0.4;femaleAffs[20]=0.15;	
		}

int main( )
{
initAffs();
	int loops=0;
	int count=0;
	//int idnum=0;
	int agecaphigh=65;
	int agecaplow=13;
	int nonhumanagecaphigh=650;
	int nonhumanagecaplow=150;
	
	srand((unsigned short) time(NULL));
 


int shalesidePop=0;
int fragariaPop=0;
int malusPop=0;
int rubusPop=0;
int sachPop=0;
int pyrusPop=0;
int vitisPop=0;
int TrafalgarPop=0;
int agriPop=0;

int numberofdemis=0;
int numberofelves=0;
int numberofhumans=0;
int numberofspirits=0;
int genderseed=444444; 
int raceseed=5;
int jobseed=13;
int classeed=3; 	
 	int innerloops=0;
 	
 	int currentmembers=0;
 	
initSkills();	
	initMissions();	
initItemsAndNames();
initShops();
initMonsters();
initDialogues();

	for(loops=0;loops<=1023;loops++)
	{Vessels[count].partynumber=0;
		raceseed=5;
/* book 2-1022 defualt specification */
strcpy( Vessels[count].name, "no name");
//seed names
//and initial priorities
Vessels[count].priorities[0]=rand()%4;
Vessels[count].priorities[1]=1;
Vessels[count].priorities[2]=0;
Vessels[count].priorities[3]=0;
Vessels[count].weapon=0;
Vessels[count].shield=0;
Vessels[count].accessory=0;

Vessels[count].debt=0;
Vessels[count].debted=0;
Vessels[count].dead=0;
Vessels[count].EXP=0;
Vessels[count].EXPneeded=50;
Vessels[count].desiredOption=0;




for (innerloops=0;innerloops<=255;innerloops++)
{Vessels[count].RecipesUnlocked[innerloops]=0;
Vessels[count+1].RecipesUnlocked[innerloops]=0;	
Vessels[count+1].SkillsUnlocked[innerloops]=0;	
Vessels[count].SkillsUnlocked[innerloops]=0;	
	}

raceseed=rand()%5;

if (raceseed==0||raceseed==4)
{Vessels[count].race='h';Vessels[count].RecipesUnlocked[1]=1;Vessels[count].RecipesUnlocked[3]=1;Vessels[count].RecipesUnlocked[4]=1;
	Vessels[count].maxfatigue=350;Vessels[count].RecipesUnlocked[10]=1;
	Vessels[count].attack=5;Vessels[count].defense=5;
	Vessels[count].HP=40;Vessels[count].maxHP=40;Vessels[count].MP=30;Vessels[count].maxMP=30;
	numberofhumans+=1;
	for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=humanAffs[innerloops];
}
	}


else if (raceseed==1)
{Vessels[count].race='s';numberofspirits+=1;Vessels[count].RecipesUnlocked[4]=1;Vessels[count].RecipesUnlocked[3]=1;
	Vessels[count].maxfatigue=300;Vessels[count].RecipesUnlocked[1]=1;
	Vessels[count].attack=3;Vessels[count].defense=4;Vessels[count].RecipesUnlocked[10]=1;
	Vessels[count].HP=40;Vessels[count].maxHP=40;Vessels[count].MP=70;Vessels[count].maxMP=70;
	for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=spiritAffs[innerloops];
}
	}


else if (raceseed==2)
{Vessels[count].race='e';Vessels[count].RecipesUnlocked[4]=1;Vessels[count].RecipesUnlocked[3]=1;
	Vessels[count].maxfatigue=350;numberofelves+=1;Vessels[count].RecipesUnlocked[1]=1;
	Vessels[count].attack=4;Vessels[count].defense=4;Vessels[count].RecipesUnlocked[10]=1;
	Vessels[count].HP=50;Vessels[count].maxHP=50;Vessels[count].MP=60;Vessels[count].maxMP=60;
	for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=elfAffs[innerloops];
}
	}
	

else if (raceseed==3)
{Vessels[count].race='d';Vessels[count].maxfatigue=400;numberofdemis+=1;
	Vessels[count].attack=6;Vessels[count].defense=3;Vessels[count].RecipesUnlocked[4]=1;Vessels[count].RecipesUnlocked[3]=1;
	Vessels[count].HP=50;Vessels[count].maxHP=50;Vessels[count].MP=15;Vessels[count].maxMP=15;
	for (innerloops=0;innerloops<23;innerloops+=1)Vessels[count].RecipesUnlocked[1]=1;
{Vessels[count].Affs[innerloops]+=demihumanAffs[innerloops];Vessels[count].RecipesUnlocked[10]=1;
}
	}




strcpy( Vessels[count].avatarfile, "cube.obj");
if(raceseed==0)
{
do
{
Vessels[count].age=rand()%65;
}
while (Vessels[count].age<agecaplow||Vessels[count].age>agecaphigh);
}

else if(raceseed!=0)
{
do
{
Vessels[count].age=rand()%650;
}
while (Vessels[count].age<nonhumanagecaplow||Vessels[count].age>nonhumanagecaphigh);
}

strcpy( Vessels[count].description, "no description");
Vessels[count].vessel_id = rand()%999999;


Vessels[count].hometown = rand()%23;

//town / seeds//
//0-0shaleside
//1-1,2 fragaria
//2-3,4,5 - malus
// 3 -6789 -rubus
//4-10,11 - pyrus
//5- -12 Agritown
//6 - 13,14 - gwater
//7 - 15 - vitis
//8 - 16,17,18,19- saccharin
//9 - 
switch(Vessels[count].hometown)
{
case 0:
	shalesidePop+=1;
	Vessels[count].sub_area_location[0]=0;
	Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=rand()%2;
break;
case 1:
	fragariaPop+=1;
	Vessels[count].sub_area_location[0]=1;
	Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=0;

break;
case 2:
	fragariaPop+=1;
	Vessels[count].sub_area_location[0]=1;
Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=1;

break;
case 3:
	malusPop+=1;
	Vessels[count].sub_area_location[0]=2;
	Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=0;

break;
case 4:
	Vessels[count].sub_area_location[0]=2;
Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=1;

	malusPop+=1;
break;
case 5:
	Vessels[count].sub_area_location[0]=2;
	Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=2;

	malusPop+=1;
break;
case 6:
Vessels[count].sub_area_location[0]=3;
	Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=0;

	rubusPop+=1;
	break;
case 7:
	Vessels[count].sub_area_location[0]=3;
	Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=1;

	rubusPop+=1;
break;
case 8:
Vessels[count].sub_area_location[0]=3;
Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=2;

	rubusPop+=1;
	break;
case 9:
Vessels[count].sub_area_location[0]=3;
Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=3;

	rubusPop+=1;
	break;
case 10:
Vessels[count].sub_area_location[0]=4;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;

	pyrusPop+=1;
	break;
case 11:
Vessels[count].sub_area_location[0]=4;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=1;

pyrusPop+=1;
	break;
case 12:
Vessels[count].sub_area_location[0]=5;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;
	agriPop+=1;
	break;
case 13:
Vessels[count].sub_area_location[0]=6;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;

	TrafalgarPop+=1;
	break;
case 14:
Vessels[count].sub_area_location[0]=6;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=1;

	TrafalgarPop+=1;
	break;
case 15:
Vessels[count].sub_area_location[0]=7;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;

	vitisPop+=1;
	break;
case 16:
Vessels[count].sub_area_location[0]=8;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;

	sachPop+=1;
	break;
case 17:
Vessels[count].sub_area_location[0]=8;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;

sachPop+=1;
	break;
case 18:
Vessels[count].sub_area_location[0]=8;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=1;

	sachPop+=1;
	break;
case 19:
Vessels[count].sub_area_location[0]=8;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=2;

	sachPop+=1;
	break;
case 20:
Vessels[count].sub_area_location[0]=5;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=1;
	agriPop+=1;
	break;
case 21:
Vessels[count].sub_area_location[0]=6;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;

	TrafalgarPop+=1;
	
	break;

	default:
	Vessels[count].sub_area_location[0]=3;
Vessels[count].sub_area_location[1]=0;
	Vessels[count].sub_area_location[2]=4;

rubusPop+=1;
	break;
}
//switch case destinations


Vessels[count].level = rand()%20;
Vessels[count].fame = rand()%255;
if (Vessels[count].vessel_id>genderseed)
{
Vessels[count].gender='f';
for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=femaleAffs[innerloops];
	}

	Vessels[count].defense+=1;
	Vessels[count].fame+=50;
}

else if (Vessels[count].vessel_id<=genderseed)
{
Vessels[count].gender='m';

for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=maleAffs[innerloops];
	}
	Vessels[count].attack+=1;
Vessels[count].fame+=50;
if (Vessels[count].fame<0)
{Vessels[count].fame=5;
	}
}


for (innerloops=0;innerloops<=511;innerloops+=1)
{Vessels[count].inventory[innerloops]=0;
	
}


Vessels[count].job='u';

//assign based on affinities
Vessels[count].status='u';


Vessels[count].class='u';

do
{
classeed=rand()%4;
}
while ((classeed<1)||(classeed>4));



if (classeed==1)

{Vessels[count].class='t';Vessels[count].RecipesUnlocked[5]=1;
Vessels[count].SkillsUnlocked[3]=1;Vessels[count].RecipesUnlocked[10]=1;
	}


 if (classeed==2)
{Vessels[count].class='m';Vessels[count].RecipesUnlocked[7]=1;
Vessels[count].SkillsUnlocked[8]=1;Vessels[count].RecipesUnlocked[10]=1;
	}


 if (classeed==3)
{Vessels[count].class='b';
	Vessels[count].RecipesUnlocked[8]=1;
Vessels[count].SkillsUnlocked[4]=1;Vessels[count].RecipesUnlocked[10]=1;
	}
	

if (classeed==4)
{Vessels[count].class='a';Vessels[count].RecipesUnlocked[9]=1;
Vessels[count].SkillsUnlocked[12]=1;	Vessels[count].RecipesUnlocked[10]=1;
}


count+=1;
}
//End of entity initialization
//BeginCharacter Setup 
//parse .names to assign names to NPCs.
count=0;
	for(loops=0;loops<=0;loops++)
	{
printf("enter a name under 20 characters\n");
scanf("%s",Vessels[count].name);
printf( "Vessel Name : %s\n",Vessels[count].name);
strcpy( Vessels[count+1].name, "Orva");

strcpy( Vessels[count+2].name, "Rose");
Vessels[count+2].level=5;

strcpy( Vessels[count+3].name, "Gizzard");
Vessels[count+3].level=12;

strcpy( Vessels[count+1022].name, "Phagiens Ghost");
strcpy( Vessels[count+1023].name, "The Phagien");


for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]=0;
	Vessels[count+1].Affs[innerloops]=0;
	Vessels[count+2].Affs[innerloops]=0;
	Vessels[count+3].Affs[innerloops]=0;
	Vessels[count+1023].Affs[innerloops]=9;
	Vessels[count+1023].Affs[innerloops]=8;
}


int racechoice=5;
Vessels[count+1].race='s';
Vessels[count+1].attack=3;
Vessels[count+1].defense=4;
Vessels[count+1].maxHP=30;
Vessels[count+1].maxMP=30;
Vessels[count+1].HP=30;
Vessels[count+1].MP=30;
Vessels[count+2].race='h';

Vessels[count+2].SkillsUnlocked[0]=0;
Vessels[count+2].SkillsUnlocked[2]=0;
Vessels[count+2].SkillsUnlocked[3]=0;
Vessels[count+2].SkillsUnlocked[4]=0;
Vessels[count+2].SkillsUnlocked[5]=0;
Vessels[count+2].SkillsUnlocked[6]=0;
Vessels[count+2].SkillsUnlocked[7]=0;
Vessels[count+2].SkillsUnlocked[1]=1;
Vessels[count+2].SkillsUnlocked[8]=0;
Vessels[count+1022].race='h';
Vessels[count+1023].race='a';
	do
	{
		
printf("enter your Race: 1 - human, 2 - Spirit, 3- Elf, 4 - Demiborn\n");

	scanf("%d",&racechoice);
	
	
	
}while(racechoice>=5);

if (racechoice==1)
{
	Vessels[count].race='h';
	Vessels[count].attack=5;Vessels[count].defense=5;
	Vessels[count].HP=40;Vessels[count].maxHP=40;Vessels[count].MP=30;Vessels[count].maxMP=30;
for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=humanAffs[innerloops];
}
	}
if (racechoice==2)
{
	Vessels[count].race='s';
Vessels[count].attack=3;Vessels[count].defense=4;
	Vessels[count].HP=40;Vessels[count].maxHP=40;Vessels[count].MP=70;Vessels[count].maxMP=70;
for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=spiritAffs[innerloops];
}
	}
if (racechoice==3)
{
	Vessels[count].race='e';
	Vessels[count].attack=4;Vessels[count].defense=4;
	Vessels[count].HP=50;Vessels[count].maxHP=50;Vessels[count].MP=60;Vessels[count].maxMP=60;
for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=elfAffs[innerloops];
}
	}
if (racechoice==4)
{
	Vessels[count].race='d';
		Vessels[count].attack=6;Vessels[count].defense=4;
	Vessels[count].HP=50;Vessels[count].maxHP=50;Vessels[count].MP=20;Vessels[count].maxMP=20;
for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=demihumanAffs[innerloops];
}
	}
	
printf( "Vessel Race : %c\n",Vessels[count].race);

if (racechoice!=1)
{
int agechoice=0;
	do
	{
printf("enter your age 150+ 650-: \n");
	scanf("%d",&agechoice);
}while(agechoice<=150||agechoice>=650);
Vessels[count].age=agechoice;
printf( "Age of Vessel : %d\n", Vessels[count].age);
}

else if (racechoice==1)
{int agechoice=0;
	do
	{
printf("enter your age 13+ 65-: \n");
	scanf("%d",&agechoice);
}while(agechoice<=12||agechoice>=66);
Vessels[count].age=agechoice;
printf( "Age of Vessel : %d\n", Vessels[count].age);

	}

Vessels[count+1].gender='f';
Vessels[count+1].age=15715;
Vessels[count+2].age=16;
Vessels[count+2].gender='f';
Vessels[count+1022].age=29;
Vessels[count+1022].gender='m';
Vessels[count+1023].age=6345849;
Vessels[count+1023].gender='m';
int genderchoice=0;
	do
	{
		
printf("male? - 1, or female? - 2: \n");

	scanf("%d",&genderchoice);
}while(genderchoice<1||genderchoice>2);

if (genderchoice==1)
{
	
for (innerloops=0;innerloops<23;innerloops+=1)
{
Vessels[count].gender='m';
Vessels[count].Affs[innerloops]+=maleAffs[innerloops];
}
}

else if (genderchoice==2)
{
Vessels[count].gender='f';

for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count].Affs[innerloops]+=femaleAffs[innerloops];
	
}
}
printf("Vessel Gender : %c\n", Vessels[count].gender); 


for (innerloops=0;innerloops<23;innerloops+=1)
{Vessels[count+2].Affs[innerloops]+=femaleAffs[innerloops];
Vessels[count+1].Affs[innerloops]+=femaleAffs[innerloops];	
Vessels[count+3].Affs[innerloops]+=maleAffs[innerloops];
Vessels[count+3].gender='m';	

}

int classchoice=0;

Vessels[count+1].class='m';
Vessels[count+2].class='t';
Vessels[count+1022].class='t';
Vessels[count+1023].class='a';

for (innerloops=0;innerloops<255;innerloops++)
{Vessels[0].SkillsUnlocked[innerloops]=0;
	Vessels[1].SkillsUnlocked[innerloops]=0;
Vessels[0].RecipesUnlocked[innerloops]=0;
	Vessels[1].RecipesUnlocked[innerloops]=0;


	}
	

	do
	{
		
printf("enter your Class: 1 - tradesmen, 2 - mage, 3 - bladesmen 4 - archer\n");

	scanf("%d",&classchoice);

}while(classchoice<=0||classchoice>=5);

if (classchoice==1)
{Vessels[count].RecipesUnlocked[1]=1;
	Vessels[count].SkillsUnlocked[1]=1;
	
	Vessels[count].RecipesUnlocked[4]=1;
	Vessels[count].RecipesUnlocked[5]=1;
	Vessels[count].RecipesUnlocked[3]=1;
	Vessels[count].SkillsUnlocked[3]=1;
	Vessels[count].class='t';
	
	
	}
if (classchoice==2)
{
	Vessels[count].class='m';
	
	Vessels[count].inventory[2]=73;
	
	Vessels[count].RecipesUnlocked[7]=1;
	Vessels[count].RecipesUnlocked[4]=1;
	Vessels[count].RecipesUnlocked[1]=1;
	Vessels[count].RecipesUnlocked[3]=1;
	Vessels[count].SkillsUnlocked[1]=1;
	Vessels[count].SkillsUnlocked[8]=1;
	}
if (classchoice==3)
{
	Vessels[count].class='b';
	Vessels[count].RecipesUnlocked[4]=1;
Vessels[count].RecipesUnlocked[1]=1;
Vessels[count].RecipesUnlocked[3]=1;
Vessels[count].RecipesUnlocked[8]=1;
	Vessels[count].SkillsUnlocked[1]=1;
	Vessels[count].SkillsUnlocked[4]=1;
	}
if (classchoice==4)
{
	Vessels[count].class='a';
Vessels[count].RecipesUnlocked[3]=1;
	Vessels[count].SkillsUnlocked[1]=1;
	Vessels[count].SkillsUnlocked[12]=1;
	Vessels[count].RecipesUnlocked[4]=1;
	Vessels[count].RecipesUnlocked[1]=1;
	Vessels[count].RecipesUnlocked[9]=1;
	}
	
	//Set orvas/npcs final skills and recipes
Vessels[count+1].RecipesUnlocked[1]=1;
	Vessels[count+1].SkillsUnlocked[1]=1;
	Vessels[count+1].RecipesUnlocked[10]=1;
	Vessels[count+1].RecipesUnlocked[3]=1;
	Vessels[count+1].RecipesUnlocked[4]=1;
		Vessels[count+1].RecipesUnlocked[7]=1;
	Vessels[count+1].SkillsUnlocked[8]=1;
	
printf( "Vessel Class : %c\n",Vessels[count].class);


int jobchoice=0;
	Vessels[count+1].job='r';
	Vessels[count+2].job='h';
	Vessels[count+1022].job='x';
	Vessels[count+1023].job='x';
	do
	{
		
printf("enter your job: 1 - Herbalist, 2 - Crafter, 3- Blacksmith\n");
printf("4 - Trader,5 - Medic, 6- GuildLeader\n");

	scanf("%d",&jobchoice);

}while(jobchoice==0);

if (jobchoice==1)
{
	Vessels[count].job='h';
	}
if (jobchoice==2)
{
	Vessels[count].job='c';
	}
if (jobchoice==3)
{
	Vessels[count].job='b';
	}
if (jobchoice==4)
{
	Vessels[count].job='m';
	}
if (jobchoice==5)
{
	Vessels[count].job='n';
	}
if (jobchoice==6)
{
	Vessels[count].job='g';
	}
	
system("clear");
// Custom NPC SPecifications 1-64 +1024
//printf( "Description : %s\n", Vessels[count].description);
Vessels[count+1].vessel_id=rand()%999999;
Vessels[count+2].vessel_id=rand()%999999;
Vessels[count].vessel_id=rand()%999999;


  Vessels[count].EXP=0;
  
  Vessels[count+1].EXP=0;
      Vessels[count].level=1;
    Vessels[count+1].level=0;
 Vessels[count].EXPneeded=25;Vessels[count+1].EXPneeded=25;

Vessels[count].sub_area_location[0]=0;
Vessels[count].sub_area_location[1]=0;
Vessels[count].sub_area_location[2]=0;
Vessels[count+1].sub_area_location[0]=0;
Vessels[count+1].sub_area_location[1]=0;
Vessels[count+1].sub_area_location[2]=2;
Vessels[count+2].sub_area_location[0]=0;
Vessels[count+2].sub_area_location[1]=0;
Vessels[count+2].sub_area_location[2]=1;
Vessels[count].status='n';Vessels[count+1].status='n';
Vessels[count+1].wallet=1;
printf("\n");


}
//Player Readout//

count=0;
	for(loops=0;loops<=0;loops++)
	{

printf( "Vessel # %d Name : %s\n",count, Vessels[count].name);
printf( "Vessel Race : %c\n",Vessels[count].race);
printf( "Age of Vessel : %d\n", Vessels[count].age);
printf("Vessel Gender : %c\n", Vessels[count].gender); 
printf( "Vessel Class : %c\n", Vessels[count].class);
printf( "Description : %s\n", Vessels[count].description);
printf("Entity id : %d\n", Vessels[count].vessel_id); 
printf("Vessel Level : %d\n", Vessels[count].level); 
printf("Vessel Fame : %d\n", Vessels[count].fame); 
printf("Vessel job : %c\n", Vessels[count].job); 
printf("Vessel status : %c\n", Vessels[count].status); 
printf("Vessels HomeTown : %d\n", Vessels[count].hometown); 
printf("Vessel OBJ file : %s\n", Vessels[count].avatarfile); 
printf("Next Desired Action if Available : %d",Vessels[count].desiredOption);
printf("\n");

for (innerloops=0;innerloops<23;innerloops+=1)
{
printf("%f ",Vessels[count].Affs[innerloops]);
}printf("\n");

}


printf("\nMap Notes\n");
printf("Saccharin: %d\n",sachPop);
printf("Shaleside: %d\n",shalesidePop);
printf("Fragaria : %d\n",fragariaPop);
printf("Malus: %d\n",malusPop);
printf("Rubus: %d\n",rubusPop);
printf("Pyrus: %d\n",pyrusPop);
printf("Vitis: %d\n",vitisPop);
printf("Trafalgar: %d\n",TrafalgarPop);
printf("Agrinuum: %d\n",agriPop);
printf("World Pop :%d\n",(agriPop+TrafalgarPop+vitisPop+pyrusPop+rubusPop+malusPop+fragariaPop+shalesidePop+sachPop));

int headcount;
headcount=numberofdemis+numberofhumans+numberofelves+numberofspirits;

printf("\nEntity Notes\n");
printf("demis: %d\n",numberofdemis);
printf("humans: %d\n",numberofhumans);
printf("elves: %d\n",numberofelves);
printf("spirits: %d\n",numberofspirits);
printf("total Enitities: %d\n\n",headcount);


//stat hacks//
Vessels[0].wallet=10000;
Vessels[0].RecipesUnlocked[10]=1;
	Vessels[0].inventory[0]=101;
	Vessels[0].fame=5;
	Vessels[0].hometown=0;
	Vessels[1].hometown=0;
Vessels[2].hometown=0;

Vessels[3].hometown=0;

Vessels[3].sub_area_location[2]=0;
Vessels[3].sub_area_location[1]=0;
Vessels[3].sub_area_location[0]=0;

Vessels[0].priorities[0]=0;
Vessels[0].priorities[1]=0;
Vessels[0].priorities[2]=0;
Vessels[0].priorities[3]=0;
Vessels[1].priorities[0]=0;
Vessels[1].priorities[1]=0;
Vessels[1].priorities[2]=0;
Vessels[1].priorities[3]=4;
Vessels[2].priorities[0]=0;
Vessels[2].priorities[1]=0;
Vessels[2].priorities[2]=0;
Vessels[2].priorities[3]=1;
Vessels[3].priorities[0]=0;
Vessels[3].priorities[1]=0;
Vessels[3].priorities[2]=0;
Vessels[3].priorities[3]=5;
Vessels[3].inventory[1]=66;

int scheduleaction;

int quit=0;

int quarterspassed=0;
int dayspassed=0;
int battles=0;
int resting=0;
int freewalking=0;
char checkforrecruit='n';
do
{//main Menu-  THE SCHEDULER
	
	
		//check/load/view party()//members
printf("Current Location(town/district/unit) : %d %d %d : ", Vessels[0].sub_area_location[0],Vessels[0].sub_area_location[1],Vessels[0].sub_area_location[2]);
printf("Current Location : %s\n",names[Vessels[0].sub_area_location[2]]);	
printf("player fatigue: %d of %d \n",Vessels[0].fatigue,Vessels[0].maxfatigue);
printf("EXP needed: %d of %d\n",Vessels[0].EXP,Vessels[0].EXPneeded);
printf("player health: %d of %d\n",Vessels[0].HP,Vessels[0].maxHP);
printf("player mana: %d of %d\n",Vessels[0].MP,Vessels[0].maxMP);
printf("Wallet: %d\t Bank: %d \n",Vessels[0].wallet,Vessels[0].heldRune);
printf("Hours Passed : %d\n",quarterspassed);
printf("Days Passed : %d\n",dayspassed);



if ((Vessels[0].debted==1)&&(Vessels[0].deadline==0))
{Vessels[0].deadline=20;
}


else if ((Vessels[0].debted==1)&&(Vessels[0].deadline!=0))
{
	Vessels[0].deadline--;
	printf("\nYou Are In DEBT! %d of %d time left: %d\n",Vessels[0].wallet,Vessels[0].debt,(Vessels[0].deadline-1));};


if ((Vessels[0].deadline==1)&&(Vessels[0].wallet<Vessels[0].debt))
{
	printf("\nYou Were Slain by ""''The Collectors''""! \n");
	exit(0);
	}


if ((Vessels[0].deadline==1)&&(Vessels[0].wallet>Vessels[0].debt))
{
	printf("\nYou were Visited by ""''The Collectors''""! \n You've Payed you're debts...\n");
	Vessels[0].wallet-=Vessels[0].debt;
	Vessels[0].debt=0;
	Vessels[0].deadline=0;
Vessels[0].debted=0;
	}

else if ((Vessels[0].deadline==0)&&(Vessels[0].wallet>Vessels[0].debt))
{
	}
int readout=0;
freewalking=0;
	battles=0;
	resting=0;
	//add cases and modifiers here npc sheduled actions
for (count=66;count<1023;count++)
{
	if (Vessels[count].priorities[3]==3)
	{Vessels[count].priorities[3]=0;}
	
	if (Vessels[count].fatigue<=250);
	{
	Vessels[count].priorities[0]=rand()%4;
	//battle outcomes for npcs 
	}
	
	if (Vessels[count].fatigue>=(Vessels[count].maxfatigue-50))
	{Vessels[count].priorities[0]=0;}
	
	switch(Vessels[count].priorities[0])
	{
		case 1:
		//Finish Full Scepcification for NPC LEVEL UP//
		Vessels[count].fatigue+=50;Vessels[count].wallet+=rand()%30;
		battles+=1;Vessels[count].EXP+=(5*Vessels[count].level);
if ((Vessels[count].EXP>Vessels[count].EXPneeded)&&(Vessels[count].level<90))
{
	Vessels[count].EXPneeded=(Vessels[count].EXPneeded*2);
		Vessels[count].EXP=0;
		Vessels[count].level+=1;
		Vessels[count].attack+=(Vessels[count].level+1);
		Vessels[count].defense+=(Vessels[count].level+1);
		Vessels[count].maxMP+=(Vessels[count].maxMP*2);
		Vessels[count].maxHP+=(Vessels[count].maxHP*2);
	}
		break;
		case 0:
		Vessels[count].fatigue-=500;
		if(Vessels[count].fatigue<0){Vessels[count].fatigue=0;}
		resting+=1;
		break;
		case 2:
		
Vessels[count].priorities[3]=3;
		
		freewalking+=1;
		break;
		default:
		Vessels[count].fatigue-=500;
		if(Vessels[count].fatigue<0){Vessels[count].fatigue=0;}
		resting+=1;
		break;
}

	
}printf("%d NPC'S are currently Adventuring.",battles);
printf("\n%d NPC'S are currently Resting.",resting);
printf("\n%d NPC'S are Roaming Towns.",freewalking);
printf("\n%d NPC'S are currently Dead.",deadNPCcount);
printf("\n%d NPC'S Have Perished\n.",bodycount);
//REWRITE THIS----//
		
for (count=0;count<1023;count++)
{
	if (Vessels[count].priorities[3]==9)
	{
printf("\n--------current party members:%d of %d---",Vessels[count].partynumber,maxparty);
		
	Vessels[count].sub_area_location[2]=Vessels[0].sub_area_location[2];
printf("\nName: %s\n",Vessels[count].name);
printf("fatigue: %d of %d \n",Vessels[count].fatigue,Vessels[count].maxfatigue);
printf("Wallet: %d\t Bank: %d ",Vessels[count].wallet,Vessels[count].heldRune);
printf("\nEXP : %d of %d",Vessels[count].EXP,Vessels[count].EXPneeded);
printf("\nHP : %d of %d",Vessels[count].HP,Vessels[count].maxHP);		
		
		
		}
		

	}

////UNTIL HERE///
//fatigue scenarios
if ((Vessels[0].fatigue>0)&&(Vessels[0].fatigue<Vessels[0].maxfatigue))
{
scheduleaction=initOptions();
}
else if(Vessels[0].fatigue>=Vessels[0].maxfatigue)
{int bills;
	printf("Player has collapsed from fatigue. Requires Medical Attention (%d rune) and Rest.\n",50*(Vessels[0].level)+5);
	bills=25*(Vessels[0].level+5);
	//instead of Vessels[0].level use subarea/location to assign medical costs.
	Vessels[0].fatigue=0;
	if((Vessels[0].wallet<bills)&&(Vessels[0].heldRune<bills))
	{Vessels[0].debted=1;Vessels[0].debt+=(bills*1);}
//remake this case 	
	else if((Vessels[0].wallet>bills)||(Vessels[0].heldRune>bills))
{
	if (Vessels[0].wallet<bills)	
		{
	Vessels[0].heldRune-=bills;
}
else if(Vessels[0].wallet>bills)
{
	Vessels[0].wallet-=bills;
}	
	}
	
	quarterspassed+=1;
	if(quarterspassed>=24)
	{quarterspassed=0;
		dayspassed+=1;
		}
	
//scheduleaction=initOptions2();
	scheduleaction=0;
	}

else if(Vessels[0].fatigue<=0)
{
scheduleaction=initOptions3();
	}

if((scheduleaction==0)&&(Vessels[0].fatigue>=1))
{
	for (count=0;count<maxparty+1;count++)
	{
	Vessels[count].HP+=500;
	if (Vessels[count].HP>Vessels[count].maxHP)
	{Vessels[count].HP=0; Vessels[count].HP+=Vessels[count].maxHP;}
	
	Vessels[count].MP+=400;
	
	if (Vessels[count].MP>Vessels[count].maxMP)
	{Vessels[count].MP=0; Vessels[count].MP+=Vessels[count].maxMP;}
Vessels[count].fatigue-=250;

if (Vessels[count].fatigue<0){Vessels[count].fatigue=0;}

}
if (Vessels[0].fatigue!=0){
	printf("scheduler recieved 0 - Player Rested...\n");
	//NPC's Will Eval NextPriority.
	}
	
	quarterspassed+=1;
	if(quarterspassed>24)
	{quarterspassed=0;
		dayspassed+=1;
		}
	
	
	}
	
else if(scheduleaction==1) //go battle
{
printf("scheduler recieved 1 - Went on Adventure \n");
//seed wild encounters for now to test battle/leveling//
for (count=0;count<=currentmembers;count++)
	{
	Vessels[count].fatigue+=50;
}
quarterspassed+=rand()%3;
if(quarterspassed>24)
	{quarterspassed=0;
		dayspassed+=1;
		}
	
battleresults=battle();


if (battleresults==0)
{
system("clear");
system("reset");

	printf("\nNothing encountered...");
	}

else if (battleresults==2)
{
system("clear");
system("reset");

	printf("\nencountered and won!");
	//Run scripted battle payouts//
	}


if (battleresults==4)
{
system("clear");
system("reset");

	printf("\nFled from Battle...\n");
	}

else if (battleresults==3)
{
system("clear");
system("reset");

	printf("\nencountered and won!");
	int totalexp=0;
	int resolveloops;
printf("\nGained Rune! %d\n",(gainedrune*(monstersSlain+1)));
itemseed=0;

	for (resolveloops=0;resolveloops<=monstersSlain;resolveloops++)
{
totalexp+=monsters[resolveloops].EXPoffered;
}
printf("EXP Gained: %d\n",totalexp);
itemseed+=rand()%64;printf("ITEMSEED: %d\n",itemseed);
if ((itemseed<64)&&(itemseed>1))
{
int recipient;
//make a function to check locations and seed items
switch (Vessels[0].sub_area_location[2])
{
	case 0:
	itemseed=rand()%9;
    if (itemseed==0)
	{break;}

	if (itemseed==8)
	{itemseed=62;break;}	
	if (itemseed==2)
	{itemseed=59;break;}
	if (itemseed==1)
	{itemseed=61;break;}
	if (itemseed==3)
	{itemseed=1;break;}
	if (itemseed==4)
	{itemseed=68;break;}
	if (itemseed==5)
	{itemseed=5;break;}
	if (itemseed==6)
	{itemseed=2;break;}
	if (itemseed==7)
	{itemseed=23;break;}
	break;
	case 1:
	itemseed=rand()%8;

	if (itemseed==0)
		{break;}
	if (itemseed==5)
	{itemseed=62;break;}
	if (itemseed==2)
	{itemseed=59;break;}
	if (itemseed==1)
	{itemseed=60;break;}
	if (itemseed==3)
	{itemseed=68;break;}
	if (itemseed==5)
	{itemseed=70;break;}
	if (itemseed==6)
	{itemseed=71;break;}
	if (itemseed==4)
	{itemseed=2;break;}
	if (itemseed==7)
	{itemseed=23;break;}
	
	break;
	case 2:
	itemseed=rand()%7;

	if (itemseed==0)
		{break;}
	if (itemseed==5)
	{itemseed=62;break;}
	if (itemseed==2)
	{itemseed=59;break;}
	if (itemseed==1)
	{itemseed=60;break;}
	if (itemseed==3)
	{itemseed=68;break;}
	if (itemseed==5)
	{itemseed=70;break;}
	if (itemseed==6)
	{itemseed=71;break;}
	if (itemseed==4)
		{itemseed=2;break;}
break;
	default:
	break;
	}
if(itemseed!=0){
printf("\nRecieved Item: %s who will take it?",items[itemseed].name);

do{
scanf("%d",&recipient);}while(recipient>currentmembers);

for (count=0;count<=511;count++)
{
	if (Vessels[recipient].inventory[count]==0)
{Vessels[recipient].inventory[count]=itemseed;
	count=512;
	}	
	}

	}
int nextEXP;
for (count=0;count<=currentmembers;count++)
{
	for (resolveloops=0;resolveloops<=monstersSlain;resolveloops++)
{
Vessels[count].EXP+=monsters[resolveloops].EXPoffered;
}

Vessels[count].wallet+=gainedrune*(monstersSlain+1);
	
	if (Vessels[count].EXP>=Vessels[count].EXPneeded)
	{	
		nextEXP=50;nextEXP*=Vessels[count].level;
		printf("\n%s LEVEL UP\n",Vessels[count].name);
	
		Vessels[count].EXPneeded+=nextEXP;
	
		Vessels[count].level+=1;	printf("\n LEVEL %d\n",Vessels[count].level);
		Vessels[count].attack+=1;
		Vessels[count].defense+=1;
		Vessels[count].maxMP+=10;
		Vessels[count].maxHP+=10;
		Vessels[count].maxfatigue+=50;
		Vessels[count].EXP=0;
		}
}	
}


}



else if (battleresults==1)
{printf("\nencountered and lost!");
printf("\ngained : %d",lostprofits);
int lossloops;
for (count=0;count<=currentmembers;count++)
{
	Vessels[count].wallet-=(lostprofits*Vessels[count].level);
	Vessels[count].HP=1;
for (lossloops=0;lossloops<=monstersSlain;lossloops++)
{

	Vessels[count].EXP-=monsters[lossloops].EXPoffered;
}

	Vessels[count].fatigue+=50;
	if (Vessels[count].EXP<0)
	{Vessels[count].EXP=0;
		}

	if (Vessels[count].wallet<0)
	{Vessels[count].wallet=0;
		}
}	
}


	}
	
else if(scheduleaction==2) //system clear/trigger
{
system("clear");
system("reset");

}


else if(scheduleaction==9) //move locations
{
printf("\nscheduler recieved : 9 - Increment/Decrement Map\n");
printf("Increment - 2 Decrement Map - 1\n");

int getlocation=0;
do{
	scanf("%d",&getlocation);
	}while((getlocation==0));

if ((getlocation==1)&&(Vessels[0].sub_area_location[2]!=0))
{Vessels[0].sub_area_location[2]-=1;}

else if ((getlocation==1)&&(Vessels[0].sub_area_location[2]==0))
{printf("\nYou Cannot go Back any Further!!! .\n");}



 if ((getlocation==2)&&(Vessels[0].sub_area_location[2]==mapmax)&&(storytriggers[0]==1))
{printf("\nHEY!!! Get over Here!\n");
	storytriggers[0]=2;
	
	
	}

else if ((getlocation==2)&&(Vessels[0].sub_area_location[2]!=mapmax))
{Vessels[0].sub_area_location[2]+=1;}


if ((getlocation==2)&&(Vessels[0].sub_area_location[2]==mapmax)&&(storytriggers[0]==2))
{printf("\nYou Cannot Proceed Further !!! Talk to Rose...\n");
	}
else if ((getlocation==2)&&(Vessels[0].sub_area_location[2]==mapmax)&&(mapmax>=2))
{printf("\nYou Cannot Proceed Further !!! \n");
	}


}



else if(scheduleaction==10)
{printf("\nscheduler recieved : 10 - Gift\n");
int thegiver=0;
int gifting=0;
int recipient=0;
int thegift=0;

printf("\nWho will Give? \n");

for(count=0;count<=maxparty;count++)
{printf("%d : %s\n",count,Vessels[count].name);
	}

scanf("%d",&thegiver);
	
	if((thegiver>maxparty)||(thegiver<0))
	{gifting=6;
		}
if (gifting!=6){
	printf("\n%s will Gift an Item to whom?\n",Vessels[thegiver].name);


for(count=1;count<=maxparty;count++)
{printf("%d : %s\n",count,Vessels[count].name);
	}
scanf("%d",&recipient);
	
	if((recipient>maxparty)||(recipient<0))
	{gifting=6;
		}
		if(gifting!=6)
		{
	printf("\n%s will Gift an Item to %s\n",Vessels[thegiver].name,Vessels[recipient].name);

	printf("Which Item? : ");
for(count=thegiver;count<=thegiver;count++)
{
for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[count].inventory[innerloops]!=0)
{
printf("\nITEM %d %s : %d \n",innerloops,items[Vessels[count].inventory[innerloops]].name,Vessels[count].inventory[innerloops]);
}
}printf("\n");

	}

scanf("%d",&thegift);

//move items
for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[recipient].inventory[innerloops]==0)
{printf("\nGave %s to %s\n",items[Vessels[thegiver].inventory[thegift]].name,Vessels[recipient].name);

Vessels[recipient].inventory[innerloops]=Vessels[thegiver].inventory[thegift];
Vessels[thegiver].inventory[thegift]=0;
innerloops=511;
}
}
gifting=6;
}
	
}
}
//check jobs
if(scheduleaction==11&&Vessels[0].priorities[0]!=0)
{printf("\nscheduler recieved : 11 - Check Job Status\n");
if (Vessels[0].priorities[0]==2){
	
	missionConditions(currentjob[0],currentjob[1]);
	
	
	}

}


else if(scheduleaction==11&&Vessels[0].priorities[0]==0)
{printf("\nscheduler recieved : 11 - Check Job Status\n");
printf("NO JOB SELECTED\n");
}

else if(scheduleaction==3) //shop if available
{
	
	int barter;
	int barter2;
int putItem;
putItem=0;
if (Shops[Vessels[0].sub_area_location[0]].sub_area_location[1]==Vessels[0].sub_area_location[2])
{
printf("\nscheduler recieved : 3 - SHOP\n");

printf("%s: Fame:%d Wallet : %d \n",Shops[Vessels[0].sub_area_location[0]].name,Shops[Vessels[0].sub_area_location[0]].fame,Shops[Vessels[0].sub_area_location[0]].wallet);

printf("%s: Fame:%d Wallet : %d \n",Vessels[0].name,Vessels[0].fame,Vessels[0].wallet);

inshop=1;

do{


printf("0 - Buy, or 1 - Sell. any other key to quit...");	
	scanf("%d",&barter);
	//BUYING//
	switch (barter)
	{
		case 0:
		printf("Buying Selected\n");
	
printf("Goods for Sale:\n");

for (loops=0;loops<=511;loops++)
{
	if (Shops[Vessels[0].sub_area_location[0]].inventory[loops]!=0)
	{
printf("%d \t %s: %d \t %d \n",loops,items[Shops[Vessels[0].sub_area_location[0]].inventory[loops]].name, Shops[Vessels[0].sub_area_location[0]].inventory[loops],items[Shops[Vessels[0].sub_area_location[0]].inventory[loops]].purchasePrice);

};
	}
	do{
		printf("Purchase Which Item? : ");
		scanf("%d",&barter2);
	if (barter2>=512)
	{
putItem=0;
};

if (items[Shops[Vessels[0].sub_area_location[0]].inventory[barter2]].purchasePrice>Vessels[0].wallet)
	{printf("\nYou do not have enough money...\n ");
		}
	}while((items[Shops[Vessels[0].sub_area_location[0]].inventory[barter2]].purchasePrice>Vessels[0].wallet));
	
		printf("Bought %s for %d\n",items[Shops[Vessels[0].sub_area_location[0]].inventory[barter2]].name,items[Shops[Vessels[0].sub_area_location[0]].inventory[barter2]].purchasePrice);
		Vessels[0].wallet-=(items[Shops[Vessels[0].sub_area_location[0]].inventory[barter2]].purchasePrice);

putItem=1;

do {
for (loops=0;loops<=511;loops++)
{
	switch (Vessels[0].inventory[loops])
	{
		case 0:
Vessels[0].inventory[loops]=Shops[Vessels[0].sub_area_location[0]].inventory[barter2];
		Shops[Vessels[0].sub_area_location[0]].inventory[barter2]=0;
		putItem=0;
		

		break;
		default:
		
		break;
		}
	
}		
}while(putItem==1);
		
		
		break;
//SELLING//
		case 1:
		printf("Sell Selected\n");

printf("Sellable Items:\n");

for (loops=0;loops<=511;loops++)
{
	if (Vessels[0].inventory[loops]!=0)
	{
printf("%d\t%s: %d\n",loops,items[Vessels[0].inventory[loops]].name,items[Vessels[0].inventory[loops]].purchasePrice);

};
	}
		do{
		printf("Sell Which Item? : ");
		
	printf("\nWeapon in Inventory Spot %d\n",Vessels[0].checkitem[0]);
	printf("\nShield in Inventory Spot %d\n",Vessels[0].checkitem[1]);
	printf("\nAccessory in Inventory Spot %d\n",Vessels[0].checkitem[2]);
	
	
		scanf("%d",&barter2);
	}while((items[Vessels[0].inventory[barter2]].purchasePrice>Shops[Vessels[0].sub_area_location[0]].wallet)||(items[Vessels[0].inventory[barter2]].type==9));
		
		if(barter2==Vessels[0].checkitem[0])
	{Vessels[0].weapon=0;Vessels[0].checkitem[0]=0;
		}
			if(barter2==Vessels[0].checkitem[1])
	{Vessels[0].shield=0;Vessels[0].checkitem[1]=0;
		}
		if(barter2==Vessels[0].checkitem[2])
	{Vessels[0].accessory=0;Vessels[0].checkitem[2]=0;
		}
		
		
		printf("Sold %s for %d\n",items[Vessels[0].inventory[barter2]].name,items[Vessels[0].inventory[barter2]].purchasePrice);
	Vessels[0].wallet+=items[Vessels[0].inventory[barter2]].purchasePrice;
	
	if (barter2>=512)
	{
putItem=0;
};
	
putItem=1;

do {
for (loops=0;loops<=511;loops++)
{
	switch (Shops[Vessels[0].sub_area_location[0]].inventory[loops])
	{
		case 0:
Shops[Vessels[0].sub_area_location[0]].inventory[loops]=Vessels[0].inventory[barter2];
		Vessels[0].inventory[barter2]=0;
		putItem=0;
		
		break;
		default:
		
		break;
		
		}
	
}		
}while(putItem==1);
		
	
	//break;
	
		default:
		inshop-=1;
		break;
		
		}
	//inshop-=1;
	
	
	}while(inshop==1);
}
}

else if(scheduleaction==4) // interact/scout NPC's
{
	
system("clear");
system("reset");

int inmenu=0;
printf("\nscheduler recieved : 4 - View Records/Entity stats \n");

printf("Entities In your area  [%d][%d][%d] : \n",Vessels[0].sub_area_location[0],Vessels[0].sub_area_location[1],Vessels[0].sub_area_location[2]);

for (count=0;count<1023;count++)
{	
	if ((Vessels[count].sub_area_location[0]==Vessels[0].sub_area_location[0])&&(Vessels[count].sub_area_location[2]==Vessels[0].sub_area_location[2]))
	{
	printf("%d : fat:%d %s  Lvl:%d Fame:%d talk:%d\n",count,Vessels[count].fatigue,Vessels[count].name,Vessels[count].level,Vessels[count].fame,Vessels[count].priorities[3]);	
	printf("HP : %d of %d\n",Vessels[count].HP,Vessels[count].maxHP);		
}
	
	
	}

printf("Enter the Entity[x] : \n");

do{
//maxparty+=1;//

//will grant another open slot unlocking orva automatically.
//this works up untill all 6 charcters are in party//
//additional charcters out side this must trade their stats with 
//another entity in place 1,2,3,4,5. The Player May not be Removed
//from the 0th

//Enitity Finder/Examiner/Alterer
int conversing;
int findNPC;
scanf("%d",&findNPC);
int input=findNPC-1;
count=findNPC;
int passprior=0;

for(input;input<findNPC;input++)
	{

printf( "Vessel # %d Name : %s\n",count, Vessels[count].name);
printf( "Vessel Race : %c\n",Vessels[count].race);
printf( "Age of Vessel : %d\n", Vessels[count].age);
printf("Vessel Gender : %c\n", Vessels[count].gender); 
printf( "Vessel Class : %c\n", Vessels[count].class);
printf( "Description : %s\n", Vessels[count].description);
printf("Entity id : %d\n", Vessels[count].vessel_id); 
printf("Vessel Level : %d\n", Vessels[count].level); 
printf("Vessel Fame : %d\n", Vessels[count].fame); 
printf("Vessel EXP : %d\n", Vessels[count].EXP); 
printf("Vessel job : %c\n", Vessels[count].job); 
printf("Vessel status : %c\n", Vessels[count].status); 
printf("Vessels HomeTown : %d\n", Vessels[count].hometown); 
printf("Vessel OBJ file : %s\n", Vessels[count].avatarfile); 
printf("Next Desired Action if Available : %d\n",Vessels[count].desiredOption);
printf("\n");
printf("\n Attack: %d, Weapon : %d\n Defense: %d, Shield :%d\n",Vessels[count].attack,Vessels[count].weapon,Vessels[count].defense,Vessels[count].shield);
printf("Affinities - \n");

printf("MINE: %.3f\t",Vessels[count].Affs[0]);
printf("MANAGE: %.3f\t",Vessels[count].Affs[1]);
printf("CRAFT: %.3f\t",Vessels[count].Affs[2]);
printf("PHYSATK: %.3f\t",Vessels[count].Affs[3]);
printf("PHYSDEF: %.3f\n",Vessels[count].Affs[4]);
printf("INT: %.3f\t",Vessels[count].Affs[5]);
printf("MAGATK: %.3f\t",Vessels[count].Affs[6]);
printf("MAGDEF: %.3f\t",Vessels[count].Affs[7]);
printf("VIT: %.3f\t",Vessels[count].Affs[8]);
printf("ARCH: %.3f\n",Vessels[count].Affs[9]); 
printf("BLADE: %.3f\t",Vessels[count].Affs[10]);
printf("MED: %.3f\t",Vessels[count].Affs[11]);
printf("BUSINESS: %.3f\t",Vessels[count].Affs[12]);
printf("COOK: %.3f\t",Vessels[count].Affs[13]);
printf("RELATION: %.3f\n",Vessels[count].Affs[14]);
printf("SMITH: %.3f\t",Vessels[count].Affs[15]);
printf("LUCK: %.3f\t",Vessels[count].Affs[16]);
printf("HERB: %.3f\t",Vessels[count].Affs[17]);
printf("TACT: %.3f\t",Vessels[count].Affs[18]);
printf("FARM: %.3f\n",Vessels[count].Affs[19]);
printf("??? 1: %.3f\t",Vessels[count].Affs[20]);
printf("??? 2: %.3f\t",Vessels[count].Affs[21]);
printf("??? 3: %.3f\t",Vessels[count].Affs[22]);
printf("??? 4: %.3f\n",Vessels[count].Affs[23]);


for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[count].inventory[innerloops]!=0)
{
printf("\nITEM %d : %d ",innerloops,Vessels[count].inventory[innerloops]);
}
}

if (((Vessels[count].priorities[3]==1)||(Vessels[count].priorities[3]==4)||(Vessels[count].priorities[3]==5)||(Vessels[count].priorities[3]==3))&&(Vessels[count].sub_area_location[2]==Vessels[0].sub_area_location[2]))
{printf("\nYou May Talk with %s\n",Vessels[count].name);
	
	printf("\nTalk - 2 Nothing - otherwise : ");
	scanf("%d",&conversing);
	}	
	if (conversing==2&&Vessels[count].priorities[3]==1)
	{	
passprior=Vessels[count].priorities[3];
		currentjob[0]=0;
	currentjob[1]=count;
	Vessels[0].priorities[0]=2;
	printDialogue(count,currentjob[0],passprior);
	}
	
	if ((conversing==2)&&(Vessels[count].priorities[3]==4)&&(maxparty<5))
	{
passprior=Vessels[count].priorities[3];
	printDialogue(count,currentjob[0],passprior);
	Vessels[count].priorities[3]=9;
	Vessels[count].partynumber=maxparty+1;
	currentmembers+=1;
	maxparty+=1;
	}
	
	
	if (conversing==2&&Vessels[count].priorities[3]==5)
	{
passprior=Vessels[count].priorities[3]-3;

for (passprior=passprior;passprior>=1;passprior--)
{
	printDialogue(count,currentjob[0],passprior);
	
	
}	Vessels[count].priorities[3]=0;
	passprior=0;
	
	for (innerloops=0;innerloops<511;innerloops++)
	{
		if (Vessels[0].inventory[innerloops]==0)
		{
			Vessels[0].inventory[innerloops]=Vessels[count].inventory[1];innerloops=512;}

		}
	printf("\nRecieved: %s\n",items[Vessels[count].inventory[1]].name);		
	Vessels[count].inventory[1]=0;
	}
	
	if (conversing==2&&Vessels[count].priorities[3]==3)
	{
passprior=Vessels[count].priorities[3];
	printDialogue(count,currentjob[0],passprior);

}
	
else if ((Vessels[count].priorities[3]==2)&&(Vessels[count].sub_area_location[2]==Vessels[0].sub_area_location[2]))
{printf("Report to %s\n",Vessels[count].name);
	printf("\nReport - 2 Do not Report - otherwise : ");
	scanf("%d",&conversing);
	}
	if (conversing==2&&Vessels[count].priorities[3]==2)
	{passprior=Vessels[count].priorities[3];
	printDialogue(count,currentjob[0],passprior);
	resolveJob(currentjob[0],currentjob[1]);
	}
	
	conversing=0;
}printf("\n");inmenu-=1;

	
	}while(inmenu==1);
}
else if(scheduleaction==5) // Use items
{
system("clear");
system("reset");

	//USE ITEMS
int inmenu=0;
int yesno=0;
printf("\nscheduler recieved : 5 - Items \n");


do{
	int findNPC;
	int findNPC2;
	int source;
	int lock=0;
int dest=0;
printf("\nITEMS: who will use? :");
scanf("%d",&findNPC);
count=findNPC;
//case for oob searching needed for user access limitation.
for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[count].inventory[innerloops]!=0)
{
printf("\nITEM %d %s : %d \n",innerloops,items[Vessels[count].inventory[innerloops]].name,Vessels[count].inventory[innerloops]);
}
}printf("\n");

printf("\nITEMS: which item? :");
scanf("%d",&findNPC2);

if (Vessels[findNPC].inventory[findNPC2]!=0)
{
printf("\n Selected ITEM : %d \n", findNPC2);
int source=Vessels[findNPC].inventory[findNPC2];
printItemStats(source);


switch (items[source].type)
{
	case 7:
	Vessels[findNPC].HP+=items[source].offeredValue;
	if (Vessels[findNPC].HP>Vessels[findNPC].maxHP)
	{Vessels[findNPC].HP=Vessels[findNPC].maxHP;	
		}
	Vessels[findNPC].inventory[findNPC2]=0;
	break;
	
	
	case 12:
	Vessels[findNPC].MP+=items[source].offeredValue;
	if (Vessels[findNPC].MP>=Vessels[findNPC].maxMP)
	{Vessels[findNPC].MP=0;Vessels[findNPC].MP+=Vessels[findNPC].maxMP;	
		}Vessels[findNPC].inventory[findNPC2]=0;
		break;
		
	case 13:
	Vessels[findNPC].MP+=items[source].offeredValue;
	if (Vessels[findNPC].MP>=Vessels[findNPC].maxMP)
	{Vessels[findNPC].MP=0;
		Vessels[findNPC].MP+=Vessels[findNPC].maxMP;	
		}
		Vessels[findNPC].HP+=items[source].offeredValue;
	if (Vessels[findNPC].HP>Vessels[findNPC].maxHP)
	{Vessels[findNPC].HP=Vessels[findNPC].maxHP;	
		}Vessels[findNPC].inventory[findNPC2]=0;
		Vessels[findNPC].fatigue-=items[source].offeredValue;
	if (Vessels[findNPC].fatigue>=0)
	{Vessels[findNPC].fatigue=0;	
		}
		break;
	
	case 14:
	Vessels[findNPC].fatigue-=items[source].offeredValue;
	if (Vessels[findNPC].fatigue>=0)
	{Vessels[findNPC].fatigue=0;	
		}
	Vessels[findNPC].inventory[findNPC2]=0;
	break;
	
	
	case 2:	
	
if ((Vessels[findNPC].level>=items[source].levelNeeded)&&(Vessels[findNPC].class==items[source].classRequired))
	{
		Vessels[findNPC].weapon=items[source].offeredValue;
		Vessels[findNPC].checkitem[0]=findNPC2;
	printf("attack %d + %d",Vessels[findNPC].attack,Vessels[findNPC].weapon);
}


else if ((Vessels[findNPC].level>=items[source].levelNeeded)&&(items[source].classRequired=='n'))
	{
		Vessels[findNPC].weapon=items[source].offeredValue;
		
		Vessels[findNPC].checkitem[0]=findNPC2;
	
	printf("\nClass or Level Requirements met : Item Equipped.\n");
	printf("Attack Power %d + %d",Vessels[findNPC].attack,Vessels[findNPC].weapon);
}

if ((Vessels[findNPC].level<items[source].levelNeeded)||((Vessels[findNPC].class!=items[source].classRequired)&&(items[source].classRequired!='n')))
{
	printf("\nClass or Level Requirements not met\n");
	}

	break;
		
	
	case 3:	
	
if ((Vessels[findNPC].level>=items[source].levelNeeded)&&(Vessels[findNPC].class==items[source].classRequired))
	{
		Vessels[findNPC].shield=items[source].offeredValue;
		Vessels[findNPC].checkitem[1]=findNPC2;
	printf("defense %d + %d",Vessels[findNPC].defense,Vessels[findNPC].shield);
}


else if ((Vessels[findNPC].level>=items[source].levelNeeded)&&(items[source].classRequired=='n'))
	{
		Vessels[findNPC].shield=items[source].offeredValue;
		Vessels[findNPC].checkitem[1]=findNPC2;
	printf("defense %d + %d",Vessels[findNPC].defense,Vessels[findNPC].shield);
}

if ((Vessels[findNPC].level<items[source].levelNeeded)||((Vessels[findNPC].class!=items[source].classRequired)&&(items[source].classRequired!='n')))
{
	printf("\nClass or Level Requirements not met\n");
	}


	break;
	

	case 15:	
	
if ((Vessels[findNPC].Affs[5]>=items[source].affRequired)&&(Vessels[findNPC].level>=items[source].levelNeeded)&&(Vessels[findNPC].class==items[source].classRequired))
	{
		for(dest=0;dest<=511;dest++)
		{
			if(Vessels[findNPC].SkillsUnlocked[dest]!=items[source].offeredValue)
			{lock=1;dest=511;}
			
			
			if(Vessels[findNPC].SkillsUnlocked[dest]==items[source].offeredValue)
			{lock=2;dest=511;}
			
			}
		
		if (lock==1)
		{
		printf("You may learn this spell\n");
		printf("1 - Learn x - Do not Learn\n");
		scanf("%d",&yesno);
		
		switch(yesno)
		{
			case 1:
			printf("Learned %s\n",skills[items[source].offeredValue].name);
			
			
			Vessels[findNPC].SkillsUnlocked[items[source].offeredValue]=1;
				
		for(dest=0;dest<=511;dest++)
		{	
			if(Vessels[findNPC].inventory[dest]==source)
			{Vessels[findNPC].inventory[dest]=0;dest=511;}
	}
			
			break;
			default:
			break;
			}
		
		
}


else if (lock==2)
		{
		printf("You have already Learned this spell...\n");
}



yesno=0;
}



if ((Vessels[findNPC].level<items[source].levelNeeded)||((Vessels[findNPC].class!=items[source].classRequired)&&(items[source].classRequired!='n')))
{
	printf("\nClass or Level Requirements not met\n");
	}


	break;
	
	
	case 5:	
	printf("Water Held %d",items[findNPC].quantity);
//ask player if they would like to use a water from the container
//offerevalue-- until  container is empty and is not a keyItem then destory it.

	break;
//switch case by item type lookup for application/removal.//
//
default:
break;
}
}
	inmenu-=1;
	}while(inmenu==1);
}
else if(scheduleaction==6) // craft
{
system("clear");
system("reset");


int inmenu=0;
printf("\nscheduler recieved : 6 - Crafting \n");

	do{printf("\nWho will Craft? : ");
		scanf("%d",&theChef);}while(theChef>maxparty);
	for(cookables=0;cookables<=255;cookables++)
	{
		switch(Vessels[theChef].RecipesUnlocked[cookables])
		{
				
		case 1:
		if (recipes[cookables].type==4){
		printf("\n %d %s %d ingredient 1: %s %d ingredient 2: %s %d \n",cookables,recipes[cookables].name,recipes[cookables].quantity,items[recipes[cookables].drainedValue].name,recipes[cookables].drainedValue,items[recipes[cookables].drainedValue2].name,recipes[cookables].drainedValue2);
		}
			
		break;
		case 0:
			
		break;
		
		default:
			
		break;
		
		
	}
		}
			do{scanf("%d",&theMeal);}while((Vessels[theChef].RecipesUnlocked[theMeal]!=1)||(recipes[theMeal].type!=4));
			printf("\n%s selected\n",recipes[theMeal].name);
	
	int validingredient1=0;
	int validingredient2=0;

for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[theChef].inventory[innerloops]==recipes[theMeal].drainedValue2)
{
printf("\nFound Material 2: %d %s : %d \n",innerloops,items[Vessels[theChef].inventory[innerloops]].name,Vessels[theChef].inventory[innerloops]);
validingredient2+=innerloops;
innerloops=512;
}
}printf("\n");


for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[theChef].inventory[innerloops]==recipes[theMeal].drainedValue)
{
printf("\nFound Material 1: %d %s : %d \n",innerloops,items[Vessels[theChef].inventory[innerloops]].name,Vessels[theChef].inventory[innerloops]);
validingredient1+=innerloops;
innerloops=512;
}
}

	
	if (validingredient1==0||validingredient2==0)
	{
	printf("Not enough Materials!!");
	inmenu-=1;
}
	
	else if ((validingredient1!=0)&&(validingredient2!=0))
	{
		
	printf("%s has enough Ingredients.\n",Vessels[theChef].name);
printf("Ing 1: %d, Ing 2: %d!!",validingredient1,validingredient2);
	printf("Will you Craft? 0 - yes 1- no : ");
	
	
	int willmake=2;
	do{scanf("%d",&willmake);}while(willmake==2);
	
	if (willmake==0)
	{willmake=2;
		printf("\n%s was Made\n",recipes[theMeal].name);
		Vessels[theChef].inventory[validingredient2]=0;
		Vessels[theChef].inventory[validingredient1]=recipes[theMeal].offeredValue;		
		Vessels[theChef].Affs[2]+=0.005;
		printf("\nCRAFT: %.3f",Vessels[theChef].Affs[2]);
		inmenu-=1;
		}
	
	else if (willmake==1)
	{willmake=2;
		printf("\n%s did not Craft anything...\n",Vessels[theChef].name);
		inmenu-=1;
		}
	

	
	
	
	}while(inmenu==1);
}
//End schedule 6//
else if(scheduleaction==7) // smith
{
system("clear");
system("reset");

int inmenu=0;
printf("\nscheduler recieved : 7 - Smithing \n");

	do{printf("\nWho will Smith? : ");
		scanf("%d",&theChef);}while(theChef>maxparty);
	for(cookables=0;cookables<=255;cookables++)
	{
		switch(Vessels[theChef].RecipesUnlocked[cookables])
		{
				
		case 1:
		if (recipes[cookables].type==2){
		printf("\n %d %s %d ingredient 1: %s %d ingredient 2: %s %d \n",cookables,recipes[cookables].name,recipes[cookables].quantity,items[recipes[cookables].drainedValue].name,recipes[cookables].drainedValue,items[recipes[cookables].drainedValue2].name,recipes[cookables].drainedValue2);
		}
			
		break;
		case 0:
			
		break;
		
		default:
			
		break;
		
		
	}
		}
			do{scanf("%d",&theMeal);}while((Vessels[theChef].RecipesUnlocked[theMeal]!=1)||(recipes[theMeal].type!=2));
			printf("\n%s selected\n",recipes[theMeal].name);
	
	int validingredient1=0;
	int validingredient2=0;

for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[theChef].inventory[innerloops]==recipes[theMeal].drainedValue2)
{
printf("\nFound Material 2: %d %s : %d \n",innerloops,items[Vessels[theChef].inventory[innerloops]].name,Vessels[theChef].inventory[innerloops]);
validingredient2+=innerloops;
innerloops=512;
}
}printf("\n");


for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[theChef].inventory[innerloops]==recipes[theMeal].drainedValue)
{
printf("\nFound Material 1: %d %s : %d \n",innerloops,items[Vessels[theChef].inventory[innerloops]].name,Vessels[theChef].inventory[innerloops]);
validingredient1+=innerloops;
innerloops=512;
}
}


	
	if (validingredient1==0||validingredient2==0)
	{
	printf("Not enough Ingredients!!");
	inmenu-=1;
}
	
	else if ((validingredient1!=0)&&(validingredient2!=0))
	{
		
	printf("%s has enough Ingredients.\n",Vessels[theChef].name);
printf("Ing 1: %d, Ing 2: %d!!",validingredient1,validingredient2);
	printf("Will you Smith? 0 - yes 1- no : ");
	
	
	int willmake=2;
	do{scanf("%d",&willmake);}while(willmake==2);
	
	if (Vessels[theChef].Affs[15]<recipes[theMeal].affRequired)
	{willmake=3;}
	
	if (willmake==0)
	{willmake=2;
		printf("\n%s was Made\n",recipes[theMeal].name);
		Vessels[theChef].inventory[validingredient2]=0;
		Vessels[theChef].inventory[validingredient1]=recipes[theMeal].offeredValue;		
		Vessels[theChef].Affs[15]+=0.005;
		printf("AFF: %.3f",Vessels[theChef].Affs[15]);
		inmenu-=1;
		}
	
	
	if (willmake==3)
	{
		printf("\nCannot Make: %s\n",recipes[theMeal].name);
		printf("\nSMITH Affinity: %.3f or higher needed.\n",recipes[theMeal].affRequired);
		
		inmenu-=1;
		}
	
	else if (willmake==1)
	{willmake=2;
		printf("\n%s did not Smith anything...\n",Vessels[theChef].name);
		inmenu-=1;
		}
	

	
	
	
	}while(inmenu==1);
}
//End schedule 7//
else if(scheduleaction==8) //cook
{
system("clear");
system("reset");

int inmenu=0;
inmenu=1;
printf("\nscheduler recieved : 8 - Cooking \n");
do{
	do{printf("\nWho will Cook? : ");
		scanf("%d",&theChef);}while(theChef>maxparty);
	for(cookables=0;cookables<=255;cookables++)
	{
		switch(Vessels[theChef].RecipesUnlocked[cookables])
		{
		case 1:
		if (recipes[cookables].type==7){
		printf("\n %d %s %d ingredient 1: %s %d ingredient 2: %s %d \n",cookables,recipes[cookables].name,recipes[cookables].quantity,items[recipes[cookables].drainedValue].name,recipes[cookables].drainedValue,items[recipes[cookables].drainedValue2].name,recipes[cookables].drainedValue2);
		}
			
		break;
		case 0:
			
		break;
		
		default:
			
		break;
		
		
	}
		}
			do{scanf("%d",&theMeal);}while(Vessels[theChef].RecipesUnlocked[theMeal]!=1);
			printf("\n%s selected\n",recipes[theMeal].name);
	
	int validingredient1=0;
	int validingredient2=0;

for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[theChef].inventory[innerloops]==recipes[theMeal].drainedValue2)
{
printf("\nfOUND iNGREDIENT 2: %d %s : %d \n",innerloops,items[Vessels[theChef].inventory[innerloops]].name,Vessels[theChef].inventory[innerloops]);
validingredient2+=innerloops;
innerloops=512;
}
}printf("\n");


for (innerloops=0;innerloops<=511;innerloops+=1)
{
if(Vessels[theChef].inventory[innerloops]==recipes[theMeal].drainedValue)
{
printf("\nfOUND iNGREDIENT 1: %d %s : %d \n",innerloops,items[Vessels[theChef].inventory[innerloops]].name,Vessels[theChef].inventory[innerloops]);
validingredient1+=innerloops;
innerloops=512;
}
}

	
	if (validingredient1==0||validingredient2==0)
	{
	printf("Not enough Ingredients!!");
	inmenu-=1;
}
	
	else if ((validingredient1!=0)&&(validingredient2!=0))
	{
		
	printf("%s has enough Ingredients.\n",Vessels[theChef].name);
printf("Ing 1: %d, Ing 2: %d!!",validingredient1,validingredient2);
	printf("Will you Cook The Meal? 0 - yes 1- no : ");
	
	
	int willmake=2;
	do{scanf("%d",&willmake);}while(willmake==2);
	
	if (willmake==0)
	{willmake=2;
		printf("\n%s was Made\n",recipes[theMeal].name);
		Vessels[theChef].inventory[validingredient2]=0;
		Vessels[theChef].inventory[validingredient1]=recipes[theMeal].offeredValue;		
		Vessels[theChef].Affs[13]+=0.005;
		inmenu-=1;
		}
	
	else if (willmake==1)
	{willmake=2;
		printf("\n%s did not Cook anything...\n",Vessels[theChef].name);
		inmenu-=1;
		}
	

	
	inmenu-=1;
}
	
	
	
	}while(inmenu==1);
}

else if((scheduleaction==0)&&(Vessels[0].fatigue<=0))
{printf("scheduler recieved 0 - Player is fully Rested...\n");	
	//Vessels[0].HP=Vessels[0].maxHP;
	for (count=0;count<maxparty+1;count++)
	{
	Vessels[count].HP+=50;
	if (Vessels[count].HP>Vessels[count].maxHP)
	{Vessels[count].HP=0; Vessels[count].HP+=Vessels[count].maxHP;}
	
	Vessels[count].MP+=40;
	
	if (Vessels[count].MP>Vessels[count].maxMP)
	{Vessels[count].MP=0; Vessels[count].MP+=Vessels[count].maxMP;}
}
	quarterspassed+=1;
	if(quarterspassed>24)
	{quarterspassed=0;
		dayspassed+=1;
		}
	
	}

}while((quit!=1)&&(Vessels[0].HP>=1)&&(scheduleaction!=22));

return 0;


}
