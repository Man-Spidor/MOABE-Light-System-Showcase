#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Inputable.h>

/// Simple controller class for debug controls
class Controller : public Inputable
{
public:
	Controller() = default;
	Controller(const Controller& other) = default;
	Controller& operator=(const Controller& other) = default;
	Controller(Controller&& other) = default;
	Controller& operator=(Controller&& other) = default;
	~Controller() = default;

	void Initialize();

	virtual void KeyPressed(JAZUL_KEY key) override;
};

#endif // CONTROLLER_H
