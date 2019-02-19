#include "StateMachine.h"

NS_DHL_BEGIN

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
    _isAdding = true;
    _isReplacing = isReplacing;

    _newState = std::move(newState); 
}

void StateMachine::RemoveState()
{
    _isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
    // if removing trigger is true and states are not empty
    if(_isRemoving && !_states.empty())
    {
        _states.pop(); //stack

        if (!_states.empty())
            _states.top()->Resume();

        _isRemoving = false;
    }

    if(_isAdding)
    {
        if (!_states.empty())
        {
            if (_isReplacing)
                _states.pop();
            else
                _states.top()->Pause();
        }

        _states.push(std::move(_newState));
        _states.top()->Init();
        _isAdding = false;
    }
}

StateRef& StateMachine::GetActiveState()
{
    return _states.top();
}

NS_DHL_END