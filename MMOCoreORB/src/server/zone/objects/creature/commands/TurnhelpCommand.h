/*
				Copyright <SWGEmu>
			Command written by BorrieBoBaka
		See file COPYING for copying conditions.*/

#ifndef TURNHELPCOMMAND_H_
#define TURNHELPCOMMAND_H_

class TurnhelpCommand : public QueueCommand {

public: 
	TurnhelpCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
	
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	
		return SUCCESS;
	}

};

#endif //TURNHELPCOMMAND_H_