/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NFOLLOWCOMMAND_H_
#define NFOLLOWCOMMAND_H_

class NFollowCommand : public QueueCommand {

public:
	NFollowCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
