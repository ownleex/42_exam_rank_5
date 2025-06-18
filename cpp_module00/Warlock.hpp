#pragma once

#include <iostream>

class Warlock {
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);

	public:
		virtual ~Warlock();
		Warlock(const std::string& name, const std::string& title);

		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& newTitle);

		void introduce() const;
};
