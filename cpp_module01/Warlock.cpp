#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

Warlock::Warlock(const std::string &name, const std::string &title): name(name), title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
}
const std::string &Warlock::getName() const
{
    return (this->name);
}

const std::string &Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell != nullptr)
    {
        std::map<std::string, ASpell *>::iterator it = SpellBook.find(spell->getName());
        if (it == SpellBook.end())
            SpellBook[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string spellName)
{
    std::map<std::string, ASpell *>::iterator it = SpellBook.find(spellName);

    if (it != SpellBook.end())
    {
        delete it->second;
        SpellBook.erase(spellName);
    }
}

void Warlock::launchSpell(std::string spellName, const ATarget &src)
{
    std::map<std::string, ASpell *>::iterator it = SpellBook.find(spellName);

    if (it != SpellBook.end())
        it->second->launch(src);
}
