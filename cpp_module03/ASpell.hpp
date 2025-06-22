#pragma once

#include <iostream>

class ATarget;

class ASpell {
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell(const std::string& name, const std::string& effects);
		virtual ~ASpell();
		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& src);
};