/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NFACECOMMAND_H_
#define NFACECOMMAND_H_

class NFaceCommand : public QueueCommand {

public:
	NFaceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
