/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef D20COMMAND_H_
#define D20COMMAND_H_

class D20Command : public QueueCommand {

public:
	D20Command(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
