#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
	private:
		std::map<std::string, ATarget*> targetType;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string& targetType);
		ATarget* createTarget(const std::string& TargetType);
};