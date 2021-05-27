/*
				Copyright <SWGEmu>
			Command written by BorrieBoBaka
		See file COPYING for copying conditions.*/

#ifndef RPFPULLCOMMAND_H_
#define RPFPULLCOMMAND_H_

class RpfpullCommand : public QueueCommand {

public: 
	RpfpullCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
	
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	
		return SUCCESS;
	}

};

#endif //RPFPULLCOMMAND_H_