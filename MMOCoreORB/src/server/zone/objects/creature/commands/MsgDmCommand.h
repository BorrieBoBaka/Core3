/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef MSGDMCOMMAND_H_
#define MSGDMCOMMAND_H_

class MsgDmCommand : public QueueCommand {

public:
	MsgDmCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
