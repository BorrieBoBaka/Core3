/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef TOOLCOMMAND_H_
#define TOOLCOMMAND_H_

class ToolCommand : public QueueCommand {

public:
	ToolCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
