/*
 * User.h
 *
 *  Created on: 31/07/2022
 *      Author: operador
 */

#ifndef SRC_USER_USER_H_
#define SRC_USER_USER_H_

#include <string>

class User {
private:
	std::string nameUser;

public:
	User(std::string& nameUser);
	virtual ~User();

	const std::string& getNameUser() const;
	void setNameUser(const std::string& nameUser);
};

#endif /* SRC_USER_USER_H_ */
