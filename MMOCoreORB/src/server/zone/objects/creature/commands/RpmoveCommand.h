/*
				Copyright <SWGEmu>
			Command written by BorrieBoBaka
		See file COPYING for copying conditions.*/

#ifndef RPMOVECOMMAND_H_
#define RPMOVECOMMAND_H_

class RpmoveCommand : public QueueCommand {
public:
	RpmoveCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
		return SUCCESS;
	}
};

#endif // RPMOVECOMMAND_H_