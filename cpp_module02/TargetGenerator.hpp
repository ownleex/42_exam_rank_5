#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
	private:
		std::map<std::string, ATarget*> targetBook;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string& targetName);
		ATarget* createTarget(const std::string& targetName);
};