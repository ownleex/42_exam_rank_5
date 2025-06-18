#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include <vector>
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;

	std::vector<ASpell*> spells;

	Warlock();
	Warlock(const Warlock& other);

	Warlock &operator=(const Warlock& other);
public:
	Warlock(const std::string& name, const std::string& title);
	virtual ~Warlock();

	const std::string& getName(void) const;
	const std::string& getTitle(void) const;

	void setTitle(const std::string& title);

	void introduce(void) const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spellName);
	void launchSpell(std::string spellName, const ATarget& target);
};

#endif