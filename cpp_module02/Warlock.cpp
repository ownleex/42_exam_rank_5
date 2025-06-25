#include "Warlock.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day.\n"; 
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!\n";
}

const std::string& Warlock::getName() const {
	return this->name;
}

const std::string& Warlock::getTitle() const {
	return this->title;
}

void Warlock::setTitle(const std::string& newTitle) {
	this->title = newTitle;
}

void Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell* spell) {
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName) {
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	ASpell* spell = spellBook.createSpell(spellName);
	if (spell != nullptr) {
		spell->launch(target);
	}
}