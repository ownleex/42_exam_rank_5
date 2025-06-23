#pragma once

#include <iostream>

class ASpell;

class ATarget {
	protected:
		std::string type;
	public:
		ATarget(const std::string& type);
		~ATarget();
		const std::string& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& src) const;
};