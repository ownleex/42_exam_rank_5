#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell*> spellBook;

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& name);
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string SpellName);
		void launchSpell(std::string SpellName,const ATarget& src);
};