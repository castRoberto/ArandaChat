/*
 * RabbitMQEntity.h
 *
 *  Created on: 17/06/2022
 *      Author: rcastro
 */

#ifndef RABBITMQMIDDLEWARE_RABBITMQENTITY_H_
#define RABBITMQMIDDLEWARE_RABBITMQENTITY_H_

#include <iostream>
#include <string>

#include <amqpcpp.h>

#include "RabbitMQController.h"

namespace jKeys {
	const std::string queueKey 					= 	"queue";
	const std::string queueNameKey 				= 	"name";
	const std::string queueDurableKey 			= 	"durable";
	const std::string queueAutoDeleteKey 		= 	"autodelete";
	const std::string queuePassiveKey 			= 	"passive";
	const std::string queueExclusiveKey 		= 	"exclusive";

	const std::string exchangeKey 				= 	"exchange";
	const std::string exchangeNameKey 			= 	"name";
	const std::string exchangeDurableKey 		= 	"durable";
	const std::string exchangeAutoDeleteKey 	= 	"autodelete";
	const std::string exchangePassiveKey 		= 	"passive";
	const std::string exchangeInternalKey 		= 	"internal";
	const std::string exchangeTypeKey 			= 	"type";
	const std::string exchangeRoutingKeysKey 	= 	"routingKeys";
}

class RabbitMQEntity {
protected:
	std::string entityKey;
	std::string username;
	std::string password;
	std::string host;
	std::string vhost;

	std::string exchange;
	AMQP::ExchangeType exchangeType;

	RabbitMQController& rabbitController = RabbitMQController::getInstance();

	bool eDurable = false;
	bool eAutoDelete = false;
	bool ePassive = false;
	bool eInternal = false;

public:
	RabbitMQEntity(std::string entityKey,
			std::string username,
			std::string password,
			std::string host,
			std::string vhost,
			std::string exchange = "",
			std::string exchangeType = "topic");

	RabbitMQEntity(std::string entityKey, json config);
	virtual ~RabbitMQEntity();

	virtual void init() = 0;
	void activateRabbit();
};



#endif /* RABBITMQMIDDLEWARE_RABBITMQENTITY_H_ */
