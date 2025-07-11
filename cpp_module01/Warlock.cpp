#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day.\n"; 
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!\n";
	for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); it != spellBook.end(); ++it) {
		delete it->second;
	}
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
	if (spell != nullptr) {
		std::map<std::string, ASpell*>::iterator it = spellBook.find(spell->getName());
		if (it == spellBook.end()) {
			spellBook[spell->getName()] = spell->clone();
		}
	}
}

void Warlock::forgetSpell(std::string spellName) {
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spellName);
		if (it != spellBook.end()) {
			delete it->second;
			spellBook.erase(spellName);
		}
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spellName);
		if (it != spellBook.end()) {
			it->second->launch(target);
		}
}