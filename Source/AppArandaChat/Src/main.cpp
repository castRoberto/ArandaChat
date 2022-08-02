/**
 * @brief Entry point for chat application
 *
 * @date 31/07/2022
 * @authors robertoca07@hotmail.com
 * @name main.cpp
 */
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <unistd.h>

#include <RabbitMQMiddleware/Consumer.h>
#include <RabbitMQMiddleware/Producer.h>
#include <UtilJson/UtilJson.h>

#include <global/common/sys/trap.h>

#include "Sesion.h"
#include "View/View.h"

int main(int argc, char *argv[]) {
	bool exitApp = false;

	std::string userName = argv[1];
	std::string path;

	path = argv[0];
	int pos = path.find("AppArandaChat");
	if (pos == -1) {
		return 1;
	}

	path = path.substr(0, pos);
	path.append("Config/ComunicationConfig.json");

	json config = UtilJson::getJson(path);

	Sesion* sesion = new Sesion(userName, config);
	sesion->init();
	usleep(1000000);

	View* view = new View(sesion);
	view->init();

//	while (!exitApp) {
//		for (std::string user : sesion->getUsersOnline()) {
//			LOG(user);
//		}
//		std::cin.get();
//	}

	return 0;
}


