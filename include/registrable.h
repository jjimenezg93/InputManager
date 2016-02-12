#ifndef _I_REGISTRABLE_H
#define _I_REGISTRABLE_H

class CEvent;

class IRegistrable {
public:
	virtual void Notify(CEvent * ev) {}
	virtual void ManageEvent(CEvent * ev) {}
};

#endif //!_I_REGISTRABLE_H