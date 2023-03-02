
# DFA Implementation Using C++

In this project you can implement the DFA you have constructed  and use it to check input of strings which determines whether the given string belongs to the language of the Finite Automata or not. 


## 🔗 Links

Lets Connect Together!

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/)

[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/)


## 🛠 Skills

Skills used consists of:-

![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

![image](https://img.shields.io/badge/GIT-E44C30?style=for-the-badge&logo=git&logoColor=white)
## Implementation

The Idea behind this code is straight forward:


Given Sigma i.e the symbols used to define a given language there exists a Finite Automata which tells whether the given input string belongs to the language or not.

Now in a DFA, every State has exactly N transitions, where N is the number of symbols present in set Sigma.

Another thing is for certain that each State will have a transition with each symbol present in Sigma and this transition will be only once from one State to another.

Coming to the implementation of code,the DFA is represented with a Data Structure called called as StateNode which has all the properties of the given state i.e whether it is an accepting state or not,which transitions are possible on the given symbol from Sigma.

The reference of the Transitions possible and the character symbols are stored in HashTable to increase the access time.





## Run Locally

Clone the project

```bash
  git clone https://github.com/NiranjanHebli/DFA-Implemention.git
```


Compile the Program

```bash
  g++ main.cpp
```

Execute the Program

```bash
 ./a.exe
```


## Optimizations

This is a very basic implementations, if there are any Optimizations possible in the code feel free to create an issue or make your pull request ;)


## License

[MIT](https://choosealicense.com/licenses/mit/)


## 👨‍🚀Show your support

Give a ⭐️ if this project helped you!

