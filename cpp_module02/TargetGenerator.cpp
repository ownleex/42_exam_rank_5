#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (std::map<std::string, ATarget*>::iterator it = targetBook.begin(); it != targetBook.end(); ++it) {
		delete it->second;
	}
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target != nullptr) {
		std::map<std::string, ATarget*>::iterator it = targetBook.find(target->getType());
		if (it == targetBook.end()) {
			targetBook[target->getType()] = target->clone();
		}
	}
}

void TargetGenerator::forgetTargetType(const std::string& targetName) {
	std::map<std::string, ATarget*>::iterator it = targetBook.find(targetName);
		if (it != targetBook.end()) {
			delete it->second;
			targetBook.erase(targetName);
		}
}

ATarget* TargetGenerator::createTarget(const std::string& targetName) {
	std::map<std::string, ATarget*>::iterator it = targetBook.find(targetName);
		if (it != targetBook.end()) {
			return it->second->clone();
		}
		return nullptr;
}