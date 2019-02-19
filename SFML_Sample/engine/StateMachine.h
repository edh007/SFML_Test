#pragma once

#include <memory>
#include <stack>

#include "State.h"

NS_DHL_BEGIN

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:
    StateMachine() { }
    ~StateMachine() { }

    void AddState(StateRef newState, bool isReplacing = true);
    void RemoveState();

    void ProcessStateChanges();

    StateRef& GetActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving, _isAdding, _isReplacing;
};

NS_DHL_END