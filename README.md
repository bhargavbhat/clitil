## CLI-TIL
A Simple program that can show facts from online sources. Something like `fortune` except this one fetches its quotes via JSON from websites. Currently for Linux Only. Requires a C++11 compiler.

### Building
* Fetch dependencies (`json11`) by running `git submodule update --init`
* run `make`
* run `/.clitil` to see the program in action

### Options
* Source to fetch from is passed in as a command line parameter, eg: `./clitil numbers`
* Available source are:
    * `reddit` for [/r/TodayILearned](https://www.reddit.com/r/todayilearned/) - top post of the day
    * `numbers` for the [NumbersAPI](http://numbersapi.com) - fact about a random year
    * `icndb` for [ICNDB](http://www.icndb.com/) - random Chuck Norris joke

### Tests
* Unit testing handled via the [CATCH](https://github.com/philsquared/Catch) framework
* To run tests, execute `make test`
* Tests for the NumbersAPI and ICNDB are yet to be added

### Pretty Printing
* `cliltil` does not handle pretty printing. 
* A standard command line tool like `cowsay` (or similar) can be used to get pretty results. Eg: `./clitil numbers | cowsay - f turtle` produces:
```
 _______________________________________
/ TIL 993 is the year that Saint Ulrich \
\ of Augsburg is canonized on July 4th. /
 ---------------------------------------
    \                                  ___-------___
     \                             _-~~             ~~-_
      \                         _-~                    /~-_
             /^\__/^\         /~  \                   /    \
           /|  O|| O|        /      \_______________/        \
          | |___||__|      /       /                \          \
          |          \    /      /                    \          \
          |   (_______) /______/                        \_________ \
          |         / /         \                      /            \
           \         \^\\         \                  /               \     /
             \         ||           \______________/      _-_       //\__//
               \       ||------_-~~-_ ------------- \ --/~   ~\    || __/
                 ~-----||====/~     |==================|       |/~~~~~
                  (_(__/  ./     /                    \_\      \.
                         (_(___/                         \_____)_)

```
