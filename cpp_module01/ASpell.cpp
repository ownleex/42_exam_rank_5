#include "ASpell.hpp"

ASpell::ASpell():
	name(), effects() {}

ASpell::ASpell(const std::string& name, const std::string& effects):
	name(name), effects(effects) {}

ASpell::ASpell(const ASpell& other):
	name(other.name), effects(other.effects) {}

ASpell::~ASpell() {}

ASpell& ASpell::operator=(const ASpell& other) {
	this->name = other.name;
	this->effects = other.effects;
	return (*this);
}

const std::string& ASpell::getName(void) const {
	return (this->name);
}

const std::string& ASpell::getEffects(void) const {
	return (this->effects);
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}
