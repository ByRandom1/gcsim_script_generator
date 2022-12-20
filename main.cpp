#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string input_path = R"(C:\Users\Maxwell\Desktop\GSimScriptConvert\gcsim\chinese_config\)";
string output_path = R"(C:\Users\Maxwell\Desktop\GSimScriptConvert\gcsim\config\)";

class Character
{
public:
    string name;
    string english_name;
    string ele_type;
    string weapon_type;
    int constellation;
    int talent_A;
    int talent_E;
    int talent_Q;
    bool life_useful;
    bool atk_useful;
    bool def_useful;
    bool mastery_useful;
    bool recharge_useful;
    bool critrate_useful;
    bool critdam_useful;
    bool damplus_useful;
    bool heal_useful;


    Character(string name_,
              string english_name_,
              string ele_type_,
              string weapon_type_,
              int constellation_,
              int talent_A_,
              int talent_E_,
              int talent_Q_,
              bool life_useful_,
              bool atk_useful_,
              bool def_useful_,
              bool mastery_useful_,
              bool recharge_useful_,
              bool critrate_useful_,
              bool critdam_useful_,
              bool damplus_useful_,
              bool heal_useful_)
    {
        name = name_;
        english_name = english_name_;
        ele_type = ele_type_;
        weapon_type = weapon_type_;
        constellation = constellation_;
        talent_A = talent_A_;
        talent_E = talent_E_;
        talent_Q = talent_Q_;
        life_useful = life_useful_;
        atk_useful = atk_useful_;
        def_useful = def_useful_;
        mastery_useful = mastery_useful_;
        recharge_useful = recharge_useful_;
        critrate_useful = critrate_useful_;
        critdam_useful = critdam_useful_;
        damplus_useful = damplus_useful_;
        heal_useful = heal_useful_;
    }
};

vector<Character *> character_list;

