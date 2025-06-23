#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	spellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell != nullptr) {
		std::map<std::string, ASpell*>::iterator it = spellBook.find(spell->getName());
		if (it == spellBook.end()) {
			spellBook[spell->getName()] = spell->clone();
		}
	}
}

void SpellBook::forgetSpell(const std::string& spellName) {
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spellName);
	if (it != spellBook.end()) {
		delete it->second;
		spellBook.erase(spellName);
	}
}

ASpell* SpellBook::createSpell(const std::string& spellName) {
	std::map<std::string, ASpell*>::iterator it = spellBook.find(spellName);
	if (it != spellBook.end()) {
		return it->second->clone();
	}
	return nullptr;
}