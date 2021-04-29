/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef NSTAYCOMMAND_H_
#define NSTAYCOMMAND_H_

class NStayCommand : public QueueCommand {

public:
	NStayCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		return SUCCESS;
	}

};

#endif 
