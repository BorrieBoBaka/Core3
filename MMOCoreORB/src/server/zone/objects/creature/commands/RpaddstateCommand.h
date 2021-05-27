/*
				Copyright <SWGEmu>
			Command written by BorrieBoBaka
		See file COPYING for copying conditions.*/

#ifndef RPADDSTATECOMMAND_H_
#define RPADDSTATECOMMAND_H_

class RpaddstateCommand : public QueueCommand {

public: 
	RpaddstateCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
	
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	
		return SUCCESS;
	}

};

#endif //RPADDSTATECOMMAND_H_