void init_character()
{
    character_list.push_back(new Character("胡桃", "hutao", "火", "长柄武器", 1, 10, 10, 10, true, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("神里绫华", "ayaka", "冰", "单手剑", 0, 10, 10, 10, false, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("雷电将军", "raiden", "雷", "长柄武器", 0, 6, 10, 10, false, true,
                                           false, false, true, true, true, true, false));
    character_list.push_back(new Character("纳西妲", "nahida", "草", "法器", 2, 6, 10, 10, false, true,
                                           false, true, false, true, true, true, false));
    character_list.push_back(new Character("甘雨", "ganyu", "冰", "弓", 0, 10, 10, 10, false, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("夜兰", "yelan", "水", "弓", 0, 6, 10, 10, true, false,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("香菱", "xiangling", "火", "长柄武器", 6, 6, 12, 12, false, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("行秋", "xingqiu", "水", "单手剑", 6, 6, 12, 12, false, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("八重神子", "yaemiko", "雷", "法器", 2, 6, 10, 10, false, true,
                                           false, true, false, true, true, true, false));
    character_list.push_back(new Character("温迪", "venti", "风", "弓", 0, 6, 9, 9, false, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("莫娜", "mona", "水", "法器", 3, 6, 9, 12, false, true,
                                           false, false, true, true, true, true, false));
    character_list.push_back(new Character("钟离", "zhongli", "岩", "长柄武器", 0, 6, 9, 9, true, true,
                                           false, false, false, true, true, true, false));
    character_list.push_back(new Character("枫原万叶", "kazuha", "风", "单手剑", 0, 6, 9, 9, false, true,
                                           false, true, false, true, true, true, false));
    character_list.push_back(new Character("班尼特", "bennett", "火", "单手剑", 6, 6, 12, 12, true, true,
                                           false, false, false, true, true, true, true));
    character_list.push_back(new Character("久岐忍", "kuki", "雷", "单手剑", 0, 1, 6, 6, true, true,
                                           false, true, false, true, true, true, true));
    //not owned
    character_list.push_back(new Character("珊瑚宫心海", "kokomi", "水", "法器", 0, 6, 9, 9, true, true,
                                           false, false, false, false, false, true, true));
}

Character *find_character_by_name(string c_name)
{
    for (auto &c: character_list)
        if (c->name == c_name)
            return c;
    return nullptr;
}

class Weapon
{
public:
    string name;
    string english_name;
    string weapon_type;
    int star;
    int refine;
    bool change_life_useful;
    bool change_atk_useful;
    bool change_def_useful;
    bool change_mastery_useful;
    bool change_recharge_useful;
    bool change_critrate_useful;
    bool change_critdam_useful;
    bool change_damplus_useful;
    bool change_heal_useful;

    Weapon(string name_,
           string english_name_,
           string weapon_type_,
           int star_,
           int refine_,
           bool change_life_useful_,
           bool change_atk_useful_,
           bool change_def_useful_,
           bool change_mastery_useful_,
           bool change_recharge_useful_,
           bool change_critrate_useful_,
           bool change_critdam_useful_,
           bool change_damplus_useful_,
           bool change_heal_useful_)
    {
        name = name_;
        english_name = english_name_;
        weapon_type = weapon_type_;
        star = star_;
        refine = refine_;
        change_life_useful = change_life_useful_;
        change_atk_useful = change_atk_useful_;
        change_def_useful = change_def_useful_;
        change_mastery_useful = change_mastery_useful_;
        change_recharge_useful = change_recharge_useful_;
        change_critrate_useful = change_critrate_useful_;
        change_critdam_useful = change_critdam_useful_;
        change_damplus_useful = change_damplus_useful_;
        change_heal_useful = change_heal_useful_;
    }
};

vector<Weapon *> weapon_list;

void init_weapon()
{
    //5 start
    weapon_list.push_back(new Weapon("雾切之回光", "mistsplitterreforged", "单手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("风鹰剑", "aquilafavonia", "单手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("波乱月白经津", "harangeppakufutsu", "单手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("斫峰之刃", "summitshaper", "单手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("天空之刃", "skywardblade", "单手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("苍古自由之誓", "freedomsworn", "单手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("磐岩结绿", "primordialjadecutter", "单手剑", 5, 1, true, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("圣显之钥", "keyofkhajnisut", "单手剑", 5, 1, true, false, false,
                                     false, false, false, false, false, false));//TODO:verify
    weapon_list.push_back(new Weapon("图莱杜拉的回忆", "tulaytullahsremembrance", "法器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));//TODO:verify
    weapon_list.push_back(new Weapon("天空之卷", "skywardatlas", "法器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("四风原典", "lostprayertothesacredwinds", "法器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("神乐之真意", "kagurasverity", "法器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("尘世之锁", "memoryofdust", "法器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("不灭月华", "everlastingmoonglow", "法器", 5, 1, true, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("千夜浮梦", "athousandfloatingdreams", "法器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));//TODO:verify
    weapon_list.push_back(new Weapon("天空之翼", "skywardharp", "弓", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("冬极白星", "polarstar", "弓", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("飞雷之弦振", "thunderingpulse", "弓", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("阿莫斯之弓", "amosbow", "弓", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("终末嗟叹之诗", "elegyfortheend", "弓", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("猎人之径", "hunterspath", "弓", 5, 1, false, false, false,
                                     true, false, false, false, false, false));//TODO:verify
    weapon_list.push_back(new Weapon("若水", "aquasimulacra", "弓", 5, 1, false, false, false,
                                     false, false, false, false, false, false));//TODO:verify
    weapon_list.push_back(new Weapon("松籁响起之时", "songofbrokenpines", "双手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("天空之傲", "skywardpride", "双手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("狼的末路", "wolfsgravestone", "双手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("无工之剑", "theunforged", "双手剑", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("赤角石溃杵", "redhornstonethresher", "双手剑", 5, 1, false, false, true,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("息灾", "calamityqueller", "长柄武器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("和璞鸢", "primordialjadewingedspear", "长柄武器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("天空之脊", "skywardspine", "长柄武器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("护摩之杖", "staffofhoma", "长柄武器", 5, 1, true, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("贯虹之槊", "vortexvanquisher", "长柄武器", 5, 1, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("薙草之稻光", "engulfinglightning", "长柄武器", 5, 1, false, false, false,
                                     false, true, false, false, false, false));
    weapon_list.push_back(new Weapon("赤沙之杖", "staffofthescarletsands", "长柄武器", 5, 1, false, false, false,
                                     true, false, false, false, false, false));//TODO:verify
    //valuable 4 star
    weapon_list.push_back(new Weapon("匣里龙吟", "lionsroar", "单手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("铁蜂刺", "ironsting", "单手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("祭礼剑", "sacrificialsword", "单手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("西风剑", "favoniussword", "单手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("流浪乐章", "thewidsith", "法器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("试作金珀", "prototypeamber", "法器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("西风秘典", "favoniuscodex", "法器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("祭礼残章", "sacrificialfragments", "法器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("曚云之月", "mouunsmoon", "弓", 4, 2, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("祭礼弓", "sacrificialbow", "弓", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("弓藏", "rust", "弓", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("绝弦", "thestringless", "弓", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("西风猎弓", "favoniuswarbow", "弓", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("祭礼大剑", "sacrificialgreatsword", "双手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("螭骨剑", "serpentspine", "双手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("西风大剑", "favoniusgreatsword", "双手剑", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("断浪长鳍", "wavebreakersfin", "长柄武器", 4, 4, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("西风长枪", "favoniuslance", "长柄武器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("渔获", "thecatch", "长柄武器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("决斗之枪", "deathmatch", "长柄武器", 4, 3, false, false, false,
                                     false, false, false, false, false, false));
    weapon_list.push_back(new Weapon("匣里灭辰", "dragonsbane", "长柄武器", 4, 5, false, false, false,
                                     false, false, false, false, false, false));
}

class Artifact
{
public:
    string name;
    string english_name;

    Artifact(string name_,
             string english_name_)
    {
        name = name_;
        english_name = english_name_;
    }
};

vector<Artifact *> artifact_list;

void init_artifact()
{
    artifact_list.push_back(new Artifact("流浪大地的乐团", "wandererstroupe"));
    artifact_list.push_back(new Artifact("角斗士的终幕礼", "gladiatorsfinale"));
    artifact_list.push_back(new Artifact("冰风迷途的勇士", "blizzardstrayer"));
    artifact_list.push_back(new Artifact("沉沦之心", "heartofdepth"));
    artifact_list.push_back(new Artifact("悠古的磐岩", "archaicpetra"));
    artifact_list.push_back(new Artifact("逆飞的流星", "retracingbolide"));
    artifact_list.push_back(new Artifact("染血的骑士道", "bloodstainedchivalry"));
    artifact_list.push_back(new Artifact("昔日宗室之仪", "noblesseoblige"));
    artifact_list.push_back(new Artifact("翠绿之影", "viridescentvenerer"));
    artifact_list.push_back(new Artifact("被怜爱的少女", "maidenbeloved"));
    artifact_list.push_back(new Artifact("苍白之火", "paleflame"));
    artifact_list.push_back(new Artifact("千岩牢固", "tenacityofthemillelith"));
    artifact_list.push_back(new Artifact("炽烈的炎之魔女", "crimsonwitchofflames"));
    artifact_list.push_back(new Artifact("渡过烈火的贤人", "lavawalker"));
    artifact_list.push_back(new Artifact("如雷的盛怒", "thunderingfury"));
    artifact_list.push_back(new Artifact("平息鸣雷的尊者", "thundersoother"));
    artifact_list.push_back(new Artifact("追忆之注连", "shimenawasreminiscence"));
    artifact_list.push_back(new Artifact("绝缘之旗印", "emblemofseveredfate"));
    artifact_list.push_back(new Artifact("华馆梦醒形骸记", "huskofopulentdreams"));
    artifact_list.push_back(new Artifact("海染砗磲", "oceanhuedclam"));
    artifact_list.push_back(new Artifact("辰砂往生录", "vermillionhereafter"));
    artifact_list.push_back(new Artifact("来歆余响", "echoesofanoffering"));
    artifact_list.push_back(new Artifact("深林的记忆", "deepwoodmemories"));//TODO:verify
    artifact_list.push_back(new Artifact("饰金之梦", "gildeddreams"));//TODO:verify
    artifact_list.push_back(new Artifact("沙上楼阁史话", "desertpavilionchronicle"));//TODO:verify
    artifact_list.push_back(new Artifact("乐园遗落之花", "flowerofparadiselost"));//TODO:verify
}

class Main
{
public:
    string name;
    string english_name;
    string value;

    Main(string name_, string english_name_, string value_)
    {
        name = name_;
        english_name = english_name_;
        value = value_;
    }
};

vector<Main *> main_list;

void init_main()
{
    main_list.push_back(new Main("生命值", "hp%", "0.466"));
    main_list.push_back(new Main("攻击力", "atk%", "0.466"));
    main_list.push_back(new Main("防御力", "def%", "0.583"));
    main_list.push_back(new Main("元素充能效率", "er", "0.518"));
    main_list.push_back(new Main("元素精通", "em", "187"));
    main_list.push_back(new Main("暴击率", "cr", "0.311"));
    main_list.push_back(new Main("暴击伤害", "cd", "0.622"));
    main_list.push_back(new Main("治疗加成", "heal", "0.359"));
    main_list.push_back(new Main("火元素伤害加成", "pyro%", "0.466"));
    main_list.push_back(new Main("水元素伤害加成", "hydro%", "0.466"));
    main_list.push_back(new Main("雷元素伤害加成", "electro%", "0.466"));
    main_list.push_back(new Main("冰元素伤害加成", "cryo%", "0.466"));
    main_list.push_back(new Main("风元素伤害加成", "anemo%", "0.466"));
    main_list.push_back(new Main("岩元素伤害加成", "geo%", "0.466"));
    main_list.push_back(new Main("草元素伤害加成", "dendro%", "0.466"));
    main_list.push_back(new Main("物理元素伤害加成", "phys%", "0.583"));
}

int find_main_by_name(Character *c, string main)
{
    string true_main = (main == "伤害加成") ? (c->ele_type + main) : main;
    for (int i = 0; i < main_list.size(); ++i)
        if (true_main == main_list[i]->name)
            return i;
    return -1;
}

class Config
{
public:
    Character *c;
    int weapon_index;
    int artifact1_index;
    int artifact2_index;
    int main3_index;
    int main4_index;
    int main5_index;
    bool react;
    bool recharge;

    Config(Character *c_,
           bool react_,
           bool recharge_)
    {
        c = c_;
        react = react_;
        recharge = recharge_;
    }

    void change_elements(int weapon_index_,
                         int artifact1_index_,
                         int artifact2_index_,
                         int main3_index_,
                         int main4_index_,
                         int main5_index_)
    {
        weapon_index = weapon_index_;
        artifact1_index = artifact1_index_;
        artifact2_index = artifact2_index_;
        main3_index = main3_index_;
        main4_index = main4_index_;
        main5_index = main5_index_;
    }

    string get_index_combination()
    {
        return to_string(weapon_index) + to_string(artifact1_index) + to_string(artifact2_index) + to_string(main3_index) + to_string(main4_index) + to_string(main5_index);
    }
};

bool check_combination(Config *config, Weapon *w, Artifact *a1, Artifact *a2, string m3, string m4, string m5)
{
    //general
    if (config->c->weapon_type != w->weapon_type) return false;

    if ((a1->name == "追忆之注连" && a2->name != "角斗士的终幕礼") || a1->name == "辰砂往生录" || a1->name == "来歆余响") return false;
    if (a1->name == "苍白之火" && a2->name != "染血的骑士道") return false;
    if (a1->name == "海染砗磲" && a2->name != "被怜爱的少女") return false;
    if ((a1->name == "饰金之梦" && a2->name != "流浪大地的乐团") || a1->name == "乐园遗落之花") return false;
    if (a1->name == "沙上楼阁史话" && a2->name != "翠绿之影") return false;

    if ((a2->name == "追忆之注连" && a1->name != "角斗士的终幕礼") || a2->name == "辰砂往生录" || a2->name == "来歆余响") return false;
    if (a2->name == "苍白之火" && a1->name != "染血的骑士道") return false;
    if (a2->name == "海染砗磲" && a1->name != "被怜爱的少女") return false;
    if ((a2->name == "饰金之梦" && a1->name != "流浪大地的乐团") || a2->name == "乐园遗落之花") return false;
    if (a2->name == "沙上楼阁史话" && a1->name != "翠绿之影") return false;

    if ((m3 == "生命值" || m4 == "生命值" || m5 == "生命值") && !(config->c->life_useful || w->change_life_useful)) return false;
    else if ((m3 == "攻击力" || m4 == "攻击力" || m5 == "攻击力") && !(config->c->atk_useful || w->change_atk_useful)) return false;
    else if ((m3 == "防御力" || m4 == "防御力" || m5 == "防御力") && !(config->c->def_useful || w->change_def_useful)) return false;
    else if (m3 == "元素充能效率" && !(config->c->recharge_useful || w->change_recharge_useful || (a1 == a2 && a1->name == "绝缘之旗印") || config->recharge)) return false;
    else if ((m3 == "元素精通" || m4 == "元素精通" || m5 == "元素精通") && !(config->c->mastery_useful || w->change_mastery_useful || config->react)) return false;
    else if (m5 == "暴击率" && !(config->c->critrate_useful || w->change_critrate_useful)) return false;
    else if (m5 == "暴击伤害" && !(config->c->critdam_useful || w->change_critdam_useful)) return false;
    else if (m5 == "治疗加成" && !(config->c->heal_useful || w->change_heal_useful)) return false;
    else if (m4 == "伤害加成" && !(config->c->damplus_useful || w->change_damplus_useful)) return false;

    //TODO:character related
    if (config->c->name=="胡桃")
    {
        return true;
    }
    else if (config->c->name=="神里绫华")
    {
        return true;
    }
    else if (config->c->name=="雷电将军")
    {
        return true;
    }
    else if (config->c->name=="纳西妲")
    {
        return true;
    }
    else if (config->c->name=="甘雨")
    {
        return true;
    }
    else if (config->c->name=="夜兰")
    {
        return true;
    }
    else if (config->c->name=="香菱")
    {
        return true;
    }
    else if (config->c->name=="行秋")
    {
        return true;
    }
    else if (config->c->name=="八重神子")
    {
        return true;
    }
    else if (config->c->name=="温迪")
    {
        return true;
    }
    else if (config->c->name=="莫娜")
    {
        return true;
    }
    else if (config->c->name=="钟离")
    {
        return true;
    }
    else if (config->c->name=="枫原万叶")
    {
        return true;
    }
    else if (config->c->name=="班尼特")
    {
        return true;
    }
    else if (config->c->name=="久岐忍")
    {
        return true;
    }
    else if (config->c->name=="珊瑚宫心海")
    {
        return true;
    }
}

Config *config1;
Config *config2;
Config *config3;
Config *config4;
vector<pair<string, string>> attack_list;

void parse_file(string filename)
{
    ifstream infile;
    infile.open(filename);
    string c_name_1;
    string react_1;
    string recharge_1;
    string c_name_2;
    string react_2;
    string recharge_2;
    string c_name_3;
    string react_3;
    string recharge_3;
    string c_name_4;
    string react_4;
    string recharge_4;

    infile >> c_name_1
           >> react_1
           >> recharge_1
           >> c_name_2
           >> react_2
           >> recharge_2
           >> c_name_3
           >> react_3
           >> recharge_3
           >> c_name_4
           >> react_4
           >> recharge_4;
    config1 = new Config(find_character_by_name(c_name_1), (react_1 == "反应"), (recharge_1 == "充能"));
    config2 = new Config(find_character_by_name(c_name_2), (react_2 == "反应"), (recharge_2 == "充能"));
    config3 = new Config(find_character_by_name(c_name_3), (react_3 == "反应"), (recharge_3 == "充能"));
    config4 = new Config(find_character_by_name(c_name_4), (react_4 == "反应"), (recharge_4 == "充能"));
    while (!infile.eof())
    {
        string c_name;
        string attack;
        infile >> c_name >> attack;
        if (attack == "平A") attack = "attack";
        else if (attack == "重A") attack = "charge";
        else if (attack == "下落A") attack = "plunge";
        else if (attack == "E") attack = "skill";
        else if (attack == "长E") attack = "skill[hold=1]";
        else if (attack == "Q") attack = "burst";
        else if (attack == "冲刺") attack = "dash";
        else if (attack == "跳跃") attack = "jump";
        attack_list.emplace_back(find_character_by_name(c_name)->english_name, attack);
    }
    infile.close();
}

void out(string filename)
{
    string filepath = filename.substr(0, filename.length() - 4) + "_" + config1->get_index_combination() + "_" + config2->get_index_combination()
                      + "_" + config3->get_index_combination() + "_" + config4->get_index_combination() + ".txt";
    ofstream outfile;
    outfile.open(filepath);
    //config chinese info
    outfile << "#" << config1->c->name << " " << weapon_list[config1->weapon_index]->name << " " << artifact_list[config1->artifact1_index]->name << " " << artifact_list[config1->artifact2_index]->name
            << " " << main_list[config1->main3_index]->name << " " << main_list[config1->main4_index]->name << " " << main_list[config1->main5_index]->name << endl;
    outfile << "#" << config2->c->name << " " << weapon_list[config2->weapon_index]->name << " " << artifact_list[config2->artifact1_index]->name << " " << artifact_list[config2->artifact2_index]->name
            << " " << main_list[config2->main3_index]->name << " " << main_list[config2->main4_index]->name << " " << main_list[config2->main5_index]->name << endl;
    outfile << "#" << config3->c->name << " " << weapon_list[config3->weapon_index]->name << " " << artifact_list[config3->artifact1_index]->name << " " << artifact_list[config3->artifact2_index]->name
            << " " << main_list[config3->main3_index]->name << " " << main_list[config3->main4_index]->name << " " << main_list[config3->main5_index]->name << endl;
    outfile << "#" << config4->c->name << " " << weapon_list[config4->weapon_index]->name << " " << artifact_list[config4->artifact1_index]->name << " " << artifact_list[config4->artifact2_index]->name
            << " " << main_list[config4->main3_index]->name << " " << main_list[config4->main4_index]->name << " " << main_list[config4->main5_index]->name << endl;
    //head
    outfile << "options iteration=1000 duration=110 swap_delay=4;" << endl;
    outfile << "target lvl=95 resist=0.1; #particle_threshold=250000 particle_drop_count=1;" << endl;
    outfile << "energy every interval=480,720 amount=1;" << endl;
    //config1
    outfile << config1->c->english_name << " char lvl=90/90 cons=" << to_string(config1->c->constellation)
            << " talent=" << to_string(config1->c->talent_A) << "," << to_string(config1->c->talent_E) << "," << to_string(config1->c->talent_Q) << ";" << endl;
    outfile << config1->c->english_name << " add weapon=\"" << weapon_list[config1->weapon_index]->english_name << "\" refine=" << to_string(weapon_list[config1->weapon_index]->refine)
            << " lvl=90/90;" << endl;
    if (config1->artifact1_index == config1->artifact2_index)
    {
        outfile << config1->c->english_name << " add set=\"" << artifact_list[config1->artifact1_index]->english_name << "\" count=4;" << endl;
    }
    else
    {
        outfile << config1->c->english_name << " add set=\"" << artifact_list[config1->artifact1_index]->english_name << "\" count=2;" << endl;
        outfile << config1->c->english_name << " add set=\"" << artifact_list[config1->artifact2_index]->english_name << "\" count=2;" << endl;
    }
    outfile << config1->c->english_name << " add stats hp=4780 atk=311 " << main_list[config1->main3_index]->english_name << "=" << main_list[config1->main3_index]->value << " "
            << main_list[config1->main3_index]->english_name << "=" << main_list[config1->main3_index]->value << " "
            << main_list[config1->main3_index]->english_name << "=" << main_list[config1->main3_index]->value << ";" << endl;
    outfile << endl;
    //config2
    outfile << config2->c->english_name << " char lvl=90/90 cons=" << to_string(config2->c->constellation)
            << " talent=" << to_string(config2->c->talent_A) << "," << to_string(config2->c->talent_E) << "," << to_string(config2->c->talent_Q) << ";" << endl;
    outfile << config2->c->english_name << " add weapon=\"" << weapon_list[config2->weapon_index]->english_name << "\" refine=" << to_string(weapon_list[config2->weapon_index]->refine)
            << " lvl=90/90;" << endl;
    if (config2->artifact1_index == config2->artifact2_index)
    {
        outfile << config2->c->english_name << " add set=\"" << artifact_list[config2->artifact1_index]->english_name << "\" count=4;" << endl;
    }
    else
    {
        outfile << config2->c->english_name << " add set=\"" << artifact_list[config2->artifact1_index]->english_name << "\" count=2;" << endl;
        outfile << config2->c->english_name << " add set=\"" << artifact_list[config2->artifact2_index]->english_name << "\" count=2;" << endl;
    }
    outfile << config2->c->english_name << " add stats hp=4780 atk=311 " << main_list[config2->main3_index]->english_name << "=" << main_list[config2->main3_index]->value << " "
            << main_list[config2->main3_index]->english_name << "=" << main_list[config2->main3_index]->value << " "
            << main_list[config2->main3_index]->english_name << "=" << main_list[config2->main3_index]->value << ";" << endl;
    outfile << endl;
    //config3
    outfile << config3->c->english_name << " char lvl=90/90 cons=" << to_string(config3->c->constellation)
            << " talent=" << to_string(config3->c->talent_A) << "," << to_string(config3->c->talent_E) << "," << to_string(config3->c->talent_Q) << ";" << endl;
    outfile << config3->c->english_name << " add weapon=\"" << weapon_list[config3->weapon_index]->english_name << "\" refine=" << to_string(weapon_list[config3->weapon_index]->refine)
            << " lvl=90/90;" << endl;
    if (config3->artifact1_index == config3->artifact2_index)
    {
        outfile << config3->c->english_name << " add set=\"" << artifact_list[config3->artifact1_index]->english_name << "\" count=4;" << endl;
    }
    else
    {
        outfile << config3->c->english_name << " add set=\"" << artifact_list[config3->artifact1_index]->english_name << "\" count=2;" << endl;
        outfile << config3->c->english_name << " add set=\"" << artifact_list[config3->artifact2_index]->english_name << "\" count=2;" << endl;
    }
    outfile << config3->c->english_name << " add stats hp=4780 atk=311 " << main_list[config3->main3_index]->english_name << "=" << main_list[config3->main3_index]->value << " "
            << main_list[config3->main3_index]->english_name << "=" << main_list[config3->main3_index]->value << " "
            << main_list[config3->main3_index]->english_name << "=" << main_list[config3->main3_index]->value << ";" << endl;
    outfile << endl;
    //config4
    outfile << config4->c->english_name << " char lvl=90/90 cons=" << to_string(config4->c->constellation)
            << " talent=" << to_string(config4->c->talent_A) << "," << to_string(config4->c->talent_E) << "," << to_string(config4->c->talent_Q) << ";" << endl;
    outfile << config4->c->english_name << " add weapon=\"" << weapon_list[config4->weapon_index]->english_name << "\" refine=" << to_string(weapon_list[config4->weapon_index]->refine)
            << " lvl=90/90;" << endl;
    if (config4->artifact1_index == config4->artifact2_index)
    {
        outfile << config4->c->english_name << " add set=\"" << artifact_list[config4->artifact1_index]->english_name << "\" count=4;" << endl;
    }
    else
    {
        outfile << config4->c->english_name << " add set=\"" << artifact_list[config4->artifact1_index]->english_name << "\" count=2;" << endl;
        outfile << config4->c->english_name << " add set=\"" << artifact_list[config4->artifact2_index]->english_name << "\" count=2;" << endl;
    }
    outfile << config4->c->english_name << " add stats hp=4780 atk=311 " << main_list[config4->main3_index]->english_name << "=" << main_list[config4->main3_index]->value << " "
            << main_list[config4->main3_index]->english_name << "=" << main_list[config4->main3_index]->value << " "
            << main_list[config4->main3_index]->english_name << "=" << main_list[config4->main3_index]->value << ";" << endl;
    outfile << endl;
    //active
    outfile << "active " << attack_list[0].first << ";" << endl;
    outfile << endl;
    //attack_list
    outfile << "let x = 5;" << endl;
    outfile << "while x {" << endl;
    for (auto &i: attack_list) outfile << "  " << i.first << " " << i.second << ";" << endl;
    outfile << "x = x - 1;" << endl;
    outfile << "}";

    outfile.close();
}

void get_config(string filename)
{
    string a_main3[5] = {"生命值", "攻击力", "防御力", "元素精通", "元素充能效率"};
    string a_main4[5] = {"生命值", "攻击力", "防御力", "元素精通", "伤害加成"};
    string a_main5[7] = {"生命值", "攻击力", "防御力", "元素精通", "暴击率", "暴击伤害", "治疗加成"};
    for (int w_1 = 0; w_1 < weapon_list.size(); ++w_1)
        for (int a1_1 = 0; a1_1 < artifact_list.size(); ++a1_1)
            for (int a2_1 = a1_1; a2_1 < artifact_list.size(); ++a2_1)
                for (int m3_1 = 0; m3_1 < 5; m3_1++)
                    for (int m4_1 = (m3_1 == 4) ? 0 : m3_1; m4_1 < 5; m4_1++)
                        for (int m5_1 = (m4_1 == 4) ? ((m3_1 == 4) ? 0 : m3_1) : m4_1; m5_1 < 7; m5_1++)
                        {
                            if (!check_combination(config1, weapon_list[w_1], artifact_list[a1_1], artifact_list[a2_1], a_main3[m3_1], a_main4[m4_1], a_main5[m5_1])) continue;
                            for (int w_2 = 0; w_2 < weapon_list.size(); ++w_2)
                                for (int a1_2 = 0; a1_2 < artifact_list.size(); ++a1_2)
                                    for (int a2_2 = a1_2; a2_2 < artifact_list.size(); ++a2_2)
                                        for (int m3_2 = 0; m3_2 < 5; m3_2++)
                                            for (int m4_2 = (m3_2 == 4) ? 0 : m3_2; m4_2 < 5; m4_2++)
                                                for (int m5_2 = (m4_2 == 4) ? ((m3_2 == 4) ? 0 : m3_2) : m4_2; m5_2 < 7; m5_2++)
                                                {
                                                    if (!check_combination(config1, weapon_list[w_2], artifact_list[a1_2], artifact_list[a2_2], a_main3[m3_2], a_main4[m4_2], a_main5[m5_2])) continue;
                                                    for (int w_3 = 0; w_3 < weapon_list.size(); ++w_3)
                                                        for (int a1_3 = 0; a1_3 < artifact_list.size(); ++a1_3)
                                                            for (int a2_3 = a1_3; a2_3 < artifact_list.size(); ++a2_3)
                                                                for (int m3_3 = 0; m3_3 < 5; m3_3++)
                                                                    for (int m4_3 = (m3_3 == 4) ? 0 : m3_3; m4_3 < 5; m4_3++)
                                                                        for (int m5_3 = (m4_3 == 4) ? ((m3_3 == 4) ? 0 : m3_3) : m4_3; m5_3 < 7; m5_3++)
                                                                        {
                                                                            if (!check_combination(config1, weapon_list[w_3], artifact_list[a1_3], artifact_list[a2_3], a_main3[m3_3], a_main4[m4_3], a_main5[m5_3])) continue;
                                                                            for (int w_4 = 0; w_4 < weapon_list.size(); ++w_4)
                                                                                for (int a1_4 = 0; a1_4 < artifact_list.size(); ++a1_4)
                                                                                    for (int a2_4 = a1_4; a2_4 < artifact_list.size(); ++a2_4)
                                                                                        for (int m3_4 = 0; m3_4 < 5; m3_4++)
                                                                                            for (int m4_4 = (m3_4 == 4) ? 0 : m3_4; m4_4 < 5; m4_4++)
                                                                                                for (int m5_4 = (m4_4 == 4) ? ((m3_4 == 4) ? 0 : m3_4) : m4_4; m5_4 < 7; m5_4++)
                                                                                                {
                                                                                                    if (!check_combination(config1, weapon_list[w_4], artifact_list[a1_4], artifact_list[a2_4], a_main3[m3_4], a_main4[m4_4], a_main5[m5_4])) continue;

                                                                                                    config1->change_elements(w_1, a1_1, a2_1, find_main_by_name(config1->c, a_main3[m3_1]),
                                                                                                                             find_main_by_name(config1->c, a_main4[m4_1]), find_main_by_name(config1->c, a_main5[m5_1]));
                                                                                                    config2->change_elements(w_2, a1_2, a2_2, find_main_by_name(config2->c, a_main3[m3_2]),
                                                                                                                             find_main_by_name(config2->c, a_main4[m4_2]), find_main_by_name(config2->c, a_main5[m5_2]));
                                                                                                    config3->change_elements(w_3, a1_3, a2_3, find_main_by_name(config3->c, a_main3[m3_3]),
                                                                                                                             find_main_by_name(config3->c, a_main4[m4_3]), find_main_by_name(config3->c, a_main5[m5_3]));
                                                                                                    config4->change_elements(w_4, a1_4, a2_4, find_main_by_name(config4->c, a_main3[m3_4]),
                                                                                                                             find_main_by_name(config4->c, a_main4[m4_4]), find_main_by_name(config4->c, a_main5[m5_4]));
                                                                                                    out(filename);
                                                                                                }
                                                                        }
                                                }
                        }
}

int main()
{
    init_character();
    init_weapon();
    init_artifact();
    init_main();

    string filename;
    cin >> filename;

    parse_file(input_path + filename);
    get_config(output_path + filename);
}
