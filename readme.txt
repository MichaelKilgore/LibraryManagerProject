HOW TO START:
g++ *.cpp
./a.out




1. Everything works with no memory leaks.

2. My only hash tables from scratch are in the ItemFactory, 
   PatronFactory, HistoryFactory, and finally the itemMap in the
   Library class.

3. HOW PATRONS ARE MADE:
    Library.cpp calls constructor
      constructor calls loadInPatrons
        loadInPatrons calls insertPatron in PatronManager.h 
          insertPatron reads from file, and inserts patron
          into patronMap.

4. HOW COMMANDS ARE READ IN:
    NOTE: command types are registered in commandFactory in
          constructor of Library.cpp

    Library.cpp calls simulateInteractions
      simulateInteractions reads in action type. 
      simulateInteractions calls parseFile in one of the following
      command class files:
        -- ReturnItem.cpp
        -- CheckoutItem.cpp
        -- DisplayLibrary.cpp
        -- DisplayPatronHistory.cpp
      parseFile basically prepares the class object to perform
      an execute. Then when execute is called (also in one of the
      4 files above) then the command is actually performed.

5. No switches are used anywhere.

6. I didn't use a single switch anywhere, I really wanted to because
   it would've made my life a lot easier, but I didn't. So I'm proud I
   managed to do that.



