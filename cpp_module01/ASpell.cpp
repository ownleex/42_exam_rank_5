#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects) : name(name), effects(effects) {

}

ASpell::~ASpell() {}

const std::string& ASpell::getName() const {
	return this->name;
}

const std::string& ASpell::getEffects() const {
	return this->effects;
}

void ASpell::launch(const ATarget& src) const {
	src.getHitBySpell(*this);
}