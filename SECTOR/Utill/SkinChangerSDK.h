#pragma once

namespace SkinChangerSDK
{
	namespace Gun
	{
		short P2000 = 0;
		short USP_S = 0;
		short Glock = 0;
		short Dual_Berettas = 0;
		short P250 = 0;
		short Tec_9 = 0;
		short CZ75_Auto = 0;
		short Desert_Eagle = 0;
		short Five_SeveN = 0;
		short R8 = 0;
		short Nova = 0;
		short XM1014 = 0;
		short MAG_7 = 0;
		short M249 = 0;
		short Negev = 0;
		short Sawed_Off = 0;
		short MAC_10 = 0;
		short MP5_SD = 0;
		short UMP_45 = 0;
		short P90 = 0;
		short PP_19 = 0;
		short MP9 = 0;
		short MP7 = 0;
		short FAMAS = 0;
		short M4A4 = 0;
		short M4A1_S = 0;
		short SSG_08 = 0;
		short AUG = 0;
		short AWP = 0;
		short SCAR_20 = 0;
		short Galil = 0;
		short AK_47 = 0;
		short SG_553 = 0;
		short C3SG1 = 0;
	}


	int GetWeaponSkin(int weapon_id)
	{
		switch (weapon_id)
		{
			case 32: return Gun::P2000;
			case 61: return Gun::USP_S;
			case 4: return Gun::Glock;
			case 2: return Gun::Dual_Berettas;
			case 36: return Gun::P250;
			case 30: return Gun::Tec_9;
			case 63: return Gun::CZ75_Auto;
			case 1: return Gun::Desert_Eagle;
			case 3: return Gun::Five_SeveN;
			case 64: return Gun::R8;
			case 35: return Gun::Nova;
			case 25: return Gun::XM1014;
			case 27: return Gun::MAG_7;
			case 14: return Gun::M249;
			case 28: return Gun::Negev;
			case 29: return Gun::Sawed_Off;
			case 17: return Gun::MAC_10;
			case 23: return Gun::MP5_SD;
			case 24: return Gun::UMP_45;
			case 19: return Gun::P90;
			case 26: return Gun::PP_19;
			case 34: return Gun::MP9;
			case 33: return Gun::MP7;
			case 10: return Gun::FAMAS;
			case 16: return Gun::M4A4;
			case 60: return Gun::M4A1_S;
			case 40: return Gun::SSG_08;
			case 8: return Gun::AUG;
			case 9: return Gun::AWP;
			case 38: return Gun::SCAR_20;
			case 13: return Gun::Galil;
			case 7: return Gun::AK_47;
			case 39: return Gun::SG_553;
			case 11: return Gun::C3SG1;
			default: return 0;
		}
	}


	namespace GunList
	{
		int ActiveItem = 0;


		static const char* AllGunList[] = { "P2000", "USP-S", "Glock", "Dual Berettas", "P250", "Tec-9", "CZ75-Auto", "Desert Eagle", "Five-SeveN", "R8", "Nova", "XM1014", "Mag-7",
									"M249", "Negev", "Sawed-Off", "MAC-10", "MP5-SD", "UMP-45", "P90", "PP-19", "MP9", "MP7", "FAMAS", "M4A4", "M4A1-S", "SSG-08", "AUG",
									"AWP", "SCAR-20", "Galil", "AK-47", "SG 553", "C3SG1" };


		namespace P2000
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Granite Marbleized ", "Silver ", "Scorpion ", "Grassland ", "Grassland Leaves ", "Corticera ", "Ocean Foam ", "Amber Fade ", "Red Fragcam ", "Chainmail ", "Pulse ", "Coach Class ", "Ivory ", "Fire Elemental ", "Pathfinder ", "Handgun ", "Imperial ", "Oceanic ", "Imperial Dragon ", "Turf ", "Woodsman ", "Urban Hazard ", "Obsidian ", "Acid Etched ", "Gnarled ", "Dispatch ", "Panther Camo ", "Space Race ", "Lifted Spirits " };
			int SkinIndex[] = { 21,  32,  71,  95,  104,  184,  211,  246,  275,  327,  338,  346,  357,  389,  443,  485,  515,  550,  591,  635,  667,  700,  894,  951,  960,  997,  1019,  1055,  113 };
		}


