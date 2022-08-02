/*
 * Producer.cpp
 *
 *  Created on: 13/06/2022
 *      Author: rcastro
 */

#include "../Producer.h"

Producer::Producer(std::string& producerName,
		std::string& username,
		std::string& password,
		std::string& host,
		std::string& vhost,
		std::string& exchange,
		std::string& exchangeType) :
	RabbitMQEntity(producerName, username, password, host, vhost, exchange, exchangeType)
{
	activateRabbit();
}

Producer::Producer(std::string& producerName, json config) :
	RabbitMQEntity(producerName, config)
{
	activateRabbit();
}

Producer::~Producer() {

}

void Producer::init() {
	int flags = this->eDurable? AMQP::durable : 0;
	rabbitController.getChannel()->declareExchange(exchange, exchangeType, flags).onSuccess([this]() {});
}

void Producer::publish(const std::string& msg, const std::string& routingKey) {
   rabbitController.getChannel()->publish(exchange, routingKey, msg.c_str());
}

