/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef HPCOMMAND_H_
#define HPCOMMAND_H_

class HpCommand : public QueueCommand {

public:
	HpCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
