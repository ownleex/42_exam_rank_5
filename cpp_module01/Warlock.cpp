#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!\n";
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it)
		delete *it;
	this->spells.clear();
}

const std::string& Warlock::getName(void) const {
	return (this->name);
}

const std::string& Warlock::getTitle(void) const {
	return (this->title);
}

void Warlock::setTitle(const std::string& title) {
	this->title = title;
}

void Warlock::introduce(void) const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell) {
	if (spell) {
		std::vector<ASpell*>::iterator ite = this->spells.end();
		for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it)
			if ((*it)->getName() == spell->getName())
				return ;
		this->spells.push_back(spell->clone());
	}
}

void Warlock::forgetSpell(std::string spellName) {
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != this->spells.end();) {
		if ((*it)->getName() == spellName) {
			delete *it;
			it = this->spells.erase(it);
			return;
		} else {
			++it;
		}
	}
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	std::vector<ASpell*>::iterator ite = this->spells.end();
	for (std::vector<ASpell*>::iterator it = this->spells.begin(); it != ite; ++it) {
		if ((*it)->getName() == spellName) {
			(*it)->launch(target);
			return ;
		}
	}
}