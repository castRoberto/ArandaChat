/*
 * Producer.h
 *
 *  Created on: 13/06/2022
 *      Author: rcastro
 */

#ifndef PRODUCER_H_
#define PRODUCER_H_

#include "RabbitMQEntity.h"
#include "RabbitMQController.h"

class Producer : public RabbitMQEntity {
public:
	Producer(std::string& producerName,
			std::string& username,
			std::string& password,
			std::string& host,
			std::string& vhost,
			std::string& exchange,
			std::string& exchangeType);
	Producer(std::string& producerName, json config);
	virtual ~Producer();

	void init() override;
	void publish(const std::string& msg, const std::string& routingKey);
};

#endif /* PRODUCER_H_ */
