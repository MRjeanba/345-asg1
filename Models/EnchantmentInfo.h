//
// Created by jeanb on 24/02/2024.
//

#ifndef ENCHANTMENTINFO_H
#define ENCHANTMENTINFO_H
#include <map>

enum enchantmentTypes {
    ArmorClass,
    Wisdom,
    Intelligence,
    Strengh,
    Constitution,
    Charisma,
    Dexterity,
    AttackBonus,
    DamageBonus
};

inline std::pmr::map<std::string,enchantmentTypes> stringToEnchantmentInt= {
    {"ArmorClass",ArmorClass},
    {"Wisdom",Wisdom},
    {"Intelligence",Intelligence},
    {"Strength",Strengh},
    {"Constitution",Constitution},
    {"Charisma",Charisma},
    {"Dexterity",Dexterity},
    {"AttackBonus",AttackBonus},
    {"DamageBonus",DamageBonus},
};

/**
 * \brief Helper method to help us get the string version of the enum enchantmentTypes
 * \param e the enum value of the enchantmentTypes enum (integer)
 * \return the string value of the given enchantmentType
 */
inline const char* ToString(enchantmentTypes e)
{
    switch (e)
    {
        case ArmorClass:   return "ArmorClass";
        case Wisdom:   return "Wisdom";
        case Intelligence: return "Intelligence";
        case Strengh: return "Strengh";
        case Constitution: return "Constitution";
        case Charisma: return "Charisma";
        case Dexterity: return "Dexterity";
        case AttackBonus: return "AttackBonus";
        case DamageBonus: return "DamageBonus";
        default:      return "[Unknown enchantmentType provided]";
    }
}

/**
 * \brief Structure defined in order to get the enchantment bonus and enchantment type from a same place
 * The structure holds two variables: enchantmentBonus and enchantmentType
 */
struct  EnchantmentInfo {
    int enchantmentBonus;
    enchantmentTypes enchantmentType;
};


#endif //ENCHANTMENTINFO_H