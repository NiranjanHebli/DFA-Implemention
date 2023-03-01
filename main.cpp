#include <iostream>
#include <unordered_map>
using namespace std;
// 2 0 0 2 0 2 2 1 1 1 1

class StateNode
{
    bool flag;
    int StateNumber;
    int N; // Number of symbols in the language
    int *TransitionStates;

protected:
    unordered_map<int, StateNode *> Reference;

public:
    // Constructors
    StateNode(int StateNumber, int flag, int N)
    {
        this->StateNumber = StateNumber;
        this->N = N;
        this->flag = flag;
        TransitionStates = new int[this->N];
    }

    StateNode(int N)
    {
        this->N = N;

        TransitionStates = new int[this->N];
    }
    StateNode()
    {
        TransitionStates = new int[this->N];
    }

    // Getters
    int getStateNo()
    {
        return StateNumber;
    }
    int getFlag()
    {
        return flag;
    }
    int getN()
    {
        return N;
    }
    int getTransitionState(int i)
    {
        return TransitionStates[i];
    }
    void getStateNodeData(StateNode *ptr)
    {
        int loop = ptr->getN();
        cout << "StateNumber of the given State:" << ptr->getStateNo() << "\nAcceting State:" << ptr->getFlag() << "\nN: " << ptr->getN() << "\nAddress: " << ptr << endl;
        for (int i = 0; i < loop; i++)
        {
            cout << "StateNumber of the given State on symbol " << i << " : "
                 << "\nTransitionState[i]:" << TransitionStates[i] << "\nAcceting State:" << Reference[TransitionStates[i]]->getFlag() << endl
                 << "Address:" << Reference[TransitionStates[i]] << endl;
            // cout<<TransitionStates[i]->getStateNo()<<endl;T
        }
        // getStateNodeData(Reference[TransitionStates[0]]);
        // getStateNodeData(Reference[TransitionStates[1]]);
    }
    // Gets address of the State of the given StateNumber
    StateNode *getReference(int StateNumber)
    {
        auto it = Reference.find(StateNumber);
        if (it != Reference.end())
        {
            cout << "StateNumber:" << Reference[StateNumber]->StateNumber << endl;
            cout << "Value of N:" << Reference[StateNumber]->N << endl;
            cout << "Accepting State:" << Reference[StateNumber]->flag << endl;
            cout << "Address of the State" << Reference[StateNumber] << endl;
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
    void setN(int N)
    {
        this->N = N;
    }

    void setReference(int StateNumber, StateNode *newState)
    {
        Reference[StateNumber] = newState;
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

    int createStateNode(int N)
    {
        cout << "Enter the corresponding State Number for the given State" << endl;
        int StateNumber = -1;

        // Checking if the state already exists
        do
        {
            cin >> StateNumber;
            if (IsState(StateNumber))
            {
                cout << "StateNode already exists!" << endl;
                return StateNumber;
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
        setReference(StateNumber, newState);

        cout << "StateNumber of the given State:" << newState->getStateNo() << "\nAcceting State:" << newState->getFlag() << "N:" << N << endl;
        // Creating States for every transition
        for (int i = 0; i < newState->N; i++)
        {
            cout << "For input symbol " << i << " of State with Statenumber:" << newState->StateNumber << "Address:" << newState << endl;
            newState->TransitionStates[i] = createStateNode(N);
            // TransitionStates[i]=getReference(StateNumber);
            cout<<"For State Number:"<<StateNumber<<" TransitionState:"<<i<<":"<<TransitionStates[i]<<endl;
        }
         cout<<"StateNumber is:"<<StateNumber<<endl;

        return StateNumber;
    }

    // Destructor
    // ~StateNode()
    // {
    //     cout << "DESTRUCTOR CALLED FOR STATE-NODES" << endl;
    //     delete [] TransitionStates; 
    // }
};

class DFA : protected StateNode
{

    bool flag;
    // Maintains a statenumber for each node address
    int StartNode;
    int N;

public:
    // Constructor

    DFA()
    {
        cout << "Enter the number of symbols in the language" << endl;
        cin >> N;
        StartNode = createStateNode(N);
        // StartNode = newStateNode;
    }

    bool checkString(DFA F)
    {
        StateNode *ptr = Reference[F.StartNode];
        int currentState=-1;
        string s;
        cout << "Enter the String that is tobe checked" << endl;
        cin >> s;
        for (int i = 0; s[i] != '\0'; i++)
        {
            int x = s[i] - 48;
            cout << x << endl;
            currentState = ptr->getTransitionState(x);
            ptr=Reference[currentState];
            cout << "Address:" << ptr << " StateNumber:" << ptr->getStateNo() << " Flag:" << ptr->getFlag() << endl;
        }
        return Reference[currentState]->getFlag();
    }

    // getters
    void ShowReferenceTable()
    {
        cout<<endl<<"----------------------------DISPLAYING REFERENCE TABLE--------------------------------"<<endl<<endl;
        for (auto it : Reference)
        {
            cout << "StateNo: " << it.first << "\nAddress: " << it.second << endl;
        }
        cout<<endl<<endl<<"--------------------------------------------------------------------------------------"<<endl;

    }
    void CheckStates(){
        cout<<endl<<"----------------------------DISPLAYING All States Data TABLE--------------------------------"<<endl<<endl;
        for (auto it : Reference)
        {
            cout << "StateNo: " << it.first << "\nAddress: " << it.second <<"\nFlag:"<<it.second->getFlag()<<"\nNumberOfTransitions:"<<it.second->getN()<<"\nTransition on input 0:"<<it.second->getTransitionState(0)<<"\nTransition on input 1:"<<it.second->getTransitionState(1)<<endl;
        }
        cout<<endl<<endl<<"--------------------------------------------------------------------------------------"<<endl;

    }

    void ShowDFA()
    {

        cout << "Showing Data of DFA" << endl;
        StateNode *ptr = NULL;
        cout << "Address of Starting Node:" << Reference[this->StartNode] << endl;
        ptr = Reference[this->StartNode];
        getStateNodeData(ptr);
    }
    DFA *createDFA()
    {
    }

    // Destructor
    // ~DFA()
    // {
    //     cout << "Destructor of DFA called" << endl;
    // }
};

int main()
{

    DFA F;
    // F.ShowReferenceTable();
    F.CheckStates();
    // F.ShowDFA();
    cout<<F.checkString(F);
    return 0;
}