		namespace USP_S
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Forest Leaves ", "Dark Water ", "Overgrowth ", "Blood Tiger ", "Serum ", "Night Ops ", "Stainless ", "Guardian ", "Orion ", "Road Rash ", "Royal Blue ", "Caiman ", "Business Class ", "Pathfinder ", "Para Green ", "Torque ", "Kill Confirmed ", "Lead Conduit ", "Cyrex ", "Neonoir ", "Blueprint ", "Cortex ", "Check Engine ", "Flashback ", "Orange Anolis ", "Monster Mashup ", "Target Acquired ", "Ancient Visions ", "The Traitor ", "Whiteout ", "Black Lotus ", "Ticket To Hell " };
			int SkinIndex[] = { 25,  60,  183,  217,  221,  236,  277,  290,  313,  318,  332,  339,  364,  443,  454,  489,  504,  540,  637,  653,  657,  705,  796,  817,  922,  991,  1027,  1031,  1040,  1065,  1102,  1136 };
		}


		namespace Glock
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Groundwater ", "Fade ", "Night ", "Dragon Tattoo ", "Pink Ddpat ", "Brass ", "Sand Dune ", "Steel Disruption ", "Blue Fissure ", "Death Rattle ", "Water Elemental ", "Reactor ", "Grinder ", "Catacombs ", "Twilight Galaxy ", "Bunsen Burner ", "Wraiths ", "Royal Legion ", "Wasteland Rebel ", "Weasel ", "Ironwork ", "Off World ", "Moonrise ", "Warhawk ", "Synth Leaf ", "Nuclear Garden ", "High Beam ", "Oxide Blaze ", "Sacrifice ", "Bullet Queen ", "Vogue ", "Neonoir ", "Franklin ", "Clear Polymer ", "Red Tire ", "Snack Attack ", "Gamma Doppler Emerald " };
			int SkinIndex[] = { 2,  38,  40,  48,  84,  159,  208,  230,  278,  293,  353,  367,  381,  399,  437,  479,  495,  532,  586,  607,  623,  680,  694,  713,  732,  789,  799,  808,  918,  957,  963,  988,  1016,  1039,  1079,  1100,  1119 };
		}


		namespace Dual_Berettas
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Anodized Navy ", "Stained ", "Contractor ", "Demolition ", "Black Limba ", "Hemoglobin ", "Cobalt Quartz ", "Marina ", "Panther ", "Retribution ", "Briar ", "Urban Shock ", "Duelist ", "Moon In Libra ", "Emerald Emerald ", "Dualing Dragons ", "Cartel ", "Ventilators ", "Royal Consorts ", "Cobra Strike ", "Shred ", "Twin Turbo ", "Drift Wood ", "Pyre ", "Balance ", "Elite 16 ", "Dezastre ", "Switch Board ", "Heist ", "Oil Change ", "Tread ", "Melondrama " };
			int SkinIndex[] = { 28,  43,  46,  153,  190,  220,  249,  261,  276,  307,  330,  396,  447,  450,  453,  491,  528,  544,  625,  658,  710,  747,  824,  860,  895,  903,  978,  998,  1005,  1086,  1091,  1126 };
		}


		namespace P250
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Gunsmoke ", "Bone Mask ", "Metallic Ddpat ", "Boreal Forest ", "Sand Dune ", "Whiteout ", "Xray ", "Splash ", "Modern Hunter ", "Nuclear Threat ", "Facets ", "Hive ", "Steel Disruption ", "Mehndi ", "Undertow ", "Franklin ", "Supernova ", "Contamination ", "Cartel ", "Muertos ", "Valence ", "Crimson Kimono ", "Wingshot ", "Asiimov ", "Iron Clad ", "Ripple ", "Red Rock ", "See Ya Later ", "Dark Filigree ", "Vino Primo ", "Facility Draft ", "Exchanger ", "Nevermore ", "Drought ", "Verdigris ", "Inferno ", "Black Tan ", "Cassette ", "Contaminant ", "Bengal Tiger ", "Cyber Shell ", "Digital Architect " };
			int SkinIndex[] = { 15,  27,  34,  77,  99,  102,  125,  162,  164,  168,  207,  219,  230,  258,  271,  295,  358,  373,  388,  404,  426,  466,  501,  551,  592,  650,  668,  678,  741,  749,  777,  786,  813,  825,  848,  907,  928,  968,  982,  1030,  1044,  1081 };
		}


		namespace Tec_9
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Groundwater ", "Urban Ddpat ", "Ossified ", "Brass ", "Nuclear Threat ", "Tornado ", "Blue Titanium ", "Varicamo ", "Army Mesh ", "Red Quartz ", "Titanium Bit ", "Sandstorm ", "Isaac ", "Toxic ", "Hades ", "Bamboo Forest ", "Terrace ", "Avalanche ", "Jambiya ", "Reentry ", "Ice Cap ", "Fuel Injector ", "Cut Out ", "Cracked Opal ", "Snek9 ", "Rust Leaf ", "Orange Murano ", "Remote Control ", "Safety Net ", "Fubar ", "Bamboozle ", "Decimator ", "Flash Out ", "Brother ", "Phoenix Chalk ", "Blast From The Past " };
			int SkinIndex[] = { 2,  17,  36,  159,  179,  206,  216,  235,  242,  248,  272,  289,  303,  374,  439,  459,  463,  520,  539,  555,  599,  614,  671,  684,  722,  733,  738,  791,  795,  816,  839,  889,  905,  964,  1010,  1024 };
		}


		namespace CZ75_Auto
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Crimson Web ", "Silver ", "Jungle Dashed ", "Hexane ", "Tread Plate ", "Tuxedo ", "Poison Dart ", "Nitro ", "Chalice ", "Indigo ", "Tigris ", "Green Plaid ", "Pole Position ", "Emerald Emerald ", "Yellow Jacket ", "Red Astor ", "Imprint ", "Polymer ", "Xiangliu ", "Tacticat ", "Eco ", "Emerald Quartz ", "Midnight Palm ", "Distressed ", "Vendetta ", "Circaetus ", "Syndicate ", "Framework " };
			int SkinIndex[] = { 12,  32,  147,  218,  268,  297,  315,  322,  325,  333,  350,  366,  435,  453,  476,  543,  602,  622,  643,  687,  709,  859,  933,  944,  976,  1036,  1064,  1076 };
		}


		namespace Desert_Eagle
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Urban Ddpat ", "Blaze ", "Night ", "Hypnotic ", "Mudder ", "Golden Koi ", "Cobalt Disruption ", "Urban Rubble ", "Heirloom ", "Meteorite ", "Hand Cannon ", "Pilot ", "Conspiracy ", "Naga ", "Bronze Deco ", "Midnight Storm ", "Corinthian ", "Kumicho Dragon ", "Directive ", "Oxide Blaze ", "Code Red ", "Emerald Jrmungandr ", "Fennec Fox ", "Mecha Industries ", "Light Rail ", "Blue Ply ", "Printstream ", "The Bronze ", "Night Heist ", "Trigger Discipline ", "Sputnik ", "Ocean Drive " };
			int SkinIndex[] = { 17,  37,  40,  61,  90,  185,  231,  237,  273,  296,  328,  347,  351,  397,  425,  468,  509,  527,  603,  645,  711,  757,  764,  805,  841,  945,  962,  992,  1006,  1050,  1056,  1090 };
		}


		namespace Five_SeveN
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Candy Apple ", "Case Hardened ", "Contractor ", "Forest Night ", "Orange Peel ", "Jungle ", "Anodized Gunmetal ", "Nightshade ", "Silver Quartz ", "Nitro ", "Kami ", "Copper Galaxy ", "Fowl Play ", "Hot Shot ", "Urban Hazard ", "Monkey Business ", "Neon Kimono ", "Retrobution ", "Triumvirate ", "Violent Daimyo ", "Scumbria ", "Capillary ", "Hyper Beast ", "Flame Test ", "Crimson Blossom ", "Coolant ", "Angry Mob ", "Buddy ", "Withered Vine ", "Fairy Tale ", "Berries And Cherries ", "Fall Hazard ", "Boost Protocol ", "Scrawl " };
			int SkinIndex[] = { 3,  44,  46,  78,  141,  151,  210,  223,  252,  254,  265,  274,  352,  377,  387,  427,  464,  510,  530,  585,  605,  646,  660,  693,  729,  784,  837,  906,  932,  979,  1002,  1082,  1093,  1128 };
		}


		namespace R8
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Crimson Web ", "Bone Mask ", "Blaze ", "Night ", "Fade ", "Reboot ", "Llama Cannon ", "Grip ", "Survivalist ", "Nitro ", "Skull Crusher ", "Canal Spray ", "Memento ", "Desert Brush ", "Bone Forged ", "Phoenix Marker ", "Junk Yard " };
			int SkinIndex[] = { 12,  27,  37,  40,  522,  595,  683,  701,  721,  798,  843,  866,  892,  924,  952,  1011,  1047 };
		}


		namespace Nova
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Candy Apple ", "Forest Leaves ", "Bloomstick ", "Sand Dune ", "Polar Mesh ", "Walnut ", "Modern Hunter ", "Blaze Orange ", "Predator ", "Tempest ", "Graphite ", "Ghost Camo ", "Red Quartz ", "Rising Skull ", "Antique ", "Green Apple ", "Army Sheen ", "Rust Coat ", "Koi ", "Moon In Libra ", "Ranger ", "Hyper Beast ", "Exo ", "Gila ", "Wild Six ", "Toy Soldier ", "Baroque Orange ", "Mandrel ", "Wood Fired ", "Plume ", "Quick Sand ", "Clear Polymer ", "Windblown ", "Interlock " };
			int SkinIndex[] = { 3,  25,  62,  99,  107,  158,  164,  166,  170,  191,  214,  225,  248,  263,  286,  294,  298,  323,  356,  450,  484,  537,  590,  634,  699,  716,  746,  785,  809,  890,  929,  987,  1051,  1077 };
		}


		namespace XM1014
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Blue Steel ", "Grassland ", "Urban Perforated ", "Blaze Orange ", "Fallout Warning ", "Jungle ", "Varicamo Blue ", "Calicamo ", "Heaven Guard ", "Red Python ", "Red Leather ", "Bone Machine ", "Tranquility ", "Quicksilver ", "Scumbria ", "Teclu Burner ", "Black Tie ", "Slipstream ", "Seasons ", "Ziggy ", "Oxide Blaze ", "Banana Leaf ", "Frost Borre ", "Elegant Vines ", "Incinegator ", "Entombed ", "Charter ", "Ancient Lore ", "Xoxo ", "Blue Tire ", "Watchdog ", "Zombie Offensive " };
			int SkinIndex[] = { 42,  95,  135,  166,  169,  205,  238,  240,  314,  320,  348,  370,  393,  407,  505,  521,  557,  616,  654,  689,  706,  731,  760,  821,  850,  970,  994,  1021,  1046,  1078,  1103,  1135 };
		}


		namespace MAG_7
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Silver ", "Metallic Ddpat ", "Bulldozer ", "Carbon Fiber ", "Sand Dune ", "Irradiated Alert ", "Memento ", "Hazard ", "Heaven Guard ", "Chainmail ", "Firestarter ", "Heat ", "Counter Terrace ", "Seabird ", "Cobalt Core ", "Praetorian ", "Petroglyph ", "Sonar ", "Hard Water ", "Swag7 ", "Cinquedea ", "Rust Coat ", "Core Breach ", "Navy Sheen ", "Popdog ", "Justice ", "Monster Call ", "Prism Terrace ", "Bi83 Spectrum ", "Foresight " };
			int SkinIndex[] = { 32,  34,  39,  70,  99,  171,  177,  198,  291,  327,  385,  431,  462,  473,  499,  535,  608,  633,  666,  703,  737,  754,  787,  822,  909,  948,  961,  1072,  1089,  1132 };
		}


		namespace M249
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Contrast Spray ", "Blizzard Marbleized ", "Jungle ", "Predator ", "Jungle Ddpat ", "Gator Mesh ", "Magma ", "System Lock ", "Shipping Forecast ", "Impact Drill ", "Nebula Crusader ", "Spectre ", "Emerald Poison Dart ", "Humidor ", "Warbird ", "Aztec ", "Midnight Palm ", "Deep Relief ", "Osipr " };
			int SkinIndex[] = { 22,  75,  151,  170,  202,  243,  266,  401,  452,  472,  496,  547,  648,  827,  900,  902,  933,  983,  1042 };
		}


		namespace Negev
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Anodized Navy ", "Palm ", "Calicamo ", "Terrain ", "Army Sheen ", "Bratatat ", "Desertstrike ", "Nuclear Waste ", "Manowar ", "Loudmouth ", "Power Loader ", "Dazzle ", "Lionfish ", "Mjlnir ", "Bulkhead ", "Boroque Sand ", "Prototype ", "Ultralight ", "Phoenix Stencil ", "Dev Texture ", "Infrastructure " };
			int SkinIndex[] = { 28,  201,  240,  285,  298,  317,  355,  369,  432,  483,  514,  610,  698,  763,  783,  920,  950,  958,  1012,  1043,  1080 };
		}


		namespace Sawed_Off
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Forest Ddpat ", "Snake Camo ", "Copper ", "Orange Ddpat ", "Sage Spray ", "Irradiated Alert ", "Mosaico ", "Amber Fade ", "Full Stop ", "The Kraken ", "Rust Coat ", "First Class ", "Highwayman ", "Serenity ", "Origami ", "Bamboo Shadow ", "Yorick ", "Fubar ", "Limelight ", "Wasteland Princess ", "Zander ", "Morris ", "Devourer ", "Brake Light ", "Black Sand ", "Jungle Thicket ", "Parched ", "Apocalypto ", "Clay Ambush ", "Spirit Board " };
			int SkinIndex[] = { 5,  30,  41,  83,  119,  171,  204,  246,  250,  256,  323,  345,  390,  405,  434,  458,  517,  552,  596,  638,  655,  673,  720,  797,  814,  870,  880,  953,  1014,  1140 };
		}


		namespace MAC_10
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Candy Apple ", "Urban Ddpat ", "Silver ", "Fade ", "Case Hardened ", "Ultraviolet ", "Tornado ", "Palm ", "Graven ", "Amber Fade ", "Heat ", "Curse ", "Indigo ", "Tatter ", "Commuter ", "Nuclear Garden ", "Malachite ", "Neon Rider ", "Rangeen ", "Lapis Gator ", "Carnivore ", "Last Dive ", "Aloha ", "Oceanic ", "Red Filigree ", "Calf Skin ", "Copper Borre ", "Pipe Down ", "Sienna Damask ", "Whitefish ", "Surfwood ", "Stalker ", "Classic Crate ", "Disco Tech ", "Allure ", "Hot Snakes ", "Gold Brick ", "Button Masher ", "Propaganda ", "Strats ", "Toybox ", "Ensnared " };
			int SkinIndex[] = { 3,  17,  32,  38,  44,  98,  101,  157,  188,  246,  284,  310,  333,  337,  343,  372,  402,  433,  498,  534,  589,  651,  665,  682,  742,  748,  761,  812,  826,  840,  871,  898,  908,  947,  965,  1009,  1025,  1045,  1067,  1075,  1098,  1131 };
		}


		namespace UMP_45
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Gunsmoke ", "Urban Ddpat ", "Blaze ", "Carbon Fiber ", "Mudder ", "Caramel ", "Fallout Warning ", "Scorched ", "Bone Pile ", "Full Stop ", "Corporal ", "Indigo ", "Labyrinth ", "Delusion ", "Grand Prix ", "Minotaurs Labyrinth ", "Riot ", "Primal Saber ", "Briefing ", "Scaffold ", "Metal Flowers ", "Exposure ", "Arctic Wolf ", "Day Lily ", "Facility Dark ", "Momentum ", "Moonrise ", "Fade ", "Plastique ", "Gold Bismuth ", "Crime Scene ", "Houndstooth ", "Oscillator ", "Mechanism " };
			int SkinIndex[] = { 15,  17,  37,  70,  90,  93,  169,  175,  193,  250,  281,  333,  362,  392,  436,  441,  488,  556,  615,  652,  672,  688,  704,  725,  778,  802,  851,  879,  916,  990,  1003,  1008,  1049,  1085 };
		}


		namespace P90
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Virus ", "Cold Blooded ", "Storm ", "Glacier Mesh ", "Sand Spray ", "Death By Kitty ", "Fallout Warning ", "Scorched ", "Emerald Dragon ", "Blind Spot ", "Ash Wood ", "Teardown ", "Trigon ", "Desert Warfare ", "Module ", "Leather ", "Asiimov ", "Elite Build ", "Shapewood ", "Chopper ", "Grim ", "Shallow Grave ", "Death Grip ", "Traction ", "Sunset Lily ", "Baroque Red ", "Astral Jrmungandr ", "Facility Negative ", "Verdant Growth ", "Off World ", "Nostalgia ", "Desert Ddpat ", "Freight ", "Cocoa Rampage ", "Run And Hide ", "Tiger Pit ", "Ancient Earth ", "Schematic " };
			int SkinIndex[] = { 20,  67,  100,  111,  124,  156,  169,  175,  182,  228,  234,  244,  283,  311,  335,  342,  359,  486,  516,  593,  611,  636,  669,  717,  726,  744,  759,  776,  828,  849,  911,  925,  969,  977,  1000,  1015,  1020,  1074 };
		}


		namespace PP_19
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Candy Apple ", "Blue Streak ", "Forest Leaves ", "Carbon Fiber ", "Sand Dashed ", "Brass ", "Modern Hunter ", "Irradiated Alert ", "Rust Coat ", "Water Sigil ", "Night Ops ", "Cobalt Halftone ", "Death Rattle ", "Antique ", "Osiris ", "Chemical Green ", "Bamboo Print ", "Fuel Rod ", "Photic Zone ", "Judgement Of Anubis ", "Harvester ", "Jungle Slipstream ", "High Roller ", "Night Riot ", "Facility Sketch ", "Anolis ", "Seabird ", "Embargo ", "Runic ", "Breaker Box ", "Lumen ", "Space Cat " };
			int SkinIndex[] = { 3,  13,  25,  70,  148,  159,  164,  171,  203,  224,  236,  267,  293,  306,  349,  376,  457,  508,  526,  542,  594,  641,  676,  692,  775,  829,  873,  884,  973,  1083,  1099,  1125 };
		}


		namespace MP9
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Hot Rod ", "Bulldozer ", "Hypnotic ", "Storm ", "Orange Peel ", "Sand Dashed ", "Dry Season ", "Rose Iron ", "Army Sheen ", "Dark Age ", "Green Plaid ", "Setting Sun ", "Dart ", "Deadly Poison ", "Pandoras Box ", "Ruby Poison Dart ", "Bioleak ", "Airlock ", "Sand Scale ", "Goo ", "Black Sand ", "Capillary ", "Wild Lily ", "Slide ", "Modest Threat ", "Music Box ", "Stained Glass ", "Hydra ", "Old Roots ", "Food Chain ", "Mount Fuji ", "Starlight Protector " };
			int SkinIndex[] = { 33,  39,  61,  100,  141,  148,  199,  262,  298,  329,  366,  368,  386,  403,  448,  482,  549,  609,  630,  679,  697,  715,  734,  755,  804,  820,  867,  910,  931,  1037,  1094,  1134 };
		}


		namespace MP7
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Forest Ddpat ", "Skulls ", "Gunsmoke ", "Anodized Navy ", "Whiteout ", "Orange Peel ", "Scorched ", "Groundwater ", "Ocean Foam ", "Army Recon ", "Full Stop ", "Urban Hazard ", "Olive Plaid ", "Armor Core ", "Asterion ", "Nemesis ", "Special Delivery ", "Impire ", "Cirrus ", "Akoben ", "Bloodsport ", "Powercore ", "Teal Blossom ", "Fade ", "Motherboard ", "Mischief ", "Neon Ply ", "Prey ", "Vault Heist ", "Tall Grass ", "Guerrilla ", "Abyssal Apparition " };
			int SkinIndex[] = { 5,  11,  15,  28,  102,  141,  175,  209,  213,  245,  250,  354,  365,  423,  442,  481,  500,  536,  627,  649,  696,  719,  728,  752,  782,  847,  893,  935,  1007,  1023,  1096,  1133 };
		}


		namespace FAMAS
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Contrast Spray ", "Colony ", "Dark Water ", "Cyanospatter ", "Afterimage ", "Doomkitty ", "Spitfire ", "Hexane ", "Calicamo ", "Teardown ", "Pulse ", "Sergeant ", "Styx ", "Djinn ", "Neural Net ", "Survivor Z ", "Valence ", "Roll Cage ", "Mecha Industries ", "Macabre ", "Eye Of Athena ", "Crypsis ", "Night Borre ", "Sundown ", "Decommissioned ", "Commemoration ", "Prime Conspiracy ", "Meltdown ", "Faulty Wiring ", "Zx Spectron ", "Rapid Eye Movement " };
			int SkinIndex[] = { 22,  47,  60,  92,  154,  178,  194,  218,  240,  244,  260,  288,  371,  429,  477,  492,  529,  604,  626,  659,  723,  835,  863,  869,  904,  919,  999,  1053,  1066,  1092,  1127 };
		}


		namespace MP5_SD
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Dirt Drop ", "Coprocessor ", "Nitro ", "Lab Rats ", "Phosphor ", "Gauss ", "Bamboo Garden ", "Acid Wash ", "Agent ", "Oxide Oasis ", "Desert Strike ", "Kitbash ", "Condition Zero ", "Autumn Twilly ", "Necro Jr " };
			int SkinIndex[] = { 753,  781,  798,  800,  810,  846,  872,  888,  915,  923,  949,  974,  986,  1061,  1137 };
		}


		namespace M4A4
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Desert Storm ", "Jungle Tiger ", "Tornado ", "Bullet Rain ", "Modern Hunter ", "Radiation Hazard ", "Faded Zebra ", "Zirka ", "Xray ", "Asiimov ", "Howl ", "Desertstrike ", "Griffin ", " Dragon King ", "Poseidon ", "Daybreak ", "Evil Daimyo ", "Royal Paladin ", "The Battlestar ", "Desolate Space ", "Buzz Kill ", "Hellfire ", "Neonoir ", "Dark Blossom ", "Mainframe ", "Converter ", "Magnesium ", "The Emperor ", "Red Ddpat ", "Tooth Fairy ", "Cyber Security ", "Global Offensive ", "In Living Color ", "The Coalition ", "Spider Lily " };
			int SkinIndex[] = { 8,  16,  101,  155,  164,  167,  176,  187,  215,  255,  309,  336,  384,  400,  449,  471,  480,  512,  533,  588,  632,  664,  695,  730,  780,  793,  811,  844,  926,  971,  985,  993,  1041,  1063,  1097 };
		}


		namespace M4A1_S
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Dark Water ", "Boreal Forest ", "Bright Water ", "Blood Tiger ", "Varicamo ", "Nitro ", "Guardian ", "Atomic Alloy ", "Master Piece ", "Knight ", "Cyrex ", "Basilisk ", "Hyper Beast ", "Icarus Fell ", "Hot Rod ", "Golden Coil ", "Chanticos Fire ", "Mecha Industries ", "Flashback ", "Decimator ", "Briefing ", "Leaded Glass ", "Nightmare ", "Control Panel ", "Moss Quartz ", "Player Two ", "Printstream ", "Welcome To The Jungle ", "Blue Phosphor ", "Fizzy Pop ", "Imminent Danger ", "Night Terror " };
			int SkinIndex[] = { 60,  77,  189,  217,  235,  254,  257,  301,  321,  326,  360,  383,  430,  440,  445,  497,  548,  587,  631,  644,  663,  681,  714,  792,  862,  946,  984,  1001,  1017,  1059,  1073,  1130 };
		}


		namespace SSG_08
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Lichen Dashed ", "Dark Water ", "Carbon Fiber ", "Blue Spruce ", "Sand Dune ", "Jungle Dashed ", "Mayan Dreams ", "Blood In The Water ", "Tropical Storm ", "Acid Fade ", "Slashed ", "Detour ", "Abyss ", "Big Iron ", "Necropos ", "Ghost Crusader ", "Dragonfire ", "Deaths Head ", "Orange Filigree ", "Hand Brake ", "Red Stone ", "Sea Calico ", "Bloodshot ", "Prey ", "Fever Dream ", "Mainframe 001 ", "Parallax ", "Threat Detected ", "Death Strike ", "Spring Twilly ", "Turbo Peek " };
			int SkinIndex[] = { 26,  60,  70,  96,  99,  147,  200,  222,  233,  253,  304,  319,  361,  503,  538,  554,  624,  670,  743,  751,  762,  868,  899,  935,  956,  967,  989,  996,  1052,  1060,  1101 };
		}


		namespace AUG
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Bengal Tiger ", "Hot Rod ", "Contractor ", "Wings ", "Storm ", "Condemned ", "Anodized Navy ", "Amber Fade ", "Chameleon ", "Torque ", "Radiation Hazard ", "Daedalus ", "Akihabara Accept ", "Ricochet ", "Fleet Flock ", "Aristocrat ", "Syd Mead ", "Triqua ", "Stymphalian ", "Amber Slipstream ", "Midnight Lily ", "Navy Murano ", "Flame Jrmungandr ", "Random Access ", "Sweeper ", "Sand Storm ", "Momentum ", "Arctic Wolf ", "Death By Puppy ", "Spalted Wood ", "Tom Cat ", "Surveillance ", "Carved Jade ", "Plague " };
			int SkinIndex[] = { 9,  33,  46,  73,  100,  110,  197,  246,  280,  305,  375,  444,  455,  507,  541,  583,  601,  674,  690,  708,  727,  740,  758,  779,  794,  823,  845,  886,  913,  927,  942,  995,  1033,  1088 };
		}


		namespace AWP
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Snake Camo ", "Lightning Strike ", "Safari Mesh ", "Pink Ddpat ", "Boom ", "Corticera ", "Graphite ", "Electric Hive ", "Pit Viper ", "Redline ", "Asiimov ", "Dragon Lore ", "Manowar ", "Worm God ", "Medusa ", "Sun In Leo ", "Hyper Beast ", "Elite Build ", "Phobos ", "Fever Dream ", "Oni Taiji ", "Mortis ", "Paw ", "The Prince ", "Gungnir ", "Acheron ", "Neonoir ", "Desert Hydra ", "Atheris ", "Containment Breach ", "Wildfire ", "Capillary ", "Exoskeleton ", "Fade ", "Silk Tiger ", "Pop Awp " };
			int SkinIndex[] = { 30,  51,  72,  84,  174,  181,  212,  227,  251,  259,  279,  344,  395,  424,  446,  451,  475,  525,  584,  640,  662,  691,  718,  736,  756,  788,  803,  819,  838,  887,  917,  943,  975,  1026,  1029,  1058 };
		}


		namespace SCAR_20
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Contractor ", "Carbon Fiber ", "Storm ", "Sand Mesh ", "Palm ", "Brass ", "Splash Jam ", "Emerald Emerald ", "Crimson Web ", "Army Sheen ", "Cyrex ", "Cardiac ", "Grotto ", "Green Marine ", "Outbreak ", "Bloodsport ", "Powercore ", "Blueprint ", "Jungle Slipstream ", "Stone Mosaico ", "Torn ", "Assault ", "Enforcer ", "Magna Carta ", "Poultrygeist " };
			int SkinIndex[] = { 46,  70,  100,  116,  157,  159,  165,  196,  232,  298,  312,  391,  406,  502,  518,  597,  612,  642,  685,  865,  896,  914,  954,  1028,  1139 };
		}


		namespace Galil
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Winter Forest ", "Orange Ddpat ", "Tornado ", "Sage Spray ", "Shattered ", "Blue Titanium ", "Varicamo ", "Urban Rubble ", "Hunting Blind ", "Amber Fade ", "Sandstorm ", "Tuxedo ", "Kami ", "Cerberus ", "Chatterbox ", "Eco ", "Aqua Terrace ", "Rocket Pop ", "Stone Cold ", "Firefight ", "Black Sand ", "Crimson Tsunami ", "Sugar Rush ", "Cold Fusion ", "Signal ", "Akoben ", "Connexion ", "Vandal ", "Phoenix Blacklight ", "Dusk Ruins ", "Chromatic Aberration ", "Caution " };
			int SkinIndex[] = { 76,  83,  101,  119,  192,  216,  235,  237,  241,  246,  264,  297,  308,  379,  398,  428,  460,  478,  494,  546,  629,  647,  661,  790,  807,  842,  972,  981,  1013,  1032,  1038,  1071 };
		}


		namespace AK_47
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Red Laminate ", "Case Hardened ", "Safari Mesh ", "Jungle Spray ", "Predator ", "Black Laminate ", "Fire Serpent ", "Blue Laminate ", "Redline ", "Emerald Pinstripe ", "Vulcan ", "Jaguar ", "Jet Set ", "Wasteland Rebel ", "Cartel ", "Elite Build ", "Hydroponic ", "Aquamarine Revenge ", "Frontside Misty ", "Point Disarray ", "Fuel Injector ", "Neon Revolution ", "Bloodsport ", "Orbit Mk01 ", "The Empress ", "Neon Rider ", "Wild Lotus ", "Baroque Purple ", "Safety Net ", "Asiimov ", "Uncharted ", "Rat Rod ", "Gold Arabesque ", "Phantom Disruptor ", "Legion Of Anubis ", "Xray ", "Panthera Onca ", "Slate ", "Green Laminate ", "Leet Museo ", "Nightwish " };
			int SkinIndex[] = { 14,  44,  72,  122,  170,  172,  180,  226,  282,  300,  302,  316,  340,  380,  394,  422,  456,  474,  490,  506,  524,  600,  639,  656,  675,  707,  724,  745,  795,  801,  836,  885,  921,  941,  959,  1004,  1018,  1035,  1070,  1087,  1141 };
		}


		namespace SG_553
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Anodized Navy ", "Bulldozer ", "Hypnotic ", "Ultraviolet ", "Tornado ", "Waves Perforated ", "Wave Spray ", "Gator Mesh ", "Damascus Steel ", "Pulse ", "Army Sheen ", "Traveler ", "Fallout Warning ", "Cyrex ", "Tiger Moth ", "Atlas ", "Aerial ", "Triarch ", "Phantom ", "Aloha ", "Integrale ", "Desert Blossom ", "Danger Close ", "Barricade ", "Candy Apple ", "Colony Iv ", "Bleached ", "Darkwing ", "Ol Rusty ", "Lush Ruins ", "Heavy Metal ", "Hazard Pay " };
			int SkinIndex[] = { 28,  39,  61,  98,  101,  136,  186,  243,  247,  287,  298,  363,  378,  487,  519,  553,  598,  613,  686,  702,  750,  765,  815,  861,  864,  897,  934,  955,  966,  1022,  1048,  1084 };
		}


		namespace C3SG1
		{
			int SkinID = 0;

			static const char* SkinList[] = { "Arctic Camo ", "Desert Storm ", "Contractor ", "Safari Mesh ", "Polar Camo ", "Jungle Dashed ", "Demeter ", "Azure Zebra ", "Varicamo ", "Green Apple ", "Murky ", "Chronos ", "Orange Kimono ", "Flux ", "The Executioner ", "Orange Crash ", "Ventilator ", "Stinger ", "Hunter ", "High Seas ", "Violet Murano ", "Scavenger ", "Black Sand ", "New Roots ", "Digital Mesh ", "Ancient Ritual ", "Keeping Tabs ", "Dream Glade " };
			int SkinIndex[] = { 6,  8,  46,  72,  74,  147,  195,  229,  235,  294,  382,  438,  465,  493,  511,  545,  606,  628,  677,  712,  739,  806,  891,  930,  980,  1034,  1095,  1129 };
		}
	}


	void ApplyGunIndex()
	{
		Gun::P2000 = SkinChangerSDK::GunList::P2000::SkinIndex[GunList::P2000::SkinID];
		Gun::USP_S = SkinChangerSDK::GunList::USP_S::SkinIndex[GunList::USP_S::SkinID];
		Gun::Glock = SkinChangerSDK::GunList::Glock::SkinIndex[GunList::Glock::SkinID];
		Gun::Dual_Berettas = SkinChangerSDK::GunList::Dual_Berettas::SkinIndex[GunList::Dual_Berettas::SkinID];
		Gun::P250 = SkinChangerSDK::GunList::P250::SkinIndex[GunList::P250::SkinID];
		Gun::Tec_9 = SkinChangerSDK::GunList::Tec_9::SkinIndex[GunList::Tec_9::SkinID];
		Gun::CZ75_Auto = SkinChangerSDK::GunList::CZ75_Auto::SkinIndex[GunList::CZ75_Auto::SkinID];
		Gun::Desert_Eagle = SkinChangerSDK::GunList::Desert_Eagle::SkinIndex[GunList::Desert_Eagle::SkinID];
		Gun::Five_SeveN = SkinChangerSDK::GunList::Five_SeveN::SkinIndex[GunList::Five_SeveN::SkinID];
		Gun::R8 = SkinChangerSDK::GunList::R8::SkinIndex[GunList::R8::SkinID];
		Gun::Nova = SkinChangerSDK::GunList::Nova::SkinIndex[GunList::Nova::SkinID];
		Gun::XM1014 = SkinChangerSDK::GunList::XM1014::SkinIndex[GunList::XM1014::SkinID];
		Gun::MAG_7 = SkinChangerSDK::GunList::MAG_7::SkinIndex[GunList::MAG_7::SkinID];
		Gun::M249 = SkinChangerSDK::GunList::M249::SkinIndex[GunList::M249::SkinID];
		Gun::Negev = SkinChangerSDK::GunList::Negev::SkinIndex[GunList::Negev::SkinID];
		Gun::Sawed_Off = SkinChangerSDK::GunList::Sawed_Off::SkinIndex[GunList::Sawed_Off::SkinID];
		Gun::MAC_10 = SkinChangerSDK::GunList::MAC_10::SkinIndex[GunList::MAC_10::SkinID];
		Gun::UMP_45 = SkinChangerSDK::GunList::UMP_45::SkinIndex[GunList::UMP_45::SkinID];
		Gun::P90 = SkinChangerSDK::GunList::P90::SkinIndex[GunList::P90::SkinID];
		Gun::PP_19 = SkinChangerSDK::GunList::PP_19::SkinIndex[GunList::PP_19::SkinID];
		Gun::MP9 = SkinChangerSDK::GunList::MP9::SkinIndex[GunList::MP9::SkinID];
		Gun::MP7 = SkinChangerSDK::GunList::MP7::SkinIndex[GunList::MP7::SkinID];
		Gun::FAMAS = SkinChangerSDK::GunList::FAMAS::SkinIndex[GunList::FAMAS::SkinID];
		Gun::MP5_SD = SkinChangerSDK::GunList::MP5_SD::SkinIndex[GunList::MP5_SD::SkinID];
		Gun::M4A4 = SkinChangerSDK::GunList::M4A4::SkinIndex[GunList::M4A4::SkinID];
		Gun::M4A1_S = SkinChangerSDK::GunList::M4A1_S::SkinIndex[GunList::M4A1_S::SkinID];
		Gun::SSG_08 = SkinChangerSDK::GunList::SSG_08::SkinIndex[GunList::SSG_08::SkinID];
		Gun::AUG = SkinChangerSDK::GunList::AUG::SkinIndex[GunList::AUG::SkinID];
		Gun::AWP = SkinChangerSDK::GunList::AWP::SkinIndex[GunList::AWP::SkinID];
		Gun::SG_553 = SkinChangerSDK::GunList::SG_553::SkinIndex[GunList::SG_553::SkinID];
		Gun::SCAR_20 = SkinChangerSDK::GunList::SCAR_20::SkinIndex[GunList::SCAR_20::SkinID];
		Gun::Galil = SkinChangerSDK::GunList::Galil::SkinIndex[GunList::Galil::SkinID];
		Gun::AK_47 = SkinChangerSDK::GunList::AK_47::SkinIndex[GunList::AK_47::SkinID];
		Gun::C3SG1 = SkinChangerSDK::GunList::C3SG1::SkinIndex[GunList::C3SG1::SkinID];
	}
}