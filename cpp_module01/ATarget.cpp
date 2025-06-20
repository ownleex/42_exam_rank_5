#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const std::string& type) : type(type) {

}

ATarget::~ATarget() {}

const std::string& ATarget::getType() const {
	return this->type;
}

void ATarget::getHitBySpell(const ASpell& src) const {
	std::cout << this->type << " has been " << src.getEffects() << "!" << std::endl;
}
