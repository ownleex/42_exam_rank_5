#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook {
	private:
		std::map<std::string, ASpell*> spellBook;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string& spellName);
		ASpell* createSpell(const std::string& spellName);
};