#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include <string>

class ATarget;

class ASpell
{
private:
	std::string name;
	std::string effects;
public:
	ASpell();
	ASpell(const std::string& name, const std::string& effects);
	ASpell(ASpell const& other);
	virtual ~ASpell();

	ASpell& operator=(const ASpell&other);

	const std::string& getName(void) const;
	const std::string& getEffects(void) const;

	void launch(const ATarget& target) const;

	virtual ASpell *clone(void) const = 0;
};

# include "ATarget.hpp"

#endif
