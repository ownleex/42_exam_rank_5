#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include <string>

class ASpell;

class ATarget
{
private:
	std::string type;
public:
	ATarget();
	ATarget(const std::string& type);
	ATarget(const ATarget& other);
	virtual ~ATarget();

	ATarget& operator=(const ATarget& other);

	const std::string& getType(void) const;

	void getHitBySpell(const ASpell& spell) const;

	virtual ATarget *clone(void) const = 0;
};

# include "ASpell.hpp"

#endif
