#include "interface.hpp"
#include <string>

int main () {
	Interface interface;
	interface.addUser("nima","mg","nima.mg@gmail.com","just a gamer");
	interface.addCompany("NMG Games", "Sna, zher prd mardokh", "creating games for gamers");
	interface.addUser("amir","hbv","amirhbv@gmail.com","gentleman");
	interface.addUser("ali","shahverdi","alish@gmail.com","just another gamer");
	interface.addUser("hamid","ashrafi","ypical@gmail.com","a friend of the gamer");
	interface.addExperience("nima.mg@gmail.com","NMG Games", "CEO", "27/10/1377");
	std::cout << 1 << std::endl;
	interface.follow("nima.mg@gmail.com", "ypical@gmail.com");
	std::cout << 2 << std::endl;
	interface.assignSkill("nima.mg@gmail.com", "c++");
	std::cout << 3 << std::endl;
	interface.assignSkill("ypical@gmail.com", "c++");
	std::cout << 4 << std::endl;
	/*interface.endorseSkill("nima.mg@gmail.com","ypical@gmail.com", "c++");
	std::cout << 5 << std::endl;
	interface.endorseSkill("alish@gmail.com","ypical@gmail.com", "c++");
	std::cout << 6 << std::endl;
	interface.endorseSkill("amirhbv@gmail.com","ypical@gmail.com", "c++");
	std::cout << 7 << std::endl;
	std::cout << "FUCK" << std::endl;
	interface.printUserProfile("ypical@gmail.com");
	interface.endorseSkill("hama","ypical@gmail.com", "c++");
	std::cout << "DONT" << std::endl;
	interface.printUserProfile("ypical@gmail.com");
	interface.endorseSkill("ypical@gmail.com","nima.mg@gmail.com", "c++");*/
	interface.printCompanyProfile("NMG Games");
	interface.printUserProfile("nima.mg@gmail.com");
}