/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef TRAINCOMMAND_H_
#define TRAINCOMMAND_H_

class TrainCommand : public QueueCommand {

public:
	TrainCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
