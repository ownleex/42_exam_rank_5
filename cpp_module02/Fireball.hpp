#pragma once

#include <iostream>
#include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		Fireball();
		~Fireball();
		ASpell* clone() const;
};