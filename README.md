## CLI-TIL
A Simple program that can show facts from a few online sources

Currently for Linux Only

### Building
* Fetch dependencies (`json11`) by running `git submodule update --init`
* run `make`
* run `make test`

### Options
* Source to fetch from is passed in as a command line parameter, eg: `./clitil numbers`
* Available source are:
    * `reddit` for [/r/TodayILearned](https://www.reddit.com/r/todayilearned/) - top post of the day
    * `numbers` for the [NumbersAPI](http://numbersapi.com) - fact about a random year
    * `icndb` for [ICNDB](http://www.icndb.com/) - random Chuck Norris joke

### Pretty Printing
This small application doesn't handle pretty printing, the standard command line tool `cowsay` or similar can be used to get pretty results. Eg: `./clitil numbers | cowsay - f turtle` produces:
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
