#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class StateNode
{
private:
    bool flag;
    int StateNumber;
    int N;
    vector<StateNode *> TransitionStates;

protected:
    unordered_map<int, StateNode *> Reference;

public:
    // Constructors
    StateNode(int StateNumber, int flag, int N)
    {
        this->StateNumber = StateNumber;
        this->N = N;
        this->flag = flag;
    }

    StateNode(int N)
    {
        this->N = N;
    }
    StateNode()
    {
    }

    // Getters
    int getStateNo()
    {
        return StateNumber;
    }

    // Gets address of the State of the given StateNumber
    StateNode *getReference(int StateNumber)
    {
        if (Reference[StateNumber])
        {
            return Reference[StateNumber];
        }
    }

    // Setters
    void setFlag(bool flag)
    {
        this->flag = flag;
    }

    void setStateNo(int StateNumber)
    {
        this->StateNumber = StateNumber;
    }

    void setReference(int StateNumber,StateNode *newState){
        Reference[StateNumber]=newState;
    }

    // Checks if the State already exists
    bool IsState(int StateNumber)
    {
        if (Reference[StateNumber])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void takeInput()
    {
    }

    StateNode *createStateNode(int N)
    {
        cout << "Enter the corresponding State Number for the given State" << endl;
        int StateNumber = -1;

        // Checking if the state already exists
        do
        {
            cin >> StateNumber;
            if (IsState(StateNumber))
            {
                return getReference(StateNumber);
            }

        } while (StateNumber == -1);

        // Setting the flag
        bool flag = -1;

        do
        {
            int choice = -1;
            cout << "Is it an Accepting State?\nPress 1 for Yes\nPress 0 for No\nYour Choice:";
            cin >> choice;
            (choice == 0 || choice == 1) ? (flag = choice) : (flag = -1);
        } while (flag == -1);


        StateNode *newState = new StateNode(StateNumber, flag, N);
        setReference(StateNumber,newState);
//Creating States for every transition
        for (int i = 0; i < this->N; i++)
        {
            TransitionStates[i] = createStateNode(N);
        }

        return newState;
    }


    // Destructor
    ~StateNode()
    {
        for (int i = 0; i < N; i++)
        {
            delete TransitionStates[i];
        }
    }
};

class DFA : public StateNode
{
    bool flag;
    // Maintains a statenumber for each node address
    StateNode * StartNode;
    int N;

public:
    // Constructor

    DFA()
    {

        StateNode *newStateNode = createStateNode(N);
        StartNode=newStateNode;
    }

    // getters
   void ShowDFA(){
    
    }
    DFA *createDFA()
    {
    }

//Destructor
    ~DFA(){

    }
};

int main()
{
    DFA F;

    return 0;
}
