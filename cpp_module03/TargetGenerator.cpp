#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target != nullptr) {
		std::map<std::string, ATarget*>::iterator it = targetType.find(target->getType());
		if (it == targetType.end()) {
			targetType[target->getType()] = target->clone();
		}
	}
}

void TargetGenerator::forgetTargetType(const std::string& target) {
	std::map<std::string, ATarget*>::iterator it = targetType.find(target);
	if (it != targetType.end()) {
		delete it->second;
		targetType.erase(target);
	}
}

ATarget* TargetGenerator::createTarget(const std::string& target) {
	std::map<std::string, ATarget*>::iterator it = targetType.find(target);
	if (it != targetType.end()) {
		it->second->clone();
	}
}






